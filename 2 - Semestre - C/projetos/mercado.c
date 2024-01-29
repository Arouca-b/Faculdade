#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//STRUCTS
struct PRODUTO{
    int cod;
    char desc[100];
    float preco;
}produtos[100];

struct CLIENTE{
    int cod;
    char nome[50];
    int compras[100];
    int quant_c;
} clientes[100];

//ESCOLHA DE OPÇÃO
int validacao(int);
int escolhe_opcao();
int confirmar(char nome[]);
//PESQUISA
int procurar_produto(int cod, int quant_produto);
int procurar_cliente(int cod, int quant_cliente);
void erro();
//MENUS
void menu_cliente(int *quant_clientes);
void menu_produto(int *quant_produtos);
void menu_inicial();

//INSERÇÃO DE DADOS
void inserir_cliente(int posicao);
void inserir_produto(int posicao);
void alterar_produto(int quant_produto);
void alterar_cliente(int quant_cliente);
void excluir(int tipo, int *quant);
int recebe_codigo(int tipo, int quant);

//TELA PRODUTOS E CLIENTES
void imprimir_produtos(int cod);
void limpar_carrinho(int id_cliente ,int *quant_compras);
void carrinho(int quant_c, int quant_p);
void venda(int id_cliente);
float preco(int cod);
void fim();
void sucess();


//CÓDIGO
int main(){
    int escolha = 0, quant_produtos = 0, quant_clientes = 0;
    for (;;){
        menu_inicial();
        escolha = escolhe_opcao();
        switch (escolha){
        case 1:
            menu_cliente(&quant_clientes);

            break;
        
        case 2: 
            menu_produto(&quant_produtos);
            break;
        
        case 3:
            if (validacao(quant_clientes) && validacao(quant_produtos)){
                carrinho(quant_clientes, quant_produtos); 
            }
            break;
        case 4:
            fim();
            break;
        }   
    }
}

//ESCOLHA DE OPÇÃO
int validacao(int quant){
    if (quant==0){
        system("clear||cls");
        printf("\n\n\t\t\t\tAlimente o Banco de dados!!\n\n");
        sleep(2);
        system("clear||cls");
        return 0;
    }
    return 1;
}

int escolhe_opcao(){
    char t[20];
    int opcao = 0;
    scanf("%19[^\n]%*c", t);
    opcao = atoi(t);
    while (opcao > 4 || opcao < 1){
        printf("\n\nOPÇÃO INVÁLIDA\n\nOpcao: ");
        scanf("%19[^\n]%*c", t);
        opcao = atoi(t);
    }
    return opcao;
}

//PROCURAR
int procurar_produto(int cod, int quant_produto){
    int i;
    
    for(i = 0; i < quant_produto; i++){
        if (produtos[i].cod == cod){
            break;
        }
    }
    if(produtos[i].cod == cod){
        return i;
    }
    erro();
    return -2;
    
}

int procurar_cliente(int cod, int quant_cliente){
    int i;
    for(i = 0; i < quant_cliente; i++){
        if (clientes[i].cod == cod){
            return i;
        }
    }
    erro();
    return -2;
}


//MENUS
void menu_cliente(int *quant_clientes){
    int escolha, indice = *quant_clientes;
    system("clear||cls");
    printf("\t\t\t\tMENU CLIENTE\n\n");
    printf("\n1. Incluir Cliente\n");
    printf("2. Excluir Cliente\n");
    printf("3. Alterar Cliente\n");
    printf("4. Retornar\n\n");
    printf("Digite sua opção: ");
    escolha = escolhe_opcao();
    switch(escolha){
        case 1:
            inserir_cliente(indice);
            (*quant_clientes)++;
            break;
        
        case 2:
            if (validacao(indice)){
                excluir(1, quant_clientes);
                sucess();
            }
            break;

        case 3:
            if (validacao(indice)){
                alterar_cliente(indice);
            }
            break;
    }
    system("clear||cls");
}

void menu_produto(int *quant_produtos){
    int escolha, indice = *quant_produtos;
    system("clear||cls");
    printf("\t\t\t\tMENU PRODUTOS\n\n");
    printf("\n1. Incluir Produto\n");
    printf("2. Excluir Produto\n");
    printf("3. Alterar Produto\n");
    printf("4. Retornar\n\n");
    printf("Digite sua opção: ");
    escolha = escolhe_opcao();
    switch(escolha){
        case 1:
            inserir_produto(indice);
            (*quant_produtos)++;
            break;
        
        case 2:
            if (validacao(2) == 1){
                excluir(2, quant_produtos);
            }
            break;
        case 3:
            if (validacao(2) == 1){
                alterar_produto(indice);   
            }
            break;
        }

    system("clear||cls");
}

void menu_inicial(){
    printf("\t\t\t\tMENU PRINCIPAL\n\n");
    printf("\n1. Cadastro de Clientes\n");
    printf("2. Cadastro de Produtos\n");
    printf("3. Venda\n");
    printf("4. Sair do Sistema\n\n");
    printf("Digite sua opção: ");
}

//INSERÇÃO DE DADOS E ALTERAÇÃO DE DADOS
void inserir_cliente(int posicao){
    char s[40];
    system("clear||cls");
    printf("\t\t\t\tCADASTRO CLIENTE\n");
    printf("\n\n\t\tCód cliente: ");
    scanf("%39[^\n]%*c", s);
    clientes[posicao].cod = atoi(s);
    printf("\t\tNome cliente: ");
    scanf("%199[^\n]%*c", clientes[posicao].nome);
}

void inserir_produto(int posicao){
    char s[80];
    system("clear||cls");
    printf("\t\t\t\tCADASTRO PRODUTO\n");
    printf("\n\n\t\tCód Produto: ");
    scanf("%79[^\n]%*c", s);
    produtos[posicao].cod = atoi(s);
    printf("\t\tDesc Produto: ");
    scanf("%199[^\n]%*c", produtos[posicao].desc);
    printf("\t\tPreço: R$ ");
    scanf("%f%*c", &produtos[posicao].preco);
}

void alterar_produto(int quant_produto){
    int cod, conf, local;
    local = recebe_codigo(2, quant_produto);
    if(local >= 0){
        conf = confirmar(produtos[local].desc);
        if (conf){
            inserir_produto(local);
            sucess();
        }        
    }else{
        erro();
    }
    
}

void alterar_cliente(int quant_cliente){
    int local;
    char s[50];
    int conf;
    printf("\n\n");
    local = recebe_codigo(1, quant_cliente);
    if(local>=0){
        printf("Nome para alteração: ");
        scanf("%49[^\n]%*c", s);
        conf = confirmar(clientes[local].nome);
        if(conf){
            strcpy(clientes[local].nome, s);
            sucess();
        }
    }else{
        erro();
    }
}

int confirmar(char nome[]){
    char op;
    printf("Confirmar <s/n>: ");
    scanf("%c%*c", &op);
    while (op != 'S' && op != 's' && op != 'N' && op != 'n'){
        system("clear||cls");
        printf("\n\n\t\tNome: %s\n", nome);
        printf("\t\tConfirmar <s/n>: ");
        scanf("%c%*c", &op);
    }
    if (op == 'S' || op == 's'){
        return 1;
    }
    return 0;
}

void excluir(int tipo, int *quant){
    int local, l_quant = *quant;
    system("clear||cls");
    printf("\t\t\t\t\tEXCLUIR %s", tipo == 1 ? "CLIENTE\n\n":"PRODUTO\n\n");

    local = recebe_codigo(tipo, l_quant);
    if(local >= 0){
        if(tipo==2 && confirmar(produtos[local].desc) == 1){
            for (int i = local; i < l_quant-1; i++){
                produtos[i] = produtos[i+1];
            }
            (*quant)--;
        }else if(tipo == 1 && confirmar(clientes[local].nome)){
                for (int i = local; i < l_quant-1; i++){
                    clientes[i] = clientes[i+1];
                }
                (*quant)--;
            }
    }
}

int recebe_codigo(int tipo, int quant){
    int cod;
    printf("Código %s: ", tipo == 1 ? "Cliente" : "Produto");
    scanf("%d%*c", &cod);
    if(cod == -1 && tipo == 2){
        return -1;
    }else if(tipo == 1){
        return procurar_cliente(cod, quant);
    }
    return procurar_produto(cod, quant);
}

void imprimir_produtos(int cod) {
    printf("\t    %-6d|  %-19s|  R$ %6.2f |\n", produtos[cod].cod, produtos[cod].desc, produtos[cod].preco);
}

float preco(int cod){
    return produtos[cod].preco;
}

void carrinho(int quant_c, int quant_p){
    int local = 0, cod = 0;
    system("clear||cls");
    printf("\t\t\t\tCARRINHO\n\n");
    do{
        local = recebe_codigo(1, quant_c);
    }while(local<0);
    while(cod != -1){
        cod = recebe_codigo(2, quant_p);
        if (cod>=0){
            clientes[local].compras[clientes[local].quant_c] = cod;
            clientes[local].quant_c++;
        }
    }
    venda(local);
}

void limpar_carrinho(int id_cliente ,int *quant_compras){
    for (int i = 0; i < *quant_compras; i++){
        clientes[id_cliente].compras[i] = 0;
    }
    *quant_compras = 0;
}

void venda(int id_cliente){
    float valor = 0; 
    system("clear||cls");
    printf("\t\t\tLISTA PRODUTOS\n\n");
    printf("\tComprador: %d  -  %s\n\n\n\n", clientes[id_cliente].cod, clientes[id_cliente].nome);
    printf("\t%-10s |  %-20s |  %-10s |\n", "Código", "Descrição", "Preço");
    for(int i = 0; i < clientes[id_cliente].quant_c; i++){
        imprimir_produtos(clientes[id_cliente].compras[i]);
        valor += preco(clientes[id_cliente].compras[i]);
    }
    printf("\n\n\n\tTOTAL: R$ %.2f\n\n\n", valor);
    printf("\t\t\tAperte ENTER para continuar");
    scanf("%*c");
    system("clear||cls");
    limpar_carrinho(id_cliente, &clientes[id_cliente].quant_c);
}

void fim(){
    system("clear||cls");
    printf("\n\n\t\t\t\t   FIM DO MEU EXPEDIENTE\n\n\t\t\t\tvaleu meu mano, até a próxima\n\n\n\n\n\n");
    exit(0);
}

void erro(){
    system("clear||cls");
    printf("\n\t\t\t\t Não encontrado!!\n\n");
    sleep(2);
    system("clear||cls");
}

void sucess(){
    system("clear||cls");
    printf("\n\n\t\t\tAtualizado\n\n");
    sleep(1);
    system("clear||cls");
}
