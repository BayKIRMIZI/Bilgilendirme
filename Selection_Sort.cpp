#include <stdio.h>
#include <conio.h>
int Sayilar[]={11,5,55,1,1905,3};
void Selection_Sort(int dizi[],int n)
{
     int i,j,min,gcc;
     for(i=0;i<n-1;i++)
     {
        min=i;
        for(j=i+1;j<n;j++)
        {
           if(dizi[j]<dizi[min])
           {
              min=j;
           }
           gcc=dizi[min];
           dizi[min]=dizi[i];
           dizi[i]=gcc;
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
    Selection_Sort(Sayilar,6);
    Goster(Sayilar,6);
    getch();
    return 0;
}
