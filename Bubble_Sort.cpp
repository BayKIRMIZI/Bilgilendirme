#include <stdio.h>
#include <conio.h>
int Sayilar[]={11,5,55,1,1905,3};
void Bubble_Sort(int dizi[],int n)
{
     int i,j,gcc;
     for(i=0;i<n-1;i++)
     {
        for(j=n-1;j>i;j--)
        {
           if(dizi[j]<dizi[j-1])
           {
              gcc=dizi[j];
              dizi[j]=dizi[j-1];
              dizi[j-1]=gcc;
           }
        }
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
    Bubble_Sort(Sayilar,6);
    Goster(Sayilar,6);
    getch();
    return 0;
}
