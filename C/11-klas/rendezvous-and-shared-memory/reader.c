#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>

#define SHM_SIZE 1024

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

void sem_lock(int sem_id, int sem_num) {
    struct sembuf sb;
    sb.sem_num = sem_num;
    sb.sem_op = -1;
    sb.sem_flg = 0;
    semop(sem_id, &sb, 1);
}

void sem_unlock(int sem_id, int sem_num) {
    struct sembuf sb;
    sb.sem_num = sem_num;
    sb.sem_op = 1;
    sb.sem_flg = 0;
    semop(sem_id, &sb, 1);
}

int main() {
    key_t key;
    int shmid, semid;
    char *data;

    // Generate unique key
    key = ftok("shmfile", 65);

    // Locate the shared memory segment
    shmid = shmget(key, SHM_SIZE, 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to the shared memory
    data = (char *)shmat(shmid, (void *)0, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // Locate the semaphore set
    semid = semget(key, 1, 0666);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }

    // Lock the semaphore
    sem_lock(semid, 0);

    // Read data from shared memory
    printf("Data read from shared memory: %s\n", data);

    // Unlock the semaphore
    sem_unlock(semid, 0);

    // Detach from shared memory
    if (shmdt(data) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Optionally, clean up shared memory and semaphore (commented out to keep example simple)
    /*
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    if (semctl(semid, 0, IPC_RMID, sem_union) == -1) {
        perror("semctl");
        exit(1);
    }
    */

    return 0;
}
