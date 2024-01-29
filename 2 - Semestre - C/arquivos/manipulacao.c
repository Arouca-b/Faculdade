#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void menu_arquivos();
char valida();
void erro_valor();
void imprimir_arquivo(FILE* fp);
void escolha(int opcao, FILE* fp, char* nomeAr);
char* criar_arquivo(FILE* fp, char* nomeAr);
void texto_arquivo(FILE* fp);
void ler_arquivo(FILE* fp, char* nomeAr);
void editar_arquivo(FILE* fp, char* nomeAr);
void abrindo_arquivo();
char* nome_arquivo(char*);
void excluir_arquivo(char*);
void prosseguir();
void mesclar();

int main(){
    int opcao;
    char nome_arq[30];
    FILE *ponte;
    do{
        menu_arquivos();
        printf("Escolha: ");
        opcao = valida();
        escolha(opcao, ponte, nome_arq);
    } while (opcao != 0);
}

void abrindo_arquivo(){
    int i = 0;

    while (i<=100){
        fflush(stdout);
        system("clear||cls");
        printf("\t\t\t\tLOADING: %d%%\n\n", i);
        sleep(1);
        if(i%2 == 1){
            i+=11;
            continue;
        }
        i+=9;
    }
    system("clear||cls");
}

void menu_arquivos(){
    printf("\t\t\t\t\tARQUIVOS\n");
    printf("\t\t\t\tManipulação de arquivos inicial\n\n\n");
    printf("1 - Ler arquivo\n");
    printf("2 - Criar Arquivo\n");
    printf("3 - Acrescentar informações em um Arquivo\n");
    printf("4 - Mesclar Arquivos\n");
    printf("8 - Excluir Arquivo\n");
    printf("0 - Sair\n\n");
}

char valida(){ //validar entrada das opções menu
    char a[4];
    scanf("%3s", a);
    if (((a[0] >= 48 && a[0] <= 53) || a[0] == 56) && a[1]=='\0'){
        return a[0] - 48;
    }
    erro_valor();
    return valida();
}

void erro_valor(){//Caso usuário insira um valor fora dos parâmetros
    system("clear||cls");
    printf("\n\t\t\t\tInsira um valor válido!!\n\n");
    sleep(2);
    system("clear||cls");
    menu_arquivos();
}

void escolha(int opcao, FILE* fp, char* nomeAr){//Executar ação conforme escolha do usuário
    switch (opcao){
    case 1:

        ler_arquivo(fp, nomeAr);
        break;
    
    case 2:
        criar_arquivo(fp, nomeAr);
        break;
    
    case 3:
        editar_arquivo(fp, nomeAr);
        break;
    
    case 4:
        mesclar();
        break;

    case 8:
        excluir_arquivo(nomeAr);
    default:
        break;
    }
}

char* criar_arquivo(FILE* fp, char* nomeAr){    //Criar um arquivo
    system("clear||cls");
    printf("\t\t\t\tCRIAR ARQUIVO\n\n");
    nomeAr = nome_arquivo(nomeAr);
    if ((fp = fopen(nomeAr, "w")) == NULL){
        printf("Erro ao criar arquivo!!\n\n\n");
        exit(1);
    }
    texto_arquivo(fp);
    fclose(fp);
    printf("\n\n\t\t\t\tArquivo Criado com sucesso!!\n\n");
    prosseguir();
    return nomeAr;
}

void texto_arquivo(FILE* fp){   //inserir conteudo no arquivo
    char ch = getchar();
    if ( ch != '$'){
        if (EOF == putc(ch,fp)){
            printf("\t\tErro no arquivo durante gravacao\n\n\n");
            return;
        }
        texto_arquivo(fp);
    }
    return;
}

char* nome_arquivo(char* nomeAr){   //inserir nome do arquivo que usuário deseja manipular
    printf("Insira nome do arquivo: "); 
    fflush(stdout);
    scanf("%29s", nomeAr);
    fflush(stdin);
    return nomeAr;
}

void ler_arquivo(FILE* fp, char* nomeAr){ //abrir e imprimir conteudo presente no arquivo
    system("clear||cls");
    printf("\t\t\t\tLEITURA DE ARQUIVOS\n\n");
    nomeAr = nome_arquivo(nomeAr);
    if ((fp = fopen(nomeAr, "r")) == NULL){
        printf("Arquivo não encontrado!!\n\n\n");
        exit(1);
    }
    //abrindo_arquivo();
    system("clear||cls");
    printf("\n\n\t\t\t\t\t\t%s\n\n\n", nomeAr);
    imprimir_arquivo(fp);
    fclose(fp);
    prosseguir();
}

void imprimir_arquivo(FILE* fp){ //imprimir conteudo presente no arquivo
    char ch = getc(fp);
    while (!feof(fp)){
        printf("%c", ch);
        ch = getc(fp);
    }
    /*
    recursividade:

    if(!feof(fp)){
        char ch = getc(fp);
        printf("%c", ch);
        imprimir_arquivo(fp);
    }
    return;
    */
   scanf("%*c");
}

void editar_arquivo(FILE* fp, char* nomeAr){ //abrir e editar arquivo, insere conteudo no final do arquivo
    system("clear||cls");
    printf("\t\t\t\tEDITAR ARQUIVO\n\n");
    nomeAr = nome_arquivo(nomeAr);
    if ((fp = fopen(nomeAr, "r")) != NULL){ //abre arquivo para modo leitura e imprime o conteudo presente
        imprimir_arquivo(fp);
        fclose(fp);
    }
    
    if ((fp = fopen(nomeAr, "a")) == NULL){ //abre o arquivo para acrescentar texto no final
        printf("Arquivo não encontrado");
        exit(1);
    }
    texto_arquivo(fp);
    fclose(fp);
    system("clear||cls");
}

void excluir_arquivo(char* nomeAr){ //excluir arquivo desejado
    system("clear||cls");
    printf("\t\t\t\t\tEXCLUIR ARQUIVO\n\n\n");
    nomeAr = nome_arquivo(nomeAr);
    remove(nomeAr);
    system("clear||cls");
    printf("\n\n\t\t\t\tArquivo  %s  Excluído com sucesso!!\n\n", nomeAr);
    sleep(2);
    system("clear||cls");
}

void prosseguir(){
    printf("\n\n\t\t\t\t\tAperte ENTER para continuar!!");
    scanf("%*c");
    system("clear||cls");
}

void mesclar(){//juntar dois arquivos
    FILE *arquivo1, *arquivo2, *arquivo_p;
    char nome1[30], nome2[30], ch, nome_p[30];

    printf("\n\t\t\t\tMESCLAR ARQUIVOS\n\n");
    //Primeiro arquivo
    printf("\n\nArquivo 1: \n\n");
    strcpy(nome1, nome_arquivo(nome1));
    arquivo1 = fopen(nome1, "r");
    if (arquivo1 == NULL){
        printf("Erro abrir o arquivo!!");
        exit(1);
    }
    //fim Primeiro arquivo

    printf("\n\nArquivo 2: \n\n");
    strcpy(nome2, nome_arquivo(nome2));
    arquivo1 = fopen(nome1, "r");
    if (arquivo1 == NULL){
        printf("Erro abrir o arquivo!!");
        exit(1);
    }

    printf("\n\nArquivo resultante: \n\n");
    strcpy(nome_p, nome_arquivo(nome_p));

    arquivo_p = fopen(nome_p, "w");//novo arquivo da junção dos 2 arquivos desejados
    
    //Primeiro arquivo
    ch = getc(arquivo1);
    while (!feof(arquivo1) && EOF != putc(ch, arquivo_p)){
        ch = getc(arquivo1);
    }
    fclose(arquivo1);
    //fim Primeiro arquivo
    putc('\n', arquivo_p);
    putc('\n', arquivo_p);
    

    //Segundo arquivo
    arquivo2 = fopen(nome2, "r");
    if (arquivo2 == NULL){
        printf("Erro ao abrir o arquivo!!");
        exit(1);
    }
    int idade;
    char nome_c[30];
    while (fscanf(arquivo2, "%29s %d", nome_c, &idade) == 2){
        fprintf(arquivo_p,"%10s       %3d", nome_c, idade);
        putc('\n', arquivo_p);
    }
    scanf("%*c");
    fclose(arquivo2);
    //Fim Segundo arquivo;

    fclose(arquivo_p);
    //fim arquivos
    system("clear||cls");
    printf("\t\t\t\t\tArquivo criado com sucesso!!!\n\n\n");
    sleep(2);    
    system("clear||cls");
}