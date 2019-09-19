// Reference: https://www.thegeekstuff.com/2012/04/create-threads-in-linux/?utm_source=feedburner
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

#define THREADS_NUM 5

// The fix
pthread_t threads_id[THREADS_NUM];

void* thread_callback(int num){
    
    // static int thread_i = 0;
    pthread_t id = pthread_self();
    
    // using static var to identify the thread is also working as the static variable sticks with the function and it is firstly intialized only in the first call of the function
    // printf("Thread #%d its id: %d is processing\n", ++thread_i, id);
    printf("Thread #%d its id: %d is processing\n", num+1, (int) id);

    // Result:
    /**
     * The idea that the thread is created and trying to perform the callback while another thread is created
     * Thread #1 has been created
        Thread #1 its id: 2116646656 is processing
        Thread #2 has been created
        Thread #2 its id: 2106058496 is processing
        Thread #3 has been created
        Thread #3 its id: 2097665792 is processing
        Thread #4 has been created
        Thread #5 has been created
        Thread #5 its id: 2013263616 is processing
        Thread #4 its id: 2089273088 is processing
    */

    // The fix
    for(int i = 0; i < THREADS_NUM; i++){
        if(pthread_equal(id,threads_id[i]))
            printf("Correct_Order: Thread #%d its id: %d is processing\n", i+1, id);
    }
    pthread_exit(NULL);

}

int main(){
    // Threads creation
    for(int i = 0; i < THREADS_NUM; i++){
        int err = pthread_create(&(threads_id[i]), NULL, &thread_callback, i);
        if(err != 0)
            printf("Error in creating the thread\n");
        else{
            printf("Thread #%d has been created\n", i+1);
        }
        if (i % 5 == 0)
            sleep(1);
    }

    pthread_exit(NULL);


    return 0;
}