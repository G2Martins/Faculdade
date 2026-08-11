#include <stdio.h>
void imprimirDiagnostico(int idade, int concentracaoGlicose, float imc) {    
    if (concentracaoGlicose < 120) {
        if (idade > 40) { printf("Não tem diabetes. IMPORTANTE: cuide da sua saúde por estar acima dos 40 anos"); }
        else printf("Você não corre risco de diabetes");
    } else if (concentracaoGlicose > 119 && concentracaoGlicose < 126 && imc > 27) {
        printf("Você tem uma probabilidade de adquirir diabetes. Procure um médico");
    } else {
        printf("É altamente recomendável que você procure um médico para avaliação");
    }
}
int main() {
    int idade, concentracaoGlicose;
    float imc;
    scanf("%d", &idade);
    scanf("%d", &concentracaoGlicose);
    scanf("%f", &imc);
    imprimirDiagnostico(idade, concentracaoGlicose, imc);
    return 0;
}