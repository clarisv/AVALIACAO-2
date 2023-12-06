#include <stdio.h>

char Classifica(float salario) {
    if (salario > 1400) {
        return 'A';
    } else if (salario < 1400) {
        return 'B';
    } else {
        return 'I';
    }
}

/* mostrar a classificação do assalariado*/
void mostraClassifica(char classificacao, float salario, char sexo) {
    printf("\nsalario e: R$ %.4f", salario);

    switch (classificacao) {
        case 'A':
            printf("\nsalario acima do salario minimo");
            break;
        case 'B':
            printf("\nsalario abaixo do salario minimo");
            break;
        case 'I':
            printf("\nsalario igual ao salario minimo");
            break;
        default:
            break;
    }

    if (sexo == 'M') {
        printf("\nMasculino");
    } else {
        printf("\nFeminino");
    }
}

void mostraPessoas(int pessoasAcima, int pessoasAbaixo) {
    printf("\npessoas com salario acima do salario minimo: %d", pessoasAcima);
    printf("\npessoas com salario abaixo do salario minimo: %d", pessoasAbaixo);
}

int main() {
    char sexo;
    float salario;
    int saida, pessoasAcima = 0, pessoasAbaixo = 0;

    do {
        printf("digite seu Sexo: M / F ");
        scanf(" %c", &sexo);
        fflush(stdin);

        // Adiciona verificação de opção inválida para o sexo
        if (sexo != 'M' && sexo != 'F') {
            printf("opcao invalida. por favor, digite M para Masculino ou F para Feminino.\n");
            continue;
        }

        printf("\ndigite o valor do seu salario: ");
        scanf("%f", &salario);
        fflush(stdin);

        char classificacao = Classifica(salario);

        mostraClassifica(classificacao, salario, sexo);

        if (classificacao == 'A') {
            pessoasAcima++;
        } else if (classificacao == 'B') {
            pessoasAbaixo++;
        }

        do {
            printf("\ndeseja adicionar mais um cadastro? 1 - sim / 2 - nao ");
            scanf("%d", &saida);
            fflush(stdin);

            if (saida != 1 && saida != 2) {
                printf("opcao invalida. por favor, digite 1 para sim ou 2 para nao.\n");
            }
        } while (saida != 1 && saida != 2);

    } while (saida == 1);

    mostraPessoas(pessoasAcima, pessoasAbaixo);

    return 0;
}
