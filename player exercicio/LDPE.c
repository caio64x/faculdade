#include <stdio.h>
#include <stdlib.h>

struct DADOS                    //estrutura dos dados
{
    int id;                     //identificacao do dado
    int valor;                  //dados a ser salvo
    struct DADOS *anterior;     //dado anterior
    struct DADOS *proximo;      //dado proximo
};
typedef struct DADOS dado;      //declaracao da variavel dados TIPO DADOS
                                //na estrutura tipo DADOS

struct LISTA                    //struct da lista
{
    int total;                  //total presente nesta lista
    int id;                     //identificacao da lista
    int status;                 //situacao de execucao
    dado *atualDADOS;           //dado atual rodando
    dado *comeco;               //comeco da lista
    dado *fim;                  //fim da lista
};
typedef struct LISTA info;      //declaracao da variavel info TIPO LISTA
                                //na estrutura tipo LISTA    
void Linha(){//funcao de linhas
	printf("============================================================================\n");
}

void Menu(info *LIST){//funcao de menu; info no ponteiro LIST
Linha(); printf("\t\t       ::BEM VINDO A ESTRUTURA DE DADOS::\n");
        printf("Opcoes:\n");
printf("\t\t\t1 - Adicionar dado\n");
    if (LIST->total>0)
    {//se o total da LISTA for maior que 0
        printf("\t\t\t2 - Remover dado\n");
        if (LIST->total>1)
        {//se o total da lista for maior que 1
            printf("\t\t\t3 - Mudar a ordem\n");
            printf("\t\t\t4 - Anterior\n");
            printf("\t\t\t5 - Proximo\n");
        }                       //lista em loop
        printf("\t\t\t6 - Modo Circular (ON/OFF)\n"); 
        if (LIST->status==0)    //if de parada de execucao
        {
            printf("\t\t\t7 - |%c%c| Pausar execucao\n");
        }else
        {
            printf("\t\t\t7 - Continuar execucao\n");
        }
printf("\t\t\t8 - Limpar Lista de informacoes\n");   
    }                           //saida do sistema de menu
    printf("\t\t\tSair do exercicio\n");                
        Linha(); printf("==>\t");
}

int vazia(info *LIST){//funcao que verifica se a lista esta vazia
    if (LIST->comeco == NULL & LIST->fim==NULL)
    {//se comeco da lista é nulo e o fim da lista é nullo, retorna 1                       
        return 1;
    }else
    {
        return 0;}
        }

void iniciar(info * LIST){//funcao de inicio
    LIST->comeco = NULL;
    LIST->fim = NULL;
    LIST->atualDADOS = NULL;
    LIST->total = 0;
    LIST->id = 1;
    LIST->status=1;       //inicia executando 
}

dado *aloca(info *p){//fucao de alocacao da informacao
    dado *novo=(dado *) malloc(sizeof(dado));
    if (!novo)//se inverso de novo
    {
    printf("Sem memoria livre\n");
    }else               //se ocorrer tudo correto vai alocar
    {
        Linha();
        printf("Entre com a informacao (digitos numerais):\t");
        	setbuf(stdin,NULL);
            scanf("%d",&novo->valor);
            novo->id=p->id;
            p->id++;
            return novo;
    }}

void Modo_de_parametro(info *LIST, int i){//fucao de modos circular
    if (i==0)
    {//coloca em modo off
        LIST->comeco->anterior = NULL;
        LIST->fim->proximo = NULL;
    }else
    {//coloca em modo on
        LIST->fim->proximo = LIST->comeco;
        LIST->comeco->anterior = LIST->fim;
        }
}

void adicionar_no_fim(info *LIST){// adicionar no fim
    int flg=0;                  //bandeira
    dado *novo = aloca(LIST);
    novo->anterior = NULL;
    novo->proximo = NULL;

    if (vazia(LIST))    //se vazia        
    {
        LIST->comeco = novo;
        LIST->fim = novo;
    }else               //se nao
    {
        novo->anterior = LIST->fim;
        if (LIST->comeco->anterior!=NULL)
        {
                novo->anterior = LIST->fim;
                novo->proximo = LIST->comeco;
        }
        LIST->fim = novo;
    }
    if (LIST->atualDADOS == NULL)
    {
        LIST->atualDADOS = LIST->comeco;
        LIST->status=0;
    }
    LIST->total++;
}

void lista_vazia_status(){
    Linha(); printf("\t\t\t LISTA VAZIA\n");
}

void mostrar_lista(info *LIST, int status){
    system("cls");

    if (vazia(LIST))
    {
        lista_vazia_status();
        return;
    }
    Linha;      printf("Lista:\t");

    if(LIST->atualDADOS->anterior == NULL){
        printf("COMECO da lista | modo de repeticao: OFF\n");
    }else if (LIST->comeco->anterior == NULL){
        printf("FIM da lista | modo de repeticao: OFF\n");
    }else if (LIST->comeco->anterior != NULL && LIST->fim->proximo != NULL)
    {
        if(status == 0){
            printf("LISTA MODO REPETICAO: ON\n");
        }else if(status == 1){
            printf("LISTA MODO REPETICAO: OFF\n");
        }else if(status == 2){
            printf("COMECO DA LISTA | MODO REPETICAO: ON\n");
        }else if(status == 3){
            printf("FIM DA LISTA | MODO REPETICAO: OFF\n");
        }else if(LIST->comeco->anterior == NULL && LIST->fim->proximo == NULL){
            printf("LISTA modo de repeticao: OFF");
        }
    }
    Linha();
    dado *tmp;
    tmp = LIST->comeco;

    for (int i = 0; i < LIST; i++)
    {
        if (tmp == LIST->atualDADOS)
        {
            if (LIST->status == 0)
            {
                printf("%2d - %s\t\t>>>>>>>>>>>>>>>> PLAY STATUS >>>>>>>>>>>>>>>>\n", tmp->id, strupr());
            }
            
        }
        
    }
    
    
    
}

//inicio do programa principal
int main(){                 
   info *LIST = (info *) malloc(sizeof(info)); //alocacao de memoria para info
    
    if (!LIST)
    {
        printf("Sem memoria livre\n");
        exit(1); }
        else {
        iniciar(LIST);
    }
    int opcaoMenu;

    do
    {
        mostrarInfo(LIST, 0);
        Menu(LIST);
        scanf("%d", &opcaoMenu);

switch (opcaoMenu)
{
case 1:
     adicionar_no_fim(LIST);   //add no fim
    break;
case 2:
    remover(LIST);             //remove o dado
    break;
case 3:
    mudar_ordem(LIST);         //Muda a ordem listada
    break;
case 4:
    proximo_dado(LIST);         //muda para o proximo dado
    break;
case 5:
    anterio_dado(LIST);         //Muda para o dado anterior
    break;
case 6:
    modo_de_repeticao(LIST);    //altera para modo circular
    break;
case 7:
    mostrar_status(LIST);       //mostra o status do processo
    break;
case 8:
    limparLista(LIST, 0);       //limpa a lista inteira
    break;
}
    } while (opcaoMenu!=0);
        Linha();
printf("\t\t\tObrigado por usar este exercicio\n\t\t\t");
    Linha();    limparLista(LIST, 0);   free(LIST);
    return 0;
}
