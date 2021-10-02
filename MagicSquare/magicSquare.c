#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isMagicSquare(int array[3][3]);

int isMagicSquare(int array[3][3]) {
    
    for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
               int number = array[row][col];
               if (number < 1 || number > 9) 
                 {
                   return 0;
                 }
            }
        }

    //getting sum of diagonals; topleft => bottomright: row = col; topright => bottom left: row(0-3), col(3-0)
    int diagonalTotal1 = 0;
    int diagonalTotal2 = 0;
    int col = 2;
    for (int i = 0; i < 3; i++) {
        diagonalTotal1 += array[i][i];
        diagonalTotal2 += array[i][col-i];
    }
    //checking if diagonal sums are equal to each other
    if (diagonalTotal1 != diagonalTotal2) {
        return 0;
    }

    //getting row and column total; checking if theyre equal to each other and diagonal
   
    for (int row = 0; row < 3; row++) {
        int rowTotal = 0;
        int colTotal = 0;
        for (int col = 0; col < 3; col++)
        {
            rowTotal += array[row][col];
            colTotal += array[col][row];
        }
        if (rowTotal != colTotal || colTotal != diagonalTotal1) {
            return 0;
        }
     }      
    
    return 1;

}
        

int main() {
    int magicSquare[3][3] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };

    int notMagicSquare[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    
    printf("Magic Square:\n");
    for (int i=0; i < 3; i++) {
        for (int j=0; j<3; j++) {
            printf("%d ", magicSquare[i][j]);
            if (j == 2) {
                printf("\n");
            }
        }
    }

    if (isMagicSquare(magicSquare) == 1) {
        printf("Array is a Lo Shu Magic Square!\n");
    }
    else {
        printf("Array is NOT a Lo Shu Magic Square.\n");
    }

    printf("Magic Square:\n");
        for (int i=0; i < 3; i++) {
            for (int j=0; j<3; j++) {
                printf("%d ", notMagicSquare[i][j]);
                if (j == 2) {
                    printf("\n");
                }
            }
        }

    if (isMagicSquare(notMagicSquare) == 1) {
        printf("Array is a Lo Shu Magic Square!\n");
    }
    else {
        printf("Array is NOT a Lo Shu Magic Square.\n");
    }
    
    

}