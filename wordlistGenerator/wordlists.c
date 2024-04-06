#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateWordlist(char *name) {
    FILE *file;
    char filename[50];
    int i, j, k, l;
    char specialChars[] = "!@#$%^&*";

    sprintf(filename, "%s_wordlist.txt", name); // Nome do arquivo de saída

    file = fopen(filename, "w"); // Abre o arquivo para escrita

    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.", filename);
        return;
    }

    // Escreve o nome original no arquivo
    fprintf(file, "%s\n", name);

    // Adiciona todas as sequências possíveis de quatro números
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < 10; k++) {
                for (l = 0; l < 10; l++) {
                    fprintf(file, "%s%d%d%d%d\n", name, i, j, k, l);
                }
            }
        }
    }

    // Adiciona todas as combinações com dois números
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            fprintf(file, "%s%d%d\n", name, i, j);
        }
    }

    // Adiciona todas as combinações com dois números mais um caractere especial
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            for (k = 0; k < strlen(specialChars); k++) {
                fprintf(file, "%s%d%d%c\n", name, i, j, specialChars[k]);
            }
        }
    }

    fclose(file); // Fecha o arquivo
}

int main() {
    char name[50];

    printf("Digite o nome para gerar a wordlist: ");
    scanf("%s", name);

    generateWordlist(name);

    printf("Wordlist gerada com sucesso!\n");

    return 0;
}
