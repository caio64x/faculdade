#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <time.h>
using namespace std;
//cabeçalhos de funcoes
void menuInicial();                                                 
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
            //cout << " " << tabuleiro[linha][coluna];              //imprime o gabarito
            cout << " " <<  mascara[linha][coluna];                 //imprime a mascara
        }
        cout << "\n";
    } 
}
void posicionaBarcos(char tabuleiro[10][10]){
    int quantidadePosicionada = 0;                                  //barcos posicionados contados 
    int cont=0;                                                     //contador de pulos 
    int quantidade = 10;                                            //limitador de barcos
    int linhaBarco = NULL, colunaBarco = NULL;                      //coordenadas dos barcos posicionados 
    while (quantidadePosicionada < quantidade)
    {
        linhaBarco = rand() %10;                                    //gera numero aleatório ate 9
        colunaBarco = rand() %10;                                   //gera numero aleatório ate 9
        if (tabuleiro[linhaBarco][colunaBarco] == 'A')              //se a posicao esta com agua entao entra um barco
        {
        tabuleiro[linhaBarco][colunaBarco] = 'B';                   //entrada do barco na posicao
        quantidadePosicionada++;                                    //incrementa a quantidade posicionada
        }
    }
}

void verificaTiro(char tabuleiro[10][10],int linhaJogada, int colunaJogada, int *pontos, string *mensagem,int *maximodeTentativas){
    int d = 1;
    switch (tabuleiro[linhaJogada][colunaJogada])
        {
        case 'B':
            *pontos = *pontos +10;
            *mensagem = "Você acertou um barco pequeno";
            break;
        case 'A':
            *mensagem = "Você acertou a agua";
            *maximodeTentativas = *maximodeTentativas -1;           
            break;
            
        } 
}

void jogo()
{
    char mascara[10][10];                                           //matriz da mascara
    char tabuleiro[10][10];                                         //matriz do tabuleiro do jogo
    int linhaJogada, colunaJogada;                                  //posicao das jogadas
    int linha, coluna;
    int estadoDeJogo = 1;                                           //mostra o estado do jogo 
    int pontos = 0;                                                 //pontuacao atual
    int opcao;                                                       //opcoes no fim do jogo
   // int tentativas = 10;                                            //tentativas atuais
    int maximodeTentativas = 10;                                   //maximo de tentativas
    string mensagem = "bem vindo ao jogo";                          //mensagem enviada
    iniciaTabuleiro(tabuleiro, mascara);                            //inicia tabuleiro com agua
    posicionaBarcos(tabuleiro);
    while (maximodeTentativas != 0)
    {
    limpaTela();    
    exibeTabuleiro(tabuleiro, mascara);                             //exibe o tabuleiro
    cout << maximodeTentativas << " Tentativas restantes";
    cout << "\nPontos " << pontos <<"\t" << mensagem;
    cout << "\nDigite uma linha: ";
    cin >> linhaJogada;
        if(linhaJogada > 9){
        cout << "\nDIGITE UM VALOR MENOR QUE 10";
        cout << "\nDigite uma linha: ";
        cin >> linhaJogada;
    }
    cout << "\nDigite uma coluna: ";
    cin >> colunaJogada;
        if(colunaJogada > 9){
        cout << "DIGITE UM VALOR MENOR QUE 10";
        cout << "\nDigite uma linha: ";
        cin >> colunaJogada;
    }
    verificaTiro(tabuleiro, linhaJogada, colunaJogada, &pontos, &mensagem, &maximodeTentativas);
    limpaTela();  
    mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];
    limpaTela();    
    }
    cout << "\n\n fim de jogo,\n deseja \t 1- Jogar Novamente 2- Menu 3- Sair";
            switch (opcao)
            {
            case 1:
                jogo();
                break;
            case 2:
                menuInicial();
                break;
            case 3:
                 cout << "Até mais!\n";
                break;
    }
}

void menuInicial()
{
    int opcao = 0;                                                  //opcao escolhida no menu
    limpaTela();
    while (opcao < 1 || opcao > 3)                                  //enquanto o jogador nao digita o menu continua em loop
    {
        limpaTela();
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
    srand( (unsigned)time(NULL) );                                    //posicoes aleatorias
    setlocale(LC_ALL, "portuguese");
    menuInicial();
} //fim do programa
