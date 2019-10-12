#include<stdio.h>
#include<conio.h>
int dizi[]={1,3,9,11,25,32,55,63,81,91,100};
int binary_search(int dizi[],int ilk,int son,int aranan)
{
	int orta;
	if(ilk>son)
	{
		printf("\n%d bulunamadi",aranan);
		return -1;
	}
	else
	{
		orta=(ilk+son)/2;
		if(aranan==dizi[orta])
		{
			printf("\n%d bulundu",aranan);
			return orta;	
		}
		else if(aranan<dizi[orta])
		{
			return binary_search(dizi,ilk,orta-1,aranan);
		}
		else
		{
			return binary_search(dizi,orta+1,son,aranan);
		}
	}
	
}
main()
{
	int sayi;
	for(int s=0;s<11;s++)printf("%d ",dizi[s]);
	printf("\nAranan sayi : ");scanf("%d",&sayi);
	
	
	binary_search(dizi,0,10,sayi);
	
	getch();
}
