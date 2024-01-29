#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define LIMITE_TUTOR 2
#define LIMITE_PET  2

int main(){
    struct Animal{
        char nome[50], genero[50], raca[50], especie[50];
    };
    struct Cliente
    {
        char nome[50], endereco[50];
        int quantidade_pet;
        struct Animal pet[LIMITE_PET];
    }tutor[LIMITE_TUTOR];

    int ordem = 0, cont_aux=0, result = 0, q_estrutores=0, q_animais=0;
    char auxl[50], opcao[30];

    do{
        do{
            opcao[0] = result = cont_aux = ordem = 0;
            printf("\t\t\t  VETERINÁRIO\n\n\n");
            printf("1 - Cadastrar Tutor em ordem alfabética\n");
            printf("2 - Cadastrar Animal\n");
            printf("3 - Listar todos os tutores com seus animais\n");
            printf("4 - Excluir animal\n");
            printf("5 - Excluir Tutor\n");
            printf("\n\n0 - Sair\n\n");

            printf("Escolha uma opção: ");
            scanf("%29[^\n]%*c", opcao);
            for (cont_aux = 0; opcao[cont_aux] != '\0'; cont_aux++);//verifica quantos caracteres foram digitados
            if ( opcao[0] < '0' || (int) opcao[0] > '5' || cont_aux>1){
                system("clear||cls");
                printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t-------------------------------------\n");
                printf("\t\t\t\t\t| Opcao invalida, insira uma correta |\n");       
                printf("\t\t\t\t\t-------------------------------------\n");
                sleep(1);
                system("clear||cls");
            }

        } while (opcao[0] < '0' || opcao[0] > '5' || cont_aux>1);

        switch (opcao[0]){
        case '1':
            system("clear||cls");
            if (q_estrutores  == LIMITE_TUTOR){
                printf("\n\n\t\t\t\tJÁ ATINGIU O MÁXIMO DE TUTORES!\n\n");
                sleep(1);
                system("clear||cls");
                break;
            }

            printf("\n\n\t\t\t\t\tCADASTRO\n\n");
            printf("\n\n\tInsira o nome do instrutor: ");
            do{
                scanf("%49[^\n]%*c", auxl);
                for (ordem = 0; ordem <= q_estrutores ; ordem++){
                    result = strcmp(auxl, tutor[ordem].nome);
                    while(result > 0 && ordem != q_estrutores){
                        ordem++;
                        result = strcmp(auxl, tutor[ordem].nome);
                    }
                    if (result < 0){
                        for (cont_aux = q_estrutores; cont_aux > ordem; cont_aux--){
                            tutor[cont_aux] = tutor[cont_aux-1];
                        }
                        break;
                    }else if (result == 0){
                        system("clear||cls");
                        printf("\n\n\t\t\tCLIENTE JÁ EXISTE NO BANCO DE DADOS\n\n");
                        printf("\tInsira outro nome: ");
                        break;
                    }else{
                        break;
                    }
                }
                if (result!=0){
                    for (cont_aux = 0; auxl[cont_aux] != '\0'; cont_aux++){
                        tutor[ordem].nome[cont_aux] = auxl[cont_aux];
                    }
                    tutor[ordem].nome[cont_aux] = '\0';
                    printf("\n\tInsira endereço: ");
                    scanf("%49[^\n]%*c", tutor[ordem].endereco);
                }
            }while(result == 0);
            system("clear||cls");
            printf("\n\n\t\t\tTUTOR CADASTRADO COM SUCESSO!!\n\n");
            q_estrutores++;
            sleep(1);
            system("clear||cls");
            break;

        case '2':
            if (q_estrutores == 0){
                system("clear||cls");
                printf("\n\n\t\t\t\tPRIMEIRO CADASTRE UM TUTOR!!\n\n");
                printf("\n\t\t\tPressione ENTER para voltar para o menu... ");
                scanf("%*c");
                system("clear||cls");
                break;
            }
            system("clear||cls");
            printf("\n\t\t\t CADASTRO DE PETs\n\n");
            printf("\n\nInsira o nome do tutor: ");
            scanf("%49[^\n]%*c", auxl);
            result = strcmp(auxl, tutor[ordem].nome);
            
            while (ordem < q_estrutores && result != 0){
                ordem++;
                result = strcmp(auxl, tutor[ordem].nome);
            }
            
            if (result == 0 && tutor[ordem].quantidade_pet < LIMITE_PET){
                printf("\n\n\t\tDADOS DO PET\n\n");
                printf("\n\tNOME: ");
                scanf("%49[^\n]%*c", tutor[ordem].pet[tutor[ordem].quantidade_pet].nome);
                printf("\n\tGÊNERO: ");
                scanf("%49[^\n]%*c", tutor[ordem].pet[tutor[ordem].quantidade_pet].genero);
                printf("\n\tRAÇA: ");
                scanf("%49[^\n]%*c", tutor[ordem].pet[tutor[ordem].quantidade_pet].raca);
                printf("\n\tESPÉCIE: ");
                scanf("%49[^\n]%*c", tutor[ordem].pet[tutor[ordem].quantidade_pet].especie);
                tutor[ordem].quantidade_pet++;
                q_animais++;
                system("clear||cls");
                printf("\n\n\t\t\tPET CADASTRADO COM SUCESSO!!\n\n");
                sleep(1);
                system("clear||cls");
            }else if(result!=0){
                printf("\n\n\t\tTUTOR NÃO ENCONTRADO!!\n\n");
                printf("\n\t\t\tPressione ENTER para voltar para o menu! ");
                scanf("%*c");
                system("clear||cls");
            }else{
                printf("\n\n\t\t\tTUTOR ATINGIU O MÁXIMO DE PETs\n\n");
                printf("\t\t\tPressione ENTER para voltar para o menu!");
                scanf("%*c");
                system("clear||cls");
            }
                        
            break;
        
        case '3':
            system("clear||cls");
            printf("\n\n\t\t\tTUTORES CADASTRADOS\n\n");
            
            if (q_estrutores == 0){
                system("clear||cls");
                printf("\n\n\t\t\t\tPRIMEIRO CADASTRE UM TUTOR!!\n\n");
                printf("\n\t\t\tPressione ENTER para voltar para o menu... ");
                scanf("%*c");
                system("clear||cls");
                break;
            }
            
            for (ordem = 0;  ordem < q_estrutores; ordem++){
                printf("\n\n\t\t\t\tTUTOR\n\n");
                printf("\n\tNome: %s", tutor[ordem].nome);
                printf("\n\tEndereço: %s", tutor[ordem].endereco);

                printf("\n\n\t\t\t\tPET's\n\n");
                if (tutor[ordem].quantidade_pet == 0){
                    printf("\t\t\tTUTOR NÃO TEM PET\n\n");
                }else{
                    for (cont_aux = 0; cont_aux < tutor[ordem].quantidade_pet; cont_aux++){
                        printf("\n\tNome: %20s", tutor[ordem].pet[cont_aux].nome);
                        printf("\n\tGênero: %18s", tutor[ordem].pet[cont_aux].genero);
                        printf("\n\tRaça: %20s", tutor[ordem].pet[cont_aux].raca);
                        printf("\n\tEspécie: %17s\n", tutor[ordem].pet[cont_aux].especie);
                    }
                }
                printf("\t----------------------------------------------------------------------------\n");
            }
            printf("\n\n\t\t\t\tPressione ENTER para voltar para o menu! ");
            scanf("%*c");
            system("clear||cls");

            break;

        case '4':
            system("clear||cls");
            if (q_estrutores == 0){
                system("clear||cls");
                printf("\n\n\t\t\t\tPRIMEIRO CADASTRE UM TUTOR!!\n\n");
                printf("\n\t\t\tPressione ENTER para voltar para o menu... ");
                scanf("%*c");
                system("clear||cls");
                break;
            }
            if (q_animais==0){
                system("clear||cls");
                printf("\n\n\t\tNÃO TEM ANIMAIS CADASTRADOS NO SISTEMA!!\n\n");
                printf("\n\t\t\tPressione ENTER para voltar para o menu... ");
                scanf("%*c");
                system("clear||cls");
                break;
            }

            printf("\n\n\t\t\tEXCLUIR PET\n\n");
            printf("Insira nome do Tutor: ");
            scanf("%49[^\n]%*c", auxl);
            for ( ordem = 0; ordem < q_estrutores; ordem++){
                result = strcmp(auxl, tutor[ordem].nome);
                if (result == 0){
                    if (tutor[ordem].quantidade_pet == 0){
                        printf("\n\t\tTUTOR NÃO TEM PET CADASTRADO\n\n");
                        printf("\n\t\t\tPressione ENTER para voltar para o menu... ");
                        break;
                    }
                    printf("Insira o nome do pet: ");
                    scanf("%49[^\n]%*c", auxl);
                    for (cont_aux = 0; cont_aux < tutor[ordem].quantidade_pet; cont_aux++){
                        result = strcmp(auxl, tutor[ordem].pet[cont_aux].nome);
                        if(result == 0){
                            while (cont_aux < tutor[ordem].quantidade_pet){
                                tutor[ordem].pet[cont_aux] = tutor[ordem].pet[cont_aux + 1];
                                cont_aux++;
                            }
                            tutor[ordem].quantidade_pet--;
                            q_animais--;
                            printf("\n\n\t\t\t\tPET DELETADO COM SUCESSO!!!\n\n");
                            sleep(1);
                            system("clear||cls");
                            break;
                        }
                    }
                    break;
                }
            }
            if (result != 0 && ordem == q_estrutores){
                printf("\n\n\tTUTOR NÃO ENCONTRADO NO NOSSO BANCO DE DADOS!!!\n\n");
                sleep(1);
                system("clear||cls");
            }
            
            break;

        case '5':
            if (q_estrutores == 0){
                system("clear||cls");
                printf("\n\n\t\t\t\tPRIMEIRO CADASTRE UM TUTOR!!\n\n");
                printf("\n\t\t\tPressione ENTER para voltar para o menu... ");
                scanf("%*c");
                system("clear||cls");
                break;
            }
            printf("\n\n\t\t\tEXCLUIR TUTOR\n\n");
            printf("Insira nome do Tutor: ");
            scanf("%49[^\n]%*c", auxl);
            for (ordem = 0; ordem < q_estrutores; ordem++){
                result = strcmp(auxl, tutor[ordem].nome);
                if (result == 0){
                    for(; ordem < q_estrutores ; ordem++){
                        tutor[ordem] = tutor[ordem + 1];
                    }
                    q_estrutores--;
                    printf("\n\n\tTUTOR DELETADO COM SUCESSO!!!\n\n");
                    sleep(1);
                    system("clear||cls");
                    break;
                }
            }
            break;
        
        default:
            system("clear||cls");
            printf("\n\n\n\t\t\t\tVOLTE SEMPRE, ESTAMOS DE PORTAS ABRIDAS PARA VOCÊ\n\n\n\n");
            break;
        }
    } while (opcao[0]!='0');
}