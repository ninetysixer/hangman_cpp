#include <iostream>
#include <iomanip>
#include <chrono>

// Function to clear the console screen
void clearScreen() {
    // Use system-specific commands or libraries to clear the console screen
    // This implementation uses the "system" function from the <cstdlib> library
#ifdef _WIN32
    std::system("cls"); // For Windows
#else
    std::system("clear"); // For Unix/Linux/Mac
#endif
}

// Function to display the calendar for a given year and month
void displayCalendar(int year, int month) {
    // Get the current date
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm* currentTm = std::localtime(&currentTime);
    int currentYear = currentTm->tm_year + 1900; // Adjust for the year offset
    int currentMonth = currentTm->tm_mon + 1;    // Adjust for the month offset
    int currentDay = currentTm->tm_mday;         // Get the current day

    // Calculate the first day of the month
    int firstDay = (year * 365 + year / 4 - year / 100 + year / 400 + (13 * (month + 1) / 5) + 1) % 7;

    // Array to store the number of days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust February for leap years
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[1] = 29;

    // Display the month and year
    std::cout << "===============================" << std::endl;
    std::cout << "        " << std::setw(2) << std::setfill('0') << month << "/" << year << std::endl;
    std::cout << "===============================" << std::endl;

    // Display the days of the week
    std::cout << "Su  Mo  Tu  We  Th  Fr  Sa" << std::endl;

    // Display the empty cells before the first day
    for (int i = 0; i < firstDay; ++i)
        std::cout << "    ";

    // Display the days of the month
    for (int day = 1; day <= daysInMonth[month - 1]; ++day) {
        // Set the color to green for the current day
        if (day == currentDay && month == currentMonth && year == currentYear)
            std::cout << "\033[1;32m"; // Set color to green

        std::cout << std::setw(2) << std::setfill('0') << day;
        std::cout << "\033[0m"; // Reset color

        std::cout << "  ";

        // Move to the next line after Saturday
        if ((day + firstDay) % 7 == 0)
            std::cout << std::endl;
    }

    std::cout << std::endl;
}

int main() {	
    // Get the current year and month
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm* currentTm = std::localtime(&currentTime);
    int year = currentTm->tm_year + 1900; // Adjust for the year offset
    int month = currentTm->tm_mon + 1;    // Adjust for the month offset

    char choice;
	

    do {

        // Clear the console screen
        clearScreen();
		std::cout << "Calender Application by semihdursungul\n" << std::endl;
        // Display the calendar for the current month
        displayCalendar(year, month);

        // Prompt the user for next or previous month
        std::cout << "Press 'n' for next month, 'p' for previous month, or 'q' to quit: ";
        std::cin >> choice;

        switch (choice) {
            case 'n':
            case 'N':
                // Increment the current month
                // If it's December, go to the next year
                if (month == 12) {
                    month = 1;
                    year++;
                } else {
                    month++;
                }
                break;

            case 'p':
            case 'P':
                // Decrement the current month
                // If it's January, go to the previous year
                if (month == 1) {
                    month = 12;
                    year--;
                } else {
                    month--;
                }
                break;

            case 'q':
            case 'Q':
                std::cout << "Exiting the calendar application..." << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

    } while (choice != 'q' && choice != 'Q');

    return 0;
}
