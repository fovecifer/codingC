#include <stdio.h>

int table[2][2][2][2][2][2][2];

int main() {
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

    int cases;
    int i, j, k;
    scanf("%d", &cases);

    for (i = 0; i < cases; i++) {
        int N, M;
        int data[100][100];
        scanf("%d %d", &N, &M);
        for (j = 0; j < N; j++) {
            char str[102];
            scanf("%s", str);
            for (k = 0; k < M; k++) {
                data[j][k] = str[k] - 48;
            }
        }
    }
}
