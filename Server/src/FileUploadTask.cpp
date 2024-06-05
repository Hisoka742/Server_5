#include "FileUploadTask.hpp"

void FileUploadTask::execute() {
    // Upload file to server
    std::ifstream infile(filename_, std::ios::binary);
    if (infile) {
        std::cout << "Uploading file " << filename_ << " to server" << std::endl;
    }
    else {
        std::cerr << "Error: Unable to open file for reading" << std::endl;
    }
}
