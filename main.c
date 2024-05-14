#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define letras 26
#define ptg 1
#define ing 2

void calcular_frequencia(char frase[], int frequencia[]) {
    for (int i = 0; frase[i] != '\0'; i++) {
        if (isalpha(frase[i])) {
            char letra = tolower(frase[i]);
            frequencia[letra - 'a']++;
        }
    }
}

int encontrar_idioma(int frequencia[]) {
    float freqptg[letras] = {0.1463, 0.0104, 0.0388, 0.0499, 0.1257, 0.0102, 0.0130, 0.0128, 0.0618, 0.0040, 0.0002, 0.0278, 0.0474, 0.0505, 0.1073, 0.0252, 0.0120, 0.0653, 0.0781, 0.0434, 0.0463, 0.0167, 0.0001, 0.0021, 0.0001, 0.0047};
    float freqing[letras] = {0.0817, 0.0149, 0.0278, 0.0425, 0.1270, 0.0223, 0.0202, 0.0609, 0.0697, 0.0153, 0.0072, 0.0403, 0.0241, 0.0675, 0.0751, 0.0193, 0.0009, 0.0599, 0.0633, 0.0906, 0.0276, 0.0098, 0.0236, 0.0015, 0.0197, 0.0007};

    float difptg = 0, difing = 0;
    for (int i = 0; i < letras; i++){
        difptg += fabs(freqptg[i] - frequencia[i]);
        difing += fabs(freqing[i] - frequencia[i]);
    }

    if (difptg < difing) {
        return ptg;
    }
    else {
        return ing;
    }
}

int main(void) {
    char frase[999];
    int frequencia[letras] = {0};
    int idioma;

    fgets(frase, sizeof(frase), stdin);
    // Remover o caractere de nova linha ('\n') se presente
    frase[strcspn(frase, "\n")] = '\0';
    calcular_frequencia(frase, frequencia);
    idioma = encontrar_idioma(frequencia);  

    if (idioma == ptg){
        printf("\nPortugues");
    }
    else {
        printf("\nIngles");
    }

    return 0;
}
