# Projeto Advinhe o Idioma

## Descrição do Projeto
 > **Neste projeto estamos desenvolvendo, um programa no qual a partir de em uma entrada de texto, determinamos qual idioma está sendo utilizado.**

### Recursos utilizados para este programa
Para este projeto utilizamos uma fonte de dados [Github Pages](https://pt.wikipedia.org/wiki/Frequ%C3%AAncia_de_letras), que tinha a frequência das letras de cada idioma, mas para o nosso programa só utilizamos o a língua portuguesa e a inglesa. 

### Lógica do Programa
Desenvolvemos uma função chamada detectar idioma, no qual divide a resolução do problema em 3 partes.

- Cálculo da frequência de letras
- Comparação da frequência das letras
- Determinar o idioma

### Cálculo da Frequência
Nesta parte da função, com as frequências das letras dos dois idiomas armazenadas em dois vetores. Fizemos um loop de iteração para percorrer o vetor de char(que declaramos como parâmetro da função), e contar as letras que se repetem ao longo do texto, para que em sequência, possamos utilizar estas informações como base para calcularmos a diferença.

```c
    float freqptg[letras] = {0.1463, 0.0104, 0.0388, 0.0499, 0.1260, 0.0102, 0.0130, 0.0128, 0.0618, 0.0040, 0.0002, 0.0278, 0.0474, 0.0505, 0.1073, 0.0252, 0.0120, 0.0653, 0.0781, 0.0434, 0.0463, 0.0167, 0.0001, 0.0021, 0.0001, 0.0047};
    float freqing[letras] = {0.0817, 0.0149, 0.0278, 0.0425, 0.1270, 0.0223, 0.0202, 0.0609, 0.0697, 0.0153, 0.0072, 0.0403, 0.0241, 0.0675, 0.0751, 0.0193, 0.0009, 0.0599, 0.0633, 0.0906, 0.0276, 0.0098, 0.0236, 0.0015, 0.0197, 0.0007};

    int pontuacao_ptg = 0, pontuacao_ing = 0;

    int frequencia[letras] = {0};
    for (int i = 0; frase[i] != '\0'; i++) {
        if (isalpha(frase[i])) {
            char letra = tolower(frase[i]);
            frequencia[letra - 'a']++;
        }
    }
```

### Comparação da frequência das letras
A partir das informações extraídas do texto de quantas letras se repetem, agora fazemos a comparação das frequências das letras esperadas para cada idioma. E com a condição de que se a diferença de um idioma for menor que a outra será pontuado, para que ocorra em breve seja determinado qual é o idioma utilizado no texto.

```c
    float dif_ptg = 0, dif_ing = 0;
    for (int i = 0; i < letras; i++) {
        dif_ptg = fabs(freqptg[i] - (float)frequencia[i]);
        dif_ing = fabs(freqing[i] - (float)frequencia[i]);

        if (dif_ptg < dif_ing) {
            pontuacao_ptg++;
        } else {
            pontuacao_ing++;
        }
    }
```

### Determinar o idioma
Na parte final desta função, a condição para determinar qual idioma está sendo utilizado pelo texto, é quantos pontos cada idioma fez a partir da menor diferença calculada anteriormente no código. Se o idioma teve mais pontos, então ele é o idioma que foi utilizado.

```c
    if (pontuacao_ptg > pontuacao_ing) {
        return ptg;
    } else {
        return ing;
    }
```

### Alguns pontos a serem observados
Nosso código não determina assertivamente ainda muitas entradas de texto inseridas. Qualquer ajuda de como melhorar nosso código será bem-vinda!!