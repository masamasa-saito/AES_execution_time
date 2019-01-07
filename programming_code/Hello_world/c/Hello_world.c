////////////////////////////////////////////////////////////
//
// Hello_world.c
//
// output "Hello_world!" 10000times
//
////////////////////////////////////////////////////////////

#include <stdio.h>
#include <time.h>

int main ( void ){
    int i = 0;
    /// Start time measurement from here ///
    clock_t c1,c2;
    c1 = clock();
    for(i = 0; i<10000; i++){
        printf("Hello world!\n");
    }
    c2 = clock();
    printf("Time taken to output Hello world! 10000 times (C-language)：%.14f[ms]\n",((double)(c2-c1)/CLOCKS_PER_SEC)*1000);
    return 0;
}
