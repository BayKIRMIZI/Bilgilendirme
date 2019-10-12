#include <stdio.h>
#include <conio.h>
int Sayilar[]={11,5,55,1,1905,3};
void Merge(int dizi[],int ilk,int orta,int son)
{
    int tempArray[1155];
    int ilk1=ilk;       int son1=orta;
    int ilk2=orta+1;    int son2=son;
    int index=ilk1;
    for(; (ilk1<=son1) && (ilk2<=son2) ;index++)
    {
       if(dizi[ilk1]<dizi[ilk2])
       {
          tempArray[index]=dizi[ilk1];
          ilk1++;
       }
       else
       {
           tempArray[index]=dizi[ilk2];
           ilk2++;
       }
    }
    for(;ilk1<=son1;ilk1++,index++)
    {
       tempArray[index]=dizi[ilk1];
    }
    for(;ilk2<=son2;ilk2++,index++)
    {
       tempArray[index]=dizi[ilk2];
    }
    for(index=ilk;index<=son;index++)
    {
       dizi[index]=tempArray[index];
    }
}
void Merge_Sort(int dizi[],int ilk,int son)
{
     if(ilk<son)
     {
        int orta=(ilk+son)/2;
        Merge_Sort(dizi,ilk,orta);
        Merge_Sort(dizi,orta+1,son);
        Merge(dizi,ilk,orta,son);
     }
}
void Goster(int dizi[],int n)
{
     for(int i=0;i<n;i++)
     {
        printf("%d ",dizi[i]);
     }
     printf("\n");
}
int main( )
{
    Goster(Sayilar,6);
    Merge_Sort(Sayilar,0,5);
    Goster(Sayilar,6);
    getch();
    return 0;
}
