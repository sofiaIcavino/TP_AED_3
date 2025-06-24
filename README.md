# Fila de Prioridade com Ordenação Bubble Sort

Este projeto implementa uma **fila duplamente encadeada** em C que simula o **atendimento de clientes com base na idade** (prioridade). A fila é preenchida com dados lidos de um arquivo `clientes.txt`, ordenada do cliente mais velho para o mais novo utilizando o algoritmo **Bubble Sort**, e então os clientes são "atendidos" (removidos da fila).

## 📁 Estrutura do Projeto

- `main.c`: Arquivo principal que realiza a leitura do arquivo, ordena a fila e executa os atendimentos.
- `fila.h`: Cabeçalho contendo as estruturas e protótipos das funções da fila.
- `fila.c`: Implementação das funções da fila.
- `clientes.txt`: Arquivo de entrada com uma lista de idades (um valor por linha).
- `README.md`: Este documento.

## 🔧 Compilação

Para compilar o projeto, utilize o GCC ou qualquer compilador C compatível. No terminal:

```bash
gcc main.c fila.c -o programa
```

## ▶️ Execução

Certifique-se de que o arquivo `clientes.txt` esteja na mesma pasta que o executável. Em seguida, execute:

```bash
./programa
```

## 📄 Formato do Arquivo `clientes.txt`

O arquivo deve conter uma lista de idades (inteiros), uma por linha. Exemplo:

```
32
45
29
60
18
```

## 🧠 Funcionalidades

- Leitura dos dados do arquivo `clientes.txt`
- Inserção dos dados na fila (final da fila)
- Impressão da fila original
- Ordenação da fila por idade (prioridade maior = idade maior)
- Impressão da fila ordenada
- Atendimento e remoção dos clientes da fila (início da fila)
- Liberação da memória

## 🔁 Ordenação por Bubble Sort

A função `ordenaFila_bubbleSort` percorre a fila diversas vezes, trocando os nós de lugar até que estejam em ordem decrescente de idade, utilizando a função auxiliar `intercala` para reorganizar os ponteiros da lista duplamente encadeada.

## ✅ Requisitos

- Compilador C (ex: `gcc`)
- Sistema operacional com suporte a terminal/shell
- Arquivo `clientes.txt` com dados válidos

## 📌 Observações

- A fila é duplamente encadeada, o que facilita as trocas de nós durante a ordenação.
- A função `fila_vazia` garante segurança na manipulação da estrutura.
- A ordenação respeita a lógica de maior idade como maior prioridade.

## 👩‍💻 Autoria

Este projeto foi criado para fins educacionais e acadêmicos, como prática de estruturas de dados em linguagem C.
