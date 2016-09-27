#define BOIL \
    if (board[r][c] == '.') continue; \
    else if (isdigit(board[r][c])){ \
        if (board[r][c] == '0' || chk[board[r][c]-'0']) \
            return false; \
            chk[board[r][c]-'0'] = 1; \
    } \
    else return false;

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    char chk[10];
    //memset(chk, 0, sizeof(chk));
    // Check each row
    for (int r = 0; r < boardRowSize; r++){
        memset(chk, 0, sizeof(chk));
        for (int c = 0; c < boardColSize; c++){
            BOIL
        }
    }
    // Check each col
    for (int c = 0; c < boardColSize; c++){
        memset(chk, 0, sizeof(chk));
        for (int r = 0; r < boardRowSize; r++){
            BOIL
        }
    }
    // Check each square 3*3
    for (int rr = 0; rr < boardRowSize; rr += 3){
        for (int cc = 0; cc < boardColSize; cc += 3){
            memset(chk, 0, sizeof(chk));
            for (int r = rr; r < rr+3; r++){
                for (int c = cc; c < cc+3; c++){
                    BOIL
                }
            }
        }
    }
    return true;
}