#include <conio.h>
#include <stdio.h>
int renk[11],parent[11],uzaklik[11],derece[11];
typedef struct x
{
    int k[10];
    int indis ;        
}kuyruk;
kuyruk a;
typedef struct dugum
{
	int dugum_num;
	dugum *sonraki;
}dugum;
typedef struct liste
{
	dugum D[11];
}liste;
int dugum_say=1;
bool kuyruk_bos_mu()
{
	if(a.indis==10) return true ;
    else return false;
}
int kuyruk_cikar()
{
	int i,k;
    k=a.k[9];
    for(i=9;i>a.indis;i--)
    {
    	a.k[i]=a.k[i-1];
	}
    	
    a.indis++;  
    return k;
}
void kuyruk_koy(int b )
{
    a.indis--;
    a.k[a.indis]=b;
}
void BFS(liste lst , int kaynak )
{
	int i,j;
	dugum *y;
	for(i=0;i<11;i++)
	{
		parent[i]=-1;
 		uzaklik[i]=0;
 		renk[i]=0;
 	}
 	renk[kaynak]=1;
 	uzaklik[kaynak]=0;
 	kuyruk_koy(kaynak);
 	while(!kuyruk_bos_mu())
 	{
		int x;
 		x=kuyruk_cikar();		 		
		y=&lst.D[x];
	 	for(y=y->sonraki;y;y=y->sonraki)
		{
			if(renk[y->dugum_num]==0)
		 	{
		 		renk[y->dugum_num]=1;
		 		uzaklik[y->dugum_num]=uzaklik[x]+1;
		 		parent[y->dugum_num]=x;
		 		kuyruk_koy(y->dugum_num);	
		 	}
		} 		
		renk[x]=2;	
 	}	
}                  
main() 
{	
	a.indis=10;
	FILE *dosya;    
    dosya= fopen("liste.txt","r");
    char c;
    while(!feof(dosya))
    {
		c=fgetc(dosya);
        if(c=='\n') dugum_say++;
    }            
	fseek(dosya,0,SEEK_SET);
    liste graph;       
	int i,j,de;
	dugum *gecici;
	for(i=0;i<dugum_say;i++)
	{
		printf("%d\t||",i);
		gecici=&graph.D[i];
		gecici->dugum_num=i;
		for(j=0;j<dugum_say;j++)
		{
			fscanf(dosya,"%d",&de);
			if(de==1)
			{
				printf(" %d",j);
				derece[i]++;
				gecici->sonraki = new dugum;
				gecici=gecici->sonraki;
				gecici->dugum_num=j;
				gecici->sonraki=NULL;
			}
		}	
		printf("\n");
	}
	int n;
	while(55)
	{
		printf("\n1-Derece\n2-Dugumun babasi ve kaynak uzakligi\n3-baslangicdan hedefe gide yol \nSecim: ");
		scanf("%d",&n);
		if(n==1) 	
			for(i=0;i<11;i++)
				printf("%d derecesi %d \n",i,derece[i]);
		else if(n==2) 
		{
			printf("Baslangic dugumu gir : ");
			scanf("%d",&n);
			BFS(graph,n);
			for(i=0;i<11;i++)
			printf("%d babasi %d kaynaktan %d uzak\n",i,parent[i],uzaklik[i]);
		}
		else if(n==3)
		{
			int dee,adim_sayisi=0;
			printf("Hangi dugumden : ");
			scanf("%d",&n);
			printf("Hangi dugume : ");
			scanf("%d",&dee);
			BFS(graph,dee);
	 		while(true)
            {           
            	printf("%d ",n);
               	if(dee==n) break;  
            	n=parent[n];
            	adim_sayisi++;
            } 
			printf("\n adim sayisi %d ",adim_sayisi);	 
		}
	}
	getch();
}
