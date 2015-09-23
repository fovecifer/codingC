#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int isBiggest(int data[6], int size) {
    int i;
    for(i = 0; i < (size - 2); i++) {
        if(data[i] < data[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int hasSameNum(int data[6], int size) {
    int tmp[10] = {0};
    int i;
    for(i = 0; i < size; i++) {
        if(tmp[data[i]] == 1) {
            return 1;
        }else {
            tmp[data[i]] = 1;
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    int case_num;
    int i;
    scanf("%d\n", &case_num);
    for(i = 1; i <= case_num; i++) {
        int t1, switch_times, size;
        int data[6];
        for(size = 0; size < 6; size++) {
            data[size] = -1;
        }
        size = 0;
        
        while(1) {
            char t = getchar();
            if(t != ' ') {
                data[size++] = t - '0';
            }else {
                break;
            }
        }
        scanf("%d\n", &switch_times);
        
        int left_p = 0;
        for(t1 = switch_times; t1 > 0; t1--) {
            if(isBiggest(data, size) == 1) {
                if(t1 % 2 == 0) {
                    t1 = 0;
                }else {
                    if(hasSameNum(data, size) == 1) {
                        t1 = 0;
                        break;
                    }
                    int tmp = data[size - 1];
                    data[size - 1] = data[size - 2];
                    data[size - 2] = tmp;
                    t1 = 0;
                }
            }else {
                /* find biggest number from right */
                int max = 0;
                int max_num = 0; 
                int j;
                int max_pos = -1;
                for(j = (size - 1); j >=left_p; j--) {
                    max = (data[j] > max) ? data[j] : max;
                }
                for(j = (size - 1); j >=left_p; j--) {
                    if(data[j] == max) {
                        if(max_pos == -1) {
                            max_pos = j;
                        }
                        ++max_num;
                    }
                }
                
                if(data[left_p] == max) {
                    left_p++;
                    t1++;
                    continue;
                }
                
                if(max_num == 1 || t1 == 1) {
                    if(max == data[left_p]) {
                        left_p++;
                        t1++;
                        continue;
                    }else {
                        data[max_pos] = data[left_p];
                        data[left_p] = max;
                        left_p++;
                    }
                }else {
                    int remain_times = t1;
                    int smaller_than_max = 0;
                    for(j = (max_pos - 1); j >= left_p; j--) {
                        if(data[j] < max) {
                            smaller_than_max++;
                        }
                    } 
                    int k = (remain_times < smaller_than_max) ? remain_times : smaller_than_max;
                    k = (k < max_num) ? k : max_num;
                    
                    int tmp[10] = {0};
                    for(j = (max_pos - 1); j >= left_p; j--) {
                        if(data[j] == max) {
                            continue;
                        }
                        tmp[data[j]]++;
                    }
                    int l = 0;
                    for(j = 9; j >=0; j--) {
                        if(tmp[j] != 0) {
                            k--;
                            if(k == 0) {
                                l = j;
                                break;
                            }
                        }
                    }
                    for(j = (max_pos - 1); j >= left_p; j--) {
                        if(data[j] == l) {
                            data[max_pos] = data[j];
                            data[j] = max;
                            break;
                        }
                    }
                    
                }
            }
        }
        printf("#%d ", i);
        for(t1 = 0; t1 < size; t1++) {
            printf("%d", data[t1]);
        }
        printf("\n");
    }

    return (EXIT_SUCCESS);
}

