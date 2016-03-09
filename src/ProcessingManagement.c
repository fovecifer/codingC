#include <stdio.h>
#include <stdlib.h>

typedef struct _plate_t {
    int length;
    int width;
} plate_t;

int N;  // 1 <= N <= 5000
int Li[5000];
int Wi[5000];
int Answer;

int compare(plate_t *p1, plate_t *p2) {
    if(p1->length != p2->length) {
        return (p1->length > p2->length ? 1 : -1);
    }else if(p1->width == p2->width){
        return 0;
    }else {
        return (p1->width > p2->width ? 1 : -1);
    }
}

void insertion_sort_asc(int size, plate_t **plates) {
    int i, j;
    for(i = 1; i < size; i++) {
        plate_t *tmp = plates[i];
        for(j = (i - 1); j >= 0; j--) {
            if(compare(tmp, plates[j]) < 0) {
                plates[j + 1] = plates[j];
            }else {
                break;
            }
        }
        plates[j + 1] = tmp;
    }
}

int getAnswer(int N, plate_t **plates) {
    int answer = 0;
    insertion_sort_asc(N, plates);
    int remain = N;
    while(remain > 0) {
        int i, j, current;
        for(i = 0; i < N; i++) {
            if(plates[i] == NULL) {
                continue;
            }
            current = plates[i]->width;
            free(plates[i]);
            plates[i] = NULL;
            remain--;
            for(j = (i + 1); j < N; j++) {
                if(plates[j] != NULL && plates[j]->width >= current) {
                    current = plates[j]->width;
                    free(plates[j]);
                    plates[j] = NULL;
                    remain--;
                }
            }
            answer++;
        }
    }
    return answer;
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
                plate_t ** plates = (plate_t **)malloc(N * (sizeof(plate_t *)));
		for(i=0; i < N; i++)
		{
			scanf("%d %d", &Li[i], &Wi[i]);
                        plate_t *plate = (plate_t *)malloc(sizeof(plate_t));
                        plate->length = Li[i];
                        plate->width = Wi[i];
                        plates[i] = plate;
		}
		
		/**********************************
		*  Implement your algorithm here. *
		***********************************/
		Answer = getAnswer(N, plates);
		
		// Print the answer to standard output(screen).
		printf("%d\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}
