#ifndef SHELL_COMMAND_TASK_HPP
#define SHELL_COMMAND_TASK_HPP

#include <iostream>
#include <cstdlib>
#include "Task.hpp"

class ShellCommandTask : public Task {
private:
    std::string command_;

public:
    ShellCommandTask(const std::string& command)
        : command_(command) {}

    void execute() override;
};

#endif // SHELL_COMMAND_TASK_HPP
