#ifndef FILE_UPLOAD_TASK_HPP
#define FILE_UPLOAD_TASK_HPP

#include <iostream>
#include <fstream>
#include "Task.hpp"

class FileUploadTask : public Task {
private:
    std::string filename_;

public:
    FileUploadTask(const std::string& filename)
        : filename_(filename) {}

    void execute() override;
};

#endif // FILE_UPLOAD_TASK_HPP
