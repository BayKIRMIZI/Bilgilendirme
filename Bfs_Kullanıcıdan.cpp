#include <stdio.h>
#include <stdlib.h>
struct kavis{
    int tepe;
    struct kavis *next;
}; 
struct kavis *kavis_ekle(struct kavis *gecerli_bas, int yeni_dugum)
{
    struct kavis *yeni_bas = new kavis;
    yeni_bas->tepe = yeni_dugum;
    yeni_bas->next = gecerli_bas;
    return yeni_bas;
}
void BreadthFirstSearch (
    struct kavis * kavis_listesi[],
    int dugumler,
    int parent[],
    int derece[],
    int baslangic_dugum )
{
    struct kavis *gidis; 
    int i, par, lev, flag = 1; 
    lev = 0;
    derece[baslangic_dugum] = lev; 
    while (flag) 
	{
        flag = 0;
        for (i = 1; i <= dugumler; ++i) 
		{
            if (derece[i] == lev) 
			{
                flag = 1;
                gidis = kavis_listesi[i];
                par = i;
                while (gidis != NULL) 
				{
                    if (derece[gidis->tepe] != -1) 
					{
                        gidis = gidis->next;
                        continue;
                    }
                    derece[gidis->tepe] = lev + 1;
                    parent[gidis->tepe] = par;
                    gidis = gidis->next;
                }
            }
        }
        ++lev;
    }
}
int main()
{
    int dugumler, kavisler, i, v1, v2;
    printf("Grafda kac dugum oldugunu gir: ");
    scanf("%d", &dugumler);
    printf("\nGrafda kac tane kavis oldugunu gir: ");
    scanf("%d", &kavisler);
    struct kavis * kavis_listesi[dugumler + 1];
    int parent[dugumler + 1];
    int derece[dugumler + 1];
    for (i = 0; i <= dugumler; ++i) 
	{
        kavis_listesi[i] = NULL;
        parent[i] = 0;
        derece[i] = -1;
    }
    for (i = 1; i <= kavisler; ++i) 
	{
    	printf("Once hangi dugum oldugunu sonra da hangi dugume kavisi oldugunu gir:");
        scanf("%d%d", &v1, &v2);
        kavis_listesi[v1] = kavis_ekle(kavis_listesi[v1], v2);
        kavis_listesi[v2] = kavis_ekle(kavis_listesi[v2], v1);
    }
    printf("\nKavis Listesi -\n\n");
    for (i = 1; i <= dugumler; ++i) 
	{
        printf("kavis_listesi[%d] -> ", i);
        struct kavis * gidis = kavis_listesi[i];
        while (gidis != NULL) 
		{
            printf("%d -> ", gidis->tepe);
            gidis = gidis->next;
        }
        printf("NULL\n");
    }
    printf("\nBaslangic dugumunu girin:- ");
    scanf("%d", &v1);
    BreadthFirstSearch(kavis_listesi, dugumler, parent, derece, v1);
    printf("\nDerece ve aile listesi: -\n"); 
    for (i = 1; i <= dugumler; ++i) 
	{
        printf("%d.Dugumun derecesi= %d, Ailesi= %d\n",i, derece[i], parent[i]);
    }
    return 0;
}
