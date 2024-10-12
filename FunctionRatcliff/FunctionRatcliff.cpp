#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time() to seed random numbers

using namespace std;

// Function to roll a single die, returns a random value between 1 and 6
int rollDice() {
    return rand() % 6 + 1; // Generates random numbers from 1 to 6
}

// Function to determine the result of the initial roll
// sum: sum of two dice, point: reference to track established point, 
// continueRolling: flag for continuing to roll, win: flag to indicate win/loss
void checkResult(int sum, int& point, bool& continueRolling, bool& win) {
    // Check for automatic win on first roll (natural)
    if (sum == 7 || sum == 11) {
        win = true; // Player wins
        continueRolling = false; // No need to continue rolling
    }
    // Check for automatic loss (craps)
    else if (sum == 2 || sum == 3 || sum == 12) {
        win = false; // Player loses
        continueRolling = false; // Game over
    }
    // If not a win or loss, establish a point
    else {
        point = sum; // Set the point
        cout << "Point is set to: " << point << endl;
        continueRolling = true; // Continue rolling until 7 or point
    }
}

int main() {
    // Seed random number generator with current time
    srand(time(0));

    char playAgain; // To store player's choice to play again

    // Main game loop, allows the player to play multiple rounds
    do {
        int die1, die2, sum, point = 0; // Variables for dice, sum, and point
        bool continueRolling = false;   // Flag for continuing the game
        bool win = false;               // Flag to track win/loss

        // First roll of the game
        die1 = rollDice(); // Roll first die
        die2 = rollDice(); // Roll second die
        sum = die1 + die2; // Sum the values of the two dice
        cout << "You rolled " << die1 << " + " << die2 << " = " << sum << endl;

        // Check the result of the initial roll
        checkResult(sum, point, continueRolling, win);

        // Loop for subsequent rolls if a point was established
        while (continueRolling) {
            die1 = rollDice(); // Roll first die
            die2 = rollDice(); // Roll second die
            sum = die1 + die2; // Sum the values of the two dice
            cout << "You rolled " << die1 << " + " << die2 << " = " << sum << endl;

            // Check if the player matches the point or rolls a 7
            if (sum == point) {
                win = true;           // Player wins by matching the point
                continueRolling = false; // Stop the game
            }
            else if (sum == 7) {
                win = false;          // Player loses by rolling a 7
                continueRolling = false; // Stop the game
            }
        }

        // Display the final result based on the win/loss flag
        if (win)
            cout << "You win!" << endl;
        else
            cout << "You lose." << endl;

        // Ask the player if they want to play again
        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y'); // Repeat if the player chooses to play again

    return 0; // Exit the program
}
