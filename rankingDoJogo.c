
#include <stdio.h>
#include <stdlib.h>
#include "header/rankingDoJogo.h"
#include "header/posicaoLetra.h"


/*
*   Função : Responsável por abrir o arquivo ranking.txt e 
*   ler os dados do arquivo no caso strings e inteiros, após 
*   a leitura ele imprime os dados paraa o usuário;
*/
void mostrarRank(){
    char nomeDoJogador[TAMANHO_PALAVRA]; // armazena a palavra lida do arquivo;
    int pontuacao; // armazena o inteiro lido do arquivo;
    
    FILE *arquivoDoRankPtr; // declaração do ponteiro do arquivo;

    //checa se o arquivo foi aberto;    
    if((arquivoDoRankPtr=fopen("arquivos/ranking.txt","r")) == NULL){
        printf("Arquivo ranking.txt nao encontrado");
        exit(1);
    }else{
        printf("Nome pontuacao\n"); 
        fscanf(arquivoDoRankPtr,"%s%d",nomeDoJogador,&pontuacao);//ler a preira linha do arquivo

        // ler e imprime os dados armazenados no arquivo até encontrar o caracter EOF; 
        while(!feof(arquivoDoRankPtr)){ 
            printf("%s %d\n",nomeDoJogador,pontuacao); // imprime o dado armazenado;
            fscanf(arquivoDoRankPtr,"%s%d",nomeDoJogador,&pontuacao); // ler os dados do arquivo;
        }
            //fecha o arquivo; 
            fclose(arquivoDoRankPtr);
    }
}

/**
 *  Função : Responsável por registrar o nome e a pontuação
 *  do jogador no arquivo ranking.txt;
 * 
 */
void salvarPontuacao(char nomeDoJogador[], int pontuacao){
    FILE *arquivoDoRankPtr; // declaração do ponteiro do arquivo;

    // checar se o arquivo foi aberto;
    if((arquivoDoRankPtr=fopen("arquivos/ranking.txt","a")) == NULL){
        printf("Arquivo ranking.txt nao encontrado");
        exit(1);
    }
    // registra os dados do jogador no arquivo ranking.txt
    fprintf(arquivoDoRankPtr,"%s %d\n", nomeDoJogador,pontuacao); 

    //fecha o arquivo;
    fclose(arquivoDoRankPtr);
}

/**
 *  Função : Recebe um valor inteiro que representa a rodada
 *  em que o jogador acertou a palavra retornado a pontuação.
 */

int pontuacao(int valorDaRodada){
 int pontuacao; // declaração da variável 
    switch (valorDaRodada) // pontuação recebe um valor de acordo com o valor passado para função;
    {
    case 0:
        pontuacao = 100;
        break;
    case 1:
        pontuacao = 80;
        break;
    case 2: 
        pontuacao = 60;
        break;
    case 3:
        pontuacao = 40;
        break;
    case 4:
        pontuacao = 20;
        break;
    case 5:
        pontuacao = 0;                  
        break;
    default:
        break;
    }
    return pontuacao; //retorna o valor;
}

/*
*   Função: Recebe um valor passado pelo usuário, caso
*   o valor seja igual a 1 ele a função chama as funções 
*   de mostrar o rank e de imprimir as regras do jogo, senão
*   diferente apenas chama a função de imprimir as regras;
*/

void menuDaOpcao(int respotaDoUsuario){
    if(respotaDoUsuario == 1){ // condicional;
      mostrarRank(); // chamda da função mostrarRank;
      printf("\n");
      regraDoJogo(); // chamada da função regraDoJogo;
    }else{
        regraDoJogo(); // chamada da funçaõ regraDoJogo;
    }
}