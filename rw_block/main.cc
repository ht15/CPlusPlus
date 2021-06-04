#include "data.h"

#define REARER_NUM 10
#define WRITER_NUM 2

void* read_str(void* book)
{
    Book* b = (Book*)book;
    b->read_content();
}

void* read_str_without_unlock(void* book)
{
    Book* b = (Book*)book;
    b->read_content_without_unlock();
}

void* write_str(void* book)
{
    Book* b = (Book*)book;
    b->write_content("a");
}

int main(int argv, const char* argc[]){
    Book A = Book();
    pthread_t rt[REARER_NUM];
    pthread_t wr[WRITER_NUM];
    for(int i=0; i< REARER_NUM; i++){
        if (i>7){
            pthread_create(&rt[i], nullptr, read_str_without_unlock, (void*)&A);
        }
        else{
            pthread_create(&rt[i], nullptr, read_str, (void*)&A);
        }
    }
    for(int i=0; i<WRITER_NUM; i++){
        pthread_create(&wr[i], nullptr, write_str, (void*)&A);
    }
    for(int i=0; i< REARER_NUM; i++){
        pthread_join(rt[i], nullptr);
    }
    for(int i=0; i<WRITER_NUM; i++){
        pthread_join(wr[i], nullptr);
    }
    return 0;
}