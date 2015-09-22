#include <stdio.h>

int table[2][2][2][2][2][2][2];

int getResult(int data[100][100], int N, int M) {
    int result = 0;
    int code[8];
    int i, j, a;

    for (i = 0; i < N; i++) {
        for (j = (M - 1); j >= 0; j--) {
            if (data[i][j] == 1) {
                int left = j - 55;
                for (a = 0; a < 8; a++) {
                    code[a] = table[data[i][left]][data[i][left + 1]][data[i][left + 2]][data[i][left + 3]][data[i][left + 4]][data[i][left + 5]][data[i][left + 6]];
                    left += 7;
                }
                int check = (code[0] + code[2] + code[4] + code[6]) * 3 + (code[1] + code[3] + code[5] + code[7]);
                if (check % 10 == 0) {
                    result = code[0] + code[1] + code[2] + code[3] + code[4] + code[5] + code[6] + code[7];
                }
                return result;
            }
        }
    }

    return result;

}

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
        int result = getResult(data, N, M);
        printf("#%d %d\n", (i + 1), result);
    }
    return 0;
}
