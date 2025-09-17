#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Alunos: Gustavo Souza Rocha e Ana Clara Nery
// Definição da struct Pokemon usando typedef 
typedef struct {
    int numero;
    char nome[50];
    char tipo[20];
} pokemon;

void imprime_pokedex(pokemon *pokedex, int n) {
    printf("\n--- POKEDEX ---\n");
    for (int i = 0; i < n; i++) {
        printf("#%d %s (%s)\n", pokedex[i].numero, pokedex[i].nome, pokedex[i].tipo);
    }
    printf("---------------\n");
}

int busca(pokemon *pokedex, int n, int numero) {
    for (int i = 0; i < n; i++) {
        if (pokedex[i].numero == numero) {
            return i; // Retorna o índice se encontrou
        }
    }
    return -1; // Retorna -1 se não encontrou
}

int main(void) {
    int total_pokemons = 3;

    // 1. Criar dinamicamente um vetor para armazenar 3 Pokemons
    pokemon *pokedex = (pokemon *) malloc(total_pokemons * sizeof(pokemon));
    if (pokedex == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    // 2. Preencher o vetor com 3 Pokémons
    pokedex[0].numero = 1;
    strcpy(pokedex[0].nome, "Bulbasaur");
    strcpy(pokedex[0].tipo, "Planta/Veneno");

    pokedex[1].numero = 4;
    strcpy(pokedex[1].nome, "Charmander");
    strcpy(pokedex[1].tipo, "Fogo");

    pokedex[2].numero = 7;
    strcpy(pokedex[2].nome, "Squirtle");
    strcpy(pokedex[2].tipo, "Agua");

    // 3. Imprimir todos os Pokémons da Pokedex
    printf("Pokedex inicial com %d Pokemons:", total_pokemons);
    imprime_pokedex(pokedex, total_pokemons);

    // 4. Expandir a Pokédex usando realloc para adicionar 2 novos Pokémons
    total_pokemons = 5;
    pokedex = (pokemon *) realloc(pokedex, total_pokemons * sizeof(pokemon));
    if (pokedex == NULL) {
        printf("Erro ao realocar memoria!\n");
        return 1;
    }

    // 5. Adicionar os 2 novos Pokémons
    pokedex[3].numero = 25;
    strcpy(pokedex[3].nome, "Pikachu");
    strcpy(pokedex[3].tipo, "Eletrico");

    pokedex[4].numero = 133;
    strcpy(pokedex[4].nome, "Eevee");
    strcpy(pokedex[4].tipo, "Normal");

    // 6. Imprimir novamente a Pokédex
    printf("\nPokedex expandida com %d Pokemons:", total_pokemons);
    imprime_pokedex(pokedex, total_pokemons);

    // 7. Testar a função busca
    printf("\n--- TESTANDO A FUNCAO DE BUSCA ---\n");

    // Teste 1: Pokémon existente
    int numero_busca_1 = 25;
    int indice_encontrado = busca(pokedex, total_pokemons, numero_busca_1);
    if (indice_encontrado != -1) {
        printf("Buscando pelo Pokemon #%d... Encontrado! -> %s\n", numero_busca_1, pokedex[indice_encontrado].nome);
    } else {
        printf("Buscando pelo Pokemon #%d... Nao encontrado na Pokedex.\n", numero_busca_1);
    }

    // Teste 2: Pokémon não existente
    int numero_busca_2 = 999;
    indice_encontrado = busca(pokedex, total_pokemons, numero_busca_2);
    if (indice_encontrado != -1) {
        printf("Buscando pelo Pokemon #%d... Encontrado! -> %s\n", numero_busca_2, pokedex[indice_encontrado].nome);
    } else {
        printf("Buscando pelo Pokemon #%d... Nao encontrado na Pokedex.\n", numero_busca_2);
    }
     printf("-----------------------------------\n");


    // Libera a memória alocada dinamicamente
    free(pokedex);

    return 0;
}