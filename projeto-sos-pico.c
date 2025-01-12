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

// Função para enviar um traço
void enviar_traco() {
    gpio_put(PINO_LED, true);
    sleep_ms(TEMPO_TRACO);
    gpio_put(PINO_LED, false);
    sleep_ms(INTERVALO_GAP);
}

// Função para enviar o padrão SOS
void enviar_sos() {
    // Três pontos
    for (int i = 0; i < 3; i++) {
        enviar_ponto();
    }
    sleep_ms(INTERVALO_LETRA);

    // Três traços
    for (int i = 0; i < 3; i++) {
        enviar_traco();
    }
    sleep_ms(INTERVALO_LETRA);

    // Três pontos
    for (int i = 0; i < 3; i++) {
        enviar_ponto();
    }
    sleep_ms(INTERVALO_CICLO);
}

int main() {
    // Configuração do GPIO
    gpio_init(PINO_LED);
    gpio_set_dir(PINO_LED, GPIO_OUT);

    // Loop infinito para enviar o sinal SOS continuamente
    while (true) {
        enviar_sos();
    }
}
