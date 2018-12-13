#include<iostream>
#include <thread>
#include <atomic>
#include <list>
#include <vector>
#include <functional>
#include <limits>
#include <condition_variable>
#include <mutex>
#include<unistd.h>

using namespace std;

std::mutex mtx;
std::condition_variable cv;

int cargo = 0;
bool shipment_available()
{
    //printf("shipment_available, cargo:%d\n", cargo);
    return cargo != 0;
}

// 消费者线程.
void consume(int n)
{
    int exe_count = 0;
    for (int i = 0; i < n; ++i) {
        // while(!shipment_available())
        //     std::this_thread::yield();
        //lock_guard<mutex> lck(mtx); // get the lock and run
        std::unique_lock <std::mutex> lck(mtx);
        // if return true will not be blocking  (cv.wait(lck, []{return true;}))   , 
        //else if always return fasle will be blocking forever(cv.wait(lck, []{return false;}))
        cv.wait(lck, shipment_available); 
        printf("after awake, cargo:%d , exe_count:%d\n", cargo, i);
        fflush(stdout); // must fflush
        cargo = 0;
        printf("consumer_thread done\n");
        fflush(stdout); //must fflush
    }
}

int main()
{
    std::thread consumer_thread(consume, 10); // 消费者线程.
    // 主线程为生产者线程, 生产 10 个物品.
    for (int i = 0; i < 10; ++i) {
        while (shipment_available()){
            std::this_thread::yield();
        }
        //std::unique_lock <std::mutex> lck(mtx);
        mtx.lock();
        cargo = i+1;
        printf("%s\n",  "awake therad");
        fflush(stdout); // in mutli_thread code, printf must fflush
        cv.notify_one();
        mtx.unlock();
    }

    printf("the end\n");

    consumer_thread.join(); 

    return 0;
}