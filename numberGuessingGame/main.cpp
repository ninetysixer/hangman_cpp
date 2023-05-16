#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));  // Seed the random number generator with the current time
    int secretNumber = rand() % 100 + 1;  // Generate a random number between 1 and 100
    int guess;
    int tries = 0;
    bool guessed = false;
    
    cout << "I'm thinking of a number between 1 and 100. Can you guess it?" << endl;
    
    while (!guessed && tries < 10) {
        cout << "Enter your guess: ";
        cin >> guess;
        tries++;
        
        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the number in " << tries << " tries." << endl;
            guessed = true;
        } else if (guess < secretNumber) {
            cout << "Too low. Try again." << endl;
        } else {
            cout << "Too high. Try again." << endl;
        }
    }
    
    if (!guessed) {
        cout << "Sorry, you ran out of tries. The number was " << secretNumber << "." << endl;
    }
    
    return 0;
}
