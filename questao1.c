/*Se o número de peças for inferior ou igual a 50, não existe adicional de produtividade;
  Se o número de peças for superior a 50 e inferior ou igual a 80, o adicional de produtividade será de R$ 0,50 para cada peça fabricada acima de 50;
  Se o número de peças for superior a 80, o adicional de produtividade será de R$ 0,50 para cada peça fabricada acima de 50 até 80 e de R$ 0,75 por peça fabricada acima das 80.
*/

#include <stdio.h>

float validaQuantidade(int quantidade);
float calculaSalario(int quantidade);
void mostraFinal(float salarioBase, float adicional);
float adicional = 0.0;

int main(){

    int quantidade;
    char continuar;

    do{
        
        printf("\ncalculando adicionais de produtividade!");
    
        /*solicitando quantidade de pecas*/
        printf("\ndigite a quantidade de pecas fabricadas: ");
        scanf("%d", &quantidade);

        /*validando quantidade*/
        while (validaQuantidade(quantidade) == 0) {
            printf("\nquantidade invalida. digite novamente: ");
            scanf("%d", &quantidade);
        }

        /*calculando e exibindo o salário*/
        float salarioBase = calculaSalario(quantidade);
        mostraFinal(salarioBase, adicional);

        /*opção para continuar*/
        printf("\ndeseja calcular o salario para outro funcionario? (S/N): ");
        scanf(" %c", &continuar);

    }while (continuar == 'S' || continuar == 's');

    printf("\nprograma encerrado.");

    return 0;
}

/*validando quantidade*/
float validaQuantidade(int quantidade) {
    if (quantidade >= 0) {
        return 1;
    } else {
        return 0;
    }
}

/*calculando e exibindo o salário*/
float calculaSalario(int quantidade) {
    if (quantidade > 50 && quantidade <= 80) {
        adicional = (quantidade - 50) * 0.50;
    } else if (quantidade > 80) {
        adicional = (30 * 0.50) + (quantidade - 80) * 0.75;
    }

    return adicional;
}

/*salario final*/
void mostraFinal(float salarioBase, float adicional) {
    printf("\no salario final sera: R$ %.2f\n", salarioBase + adicional + 600.0);
}