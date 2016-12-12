#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

/* Initialize a binary semaphore with a value. */
int semaphore_initialize (int semid, int value);

/* Wait on a binary semaphore. Block until the semaphore value is positive, then decrement it by 1. */
int binary_semaphore_wait (int semid);

/* Post to a binary semaphore: increment its value by 1. This returns immediately. */
int binary_semaphore_post (int semid);

int binary_semaphore_deallocate (int semid);
