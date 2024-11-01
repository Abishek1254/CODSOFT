#include <iostream>
using namespace std;

// function to display the game board as it looks drawn on a paper
void displayBoard ( char board[][3]) {

cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
cout<<"__|___|__"<<endl;
cout<<"  |   |  "<<endl;
cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
cout<<"__|___|__"<<endl;
cout<<"  |   |  "<<endl;
cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;

}

// function for a player to make a move
bool move(char board[][3], char player, int x, int y) {
    if(x <=0 || x>=4 || y<=0 || y>=4) {
    cout<<"Invalid move .Please enter again "<<endl;
    return false;
    }

    if (board[x-1][y-1] == '-') {
        board[x-1][y-1] = player;
        return true;
    } 
    
    cout << "Cell is already taken! Choose another cell." << endl;
    return false;
    
}

// function to check for win
bool checkWin(char board[][3]) {
    // row-wise or column-wise win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            cout << "Congratulations Player " << board[i][0] << ", you have won!!" << endl;
            return true;
        }
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            cout << "Congratulations Player " << board[0][i] << ", you have won!!" << endl;
            return true;
        }
    }
    
    //diagonal-wise win
    if (board[0][0] !='-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        cout << "Congratulations Player " << board[0][0] << ", you have won!!" << endl;
        return true;
    }
    if (board[0][2] !='-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        cout << "Congratulations Player " << board[0][2] << ", you have won!!" << endl;
        return true;
    }

    return false;
}



int main () {
    char board[3][3]= { 
        {'-','-','-' } ,
        {'-','-','-' } ,
        {'-','-','-' } 
    };

    cout << "\nWelcome to 'Tic Tac Toe' Game. Two players take turns to play." << endl;
    cout << "Player X uses 'X' and Player O uses 'O' " << endl;
    cout << " - represents empty cells. These are available for moves\n" << endl;
    cout<<"Inital configuration of board is as follows :"<<endl;
    displayBoard(board);
    cout<<"Let's start the match between player X and player O !! "<<endl;

    char ch = 'y';
    while (ch == 'y' || ch == 'Y') {
        // Reset board for a new game
        char board[3][3]= { 
        {'-','-','-' } ,
        {'-','-','-' } ,
        {'-','-','-' } 
    };
        
        int cnt = 0;
        bool win = false;

        while ( cnt < 9 && !win ) {
            int x, y;
            bool validMove = false;

            // Player X's turn
            while (!validMove) {
                cout << "Player X (X) make your move, enter row no. and column no. (1-3): ";
                cin >> x >> y;
                validMove = move(board, 'X', x, y); // Re-attempt if the move was invalid
            }
            displayBoard(board);
            cnt++;

            if (checkWin(board)) {
                win = true;
                break;
            }

            // Check if board is full
            if (cnt >= 9) 
            break;

            // Player O's turn
            validMove = false;
            while (!validMove) {
                cout << "Player O (O) make your move , enter row no. and column no. (1-3): ";
                cin >> x >> y;
                validMove = move(board, 'O', x, y); // Re-attempt if the move was invalid
            }
            displayBoard(board);
            cnt++;

            if (checkWin(board)) {
                win = true;
                break;
            }

        }

        if (!win)
            cout << "Match Ended .It's a draw!" << endl;

        cout << "Do you want to play again? Enter y for yes and n for no : \n";
        cin >> ch;
    }

    cout << "Thanks for playing Tic Tac Toe !! GoodBye " << endl;




}