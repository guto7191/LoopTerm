#include <stdio.h>
#include "header/posicaoLetra.h"


/*
*  Função : Reponsável por verificar se as letra da palavra o usuário são iguais e estão na posição certa
*  se isso for satisfeito o array de caracter recebe um * na possição i que essa condição foi verdadeira
*/
void posicaoLetraCerta(char palavraDoUsuario[], char palavraDoArquivo[], char posicaoDaLetra[]){
    int i, j;
    
    for(i=0; i<TAMANHO_PALAVRA; i++){ // loop para percorrer as strings 
        for(j=0; j<TAMANHO_PALAVRA; j++){
            if(palavraDoUsuario[i] == palavraDoArquivo[j] && i==j){ // condição para atribuição do * no array de caracter 
                posicaoDaLetra[i]='*';
            }
        }
    }
}    
       
/*
*   Função : Função responsável por contar a quantidade de letras repetidas na 
*   palavra.
*/

int checarLetrasRepetidas(char letra[], char palavra[], int posicao){
    int i, contador=0;
    
    for(i=0; i<TAMANHO_PALAVRA; i++){  // loop para comparar a letra com os caracter da string 
        if(letra[posicao] == palavra[i]){ // comparação da caracter letra com os caracteres da String
              contador++; 
        }
    }
        return contador;  
}

/*
*   Função : Responsáve por verificar a posição da primeira letra repetida 
*
*/

int checarPosicaoDaPrimeiraLetraRepetida(char letra[],char palavra[],int posicao){ 
    int i, valorDaPosicao;
    
    for(i=0; i<TAMANHO_PALAVRA; i++){
        if(letra[posicao] == palavra[i]){ // condição responsável por procurar a primeira letra que se repete   
              valorDaPosicao = i; 
              return valorDaPosicao;
        }
    }
    
}                       
    
/*
    Função : Responsável por verificar se a letra pertence a palavra, mas encontra-se na posição errada;
*/

void posicaoLetraPertence(char palavraDoUsuario[], char palavraDoArquivo[], char posicaoDaLetra[]){
    int i, j, numLetraRepetidaDoUsuario, numLetraRepetidaDoArquivo, posicaoDaPrimeiraLetraRepetida;
    for(i=0; i<TAMANHO_PALAVRA;i++){//loop para percorrer a palavra do usuário 
        for(j=0;j<TAMANHO_PALAVRA; j++){//loop ressponsável por percorrer a palavra do arquivo 
            if(palavraDoUsuario[i]==palavraDoArquivo[j] && i!=j && (posicaoDaLetra[i]!='*')){ //condição para verificar se a letra está na palavra mas não na posição certa 
                numLetraRepetidaDoUsuario = checarLetrasRepetidas(palavraDoUsuario,palavraDoArquivo,i);//chamada da função checarLetraRepetidas
                numLetraRepetidaDoArquivo = checarLetrasRepetidas(palavraDoArquivo,palavraDoUsuario,j);//chamada da função checarLetraRepetidas
                posicaoDaPrimeiraLetraRepetida = checarPosicaoDaPrimeiraLetraRepetida(palavraDoArquivo,palavraDoUsuario,j);//chamada da função checarPosiçãoDaLetraRepetida
                 if(numLetraRepetidaDoUsuario != numLetraRepetidaDoArquivo && (posicaoDaLetra[posicaoDaPrimeiraLetraRepetida]=='+' || posicaoDaLetra[posicaoDaPrimeiraLetraRepetida]=='*')){
                              posicaoDaLetra[i]='-';  // Essa condicional é responsável por verificar quantidade de vezes que essa letra se repete em cada palavra e verificar se posição da letra 
                 }else{                               // letra repetida já esta preenchida com + ou * caso seja verdade posicaoLetra i recebe -
                             posicaoDaLetra[i]='+'; // caso a condicional seja falsa posicaoLetra i recebe + 
                 }
            }
        }
     }                          
}         

                
/*
*   Função : Responsável por preencher posicaoLetra com - caso a letra não 
*   pertença a palavra;
*/

void posicaoLetraNaoPertence(char posicaoDaLetra[]){
    int i;
    
    for(i=0; i<TAMANHO_PALAVRA; i++){
            if(posicaoDaLetra[i]!='*' && posicaoDaLetra[i]!='+'){ // condicional responsável por verificar se a letra não pertence a palavra 
                posicaoDaLetra[i]='-';  // atribuição de - em posicaoLetra caso condição seja verdadeira;
            }
   }
}

/*
*   Função responsavel por zerar as posições de posicaoLetra 
*/

void zeraPosicaoLetra(char posicaoLetra[]){
    int i;
    for(i =0; i<TAMANHO_PALAVRA; i++){
        posicaoLetra[i]='0';//preenche a posição com caracter zero;
    }
}

/*
*   Função : Responsavél por imprimir as regras do jogo
*/
void regraDoJogo(){
    // Print das regras 
    printf("%s\n","*************************");
    printf("%s\n","| *  =  letra pertence  |");
    printf("%s\n","| +  =  posicao errada  |");
    printf("%s\n","| -  =  nao pertence    |");
    printf("%s\n","*************************");
    printf("Digite a sua palavra\n");
}