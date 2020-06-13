#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum;
void *runner01(void *param);
void *runner02(void *param);

typedef struct ARGV
{
    char* a;
    pthread_t b;
}ARGV;


int main(int argc, char *argv[])
{
    sum = 0;
    pthread_t tid01;
    pthread_t tid02;
    pthread_attr_t attr;
    if (argc != 2)
    {
        fprintf(stderr, "Usage: a.out <intager value>\n");
        return -1;
    }
    if (atoi(argv[1]) <= 0)
    {
        fprintf(stderr, "%d must be > 0\n", atoi(argv[1]));
        return -1;
    }

    pthread_attr_init(&attr);

    pthread_create(&tid01, &attr, runner01, argv[1]);
    pthread_create(&tid02, &attr, runner02, argv[1]);

    pthread_join(tid01, NULL);
    pthread_join(tid02, NULL);
    
    pthread_exit(0);
    return 0;
}

void *runner01(void *param)
{
    int i;
    int upper = atoi(param);
    for (i = 1; i <= upper; i++)
    {
        sum += i;
    }
    printf("[thread 1] sum = %d\n", sum);
}

void *runner02(void *param)
{
    int i;
    int lower = atoi(param);
    for (i = 1; i <= lower; i++)
    {
        sum -= i;
    }
    printf("[thread 2] sum = %d\n", sum);
}
