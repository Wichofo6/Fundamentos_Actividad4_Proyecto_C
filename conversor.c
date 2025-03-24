#include <stdio.h>

// Tasas de cambio (valores aproximados, actualízalos según el mercado)
#define GTQ_TO_USD 0.13
#define GTQ_TO_EUR 0.12
#define USD_TO_GTQ 7.8
#define USD_TO_EUR 0.92
#define EUR_TO_GTQ 8.5
#define EUR_TO_USD 1.09

// Función para convertir moneda
double convertirMoneda(double cantidad, int monedaOrigen, int monedaDestino) {
    if (monedaOrigen == 1 && monedaDestino == 2) return cantidad * GTQ_TO_USD; // GTQ a USD
    if (monedaOrigen == 1 && monedaDestino == 3) return cantidad * GTQ_TO_EUR; // GTQ a EUR
    if (monedaOrigen == 2 && monedaDestino == 1) return cantidad * USD_TO_GTQ; // USD a GTQ
    if (monedaOrigen == 2 && monedaDestino == 3) return cantidad * USD_TO_EUR; // USD a EUR
    if (monedaOrigen == 3 && monedaDestino == 1) return cantidad * EUR_TO_GTQ; // EUR a GTQ
    if (monedaOrigen == 3 && monedaDestino == 2) return cantidad * EUR_TO_USD; // EUR a USD
    return cantidad; // Si no hay conversión, devuelve la misma cantidad
}

int main() {
    int monedaOrigen, monedaDestino;
    double cantidad, resultado;

    printf("Conversor de Monedas\n");
    printf("1: Quetzales (GTQ)\n");
    printf("2: Dólares (USD)\n");
    printf("3: Euros (EUR)\n");

    printf("Seleccione la moneda de origen (1-3): ");
    scanf("%d", &monedaOrigen);

    printf("Seleccione la moneda de destino (1-3): ");
    scanf("%d", &monedaDestino);

    if (monedaOrigen < 1 || monedaOrigen > 3 || monedaDestino < 1 || monedaDestino > 3 || monedaOrigen == monedaDestino) {
        printf("Selección inválida. Inténtelo de nuevo.\n");
        return 1;
    }

    printf("Ingrese la cantidad a convertir: ");
    scanf("%lf", &cantidad);

    resultado = convertirMoneda(cantidad, monedaOrigen, monedaDestino);

    printf("Resultado: %.2f\n", resultado);

    return 0;
}