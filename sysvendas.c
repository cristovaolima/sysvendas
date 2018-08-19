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

char *login = "ADMIN";
char *senhaadm = "admin@01";

void telainicio(char* nomeusuario)
{
    logo();
    Venda* v;
    v = CriarListaVaziaVenda();
    float quantidade = 0.0;
    float totalvenda = 0.0;
    char mes[4];
    char dia[3];
    char ano[5];
    char hora[3];
    char min[3];
    char seg[3];
    char opcao[2];
    char clte[41];
    char item[41];
    printf("\n\n* 1.VENDA - 2.ESTOQUE - 3.CADASTROS - 4.CONSULTAS - 5.RELATÓRIOS - 6.ACESSO *******************************************\nOpção: ");
    scanf(" %[^\n]", opcao); fflush(stdin);
    if(strlen(opcao) > 1)
        {
            printf("\nOpção invalida! Informe novamente!\n\n");
            system("pause");
            telainicio(login);
        }
    else
        switch(*opcao)
        {
          case '1':
            v = Vendas(v, clte, item, quantidade, totalvenda, mes, dia, ano, hora, min, seg);
            break;
          case '2':
            menuestoque();
            break;
          case '3':
            menucadastros();
            break;
          case '4':
            menuconsultas();
            break;
          case '5':
            menurelatorios();
            break;
          case '6':
            login = "ADMIN";
            acesso();
            break;
          default:
            printf("\nOpção invalida! Informe novamente!\n\n");
            system("pause");
            telainicio(login);
        }
}

void logo(void)
{
    char mesmenu[4], diamenu[3], anomenu[5];
    strcpy(mesmenu, "");
    strcpy(diamenu, "");
    strcpy(anomenu, "");
    strncat(mesmenu, __DATE__ , 3);
    strncat(diamenu, __DATE__ +4, 2);
    strncat(anomenu, __DATE__ +7, 4);
    system("cls");
    printf("\n************************************************* | SysVendas | ************************************ %s/%s/%s ", diamenu, mesmenu, anomenu);
    printf("\n Bem vindo(a), %s. ", login);
}

void menucadastros(void)
{
    logo();
    Cliente* c;
    Produto* p;
    Usuario* u;
    c = CriarListaVaziaCliente();
    p = CriarListaVaziaProduto();
    u = CriarListaVaziaUsuario();
    char opcao[2];
    char nome[41];
    char senha[11];
    char cidade[41];
    char estado[3];
    char telefone[31];
    char endereco[41];
    char email[101];
    char bairo[41];
    char complemento[41];
    char cnpjcpf[15];
    char cep[13];
    char dia[3];
    char mes[3];
    char ano[5];
    char numero[16];
    char largura[11];
    char comprimento[11];
    char peso[11];
    float estoque = 0.0;
    float id = 0.0;
    printf("\n\n* CADASTROS -----------------------------------------------------------------------------------------------------------");
    printf("\n\n**** 1.Cliente - 2.Produto - 3.Usuário - 4.Menu ***********************************************************************\nOpção: ");
    scanf(" %[^\n]", opcao); fflush(stdin);
    if(strlen(opcao) > 1)
        {
            printf("\nOpção invalida! Informe novamente!\n\n");
            system("pause");
            menucadastros();
        }
    else
        switch(*opcao)
        {
          case '1':
            c = CadastroCliente(c, nome, cidade, estado, telefone, endereco, email, bairo, complemento, cnpjcpf, cep, dia, mes, ano, numero);
            break;
          case '2':
            p = CadastroProduto(p, nome, largura, comprimento, peso, estoque);
            break;
          case '3':
            u = CadastroUsuario(u, nome, senha, id);
            break;
          case '4':
            telainicio(login);
            break;
          default:
            printf("\nOpção invalida! Informe novamente!\n");
            system("pause");
            menucadastros();
        }
}

void menuconsultas(void)
{
    logo();
    char opcao[2];
    printf("\n\n* CONSULTAS -----------------------------------------------------------------------------------------------------------");
    printf("\n\n**** 1.Cliente - 2.Produto - 3.Usuário - 4.Menu ***********************************************************************\nOpção: ");
    scanf(" %[^\n]", opcao); fflush(stdin);
    if(strlen(opcao) > 1)
        {
            printf("\nOpção invalida! Informe novamente!\n\n");
            system("pause");
            menuconsultas();
        }
    else
        switch(*opcao)
        {
          case '1':
            TelaBuscaCliente();
            break;
          case '2':
            TelaBuscaProduto();
            break;
          case '3':
            TelaBuscaUsuario();
            break;
          case '4':
            telainicio(login);
          default:
            printf("\nOpção invalida! Informe novamente!\n");
            system("pause");
            menucadastros();
        }
}

Cliente* CadastroCliente(Cliente* c, char* nome, char* cidade, char* estado, char* telefone, char* endereco, char* email, char* bairo, char* complemento, char* cnpjcpf, char* cep, char* dia, char* mes, char* ano, char* numero)
{
    logo();
    arquivoClientes = fopen("CadastroClientes.txt","a");

    Cliente* NovoCliente = (Cliente*)malloc(sizeof(Cliente));
    printf("\n\n* CADASTROS/Cliente ---------------------------------------------------------------------------------------------------\n");

    printf("\nNome completo: ");
    scanf(" %40[^\n]", nome); fflush(stdin);
    strcpy(NovoCliente -> nome, nome);

    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf(" %2[^\n]/%2[^\n]/%4[^\n]", dia, mes, ano); fflush(stdin);
    strcpy(NovoCliente -> dia, dia); strcpy(NovoCliente -> mes, mes); strcpy(NovoCliente -> ano, ano);

    printf("CNPJ/CPF: ");
    scanf(" %14[^\n]", cnpjcpf); fflush(stdin);
    strcpy(NovoCliente -> cnpjcpf, cnpjcpf);

    printf("--Endereço-------\n");
    printf("CEP: ");
    scanf(" %12[^\n]", cep); fflush(stdin);
    strcpy(NovoCliente -> cep, cep);

    printf("Endereço(Rua): ");
    scanf(" %40[^\n]", endereco); fflush(stdin);
    strcpy(NovoCliente -> endereco, endereco);

    printf("Número: ");
    scanf(" %15[^\n]", numero); fflush(stdin);
    strcpy(NovoCliente -> numero, numero);

    printf("Complemento: ");
    scanf(" %40[^\n]", complemento); fflush(stdin);
    strcpy(NovoCliente -> complemento, complemento);

    printf("Bairo: ");
    scanf(" %40[^\n]", bairo); fflush(stdin);
    strcpy(NovoCliente -> bairo, bairo);

    printf("Cidade: ");
    scanf(" %40[^\n]", cidade); fflush(stdin);
    strcpy(NovoCliente -> cidade, cidade);

    printf("Estado (sigla): ");
    scanf(" %2[^\n]", estado); fflush(stdin);
    strupr(estado);
    strcpy(NovoCliente -> estado, estado);

    printf("Telefone: ");
    scanf(" %30[^\n]", telefone); fflush(stdin);
    strcpy(NovoCliente -> telefone, telefone);

    printf("E-mail: ");
    scanf(" %100[^\n]", email); fflush(stdin);
    strcpy(NovoCliente -> email, email);

    fprintf(arquivoClientes, "%s|%s/%s/%s|%s|%s|%s|%s|%s|%s|%s/%s|%s|%s\n", NovoCliente -> nome, NovoCliente -> dia, NovoCliente -> mes, NovoCliente -> ano, NovoCliente -> cnpjcpf, NovoCliente -> cep, NovoCliente -> endereco, NovoCliente -> numero, NovoCliente -> complemento, NovoCliente -> bairo, NovoCliente -> cidade, NovoCliente -> estado, NovoCliente -> telefone, NovoCliente -> email);

    printf("\n\t\t\t-----------------------\n");
    printf("\t\t\t| Cadastro realizado! |\n");
    printf("\t\t\t-----------------------\n\n");

    NovoCliente -> prox = c;
    fclose(arquivoClientes);

    system("pause");
    telainicio(login);

    free(NovoCliente);
    return NovoCliente;
}

Usuario* CadastroUsuario(Usuario* u, char* nome, char* senha, float id)
{
    logo();
    arquivoUsuarios = fopen("CadastroUsuarios.txt","a");

    Usuario* NovoUsuario = (Usuario*)malloc(sizeof(Usuario));
    printf("\n\n* CADASTROS/Usuário ---------------------------------------------------------------------------------------------------\n");

    printf("\nNome do usuário: ");
    scanf(" %40[^\n]", nome); fflush(stdin);
    strcpy(NovoUsuario -> nome, nome);

    printf("\n(Até 10 caracteres, entre letras, número e caracteres especiais.)\nSenha: ");
    scanf(" %40[^\n]", senha); fflush(stdin);
    strcpy(NovoUsuario -> senha, senha);

    NovoUsuario -> id = id;
    fprintf(arquivoUsuarios, "%s|%s|%1.f\n", NovoUsuario -> nome, NovoUsuario -> senha, NovoUsuario -> id = id);

    printf("\n\t\t\t-----------------------\n");
    printf("\t\t\t| Cadastro realizado! |\n");
    printf("\t\t\t-----------------------\n\n");

    NovoUsuario -> prox = u;
    fclose(arquivoUsuarios);

    system("pause");
    telainicio(login);

    free(NovoUsuario);
    return NovoUsuario;
}

Usuario* CadastroUsuarioAcesso(Usuario* u, char* nome, char* senha, float id)
{
    logo();
    arquivoUsuarios = fopen("CadastroUsuarios.txt","a");

    Usuario *NovoUsuario;
    NovoUsuario = (Usuario*)malloc(sizeof(Usuario));
    printf("\n\n* CADASTROS/Usuário ---------------------------------------------------------------------------------------------------\n");

    printf("\nNome do usuário: ");
    scanf(" %40[^\n]", nome); fflush(stdin);
    strcpy(NovoUsuario -> nome, nome);

    printf("\n(Até 10 caracteres, entre letras, número e caracteres especiais.)\nSenha: ");
    scanf(" %40[^\n]", senha); fflush(stdin);
    strcpy(NovoUsuario -> senha, senha);

    NovoUsuario -> id = id;
    fprintf(arquivoUsuarios, "%s|%s|%1.f\n", NovoUsuario -> nome, NovoUsuario -> senha, NovoUsuario -> id = id);

    printf("\n\t\t\t-----------------------\n");
    printf("\t\t\t| Cadastro realizado! |\n");
    printf("\t\t\t-----------------------\n\n");

    NovoUsuario -> prox = u;
    fclose(arquivoUsuarios);

    system("pause");
    acesso();

    free(NovoUsuario);
    return NovoUsuario;
}

Produto* CadastroProduto(Produto* p, char* nome, char* largura, char* comprimento, char* peso, float estoque)
{
    logo();
    arquivoProdutos = fopen("CadastroProdutos.txt","a");

    Produto* NovoProduto = (Produto*)malloc(sizeof(Produto));
    printf("\n\n* CADASTROS/Produto----------------------------------------------------------------------------------------------------\n");

    printf("\nNome do produto: ");
    scanf(" %40[^\n]", nome); fflush(stdin);
    strcpy(NovoProduto -> nome, nome);

    printf("--- Ficha tecnica ---\n");
    printf("Largura: ");
    scanf(" %11[^\n]", largura); fflush(stdin);
    strcpy(NovoProduto -> largura, largura);

    printf("Comprimento: ");
    scanf(" %11[^\n]", comprimento); fflush(stdin);
    strcpy(NovoProduto -> comprimento, comprimento);

    printf("Peso: ");
    scanf(" %11[^\n]", peso); fflush(stdin);
    strcpy(NovoProduto -> peso, peso);

    printf("Estoque: ");
    scanf("%f", &estoque);
    NovoProduto -> estoque = estoque;

    fprintf(arquivoProdutos, "%s|%s|%s|%s|%1.f\n", NovoProduto -> nome, NovoProduto -> largura, NovoProduto -> comprimento, NovoProduto -> peso, NovoProduto -> estoque);

    printf("\n\t\t\t-----------------------\n");
    printf("\t\t\t| Cadastro realizado! |\n");
    printf("\t\t\t-----------------------\n\n");

    NovoProduto -> prox = p;
    fclose(arquivoProdutos);

    system("pause");
    telainicio(login);

    free(NovoProduto);
    return NovoProduto;
}

Venda* Vendas(Venda* v, char* clte, char* item, float quantidade, float totalvenda, char* mes, char* dia, char* ano, char* hora, char* min, char* seg)
{
    logo();
    char nomebusca[41];
    char opcao[2];
    char nome[41];
    char cidade[41];
    char estado[3];
    char telefone[31];
    char endereco[41];
    char email[101];
    char bairo[41];
    char complemento[41];
    char cnpjcpf[15];
    char cep[13];
    char numero[16];
    char largura[11];
    char comprimento[11];
    char peso[11];
    float estoque = 0.0;

    arquivoVendas = fopen("Vendas.txt","a");

    Venda* NovaVenda = (Venda*)malloc(sizeof(Venda));
    float dd, mm, aaaa, hh, mi, ss;
    struct tm *local;
    time_t t;
    t = time(NULL);
    local = localtime(&t);

    printf("\n\n* VENDA ---------------------------------------------------------------------------------------------------------------\n");
    LerArquivoClientes();
    LerArquivoProdutos();
    printf("\n(Informe o nome com acentos)\nInforme o nome completo do cliente: ");
    scanf(" %40[^\n]", nomebusca); fflush(stdin);
    BuscaCliente(nomebusca, nome, dia, mes, ano, cnpjcpf, cep, endereco, numero, complemento, bairo, cidade, estado, telefone, email);
    if((BuscaCliente(nomebusca, nome, dia, mes, ano, cnpjcpf, cep, endereco, numero, complemento, bairo, cidade, estado, telefone, email)) != NULL)
    {
        ExibirCliente(nome, dia, mes, ano, cnpjcpf, cep, endereco, numero, complemento, bairo, cidade, estado, telefone, email);
        strcpy(NovaVenda -> clte, nome);
        fprintf(arquivoVendas, "%s|", NovaVenda -> clte);
    }
    else
    {
        printf("\n Cliente não encontrado!\n\n");
        system("pause");
        telainicio(login);
    }

    while(1)
    {
        printf("\nInforme o nome do produto: ");
        scanf(" %40[^\n]", nomebusca); fflush(stdin);
        if((BuscaProduto(nomebusca, nome, largura, comprimento, peso, estoque)) != NULL)
        {
            ExibirProduto(nome, largura, comprimento, peso, estoque);
            strcpy(NovaVenda -> item, nome);
            fprintf(arquivoVendas, "%s|",NovaVenda -> item);
        }
        else
        {
            printf("\n Produto não encontrado!\n\n");
            system("pause");
            continue;
        }

        printf("Quantidade: ");
        scanf("%f.2", &quantidade);
        NovaVenda -> quantidade = quantidade;
        fprintf(arquivoVendas, "%.2f#",NovaVenda -> quantidade);

            printf("\n\n*Finalizar venda? \n1.SIM - 2.NÃO - 3.CANCELAR VENDA\nOpção: ");
            scanf(" %[^\n]", opcao); fflush(stdin);
            if(strlen(opcao) > 1)
            {
                printf("\nOpção invalida! Informe novamente!\n\n");
                system("pause");
                system("cls");
            }
            else
                switch(*opcao)
                {
                    case '1':
                        printf("Total da venda: ");
                        scanf("%f.2", &totalvenda);
                        NovaVenda -> totalvenda = totalvenda;
                        fprintf(arquivoVendas, "%.2f|", NovaVenda -> totalvenda);

                        dd = local -> tm_mday;
                        sprintf(dia, "%.f",dd);
                        strcpy(NovaVenda -> dia, dia);

                        mm = local -> tm_mon + 1;
                        sprintf(mes, "%.f",mm);
                        strcpy(NovaVenda -> mes, mes);

                        aaaa = local -> tm_year + 1900;
                        sprintf(ano, "%.f",aaaa);
                        strcpy(NovaVenda -> ano, ano);

                        hh = local -> tm_hour;
                        sprintf(hora, "%.f",hh);
                        strcpy(NovaVenda -> hora, hora);

                        mi = local -> tm_min;
                        sprintf(min, "%.f",mi);
                        strcpy(NovaVenda -> min, min);

                        ss = local -> tm_sec;
                        sprintf(seg, "%1.f",ss);
                        strcpy(NovaVenda -> seg, seg);
                        fprintf(arquivoVendas, "%s/%s/%s|%s:%s:%s\n",NovaVenda -> dia, NovaVenda -> mes, NovaVenda -> ano, NovaVenda -> hora, NovaVenda -> min, NovaVenda -> seg);
                        //fprintf(arquivoVendas, "%s|%s|%.2f|%.2f|%s/%s/%s|%s:%s:%s\n", NovaVenda -> clte, NovaVenda -> item, NovaVenda -> quantidade, NovaVenda -> totalvenda, NovaVenda -> dia, NovaVenda -> mes, NovaVenda -> ano, NovaVenda -> hora, NovaVenda -> min, NovaVenda -> seg);
                        //printf("%s:%s:%s - %s/%s/%s\n", hora, min, seg, dia, mes, ano);
                        printf("\n\t\t------------------------\n");
                        printf("\t\t|   Venda realizada!   |\n");
                        printf("\t\t------------------------\n\n");
                        NovaVenda -> prox = v;
                        fclose(arquivoVendas);
                        system("pause");
                        telainicio(login);
                        break;
                    case '2':
                        continue;
                        break;
                    case '3':
                        telainicio(login);
                        break;
                    default:
                        printf("\nOpção invalida! Informe novamente!\n\n");
                        system("pause");
                        break;
                }
    }

    NovaVenda -> prox = v;
    fclose(arquivoVendas);
    system("pause");
    telainicio(login);

    free(NovaVenda);
    return NovaVenda;
}

void menuestoque(void)
{
    logo();
    char opcao[2];

    printf("\n\n* ESTOQUE -------------------------------------------------------------------------------------------------------------");
    printf("\n\n**** 1.Entrada - 2.Saida - 3.Menu *************************************************************************************\nOpção: ");
    scanf(" %[^\n]", opcao); fflush(stdin);
    if(strlen(opcao) > 1)
        {
            printf("\nOpção invalida! Informe novamente!\n\n");
            system("pause");
            menuestoque();
        }
    else
        switch(*opcao)
        {
          case '1':
            EstoqueEntrada();
            break;
          case '2':
            EstoqueSaida();
            break;
          case '3':
            telainicio(login);
            break;
          default:
            printf("\nOpção invalida! Informe novamente!\n");
            system("pause");
            menuestoque();
        }
}

void EstoqueEntrada(void)
{
    logo();
    printf("\n\n* ESTOQUE/Entrada------------------------------------------------------------------------------------------------------\n");
    system("pause");
    telainicio(login);
}

void EstoqueSaida(void)
{
    logo();
    printf("\n\n* ESTOQUE/Saida--------------------------------------------------------------------------------------------------------\n");
    system("pause");
    telainicio(login);
}

Cliente* CriarListaVaziaCliente(void)
{
    return NULL;
}

Produto* CriarListaVaziaProduto(void)
{
    return NULL;
}

Venda* CriarListaVaziaVenda(void)
{
    return NULL;
}

Usuario* CriarListaVaziaUsuario(void)
{
    return NULL;
}

FILE* BuscaUsuario(char* b, char* nome, char* senha, float id)
{
    arquivoUsuarios = fopen("CadastroUsuarios.txt","r");
    while((fscanf(arquivoUsuarios, "%[^|]|%[^|]|%f\n", nome, senha, &id)) != EOF)
        if(stricmp(nome, b) == 0)
        {
            fclose(arquivoUsuarios);
            return arquivoUsuarios;
        }
    fclose(arquivoUsuarios);
    return NULL;
}

FILE* BuscaCliente(char* b, char* nome, char* dia, char* mes, char* ano, char* cnpjcpf, char* cep, char* endereco, char* numero, char* complemento, char* bairo, char* cidade, char* estado, char* telefone, char* email)
{
    arquivoClientes = fopen("CadastroClientes.txt","r");
    while((fscanf(arquivoClientes, "%[^|]|%[^/]/%[^/]/%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^/]/%[^|]|%[^|]|%[^\n]\n", nome, dia, mes, ano, cnpjcpf, cep, endereco, numero, complemento, bairo, cidade, estado, telefone, email)) != EOF)
        if(stricmp(nome, b) == 0)
        {
            fclose(arquivoClientes);
            return arquivoClientes;
        }
    fclose(arquivoClientes);
    return NULL;
}

FILE* BuscaProduto(char* b, char* nome, char* largura, char* comprimento, char* peso, float estoque)
{
    arquivoUsuarios = fopen("CadastroProdutos.txt","r");
    while((fscanf(arquivoProdutos, "%[^|]|%[^|]|%[^|]|%[^|]|%f\n", nome, largura, comprimento, peso, &estoque)) != EOF )
        if(stricmp(nome, b) == 0)
        {
            fclose(arquivoProdutos);
            return arquivoProdutos;
        }
    fclose(arquivoProdutos);
    return NULL;
}

void TelaBuscaUsuario(void)
{
    logo();
    char nomebusca[41];
    char nome[41];
    char senha[11];
    float id = 0.0;
    printf("\n\n* CONSULTAS/Usuário ---------------------------------------------------------------------------------------------------");
    LerArquivoUsuarios();
    printf("\n\nInforme o nome do usuário: ");
    scanf(" %40[^\n]", nomebusca); fflush(stdin);
    if((BuscaUsuario(nomebusca, nome, senha, id)) != NULL)
        ExibirUsuario(nome, senha, id);
    else
        printf("\n Usuário não encontrado!\n\n");

    printf("\n-----------------------------------------------------------------------------------------------------------------------\n\n");
    system("pause");
    telainicio(login);
}

void TelaBuscaCliente(void)
{
    logo();
    char nomebusca[41];
    char nome[41];
    char cidade[41];
    char estado[3];
    char telefone[31];
    char endereco[41];
    char email[101];
    char bairo[41];
    char complemento[41];
    char cnpjcpf[15];
    char cep[13];
    char dia[3];
    char mes[3];
    char ano[5];
    char numero[16];
    printf("\n\n* CONSULTAS/Cliente ----------------------------------------------------------------------------------------------------");
    LerArquivoClientes();
    printf("\n\n(Informe o nome com acentos)\nInforme o nome completo do cliente: ");
    scanf(" %40[^\n]", nomebusca); fflush(stdin);
    if((BuscaCliente(nomebusca, nome, dia, mes, ano, cnpjcpf, cep, endereco, numero, complemento, bairo, cidade, estado, telefone, email)) != NULL)
        ExibirCliente(nome, dia, mes, ano, cnpjcpf, cep, endereco, numero, complemento, bairo, cidade, estado, telefone, email);
    else
        printf("\n Cliente não encontrado!\n\n");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n\n");
    system("pause");
    telainicio(login);
}

void TelaBuscaProduto(void)
{
    logo();
    char nomebusca[41];
    char nome[41];
    char largura[11];
    char comprimento[11];
    char peso[11];
    float estoque = 0.0;
    printf("\n\n* CONSULTAS/Produto ---------------------------------------------------------------------------------------------------\n");
    LerArquivoProdutos();
    printf("\nInforme o nome do produto: ");
    scanf(" %40[^\n]", nomebusca); fflush(stdin);
    if((BuscaProduto(nomebusca, nome, largura, comprimento, peso, estoque)) != NULL)
        ExibirProduto(nome, largura, comprimento, peso, estoque);
    else
        printf("\n Produto não encontrado!\n\n");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n\n");
    system("pause");
    telainicio(login);
}

void menurelatorios(void)
{
    logo();
    char opcao[2];
    printf("\n\n* RELATÓRIOS ----------------------------------------------------------------------------------------------------------");
    printf("\n\n**** 1.Vendas - 2.Clientes - 3.Produtos - 4.Usuários - 5.Menu *********************************************************\nOpção: ");
    scanf(" %[^\n]", opcao); fflush(stdin);
    if(strlen(opcao) > 1)
        {
            printf("\nOpção invalida! Informe novamente!\n\n");
            system("pause");
            menurelatorios();
        }
    else
        switch(*opcao)
        {
          case '1':
            TelaRelatorioVendas();
            break;
          case '2':
            TelaRelatorioCliente();
            break;
          case '3':
            TelaRelatorioProdutos();
            break;
          case '4':
            TelaRelatorioUsuario();
            break;
          case '5':
            telainicio(login);
          default:
            printf("\nOpção invalida! Informe novamente!\n");
            system("pause");
            menucadastros();
        }
}

void ExibirUsuario(char* nome, char* senha, float id)
{
    printf("\nNome: %s \nSenha: %s \nID: %1.f\n", nome, senha, id);
    printf("***********************************************************************************************************************\n");
}

void ExibirVenda(char* clte, char* item, float quantidade, float totalvenda, char* dia, char* mes, char* ano, char* hora, char* min, char* seg)
{
    printf("\n\nCliente: %s\n - Produto: %s\n - Quantidade: %1.f\n - Total da venda: %1.f\n %s/%s/%s - %s:%s:%s\n", clte, item, quantidade, totalvenda, dia, mes, ano, hora, min, seg);
    printf("***********************************************************************************************************************\n");
}

void ExibirProduto(char* nome, char* largura, char* comprimento, char* peso, float estoque)
{
    printf("\nNome: %s \n--- Ficha tecnica ---\nLargura: %s --- Comprimento: %s --- Peso: %s \nEstoque: %1.f\n", nome, largura, comprimento, peso, estoque);
    printf("***********************************************************************************************************************\n");
}

void ExibirCliente(char* nome, char* dia, char* mes, char* ano, char* cnpjcpf, char* cep, char* endereco, char* numero, char* complemento, char* bairo, char* cidade, char* estado, char* telefone, char* email)
{
    printf("\nNome completo: %s --- Data de nascimento: %s/%s/%s --- CNPJ/CPF: %s\n", nome, dia, mes, ano, cnpjcpf);
    printf("--Endereço-------\n");
    printf("CEP: %s --- Endereço(Rua): %s --- Número: %s --- Complemento: %s\n", cep, endereco, numero, complemento);
    printf("Bairo: %s --- Cidade: %s/%s\n", bairo, cidade, estado);
    printf("--Contatos-------\n");
    printf("Telefone: %s --- E-mail: %s\n", telefone, email);
    printf("***********************************************************************************************************************\n");
}

void TelaRelatorioUsuario(void)
{
    logo();
    char nome[41];
    char senha[11];
    float id = 0.0;
    printf("\n\n* RELATÓRIOS/Usuários -------------------------------------------------------------------------------------------------");
    LerArquivoUsuarios();
    arquivoUsuarios = fopen("CadastroUsuarios.txt","r");
    printf("\n\n*** Usuários cadastrados:\n");
    while((fscanf(arquivoUsuarios, "%[^|]|%[^|]|%f\n", nome, senha, &id)) != EOF)
        ExibirUsuario(nome, senha, id);
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n\n");
    system("pause");
    telainicio(login);
}

void TelaRelatorioVendas(void)
{
    logo();
    char clte[41];
    float quantidade = 0.0;
    float totalvenda = 0.0;
    char mes[4];
    char dia[3];
    char ano[5];
    char hora[3];
    char min[3];
    char seg[3];
    char item[41];
    printf("\n\n* RELATÓRIOS/Vendas ---------------------------------------------------------------------------------------------------");
    LerArquivoVendas();
    arquivoVendas = fopen("Vendas.txt","r");
    while((fscanf(arquivoVendas, "%[^|]|%[^|]|%f[^#]#%f[^|]|%[^/]/%[/]/%s[^|]|%[^:]:%[^:]:%[^\n]\n", clte, item, &quantidade, &totalvenda, dia, mes, ano, hora, min, seg)) != EOF)
        ExibirVenda(clte, item, quantidade, totalvenda, dia, mes, ano, hora, min, seg);

    printf("\n-----------------------------------------------------------------------------------------------------------------------\n\n");
    system("pause");
    telainicio(login);
}

void TelaRelatorioProdutos(void)
{
    logo();
    char nome[41];
    char largura[11];
    char comprimento[11];
    char peso[11];
    float estoque;
    printf("\n\n* RELATÓRIOS/Produtos -------------------------------------------------------------------------------------------------");
    LerArquivoProdutos();
    arquivoProdutos = fopen("CadastroProdutos.txt","r");
    printf("\n\n*** Produtos cadastrados:\n");
    while((fscanf(arquivoProdutos, "%[^|]|%[^|]|%[^|]|%[^|]|%f\n", nome, largura, comprimento, peso, &estoque)) != EOF )
        ExibirProduto(nome, largura, comprimento, peso, estoque);
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n\n");
    system("pause");
    telainicio(login);
}

void TelaRelatorioCliente(void)
{
    logo();
    char nome[41];
    char cidade[41];
    char estado[3];
    char telefone[31];
    char endereco[41];
    char email[101];
    char bairo[41];
    char complemento[41];
    char cnpjcpf[15];
    char cep[13];
    char dia[3];
    char mes[3];
    char ano[5];
    char numero[16];
    printf("\n\n* RELATÓRIOS/Clientes -------------------------------------------------------------------------------------------------");
    LerArquivoClientes();
    arquivoClientes = fopen("CadastroClientes.txt","r");
    printf("\n\n*** Clientes cadastrados:\n");
    while((fscanf(arquivoClientes, "%[^|]|%[^/]/%[^/]/%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^/]/%[^|]|%[^|]|%[^\n]\n", nome, dia, mes, ano, cnpjcpf, cep, endereco, numero, complemento, bairo, cidade, estado, telefone, email)) != EOF)
        ExibirCliente(nome, dia, mes, ano, cnpjcpf, cep, endereco, numero, complemento, bairo, cidade, estado, telefone, email);
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n\n");
    system("pause");
    telainicio(login);
}

void LerArquivoUsuarios(void)
{
    arquivoUsuarios = fopen("CadastroUsuarios.txt","r");
    if (arquivoUsuarios == NULL)
    {
        printf("\n\n Erro ao abrir o arquivo de usuários!\n\n");
        system("pause");
        telainicio(login);
    }
}

int LerArquivoUsuariosAcesso(void)
{
    Usuario* u;
    u = CriarListaVaziaUsuario();
    char nome[41];
    char senha[11];
    float id = 0.0;
    arquivoUsuarios = fopen("CadastroUsuarios.txt","r");
    if (arquivoUsuarios == NULL)
    {
        printf("\n\n\n\n\t\t\t\t\t\t Sistema sem usuários!\n\n");
        system("pause");
        u = CadastroUsuarioAcesso(u, nome, senha, id);
    }
    fclose(arquivoUsuarios);
    return 1;
}

void LerArquivoProdutos(void)
{
    arquivoProdutos = fopen("CadastroProdutos.txt","r");
    if (arquivoProdutos == NULL)
    {
        printf("\n\n Erro ao abrir o arquivo de produtos!\n\n");
        system("pause");
        telainicio(login);
    }
}

void LerArquivoClientes(void)
{
    arquivoClientes = fopen("CadastroClientes.txt","r");
    if (arquivoClientes == NULL)
    {
        printf("\n\n Erro ao abrir o arquivo de clientes!\n\n");
        system("pause");
        telainicio(login);
    }
}

void LerArquivoVendas(void)
{
    arquivoVendas = fopen("Vendas.txt","r");
    if (arquivoVendas == NULL)
    {
        printf("\n\n Erro ao abrir o arquivo de vendas!\n\n");
        system("pause");
        telainicio(login);
    }
}

float IDUsuario(void)
{
    char nome[41];
    char senha[11];
    float id;
    float novoidusuario = 0.0;
    arquivoUsuarios = fopen("CadastroUsuarios.txt","r");
    while((fscanf(arquivoUsuarios, "%[^|]|%[^|]|%f\n", nome, senha, &id)) != EOF)
    {
        novoidusuario = id;
    }
    novoidusuario += 1;
    fclose(arquivoUsuarios);
    return novoidusuario;
}

void acesso(void)
{
    char s[11];
    char nome[41];
    char senha[11];
    float id;
    logo();
    LerArquivoUsuariosAcesso();
    printf("\n\n*ACESSO ---------------------------------------------------------------------------------------------------------------");
    if(LerArquivoUsuariosAcesso() == 1)
    {
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\tDigite sua senha: ");
        scanf(" %10[^\n]", s);
        arquivoUsuarios = fopen("CadastroUsuarios.txt","r");
        while((fscanf(arquivoUsuarios, "%[^|]|%[^|]|%f\n", nome, senha, &id)) != EOF)
        if(stricmp(senha, s) == 0 || stricmp(senhaadm, s) == 0)
        {
            if(stricmp(senhaadm, s) == 0)
                login = "ADM Sistema";
            else
                login = nome;
            telainicio(login);
        }
        else if((feof(arquivoUsuarios)) && (stricmp(senha, s) != 0))
        {
            printf("\n !! Senha incorreta! Informe novamente a senha.\n\n");
            system("pause");
            acesso();
        }
    }
}
