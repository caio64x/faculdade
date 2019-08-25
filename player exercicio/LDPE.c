#include <stdio.h>
#include <stdlib.h>

struct DADOS
{
    int id;
    int valor;
    struct DADOS *anterior;
    struct DADOS *proximo;
};
typedef struct DADOS dado;

struct LISTA
{
    int total;
    int id;
    int status;
    dado *atualDADOS;
    dado *comeco;
    dado *fim;
};
typedef struct LISTA info;

void Linha(){
	printf("============================================================================\n");
}

void Menu(info *LIST){
Linha(); printf("\t\t       ::BEM VINDO A ESTRUTURA DE DADOS::\n");
        printf("Opcoes:\n");
printf("\t\t\t1 - Adicionar dado\n");
    if (LIST->total>0)
    {
        printf("\t\t\t2 - Remover dado\n");
        if (LIST->total>1)
        {
            printf("\t\t\t3 - Mudar a ordem\n");
            printf("\t\t\t4 - Anterior\n");
            printf("\t\t\t5 - Proximo\n");
        }
        printf("\t\t\t6 - Modo Circular (ON/OFF)\n");
        if (LIST->status==0)
        {
            printf("\t\t\t7 - |%c%c| Pausar execucao\n")
        }else
        {
            printf("\t\t\t7 - Continuar execucao\n");
        }
printf("\t\t\t8 - Limpar Lista de informacoes\n");   
    }
    printf("\t\t\tSair do exercicio\n");
        Linha(); printf("==>\t");
}

int vazia(info *LIST){
    if (LIST->comeco == NULL & LIST->end==NULL)
    {
        return 1;
    }else
    {
        return 0;}
        }

void iniciar(info * LIST){
    LIST->comeco = NULL;
    LIST->fim = NULL;
    LIST->atualDADOS = NULL;
    LIST->total = 0;
    list->id = 1;
    LIST->status=1;
}

