#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define limite 5

int main(){
    struct numero{
        char DDD[3], numero[10];
    };
    struct lista{
        char nome[50];
        struct numero celular; 
        struct numero telefone;
    } contato[limite];
    
    char aux[50];
    int opcao = 0, cont = 0, q_contatos = 0, result = 0, ordem = 0, pesquisa = 0, escolha = 0;

    do{
        do{
            //menu
            opcao = escolha = pesquisa = 0;
            printf("\n\t\t================================================================");
            printf("\n\t\t\t\t\t LISTA TELEFÔNICA");
            printf("\n\t\t================================================================\n");
            printf("\n\t\t    -----------------------------------------------------------");
            printf("\n\t\t    |\t1 - Inserir dados de forma ordenada por nome\t      |");
            printf("\n\t\t    |\t2 - Listar toda a agenda\t\t\t      |");
            printf("\n\t\t    |\t3 - Editar agenda por nome\t\t\t      |");
            printf("\n\t\t    |\t4 - Excluir contato por nome, atualizando índices     |");
            printf("\n\t\t    |\t5 - Procurar por nome ou por número\t\t      |");
            printf("\n\t\t    |\t\t\t\t\t\t\t      |");
            printf("\n\t\t    |\t6 - Sair\t\t\t\t\t      |");
            printf("\n\t\t    -----------------------------------------------------------");
            printf("\n\n\t    Escolha uma opcao: ");
            result = scanf("%d", &opcao);
            scanf("%*c");
            //menu

            //validação de entrada para opção
            if (result == 0 || opcao < 0 || opcao > 6){
                    system("clear||cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t-------------------------------------\n");
                    printf("\t\t\t\t\t| Opcao invalida, insira uma correta |\n");       
                    printf("\t\t\t\t\t-------------------------------------\n");
                    sleep(1);
                    system("clear||cls");
            }
        }while (result == 0 || opcao < 0 || opcao > 6);
            //fim validação de entrada

            switch (opcao){

            case 1:
                if(q_contatos == limite){
                    system("clear||cls");
                    printf("\n\n\t\t\t\tLISTA DE CONTATOS ESGOTADA\n");
                    break;
                }
                system("clear||cls");
                printf("\n\t\t================================================================");
                printf("\n\t\t\t\t\t LISTA TELEFÔNICA");
                printf("\n\t\t================================================================\n");
                printf("\n\t\t\t\tINSIRA O NOVO CONTATO\n\n\n");
                printf("Nome do contato: ");
                scanf("%49[^\n]%*c", aux);
                for(ordem = 0, cont = 0; ordem <= q_contatos; ordem++){
                    result = strcmp(aux, contato[ordem].nome);
                    if(result>0){
                        while(result>0 && ordem < q_contatos){
                            ordem++;
                            result = strcmp(aux, contato[ordem].nome);
                        }
                        if(result == 0){
                            printf("\n\n\t\t\tJÁ EXISTE UM CONTATO COM ESSE NOME\n\n\n");
                            sleep(1);
                            system("clear||cls");
                            break;
                        }
                        if (ordem!=q_contatos){
                            for (int pos = q_contatos; pos > ordem; pos--){
                                contato[pos] = contato[pos-1]; 
                            }
                        }
                        
                        while (aux[cont] != '\0'){
                            contato[ordem].nome[cont] = aux[cont];
                            cont++;
                        }
                        contato[ordem].nome[cont] = '\0';
                        break;
                    }
                    if(result < 0){
                        if (ordem!=q_contatos){
                            for (int pos = q_contatos; pos > ordem; pos--){
                                contato[pos] = contato[pos-1]; 
                            }
                        }
                        while (aux[cont] != '\0'){
                            contato[ordem].nome[cont] = aux[cont];
                            cont++;
                        }
                        contato[ordem].nome[cont] = '\0';
                        break;
                    }
                    if(result == 0){
                        printf("\n\n\t\t\tJÁ EXISTE UM CONTATO COM ESSE NOME\n\n\n");
                        sleep(1);
                        system("clear||cls");
                        break;
                    }
                }
                if (result != 0){
                    printf("Insira DDD do contato (ex: 73): ");
                    scanf("%3[^\n]%*c", contato[ordem].celular.DDD);
                    printf("Insira número do contato: ");
                    scanf("%10[^\n]%*c", contato[ordem].celular.numero);
                    printf("Insira DDD do contato (ex: 73): ");
                    scanf("%3[^\n]%*c", contato[ordem].telefone.DDD);
                    printf("Insira telefone do cliente: ");
                    scanf("%10[^\n]%*c", contato[ordem].telefone.numero);
                    system("clear||cls");

                    printf("\n\n\n\t\t\t\tCONTATO CRIADO COM SUCESSO\n\n");
                    printf("\n\n\n\t\tpressione ENTER ou qualquer tecla para continuar");
                    scanf("%*c");
                    system("clear||cls");
                    q_contatos++;
                    }
                break;
            
            case 2:
                system("clear||cls");
                printf("\n\t\t================================================================");
                printf("\n\t\t\t\t\t LISTA TELEFÔNICA");
                printf("\n\t\t================================================================\n");
                if (q_contatos>0){
                    printf("\t\tNome\t\t|\tCelular\t\t|\tTelefone\t|\n");
                    for(cont = 0; cont < q_contatos; cont++){
                        printf("\t\t%.30s\t\t|    (%.3s) %.10s\t|\t(%.5s) %.10s\t|\n", contato[cont].nome, contato[cont].celular.DDD, contato[cont].celular.numero, contato[cont].telefone.DDD, contato[cont].telefone.numero);
                    }
                }else{
                    printf("\n\n\t\t\t\t\tLISTA DE CONTATO VAZIA");
                }
                printf("\n\n\n\n\t\t\t\tPressione ENTER para voltar para o menu");
                scanf("%*c");
                system("clear||cls");
                break;

            case 3:
                system("clear||cls");
                printf("\n\t================================================================");
                printf("\n\t\t\t\t LISTA TELEFÔNICA \n");
                printf("\t================================================================\n");
                printf("\n\t\t-------------------------------------------------");
                printf("\n\t\t\t\tEDIÇÃO DE CONTATO\n\n\n");
                if (q_contatos == 0){
                    printf("\n\n\t\t\t\tLISTA DE CONTATO VAZIA");
                    printf("\n\n\n\n\t\tPressione ENTER para continuar");
                    scanf("%*c");
                    system("clear||cls");
                    break;
                }
                printf("\n\n\n\t\tInsira o nome do contato que deseja editar: ");
                scanf("%49[^\n]%*c", aux);
                for(cont = 0; cont <= q_contatos; cont++){
                    result = strcmp(aux, contato[cont].nome);
                    if (result == 0){
                        printf("\n1 - TROCAR TELEFONE\n2 - TROCAR CELULAR\n3 - AMBOS\n\n");
                        printf("Escolha: ");
                        scanf("%d%*c", &escolha);
                        while (escolha < 1 || escolha > 3){
                            printf("\n\t\t\tOPÇÃO INVÁLIDA\n\n");
                            printf("\n1 - TROCAR TELEFONE\n2 - TROCAR CELULAR\n3 - AMBOS\n\n");
                            printf("Escolha: ");
                            scanf("%d%*c", &escolha);
                        }
                        switch (escolha){
                        case 1:
                            printf("Insira DDD do telefone(ex: 73): ");
                            scanf("%3[^\n]%*c", contato[cont].telefone.DDD);
                            printf("Insira numero telefone do contato: ");
                            scanf("%10[^\n]%*c", contato[cont].telefone.numero);
                            break;
                        
                        case 2:
                            printf("Insira DDD do celular (ex: 73): ");
                            scanf("%3[^\n]%*c", contato[cont].celular.DDD);
                            printf("Insira número do celular do contato: ");
                            scanf("%10[^\n]%*c", contato[cont].celular.numero); 
                            break;

                        default:
                            printf("Insira DDD do celular (ex: 73): ");
                            scanf("%3[^\n]%*c", contato[cont].celular.DDD);
                            printf("Insira número do celular do contato: ");
                            scanf("%10[^\n]%*c", contato[cont].celular.numero); 
                            printf("Insira DDD do telefone(ex: 73): ");
                            scanf("%3[^\n]%*c", contato[cont].telefone.DDD);
                            printf("Insira numero telefone do contato: ");
                            scanf("%10[^\n]%*c", contato[cont].telefone.numero);
                            break;
                        }

                        system("clear||cls");

                        printf("\n\t\t\t\tCONTATO EDITADO COM SUCESSO\n\n\n\t\t\tpressione ENTER ou qualquer letra para voltar para o menu");
                        scanf("%*c");
                        system("clear||cls");
                        break;

                    }else if (cont == q_contatos){
                        printf("\n\t\t\t\t CONTATO NÃO ENCONTRADO\n\n\n");
                        printf("\n\n\n\n\t\tPressione ENTER ou qualquer tecla para continuar");
                        scanf("%*c");
                        system("clear||cls");
                        break;
                    }
                }
                break;

            case 4:
                system("clear||cls");
                printf("\n\t================================================================");
                printf("\n\t\t\t\t LISTA TELEFÔNICA \n");
                printf("\t================================================================\n");
                printf("\n\t\t-------------------------------------------------");
                printf("\n\t\t\t\tEXCLUSÃO DE CONTATO\n\n\n");
                if (q_contatos == 0){
                    printf("\n\n\t\t\t\tLISTA DE CONTATO VAZIA");
                    printf("\n\n\n\n\t\tPressione ENTER ou qualquer tecla para continuar");
                    scanf("%*c");
                    system("clear||cls");
                    break;
                }
                printf("\n\n\n\t\tInsira o nome do contato que deseja EXCLUIR: ");
                scanf("%49[^\n]%*c", aux);
                for(cont = 0; cont <= q_contatos; cont++){
                    result = strcmp(aux, contato[cont].nome);
                    if (result == 0 && cont < q_contatos){
                        for (; cont < q_contatos; cont++){
                            contato[cont] = contato[cont+1];
                        }
                        q_contatos--;
                        break;
                    }else if (result != 0 && cont == q_contatos){
                        system("clear||cls");
                        printf("\n\t\t\t\t CONTATO NÃO ENCONTRADO\n\n\n");
                        printf("\n\n\n\n\tPressione ENTER para continuar");
                        scanf("%*c");
                        system("clear||cls");
                        break;
                    }else{
                        q_contatos--;
                        break;
                    }
                }
                printf("\n\t\t\t\tCONTATO EXCLUIDO COM SUCESSO\n\n\n\t\t\tpressione ENTER para voltar para o menu");
                scanf("%*c");
                system("clear||cls");
                break;

            case 5:
                system("clear||cls");
                printf("\n\t================================================================");
                printf("\n\t\t\t\t LISTA TELEFÔNICA \n");
                printf("\t================================================================\n");
                printf("\n\t\t-------------------------------------------------");
                printf("\n\t\t\t\tPROCURA DE CONTATO\n\n\n");
                if (q_contatos == 0){
                    printf("\n\n\t\t\t\tLISTA DE CONTATO VAZIA");
                    printf("\n\n\n\n\t\tPressione ENTER ou qualquer tecla para continuar");
                    scanf("%*c");
                    system("clear||cls");
                }else{
                    do{
                        printf("\n\t\t\tPESQUISA POR NOME = 1\n\t\t\tPESQUISA POR CELULAR = 2\n\t\t\tPESQUISA POR TELEFONE = 3\n\n");
                        printf("opção: ");
                        scanf("%d%*c", &opcao);
                    } while (opcao < 1 || opcao > 3);
                    
                    if (opcao == 1 ){
                        printf("\n\n\n\t\tInsira o nome do contato que deseja encontrar: ");
                        scanf("%49[^\n]%*c", aux);
                        for(cont = 0; cont <= q_contatos; cont++){
                            result = strcmp(aux, contato[cont].nome);
                            if (result == 0){
                                pesquisa = 1;
                                break;
                            }else if (cont == q_contatos){
                                printf("\n\t\t\t\t CONTATO NÃO ENCONTRADO\n\n\n");
                                printf("\n\n\n\n\t\tPressione ENTER ou qualquer tecla para continuar");
                                scanf("%*c");
                                system("clear||cls");
                                break;
                            }
                        }
                    }else if(opcao == 2){
                        printf("\n\n\n\t\tInsira o numuro de celular que deseja encontrar (sem DDD): ");
                        scanf("%10[^\n]%*c", aux);
                        for(cont = 0; cont <= q_contatos; cont++){
                            result = strcmp(aux, contato[cont].celular.numero);
                            if (result == 0){
                                pesquisa = 1;
                                break;
                            }else if (cont == q_contatos){
                                printf("\n\t\t\t\t CONTATO NÃO ENCONTRADO\n\n\n");
                                printf("\n\n\n\n\t\tPressione ENTER ou qualquer tecla para continuar");
                                scanf("%*c");
                                system("clear||cls");
                                break;
                            }
                        }
                    }else{
                        printf("\n\n\n\t\tInsira o numero de telefone que deseja encontrar (sem DDD): ");
                        scanf("%10[^\n]%*c", aux);
                        for(cont = 0; cont <= q_contatos; cont++){
                            result = strcmp(aux, contato[cont].telefone.numero);
                            if (result == 0){
                                pesquisa = 1;
                                break;
                            }else if (cont == q_contatos){
                                printf("\n\t\t\t\t CONTATO NÃO ENCONTRADO\n\n\n");
                                printf("\n\n\n\n\t\tPressione ENTER ou qualquer tecla para continuar");
                                scanf("%*c");
                                system("clear||cls");
                                break;
                            }
                        } 
                    }
                    if (pesquisa == 1){
                        system("clear||cls");
                        printf("\n\t================================================================");
                        printf("\n\t\t\t\t LISTA TELEFÔNICA \n");
                        printf("\t================================================================\n");
                        printf("\n\t\t-------------------------------------------------");
                        printf("\n\t\t\t\tPROCURA DE CONTATO\n\n\n");
                        printf("\t\tNome\t\t|\tCelular\t\t|\tTelefone\t|\n");
                        printf("\t\t%.30s\t\t|\t(%.5s) %.10s\t|\t(%.5s) %.10s\t|\n", contato[cont].nome, contato[cont].celular.DDD, contato[cont].celular.numero, contato[cont].telefone.DDD, contato[cont].telefone.numero);

                        printf("\n\n\n\t\t\t\tCONTATO ENCONTRADO COM SUCESSO\n\n\n\t\tpressione ENTER ou qualquer letra para voltar para o menu");
                        scanf("%*c");
                        system("clear||cls");
                    }
                }
                break;

            default:
                //mensagem de encerramento
                system("clear||cls");
                printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t----------------\n");
                printf("\t\t\t\t\t| Volte sempre |\n");       
                printf("\t\t\t\t\t----------------\n");
                printf("\n\n\n\n\n\n\n\n\n");
                break;
            }
    } while (opcao != 6);
}