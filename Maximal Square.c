#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
     
#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    int dyna[matrixRowSize][matrixColSize];
    memset(dyna, 0, sizeof dyna);
    int gmax = 0;
    // Corner case: 1st row and col
    for (int i = 0; i < matrixRowSize; i++){
        dyna[i][0] = matrix[i][0] - '0';
        gmax = max(dyna[i][0], gmax);
    }
    for (int i = 0; i < matrixColSize; i++){
        dyna[0][i] = matrix[0][i] - '0';
        gmax = max(dyna[0][i], gmax);
    }
    
    for (int i = 1; i < matrixRowSize; i++){
        for (int j = 1; j < matrixColSize; j++){
            if (matrix[i][j] == '0') dyna[i][j];
            else dyna[i][j] = min(dyna[i-1][j-1], min(dyna[i-1][j], dyna[i][j-1])) + 1;
            gmax = max(dyna[i][j], gmax);
        }
    }
    return gmax * gmax;
}