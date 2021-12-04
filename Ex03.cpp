#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define True 1
#define TAM 256


typedef struct {
    char nome[TAM];
    int cpf;
} Cliente;

typedef struct {
    int numeroDaConta;
    Cliente cliente;
    float saldo;
} Conta;


void depositar(Conta *conta, float valor) {
    if (valor < 0) {
        printf("\nValor precisa ser positivo.\n");
        return;
    }
    conta->saldo = conta->saldo + valor;
    printf("\nDeposito realizado com sucesso!\n");

}

void sacar(Conta *conta, float valor) {
    if (conta->saldo < valor) {
        printf("\nSaldo insuficiente.\n");
        return;
    }
    conta->saldo = conta->saldo - valor;
    printf("\nSaque realizado com sucesso!\n");

}

void exibirSaldo(Conta *conta) {
    printf("\nSaldo = R$%.2f\n", conta->saldo);
}


int main() {
    int opc;
    float valor;
    Conta *conta = malloc(sizeof(Conta));

    srand(time(0)); // Usado para gerar o número aleatório da conta.

    printf("== ABERTURA DE CONTA ==\n");
    printf("Digite o seu nome: ");
    scanf(" %[^\n]s", conta->cliente.nome); //Substituição do scanf("%s", conta->cliente.nome) para permitir entrar com uma string que contém espaços

    printf("Digite o seu CPF: ");
    scanf("%d", &conta->cliente.cpf);

    conta->saldo = 0.0;
    conta->numeroDaConta = rand() % 100;

    printf("\nConta aberta com sucesso.\nNumero da conta = %d.\n", conta->numeroDaConta);

    while (True) {
        printf("\nSelecione uma opcao:\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Exibir Saldo\n");
        printf("4 - Sair\n=> ");
        scanf("%d", &opc);

        if (opc == 1) {
            printf("Digite o valor a ser depositado: R$");
            scanf("%f", &valor);
            depositar(conta, valor);
        }

        if (opc == 2) {
            printf("Digite o valor a ser sacado: R$");
            scanf("%f", &valor);
            sacar(conta, valor);
        }

        if (opc == 3) {
            exibirSaldo(conta);
        }

        if (opc == 4) {
            break;
        }

    }




}

