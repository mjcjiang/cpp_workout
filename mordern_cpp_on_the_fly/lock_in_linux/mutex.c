#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *thread_func(void *arg) {
    pthread_mutex_lock(&mutex);
    printf("Thread %d is accessing the shared resource.\n", *(int *)arg);
    pthread_mutex_unlock(&mutex);
}

int main() {
    pthread_t threads[5];
    int thread_args[5] = {1, 2, 3, 4, 5};
    int i;

    pthread_mutex_init(&mutex, NULL);
    
    for(i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, thread_func, &thread_args[i]);
    }

    for(i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    
    return 0;
}