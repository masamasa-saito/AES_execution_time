////////////////////////////////////////////////////////////
//
// Hello_world.c
//
// Hello_worldを100回繰り返す
//
////////////////////////////////////////////////////////////

#include <stdio.h>
#include <time.h>

int main ( void ){
    int i = 0;
    /// ここから時間測定開始 ///
    clock_t c1,c2;
    c1 = clock();
    for(i = 0; i<10000; i++){
        printf("Hello world!\n");
    }
    c2 = clock();
    printf("全ての解を求めるまでにかかった時間：%.14f[ms]\n",((double)(c2-c1)/CLOCKS_PER_SEC)*1000);

    return 0;
}
