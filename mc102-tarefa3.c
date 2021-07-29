#include <stdio.h>

#define MAX_ALUNOS 100

float ler_media(int m) {
    int i;
    float media, nota;
    media = 0;
    for (i = 0; i < m; i++) {
        scanf("%f", &nota);
        media += nota;
    }
    media = media / m;
    return media;
}

void ler_notas_praticas(float P[MAX_ALUNOS], int n) {
    int i; /* índice da posição do vetor */
    for (i = 0; i < n; i++) {
        P[i] = ler_media(3);
    }
}

void ler_notas_teoricas(float T[MAX_ALUNOS], int n) {
    int i; /* índice da posição do vetor */
    for (i = 0; i < n; i++) {
        T[i] = ler_media(2);
    }
}

float obter_maximo(float vetor[MAX_ALUNOS], int n) {
    int i;
    float maximo = vetor[0];
    for (i = 0; i < n; i++) {
        if (maximo < vetor[i])
            maximo = vetor[i];
    }
    return maximo;
}

void multiplicar_fator(float vetor[MAX_ALUNOS], int n, float fator) {
    int i;
    for (i = 0; i < n; i++) {
        vetor[i] = vetor[i] * fator;
    }
}

float obter_media(float vector[MAX_ALUNOS], int n) {
	int i;
	float media = 0;
	for (i = 0; i < n; i++) {
		media += vector[i];
	}
	media = media / n;
	return media;
}

void imprimir_notas(float P[MAX_ALUNOS], float T[MAX_ALUNOS], int n) {
	float maximo_p, maximo_t, media_p, media_t;
	float MF[MAX_ALUNOS];
	int i;
	
	/* cálculo da média final por aluno */
	for (i = 0; i < n; i++) {
		MF[i] = (P[i] + T[i]) / 2;
		printf("%f\n", MF[i]);
	}	
	
	maximo_p = obter_maximo(P, n);
	maximo_t = obter_maximo(T, n);
	media_p = obter_media(P, n);
	media_t = obter_media(T, n);
	
	printf("Max P: %f\n", maximo_p);
	printf("Max T: %f\n", maximo_t);
	printf("Med P: %f\n", media_p);
	printf("Med T: %f\n", media_t);	
}

int main() {
    int n;
    float P[MAX_ALUNOS], T[MAX_ALUNOS];
    float maximo, fator;
    scanf("%d", &n);
	
    ler_notas_praticas(P, n);
	ler_notas_teoricas(T, n);
	maximo = obter_maximo(T, n);
	fator = 10 / maximo;
	multiplicar_fator(T, n, fator);
    multiplicar_fator(P, n, 1.1);
    imprimir_notas(P, T, n);
}
