#include <stdio.h>

int main() {
	int rgba = 0x010203FF;
	unsigned char *c = (unsigned char *) &rgba; // c = &rgba
// r = 01
    printf("\nNOTACAO DE PONTEIROS:\n");
    printf("c (&rgba): %u\n", c+3);
    printf("*c - byte 4 - %x (%d)\n", *(c+3), *(c+3));
    printf("\nNOTACAO DE VETORES\n");
    printf("c[3] - %x (%d)\n", c[3], c[3]);
    
// g = 02
    printf("\nNOTACAO DE PONTEIROS\n");
    printf("c (&rgba): %u\n", c+2);
    printf("*c - %x (%d)\n", *(c+2), *(c+2));
    printf("\nNOTACAO DE VETORES\n");
    printf("c[2] - %x (%d)\n", c[2], c[2]);
    
// b = 03
    printf("\nNOTACAO DE PONTEIROS\n");
    printf("c (&rgba): %u\n", c+1);
    printf("*c - %x (%d)\n", *(c+1), *(c+1));
    printf("NOTACAO DE VETORES");
    printf("c[1] - %x (%d)\n", c[1], c[1]);
    
// a = FF (255 em decimal)
    printf("\nNOTACAO DE PONTEIROS\n");
    printf("c (&rgba): %u\n", c);     
    printf("*c - %x (%d)\n", *c, *c);
    printf("\nNOTACAO DE VETORES\n");
    printf("c[0] - %x (%d)\n", c[0], c[0]);
    
    
	return 0;
}
