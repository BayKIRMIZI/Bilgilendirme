#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void Bubble_Sort(int dizi[],int n){
    int i,j,gcc;
    for(i=0;i<n-1;i++){
    	for(j=n-1;j>i;j--){
           if(dizi[j]<dizi[j-1]){
              gcc=dizi[j];
              dizi[j]=dizi[j-1];
              dizi[j-1]=gcc;
           }
        }
    }
}
int main( ){
    int array[10000];
    for(int i=0;i<10000;i++){
       array[i]=i;
    }
    time_t basla,bitir;
    time(&basla);	Bubble_Sort(array,10000);	time(&bitir);
    printf("Çalýþma Zamaný = %.2lf sn\n",difftime(bitir,basla));
    getch();
    return 0;
}
