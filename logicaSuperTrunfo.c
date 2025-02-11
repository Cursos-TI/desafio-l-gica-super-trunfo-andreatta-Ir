#include <stdio.h>
#include <string.h>

// Definição da estrutura para armazenar os dados da cidade
struct Cidade {
    char codigo[10];
    char nome[50];
    char estado[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional; // Calculada como população/área
};

// Função para cadastrar as informações da cidade
void cadastrarCidade(struct Cidade* cidade) {
    printf("\nDigite o código da cidade: ");
    scanf("%s", cidade->codigo);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]s", cidade->nome); // Para ler espaços
    printf("Digite o estado da cidade: ");
    scanf(" %[^\n]s", cidade->estado);
    printf("Digite a população da cidade: ");
    scanf("%d", &cidade->populacao);
    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &cidade->area);
    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &cidade->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);

    // Calculando a densidade populacional
    cidade->densidade_populacional = cidade->populacao / cidade->area;
}

// Função para comparar as cartas de duas cidades
void compararCartas(struct Cidade cidadeA, struct Cidade cidadeB, char atributo[]) {
    printf("\nComparando as cartas com base no atributo: %s\n", atributo);

    // Comparação baseada no atributo
    if (strcmp(atributo, "populacao") == 0) {
        if (cidadeA.populacao > cidadeB.populacao) {
            printf("A cidade %s tem maior população.\n", cidadeA.nome);
        } else if (cidadeA.populacao < cidadeB.populacao) {
            printf("A cidade %s tem maior população.\n", cidadeB.nome);
        } else {
            printf("As duas cidades têm a mesma população.\n");
        }
    } 
    else if (strcmp(atributo, "area") == 0) {
        if (cidadeA.area > cidadeB.area) {
            printf("A cidade %s tem maior área.\n", cidadeA.nome);
        } else if (cidadeA.area < cidadeB.area) {
            printf("A cidade %s tem maior área.\n", cidadeB.nome);
        } else {
            printf("As duas cidades têm a mesma área.\n");
        }
    }
    else if (strcmp(atributo, "pib") == 0) {
        if (cidadeA.pib > cidadeB.pib) {
            printf("A cidade %s tem maior PIB.\n", cidadeA.nome);
        } else if (cidadeA.pib < cidadeB.pib) {
            printf("A cidade %s tem maior PIB.\n", cidadeB.nome);
        } else {
            printf("As duas cidades têm o mesmo PIB.\n");
        }
    } 
    else if (strcmp(atributo, "pontos_turisticos") == 0) {
        if (cidadeA.pontos_turisticos > cidadeB.pontos_turisticos) {
            printf("A cidade %s tem mais pontos turísticos.\n", cidadeA.nome);
        } else if (cidadeA.pontos_turisticos < cidadeB.pontos_turisticos) {
            printf("A cidade %s tem mais pontos turísticos.\n", cidadeB.nome);
        } else {
            printf("As duas cidades têm o mesmo número de pontos turísticos.\n");
        }
    } 
    else if (strcmp(atributo, "densidade_populacional") == 0) {
        if (cidadeA.densidade_populacional < cidadeB.densidade_populacional) {
            printf("A cidade %s tem menor densidade populacional.\n", cidadeA.nome); // Menor densidade vence
        } else if (cidadeA.densidade_populacional > cidadeB.densidade_populacional) {
            printf("A cidade %s tem menor densidade populacional.\n", cidadeB.nome);
        } else {
            printf("As duas cidades têm a mesma densidade populacional.\n");
        }
    } else {
        printf("Atributo inválido.\n");
    }
}

int main() {
    struct Cidade cidade1, cidade2;
    char atributo[50];

    // Cadastro das duas cidades
    printf("Cadastro da primeira cidade:\n");
    cadastrarCidade(&cidade1);

    printf("\nCadastro da segunda cidade:\n");
    cadastrarCidade(&cidade2);

    // Escolha do atributo para comparação
    printf("\nEscolha o atributo para comparar (populacao, area, pib, pontos_turisticos, densidade_populacional): ");
    scanf(" %[^\n]s", atributo);

    // Comparação entre as cartas
    compararCartas(cidade1, cidade2, atributo);

    return 0;
}
