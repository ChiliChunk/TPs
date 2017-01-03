#include "semops.h"

union semun {
		int val;
		struct semid_ds *buf;
		ushort * array;
	} argument;

/* Initialize a binary semaphore with a value of 1. */
int semaphore_initialize (int semid, int value) {
    union semun argument;
    unsigned short values[1];
    values[0] = value;
    argument.array = values;
    return semctl (semid, 0, SETALL, argument);
}

/* Wait on a binary semaphore. Block until the semaphore value is positive, then decrement it by 1. */
int binary_semaphore_wait (int semid) {
    struct sembuf operations[1];
    /* Use the first (and only) semaphore. */ operations[0].sem_num = 0;
    /* Decrement by 1. */ operations[0].sem_op = -1;
    /* Permit undo’ing. */ operations[0].sem_flg = SEM_UNDO;
    return semop (semid, operations, 1); }


/* Post to a binary semaphore: increment its value by 1. This returns immediately. */
int binary_semaphore_post (int semid) {
    struct sembuf operations[1];
    /* Use the first (and only) semaphore. */ operations[0].sem_num = 0;
    /* Increment by 1. */ operations[0].sem_op = 1;
    /* Permit undo’ing. */ operations[0].sem_flg = SEM_UNDO;
    return semop (semid, operations, 1);
}

int binary_semaphore_deallocate (int semid) {
    union semun ignored_argument;
    return semctl (semid, 1, IPC_RMID, ignored_argument);
}