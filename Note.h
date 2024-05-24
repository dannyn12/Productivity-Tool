#ifndef NOTE_H
#define NOTE_H

#include <string>

// note class
class Note {
public:
    std::string title;
    std::string content;
    std::string date;
    
    /**
     * @brief Construct a new Note object
     * 
     */
    Note();
};

#endif