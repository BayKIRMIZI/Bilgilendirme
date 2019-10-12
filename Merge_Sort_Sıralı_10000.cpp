#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void Merge(int dizi[],int ilk,int orta,int son){
    int tempArray[30000];
    int ilk1=ilk;       int son1=orta;
    int ilk2=orta+1;    int son2=son;
    int index=ilk1;
    for(; (ilk1<=son1) && (ilk2<=son2) ;index++){
       if(dizi[ilk1]<dizi[ilk2]){
          tempArray[index]=dizi[ilk1];
          ilk1++;
       }else{
           tempArray[index]=dizi[ilk2];
           ilk2++;
       }
    }
    for(;ilk1<=son1;ilk1++,index++){
       tempArray[index]=dizi[ilk1];
    }
    for(;ilk2<=son2;ilk2++,index++){
       tempArray[index]=dizi[ilk2];
    }
    for(index=ilk;index<=son;index++){
       dizi[index]=tempArray[index];
    }
}
void Merge_Sort(int dizi[],int ilk,int son){
    if(ilk<son){
        int orta=(ilk+son)/2;
        Merge_Sort(dizi,ilk,orta);
        Merge_Sort(dizi,orta+1,son);
        Merge(dizi,ilk,orta,son);
    }
}
int main( ){
    int array[10000];
    for(int i=0;i<10000;i++){
       array[i]=i;
    }
    time_t basla,bitir;
    time(&basla);	Merge_Sort(array,0,10000);	time(&bitir);
    printf("Çalýþma Zamaný = %.2lf sn\n",difftime(bitir,basla));
    getch();
    return 0;
}
