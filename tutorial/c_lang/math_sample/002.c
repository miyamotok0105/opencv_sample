//gcc 002.c
#include<stdio.h>
#include<math.h>

double x,y,z;

main(){
    scanf("%f",&x);
    scanf("%f",&y);
    scanf("%f",&z);
    printf("%f\n",(sin(x)+pow(x,log(y)))/sqrt(z));
}

