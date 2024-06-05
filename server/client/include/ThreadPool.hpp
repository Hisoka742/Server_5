#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP

#include <vector>
#include <thread>
#include "TaskQueue.hpp"

class ThreadPool {
private:
    std::vector<std::thread> workers_;
    TaskQueue& task_queue_;
    bool stop_ = false;

    void workerThread();

public:
    ThreadPool(size_t num_threads, TaskQueue& task_queue);
    ~ThreadPool();

    void stop();
};

#endif // THREAD_POOL_HPP
