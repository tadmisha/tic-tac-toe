#include <iostream>
#define BOOL_CHAR(x_or_o) ((x_or_o) ? 'X' : 'O')


bool is_draw(int turn) {
    if (turn == 9) {
        return true;
    }
    return false;
}

bool is_win(char board[3][3]) {
    bool iswin = 
    (((board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != '-') or 
      (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != '-') or
      (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != '-'))
    or
     ((board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != '-') or
      (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != '-') or
      (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != '-'))
    or
     ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != '-') or
      (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != '-')));

    return iswin;
}

void print_board(char board[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            std::cout << board[row][col] << " ";
        }

        std::cout << std::endl;
    }
}


bool make_turn(bool x_or_o, char (*board)[3]) {
    int row;
    int col;

    char type = (x_or_o) ? 'X' : 'O';

    std::cout << "Input row: ";
    std::cin >> row;

    std::cout << "Input column: ";
    std::cin >> col;

    bool cell_is_empty = (board[row-1][col-1] != '-') ? true : false;

    if (!cell_is_empty) {
        board[row-1][col-1] = type;
        return false;
    }

    std::cout << "\nThis cell is already taken, try again.\n" << std::endl;
    return true;
}


int main() {
    char board[3][3] = {{'-','-','-'},
                        {'-','-','-'}, 
                        {'-','-','-'}};
    
    char (*board_ptr)[3] = board;

    int turn = 1;

    bool x_or_o = 1;
    bool cell_is_empty;

    while (true) {
        cell_is_empty = true;
        print_board(board);
        std::cout << "\n\n";
        std::cout << "Now it's " << BOOL_CHAR(x_or_o) << " turn.\n" << std::endl; 

        while (cell_is_empty) {
            cell_is_empty = make_turn(x_or_o, board_ptr);
        }

        if (is_win(board)) {
            std::cout << std::endl;
            print_board(board);
            std::cout << "\n\nYou won!" << std::endl;
            break;
        }  

        if (is_draw(turn)) { 
            std::cout << std::endl;
            print_board(board);
            std::cout << "\n\nIt's a draw!" << std::endl;
            break;
        }

        turn++;

        x_or_o = !x_or_o;
    }

    return 0;
}
