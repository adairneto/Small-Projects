#include <stdio.h>

int main() {
    int n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        float operando1, operando2;
        float resultado;
        char operador;
        scanf("%f %c %f", &operando1, &operador, &operando2);    
        switch (operador) {
            case '+':
                resultado = operando1 + operando2;
                break;
            case '-':
                resultado = operando1 - operando2;
                break;   
            case '*':
                resultado = operando1 * operando2;
                break;
            case '/':
                resultado = operando1 / operando2;
                break;         
        }
        printf("%f\n", resultado);
    }
}
