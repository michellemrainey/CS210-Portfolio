/*
 * Name: Michelle Rainey
 * Course: CS-210
 * Project One: Chada Tech Clocks
 *
 * Description:
 * This program displays both a 12-hour and a 24-hour clock.
 * The user can add one hour, one minute, or one second.
 *
 * AI Acknowledgment:
 * ChatGPT was used to help review requirements, organize functions,
 * and troubleshoot the program.
 */

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Stores the current clock time.
unsigned int hour = 0;
unsigned int minute = 0;
unsigned int second = 0;


// Formats a number as two digits.
string twoDigitString(unsigned int n) {
    if (n < 10) {
        return "0" + to_string(n);
    }

    return to_string(n);
}


// Creates a string containing n copies of character c.
string nCharString(size_t n, char c) {
    return string(n, c);
}


// Formats the time as a 24-hour clock.
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    return twoDigitString(h) + ":" +
        twoDigitString(m) + ":" +
        twoDigitString(s);
}


// Formats the time as a 12-hour clock.
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string period;

    if (h < 12) {
        period = "A M";
    }
    else {
        period = "P M";
    }

    unsigned int hour12 = h % 12;

    if (hour12 == 0) {
        hour12 = 12;
    }

    return twoDigitString(hour12) + ":" +
        twoDigitString(m) + ":" +
        twoDigitString(s) + " " + period;
}


// Displays both clocks at the same time.
void displayClocks() {
    cout << endl;

    cout << nCharString(26, '*')
        << "   "
        << nCharString(26, '*') << endl;

    cout << "*      12-Hour Clock     *"
        << "   "
        << "*      24-Hour Clock     *" << endl;

    cout << "*      "
        << formatTime12(hour, minute, second)
        << "      *"
        << "   "
        << "*        "
        << formatTime24(hour, minute, second)
        << "        *" << endl;

    cout << nCharString(26, '*')
        << "   "
        << nCharString(26, '*') << endl;
}


// Prints the menu.
void printMenu() {
    cout << endl;
    cout << nCharString(26, '*') << endl;
    cout << "* 1 - Add One Hour       *" << endl;
    cout << "* 2 - Add One Minute     *" << endl;
    cout << "* 3 - Add One Second     *" << endl;
    cout << "* 4 - Exit Program       *" << endl;
    cout << nCharString(26, '*') << endl;
}


// Gets a valid menu choice.
unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int choice;

    while (true) {
        cout << "Enter choice: ";

        if (cin >> choice && choice >= 1 && choice <= maxChoice) {
            return choice;
        }

        cout << "Invalid choice. Enter a number from 1 to "
            << maxChoice << "." << endl;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


// Adds one hour.
void addOneHour() {
    hour++;

    if (hour >= 24) {
        hour = 0;
    }
}


// Adds one minute.
void addOneMinute() {
    minute++;

    if (minute >= 60) {
        minute = 0;
        addOneHour();
    }
}


// Adds one second.
void addOneSecond() {
    second++;

    if (second >= 60) {
        second = 0;
        addOneMinute();
    }
}


// Gets the initial time from the user.
void getInitialTime() {
    cout << "Enter hour (0-23): ";
    cin >> hour;

    while (hour > 23) {
        cout << "Enter a valid hour (0-23): ";
        cin >> hour;
    }

    cout << "Enter minute (0-59): ";
    cin >> minute;

    while (minute > 59) {
        cout << "Enter a valid minute (0-59): ";
        cin >> minute;
    }

    cout << "Enter second (0-59): ";
    cin >> second;

    while (second > 59) {
        cout << "Enter a valid second (0-59): ";
        cin >> second;
    }
}


// Controls the program.
int main() {
    unsigned int choice;

    getInitialTime();

    do {
        printMenu();

        choice = getMenuChoice(4);

        if (choice == 1) {
            addOneHour();
            displayClocks();
        }
        else if (choice == 2) {
            addOneMinute();
            displayClocks();
        }
        else if (choice == 3) {
            addOneSecond();
            displayClocks();
        }

    } while (choice != 4);

    cout << endl << "Program ended." << endl;

    return 0;
}