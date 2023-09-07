#include <stdio.h>

int num[3][4] = {
    { 1, 2, 3, 4},
    { 5, 6, 7, 8},
    { 9, 10, 11, 12}
    };

int main(){
    
    for(int lin = 0; lin < 3; lin++) 
    {
        for(int col = 0; col < 4; col++) 
        {
    		printf("Mat[%d][%d]: %d\n", lin, col, num[lin][col]);
    	}
    }

    int *p = (int *)num;

    printf("\n");
    
    for(int i = 0; i < 3 * 4; i++)
    {
        printf("P [%i]: % d\n", i, p[i]);
    }
    

    
return 0;
}
