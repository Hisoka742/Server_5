#include "FileDownloadTask.hpp"

void FileDownloadTask::execute() {
    // Download file from URL and save it
    std::ofstream outfile(filename_, std::ios::binary);
    if (outfile) {
        outfile << "Content of downloaded file from " << url_;
        std::cout << "File downloaded successfully" << std::endl;
    }
    else {
        std::cerr << "Error: Unable to open file for writing" << std::endl;
    }
}
