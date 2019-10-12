#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void Insertion_Sort(int dizi[],int n){
    int i,j,mevcut;
    for(i=1;i<n;i++){
        mevcut=dizi[i];
        j=i;
        for(;j>0 && mevcut<dizi[j-1];j--){
           dizi[j]=dizi[j-1];
        }
        dizi[j]=mevcut;
    }
}
int main( ){
    int array[10000];
    for(int i=0;i<10000;i++){
       array[i]=rand()%10000;
    }
    time_t basla,bitir;
    time(&basla);	Insertion_Sort(array,10000);	time(&bitir);
    printf("Çalýþma Zamaný = %.2lf sn\n",difftime(bitir,basla));
    getch();
    return 0;
}
