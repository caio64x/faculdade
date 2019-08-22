#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <new>
#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <tchar.h>
#define qt 30
using namespace std;

//funçao limpa tela
void limpaTela(){ 
    system("CLS");   }

//funcao palavra aleatoria
string retornaPalavraAleatoria(){
    string palavras[qt] = {"abacaxi", "manga", "morango", "bailarina", "futebol", "estátua", "pintor", "frio", "bebê", "quimico", "escova", "lapis", "livro", "astronauta", "amor","odio", "cego", "cadeira", "sacola", "professor", "medico", "calculadora", "artista", "vitoria", "pescador", "internet", 
"basquete", "semente", "policial", "amargo"};
//indice gerado
 int indiceAleatorio = rand() %qt;
//retorna a palavra
        return palavras[indiceAleatorio]; }

//funcao de mascara
string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){
    //declaracao de variaveis
    int cont = 0;
string palavraComMascara;
    while(cont < tamanhoDaPalavra){
        palavraComMascara +="_";
         cont ++;}
           return palavraComMascara;}

//funcao exibe o status
void exibeStatus(string palavraComMascara, int tamanhoDaPalavra, int tentativasRestantes, string letrasJaArriscadas, string mensagem){
  cout << mensagem;
    cout << "Palavra: " << palavraComMascara <<"(tamanho:"<< tamanhoDaPalavra << ")";
         cout << "\nTentativas restantes:" << tentativasRestantes << "\n\n";
        int cont; //exibe as letras arriscadas
            cout << "\n letras arriscadas: "; 
            for ( cont = 0; cont < letrasJaArriscadas.size(); cont++) {
                cout << letrasJaArriscadas[cont] << ", ";   }   }

//funçao opcao jogar sozinho
int jogar(int numeroDeJogadores){
    //palavra advinhada
    string palavra;
        //confere os jogadores
        if (numeroDeJogadores == 1){
            palavra = retornaPalavraAleatoria();
            }else
            {
                cout << "\nDigite uma palavra\n";
                cin >> palavra;       }
 //tamanho da palavra
int tamanhoDaPalavra = palavra.size();
   // retorno da palavra e o tamanho dela para a funcao etornaPalavraComMascara
     string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDaPalavra); 
  //declaracao de variaveis gerais
int tentativas = 0, maximoDeTentativas = 15; // tentativas
int cont = 0;                                //auxiliar para repetiçao
int opcao;                                   //opções finais
string letrasJaArriscadas;                   //acumula as tentativas
string mensagem;                             //feedback
char letra;                                  //letra identificada
bool jaDigitouLetra = false;                 //bool de letra digitada
bool acertouletra = false;                   //auxiliar de letra acertada
    //sistema de tentativas
    while (palavra != palavraComMascara && maximoDeTentativas - tentativas > 0){
     limpaTela();
     //exibe o status atual do jogo
exibeStatus(palavraComMascara, tamanhoDaPalavra, maximoDeTentativas - tentativas, letrasJaArriscadas, mensagem);
    cout << "\nDigite uma letra:";           
       cin >> letra;                //leitura de letras
for ( cont = 0; cont < tentativas; cont++){ 
    //percorre as letras ja arriscadas
      if (letrasJaArriscadas[cont] == letra){
        mensagem = "Essa letra ja foi digitada\n";    //se encontrar a letra  //se letra for repetida true
             jaDigitouLetra = true;  }}         
 if (jaDigitouLetra == false)  {
             //incrementa letras arriscadas
     letrasJaArriscadas += tolower(letra); 
//percorre a palavra se acertar a letra
    for (cont = 0; cont < tamanhoDaPalavra; cont++){ //se for uma letra nova
        if (palavra[cont] == tolower(letra)){
          //faço a letra aparecer na palavra
           palavraComMascara[cont] = palavra[cont]; 
           mensagem = "voce acertou uma letra\n";
           acertouletra = true;       }}
      //incrementa tentativas
if (acertouletra == false) {
            mensagem = "voce errou uma letra\n";}
        tentativas ++;   }
        acertouletra = false;
        jaDigitouLetra = false;
         }
if(palavra == palavraComMascara){
            limpaTela();
            cout << "Parabens, voce venceu\n";
                cout << "deseja reiniciar?";
                   cout << "\n1 sim - 2 nao\n"; 
                    cin >> opcao;
                        return opcao;  }
            else{
    limpaTela();
             cout <<"Voce perdeu!";
                cout << "deseja reiniciar?";
                   cout << "\n1 sim - 2 nao\n"; 
                    cin >> opcao;
                        return opcao;}}

//funçao menu
void menuInicial(){
//declaracao de variaveis
int opcao = 0; //opcao do usuario
//menu
while (opcao < 1 || opcao > 4){
//opcoes                                      
cout << "Bem vindo ao jogo";
    cout << "\n1 - Jogar sozinho";
        cout << "\n2 - jogar em dupla";
            cout << "\n3 - Sobre"; //informacoes do jogo
                cout << "\n4 - Sair";
                    cout << "\n Escolha uma opcao e tecle ENTER: ";
    cin >> opcao;
//sistema de escolhas (sub menu)
switch(opcao){
case 1:
            cout << "\t Jogo iniciado\n\n";
            limpaTela();
        
        if (jogar(1) == 1)  {
        limpaTela();
           menuInicial();}  
    break;
case 2:
            cout << "\t Jogo iniciado\n\n";
            limpaTela();
        
        if (jogar(2) == 1)  {
        limpaTela();
           menuInicial();}  
    break;
case 3:
            cout << "Informacoes do jogo\n"; 
    limpaTela();
            cout << "Jogo desenvolvido por Caio Ribeiro em 2019";
                cout << "\n1 - Voltar";
                cout << "\n2 - Sair \n";
                cin >> opcao;
                if (opcao == 1){
                    limpaTela();
                    menuInicial();       }
    break;
case 4:
            limpaTela();
            cout << "Ate mais\n";
    break;}}  }
    
int main(){
setlocale(LC_ALL,"Brasil");
_tsetlocale(LC_ALL, _T("portuguese"));
limpaTela();
srand((unsigned)time(NULL));
menuInicial();}
