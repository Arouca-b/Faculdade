#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cod, estoque;
    char desc[100];
    float preco;
} PRODUTO;

typedef struct {
    int cod_venda;
    char hora[100], data[100];
    PRODUTO produtos;
    float preco_venda;
} VENDA;

//VALIDAÇÃO
int validacao_inteiro(char op[]);
int validacao(int quantidade_produto);
int recebe_cod_produto(PRODUTO *prod2, int quant);
int recebe_estoque(PRODUTO *prod2, int posicao);
int confirmar();
int escolhe_opcao();
int recebe_inteiro();

//MENU
void menu();

//PRODUTOS
PRODUTO* inserir_produto(int* quant, PRODUTO* prod1);
void imprimir_produtos(PRODUTO* produtos, int quant);
void imprimir_venda(int *compras, int q_compras, PRODUTO *produtos);
int procurar_produto(int cod, PRODUTO *prod2, int quant);
void atualizar_estoque(PRODUTO *prod3, int quant);
int novo_estoque(int posicao_produto, PRODUTO *prod3);
void venda(PRODUTO *produtos, int quantidade_produtos);

//MEMORIA
PRODUTO* alocar_espacos();
PRODUTO* realocar_espaco(PRODUTO *prod2, int quant);

//MENSAGENS
void fim();
void erro();
void sucess();
void imprimir_correcao(int qnt, PRODUTO *prod2, int posicao);

int main(){
    PRODUTO *produto = NULL;
    int quant_produto = 0, quant_clientes;
    produto = alocar_espacos();
    int op = 0;
    for (;;){
        menu();
        op = escolhe_opcao();
        
        switch (op){
        case 1:
            produto = inserir_produto(&quant_produto, produto);
            break;
        
        case 2: 
            if (validacao(quant_produto)){
                atualizar_estoque(produto, quant_produto);
            }
            break;

        case 3:
            if (validacao(quant_produto)){
                venda(produto, quant_produto);
            }
            break;

        case 4:
            if (validacao(quant_produto)){
                imprimir_produtos(produto, quant_produto);
            }
            break;

        case 5:
            free(produto);
            fim();
            break;
        }
    }
}

//ALOCAÇÃO E INSERÇÃO DE PRODUTOS
PRODUTO* alocar_espacos() { //Alocação de espaço inicial, transformação de ponteiro em vetor
    PRODUTO* prod1 = (PRODUTO *) malloc(sizeof(PRODUTO));
    if (prod1 == NULL) {
        exit(1);
    }
    return prod1;
}

PRODUTO* realocar_espaco(PRODUTO *prod2, int quant){//Realocação de espaço do vetor, aumentar para inserir mais produtos
    prod2 = realloc(prod2, (quant + 1) * sizeof(PRODUTO));
    if (prod2 == NULL) {
        exit(1);
    }
    return prod2;
}

PRODUTO* inserir_produto(int *quant, PRODUTO *prod1){ //Inserir produtos
    char op[10];
    int indice = *quant, cod;
    //indice passa a ser o valor apontado por quant, ou seja, o último elemento do vetor e a quantidade de produtos

    system("clear||cls");
    printf("\t\t\tNOVO PRODUTO\n\n");
    if(indice){ //realocar espaco se houver mais de 1 produto
        prod1 = realocar_espaco(prod1, indice);
    }

    //receber o código do produto
    prod1[indice].cod = recebe_cod_produto(prod1, indice);
    
    printf("Nome produto: ");
    scanf("%99[^\n]%*c", prod1[indice].desc);

    //receber valor estoque
    prod1[indice].estoque = 0;

    printf("Preço: R$ ");
    scanf("%f%*c", &prod1[indice].preco);
    
    system("clear||cls");
    (*quant)++;
    
    return prod1;
}
//FIM ALOCAÇÃO E INSERÇÃO DE PRODUTOS

//MENSAGENS
void menu(){
    printf("1 - Inserir produto no programa\n");
    printf("2 - Atualizar estoque\n");
    printf("3 - Venda de produtos\n");
    printf("4 - Mostrar produtos e estoque\n");
    printf("5 - Sair\n");
}

void sucess(){
    system("clear||cls");
    printf("\n\n\t\t\tAtualizado\n\n");
    sleep(2);
    system("clear||cls");
}

void erro(){
    system("clear||cls");
    printf("\n\t\t\t\t Não encontrado!!\n\n");
    sleep(2);
    system("clear||cls");
}

void fim(){
    system("clear||cls");
    printf("\n\n\t\t\t   FIM DO MEU EXPEDIENTE\n\n\t\t\tvaleu meu mano, até a próxima\n\n\n\n\n\n");
    exit(0);
}

void imprimir_produtos(PRODUTO* produtos, int quant) {
    system("clear||cls");
    printf("\n\t\t\tLISTA DE PRODUTOS\n\n");
    for (int i = 0; i < quant; i++) {
        printf("Código: %d\n", produtos[i].cod);
        printf("Descrição: %s\n", produtos[i].desc);
        printf("Estoque: %d\n", produtos[i].estoque);
        printf("Preço: %.2f\n", produtos[i].preco);
        printf("\n");
    }
    printf("\t\t\taperte ENTRER para continuar\n\n");
    scanf("%*c");
    system("clear||cls");
}

int validacao(int quantidade_produto){
    if (quantidade_produto <= 0){
        system("clear||cls");
        printf("\n\n\t\t\t\tAlimente o Banco de dados primeiro!!\n\n");
        sleep(2);
        system("clear||cls");
        return 0;
    }
    return 1;
}//FIM MENSAGENS


//DADOS
int escolhe_opcao() {
    char t[20];
    int opcao = 0;
    printf("\nEscolha: ");
    scanf("%19[^\n]%*c", t);
    opcao = atoi(t);
    while (opcao >5 || opcao < 0) {
        printf("\n\nOPÇÃO INVÁLIDA\n\nEscolha: ");
        scanf("%19[^\n]%*c", t);
        opcao = atoi(t);
    }
    return opcao;
}

void atualizar_estoque(PRODUTO *prod3, int quant){
    char op[10];
    int cod, posicao_produto;
    system("clear||cls");
    printf("\t\t\tATUALIZAÇÃO DE ESTOQUE\n\n");
    printf("Código produto: ");
    cod = recebe_inteiro(); //valor para o código
    posicao_produto = procurar_produto(cod, prod3, quant); //procura a posição do produto que deseja retornar -1 se não encontrar
    if(posicao_produto>-1){
        prod3[posicao_produto].estoque = novo_estoque(posicao_produto, prod3); //atualizar o estoque
    }else{
        erro();//Caso não ache o produto no banco de dados
    }
}

int novo_estoque(int posicao_produto, PRODUTO *prod3){ //atualizar estoque
    int quantidade;
    imprimir_correcao(2, prod3, posicao_produto);
    printf("Novo estoque: ");
    quantidade = recebe_inteiro();
    while (quantidade < 0){
        system("clear||cls");
        printf("\t\t\tVALOR INVÁLIDO!!\n\n");
        imprimir_correcao(2, prod3, posicao_produto);//imprimir código e nome do produto
        printf("Novo estoque: ");   
        quantidade = recebe_inteiro();
    }
    sucess();
    return quantidade;
}
//FIM DADOS

int procurar_produto(int cod, PRODUTO *prod2, int quant){ //procura e retorna posição do produto, -1 se não encontrar
    for (int posicao = 0; posicao < quant; posicao++){
        if (prod2[posicao].cod == cod){
            return posicao;
        }
    }
    return -1;
}

int recebe_inteiro(){   //receber valores inteiros
    char op[10];
    int situacao;
    scanf("%9[^\n]", op);
    fflush(stdin);
    situacao = validacao_inteiro(op);   //verificar se tem apenas número na string
    return situacao;
}

int validacao_inteiro(char op[]){   //verificar se tem apenas número na string
    for (int i = 0; op[i] != '\0'; i++){
        if (op[i] > 57 || op[i] < 48){
            return -1;
        }
    }
    return atoi(op);
}

int recebe_cod_produto( PRODUTO *prod2, int quant){     //validação para códigos de produtos, para não repetir e garantir que seja apenas números
    int situacao, cod;
    printf("Insira código: ");
    cod = recebe_inteiro();
    situacao = procurar_produto(cod, prod2, quant);
    if (situacao == -1 && cod > -1){
        return cod;
    }else{
        while (situacao > -1 || cod == -1){
            system("clear||cls");
            printf("\t\t\tNOVO PRODUTO\n\n");
            printf("\t\t\tCódigo inválido\n\n");
            printf("Insira novo código: ");
            cod = recebe_inteiro();
            if (cod >= 0)
                situacao = procurar_produto(cod, prod2, quant);
        }
    }
    return cod;
}


int recebe_estoque(PRODUTO *prod2, int posicao){    //Receber apenas valores inteiros para estoque
    int estoque;
    printf("Estoque: ");
    estoque = recebe_inteiro();
    while (estoque == -1){
        system("clear||cls");
        printf("\t\t\tVALOR INVÁLIDO!!\n\n");
        imprimir_correcao(1, prod2, posicao);
        printf("Estoque: ");
        estoque = recebe_inteiro();
    }
    return estoque;
}

void imprimir_correcao(int qnt, PRODUTO *prod2, int posicao){//imprimir mensagens
    for (int imp = 0; imp < qnt; imp++){
        switch (imp){
            case 0:
                printf("\nCódigo: %d\n", prod2[posicao].cod);
                break;
            
            case 1:
                printf("Produto: %s\n", prod2[posicao].desc);
                break;

            case 2:
                printf("Estoque: %d\n", prod2[posicao].estoque);
                break;

            case 3:
                printf("Valor: %.2f\n", prod2[posicao].preco);
                break;
        }
    }
}

void venda(PRODUTO *produtos, int quantidade_produtos){ //vender produtos, criar vetor e salvar as posições dos produtos comprados
    int *posicao_comprados, confirma;
    int quant_compras = 0, codigo = 0, indice_produto = 0;
    posicao_comprados = malloc(sizeof(int));
    do{
        system("clear||cls");
        printf("\t\t\t\tCOMPRAS\n\n");
        printf("Código produto: ");

        codigo = recebe_inteiro();
        indice_produto = procurar_produto(codigo, produtos, quantidade_produtos);

        if (indice_produto> -1 && produtos[indice_produto].estoque > 0){
            printf("\nProduto adicionado ao carrinho\n");
            posicao_comprados[quant_compras] = indice_produto;
            quant_compras++;
            produtos[indice_produto].estoque--;
            posicao_comprados = realloc(posicao_comprados, (quant_compras+1) * sizeof(int));
            if (posicao_comprados == NULL){
                exit(1);
            }
        }else if(produtos[indice_produto].estoque == 0){
                system("clear||cls");
                printf("\n\n\t\t\tPRODUTO SEM ESTOQUE!!\n\n");
                sleep(1);
                system("clear||cls");
            }else{
                erro();
            }
        confirma = confirmar();
    }while (confirma==1);
    imprimir_venda(posicao_comprados, quant_compras, produtos);
    free(posicao_comprados);

}

void imprimir_venda(int *compras, int q_compras, PRODUTO *produtos){    //imprimir os produtos comprados
    float preco = 0;
    system("clear||cls");
    printf("\t\t\t\tCOMPRAS\n\n");
    printf("\t%-10s |  %-20s |  %-10s |\n", "Código", "Descrição", "Preço");
    for (int i = 0; i < q_compras; i++){
        printf("\t    %-6d|  %-19s|  R$ %6.2f |\n", produtos[compras[i]].cod, produtos[compras[i]].desc, produtos[compras[i]].preco);   
        preco+=produtos[compras[i]].preco;
    }
    printf("\n\n\n\tTOTAL: R$ %.2f\n\n\n", preco);

    printf("\n\t\t\taperte ENTRER para continuar\n\n");
    scanf("%*c");
    system("clear||cls");
}

int confirmar(){
    char op;
    printf("\ncontinuar compras? S/N: ");
    scanf("%c%*c", &op);
    while (op != 'S' && op != 's' && op != 'N' && op != 'n'){
        system("clear||cls");    
        printf("\ncontinuar compras? S/N: ");
        scanf("%c%*c", &op);
    }
    if (op == 'S' || op == 's'){
        return 1;
    }
    return 0;
}


