#include <stdio.h>

int table[4][4][4];

int MAX_N = 2000;
int MAX_M = 500;
/*
 * 
 */
void getBinary(char hex, int *result) {
    int t;
    if (hex >= '0' && hex <= '9') {
        t = hex - '0';

    } else {
        t = hex - 'A' + 10;
    }
    *result = t;
}

int getSum(int *start) {
    int c = (start[0] + start[2] + start[4] + start[6]) * 3 + start[1] 
            + start[3] + start[5] + start[7];
    if(c % 10 == 0) {
        return start[0] + start[2] + start[4] + start[6] + start[1] 
            + start[3] + start[5] + start[7];
    }else {
        return 0;
    }
}

int main(int argc, char** argv) {
    
    table[1][0][0] = 0;
    table[1][1][0] = 1;
    table[0][1][1] = 2;
    table[3][0][0] = 3;
    table[0][2][1] = 4;
    table[1][2][0] = 5;
    table[0][0][3] = 6;
    table[2][0][1] = 7;
    table[1][0][2] = 8;
    table[0][0][1] = 9;
    
    int case_num;
    int i, j, k;
    scanf("%d", &case_num);
    
    for(i = 0; i < case_num; i++) {
        int N, M;
        scanf("%d %d", &N, &M);
        char data[N][M];
        /* full file data */
        for(j = 0; j < N; j++) {
            char str[MAX_M];
            scanf("%s", str);
            for(k = 0; k < M; k++) {
                data[j][k] = str[k];
            }
        }
        
        int sum = 0;
        int code[8];
        /* find all hex code */
        for(j = 0; j < N; j++) {
            for(k = (M - 1); k >= 0; k--) {
                if(data[j][k] != '0' && (data[j - 1][k] != data[j][k])) {
                    int bit = 0;
                    int tmp, l;
                    getBinary(data[j][k], &tmp);
                    
                    while (k >= 13) {
                        while (1 == 1) {
                            if ((tmp & 0x1) == 0) {
                                tmp = tmp >> 1;
                                bit++;
                            } else {
                                break;
                            }
                        }

                        for (l = 7; l >= 0; l--) {
                            int x = 0; 
                            int y = 0; 
                            int z = 0; 
                            int min;
                            do {
                                z++;
                                if (bit != 3) {
                                    tmp = tmp >> 1;
                                    bit++;
                                } else {
                                    getBinary(data[j][--k], &tmp);
                                    bit = 0;
                                }
                            } while ((tmp & 0x1) == 1);

                            do {
                                y++;
                                if (bit != 3) {
                                    tmp = tmp >> 1;
                                    bit++;
                                } else {
                                    getBinary(data[j][--k], &tmp);
                                    bit = 0;
                                }
                            } while ((tmp & 0x1) == 0);

                            do {
                                x++;
                                if (bit != 3) {
                                    tmp = tmp >> 1;
                                    bit++;
                                } else {
                                    getBinary(data[j][--k], &tmp);
                                    bit = 0;
                                }
                            } while ((tmp & 0x1) == 1);

                            if (x < y) {
                                min = x;
                            } else {
                                min = y;
                            }
                            if (min < z) {
                                min = min;
                            } else {
                                min = z;
                            }

                            x = x / min - 1;
                            y = y / min - 1;
                            z = z / min - 1;

                            int num = table[x][y][z];
                            code[l] = num;
                            if (l == 0) {
                                sum = getSum(code) + sum;
                            }
                        }
                    }
                }
            }
        }
        
        printf("%d %d\n", (i + 1), sum);
    }

    return (0);
}

