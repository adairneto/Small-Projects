#include <stdio.h>

int main() {
    int i, n;
    int velocidades[100];

    scanf("%d", &n);

    /* guardamos as velocidades */
    for (i = 0; i < n; i++) {
        scanf("%d", &velocidades[i]);
    }
    
    /* duração do evento */
    int duracao, limite;
    scanf("%d", &duracao);
    
    /* velocidade limite para o evento */
    if (duracao == 1) {
        limite = 100;
    }
    else if (duracao == 2) {
        limite = 20;
    }
    else {
        limite = 10;
    }
    
    /* maior velocidade das lesmas qualificadas */
    int maxima;
    maxima = 0;
    
    for (i = 0; i < n; i++) {
        if (velocidades[i] > maxima && velocidades[i] <= limite) {
            maxima = velocidades[i];
        }
    }
    
    /* imprime maior velocidade */
    printf("A maior velocidade é: %d\n", maxima);
}
