/*
	300Player (DCLLMPlayer - Doubly and Circular Linked Lists Music Player)
	Desenvolvido por Andr� Gomes em 19/03/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct Music {   
  int id;
  char title[45];
  struct Music *previous;   
  struct Music *next;   
};
typedef struct Music music;   

struct List{
	int total;
	int id;
	int status;  //Indica a situa��o atual da musica corrente. 0-Play  1-Stop
	music *currentMusic;
	music *begin;
	music *end;
};
typedef struct List playlist;

void Line(){
	printf("============================================================================\n");
}

void Menu(playlist *LIST){
Line();	printf("\t\t      ::WELCOME TO 300PLAYER:::\n");				Line();		
			printf("OPTIONS:\n");		
	printf("\t\t\t1 - ADD TRACK\n");
	if(LIST->total>0){
		printf("\t\t\t2 - REMOVE TRACK\n");
		if(LIST->total>1){
			printf("\t\t\t3 - CHANGE ORDER\n");
			printf("\t\t\t4 - |<<| PREVIOUS\n");
			printf("\t\t\t5 - |>>| NEXT\n");
		}
		printf("\t\t\t6 - |<>| MODE REPEAT (ON/OFF)\n");
		if(LIST->status==0){
			printf("\t\t\t7 - |%c%c| STOP TRACK\n", 219,219);
		}else{
			printf("\t\t\t7 - ||>| PLAY TRACK\n");
		}
		printf("\t\t\t8 - CLEAN PLAYLIST\n", 232);
	}
	printf("\t\t\t0 - EXIT 300PLAYER\n");
			Line();		printf("==>\t");
}

int empty(playlist *LIST){
	if(LIST->begin == NULL && LIST->end==NULL)
		return 1;
	else		
		return 0;
}

void start(playlist *LIST){
	LIST->begin = NULL;
	LIST->end=NULL;
	LIST->currentMusic=NULL;
	LIST->total=0;
	LIST->id=1;
	LIST->status=1;
}

music *aloca(playlist *p){
	music *novo=(music *) malloc(sizeof(music));
	if(!novo){
		printf("NO MEMORY AVALIABLE!\n");
		exit(1);
	}else{
				Line();		
		printf("ENTER MUSIC TITLE (45 CHARACTERS):\t");		
		setbuf(stdin,NULL);
		gets(novo->title);		
		novo->id=p->id;
		p->id++;
		return novo;
	}
}

void changeModeParameter(playlist *LIST, int i){
	if(i==0){//Coloca pra mode Off
		LIST->begin->previous=NULL;
		LIST->end->next=NULL;
	}else{//Coloca pra mode On
		LIST->end->next=LIST->begin;
		LIST->begin->previous = LIST->end;
	}
}

void changeModeRepeat(playlist *LIST){
	if(LIST->begin->previous==NULL)//if mode Repeat OFF, set mode repeat ON
		changeModeParameter(LIST, 1);
	else//if mode Repeat ON, set mode repeat OFF
		changeModeParameter(LIST, 0);	
}

void addEnd(playlist *LIST){
	int flg=0;
	music *novo=aloca(LIST);
	novo->previous = NULL;
	novo->next = NULL;
		
	if(empty(LIST)){
		LIST->begin=novo;
		LIST->end=novo;
	}else{
		novo->previous = LIST->end;
		LIST->end->next = novo;
		if(LIST->begin->previous!=NULL) {
			novo->previous = LIST->end;
			novo->next= LIST->begin;
		}
		LIST->end = novo;
	}
	if(LIST->currentMusic==NULL) {
		LIST->currentMusic = LIST->begin;
		LIST->status=0;
	}
	LIST->total++;
}

void emptyListStatus(){
			Line();			printf("\t\t\t    EMPTY PLAYLIST!\n");	
}

void showPlaylist(playlist *LIST, int status){
	system("cls");

	if(empty(LIST)){
		emptyListStatus();
		return ;
	}
	
			Line();		printf("PLAYLIST:\t");		
	
	if(LIST->currentMusic->previous==NULL){
		printf("BEGIN PLAYLIST! MODE REPEAT: OFF\n");
	}else if(LIST->currentMusic->next==NULL){
		printf("END PLAYLIST! MODE REPEAT: OFF\n");	
	}else if (LIST->begin->previous!=NULL && LIST->end->next!=NULL){
		if(status==0)
			printf("PLAYLIST MODE REPEAT: ON\n");	
		else if (status==1)
			printf("PLAYLIST MODE REPEAT: OFF\n");
		else if (status==2)
			printf("BEGIN PLAYLIST! MODE REPEAT: OFF\n");
		else if (status==3)
			printf("END PLAYLIST! MODE REPEAT: OFF\n");
	}else if (LIST->begin->previous==NULL && LIST->end->next==NULL){
		printf("PLAYLIST MODE REPEAT: OFF\n");
	}
			Line();	
	music *tmp;
	tmp = LIST->begin;
	
	for(int i=0;i<LIST->total;i++){
		
		if(tmp==LIST->currentMusic){
			
				if(LIST->status==0){
					printf("%2d - %s\t\t>>>>>>>>>>>>>>>> PLAY STATUS >>>>>>>>>>>>\n", tmp->id, strupr(tmp->title));
				}else{
					printf("%2d - %s\t\t>>>>>>>>>>>>>>>> STOP STATUS >>>>>>>>>>>>\n", tmp->id, strupr(tmp->title));
				}
			
		}else{
			printf("%2d - %s\n", tmp->id, strupr(tmp->title));
		}
		tmp = tmp->next;
	}
			Line();		
	printf("PLAYLIST TRACKS: %d\n", LIST->total);	
}

void clearPlaylist(playlist *LIST, int status){
	if(LIST->begin!=NULL && LIST->end!=NULL){	
		music *tmp = LIST->begin;
		changeModeParameter(LIST, 0); //Quebra a lista antes de dar o clear
		while( tmp != NULL){
			free(tmp);
			tmp = tmp->next;
		}
		if (status==0){
			start(LIST);
			emptyListStatus();
		}
	}
}

void removeMusic(playlist *LIST){
	if(empty(LIST)){
		emptyListStatus();
		return ;
	}
	showPlaylist(LIST, 0);
	int idM;
			Line();		
	printf("ENTER THE MUSIC TRACK NUMBER TO BE REMOVED:\t");
	scanf("%d==>\t", &idM);		
	music *previousMusic, *nextMusic;
	music *tmp = LIST->begin;
	while( tmp != NULL){
		if(tmp->id==idM){
			char title[30];
			strcpy(title,tmp->title);			
			nextMusic = tmp->next;
			previousMusic=tmp->previous;
			
			if(LIST->begin==tmp && LIST->end==tmp){//Testa se track � o �nico elemento da lista
				start(LIST);
			}else{
			
				if(LIST->begin==tmp){//Testa se track � o primeiro elemento da lista
					if(LIST->currentMusic==tmp) LIST->currentMusic=tmp->next;
					LIST->begin=tmp->next;
					nextMusic->previous=NULL;
				}else if(LIST->end==tmp){//Testa se track � o �ltimo elemento da lista
					if(LIST->currentMusic==tmp) LIST->currentMusic=tmp->previous;
					LIST->end = tmp->previous;
					previousMusic->next = NULL;
				}else{//Elemento no meio da lista
					if(LIST->currentMusic==tmp) LIST->currentMusic=tmp->next;
					previousMusic->next = nextMusic;
					nextMusic->previous = previousMusic;
				}
				LIST->total--;
				if(LIST->total==0) LIST->currentMusic = NULL;
			}
			free(tmp);
			return;
		}else{
			tmp = tmp->next;
		}	
	}		
}

void nextMusic(playlist *LIST){
	if(LIST->currentMusic->next==NULL){
		showPlaylist(LIST, 0);
		return;
	}
	LIST->currentMusic = LIST->currentMusic->next;
}

void previousMusic(playlist *LIST){
	if(LIST->currentMusic->previous==NULL){
		showPlaylist(LIST, 0);
		return;
	}
	LIST->currentMusic = LIST->currentMusic->previous;
}

void changeOrder(playlist *LIST){
	if(empty(LIST)){
		emptyListStatus();
		return ;
	}

	showPlaylist(LIST, 0);
	int idM;
			Line();			
	printf("ENTER THE MUSIC TRACK NUMBER TO BE CHANGED:\t");
	scanf("%d==>\t", &idM);
	
	int option, flg=0;
	do{
				Line();		
		printf("ORDER OPTIONS \n");
				Line();		
			printf("\t\t\t1 - MOVE UP\n");
			printf("\t\t\t2 - MOVE DOWN\n");
			printf("\t\t\t0 - RETURN\n");
				Line();		
		music *tmp = LIST->begin, *aux, *aux1, *aux2;
			scanf("%d==>\t", &option);
			switch(option){
				case 0:
					break;
				case 1:	
					if(LIST->begin->previous==NULL){//if mode Repeat OFF, set mode repeat ON
						changeModeParameter(LIST, 1);
						flg=1;
					}
					while(tmp){
						if(tmp->id==idM){
							
							if(LIST->begin==tmp) {
								flg=2;
								break;
							}
							if(LIST->begin==tmp->previous) LIST->begin=tmp;
							if(LIST->end==tmp) LIST->end=tmp->previous;						
							
							aux = tmp->previous;
							aux1 = aux->previous;
							aux2 = tmp->next;
							
							aux1->next = tmp;
							aux2->previous=aux;
							
							tmp->next = aux;
							tmp->previous = aux1;
							
							aux->next =aux2;
							aux->previous = tmp; 
							break;
						}
						tmp=tmp->next;
					}
					showPlaylist(LIST, flg);
					
					if(flg>0) {
						changeModeParameter(LIST,0);
					}
					break;
				case 2:
					if(LIST->begin->previous==NULL){//if mode Repeat OFF, set mode repeat ON
						changeModeParameter(LIST,1);
						flg=1;
					}
					while(tmp){
						if(tmp->id==idM){
							
							if(LIST->end==tmp) {
								flg=3;
								break;
							}
							if(LIST->end==tmp->next) LIST->end=tmp;
							if(LIST->begin==tmp) LIST->begin=tmp->next;						
							
							aux = tmp->next;
							aux1 = aux->next;
							aux2 = tmp->previous;
							
							aux1->previous = tmp;
							aux2->next=aux;
							
							tmp->previous = aux;
							tmp->next = aux1;
							
							aux->previous =aux2;
							aux->next = tmp; 
							break;
						}
						tmp=tmp->next;
					}
					showPlaylist(LIST, flg);
					
					if(flg>0) {
						changeModeParameter(LIST,0);
					}
					break;
			}
	}while(option!=0);	
}

void changeStatus(playlist *LIST){
	if(LIST->status==0){
		LIST->status=1;
	}else{
		LIST->status=0;
	}
}

int main(){
	
	playlist *LIST = (playlist *) malloc(sizeof(playlist));
	
	if(!LIST){
		printf("NO MEMORY AVALIABLE!\n");
		exit(1);
	}else{		
		start(LIST);
	}
	int optionMenu;
	
	do{
		showPlaylist(LIST, 0);
		Menu(LIST);		
		scanf("%d", &optionMenu);
		
		switch(optionMenu){			
			case 1: 
			
				addEnd(LIST); //Adicionar M�sica no fim da lista
				break;
			case 2:
				removeMusic(LIST); //Remover M�sica da Lista
				break;
			case 3:
				changeOrder(LIST); //Modifica sequencia de m�sicas da playlist.
				break;
			case 4:
				previousMusic(LIST); //Tocar Musica Anterior
				break;
			case 5:
				nextMusic(LIST); //Tocar Pr�xima M�sica
				break;
			case 6:
				changeModeRepeat(LIST); //Altera modo repeat(circular) da lista invertendo o valor atual.
				break;
			case 7:
				changeStatus(LIST); //Altera o estado de execu��o da Playlist. Play e Stop.
				break;
			case 8:
				clearPlaylist(LIST, 0); //Limpar Playlist
				break;
		}	
	}while(optionMenu!=0);
			Line();		
	printf("\t\t    THANKS FOR USING 300PLAYER\n\t\tVISIT OUR WEBSITE: www.300player.uk\n");	
	printf("\t\t    Developed by ANDRE GOMES\n");
			Line();		clearPlaylist(LIST, 1); 		free(LIST);
	return 0;	
}

