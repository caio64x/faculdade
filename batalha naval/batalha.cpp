#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//funcoes
void limpaTela()
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
            cout << " " << tabuleiro[linha][coluna];
            cout << " " <<  mascara[linha][coluna];
        }
        cout << "\n";
    }
}

void jogo()
{

    char mascara[10][10];                                           //mascara
    char tabuleiro[10][10];                                         //tabuleiro do jogoinicia
    int linhaJogada, colunaJogada;                                  //jogadas
    int linha, coluna;
    
    iniciaTabuleiro(tabuleiro, mascara);                            //inicia tabuleiro com agua
    exibeTabuleiro(tabuleiro, mascara);                             //exibe o tabuleiro

    cout << "\nDigite uma linha";
   // cin >> 
}

void menuInicial()
{
    int opcao = 0;                                                 //opcao escolhida
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
                                                                   //case de leitura da opcao
        switch (opcao)
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
    setlocale(LC_ALL, "portuguese");
    menuInicial();
} //fim do programa
