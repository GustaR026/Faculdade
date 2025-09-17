// Nomes: [Seu Nome Completo] e [Nome do Colega, se aplicável]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//===
// POKEDEX Tabela Hash com Lista Encadeada (Separate Chaining)
//
// Objetivo
// - Implementar TABELA HASH com tratamento de colisoes por
//   LISTA ENCADEADA (separate chaining).
// Cada posicao do vetor (bucket) guarda o inicio de uma lista.
// Colisoes viram nos adicionais no mesmo bucket.
//===

#define TAM 11 // numero primo ajuda na distribuicao

// Estrutura do dado armazenado (registro da Pokedex)
typedef struct {
    int numero;      // chave (numero da Pokedex)
    char nome[50];
    char tipo[20];
} Pokemon;

// No da lista de cada bucket
typedef struct Node {
    Pokemon registro;      // dado do no
    struct Node *next; // proximo no
} Node;

// PROTOTIPOS
int h(int chave);
void inicializar(Node *tab[]);
int buscar(Node *tab[], int numero);
int inserir(Node *tab[], int numero, const char *nome, const char *tipo);
int remover_pokemon(Node *tab[], int numero);
void imprimir_pokedex(Node *tab[]);
void imprimir_tabela(Node *tab[]);

// Funcao hash
// O que fazer: calcular indice do bucket (0..TAM-1)
int h(int chave) {
    return (chave % TAM);
}

// Inicializacao da tabela
// O que fazer: colocar NULL em todas as posicoes do vetor
void inicializar(Node *tab[]) {
    // TODO: definir tab[i] = NULL para todo i
    for (int i = 0; i < TAM; i++) {
        tab[i] = NULL;
    }
}

// Buscar por numero
// O que fazer:
// - Calcular bucket com h(numero)
// - Percorrer lista encadeada
// - Se encontrar, retornar indice do bucket
// - Caso contrario, retornar -1
int buscar(Node *tab[], int numero) {
    // TODO: implementar busca
    int idx = h(numero);
    Node *p = tab[idx];
    while (p) {
        if (p->registro.numero == numero) {
            return idx; // Encontrado, retorna o índice do bucket
        }
        p = p->next;
    }
    return -1; // placeholder
}

// Inserir novo registro
// O que fazer:
// - Se ja existir (buscar), retornar -1
// - Calcular idx = h(numero)
// - Alocar no (malloc)
// - Copiar numero, nome e tipo para novo->registro
// - Encadear no inicio da lista: novo->next = tab[idx]
// - tab[idx] = novo
// - Retornar 1 se deu certo; 0 se falhar
int inserir(Node *tab[], int numero, const char *nome, const char *tipo) {
    // TODO: implementar insercao
    if (buscar(tab, numero) != -1) {
        return -1; // Já existe
    }

    int idx = h(numero);
    Node *novo = (Node *)malloc(sizeof(Node));
    if (!novo) {
        return 0; // Falha na alocação de memória
    }

    novo->registro.numero = numero;
    strcpy(novo->registro.nome, nome);
    strcpy(novo->registro.tipo, tipo);

    novo->next = tab[idx];
    tab[idx] = novo;

    return 1; // Sucesso
}

// Remover por numero
// O que fazer:
// - Calcular idx = h(numero)
// - Percorrer lista guardando anterior e atual
// - Ao encontrar, religar a lista e liberar no
// - Retornar 1 se removeu; 0 se nao achou
int remover_pokemon(Node *tab[], int numero) {
    // TODO: implementar remocao
    int idx = h(numero);
    Node *atual = tab[idx];
    Node *anterior = NULL;

    // Percorre a lista no bucket para encontrar o pokemon
    while (atual != NULL && atual->registro.numero != numero) {
        anterior = atual;
        atual = atual->next;
    }

    // Se não encontrou (lista do bucket acabou)
    if (atual == NULL) {
        return 0;
    }

    // Se encontrou, remove o nó
    if (anterior == NULL) {
        // O nó a ser removido é o primeiro da lista
        tab[idx] = atual->next;
    } else {
        // O nó está no meio ou no fim da lista
        anterior->next = atual->next;
    }

    free(atual);
    return 1; // Removeu com sucesso
}


// Imprimir Pokedex (todos os registros)
// Implementacao fornecida
void imprimir_pokedex(Node *tab[]) {
    int vazio = 1;
    for (int i = 0; i < TAM; i++) {
        for (Node *p = tab[i]; p != NULL; p = p->next) {
            printf("#%d %s (%s)\n", p->registro.numero, p->registro.nome, p->registro.tipo);
            vazio = 0;
        }
    }
    if (vazio) printf("(Pokedex vazia)\n");
}

// Imprimir Tabela (cadeias por bucket)
// Implementacao fornecida
void imprimir_tabela(Node *tab[]) {
    for (int i = 0; i < TAM; i++) {
        printf("[%d]: ", i);
        if (!tab[i]) {
            printf("-\n");
            continue;
        }
        Node *p = tab[i];
        while (p) {
            printf("%d", p->registro.numero);
            p = p->next;
            if (p) printf(" -> ");
        }
        printf("\n");
    }
}

//==== DEMO/MENU ====
int main(void) {
    Node *tabela[TAM];
    inicializar(tabela);

    int opcao;
    do {
        printf("\n=== MENU POKEDEX (HASH + LISTA) ===\n");
        printf("1) Capturar Pokemon\n");
        printf("2) Buscar Pokemon por numero\n");
        printf("3) Remover Pokemon\n");
        printf("4) Listar Pokemons da Pokedex\n");
        printf("5) Imprimir Tabela Hash (cadeias)\n");
        printf("0) Sair\n");
        printf("Opcao: ");
        if (scanf("%d", &opcao) != 1) return 0;

        switch (opcao) {
            case 1: {
                int numero; char nome[50]; char tipo[20];
                printf("\nInforme os dados do Pokemon abaixo.\n");
                // Leitura do numero
                printf("Numero: ");
                scanf("%d", &numero);
                int c; while ((c = getchar()) != '\n' && c != EOF);
                // Leitura do nome
                printf("Nome: ");
                if (fgets(nome, sizeof(nome), stdin)) {
                    nome[strcspn(nome, "\n")] = '\0';
                }
                // Leitura do tipo
                printf("Tipo: ");
                if (fgets(tipo, sizeof(tipo), stdin)) {
                    tipo[strcspn(tipo, "\n")] = '\0';
                }

                int r = inserir(tabela, numero, nome, tipo);
                if (r == 1)
                    printf("Inserido com sucesso.\n");
                else if (r == -1)
                    printf("Ja existe esse numero na Pokedex.\n");
                else
                    printf("Falha ao inserir (ou funcao nao implementada).\n");
                break;
            }
            case 2: {
                int numero;
                printf("Numero do Pokemon a ser buscado: ");
                scanf("%d", &numero);
                int pos = buscar(tabela, numero);
                if (pos >= 0)
                    printf("Encontrado no bucket %d.\n", pos);
                else
                    printf("Nao encontrado.\n");
                break;
            }
            case 3: {
                int numero;
                printf("Numero do Pokemon a ser removido: ");
                scanf("%d", &numero);
                if (remover_pokemon(tabela, numero))
                    printf("Removido.\n");
                else
                    printf("Nao encontrado (ou funcao nao implementada).\n");
                break;
            }
            case 4:
                imprimir_pokedex(tabela);
                break;
            case 5:
                imprimir_tabela(tabela);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    // Liberacao de memoria
    // O que fazer:
    // - Percorrer cada bucket i
    // - Percorrer lista liberando nos com free
    for (int i = 0; i < TAM; i++) {
        // TODO: liberar lista do bucket i
        Node *atual = tabela[i];
        while (atual != NULL) {
            Node *proximo = atual->next;
            free(atual);
            atual = proximo;
        }
    }

    return 0;
}