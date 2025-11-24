# Makefile para o projeto CPF validator
# Autor: você
# Targets: all (build), debug, release, run, clean

# Compiler and flags
CC := gcc
SRC := cpf.c
BIN := bin/cpf_validator

CFLAGS := -Wall -Wextra -Wpedantic -std=c11
DBGFLAGS := -g -O0
RELEASEFLAGS := -O2

.PHONY: all debug release run clean dirs

all: dirs $(BIN)

debug: CFLAGS += $(DBGFLAGS)
debug: dirs $(BIN)

release: CFLAGS += $(RELEASEFLAGS)
release: dirs $(BIN)

dirs:
	@mkdir -p bin

$(BIN): $(SRC)
	@echo "Compilando $< -> $@"
	$(CC) $(CFLAGS) $< -o $@

run: all
	@echo "Executando $(BIN)"
	$(BIN)

clean:
	@echo "Removendo binários..."
	@rm -rf bin

