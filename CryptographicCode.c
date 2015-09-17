#include <stdio.h>
#include <stdlib.h>

int table[2][2][2][2][2][2][2];

/*
 * 
 */
int main(int argc, char** argv) {
    
    table[0][0][0][1][1][0][1] = 0;
    table[0][0][1][1][0][0][1] = 1;
    table[0][0][1][0][0][1][1] = 2;
    table[0][1][1][1][1][0][1] = 3;
    table[0][1][0][0][0][1][1] = 4;
    table[0][1][1][0][0][0][1] = 5;
    table[0][1][0][1][1][1][1] = 6;
    table[0][1][1][1][0][1][1] = 7;
    table[0][1][1][0][1][1][1] = 8;
    table[0][0][0][1][0][1][1] = 9;
    
    

    return (EXIT_SUCCESS);
}

