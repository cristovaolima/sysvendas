#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

typedef struct cliente
{
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
    struct cliente* prox;
} Cliente;

typedef struct usuario
{
    char nome[41];
    char senha[11];
    float id;
    struct usuario* prox;

} Usuario;

typedef struct produto
{
    char nome[41];
    char largura[11];
    char comprimento[11];
    char peso[11];
    float estoque;
    struct produto* prox;
} Produto;

typedef struct venda
{
    char clte[41];
    float quantidade;
    float totalvenda;
    char mes[4];
    char dia[3];
    char ano[5];
    char hora[3];
    char min[3];
    char seg[3];
    char item[41];
    struct venda* prox;
} Venda;

int main(void);
void telainicio(char* nomeusuario);
void logo(void);
void menucadastros(void);
void menuconsultas(void);
void menuestoque(void);
void menurelatorios(void);
Cliente* CadastroCliente(Cliente* c, char* nome, char* cidade, char* estado, char* telefone, char* endereco, char* email, char* bairo, char* complemento, char* cnpjcpf, char* cep, char* dia, char* mes, char* ano, char* numero);
Produto* CadastroProduto(Produto* p, char* nome, char* largura, char* comprimento, char* peso, float estoque);
Usuario* CadastroUsuario(Usuario* u, char* nome, char* senha, float id);
Venda* Vendas(Venda* v, char* clte, char* item, float quantidade, float totalvenda, char* mes, char* dia, char* ano, char* hora, char* min, char* seg);
void EstoqueEntrada(void);
void EstoqueSaida(void);
Cliente* CriarListaVaziaCliente(void);
Produto* CriarListaVaziaProduto(void);
Venda* CriarListaVaziaVenda(void);
Usuario* CriarListaVaziaUsuario(void);
void TelaBuscaUsuario(void);
void TelaBuscaCliente(void);
void TelaBuscaProduto(void);
void TelaBuscaUsuario(void);
void TelaRelatorioProdutos(void);
void TelaRelatorioCliente(void);
void TelaRelatorioUsuario(void);
void TelaRelatorioVendas(void);
void ExibirVenda(char* clte, char* item, float quantidade, float totalvenda, char* mes, char* dia, char* ano, char* hora, char* min, char* seg);
void ExibirUsuario(char* nome, char* senha, float id);
void ExibirProduto(char* nome, char* largura, char* comprimento, char* peso, float estoque);
void ExibirCliente(char* nome, char* dia, char* mes, char* ano, char* cnpjcpf, char* cep, char* endereco, char* numero, char* complemento, char* bairo, char* cidade, char* estado, char* telefone, char* email);
FILE* BuscaUsuario(char* b, char* nome, char* senha, float id);
FILE* BuscaProduto(char* b, char* nome, char* largura, char* comprimento, char* peso, float estoque);
FILE* BuscaCliente(char* b, char* nome, char* cidade, char* estado, char* telefone, char* endereco, char* email, char* bairo, char* complemento, char* cnpjcpf, char* cep, char* dia, char* mes, char* ano, char* numero);
void LerArquivoUsuarios(void);
void LerArquivoProdutos(void);
void LerArquivoClientes(void);
void LerArquivoVendas(void);
float IDUsuario(void);
void acesso(void);
int LerArquivoUsuariosAcesso(void);
Usuario* CadastroUsuarioAcesso(Usuario* u, char* nome, char* senha, float id);
