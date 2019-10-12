#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void Selection_Sort(int dizi[],int n){
    int i,j,min,gcc;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
           if(dizi[j]<dizi[min]){
              min=j;
           }
           gcc=dizi[min];
           dizi[min]=dizi[i];
           dizi[i]=gcc;
        }
    }
}
int main( ){
    int array[10000];
    for(int i=0;i<10000;i++){
       array[9999-i]=i;
    }
    time_t basla,bitir;
    time(&basla);	Selection_Sort(array,10000);	time(&bitir);
    printf("Çalýþma Zamaný = %.2lf sn\n",difftime(bitir,basla));
    getch();
    return 0;
}
