#include <stdio.h>

int N;
int data[10000];
int time;

void insertion_sort_desc(int data[], int size) {
    int i, j;
    for(i = 1; i < size; i++) {
        int tmp = data[i];
        for(j = (i - 1); j >= 0; j--) {
            if(tmp > data[j]) {
                data[j + 1] = data[j];
            }else {
                break;
            }
        }
        data[j + 1] = tmp;
    }
}

int compute(int data[], int size) {
    int result = 0;
    while (size > 0) {

        int tmp = data[size - 1] + data[size - 2];
        result += tmp;
        size--;
        int i;
        for (i = (size - 2); i >= 0; i--) {
            if (tmp > data[i]) {
                data[i + 1] = data[i];
            } else {
                break;
            }
        }
        data[i + 1] = tmp;

        if (size == 1) {
            break;
        }
    }

    return result;
}

int main(void)
{
	int test_case;
	int T;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using scanf function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */
	// freopen("input.txt", "r", stdin);

	/*
	   If you remove the statement below, your program's output may not be rocorded
	   when your program is terminated after the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		int i;
		scanf("%d", &N);
		
		for(i = 0; i < N; i++) {
			scanf("%d", &data[i]);
		}

		/**********************************
		 * Implement your algorithm here. *
		 **********************************/
		time = 0;
                
                insertion_sort_desc(data, N);
                time = compute(data, N);
		
		// Print the answer to standard output(screen).
		printf("%d\n",time);
		
	}

	return 0;//Your program should return 0 on normal termination.
}

