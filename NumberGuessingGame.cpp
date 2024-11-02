# include<iostream>
# include<cstdlib>
# include<ctime>
using namespace std;

// Function to generate a random number in range [1, 500] both included
int generateRandomNumber() {
    return (rand() % 500) + 1;
}

// Function to play the game
void playGame() {
    int random_num = generateRandomNumber();
    int guess;

    cout << "\nI've generated a random number between 1 and 500. Try to guess it!" << endl;
    int cnt=0;

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;
        cnt++;

        if (guess - random_num >=50) {
            cout << "Too high! Try guessing a much lower number.\n";
        } 
        else if ( guess - random_num>=25) {
            cout << "High ! Try guessing a lower number.\n";
        } 
        else if ( random_num- guess >=50 ) {
            cout << "Too low ! Try guessing a much higher number.\n";
        } 
        else if ( random_num- guess >=25 ) {
            cout << "Low ! Try guessing a higher number.\n";
        } 

        else {
            cout << "Congratulations! You guessed the number correctly in "<<cnt<<" steps" << endl;
            break;
        }

    }
}


int main() {
     // Seeding  rand() with current time to ensure that different numbers are generated  each time
    srand(static_cast<unsigned int>(time(0)));
    cout<<"<-------------------------------------------------------------------------------------------------->"<<endl;
    cout << "Welcome to the Number Guessing Game!!" << endl;
    char choice;

    do {
        playGame();
        cout << "\nWould you like to play again? Enter y for yes and n for no : ";
        cin >> choice;
    } 
    while (choice == 'y' || choice == 'Y');

    cout << "Thank you for playing! GOODBYE!!" << endl;

}
