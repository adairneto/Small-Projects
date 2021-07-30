#include <stdio.h>
#include <string.h>

#define MAX_PALAVRA 20

/* poderia utilizar a função strlen do arquivo string.h */
int comprimento_str(char string[]) {
    int comprimento = 0;
    while (string[comprimento] != '\0') {
        comprimento += 1;
    }
    return comprimento;
}

void copiar_inverso(char palavra[], char inverso[]) {
    int i, j;
    i = comprimento_str(palavra) - 1;  /* índice da última letra de palavra */
    j = 0;                             /* índice da primeira posição de inverso */
    while (i >= 0) {
        /* copia a i-ésima letra de palavra para a j-ésima posição de inverso */
        inverso[j] = palavra[i];
        i = i - 1;
        j = j + 1;
    }
    /* adicionamos o '\0' para indicar que a string inverso terminou */
    inverso[j] = '\0';
}

void copiar_cebolinha(char palavra[], char palavra_modificada[]) {
	int i, j;
	int controle = 0;
	int len = comprimento_str(palavra) - 1;
	char letra;
	
	j = 0;
	for (i = 0; i <= len; i++) {
		letra = palavra[i];
		if (letra == 'R') {
			if (controle == 0) {
				palavra_modificada[j] = 'L';
				j++;
			}
			controle = 1;
		} else {
			palavra_modificada[j] = letra;
			controle = 0;
			j++;
		}
	}
	palavra_modificada[j] = '\0';
}

int main() {
	char palavra[MAX_PALAVRA];
	char inverso[MAX_PALAVRA];
	char palavra_modificada[MAX_PALAVRA];
	
	scanf("%s", palavra);
       	copiar_inverso(palavra, inverso);
	if (strcmp(palavra, inverso) == 0) /* se as strings são iguais */
		printf("É palíndromo\n");
	else
		printf("Não é palíndromo\n");
	
	copiar_cebolinha(palavra, palavra_modificada);
	printf("%s", palavra_modificada);
}
