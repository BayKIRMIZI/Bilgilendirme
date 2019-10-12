#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<limits.h>
  	int adj[6][6];// MALÝYET MATRÝSÝ
 	int visit[6];//GRAFLARIN ZÝYARET EDÝLÝP EDÝLMEDÝÐÝNÝ KONTROL etmek için...
 	int color[6];//1 ise kuyruktan çýktý, 0 ise kuyrukta...
 	int key[6];//key dizisi
	int parent[6];//parent dizisi...
struct adjlistnode   //komþuluk listesinin bir düðümünü ifade eden yapý..
{
    int destination;//hedef node
    struct adjlistnode *next; 
};
struct adjlist
{
    struct adjlistnode *head;//her komþuluk listesinin ana düðümü vardýr. bu düðüm de bunu temsilk eder...   
};
struct graph	// genel olarak graf yapýsý...
{
    int v;
    struct adjlist* array;//node sayýsý kadar komþuluk listesi oluþturmak için  dizi yapýsý tanýmlandý......
};
struct adjlistnode* new_adjlist_node(int dest)	//düðümleri baðlarken kullanacaðýmýz yeni bir düðümün oluþturulmasý..
{
    struct adjlistnode* new_node=(struct adjlistnode*) malloc(sizeof(adjlistnode));
    new_node->destination=dest;
    new_node->next=NULL;
    return new_node;//geri dönüþ deðeri olarak oluþturulan düðümü gönderiyo...
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
{//kenarlarý birleþtirme için yazýlmýþ metod..kaynak ve hedef düðümlerini parametre olarak alýyor...
    struct adjlistnode* new_node=new_adjlist_node(desti);//hedef düðümü için oluþturulan düðüm
    new_node->next=graph->array[source].head;
    graph->array[source].head=new_node;// yönsüz graf olduðu için her iki yön  baðlanýr....
    /* new_node=new_adjlist_node(source);
    new_node->next=graph->array[desti].head;
    graph->array[desti].head=new_node;*/
}
int convert(char x)
{//char ifadenin int deðere convert yapýlmasý...
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
{//istenilirse graf ekrana yazdýrýlabilir...
   for(int i=0;i<graph->v;i++)
   {
        struct adjlistnode* temp=graph->array[i].head;//ana düðüm ..
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
    visit[s]=1;//ziyaret edildi anlamýnda...
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
{//kuyruðun boþ olup olmadýðýnýn kontrolü...0:dolu 1: bos
    for(int i=0;i<6;i++)
	{
        if(color[i]==0) 
			return 0;
    }          
    return 1;
}
int min_key()
 {//kuyruktaki elemanlarýn key deðerleri...
    int min=INT_MAX;//sonsuz anlamýnda...
    int min_index=-1;
    for(int v=0;v<6;v++)
	{
        if(color[v]==0&&key[v]<min)
		{
            min=key[v];
            min_index=v;     
        }              
    }
    return min_index; //enküçük key deðerine sahip düðüm inedexi geri döndürülüyor..
}        
void prim(int s)
{//prim fonksiyonu...
    for(int i=0;i<6;i++)
	{
        color[i]=0;
        key[i]=INT_MAX;
    }//for
    key[s]=0;//baslangýc nodu key deðeri 0 yapýlýyor...
    parent[s]=-1;//baþlangýç düðümü parenti olamaz..
    while(empty()!=1)
	{       
        int u=min_key();
        color[u]=1;//kuyruktan cýkarma anlamýna geliyo..
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
        struct graph* graph = createGraph(v);//v tane node olan graph oluþturuldu...
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
					add_edge(graph,k,j);  //komþusu olanlar baðlanýyor..                                       
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
