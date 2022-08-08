#include<stdio.h>
#include<string.h>

int main(){
    int n,k=0,m,f=1;
    char x;
    scanf("%d ",&n);

    while(1 == scanf("%c",&x)){
        k++;
    }
    m = n%k;

    for(int i=0;(n-i*k)>=m;i++){
        f = f*(n-i*k);
    }



    printf("%d",f);

    return 0;
}