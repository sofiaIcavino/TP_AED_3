#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/*Função responsável por ordenar a fila com ordem de prioridade do maior para o menor,
usando o algoritmo de ordenação com bubble sort.*/
void ordenaFila_bubbleSort(Fila *f){
FilaNo* q=f->prim; 
FilaNo* aux=q->prox; 
//flag responsável pelo critério de parada do while, recebe 1 para dar inicio a ordenação
int flagtroca=1; 

    while(flagtroca){
        /*Flagtroca garante que a repetição continue enquanto houver nós fora de ordem, 
        ela recebe 1 sempre que uma troca for feita para garantir que o processo continue.
        Caso não tenha acontecido nenhuma troca, quer dizer que a fila está ordenada,
        ocasionando o fim do algoritmo*/
        flagtroca=0; //flag recebe falso

        q=f->prim; // q recebe o primeiro elemento da fila no inicio de cada iteração
        //Garante assim que toda a lista seja revisada desde o inicio

        while (q && q->prox) {//Verifica se q e q->prox são diferentes de NULL

            //Caso 'q' seja menor que o valor do nó a sua direita
            if (q->info < q->prox->info) {//Comparação para realizar a troca dos nós em ordem decrescente
                
                /*Chama a função responsável por realizar a troca dos nós,
                passando a lista e os dois nós que precisam ser intercalados como parametro*/
                /*Intercalando o nó 'q', com o nó a sua direita (o q->prox)*/
                intercala(f,q,q->prox);
                
                flagtroca=1;// flagtroca recebe 1 marcando que houve troca

            }else{ // Caso não seja necessário realizar a troca
                q=q->prox; // 'q' avança para o próximo nó
            }
        }
    }
}

int main(){

    /*Realizando a abertura do arquivo "cliente.txt"*/
    FILE* arq = fopen("clientes.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
    }

    int idade;
    //Criação da fila duplamente encadeada
    Fila *f= fila_cria();

    /*Realizando a leitura das idades dos clientes a partir do 
    arquivo "cliente.txt" aberto anteriormente*/
    while(fscanf(arq,"%d",&idade)!=EOF){
        fila_insere(f,idade); //Inserindo a idade dos clientes na fila
    }

//Vericando se a fila é vazia
if (fila_vazia(f)){
    printf("\nFila vazia!\n");//Caso vazia vai imprimir a mensagem de alerta e encerrar a execução
    exit(1);
}else{
    //Caso contrário:

    //Realizar a impressão da fila "original" (não ordenada)
    printf("\nFILA BRADESCO ORIGINAL: ********\n\n");
    fila_imprime(f);
    printf("\n********************************\n\n");

    /*A fila é ordenada com ordem de prioridade do maior para o menor,
    usando a ordenação com bubble sort.*/
    ordenaFila_bubbleSort(f);
   
   //Realizar a impressão da fila com ordem de prioridade (já ordenada)
    printf("\nFILA BRADESCO ORDENADA: ********\n\n");
    fila_imprime(f);
    printf("\n********************************\n\n");


   //Realização do "atendimento" aos clientes da fila
    printf("\n******** ATENDIMENTO ********\n\n");
    printf("-----------------------------\n");

    /*Os clientes são atendidos e são retirados
    do inicio da fila, até no final a fila ficar vazia*/

    /*No while verifica se a fila ainda tem clientes para serem atendidos (não está vazia),
    caso verdadeiro é retirado o cliente do inicio da fila, caso contrário parando quando 
    a fila estiver vazia*/
    while(!fila_vazia(f)){
        int id_retira =fila_retira(f); // Função de retirada do inicio da fila
        printf("Cliente retirado da fila: %d\n",id_retira);// Impressão no terminal do cliente atendido
        printf("-----------------------------\n");
    }
    printf("\n*****************************\n\n");
    printf("Fila Vazia!\nClientes atendidos com sucesso.\n\n");
}

    //Liberação da memória
    fila_libera(f);
    //Fechamento do arquivo
    fclose(arq);

    return 0 ;
}