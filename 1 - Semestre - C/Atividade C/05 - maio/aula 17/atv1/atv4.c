/*Modificar o programa para atender a passageiros
de avião (usuário informará o modelo do avião):
– AirBus e Boing: 2 fileiras de 3 cadeiras: Janela-meio-
corredor (a-b-c/d-e-f).
– Padrão internacional: fileiras de 8 cadeiras: 2 – 4 – 2
(a-b/c-d-e-f/g-h)
– Foccker 100: 3 – 2 (a-b-c/d-f)
Obs: Da esquerda pra direita*/
#include <stdio.h>

int main(){
    int poltrona, modelo, fileira, q_poltrona, pos;
    char pol;

    pol = poltrona = modelo = fileira = q_poltrona = pos = 0;
    do{
        printf("\t\t----------------------------\n");
        printf("\t\t|  Qual o modelo do Avião? |");
        printf("\n\t\t----------------------------\n");
        printf("1 - Airbusz\n");
        printf("2 - Boing\n");
        printf("3 - Padrão Internacional\n");
        printf("4 - Foccker 100\n");
        printf("\nopção: ");
        scanf("%d", &modelo);
        switch(modelo){
            case 1:
            case 2:  
                q_poltrona = 6;
            break;
            case 3: 
                q_poltrona = 8; 
            break;
            case 4:
                q_poltrona = 5;
            break;
            default: printf("\n\t\t\tValor Inválido!\n\n");
        }
    }while(modelo > 4 || modelo < 1);

    printf("\nNumeração da poltrona(ex: 9A): ");
    scanf("%d%c", &poltrona, &pol);
    
    if (modelo == 1 || modelo == 2){
        //validação de entrada modelo 1 e 2
        while (poltrona > 10 || poltrona < 0 || (pol > 'F' || pol < 'A'))
        {
            system("clear");
            printf("----------------------------------\n");
            printf("|Poltrona não existe, verifique!!|\n");  
            printf("----------------------------------\n");
            printf("\nNumeração da poltrona(1A - 10F): ");
            scanf("%d%c", &poltrona, &pol);        
        }

        // Inicia fileiras do modelo 1 e 2

        pol -= 64;
        if( pol % q_poltrona == 1 || pol % q_poltrona == 2 || pol % q_poltrona == 3 ){
            fileira = 1;
            if(pol % 3 == 0){
                pos = 3; // corredor
            }else if(pol % 3 == 2){
                pos = 2; // meio
            }else{
                pos = 1; // janela
            }

        }else{
            fileira = 2;
            if (pol % 3 == 0 )
            {
                pos = 1; //janela
            } else if(pol % 3 == 2){
                pos = 2; //meio
            }else{
                pos = 3; //corredor
            }
        } // Fecha fileiras do modelo 1 e 2

    }else if (modelo == 4){
            //validação de entrada modelo 4
            while (poltrona > 10 || poltrona < 0 || (pol > 'E' || pol < 'A'))
            {
                printf("\nPoltrona não existe, verifique!!\n");  
                printf("----------------------------\n");
                printf("\nNumeração da poltrona(1A - 10E): ");
                scanf("%d%c", &poltrona, &pol);          
            }

            // Abre fileiras modelo 4

            pol -= 64;
            if((int) pol % q_poltrona == 1 || (int) pol % q_poltrona == 2 ||(int) pol % q_poltrona == 3 ){
                fileira = 1;
                if(pol % 3 == 0){
                    pos = 3; // corredor
                }else if(pol % 3 == 2){
                    pos = 2; // meio
                }else{
                    pos = 1; // janela
                }
            }else{
                fileira = 2;
                if (pol % 3 == 0 )
                {
                    pos = 1; //janela
                } else{
                    pos = 3; //corredor
                }
            }
            //fecha fileiras modelo 4

        }else{
            //validação de entrada modelo 3
                while (poltrona > 10 || poltrona < 0 || (pol > 'H' || pol < 'A'))
                {
                    printf("\nPoltrona não existe, verifique!!\n");  
                    printf("----------------------------\n");
                    printf("\nNumeração da poltrona(1A - 10H): ");
                    scanf("%d%c", &poltrona, &pol);          
                }
                // Abre fileiras modelo 3
                pol -= 64;
                if( pol % q_poltrona == 1 || pol % q_poltrona == 2){
                    fileira = 1;
                    if(pol % 2 == 0){
                        pos = 3; // corredor
                    }else{
                        pos = 1; // janela
                    }    
                }
                else if( pol % q_poltrona == 3 || pol % q_poltrona == 4 || pol % q_poltrona == 5 || pol % q_poltrona == 6){
                        fileira = 2;
                        printf("****%d = %d*****\n",pol, pol % 4);
                        if (pol % 4 == 0 ){
                            pos = 2; //meio
                        }else if(pol % 4 == 2){
                            pos = 3; // corredor
                        }else if(pol % 4 == 1){
                            pos = 2; // meio
                        }else{ 
                            pos = 3; // corredor
                            }
                    }else{
                            fileira = 3;
                            if(pol % 2 == 0){
                                pos = 1; // janela
                            }else{
                                pos = 3; // corredor
                            }
                    } // Fecha fileiras modelo 3
        }

        printf("Modelo do avião: %s\n", modelo == 1 ? "Airbusz" : modelo == 2 ? "Boing" : modelo == 3 ? "Padrão Internacional" : "Foccker 100");
        printf("Poltrona: %d%c\n", poltrona, pol+64);
        printf("Fileira: %d\n", fileira);
        printf("pos: %s\n", pos == 1 ? "Janela" : pos == 2 ? "Meio" : "Corredor");       
}