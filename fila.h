/*Definição das estruturas responsáveis pela criação da fila*/
typedef struct fila Fila;
typedef struct filano FilaNo;

//Estrutura para os elementos da fila (os nós)
struct filano {
 int info;
 FilaNo* prox;
 FilaNo* ant;
};
//Estrutura para a fila em si
struct fila {
 FilaNo* prim;
 FilaNo* ult;
};

/*Função responsável pela criação da fila duplamente encadeada*/
Fila* fila_cria(void);

/*Função responsável por inserir o valor passado por parametro na função, no final da fila*/
void fila_insere(Fila* f, int v);

/*Função responsável por retirar o valor que está no inicio da fila*/
// A função retorna o valor retirado para realizar a impressão no terminal
int fila_retira(Fila* f);

/*Função verifica se a fila está vazia*/
//Quando o inicio e o fim da fila são iguais a NULL, a fila está vazia.
//Retorna 1 se está vazia
int fila_vazia(Fila* f);

/*Função responsável por realizar a troca de dois nós,
passando a lista e os dois nós que precisam ser intercalados como parametro*/
void intercala(Fila *f,FilaNo *q,FilaNo *aux);

//Função responsável por liberar a memória da fila
void fila_libera(Fila* f);

/*Função realiza a impressão da fila na tela*/
//A impressão no terminal fica: Cliente -> 'idade'
void fila_imprime(Fila* f);