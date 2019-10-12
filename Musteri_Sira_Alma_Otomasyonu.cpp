#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct kuyruk{
	int musteri_no,sira_no;
	char ad[55],soyad[55];
	struct kuyruk *prev,*next;
}KY;
FILE *f;
KY *ilk=NULL,*gcc;
int onc1=1,onc2=101,i=0,j=0;
void listele();
void ekleme(KY *);
void kuyruk_ekle(char a[4][55]);
int bilgi_al(int);
int kontrol(int);
void kuyruktan_cikar();

main(){
	int m_no;
	char secim;
while(1){
	printf("Sira Al(A)\nSiradakini Cikart(S)\nListele(L)\nCikis(C)\n");
	secim=getch();
	switch(secim){
		case 'a':	printf("Musteri no gir : ");
					scanf("%d",&m_no);
					if(kontrol(m_no)==1)
						{
						if(bilgi_al(m_no)==1) printf("Ekleme basarili\n");
						else printf("Ekleme basarisiz . Musteri yok\n");
					}
					else printf("Musteri no alinmis\n");
						
					break;
		case 's':	if(ilk!=NULL)
					kuyruktan_cikar();
					else printf("Liste Bos\n");
					break;
			
		case 'l': if(ilk!=NULL)
					listele();
					else printf("Liste Bos\n");
					break;
		case 'c':exit(0);
				break;
		default:
			printf("Hatali secim\n");
			break;
		}
		
system("PAUSE");
system("CLS");
}
}
int kontrol(int no){
	gcc=ilk;
	while(gcc!=NULL){
		if(gcc->musteri_no==no) return 0;
		gcc=gcc->next;
	}
	return 1;
}
int bilgi_al(int m_no){
	
		f=fopen("Musteri.txt","r");
	if(f==NULL){
		printf("Dosya yok.");
		exit(0);
	}
	
	char satir[4][55]={NULL},oku;
	

	while(!feof(f)){
		oku=fgetc(f);
		if(oku=='#'){
			i++;
			j=0;	
		}
		else if(oku=='\n'){
			i=0;
			j=0;
			if(atoi(satir[0])==m_no) {	
			kuyruk_ekle(satir);
			fclose(f);
			return 1;
			}
			for(int k=0;k<4;k++)
			for(int l=0;satir[k][l];l++)
			satir[k][l]={NULL};
		}
		else{
		satir[i][j]=oku;
			j++;
		}
	}
	fclose(f);
	return 0;
}
void kuyruk_ekle(char a[4][55]){
	
	gcc=new KY;
	strcpy(gcc->ad,a[1]);
	strcpy(gcc->soyad,a[2]);
	gcc->musteri_no=atoi(a[0]);
	if(onc1!=onc2-1){
	if(atoi(a[3])==1) {
	gcc->sira_no=onc1;
	onc1++;
	}
	else{
	 gcc->sira_no=onc2;
	 onc2++;
	}}
	else{
		gcc->sira_no=onc2;
		onc1++;
		onc2++;
	}
	gcc->next=NULL;
	gcc->prev=NULL;
	ekleme(ilk);
}
void ekleme(KY *kok){
if(ilk==NULL) ilk=gcc;
else{

	if(kok->sira_no>gcc->sira_no){
			if(kok->prev==NULL)
			{
				kok->prev=gcc;
				gcc->next=kok;
				ilk=gcc;	
			}
			else{
				if(kok->prev->sira_no>gcc->sira_no) ekleme(kok->prev);
				else{
					kok->prev->next=gcc;
					gcc->next=kok;
					gcc->prev=kok->prev;
					kok->prev=gcc;
				}
			}
		}
else{
				if(kok->next==NULL)
			{
				kok->next=gcc;
				gcc->prev=kok;
			}
			else{
				if(kok->next->sira_no<gcc->sira_no) ekleme(kok->next);
				else{
					kok->next->prev=gcc;
					gcc->prev=kok;
					gcc->next=kok->next;
					kok->next=gcc;
				}
			}
			}
	}
}
void listele(){
	gcc=ilk;
	while(gcc!=NULL) 
	{
		printf("%d\t%d\t%s %s\n",gcc->sira_no,gcc->musteri_no,gcc->ad,gcc->soyad);
		gcc=gcc->next;
	}
}


void kuyruktan_cikar(){
	gcc=ilk;
	printf("%d %d %s %s\n",gcc->sira_no,gcc->musteri_no,gcc->ad,gcc->soyad);
	ilk=ilk->next;
	free(gcc);
	if(ilk!=NULL)
	ilk->prev=NULL;
}
