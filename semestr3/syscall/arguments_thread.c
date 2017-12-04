#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
 

#define SUCCESS 0

#define NUM_THREADS 4

 
typedef struct someArgs_tag {
    int id;
    const char *msg;
    int out;
} someArgs_t;
 
void* thread_function(void *args) {
    someArgs_t *arg = (someArgs_t*) args;
    int len;
    
    len = strlen(arg->msg);
    printf("my number is %d, my string %s\n", (int)pthread_self(), arg->msg);
    arg->out = len;

    sleep(5);
 
    return SUCCESS;
}
 
 
int main() {
    pthread_t threads[NUM_THREADS];
    int status;
    int i;
    int status_addr;
    someArgs_t args[NUM_THREADS];
    const char *messages[] = {
        "First",
        "Second Message",
        "Third Message",
        "Fourth Message is the biggest"
    };
 
    for (i = 0; i < NUM_THREADS; i++) {
        args[i].id = i;
        args[i].msg = messages[i];
    }
 
    for (i = 0; i < NUM_THREADS; i++) {
        status = pthread_create(&threads[i], NULL, thread_function, (void*) &args[i]);
        
    }
 
    printf("Main Message\n");
 
    for (i = 0; i < NUM_THREADS; i++) {
        status = pthread_join(threads[i], (void**)&status_addr);
    }
 
    for (i = 0; i < NUM_THREADS; i++) {
        printf("thread %d arg.out = %d\n", i, args[i].out);
    }

    return 0;
}
