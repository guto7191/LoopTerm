#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>           
#include <ctype.h>
#include "header/posicaoLetra.h"
#include "header/rankingDoJogo.h"


#define TAMANHO_PALAVRA 5 //Define o tamanho da palavra no arquivo;
#define QUANTIDADE_DE_PALAVRAS 1338  // Define a quantidade de palavras no arquivo 

// declaração do protótipo das funções
int geradorDeNumAleatorio(int quantidadeDePalavrasNoArquivo, int guardarValoresAleatorios[]);
void letraInvalida(int valorDeChecarLetra, char palavraDoUsuario[]);
void palavraInvalida(int valorDeChecarPalavraNoArquivo, char palavraDoUsuario[],FILE *arquivoPTR);
int comparacaoPalavra(char palavraDoArquivo[], char palavraDoUsuario[]);
int checarLetra(char palavraDoUsuario[],int tamanho);
void converterLetra(char palavraUsuario);
void pegarPalavraNoArquivo(FILE *arquivoPTR, char palavraDoArquivo[], int guardarValoresAleatorios[]);
int checarPalavraNoArquivo(FILE *arquivoPTR, char palavraDoUsuario[]);
int loopDojogo(FILE *arquivoPTR, char palavraNoArquivo[], char posicaoDaLetra[]);

// declaração da variável global 
int pontuacaoAtual=0;

//Função main 
int main(){
    // declaração das variáveis
    char nomeDoJogador[TAMANHO_PALAVRA];
    char palavraDoArquivo[TAMANHO_PALAVRA];
    char posicaoLetra[TAMANHO_PALAVRA]; 
    int guardarValoresAleatorios [QUANTIDADE_DE_PALAVRAS]={0};
    int valorDoLoop, resposta;
    
   
    //declaração do ponteiro do arquivo;
    FILE* arquivoPtr; 

    // limpa o terminal;
    system("cls");
    
    // Pede uma entra para o usuário; 
    printf("Digite 1 --> Ver Ranking\nDigite 2 --> Jogar\n");
    scanf("%d", &resposta);
    
    // Chamada da função menuDaOpcao;
    menuDaOpcao(resposta);
    
    // Chamada da função pegarPalavraNoArquivo;
    pegarPalavraNoArquivo(arquivoPtr,palavraDoArquivo,guardarValoresAleatorios);
    

    
    // TESTE DA PALAVRA NO ARQUIVO;
    //printf(">%s\n",palavraDoArquivo);

    //chamada da função loopDoJogo;
    valorDoLoop = loopDojogo(arquivoPtr,palavraDoArquivo, posicaoLetra);  
    
    /*
    *  Esse loop é responsável por verificar se o valor retornado por loopDoJogo
    *  é igual a 1, caso seja ele chama a função pegarPalavraNoArquivo que traz uma
    *  nova palavra e chama novamente a função loopDoJogo. Senão ele pede para o usuário
    *  digitar seu nome, registrando num arquivo ranking.txt ;
    */
    while(valorDoLoop == 1){
        pegarPalavraNoArquivo(arquivoPtr,palavraDoArquivo,guardarValoresAleatorios); //Chamda da função pegarPalavra no arquivo
        printf("pontos>>%d\n", pontuacaoAtual); // Imprime a pontuação do jogador;
        //printf(">%s\n",palavraDoArquivo); // TESTE DA PALAVRA NO ARQUIVO;
        printf("\n/// NOVA RODADA ///\n");//Indica uma nova rodada
        valorDoLoop = loopDojogo(arquivoPtr,palavraDoArquivo, posicaoLetra);//Chamada da função loopDoJogo
        
        if(valorDoLoop!=1){
            printf("pontos>>%d\n", pontuacaoAtual); // Imprime a pontuação do jogodor;
            printf("Digite seu nome :"); // Pede para usuario digitar seu nome;
            scanf("%s",nomeDoJogador); // armazena o nome do jogador em nomeDojagador; 
            salvarPontuacao(nomeDoJogador,pontuacaoAtual); // Chamada da função salvarPontuacao;
        }  
    }
     

     //fechamento do arquivo
     fclose(arquivoPtr);

    return 0;
}



/* 
*  Função : Responsável por gerar um valor aleatório utilizando o função rand determinado um intervalor  
*  desses números aleatórios de acordo com a quantidade de palavras no arquivo além de gerar um valor ale-
*  atório preenche uma array com os números aleatórios que já foram sorteados evitando repetição de palavras,
*  pois os numeros aleatório indicam a linha que a palavra estar no arquivo txt.
*/  

int geradorDeNumAleatorio(int quantidadeDePalavrasNoArquivo,int guardarValoresAleatorios[]){
    int numAleatorio, valor, j; //declarando variáveis;
    valor = 1; // inicializando valor com 1; 
    srand(time(NULL)); // define o ponto de partida para gerar uma série de números pseudoaleatorio, com base na hora do computador;
    while( valor == 1){//loop while para pegar os números aleatórios que não foram utilizados ainda.
        numAleatorio = 1 + rand()%quantidadeDePalavrasNoArquivo; // intervalo de números de 0 até quantidadePalavras no arquivo;
        valor = 0;// inicializando com zera para ver se o número sorteado, está sendo usado pela primeira vez;       
        for(j=0; j < QUANTIDADE_DE_PALAVRAS; j++){ //percorrendo o array guardarValoresAleatorios para ver se o número sorteado já tinha sido escolhido;
            if(numAleatorio == guardarValoresAleatorios[j])//condicional para ver se o número sorteado está no array;
                valor = 1; // caso seja verdade valor recebe 1 iniciando novamente o loop;
        }

        if(valor == 0) // condicional para verificar se valor igual a 0 indicando que o número foi sorteado pela primeira vez;
            guardarValoresAleatorios[numAleatorio-1]=numAleatorio; // guarda o número sorteado na posição número sorteado menos um;
    }
    return numAleatorio; // retornar o valor do número sorteado; 
}

/*
*   Função: Essa função é responsável por pegar o uma String num arquivo txt de 
*   acorda com um número aleatório que é passado pela função geradorDeNumAleatorio;  
*
*/

void pegarPalavraNoArquivo(FILE *arquivoPTR, char palavraDoArquivo[],int guardarValoresAleatorios[]){
    int i = 1, valorAleatorio, quantidadeDePalavrasNoArquivo; //Declaração das variáveis;
    
     if((arquivoPTR=fopen("arquivos/palavra.txt", "r")) == NULL){ //responsável por abrir o arquivo txt e verificar se o arquivo foi aberto;
            printf("O arquivo nao foi  encontrado!");
            exit(1); //finaliza o programa caso o arquivo não seja encontrado;
    }
    fscanf(arquivoPTR,"%d",&quantidadeDePalavrasNoArquivo);//responsável por ler a quantidade de palavras no arquivo;
    
    valorAleatorio = geradorDeNumAleatorio(quantidadeDePalavrasNoArquivo, guardarValoresAleatorios);//chamada da função geradorDeNumAleatorio e atribuição do valor retornado;
 
     while(!feof(arquivoPTR)){ // loop resposável por pegar a palavra de acorda com o valorAleatorio que foi passa pela função geradorDeNumAleatorio;
        fscanf(arquivoPTR,"%s",palavraDoArquivo);//le a string do arquivo sobrescrevendo atá incontrar o valor correspondente a valorAleatorio;
        i++;// incremento 
        if(i==valorAleatorio){ // condição reponsável por verificar se o valor de i é igual ao de valorAleatorio;
            break; // encerra o loop caso seja verdade;
        } 
    }
    fclose(arquivoPTR);//fecha o arquivo;
}


/*  
    Função : Responsável por checar se a entrada do usuário é um caracter que repreesente uma letra;
*/
int checarLetra(char palavraDoUsuario[],int tamanho){
    int i, valor;
    for(i = 0; i < tamanho; i++){   //for para percorrer a string entrada do usuário;
         if(palavraDoUsuario[i] == '\0'){ // condição de parada do loop;
            return valor = 1;  
         }else{ 
            valor = isalpha(palavraDoUsuario[i]);  // caso não seja uma letra a função isalpha retorna 0;
            if(valor == 0){ //codição para verificar se valor é igual a zero;  
            return valor = 0;
            }
        }
    }
}

/*
*   Função : Responsável por fazer a comparação de duas strings uma fornecida pelo usuário e outra fornecida pelo
*   arquivo de palavras;  
*/

int comparacaoPalavra(char palavraDoArquivo[], char palavraDoUsuario[]){
    int contador = 0, sentinela = 1, valor = 1;
    
    while(sentinela == 1){  //Loop para percorre o array das strings 
        if(palavraDoArquivo[contador] == '\0' || palavraDoUsuario[contador] == '\0') //condição que indica fim da string;
            break;
        if(palavraDoArquivo[contador] != palavraDoUsuario[contador]){  // condição que indica que as letras são diferentes;
            valor = 0;
            break;
        } 
        contador++;   // contador
    }
    return valor;
}

/*
* Função : Responsável por criar um loop caso a entrado do usuário seja uma letra inválida só parando 
*  quando a entrada fornecida seja uma letra válida; 
*/


void letraInvalida(int valorDeChecarLetra, char palavraDoUsuario[]){
    int sentinelaChecarPalavra=1;
    char palavraUsuario[TAMANHO_PALAVRA];
    
    if(valorDeChecarLetra==0){//condição reponsável por verificar se o valor passado de checarLetra foi igual a 0 
        while(sentinelaChecarPalavra != 0){//loop responsável por repetir até a entrada ser válida 
            printf("Caracter invalido digite de novo:\n");
            scanf("%s", palavraUsuario);
            valorDeChecarLetra =  checarLetra(palavraUsuario, TAMANHO_PALAVRA); //chamada da função checarLetra; 
            if(valorDeChecarLetra == 0){//condicional para checar o valor retornado de checarLetra;
                sentinelaChecarPalavra = 1;
            }else{
                sentinelaChecarPalavra = 0;  // caso a palavra seja válida a string passada primeiramente é subtituida pela 
                strcpy(palavraDoUsuario,palavraUsuario); // string válida passada a função strcpy faz esse trabalho; 
            } 
        }
    }   
}

/*
*   Função : responsável por checar se a palavra fornecida pelo usuário está presente no 
*   arquivo;
*/

int checarPalavraNoArquivo(FILE *arquivoPTR, char palavraDoUsuario[]){
    char palavraDoArquivo[TAMANHO_PALAVRA];
    int valor,teste;
    
    if((arquivoPTR = fopen("arquivos/palavra.txt","r"))==NULL){  //Reponsável por abrir o arquivo das palavras;
        printf("O arquivo NOT encontrado!!!");
        exit(1);
    }
    
    while(!feof(arquivoPTR)){//Loop responável por percorrer o arquivo comparadando a palavra do usuário com a do arquivo;
        fscanf(arquivoPTR,"%s",palavraDoArquivo);//leitura da palavra do arquivo;
        valor = strcmp(palavraDoArquivo,palavraDoUsuario);// strcmp compara as duas palavras e retorna 0 se forem iguis; 
        if(valor == 0) // checar se valor é igual a zero;
            break;
    }
     fclose(arquivoPTR);//fecha o arquivo;
     return valor;
}

/*
* Função : Responsável por verificar criar um loop caso a palavra do usuário não esteja no
*  arquivo;
*/

void palavraInvalida(int valorDeChecarPalavraNoArquivo, char palavraDoUsuario[],FILE *arquivoPTR){
    int sentinelaChecarPalavra=1;
    char palavraUsuario[TAMANHO_PALAVRA];

    if(valorDeChecarPalavraNoArquivo !=0){ //verifica se o valor retornado checarPalavraValidaNoArquivo é diferente de 0;
        while(sentinelaChecarPalavra != 0){ //Loop para receber uma palavra valida  
            printf("Palavra invalida digite de novo:\n");
            scanf("%s", palavraUsuario);
            valorDeChecarPalavraNoArquivo =  checarPalavraNoArquivo(arquivoPTR, palavraUsuario);//chamada  da função checarPalavraNoArquivo 
            if(valorDeChecarPalavraNoArquivo != 0){ // condicional para verificar o valor retornado de checarPalavraNoArquivo 
                sentinelaChecarPalavra = 1;
            }else{
                strcpy(palavraDoUsuario,palavraUsuario);//strcpy substitui a palavra inválida pela nova palavra válida 
                sentinelaChecarPalavra = 0;
            } 
        }
    }
}

/*
*   Função : Responsável por receber a string do usuário e chamar as funções 
*   para analisar se a palavra tem uma letra válida, se é uma palavra válida,
*   se as letras pertence, não pertencem ou estão em posiçôes erradas.
*/

int loopDojogo(FILE *arquivoPTR, char palavraNoArquivo[], char posicaoDaLetra[]){
    char palavraDoUsuario[TAMANHO_PALAVRA]; // guarda o valor digitado pelo usuário 
    int valorDeChecarLetra, valorDeChecarPalavraNoArquivo, valorDaComparacao;
    int rodada = 0, i, j, valor;


    while(rodada<6){
         //entrada do usuário 
        printf("##### VIDAS %d #####\n",6-(rodada));
        scanf("%5s", palavraDoUsuario);// %ns => n tem que ser mudado de acordo com tamnho da palavra

        // chamada da função checarLetra
        valorDeChecarLetra = checarLetra(palavraDoUsuario,TAMANHO_PALAVRA);

        //chamada da função letraInvalida
        letraInvalida(valorDeChecarLetra,palavraDoUsuario);
        
        //converte a entrada do usuário
         for(j=0; j<TAMANHO_PALAVRA; j++){
            palavraDoUsuario[j] = tolower(palavraDoUsuario[j]);
        }
        
        //chamada de checarPalavraNoArquivo
        valorDeChecarPalavraNoArquivo = checarPalavraNoArquivo(arquivoPTR,palavraDoUsuario);
        
        //printf(">%d\n",valorDeChecarPalavraNoArquivo);
        
        //Chamada da função palavraInvalida
        palavraInvalida(valorDeChecarPalavraNoArquivo,palavraDoUsuario,arquivoPTR);
     
        //chamada da função comparacao     
        valorDaComparacao = comparacaoPalavra(palavraNoArquivo, palavraDoUsuario);
        
        //chamda das funções de checar posição da letra
        posicaoLetraCerta(palavraDoUsuario,palavraNoArquivo,posicaoDaLetra);
        posicaoLetraPertence(palavraDoUsuario,palavraNoArquivo,posicaoDaLetra);
        posicaoLetraNaoPertence(posicaoDaLetra);
    
       
        // impressão da posição das letras 
        for(i=0; i<TAMANHO_PALAVRA; i++){
            printf("%c", posicaoDaLetra[i]);
        }

        printf("\n");

        // chamada da função zeraPosição 
        zeraPosicaoLetra(posicaoDaLetra);

        //checar valor retornada de comparacaoPalavra;
        if(valorDaComparacao==1){
            pontuacaoAtual += pontuacao(rodada);
            return valor = 1;
        }

        //contador de rodada;
        rodada++;

  }
}


