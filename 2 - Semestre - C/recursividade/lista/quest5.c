/*

*/

#include <stdio.h>

int calc_MMC(int x, int y, int z, int w){
    if (w<=z){
        if (x%w == 0 && y%w == 0)
            return w;
        return calc_MMC(x,y,z,w+1);
    }
    return 0;
}

int MMC(int x, int y){
    if(x>y)
        return calc_MMC(x, y, y, 2);
    return calc_MMC(x, y, x, 2);
}

int main(){
    int x = 55, y = 50;

    printf("\n\nMENOR MULTIPLICADO COMUM ENTRE %d e %d : %d\n\n", x, y, MMC(x, y));

}