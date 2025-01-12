#include <stdio.h>
#include "pico/stdlib.h"

#define PINO_LED 13 // Pino conectado ao LED
#define TEMPO_PONTO 200   // Duração de um ponto (ms)
#define TEMPO_TRACO 800   // Duração de um traço (ms)
#define INTERVALO_GAP 125 // Intervalo entre pontos e traços (ms)
#define INTERVALO_LETRA 250 // Intervalo entre letras (ms)
#define INTERVALO_CICLO 3000 // Intervalo entre ciclos SOS (ms)

// Função para enviar um ponto
void enviar_ponto() {
    gpio_put(PINO_LED, true);
    sleep_ms(TEMPO_PONTO);
    gpio_put(PINO_LED, false);
    sleep_ms(INTERVALO_GAP);
}

int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
