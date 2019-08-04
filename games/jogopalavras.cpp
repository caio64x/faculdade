#include <stdio.h>
#include <stdlib.h>
#include <new>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

//funçao limpa tela
void limpaTela(){ 
    system("CLS");   }

//funcao palavra aleatoria
string rotornaPalavraAleatoria(){
string palavras[3] = {"abacaxi", "manga", "morango"};

//indice gerado
          int indiceAleatorio = rand() %3;
//retorna a palavra
            return palavras[indiceAleatorio];}

//funcao de mascara
string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){
    //declaracao de variaveis
    int cont = 0;
string palavraComMascara;
while(cont < tamanhoDaPalavra){
    palavraComMascara +="_";
    cont ++;}
    return palavraComMascara;}

//funçao opcao jogar sozinho
void jogarSozinho(){
        //palavra a ser advinhada
        string palavra = rotornaPalavraAleatoria();
//tamanho da palavra
int tamanhoDaPalavra = palavra.size();
// retorno da palavra e o tamanho dela para a funcao etornaPalavraComMascara
string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra);

//declaracao de variaveis
int tentativas = 0, maximoDeTentativas = 5, cont = 0;
//letra identificada
char letra;
    //sistema de tentativas
    while (maximoDeTentativas - tentativas > 0){
        cout << "Palavra: " << palavraComMascara <<"(tamanho:"<< tamanhoDaPalavra << ")";
                 cout << "\nTentativas restantes:" << maximoDeTentativas - tentativas << "\n\n";
//leitura de letras
         cout << "Digite uma letra:";
           cin >> letra;
//percorre a palavra se acertar a letra
for (cont = 0; cont < tamanhoDaPalavra; cont++){
    if (palavra[cont] == letra){
        //faço a letra aparecer na palavra
        palavraComMascara[cont] = palavra[cont]; }}
    //incrementa tentativas
  tentativas ++;}}

//funçao menu
void menuInicial(){
// opcao do usuario
//declaracao de variaveis
int opcao = 0;
//menu
while (opcao < 1 || opcao > 3){

//opcoes                                      
cout << "Bem vindo ao jogo";
    cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
            cout << "\n3 - Sair";
                cout << "\n Escolha uma opcao e tecle ENTER: ";
cin >> opcao;

//sistema de escolhas (sub menu)
switch(opcao){
case 1:
            cout << "\t Jogo iniciado\n\n";
 jogarSozinho();
    break;
case 2:
            cout << "Informacoes do jogo\n"; 
    break;
case 3:
            cout << "Ate mais\n";
    break;}}}

int main(){
setlocale(LC_ALL, "Portuguese");

srand((unsigned)time(NULL));

menuInicial();}
