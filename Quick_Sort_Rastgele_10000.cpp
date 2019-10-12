#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int Partition(int dizi[],int alt_indis,int ust_indis){
    int i,j,pivot_degeri,pivot_indisi,gcc;
    pivot_degeri=dizi[alt_indis];
    j=alt_indis;
    for(i=alt_indis+1;i<=ust_indis;i++){
       if(dizi[i]<pivot_degeri){
          j++;
          gcc=dizi[i];
          dizi[i]=dizi[j];
          dizi[j]=gcc;
       }
    }
    pivot_indisi=j;
    gcc=dizi[alt_indis];
    dizi[alt_indis]=dizi[pivot_indisi];
    dizi[pivot_indisi]=gcc;
    return pivot_indisi;
}
void Quick_Sort(int dizi[],int alt,int ust){
    int pivot_indisi;
    if(ust>alt){
        pivot_indisi=Partition(dizi,alt,ust);
        Quick_Sort(dizi,alt,pivot_indisi-1);
        Quick_Sort(dizi,pivot_indisi+1,ust);
    }
}
int main( ){
    int array[10000];
    for(int i=0;i<10000;i++){
       array[i]=rand()%10000;
    }
    time_t basla,bitir;
    time(&basla);	Quick_Sort(array,0,10000);	time(&bitir);
    printf("calisma zamani : %.2lf ",difftime(bitir,basla));
    getch();
    return 0;
}
