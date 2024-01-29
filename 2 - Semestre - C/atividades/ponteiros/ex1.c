#include <stdio.h>

void main(){
    int i = 5, *p;
    p = &i;
    printf("%p %d %d %d %d\n", p, *p+2, **&p, 3**p, **&p+4);
   /* int i=3, j=5;
    int *p, *q;
    p = &i;
    q = &j;

    printf("p == &i = %d\n", (p == &i));
    printf("*p - *q = %d\n", (*p - *q));
    printf("**&p = %d\n", **&p);
    printf("3* - *p/(*q) + 7 = %d\n", (3* - *p/(*q) + 7));
    */
}