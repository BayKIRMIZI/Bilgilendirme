#include <stdio.h>
#include <conio.h>
int Sayilar[]={11,5,55,1,1905,3};
void Insertion_Sort(int dizi[],int n)
{
     int i,j,mevcut;
     for(i=1;i<n;i++)
     {
        mevcut=dizi[i];
        j=i;
        for(;j>0 && mevcut<dizi[j-1];j--)
        {
           dizi[j]=dizi[j-1];
        }
        dizi[j]=mevcut;
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
    Insertion_Sort(Sayilar,6);
    Goster(Sayilar,6);
    getch();
    return 0;
}
