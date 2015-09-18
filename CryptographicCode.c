#include <stdio.h>

int table[2][2][2][2][2][2][2];

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
    result[3] = t & 1;
    result[2] = t >> 1 & 1;
    result[1] = t >> 2 & 1;
    result[0] = t >> 3 & 1;
}

int getSum(int *start, int size) {
    int width = size / 56;
    int code[8];
    int i = 7;
    int j = size - 1;
    for(; j >=0; j--) {
        if(start[j] == 0) {
            continue;
        }
        code[i--] = table[start[(j - 6*width)]][start[j - 5*width]][start[j - 4*width]][start[j - 3*width]][start[j - 2*width]][start[j - 1*width]][start[j]];
        j = j - 6*width - (width - 1);
        if(i < 0) {
            break;
        }
    }
    int c = (code[0] + code[2] + code[4] + code[6]) * 3 + code[1] + code[3] + code[5] + code[7];
    if(c % 10 == 0) {
        return code[0] + code[1] + code[2] + code[3] + code[4] + code[5] + code[6] + code[7];
    }else {
        return 0;
    }
}

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
        /* find all hex code */
        for(j = 0; j < N; j++) {
            for(k = 0; k < M; k++) {
                char tmp = data[j][k];
                /* 0 */
                if(tmp == '0') {
                    continue;
                }
                
                int right_col = k + 1;
                int down_row = j + 1;
                for(; right_col < M; right_col++) {
                    if(data[j][right_col] == '0') {
                        int l;
                        int flag = 0;
                        for(l = (right_col + 1); l < M; l++) {
                            if(data[j][l] != '0' && (l - right_col) <= 6) {
                                flag = 1;
                                break;
                            }
                        }
                        if(flag == 1) {
                            continue;
                        }else {
                            break;
                        }
                    }else {
                        continue;
                    }
                }
                /* data[j][k] - data[j][right_col - 1] */
                int hex_w = right_col - k;
                int num_0 = 24;
                int binary_array[hex_w * 4 + num_0];
                int t = 0;
                for(t = 0; t < num_0; t++) {
                    binary_array[t] = 0;
                }
                int a = num_0;
                int b = k;
                for(; b < (right_col); b++) {
                    int tmp[4]; 
                    getBinary(data[j][b], tmp);
                    binary_array[a++] = tmp[0];
                    binary_array[a++] = tmp[1];
                    binary_array[a++] = tmp[2];
                    binary_array[a++] = tmp[3];
                }
                sum += getSum(binary_array, (hex_w * 4 + num_0));
                
                /* remove code */
                for(; down_row < N; down_row++) {
                    if(data[down_row][k] == '0'){
                        break;
                    }
                }
                /* data[j][k] - data[down_row - 1][k] */
                for(a = j; a < (down_row); a++) {
                    for(b = k; b < (right_col); b++) {
                        data[a][b] = '0';
                    }
                }
            }
        }
        
        printf("%d %d\n", (i + 1), sum);
    }

    return (0);
}

