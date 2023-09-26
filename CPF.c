#include <stdio.h>
#include <stdbool.h>

bool validaCPF(long long cpf);

int main() {
    long long cpf;

    printf("Digite o seu CPF (sem pontos ou hifens): ");
    scanf("%lld", &cpf);

    if (validaCPF(cpf)) {
        printf("CPF fornecido é válido.\n");
    } else {
        printf("CPF fornecido é inválido.\n");
    }

    return 0;
}

bool validaCPF(long long cpf) {
    int i, j, digito, resto;
    long long soma, temp, fator;

    // Calcula o primeiro dígito verificador
    temp = cpf / 100;
    soma = 0;
    fator = 10;
    for (i = 0; i < 9; i++) {
        digito = temp % 10;
        soma += digito * fator;
        fator--;
        temp /= 10;
    }
    resto = soma % 11;
    if (resto < 2) {
        if ((cpf % 100) / 10 != 0) {
            return false;
        }
    } else {
        if ((cpf % 100) / 10 != (11 - resto)) {
            return false;
        }
    }

    // Calcula o segundo dígito verificador
    temp = cpf / 10;
    soma = 0;
    fator = 11;
    for (j = 0; j < 10; j++) {
        digito = temp % 10;
        soma += digito * fator;
        fator--;
        temp /= 10;
    }
    resto = soma % 11;
    if (resto < 2) {
        if (cpf % 10 != 0) {
            return false;
        }
    } else {
        if (cpf % 10 != (11 - resto)) {
            return false;
        }
    }

    return true;
}
