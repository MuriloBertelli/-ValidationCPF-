# CPF Validator (C)

Programa em C que valida um CPF (Cadastro de Pessoa Física) usando o algoritmo oficial de dígitos verificadores.

## Como usar

1. Clone o repositório.
2. Rode `make` para compilar.
3. Execute `./bin/cpf_validator` (ou `make run`).

O programa aceita entrada no formato `xxx.xxx.xxx-xx` ou apenas `xxxxxxxxxxx`.

## Lógica do algoritmo (resumo)

1. **Limpeza da entrada**: removemos pontos e traços para trabalhar apenas com os 11 dígitos.
2. **Primeiro dígito verificador**:
   - Multiplicamos os 9 primeiros dígitos pelos pesos 10,9,...,2.
   - Somamos o resultado.
   - Calculamos `resto = soma % 11`.
   - Se `resto < 2` então `digito1 = 0` senão `digito1 = 11 - resto`.
3. **Segundo dígito verificador**:
   - Aplicamos pesos 11,10,...,2 sobre os 9 primeiros dígitos + o `digito1` calculado.
   - Repetimos a mesma regra do resto.
4. **Validação final**: comparamos os dígitos calculados com os dois últimos dígitos informados no CPF.

## Observações

- O programa faz validação básica (verifica se existem 11 dígitos) mas não valida casos especiais como CPFs com todos os dígitos iguais (ex.: `111.111.111-11`) — poderíamos adicionar essa checagem caso queira.
- Complexidade: O algoritmo é linear em relação ao número de dígitos (O(1) prático — quantidade fixa 11).

## Estrutura do projeto

'''brench
.
├── Makefile
├── README.md
├── cpf.c
└── bin/ (gerado pelo Makefile)
'''
