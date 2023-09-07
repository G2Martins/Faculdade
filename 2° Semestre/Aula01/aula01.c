#include <stdio.h>

int main() {
	
    int a = 65; // escrita (inicialização)
	float b; 
    printf("input b: "); 
    scanf("%f%*c", &b); // escrita
	
    double c = 2.5; // escrita (inicialização)
    char d; 
    printf("input d: "); 
    d = getchar(); // escrita
	printf("a: %d\n", a); // leitura
    
    b > 0 ? printf("true\n") : printf("false\n"); // leitura
    
    printf("c: %f\n", c); // leitura
    d = (char)a; // leitura de a, escrita em d
	
    printf("d: %c\n", d); // leitura
  
    return 0;
}

/*
Inteiro = 2 Bytes

int i, j, k, l;

- &i = 0x100, ocupa os endereços 0x100 e 0x101
- &j = 0x102, ocupa os endereços 0x102 e 0x103
- &k = 0x104, ocupa os endereços 0x104 e 0x105
- &l = 0x106, ocupa os endereços 0x106 e 0x107
*/

/*
int,Float = 4 Bytes ----- double = 8 Bytes

int i; double j; float k; int l;

- &i = 0x100, ocupa os endereços 0x100 a 0x103
- &j = 0x104, ocupa os endereços 0x104 a 0x111
- &k = 0x112, ocupa os endereços 0x112 a 0x115
- &l = 0x116, ocupa os endereços 0x116 a 0x119
*/
