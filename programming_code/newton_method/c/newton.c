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
/*=== f function : Return f (x) for argument x ===*/

/* 今回使用した f(x) は、「 f(x) = x^3 - 16x^2 + 73x -90 」である */
/* The f(x) used this time is  " f(x) =  x^3 - 16x^2 + 73x - 90 " */
double f ( double x ){
    return x * x * x - 16 * x * x + 73 * x - 90;
}

/*=== dfdx関数：引数xに対しf'(x)を返す ===*/
/*=== dfdx function: Return f'(x) for argument x ===*/

/* 今回使用した f'(x) は、「 f'(x) = 3x^2 - 32x + 73 」である */
/* The f'(x) used this time is  " f'(x) = 3x^2 - 32x + 73 " */
double dfdx ( double x ){
    return 3 * x * x - 32 * x + 73;
}

/*--- 終端条件の最小値を規定する ---*/
/*--- Define minimum value of termination condition ---*/
#define Epsilon ( 1e-5 )

/*=== newton_method関数：ニュートン法を用いて、「f(x) = 0」の解をどれか一つ求める ===*/
/*=== newton_method function: Find one solution of "f (x) = 0" using Newton's method ===*/
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
    /// Read each line from an external input file and place it in the input array ///
    FILE *fp;
    char *filename = "../input/input.txt";
    char readline[N] = {'\0'};
    double input_arr[MAX] = {};
    int i = 0;
    /* ファイルのオープン */
    /* Opening a file */
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "%sのオープンに失敗しました.\n", filename);
        exit(EXIT_FAILURE);
    }

    /* ファイルの終端まで文字を読み取り入力用の配列に入れる */
    /* Read characters up to the end of the file and place it in the input array */
    while ( fgets(readline, N, fp) != NULL ){
        input_arr[i] = atof(readline);
        i++;
    }

    /* ファイルのクローズ */
    /* Close the file */
    fclose(fp);
    
    int input_arr_len = i;
    double answer;
    /// ここから時間測定開始 ///
    /// Start measuring time from here ///
    clock_t c1,c2;
    c1 = clock();
    for(i = 0; i<input_arr_len; i++){
        answer = newton_method (input_arr[i] );
        //printf("answer = %f\n",answer);
        //printf("i = %d\ninput_arr_len = %d\n",i,input_arr_len);
        //printf("===============================\n");
    }
    c2 = clock();
    //printf("全ての解を求めるまでにかかった時間：%.14f[ms]\n",((double)(c2-c1)/CLOCKS_PER_SEC)*1000);
    printf("Time taken to obtain 20000 solutions (C-language)：%.14f[ms]\n",((double)(c2-c1)/CLOCKS_PER_SEC)*1000);
    return 0;
}
