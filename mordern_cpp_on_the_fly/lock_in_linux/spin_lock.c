#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_spinlock_t lock;
int count = 0;

void *thread_func(void *arg) {
    int i;
    for (i = 0; i < 1000000; i++) {
        pthread_spin_lock(&lock);
        count++;
        pthread_spin_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_spin_init(&lock, PTHREAD_PROCESS_PRIVATE);
    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_create(&t2, NULL, thread_func, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_spin_destroy(&lock);
    printf("count: %d\n", count);
    return 0;
}