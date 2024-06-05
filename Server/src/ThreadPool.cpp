#include "ThreadPool.hpp"

ThreadPool::ThreadPool(size_t num_threads, TaskQueue& task_queue)
    : task_queue_(task_queue) {
    for (size_t i = 0; i < num_threads; ++i) {
        workers_.emplace_back([this] { workerThread(); });
    }
}

ThreadPool::~ThreadPool() {
    stop();
}

void ThreadPool::stop() {
    {
        std::lock_guard<std::mutex> lock(task_queue_.mutex_);
        stop_ = true;
    }

    for (auto& worker : workers_) {
        worker.join();
    }
}

void ThreadPool::workerThread() {
    while (true) {
        auto task = task_queue_.pop();
        if (!task)
            break;
        task->execute();
    }
}

