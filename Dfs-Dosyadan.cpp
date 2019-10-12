#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<limits.h>
  	int adj[6][6];// MAL�YET MATR�S�
 	int visit[6];//GRAFLARIN Z�YARET ED�L�P ED�LMED���N� KONTROL etmek i�in...
 	int color[6];//1 ise kuyruktan ��kt�, 0 ise kuyrukta...
 	int key[6];//key dizisi
	int parent[6];//parent dizisi...
struct adjlistnode   //kom�uluk listesinin bir d���m�n� ifade eden yap�..
{
    int destination;//hedef node
    struct adjlistnode *next; 
};
struct adjlist
{
    struct adjlistnode *head;//her kom�uluk listesinin ana d���m� vard�r. bu d���m de bunu temsilk eder...   
};
struct graph	// genel olarak graf yap�s�...
{
    int v;
    struct adjlist* array;//node say�s� kadar kom�uluk listesi olu�turmak i�in  dizi yap�s� tan�mland�......
};
struct adjlistnode* new_adjlist_node(int dest)	//d���mleri ba�larken kullanaca��m�z yeni bir d���m�n olu�turulmas�..
{
    struct adjlistnode* new_node=(struct adjlistnode*) malloc(sizeof(adjlistnode));
    new_node->destination=dest;
    new_node->next=NULL;
    return new_node;//geri d�n�� de�eri olarak olu�turulan d���m� g�nderiyo...
};
struct graph* createGraph(int vertex)
{
    struct graph* graph=(struct graph*) malloc(sizeof(struct graph));
    graph->v=vertex;
    graph->array=(struct adjlist*) malloc(vertex*sizeof(struct adjlist));
    for(int i=0;i<vertex;i++) 
		graph->array[i].head=NULL;
    return graph;
};
void add_edge(struct graph* graph,int source,int desti)
{//kenarlar� birle�tirme i�in yaz�lm�� metod..kaynak ve hedef d���mlerini parametre olarak al�yor...
    struct adjlistnode* new_node=new_adjlist_node(desti);//hedef d���m� i�in olu�turulan d���m
    new_node->next=graph->array[source].head;
    graph->array[source].head=new_node;// y�ns�z graf oldu�u i�in her iki y�n  ba�lan�r....
    /* new_node=new_adjlist_node(source);
    new_node->next=graph->array[desti].head;
    graph->array[desti].head=new_node;*/
}
int convert(char x)
{//char ifadenin int de�ere convert yap�lmas�...
    switch(x)
	{
    	case '0':
            return 0;
            break;
    	case '1':
            return 1;
            break;
        case '2':
            return 2;
            break;
        case '3':
            return 3;
            break;
        case '4':
            return 4;
            break;
        case '5':
            return 5;
            break;
        case '6':
            return 6;
            break;
        case '7':
            return 7;
            break;
        case '8':
            return 8;
            break;
    	case '9':
            return 9;
            break;
        default:
            return 0;           
    }
}
void print(struct graph * graph)
{//istenilirse graf ekrana yazd�r�labilir...
   for(int i=0;i<graph->v;i++)
   {
        struct adjlistnode* temp=graph->array[i].head;//ana d���m ..
        printf("vertex: %d-",i);
        while(temp)
		{
            printf("-%d",temp->destination); 
            temp=temp->next;
        }
        printf("\n\n");
	}
}
void dfs(int s)
{//deept first search fonksiyonu...
    visit[s]=1;//ziyaret edildi anlam�nda...
   	for(int i=0;i<6;i++)
	{
        if(adj[s][i] !=0 &&visit[i]==0)
		{
            dfs(i);
            printf("%d-->",i); 
        }
    }    
}
int empty()
{//kuyru�un bo� olup olmad���n�n kontrol�...0:dolu 1: bos
    for(int i=0;i<6;i++)
	{
        if(color[i]==0) 
			return 0;
    }          
    return 1;
}
int min_key()
 {//kuyruktaki elemanlar�n key de�erleri...
    int min=INT_MAX;//sonsuz anlam�nda...
    int min_index=-1;
    for(int v=0;v<6;v++)
	{
        if(color[v]==0&&key[v]<min)
		{
            min=key[v];
            min_index=v;     
        }              
    }
    return min_index; //enk���k key de�erine sahip d���m inedexi geri d�nd�r�l�yor..
}        
void prim(int s)
{//prim fonksiyonu...
    for(int i=0;i<6;i++)
	{
        color[i]=0;
        key[i]=INT_MAX;
    }//for
    key[s]=0;//baslang�c nodu key de�eri 0 yap�l�yor...
    parent[s]=-1;//ba�lang�� d���m� parenti olamaz..
    while(empty()!=1)
	{       
        int u=min_key();
        color[u]=1;//kuyruktan c�karma anlam�na geliyo..
        for(int j=0;j<6;j++)
		{
        	if(adj[u][j]!=0&&color[j]==0&&adj[u][j]<key[j])
			{
                parent[j]=u;     
                key[j]=adj[u][j];
            } 
        }//for sonu..
    }//while sonu            
    printf("KENAR -----PARENT-----MALIYET\n\n");          
    for(int i=0;i<6;i++)
	{
        if(i!=s)
        printf("%d------------>%d------------>%d\n\n",i,parent[i],adj[i][parent[i]]);          
    }
}
main()
{
    char arr[20];
    for(int i=0;i<6;i++)
	{//ziyaret edilmedi hepsi....
        visit[i]=0;
    }
    FILE *dosya;
	printf("Graf dosyadan okunuyor...\n");
    dosya=fopen("graf.txt","r");
    if(fopen("graf.txt","r")==NULL) 
	    printf("Dosya acilamadi..\n");
    else
	{ 
        int v=6;
        struct graph* graph = createGraph(v);//v tane node olan graph olu�turuldu...
    	fscanf(dosya,"%s",arr);
        int i=0;
        while(!feof(dosya))
		{
        	for(int j=0;j<6;j++)
			{
                adj[i][j]=convert(arr[j]);       
            }                         
            fscanf(dosya,"%s",arr); 
            i++; 
            for(int j=0;j<6;j++)
			{
                adj[i][j]=convert(arr[j]);
            }           
        } //feof sonu
        fclose(dosya);
    	for(int k=0;k<6;k++)
		{
        	for(int j=0;j<6;j++)
			{
                if(adj[k][j]!=0)
					add_edge(graph,k,j);  //kom�usu olanlar ba�lan�yor..                                       
            } 
		}             
        printf("\n\nGraf olusturuldu...\n");
      	printf("\n\nAgirliklandirilmis  GRAF MATRIX:\n\n");
      	for(int i=0;i<6;i++)
		{
            for(int j=0;j<6;j++)
			{
                printf("%d",adj[i][j]);
                if(j<5)printf("--");
            }
            printf("\n");
        }
      	int s;
      	printf("\n\nVerilen Grafin Komsuluk Matrisi\n\n");
      	print(graph);
    	printf("Baslangic nodu gir[0-5]="); scanf("%d",&s);
      	printf("\n\nDfs  ciktisi:\n\n");
      	dfs(s);
		printf("%d",s);
    	printf("\n\nPrim Ciktisi:\n\n");
      	prim(s);
    }//else sonu...
    getch();
}
