#ifndef CALENDAR_H
#define CALENDAR_H

#include <vector>

// calendar task
class Calendar {
public:
    std::string date ;
    std::vector<std::string> events;
    /**
     * @brief Construct a new Calendar object
     * 
     */
    Calendar();
};

#endif