#ifndef POSICAO_LETRA
#define POSICAO_LETRA 

#define TAMANHO_PALAVRA 5
void posicaoLetraCerta(char palavraDoUsuario[], char palavraDoArquivo[], char posicaoDaLetra[]);
int checarLetrasRepetidas(char letra[], char palavra[], int posicao);
int checarPosicaoDaPrimeiraLetraRepetida(char letra[],char palavra[],int posicao);
void posicaoLetraPertence(char palavraDoUsuario[], char palavraDoArquivo[], char posicaoDaLetra[]);
void posicaoLetraNaoPertence(char posicaoDaLetra[]);
void zeraPosicaoLetra(char posicaoLetra[]);
void regraDoJogo();
#endif