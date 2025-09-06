#include <stdbool.h>

int charToValue(char input){
    if(input == '.'){
        return -1;
    }
    return input - '1';
}

void init_table(int* data, int size){
    for(int i=0; i<size; i++){
        data[i] = 0;
    }
}


bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int freqTable[9];
    int currSudokuValue;
    
    
    for(int i=0; i<9; i++){
        // row check
        init_table(freqTable, 9);
        for(int j=0; j<9; j++){
            currSudokuValue = charToValue(board[i][j]);
            if(currSudokuValue != -1){
                freqTable[currSudokuValue]++;
            }
        }
        for(int j=0; j<9; j++){
            if(freqTable[j] > 1){
                return false;
            }
        }
        // column check
        init_table(freqTable, 9);
        for(int j=0; j<9; j++){
            currSudokuValue = charToValue(board[j][i]);
            if(currSudokuValue != -1){
                freqTable[currSudokuValue]++;
            }
        }
        for(int j=0; j<9; j++){
            if(freqTable[j] > 1){
                return false;
            }
        }
    }
    // sub-box check
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            init_table(freqTable, 9);
            for(int k=0; k<3; k++){
                for(int z=0; z<3; z++){
                    currSudokuValue = charToValue(board[i*3+k][j*3+z]);
                    if(currSudokuValue != -1){
                        freqTable[currSudokuValue]++;
                    }
                }
            }
            for(int j=0; j<9; j++){
                if(freqTable[j] > 1){
                    return false;
                }
            }
        }
    }
    return true;
}

