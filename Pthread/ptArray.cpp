// #include <pthread.h>
// #include <windows.h>

// #define n 10
// #define thread_num 2

// int arr[n] = {1, 2, 3, 4, 5, 3, 2, 1, 5, 5};

// void *routine(void *arg)
// {
//     int *index = (int*)arg;
//     int sum = 0;
// }

// int main()
// {
//     pthread_t th[thread_num];
//     for (int i = 0; i < thread_num; i++)
//     {
//         if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
//         {
//             perror("Failed to create thread");
//         }
//     }
// }
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

void* routine(void* arg) {
    int index = *(int*)arg;
    int sum = 0;
    for (int j = 0; j < 5; j++) {
        sum += primes[index + j];
    }
    printf("Local sum: %d\n", sum);
    *(int*)arg = sum;
    return arg;
}

int main(int argc, char* argv[]) {
    pthread_t th[2];
    int i;
    for (i = 0; i < 2; i++) {
        int* a = (int*)malloc(sizeof(int));
        *a = i * 5;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("Failed to create thread");
        }
    }
    int globalSum = 0;
    for (i = 0; i < 2; i++) {
        int* r;
        if (pthread_join(th[i], (void**) &r) != 0) {
            perror("Failed to join thread");
        }
        globalSum += *r;
        free(r);
    }
    printf("Global sum: %d\n", globalSum);
    return 0;
}

