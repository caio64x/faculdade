#include <stdio.h>
#include <stdlib.h>
#include <new>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

//limpa tela
void limpaTela(){ 
    system("CLS");   }

string rotornaPalavraAleatoria(){
string palavras[3] = {"abacaxi", "manga", "Morango"};

//indice gerado
    int indiceAleatorio = rand() %3;
//retorna a palavra
        return palavras[indiceAleatorio];}

void jogarSozinho(){

//palavra a ser advinhada
        string palavra = rotornaPalavraAleatoria();
            cout << " A plavra secreta eh " << palavra << "\n";
//tamanho da palavra
int tamanhoDaPalavra = palavra.size();

int cont = 0;
string palavraComMascara;

while(cont < tamanhoDaPalavra){
    palavraComMascara +="_";
    cont ++;
        cout << "A palavra secreta eh: " << palavra <<"(tamanho:"<< tamanhoDaPalavra << ")";
            cout << "\nMascara:" << palavraComMascara;
}}

void menuInicial(){
// opcao do usuario
int opcao = 0;
//menu
while (opcao < 1 || opcao > 3){

//opcoes                                      
cout << "Bem vindo ao jogo";
    cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
            cout << "\n3 - Sair";
                cout << "\n Escolha uma opcao e tecle ENTER:";
cin >> opcao;

//sistema de escolhas (sub menu)
switch(opcao){
case 1:
            cout << "Jogo iniciado\n";
 jogarSozinho();
           
    break;
case 2:
            cout << "Informacoes do jogo\n"; 
    break;
case 3:
            cout << "Ate mais\n";
    break;
}}}

int main(){


srand((unsigned)time(NULL));

menuInicial();


}
