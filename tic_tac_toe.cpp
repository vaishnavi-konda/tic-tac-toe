#include <iostream>
using namespace std;

char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};


void print_board();
bool isGameOver();
bool isEqual(char a, char b, char c);


int main()
{
    cout << "\nTIC-TAC-TOE Game\n\n";
    cout << "The board is numbered like the keyboard's number pad.\nYou can make a move in the game board by entering the number from the keyboard number pad." << endl;
    cout << "       |       |       " << endl;
    cout << "   7   |   8   |   9   " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   4   |   5   |   6   " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   1   |   2   |   3   " << endl;
    cout << "       |       |       " << endl;    
    
    char currentPlayer = 'X';
    int count = 1;

    while (count < 10)
    {
        int choice;

        cout << "It's Player " << currentPlayer << "'s turn. Move to which place?  ";
        cin >> choice;

        if (choice < 1 || choice > 9 || board[choice - 1] != ' ')
        {
            cout << "Invalid move! Please choose another place" << endl;
            continue;
        }

        count++;
        
        board[choice - 1] = currentPlayer;

        print_board();

        if (count >= 5 && isGameOver())
        {
            cout << "Game Over." << endl;
            cout << "Congratulations! " << currentPlayer << " WON";
            exit(0);
        }    

        if (currentPlayer == 'X')
        {
            currentPlayer = 'O';
        }
        else
        {
            currentPlayer = 'X';
        }
    }

    cout << "No one wins!\nDraw!";
    return 0;
}


void print_board()
{
    cout << "       |       |       " << endl;
    cout << "   " << board[6] << "   |   " << board[7] << "   |   " << board[8] << "   " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   " << board[3] << "   |   " << board[4] << "   |   " << board[5] << "   " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   " << board[0] << "   |   " << board[1] << "   |   " << board[2] << "   " << endl;
    cout << "       |       |       " << endl;
}


bool isGameOver()
{
   // Check if any row has same characters
    if (isEqual(board[0], board[1], board[2]))
    {
        return true;
    }
    
    if (isEqual(board[3], board[4], board[5]))
    {
        return true;
    }

    if (isEqual(board[6], board[7], board[8]))
    {
        return true;
    }

    // Check if any column has same characters
    if (isEqual(board[0], board[3], board[6]))
    {
        return true;
    }

    if (isEqual(board[1], board[4], board[7]))
    {
        return true;
    }

    if (isEqual(board[2], board[5], board[8]))
    {
        return true;
    }

    // Check if any diagonal has same characters
    if (isEqual(board[2], board[4], board[6]))
    {
        return true;
    }

    if (isEqual(board[0], board[4], board[8]))
    {
        return true;
    }

    return false;
}

bool isEqual(char a, char b, char c)
{
    return ((a == b) && (b == c) && a != ' ');
}