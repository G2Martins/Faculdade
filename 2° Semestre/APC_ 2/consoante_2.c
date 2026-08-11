#include <stdio.h>

char localizarConsoante (char *p, char *endConsoante){
  
  while (*p != '\0') {
    switch (*p){
      case 'a' : case 'A' : 
      case 'e' : case 'E' :
      case 'i' : case 'I' :
      case 'o' : case 'O' :
      case 'u' : case 'U' : 
      break;
      default :endConsoante = p;
    }
    p++;
   }

  if (endConsoante == NULL){
    return 0;
  } else {
    return *endConsoante;
  }
}

int main() {
  
  char string[20] = "";
  printf("Insira uma palavra: ");
  scanf("%s", string);
  char *endConsoante = NULL;
  char *p = string;

  char ultimaConsoante = localizarConsoante (p, endConsoante);

  if (ultimaConsoante == 0){
    printf("Nao ha consoante na palavra");
  }
  else printf("A ultima consoante da palavra: %c", ultimaConsoante);
  
   return 0;
}