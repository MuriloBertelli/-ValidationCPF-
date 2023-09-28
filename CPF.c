#include <stdio.h>
#include <string.h>

int main()
{
    
    char cpf[15];
    int i, j, soma = 0, resto, digito1, digito2;

    printf("Digite o CPF no formato xxx.xxx.xxx-xx: ");
    scanf("%s", cpf);

    // Removendo os pontos e o traço do CPF
    char cpfNumerico[12];
    int count = 0;
    for (i = 0; i < strlen(cpf); i++)
    {
        if (cpf[i] != '.' && cpf[i] != '-')
        {
            cpfNumerico[count++] = cpf[i];
        }
    }
    cpfNumerico[count] = '\0';

    // Cálculo do 1o dígito
    for (i = 0, j = 10; i < 9; i++, j--)
    {
        soma += (cpfNumerico[i] - '0') * j;
    }
    resto = soma % 11;
    if (resto < 2)
    {
        digito1 = 0;
    }
    else
    {
        digito1 = 11 - resto;
    }

    // Cálculo do 2o dígito
    soma = 0;
    for (i = 0, j = 11; i < 10; i++, j--)
    {
        soma += (i == 9 ? digito1 : (cpfNumerico[i] - '0')) * j;
    }
    resto = soma % 11;
    if (resto < 2)
    {
        digito2 = 0;
    }
    else
    {
        digito2 = 11 - resto;
    }

    // Verificação
    if (digito1 == (cpfNumerico[9] - '0') && digito2 == (cpfNumerico[10] - '0'))
    {
        printf("CPF fornecido é válido.\n");
    }
    else
    {
        printf("CPF fornecido é inválido.\n");
    }

    return 0;
}
