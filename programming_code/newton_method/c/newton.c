////////////////////////////////////////////////////////////
//
// newton.c
//
// 決められた3次の方程式に対し、
// 「../input/input.txt」のファイルから一行ずつ数値を読み込み、
// それらを初期値としたニュートン法で求めて、
// 全てを解き終わるまでの実行時間を求める
//
////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*=== f関数：引数xに対しf(x)を返す ===*/
double f ( double x ){
    return x * x * x - 16 * x * x + 73 * x - 90;
}

/*=== dfdx関数：引数xに対しf'(x)を返す ===*/
double dfdx ( double x ){
    return 3 * x * x - 32 * x + 73;
}

/*--- 終端条件の最小値を規定する ---*/
#define Epsilon ( 1e-5 )

/*=== newton_method関数：ニュートン法を用いて、「f(x) = 0」の解をどれか一つ求める ===*/
double newton_method ( double initial_value ){
    double x = initial_value;
    int i = 0;
    while((fabs(f(x))) > Epsilon){
        //fprintf(stderr, "i = %2d   x = %3.16f\n",i,x);
        x = x - f(x)/dfdx(x);
        i++;
    }
    return x;
}


#define N 256
#define MAX 20000
int main(void){
    /// 外部の入力ファイルから1行ずつ読み込んで、入力用の配列に入れる ///
    FILE *fp;
    char *filename = "../input/input.txt";
    char readline[N] = {'\0'};
    double input_arr[MAX] = {};
    int i = 0;
    /* ファイルのオープン */
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
        exit(EXIT_FAILURE);
    }

    /* ファイルの終端まで文字を読み取り入力用の配列に入れる */
    while ( fgets(readline, N, fp) != NULL ){
        input_arr[i] = atof(readline);
        i++;
    }

    /* ファイルのクローズ */
    fclose(fp);
    
    int input_arr_len = i;
    double answer;
    /// ここから時間測定開始 ///
    clock_t c1,c2;
    c1 = clock();
    for(i = 0; i<input_arr_len; i++){
        answer = newton_method (input_arr[i] );
        //printf("answer = %f\n",answer);
        //printf("i = %d\ninput_arr_len = %d\n",i,input_arr_len);
        //printf("===============================\n");
    }
    c2 = clock();
    /*
    printf("cpuの1クロックするまでの時間 = %.14f[ms]\n",(1/(double)CLOCKS_PER_SEC)*1000);
    printf("c1 = %d\n",(int)c1);
    printf("測り始めた時間：%.14f[ms]\n",((double)c1/CLOCKS_PER_SEC)*1000);
    printf("c2 = %d\n",(int)c2);
    printf("測り終わった時間：%14f[ms]\n",((double)c2/CLOCKS_PER_SEC)*1000);
    */
    printf("全ての解を求めるまでにかかった時間：%.14f[ms]\n",((double)(c2-c1)/CLOCKS_PER_SEC)*1000);

    return 0;
}
