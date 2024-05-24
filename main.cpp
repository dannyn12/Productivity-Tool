#include <iostream>
#include "Productivity.h"

using namespace std;

int main() {
    cout << "Welcome to Danny's Productivity Tool!"<< endl;

    // initializes list
    Productivity list;

    // prints out user options for to do list
    while (true) {
        cout << "Select an option:" << endl;
        cout << "1. Add a note" << endl;
        cout << "2. Add a task" << endl;
        cout << "3. View notes added" << endl;
        cout << "4. View tasks added" << endl;
        cout << "5. Mark task as complete" << endl;
        cout << "6. Add event to calendar" << endl;
        cout << "7. View calendar" << endl;
        cout << "8. Quit" << endl;


    // ask user for there choice
    int choice;
    cout << "Choice: ";

    // makes sure that input is only a int
    while (true) {
        cin >> choice;

        if (!cin.fail()) {
            break;
        }

        cerr << "Invalid choice, please try again" << endl;
        cin.clear();

        char badChar;
        do {badChar = cin.get(); } while (badChar != '\n');

        cout << endl;
        cout << "Select an option:" << endl;
        cout << "1. Add a note" << endl;
        cout << "2. Add a task" << endl;
        cout << "3. View notes added" << endl;
        cout << "4. View tasks added" << endl;
        cout << "5. Mark task as complete" << endl;
        cout << "6. Add event to calendar" << endl;
        cout << "7. View calendar" << endl;
        cout << "8. Quit" << endl;
        cout << "Choice: ";
    }

    // switch cases
    switch (choice) {
        // if choice 1 add note and sort list in in alphabetical order
        case 1:
            list.addNote();
            list.writeNotes();
            break;
        // if choice 2 add task and sort list in in alphabetical order
        case 2:
            list.addTask();
            list.writeTasks();
            break;
        // if choice 3 the list of notes will be printed out to terminal
        case 3:
            list.viewNotes();
            break;
        // if choice 4 the list of tasks will printed out to terminal
        case 4:
            list.viewTasks();
            break;
        // if choice 5 mark a task as done
        case 5:
            list.markTaskComplete();
            list.writeTasks();
            break;
        // if choice 6 add a event to calendar
        case 6:
            list.addEventToCalendar();
            list.sortCalendar();
            list.writeCalendar();
            break;
        // if choice 7 the list of event will printed out to terminal
        case 7:
            list.viewCalendar();
            break;
        // if choice 8 the program will end
        case 8:
            cout << "Goodbye!" << endl;
            return 0;
        // if user inputs someting else that is not 1 to 8
        default:
            cout << "Invalid choice, please try again" << endl;
            break;
    }
    cout << endl;
    }
}

