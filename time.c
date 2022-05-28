#include <time.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    time_t start = ts.tv_sec;
    long startn = ts.tv_nsec;
    printf("Foda-se");
    printf("\nStart: %d.%09ld", start, startn);
    for(;;) {
        sleep(1);
        timespec_get(&ts, TIME_UTC);
        time_t end = ts.tv_sec;
        long endn = ts.tv_nsec;
        printf("\nTime Elapsed: %d.%09ld", end-start, endn-startn);
 
    }


    /*for (;;) {
        struct timespec first;
        struct timespec second;
        timespec_get(&first, TIME_UTC);
        sleep(1);
        timespec_get(&second, TIME_UTC);
        time_t difference = second.tv_sec - first.tv_sec;
        long differencen = (long)second.tv_nsec - (long)first.tv_nsec;
        printf("\nTime: %d.%09ld", difference, differencen);
        }*/
}
