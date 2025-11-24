#include <stdio.h>
#include <string.h>
/*
 * cpf.c
 * Validação de CPF no formato xxx.xxx.xxx-xx ou apenas dígitos.
 *
 * Algoritmo:
 * 1) Remove caracteres não numéricos.
 * 2) Calcula o primeiro dígito verificador usando pesos 10..2.
 * 3) Calcula o segundo dígito verificador usando pesos 11..2.
 * 4) Compara com os dígitos informados.
 *
 * Compilar: make (com o Makefile fornecido)
 */

int main()
{
    // Declaração de variavel
    char cpf[15]; // Armazena o cpf inserido dentro de um array de tamanho 15 
    int i, j, soma = 0, resto, digito1, digito2; // Variaveis para os calculos de loop. 

    printf("Digite o CPF no formato xxx.xxx.xxx-xx: ");
    scanf("%s", cpf);

    // Removendo os pontos e o traço do CPF
    char cpfNumerico[12]; // Amazena o cpf em formato númerico. 
    int count = 0; // contador para o array cpfNumerico
    for (i = 0; i < strlen(cpf); i++)
    {
        if (cpf[i] != '.' && cpf[i] != '-')
        {
            cpfNumerico[count++] = cpf[i]; // Adiciona o Digito para o meu Array 
        }
    }
    cpfNumerico[count] = '\0'; // Adiciona caracter nulo no final da str 

    // Cálculo do 1o dígito
    for (i = 0, j = 10; i < 9; i++, j--) // -----> Exemple 
    {
        soma += (cpfNumerico[i] - '0') * j; // Multiplica o Digito pelo peso e soma
    }
    resto = soma % 11; // calcula o resto da soma por 11 
    if (resto < 2)
    {
        digito1 = 0; // Se o resto for menor que 2 o primeiro digito verificado é 0 
    }
    else
    {
        digito1 = 11 - resto; // Se não é 11 - resto 
    }

    // Cálculo do 2o dígito
    soma = 0; // resetar a variavel soma 
    for (i = 0, j = 11; i < 10; i++, j--) // -----> Exemplo
    {
        soma += (i == 9 ? digito1 : (cpfNumerico[i] - '0')) * j; //Multiplica cada digito pleo seu peso e soma
    }
    resto = soma % 11; // calcula o resto da divisão da soma por 11
    if (resto < 2)
    {
        digito2 = 0; // se o resto da soma for menor que dois o segundo digito verificado é 0 
    }
    else
    {
        digito2 = 11 - resto; // se não 11 menos o resto. 
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
