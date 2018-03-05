//gcc -lm 001.c
//lmオプはmathをビルドするときに使う。
#include<stdio.h>
#include<math.h>  //math.h を include する。

double f;

main(){
    scanf("%f",&f);
    printf("%f\n",log(f));  //math.h を include したので、log が使用できる。
}
