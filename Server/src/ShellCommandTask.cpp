#include "ShellCommandTask.hpp"

void ShellCommandTask::execute() {
    std::cout << "Executing shell command: " << command_ << std::endl;
    int result = std::system(command_.c_str());
    if (result != 0) {
        std::cerr << "Error: Command execution failed" << std::endl;
    }
}
