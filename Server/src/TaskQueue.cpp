#include "TaskQueue.hpp"

TaskQueue::TaskQueue() {}

TaskQueue::~TaskQueue() {}

void TaskQueue::push(std::shared_ptr<Task> task) {
    std::lock_guard<std::mutex> lock(mutex_);
    tasks_.push(task);
}

std::shared_ptr<Task> TaskQueue::pop() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (tasks_.empty()) {
        return nullptr; // Return nullptr if the queue is empty
    }
    auto task = tasks_.front();
    tasks_.pop();
    return task;
}
