#ifndef TASK_QUEUE_HPP
#define TASK_QUEUE_HPP

#include <mutex>
#include <queue>
#include <memory>
#include "Task.hpp"

class ThreadPool; // Forward declaration

class TaskQueue {
private:
    std::queue<std::shared_ptr<Task>> tasks_;
    mutable std::mutex mutex_; // Make mutex_ mutable to allow locking in const member functions

public:
    TaskQueue();
    ~TaskQueue();

    void push(std::shared_ptr<Task> task);
    std::shared_ptr<Task> pop();

    // Declare ThreadPool as a friend class to access mutex_
    friend class ThreadPool;
};

#endif // TASK_QUEUE_HPP
