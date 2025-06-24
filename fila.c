#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/*Função responsável por criar a fila duplamente encadeada*/
Fila* fila_cria (void) {
 Fila* f = malloc(sizeof(Fila));
 f->prim = NULL;
 f->ult = NULL;
 return f;
}

/*Função responsável por inserir os valores na fila - sempre no final da fila*/
void fila_insere(Fila* f, int v){
 FilaNo* novo = malloc(sizeof(FilaNo));
 novo->info = v; //novo recebe o valor inteiro passado por parametro na função
 novo->ant = f->ult; // o anterior ao novo aponta para o 'antigo' ultimo
 novo->prox = NULL; // o novo passa a ser o ultimo da fila

 if (f->ult != NULL){//Verifica se a fila não é vazia
 f->ult->prox = novo; // o 'antigo' ultimo da fila passa a ser o penultimo
 }
 else { //Verifica se a fila é vazia
 f->prim = novo; //inicio da fila aponta para novo
 }
 f->ult = novo;  //fim da fila aponta para novo
}

/*Função responsável por retirar os valores na fila - sempre no inicio da fila*/
int fila_retira(Fila* f){
 FilaNo* p = f->prim; //p recebe o primeiro elemento da fila para ser retirado
 int v = p->info; //variável inteira recebendo a valor que vai ser retirado
 //inicio da fila aponta para o sucessor de 'p', que será o novo primeiro elemento da fila
 f->prim = p->prox; 
 
 if (f->prim != NULL) { //Verifica se a fila não é vazia
    f->prim->ant = NULL; // Ajusta o ponteiro 'ant' do novo f->prim para NULL
 } else { //Verifica se a fila é vazia
    f->ult = NULL;  // Caso a fila ficou vazia, vai atualizar 'ult' para NULL
 }
 //O elemento é retirado da fila
 free(p);

 //O valor retirado eh retornado na função para realizar a impressão no terminal
 return v;
}

/*Função verifica se a fila está vazia*/
int fila_vazia(Fila* f){
//Quando o inicio e o fim da fila são iguais a NULL, a fila está vazia.
//Retorna 1 se está vazia
 return (f->prim == NULL && f->ult == NULL); 
}

/*Função realiza a impressão da fila na tela*/
void fila_imprime(Fila* f){
 FilaNo* p = f->prim;
 for(p= f->prim; p!=NULL; p=p->prox ){
 printf("Cliente -> %d\n", p->info);
 }
}

/*Função responsável por realizar a troca de dois nós,
passando a lista e os dois nós que precisam ser intercalados como parametro para a função*/
/*'q' é o nó a esquerda de 'aux', para assim intercalar os nós e 'aux' ficar a esquerda de 'q'*/
void intercala(Fila *f,FilaNo *q,FilaNo* aux){
   // Caso 'q' seja o primeiro nó 
   if (q == f->prim) {
      /*irá atualizar o primeiro nó, fazendo que ele aponte para aux,
      que será o novo primeiro elemento*/
      f->prim = aux; 
   }else{ // Caso contrário:
      /*O ponteiro "prox" do nó anterior a 'q' recebe aux*/
      q->ant->prox = aux; 
   }

   // Caso 'aux' seja o último nó 
   if (aux == f->ult) {
      /*irá atualizar o ultimo nó, fazendo que ele aponte para 'q',
      que será o novo ultimo elemento*/
      f->ult = q;
   }else{ // Caso contrário:
      /*O ponteiro "ant" do proximo nó após 'aux' recebe 'q'*/
      aux->prox->ant = q;
   }

   /* q->prox aponta para o próximo nó de 'aux', assim fazendo com que 'q' fique 
   depois de 'aux' na lista.*/
   q->prox = aux->prox;

   /* aux->ant aponta para o nó anterior a 'p', assim fazendo com que 'aux' fique 
   antes de 'q' na lista.*/
   aux->ant = q->ant;

   /* aux->prox aponta para 'q', fazendo assim ligação direta entre 'aux' e 'q'*/
   aux->prox = q;

   /* q->ant aponta para 'aux', finalmente completando a troca de posição entre 
   os dois nós.*/
   q->ant = aux;
}

//Função responsável por liberar a memória da fila
void fila_libera(Fila* f){
 FilaNo* q = f->prim;
 while (q != NULL) {
 FilaNo* t = q->prox;
 free(q);
 q = t;
 }
 free(f);
}

