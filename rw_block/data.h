#pragma once
#include <pthread.h>
#include <string>
#include <unistd.h>

class Book {
    pthread_rwlock_t _lock;
    std::string content;

public:
    Book();
    ~Book();

    void write_content(std::string cont);

    std::string read_content();

    std::string read_content_without_unlock();
};

Book::Book(){
    pthread_rwlock_init(&_lock, nullptr);
}

Book::~Book(){
    pthread_rwlock_destroy(&_lock);
}

std::string Book::read_content(){
    pthread_rwlock_rdlock(&_lock);
    printf("read content\n");
    pthread_rwlock_unlock(&_lock);
    return content;
}

std::string Book::read_content_without_unlock(){
    pthread_rwlock_rdlock(&_lock);
    printf("read content without unlock\n");
    sleep(5);
    pthread_rwlock_unlock(&_lock);
    return content;
}

void Book::write_content(std::string cont){
    printf("write try get lock\n");
    pthread_rwlock_wrlock(&_lock);
    content = cont;
    printf("write content\n");
    pthread_rwlock_unlock(&_lock);
}