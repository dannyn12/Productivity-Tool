
#ifndef TASK_H
#define TASK_H

#include <string>

// task class
class Task {
public:
    std::string title;
    std::string description;
    std::string date;
    bool completed = false;
    /**
     * @brief Construct a new Task object
     * 
     */
    Task();
};

#endif