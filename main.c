#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "sysvendas.h"

FILE *arquivoUsuarios;
FILE *arquivoUsuariosAux;
FILE *arquivoClientes;
FILE *arquivoProdutos;
FILE *arquivoVendas;

int main(void)
{
    setlocale(LC_ALL,"portuguese");
    logo();
    acesso();
    return 0;
}
