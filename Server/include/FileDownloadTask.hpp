#ifndef FILE_DOWNLOAD_TASK_HPP
#define FILE_DOWNLOAD_TASK_HPP

#include <iostream>
#include <fstream>
#include "Task.hpp"

class FileDownloadTask : public Task {
private:
    std::string url_;
    std::string filename_;

public:
    FileDownloadTask(const std::string& url, const std::string& filename)
        : url_(url), filename_(filename) {}

    void execute() override;
};

#endif // FILE_DOWNLOAD_TASK_HPP
