//soma dos elementos com soma de indice par e soma dos elementos com soma de indice impar

#include <stdio.h>

int main(){
    int matriz[2][3][3] = {0}, soma_p, soma_i, a,b,c;
    
    for ( a = 0; a < 2; a++)
    {
        for (b = 0; b < 3; b++)
        {
            for ( c = 0; c < 3; c++)
            {
                printf("Insira valor para matriz[%d][%d][%d]: ", a,b,c);
                scanf("%d%*c", &matriz[a][b][c]);
                printf("\nsoma dos indices: %d\n\n", a+b+c);
                if ((a+b+c)%2 == 0)
                {
                    printf("\n\npassou %d\n\n", a+b+c);
                    soma_p+=matriz[a][b][c];
                }else{
                    soma_i+=matriz[a][b][c];
                }
            }
        }
    }
    printf("A soma dos elementos com soma de indice par: %3d\n", soma_p);
    printf("A soma dos elementos com soma de indice impar: %3d\n", soma_i);

    for ( a = 0; a < 2; a++){
        for (b = 0; b < 3; b++){
            for ( c = 0; c < 3; c++){
                printf("%3d | ", matriz[a][b][c]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
    
}