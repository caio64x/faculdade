#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
void limpaTela()                                                    //funcao para limpar informacoes 
{
    system("CLS");
}

void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10])
{
    int linha, coluna;
    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 10; coluna++)                     //popula com agua
        {
            tabuleiro[linha][coluna] = 'A';
            mascara[linha][coluna] = '*';
        }
    }
}

void exibeTabuleiro(char tabuleiro[10][10], char mascara[10][10])
{
    int linha, coluna;
    for (linha = 0; linha < 10; linha++)
    {
        for (coluna = 0; coluna < 10; coluna++)                     //imprime o tabuleiro
        {
            //cout << " " << tabuleiro[linha][coluna];
            cout << " " <<  mascara[linha][coluna];                 //mascara
        }
        cout << "\n";
    }
}
void posicionaBarcos(char tabuleiro[10][10]){
    int quantidadePosicionada = 0;                                  //barcos posicionados contados 
    int cont;                                                       //contador
    int quantidade = 10;                                            //limitador de barcos

    while (quantidadePosicionada < quantidade)
    {
        int linhaBarco = rand() %10;                                //gera numero aleatório ate 9
        int colunaBarco = rand() %10;                               //gera numero aleatório ate 9
        tabuleiro[linhaBarco][colunaBarco] = 'B';

        if (tabuleiro[linhaBarco][colunaBarco] == 'A')              //se a posicao esta com agua entao entra um barco
        {
            tabuleiro[linhaBarco][colunaBarco] = 'B';               //entrada do barco na posicao
            quantidadePosicionada++;                                //incrementa a quantidade posicionada
        }

    }
}

void jogo()
{
    char mascara[10][10];                                           //matriz da mascara
    char tabuleiro[10][10];                                         //matriz do tabuleiro do jogo
    int linhaJogada, colunaJogada;                                  //posicao das jogadas
    int linha, coluna;
    bool estadoDeJogo = 1;                                          //mostra o estado do jogo 

    iniciaTabuleiro(tabuleiro, mascara);                            //inicia tabuleiro com agua
    posicionaBarcos(tabuleiro);

    while (estadoDeJogo == 1)
    {
       // limpaTela();    
    exibeTabuleiro(tabuleiro, mascara);                             //exibe o tabuleiro
    cout << "\nDigite uma linha: ";
    cin >> linhaJogada;
    cout << "\nDigite uma coluna: ";
    cin >> colunaJogada;
    mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];
  //  limpaTela();
    }
}

void menuInicial()
{
    int opcao = 0;                                                  //opcao escolhida no menu
    limpaTela();
    while (opcao < 1 || opcao > 3)
    {
        limpaTela();
                                                                    //enquanto o jogador nao digita o menu continua em loop
        cout << "Bem vindo ao Jogo";
        cout << "\n 1 - Jogar";
        cout << "\n 2 - Sobre";
        cout << "\n 3 - Sair";
        cout << "\n Escolha uma opção e tecle ENTER: ";
        cin >> opcao;
                                                                   
        switch (opcao)                                              //case de leitura da opcao
        {
        case 1:
            cout << "Jogo iniciado\n";
            jogo();
            break;
        case 2:
            cout << "Informações do jogo\n";
            break;
        case 3:
            cout << "Até mais!\n";
            break;
        }
    }
}

int main()
{   
    srand((unsigned)time(NULL));                                    //posicoes aleatorias
    setlocale(LC_ALL, "portuguese");
    menuInicial();
    

} //fim do programa
