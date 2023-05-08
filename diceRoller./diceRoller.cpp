#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL)); // seed the random number generator

    int dice = 0;
    int roll = 0;
    char choice;

    do {
        cout << "Roll the dice? (y/n): ";
        cin >> choice;

        if (choice == 'y') {
            dice = rand() % 6 + 1; // generate a random number between 1 and 6
            cout << "You rolled a " << dice << endl;
            roll++;
        }

    } while (choice == 'y');

    cout << "You rolled the dice " << roll << " times." << endl;

    return 0;
}
