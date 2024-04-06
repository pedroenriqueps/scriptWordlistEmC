#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarSenha(char *senha, int comprimento) {
    const char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i;
    srand(time(NULL));

    for (i = 0; i < comprimento; ++i) {
        senha[i] = caracteres[rand() % (sizeof(caracteres) - 1)];
    }
    senha[comprimento] = '\0';
}

void salvarSenha(const char *nome, const char *senha) {
    FILE *arquivo = fopen("senhas.txt", "a"); // Abre o arquivo para escrita (append mode)
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar a senha.\n");
        return;
    }
    fprintf(arquivo, "%s: %s\n", nome, senha); // Escreve a senha no arquivo
    fclose(arquivo);
}

int main() {
    int comprimento;

    while (1) {
        printf("Digite o comprimento da senha desejada: ");
        scanf("%d", &comprimento);

        if (comprimento <= 0) {
            printf("Comprimento inválido.\n");
        } else {
            break;
        }
    }

    char senha[comprimento + 1];
    gerarSenha(senha, comprimento);
    printf("Senha gerada: %s\n", senha);

    char opcao;
    printf("Deseja salvar esta senha? (s/n): ");
    scanf(" %c", &opcao);

    if (opcao == 's' || opcao == 'S') {
        char nome[100];
        printf("Digite um nome para a senha: ");
        scanf("%s", nome);
        salvarSenha(nome, senha);
        printf("Senha salva com sucesso no arquivo 'senhas.txt'.\n");
    } else if (opcao == 'n' || opcao == 'N') {
        printf("Senha não salva.\n");

        printf("Deseja gerar outra senha? (s/n): ");
        scanf(" %c", &opcao);

        if (opcao == 's' || opcao == 'S') {
            gerarSenha(senha, comprimento);
            printf("Nova senha gerada: %s\n", senha);

            printf("Deseja salvar esta nova senha? (s/n): ");
            scanf(" %c", &opcao);

            if (opcao == 's' || opcao == 'S') {
                char nome[100];
                printf("Digite um nome para a nova senha: ");
                scanf("%s", nome);
                salvarSenha(nome, senha);
                printf("Nova senha salva com sucesso no arquivo 'senhas.txt'.\n");
            }
        }
    } else {
        printf("Opção inválida.\n");
    }

    return 0;
}
