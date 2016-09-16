//#pragma GCC optimize ("O0")
typedef unsigned char u8int;
bool find_path(char** board, int boardRowSize, int boardColSize, char* word, u8int** _check, int lastRowPos, int lastColPos, int i);
bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    if (strlen(word) <= 0) return false;
    // Checkboard
    u8int check[boardRowSize][boardColSize];
    memset(check, 0, sizeof(check[0][0])*boardRowSize * boardColSize);
    int r, c;
    bool bflag = 0;
    for (r = 0; r < boardRowSize; r++){
        for (c = 0; c < boardColSize; c++){
            if (find_path(board, boardRowSize, boardColSize, word, check, r, c, 0))
                return true;
        }
    }
    return false;
}

bool find_path(char** board, int boardRowSize, int boardColSize, char* word, u8int** _check, int lastRowPos, int lastColPos, int i) {
    u8int check[boardRowSize][boardColSize];
    memcpy(check, _check, sizeof(check[0][0])*boardRowSize*boardColSize);
    if (word[i] != board[lastRowPos][lastColPos] || check[lastRowPos][lastColPos])
        return false;
    check[lastRowPos][lastColPos] = 1;
    if (i == strlen(word)-1) return true;
    i++;
    // Check East
    if (lastColPos+1 < boardColSize){
        if (find_path(board, boardRowSize, boardColSize, word, check, lastRowPos, lastColPos+1, i)) return true;
    }
    // Check West
    if (lastColPos > 0){
        if (find_path(board, boardRowSize, boardColSize, word, check, lastRowPos, lastColPos-1, i)) return true;
    }
    // Check North
    if (lastRowPos > 0){
        if (find_path(board, boardRowSize, boardColSize, word, check, lastRowPos-1, lastColPos, i)) return true;
    }
    // Check South
    if (lastRowPos+1 < boardRowSize){
        if (find_path(board, boardRowSize, boardColSize, word, check, lastRowPos+1, lastColPos, i)) return true;
    }
    check[lastRowPos][lastColPos] = 0;
    return false;
}