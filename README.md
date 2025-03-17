#include <stdio.h>

// Estrutura da Carta
typedef struct {
    char nome[50];
    unsigned long int populacao;
    float area;
    double pib;
    int pontos_turisticos;
    float densidade_populacional;
    double pib_per_capita;
} Carta;

// Função para exibir o menu de atributos e capturar a escolha do usuário
int escolherAtributo(int excluido) {
    int escolha;
    do {
        printf("\nEscolha um atributo para comparar:\n");
        if (excluido != 1) printf("1 - População\n");
        if (excluido != 2) printf("2 - Área\n");
        if (excluido != 3) printf("3 - PIB\n");
        if (excluido != 4) printf("4 - Pontos Turísticos\n");
        if (excluido != 5) printf("5 - Densidade Populacional\n");
        if (excluido != 6) printf("6 - PIB per Capita\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        if (escolha < 1 || escolha > 6 || escolha == excluido)
            printf("Opção inválida! Escolha um atributo válido.\n");

    } while (escolha < 1 || escolha > 6 || escolha == excluido);

    return escolha;
}

// Função para obter o valor do atributo escolhido de uma carta
double obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontos_turisticos;
        case 5: return c.densidade_populacional;
        case 6: return c.pib_per_capita;
        default: return 0; // Nunca deve ocorrer
    }
}

// Função para comparar dois atributos e determinar qual carta vence
int compararAtributos(double valor1, double valor2, int atributo) {
    return (atributo == 5) ? (valor1 < valor2) : (valor1 > valor2);
}

// Função principal
int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 214000000, 8515767, 2200000000000, 50, 25.1, 10290};
    Carta carta2 = {"EUA", 331000000, 9833517, 21000000000000, 100, 33.7, 63500};

    printf("Cartas disponíveis:\n1 - %s\n2 - %s\n", carta1.nome, carta2.nome);

    // Escolher os dois atributos
    int atributo1 = escolherAtributo(0);
    int atributo2 = escolherAtributo(atributo1);

    // Obter os valores dos atributos para cada carta
    double valor1_c1 = obterValorAtributo(carta1, atributo1);
    double valor1_c2 = obterValorAtributo(carta2, atributo1);
    double valor2_c1 = obterValorAtributo(carta1, atributo2);
    double valor2_c2 = obterValorAtributo(carta2, atributo2);

    // Comparação dos atributos
    int resultado1 = compararAtributos(valor1_c1, valor1_c2, atributo1);
    int resultado2 = compararAtributos(valor2_c1, valor2_c2, atributo2);

    // Soma dos valores dos atributos
    double soma_c1 = valor1_c1 + valor2_c1;
    double soma_c2 = valor1_c2 + valor2_c2;

    // Determinação do vencedor geral
    int vencedor = (soma_c1 > soma_c2) ? 1 : (soma_c1 < soma_c2) ? 2 : 0;

    // Exibição do resultado
    printf("\nComparação de Cartas:\n");
    printf("Atributo 1: %d -> %s: %.2f | %s: %.2f\n", atributo1, carta1.nome, valor1_c1, carta2.nome, valor1_c2);
    printf("Atributo 2: %d -> %s: %.2f | %s: %.2f\n", atributo2, carta1.nome, valor2_c1, carta2.nome, valor2_c2);
    printf("\nSoma dos atributos:\n%s: %.2f\n%s: %.2f\n", carta1.nome, soma_c1, carta2.nome, soma_c2);

    // Exibir o vencedor
    if (vencedor == 0)
        printf("\nResultado: Empate!\n");
    else
        printf("\nResultado: %s venceu!\n", (vencedor == 1) ? carta1.nome : carta2.nome);

    return 0;
}
