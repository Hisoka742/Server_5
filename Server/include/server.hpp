#ifndef SERVER_HPP
#define SERVER_HPP

#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include "TaskQueue.hpp"
#include "ThreadPool.hpp"
#include "spdlog/spdlog.h"

// Exclude <unistd.h> on Windows
#ifndef _WIN32
#include <unistd.h>
#endif

class Server {
private:
    std::shared_ptr<TaskQueue> task_queue_;
    std::shared_ptr<ThreadPool> thread_pool_;
    int max_threads_;
    std::shared_ptr<spdlog::logger> logger_;

public:
    Server(int max_threads);
    ~Server();

    void start();
    void stop();
    void addTask(std::shared_ptr<Task> task);
};

#endif // SERVER_HPP
