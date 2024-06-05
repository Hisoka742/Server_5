#ifndef TASK_HPP
#define TASK_HPP

class Task {
public:
    virtual void execute() = 0;
    virtual ~Task() {}
};

#endif // TASK_HPP
