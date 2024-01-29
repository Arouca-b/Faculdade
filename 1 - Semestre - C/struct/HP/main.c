#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define limite 5

int main(){
    struct Dados{
        char nome[50], genero, date_nas[12], hair[20], eyes[20], especie[20], tipo_sangue[20],familia[20];
    };
    struct Casa{
        struct Dados sensiveis;
        char varinha[30], feiticio[30], medo[30], animal[30], clube[30], extra[30];
        int situacao, casa;
    } students[limite];
    
    char opcao[30] = {0}, auxiliar[50];
    int confirmar = 0, cont = 0, q_alunos = 0, result = 0, ordem = 0;

    do{
        do{
            //menu
            opcao[0] = ordem = cont = 0;
            system("clear||cls");
            printf("\n\t\t================================================================");
            printf("\n\t\t\t\t\t HOWARDS STUDENTS ID");
            printf("\n\t\t================================================================\n");
            printf("\n\t\t\t    -------------------------------------");
            printf("\n\t\t\t    |\t1 - Listar alunos por casa\t|");
            printf("\n\t\t\t    |\t2 - Listar Alunos\t\t|");
            printf("\n\t\t\t    |\t3 - Inserir novo aluno\t\t|");
            printf("\n\t\t\t    |\t4 - Recusou Convite\t\t|");
            printf("\n\t\t\t    |\t\t\t\t\t|");
            printf("\n\t\t\t    |\t0 - Sair\t\t\t|");
            printf("\n\t\t\t    -------------------------------------");
            printf("\n\n\t\t    Escolha uma opcao: ");
            scanf("%29[^\n]", opcao);
            scanf("%*c");
            //menu

            //validação de entrada para opção
            for (cont = 0; opcao[cont] != '\0'; cont++);//verifica quantos caracteres foram digitados
            if ( (int) opcao[0] < 48 || (int) opcao[0] > 52 || cont>1){
                    system("clear||cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t-------------------------------------\n");
                    printf("\t\t\t\t\t| Opcao invalida, insira uma correta |\n");       
                    printf("\t\t\t\t\t-------------------------------------\n");
                    sleep(1);
                    system("clear||cls");
            }
        }while (cont!=1 || (int) opcao[0] < 48 || (int) opcao[0] > 52);
            //fim validação de entrada

            switch (opcao[0]){
            case '1': //IMPRIMIR ALUNOS DE DETERMINADA CASA
                system("clear||cls");
                printf("\n\t\t================================================================");
                printf("\n\t\t\t\t\t HOWARDS STUDENTS ID");
                printf("\n\t\t================================================================\n");
                if(q_alunos>0){ //EXECUTAR APENAS SE TIVER ALUNOS REGISTRADOS
                    printf("\n\t\t\t\t\t ALUNOS REGISTRADOS\n\n");
                    printf("\t 1- Grifinória\t 2-  Lufa-Lufa\t 3- Corvinal\t 4- Sonserina \n\n\t Select: ");
                    result = scanf("%d%*c", &confirmar);
                    while (result == 0){
                        system("clear||cls");
                        printf("\n\n\t\t\t\t\tInsira um valor válido\n\n");
                        printf("\n\t\t\t\t\t ALUNOS REGISTRADOS\n\n");
                        printf("\t 1- Grifinória\t 2-  Lufa-Lufa\t 3- Corvinal\t 4- Sonserina \n\n\t Select: ");
                        result = scanf("%d%*c", &confirmar);
                    }
                    system("clear||cls");
                    printf("\n\t\t================================================================");
                    printf("\n\t\t\t\t\t HOWARDS STUDENTS ID");
                    printf("\n\t\t================================================================\n");
                    printf("\n\t\t\t\t\t %s HOUSE\n\n",(students[ordem].casa == 1) ? "GRIFINÓRIA" : (students[ordem].casa == 2) ? "LUFA-LUFA" : (students[ordem].casa == 3) ? "CORVINAL" : "SONSERINA");

                    for (ordem = 0; ordem <= q_alunos; ordem++){ //FOR PARA IDENTIFICAR TODOS ALUNOS DA CASA
                        if (confirmar == students[ordem].casa){ //COMPARAÇÃO PARA ACHAR OS ALUNOS
                            printf("\tName: %s\n", students[ordem].sensiveis.nome);
                            printf("\tGender: %c\n",students[ordem].sensiveis.genero);
                            printf("\tDOB: %s\n" ,students[ordem].sensiveis.date_nas);
                            printf("\tHair: %s\n", students[ordem].sensiveis.hair);
                            printf("\tEyes: %s\n",students[ordem].sensiveis.especie);
                            printf("\tBlood: %s\n",students[ordem].sensiveis.tipo_sangue);
                            printf("\tRegistered: %s\n",students[ordem].sensiveis.familia);
                            printf("\tHouse: %s\n", (students[ordem].casa == 1)? "Grifinória": (students[ordem].casa == 2) ? "Lufa-Lufa" : (students[ordem].casa == 3) ? "Corvinal" : "Sonserina");
                            printf("\tWand: %s\n", students[ordem].varinha);
                            printf("\tPatronus: %s\n", students[ordem].feiticio);
                            printf("\tBoggart: %s\n",students[ordem].medo);
                            printf("\tPet: %s\n", students[ordem].animal);
                            printf("\tClubs: %s\n", students[ordem].clube);
                            printf("\tExtra: %s\n", students[ordem].extra);
                            printf("\tSituação: %s", students[ordem].situacao == 0 ? "Pendente":"Matrículado");
                            printf("\n\n");
                            cont++;
                        }
                        if(cont == 0 && ordem == q_alunos){ //IMPRIMIR CASO CHEGUE NO FINAL DA LISTA E NÃO TENHA ENCONTRADO NENHUM ALUNO NA CASA DESEJADA
                            printf("\n\n\t\t\tNÃO TEM ALUNOS NESSA CASA!!");
                        }
                        printf("\n");
                    }
                }else{//CASO NÃO TENHA NENHUM ALUNO REGISTRADO
                    printf("\n\n\t\t\t\t\tLISTA DE MATRICULA VAZIA");
                }
                printf("\n\n\t\t\t\tPressione ENTER para voltar para o menu");
                scanf("%*c");
                system("clear||cls");
                break;

            case '2':
                system("clear||cls");
                printf("\n\t\t================================================================");
                printf("\n\t\t\t\t\t HOWARDS STUDENTS ID");
                printf("\n\t\t================================================================\n\n");
                if(q_alunos>0){//EXECUTAR APENAS SE TIVER ALUNOS REGISTRADOS
                    system("clear||cls");
                    printf("\n\t\t\t\t\t ALUNOS REGISTRADOS\n\n");
                    for (ordem = 0; ordem < q_alunos; ordem++){ //imprimir todos os alunos
                        printf("\tSituação: ");
                        students[ordem].situacao == 0 ? printf("Pendente\n") : printf("Matrículado\n");
                        printf("\tName: %s\n", students[ordem].sensiveis.nome);
                        printf("\tGender: %c\n",students[ordem].sensiveis.genero);
                        printf("\tDOB: %s\n" ,students[ordem].sensiveis.date_nas);
                        printf("\tHair: %s\n", students[ordem].sensiveis.hair);
                        printf("\tEyes: %s\n",students[ordem].sensiveis.especie);
                        printf("\tBlood: %s\n",students[ordem].sensiveis.tipo_sangue);
                        printf("\tRegistered: %s\n",students[ordem].sensiveis.familia);
                        printf("\tHouse: %s\n", (students[ordem].casa == 1)? "Grifinória": (students[ordem].casa == 2) ? "Lufa-Lufa" : (students[ordem].casa == 3) ? "Corvinal" : "Sonserina");
                        printf("\tWand: %s\n", students[ordem].varinha);
                        printf("\tPatronus: %s\n", students[ordem].feiticio);
                        printf("\tBoggart: %s\n",students[ordem].medo);
                        printf("\tPet: %s\n", students[ordem].animal);
                        printf("\tClubs: %s\n", students[ordem].clube);
                        printf("\tExtra: %s\n", students[ordem].extra);
                        printf("\n\n");
                    }
                }else{
                    printf("\n\n\t\t\t\t\tLISTA DE MATRICULAS VAZIA");
                }
                printf("\n\n\t\t\t\tPressione ENTER para voltar para o menu");
                scanf("%*c");
                system("clear||cls");
                break;

            case '3':
                if(q_alunos == limite){//CASO TENHA ATINGIDO O LIMITE DE ALUNO
                    system("clear||cls");
                    printf("\n\n\t\t\t\t\tLISTA DE ALUNOS ESGOTADA\n");
                }else{
                    system("clear||cls");
                    printf("\n\t\t================================================================");
                    printf("\n\t\t\t\t\t HOWARDS STUDENTS ID");
                    printf("\n\t\t================================================================\n");
                    printf("\n\t\t\t\tINSIRA O NOVO ALUNO\n\n\n");
                    printf("Name student: ");
                    scanf("%49[^\n]%*c", auxiliar);
                    for(ordem = 0, cont = 0; ordem <= q_alunos; ordem++){ //for para adicionar e ordenar
                        result = strcmp(auxiliar, students[ordem].sensiveis.nome);
                        if(result>0){ //caso seja maior doq o primeiro elemento
                            while(result>0 && ordem < q_alunos){ //verificar se ele é maior do que outros valores já registrados
                                ordem++;
                                result = strcmp(auxiliar, students[ordem].sensiveis.nome);
                            }
                            if (ordem!=q_alunos){ //organizar caso seja menor do que algum valor
                                for (int posicao = q_alunos; posicao > ordem; posicao--){
                                    students[posicao] = students[posicao-1]; 
                                }
                            }
                            while (auxiliar[cont] != '\0'){
                                students[ordem].sensiveis.nome[cont] = auxiliar[cont];
                                cont++;
                            }
                            students[ordem].sensiveis.nome[cont] = '\0';
                            break;
                        }
                        if(result < 0){ //caso seja menor do que algum valor
                            if (ordem!=q_alunos){ //organizar a ordem alfabética
                                for (int pos = q_alunos; pos > ordem; pos--){
                                    students[pos] = students[pos-1];
                                }
                            }
                            while (auxiliar[cont] != '\0'){ //colocar o nome na posição
                                students[ordem].sensiveis.nome[cont] = auxiliar[cont];
                                cont++;
                            }
                            students[ordem].sensiveis.nome[cont] = '\0';
                            break;
                        }
                        if(result == 0){//caso já tenha esse nome nas matriculas
                            printf("\n\n\t\t\tJÁ EXISTE UM ALUNO COM ESSE NOME\n\n\n");
                            break;
                        }
                    }
                    if (result != 0){ //inserir os dados na ordem certa
                        printf("Gender (M ou F): ");
                        scanf("%c%*c", &students[ordem].sensiveis.genero);
                        printf("DOB (dd/mm/yyyy): ");
                        scanf("%12[^\n]%*c", students[ordem].sensiveis.date_nas);
                        printf("Hair: ");
                        scanf("%19[^\n]%*c", students[ordem].sensiveis.hair);
                        printf("Eyes: ");
                        scanf("%19[^\n]%*c", students[ordem].sensiveis.especie);
                        printf("Blood: ");
                        scanf("%19[^\n]%*c", students[ordem].sensiveis.tipo_sangue);
                        printf("Species: ");
                        scanf("%19[^\n]%*c", students[ordem].sensiveis.especie);
                        printf("Registered: ");
                        scanf("%19[^\n]%*c", students[ordem].sensiveis.familia);
                        printf("Houses:\n\n 1- Grifinória\n 2-  Lufa-Lufa\n 3- Corvinal\n 4- Sonserina\n\n Select: ");
                        result = scanf("%d%*c", &students[ordem].casa);
                        
                        //validação de entrada para a escolha da casa (Inteiros)
                        while (result == 0){
                            system("clear||cls");
                            printf("\n\n\t\t\t\t\tInsira um valor válido\n\n");
                            printf("\tName: %s\n", students[ordem].sensiveis.nome);
                            printf("\tGender: %c\n",students[ordem].sensiveis.genero);
                            printf("\tDOB: %s\n" ,students[ordem].sensiveis.date_nas);
                            printf("\tHair: %s\n", students[ordem].sensiveis.hair);
                            printf("\tEyes: %s\n",students[ordem].sensiveis.especie);
                            printf("\tBlood: %s\n",students[ordem].sensiveis.tipo_sangue);
                            printf("\tRegistered: %s\n",students[ordem].sensiveis.familia);
                            printf("Houses:  1- Grifinória\n 2-  Lufa-Lufa\n 3- Corvinal\n 4- Sonserina \n Select: ");
                            result = scanf("%d%*c", &students[ordem].casa);
                        }
                        printf("\nWand: ");
                        scanf("%[^\n]%*c", students[ordem].varinha);
                        printf("Patronus: ");
                        scanf("%[^\n]%*c", students[ordem].feiticio);
                        printf("Boggart: ");
                        scanf("%[^\n]%*c", students[ordem].medo);
                        printf("Pet: ");
                        scanf("%[^\n]%*c", students[ordem].animal);
                        printf("Clubs: ");
                        scanf("%[^\n]%*c", students[ordem].clube);
                        printf("Extra: ");
                        scanf("%[^\n]%*c", students[ordem].extra);
                        students[ordem].situacao = 0;
                        system("clear||cls");
                        

                        printf("\n\n\n\t\t\t\t\tMATRICULA REGISTRADA COM SUCESSO\n\n");
                        q_alunos++;
                        }
                    }
                printf("\n\n\n\t\t\t\tpressione ENTER ou qualquer tecla para continuar");
                scanf("%*c");
                system("clear||cls");
                break;

            case '4':
            //confirmar se a pessoa aceitou o convite ou não
                system("clear||cls");
                printf("\n\t\t================================================================");
                printf("\n\t\t\t\t\t HOWARDS STUDENTS ID");
                printf("\n\t\t================================================================\n");
                
                if (q_alunos == 0){
                    printf("\n\n\t\t\t\t\tLISTA DE MATRICULAS VAZIA");
                }else{
                    printf("\n\t\t\t\tCONFIRMAR MATRICULA DO ALUNO\n\n\n");
                    printf("\n\n\tName student: ");
                    scanf("%30[^\n]%*c", auxiliar);
                    system("clear||cls");
                    
                    for (ordem = 0; ordem <= q_alunos; ordem++){//achar o aluno
                        result = strcmp(auxiliar, students[ordem].sensiveis.nome);
                        if (result == 0){
                            printf("\tName: %s\n", students[ordem].sensiveis.nome);
                            printf("\tGender: %c\n",students[ordem].sensiveis.genero);
                            printf("\tDOB: %s\n" ,students[ordem].sensiveis.date_nas);
                            printf("\tHair: %s\n", students[ordem].sensiveis.hair);
                            printf("\tEyes: %s\n",students[ordem].sensiveis.especie);
                            printf("\tBlood: %s\n",students[ordem].sensiveis.tipo_sangue);
                            printf("\tRegistered: %s\n",students[ordem].sensiveis.familia);
                            printf("\tHouse: %s\n", (students[ordem].casa == 1)? "Grifinória": (students[ordem].casa == 2) ? "Lufa-Lufa" : (students[ordem].casa == 3) ? "Corvinal" : "Sonserina");
                            printf("\tWand: %s\n", students[ordem].varinha);
                            printf("\tPatronus: %s\n", students[ordem].feiticio);
                            printf("\tBoggart: %s\n",students[ordem].medo);
                            printf("\tPet: %s\n", students[ordem].animal);
                            printf("\tClubs: %s\n", students[ordem].clube);
                            printf("\tExtra: %s\n", students[ordem].extra);
                            printf("\tSituação: ");
                            students[ordem].situacao == 0 ? printf("Pendente") : printf("Matrículado");
                            printf("\n");

                            if (result == 0){//se achar o aluno
                                do{ //validação de entrada para confirmar matricula ou desmatrícula
                                    printf("\n\n\t\t 1 - Para Desmatricular\n\t\t 2 - Para Matricular\n\n ");
                                    printf("\t\t escolha: ");
                                    result = scanf("%d%*c", &confirmar);
                                }while (confirmar != 1 && confirmar != 2 || result == 0);

                                if (confirmar == 1){//organizar lista ao desmatricular aluno
                                    while (ordem < q_alunos){
                                        students[ordem] = students[ordem + 1];
                                        ordem++;
                                    }
                                    printf("\n\n\t\t\t LISTA ATUALIZADA!! ");
                                    q_alunos--;
                                }else{//confirmar a matricula
                                    printf("\n\n\t\t\tMatrícula Confirmada!! ");
                                    students[ordem].situacao = 1;
                                } 
                            }
                            break;
                        }
                        if(result != 0 && ordem == q_alunos){ //mensagem caso não encontre o aluno
                            printf("\n\t\t\t\tMATRICULA NÃO ENCONTRADA");
                        }
                    }
                }
                        
                printf("\n\n\n\n\t\t\t\tPressione ENTER para voltar para o menu");
                scanf("%*c");
                system("clear||cls");
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
    } while (opcao[0] != '0');
}