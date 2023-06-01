#include <stdio.h>
#include <pthread.h>

pthread_rwlock_t rwlock;
int data = 0;

void *read_thread(void *arg)
{
    int i;
    for (i = 0; i < 10; i++) {
        pthread_rwlock_rdlock(&rwlock);
        printf("Read thread: %d, data is: %d\n", i, data);
        pthread_rwlock_unlock(&rwlock);
    }
    return NULL;
}

void *write_thread(void *arg)
{
    int i;
    for (i = 0; i < 10; i++) {
        pthread_rwlock_wrlock(&rwlock);
        data = i + 1;
        printf("Write thread: %d, data is: %d\n", i, data);
        pthread_rwlock_unlock(&rwlock);
    }
    return NULL;
}

int main()
{
    pthread_t tid1, tid2;

    pthread_rwlock_init(&rwlock, NULL);

    pthread_create(&tid1, NULL, read_thread, NULL);
    pthread_create(&tid2, NULL, write_thread, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_rwlock_destroy(&rwlock);
    return 0;
}