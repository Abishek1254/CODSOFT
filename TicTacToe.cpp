#include <iostream>
using namespace std;

// function to display the game board after each move
void displayBoard(int board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == -1)
                cout << "- ";
            else
                cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// function for a player to make a move
bool move(int board[][3], int player, int x, int y) {
    if(x>0 && x<4 && y>0 && y<4) {

    if (board[x-1][y-1] == -1) {
        board[x-1][y-1] = player;
        return true;
    } 
    else {
        cout << "Cell is already taken! Choose another cell." << endl;
        return false;
    }

    }

    else {
        cout<<"Invalid move .Please enter again "<<endl;
    return false;
    }

}

// function to check for win
bool checkWin(int board[3][3]) {
    // row-wise or column-wise win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != -1 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            cout << "Congratulations Player " << board[i][0] << ", you have won!!" << endl;
            return true;
        }
        if (board[0][i] != -1 && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            cout << "Congratulations Player " << board[0][i] << ", you have won!!" << endl;
            return true;
        }
    }
    
    //diagonal-wise win
    if (board[0][0] != -1 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        cout << "Congratulations Player " << board[0][0] << ", you have won!!" << endl;
        return true;
    }
    if (board[0][2] != -1 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        cout << "Congratulations Player " << board[0][2] << ", you have won!!" << endl;
        return true;
    }

    return false;
}

int main() {
    // 3*3 matrix designed for game 
    int board[3][3] = {
        {-1, -1, -1},
        {-1, -1, -1},
        {-1, -1, -1}
    };

    cout << "\nWelcome to 'Tic Tac Toe' Game. Two players take turns to play." << endl;
    cout << "Player 1 uses '1' and Player 0 uses '0'." << endl;
    cout << "- represents empty cells. These are available for moves\n" << endl;

    char ch = 'y';

    while (ch == 'y' || ch == 'Y') {
        // Reset board for a new game
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = -1;
        
        int cnt = 0;
        bool win = false;

        while (cnt < 9 && !win) {
            int x, y;
            bool validMove = false;

            // Player 1's turn
            while (!validMove) {
                cout << "Player 1 (1) make your move, enter row and column (1-3): ";
                cin >> x >> y;
                validMove = move(board, 1, x, y); // Re-attempt if the move was invalid
            }
            displayBoard(board);
            cnt++;

            if (checkWin(board)) {
                win = true;
                break;
            }

            // Check if board is full
            if (cnt >= 9) break;

            // Player 0's turn
            validMove = false;
            while (!validMove) {
                cout << "Player 0 (0) make your move , enter row and column (1-3): ";
                cin >> x >> y;
                validMove = move(board, 0, x, y); // Re-attempt if the move was invalid
            }
            displayBoard(board);
            cnt++;

            if (checkWin(board)) {
                win = true;
                break;
            }
        }

        if (!win)
            cout << "Mtach Ended .It's a draw!" << endl;

        cout << "Do you want to play again? Enter y for yes and n for no: ";
        cin >> ch;
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}
