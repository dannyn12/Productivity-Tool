#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <iomanip>

#include "Note.h"
#include "Task.h"
#include "Calendar.h"
#include <iostream>

#include "Productivity.h"

using namespace std;
    
void Productivity::addNote() {
    // initializes notes
    Note note;
    // ignores input buffer
    cin.ignore();

    cout << "Enter note title: ";
    getline(cin, note.title);
    cout << "Enter note content: ";
    getline(cin, note.content);

    // get current time and date
    time_t now = time(0);
    string time = ctime(&now);  
    note.date = time;

    // add note class to vector
    notes.push_back(note);
    cout << "Note added successfully" << endl;

}

void Productivity::addTask() {
    // intializes task
    Task task;
    // ignores input buffer
    cin.ignore();
    // get task name
    cout << "Enter task name: ";
    getline(cin, task.title);
    // Validate task title
    while (task.title.empty()) {
        cout << "Invalid task title. Please enter a non-empty title: ";
        getline(cin, task.title);
    }
    cout << "Enter task description: ";
    getline(cin, task.description);
    // get current time and date
    time_t now = time(0);
    string time = ctime(&now);  
    task.date = time;
    task.completed = false;
    tasks.push_back(task);
    cout << "Task added successfully" << endl;
}

void Productivity::viewNotes() const {
    // print header
    cout << "***********" << endl; 
    cout << "*  Notes  *" << endl;
    cout << "***********" << endl;
    for (unsigned int i = 0; i < notes.size(); i++) {
        Note note = notes[i];
        cout << "Note Created: " << note.date;
        cout << "Title: " << note.title << endl << endl;
        cout<< note.content << endl;
        cout << "---------------------------------------------------" << endl;    
    }
}

void Productivity::viewTasks() const {
    // print header
    cout << "***********" << endl; 
    cout << "*  Tasks  *" << endl;
    cout << "***********" << endl;
    for (unsigned int i = 0; i < tasks.size(); i++) {
        Task task = tasks[i];
        // write task as completed if it is marked completed
        if (task.completed == true) {
                cout << "Task Created: " << task.date << endl;
                cout << "Title: " << task.title << endl;
                cout << "Completion Status: [X]" << endl << endl;
                cout << task.description << endl;
                cout << "---------------------------------------------------" << endl;              
        }
        // write task to file if not complete
        else {
                cout << "Task Created: " << task.date << endl;
                cout << "Title: " << task.title << endl;
                cout << "Completion Status:" << endl << endl;
                cout << task.description << endl;
                cout << "---------------------------------------------------" << endl; 
        }
    }
}

void Productivity::markTaskComplete() {
    // ask user for which task to mark as down
    cout << "Enter task title: ";
    string title;
    cin.ignore();
    getline(cin, title);
    // find task with same name as inputed
    for (unsigned int i = 0; i < tasks.size(); i++) {
        Task& task = tasks[i];
        if (task.title == title) {
            task.completed = true;
            cout << "Task marked as completed" << endl;
            return;
        }
    }
    cout << "Task not found" << endl;
}

void Productivity::addEventToCalendar() {
    while (true) {
        cout << "Enter calendar date (YYYY-MM-DD): ";
        string date;
        cin >> date;

        // check if date is in the correct format
        if (date.length() == 10 && date[4] == '-' && date[7] == '-' && stoi(date.substr(5, 2)) <= 12 && stoi(date.substr(5, 2)) > 0 && stoi(date.substr(8, 2)) <= 31 && stoi(date.substr(8, 2)) > 0) {
            for (unsigned int i = 0; i < calendars.size(); i++) {
                Calendar& calendar = calendars[i];
                if (calendar.date == date) {
                    cout << "Enter event name: ";
                    string event;
                    cin.ignore(); // ignore any remaining input in buffer before getline
                    getline(cin, event);
                    calendar.events.push_back(event);
                    cout << "Event added to calendar" << endl;
                    return;
                }
            }
            Calendar calendar;
            calendar.date = date;
            cout << "Enter event name: ";
            string event;
            cin.ignore(); // ignore any remaining input in buffer before getline
            getline(cin, event);

            calendar.events.push_back(event);
            calendars.push_back(calendar);
            cout << "Calendar created and event added" << endl;
            return;
        } 
        else {
            cout << "Invalid date format. Please enter date in the format YYYY-MM-DD." << endl;
            // clear the input stream and try again
            cin.clear();
            while (cin.get() != '\n') {
                continue;
            }
        }
    }
}

void Productivity::viewCalendar() const {
    // prints out calendar events to terminal
    cout << "************" << endl; 
    cout << "* Calendar *" << endl;
    cout << "************" << endl; 
    for (unsigned int i = 0; i < calendars.size(); i++) {
        Calendar calendar = calendars[i];
        cout << "Date: " << calendar.date << endl << endl;
        for (unsigned int j = 0; j < calendar.events.size(); j++) {
            string event = calendar.events[j];
            cout << "- " << event << endl;
        }
        cout << "---------------------------------------------------" << endl;
    }
}


void Productivity::sortCalendar() {
    // sorts the calender dates vector by dates (oldest to newest)
    for (unsigned int i = 0; i < calendars.size() - 1; i++) {
        for (unsigned int j = i + 1; j < calendars.size(); j++) {
            // compare the dates by year
            int year1 = stoi(calendars[i].date.substr(0, 4));
            int year2 = stoi(calendars[j].date.substr(0, 4));
            if (year1 > year2) {
                swap(calendars[i], calendars[j]);
            }
            else if (year1 == year2) {
                // compare the dates by month
                int month1 = stoi(calendars[i].date.substr(5, 2));
                int month2 = stoi(calendars[j].date.substr(5, 2));
                if (month1 > month2) {
                    swap(calendars[i], calendars[j]);
                }
                else if (month1 == month2) {
                    // Ccmpare the dates by day
                    int day1 = stoi(calendars[i].date.substr(8, 2));
                    int day2 = stoi(calendars[j].date.substr(8, 2));
                    if (day1 > day2) {
                        swap(calendars[i], calendars[j]);
                    }
                }
            }
        }
    }
}

void Productivity::writeNotes() const {
    // gets current year, day, and month to make a note text file with the date it was made on it
    time_t now = time(0);
    // converts the time_t value to a struct tm containing the local date and time information
    tm *locTime = localtime(&now);
    // calculate the current year
    int year = 1900 + locTime->tm_year;
    // calculate the current month
    int month = 1 + locTime->tm_mon;
    // calculate the current day
    int day = locTime->tm_mday;
    // create file name with current date
    string fileName = "Notes-" + to_string(year) + "-" + to_string(month) + "-" + to_string(day) + ".txt";
    // open file with name
    ofstream writeFile(fileName);
    // if opening file fails
    if (writeFile.fail() ) {
        cerr << "Error Opening Notes Output File";
        return;
    }
    // while file is open, write in note name and content
    if (writeFile.is_open() == true) {
        writeFile << "***********" << endl; 
        writeFile << "*  Notes  *" << endl;
        writeFile << "***********" << endl;
        for (unsigned int i = 0; i < notes.size(); i++) {
            Note note = notes[i];
            writeFile << "Note Created: " << note.date << endl;
            writeFile << "Title: " << note.title << endl << endl;
            writeFile << note.content << endl;
            writeFile << "---------------------------------------------------" << endl;
        }
        // close file
        writeFile.close();
    }
}

void Productivity::writeTasks() const {
    // gets current year, day, and month to make a note text file with the date it was made on it
    time_t now = time(0);
    // converts the time_t value to a struct tm containing the local date and time information
    tm *locTime = localtime(&now);
    // calculate the current year
    int year = 1900 + locTime->tm_year;
    // calculate the current month
    int month = 1 + locTime->tm_mon;
    // calculate the current day
    int day = locTime->tm_mday;
    // create file name with current date
    string fileName = "Tasks-" + to_string(year) + "-" + to_string(month) + "-" + to_string(day) + ".txt";
    // open file with name
    ofstream writeFile(fileName);
    // if opening file fails 
    if (writeFile.fail() ) {
        cerr << "Error Opening Tasks Output File";
        return;
    }
    // write to file when it is open
    if (writeFile.is_open() == true) {
        writeFile << "***********" << endl; 
        writeFile << "*  Tasks  *" << endl;
        writeFile << "***********" << endl;
        for (unsigned int i = 0; i < tasks.size(); i++) {
            Task task = tasks[i];
            // mark task as complete
            if (task.completed == true) {
                writeFile << "Task Created: " << task.date << endl;
                writeFile << "Title: " << task.title << endl;
                writeFile << "Completion Status: [X]" << endl << endl;
                writeFile << task.description << endl;
                writeFile << "---------------------------------------------------" << endl;             
            }
            // write task to file if not complete
            else {
                writeFile << "Task Created: " << task.date << endl;
                writeFile << "Title: " << task.title << endl;
                writeFile << "Completion Status:" << endl << endl;
                writeFile << task.description << endl;
                writeFile << "---------------------------------------------------" << endl;
            }
        }
        writeFile.close();
    }    
}

void Productivity::writeCalendar() const {
    // open file with name
    ofstream writeFile("Calendar.txt");
    // if opening file fails
    if (writeFile.fail()) {
        cerr << "Error Opening Calendar Output File";
        return;
    }
    // while file is open, write in note name and content
    if (writeFile.is_open() == true) {
        writeFile << "************" << endl; 
        writeFile << "* Calendar *" << endl;
        writeFile << "************" << endl;
        for (unsigned int i = 0; i < calendars.size(); i++) {
            Calendar calendar = calendars[i];
            writeFile << "Date: " << calendar.date  << endl;
            for (unsigned int j = 0; j < calendar.events.size(); j++) {
                string event = calendar.events[j];
                writeFile << "- " << event << endl;
        }
        writeFile << "---------------------------------------------------" << endl;
    }
        // close file
        writeFile.close();
    }
}



