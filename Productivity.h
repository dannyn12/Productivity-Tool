#ifndef PRODUCTIVITY_H
#define PRODUCTIVITY_H

#include "Note.h"
#include "Task.h"
#include "Calendar.h"
#include <vector>

// productivity class
class Productivity {
private:
    std::vector<Note> notes;
    std::vector<Task> tasks;
    std::vector<Calendar> calendars;

public:
    /**
     * @brief adds a note to the notes list
     * 
     */
    void addNote();

    /**
     * @brief adds a task to the tasks list
     * 
     */
    void addTask();

    /**
     * @brief prints outs list of notes 
     * 
     */
    void viewNotes() const;

    /**
     * @brief prints outs list of vectors
     * 
     */
    void viewTasks() const;

    /**
     * @brief marks a task as complete 
     * 
     */
    void markTaskComplete();

    /**
     * @brief adds a event to the tasks list
     * 
     */
    void addEventToCalendar();

    /**
     * @brief prints outs events in calender
     * 
     */
    void viewCalendar() const;

    /**
     * @brief sorts calender by date
     * 
     */
    void sortCalendar();

    /**
     * @brief writes notes to text file
     * 
     */
    void writeNotes() const;

    /**
     * @brief writes tasks to text file
     * 
     */
    void writeTasks() const;

    /**
     * @brief writes events in calendar to text file 
     * 
     */
    void writeCalendar() const;


};

#endif