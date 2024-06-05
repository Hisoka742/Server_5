#include "Server.hpp"
#include "spdlog/sinks/stdout_color_sinks.h" // Include the header for stdout_color_mt

Server::Server(int max_threads)
    : task_queue_(std::make_shared<TaskQueue>()),
    thread_pool_(std::make_shared<ThreadPool>(max_threads, *task_queue_)),
    max_threads_(max_threads) {
    // Initialize logger
    logger_ = spdlog::stdout_color_mt("server");
    spdlog::set_level(spdlog::level::debug);
}

Server::~Server() {
    stop();
}

void Server::start() {
    logger_->info("Server started");
    // Add any initialization code here
}

void Server::stop() {
    thread_pool_->stop();
    logger_->info("Server stopped");
}

void Server::addTask(std::shared_ptr<Task> task) {
    task_queue_->push(task);
}
