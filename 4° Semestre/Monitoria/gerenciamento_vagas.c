#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#define MAX_VAGAS 10 
#define MAX_MATRICULAS 100

typedef struct matricula {
    char matricula[11];
    int status_Estudante; //1 - estudante, 0 - Não
} Matricula;

int main()                                                                  
{
    Matricula matriculas[MAX_MATRICULAS];
    int vagas[MAX_VAGAS] = {0};
    int i, j, escolha, vaga, plano, matricula_valida;
    char matricula[11];
    int total_matriculas = 0;
    int menuLoop = 1;
    
    do{ 
        sleep(1);
        system("clear || cls");
        printf("             _____  _     _                       _                                        \n");
        printf("             |   __|_|___| |_ ___ _____ ___     _| |___                                    \n");
        printf("             |__   | |_ -|  _| -_|     | .'|   | . | -_|                                   \n");
        printf("             |_____|_|___|_| |___|_|_|_|__,|   |___|___|                                   \n");
        printf("                                                                                           \n");                                                                                                            
        printf("             _____                     _                   _                               \n");
        printf("            |   __|___ ___ ___ ___ ___|_|___ _____ ___ ___| |_ ___                         \n");
        printf("            |  |  | -_|  _| -_|   |  _| | .'|     | -_|   |  _| . |                        \n");
        printf("            |_____|___|_| |___|_|_|___|_|__,|_|_|_|___|_|_|_| |___|                        \n");
        printf("                                                                                           \n");
        printf("              _                _                                       _                   \n");
        printf("            _| |___     __ ___| |_ ___ ___ _ ___ _____ _ _____ ___ ___| |_ ___             \n");
        printf("           | . | -_|  | -_|_ -|  _| .'|  _| | . |   | .'|     | -_|   |  _| . |            \n");
        printf("           |___|___|  |___|___|_| |__,|___|_|___|_|_|__,|_|_|_|___|_|_|_| |___|           \n");
        printf("                                                                                          \n");
        printf("                                                                                          \n");
        printf("                                                                                          \n");
        printf("                              ######################                                      \n");
        printf("                            ##########################                                    \n");
        printf("                            ############################                                  \n");
        printf("                          ######      ####        ########                                \n");
        printf("                          ######      ####          ########                              \n");
        printf("                        ########      ####            ######                              \n");
        printf("                        ##########################################                        \n");
        printf("                      ################################################                    \n");
        printf("                    ##################################################                    \n");
        printf("                    ##################################################                    \n");
        printf("                    ##################################################                    \n");
        printf("                    ##################################################                    \n");
        printf("                    ############  ######################    ##########                    \n");
        printf("                    ##########      ##################        ########                    \n");
        printf("                          ####      ####          ####        ####                        \n");
        printf("                          ######  ######            ######  ######                        \n");
        printf("                            ############            ############                          \n");
        printf("                              ######                  ########                            \n");
        printf("                                                                                          \n");
        printf("                                                                                          \n");
        printf("1. Cadastrar nova matricula                                                              #\n");
        printf("2. Verificar matricula                                                                   #\n");
        printf("3. Remover matricula                                                                     #\n");
        printf("4. Reservar vaga                                                                         #\n");
        printf("5. Liberar vaga                                                                          #\n");
        printf("6. Exibir status das vagas                                                               #\n");
        printf("0. Sair                                                                                  #\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) 
        {
            case 1:

                system("clear || cls");

                printf("     ____                \n");
                printf("  __/  |_ _              \n");
                printf(" |  _     _``-.          \n");
                printf(" '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                        ____                \n");
                printf("                     __/  |_ _              \n");
                printf("  CARREGANDO         |  _     _``-.          \n");
                printf("                     '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                               ____                \n");
                printf("                                            __/  |_ _              \n");
                printf("                        CARREGANDO         |  _     _``-.          \n");
                printf("                                           '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                      ____                \n");
                printf("                                                                   __/  |_ _              \n");
                printf("                                               CARREGANDO          |  _     _``-.          \n");
                printf("                                                                   '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                                            ____                \n");
                printf("                                                                                         __/  |_ _              \n");
                printf("                                                                 CARREGANDO             |  _     _``-.          \n");
                printf("                                                                                        '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");
                
                printf("                                                                                                                     ____                \n");
                printf("                                                                                                                  __/  |_ _              \n");
                printf("                                                                                        CARREGANDO               |  _     _``-.          \n");
                printf("                                                                                                                 '-(_)---(_)--'          \n");
                
                usleep(350000);
                system("clear || cls");
                // Cadastrar nova matrícula
                if (total_matriculas >= MAX_MATRICULAS) {
                    printf("Limite de matriculas atingido.\n");
                    sleep(1);
                } else {
                    printf("Digite a nova matricula (10 digitos): ");
                    scanf("%s", matricula);                              
                    
                    // Verificar se a matrícula já existe
                    matricula_valida = 1; //True
                    for (i = 0; i < total_matriculas; i++) {                
                        if (strcmp(matriculas[i].matricula, matricula) == 0)
                        {
                            matricula_valida = 0; //False
                            printf("Matricula ja cadastrada.\n");
                            sleep(1);
                            break;
                        }
                    }
                    if (matricula_valida) {
                        strcpy(matriculas[total_matriculas].matricula, matricula);
                        printf("O usuario e estudante? (1 para sim, 0 para nao): ");
                        scanf("%d", &matriculas[total_matriculas].status_Estudante);
                        total_matriculas++;
                        printf("Matricula cadastrada com sucesso.\n");
                        sleep(1);
                    }
                }
                break;

            case 2:
                system("clear || cls");

                printf("     ____                \n");
                printf("  __/  |_ _              \n");
                printf(" |  _     _``-.          \n");
                printf(" '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                        ____                \n");
                printf("                     __/  |_ _              \n");
                printf("  CARREGANDO         |  _     _``-.          \n");
                printf("                     '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                               ____                \n");
                printf("                                            __/  |_ _              \n");
                printf("                        CARREGANDO         |  _     _``-.          \n");
                printf("                                           '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                      ____                \n");
                printf("                                                                   __/  |_ _              \n");
                printf("                                               CARREGANDO          |  _     _``-.          \n");
                printf("                                                                   '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                                            ____                \n");
                printf("                                                                                         __/  |_ _              \n");
                printf("                                                                 CARREGANDO             |  _     _``-.          \n");
                printf("                                                                                        '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");
                
                printf("                                                                                                                     ____                \n");
                printf("                                                                                                                  __/  |_ _              \n");
                printf("                                                                                        CARREGANDO               |  _     _``-.          \n");
                printf("                                                                                                                 '-(_)---(_)--'          \n");
                
                usleep(350000);
                system("clear || cls");

                // Verificar matrícula
                printf("Digite a matricula (10 digitos): ");
                scanf("%s", matricula);
                matricula_valida = 0;

                for (i = 0; i < total_matriculas; i++) {
                    if (strcmp(matriculas[i].matricula, matricula) == 0) {
                        matricula_valida = 1;
                        printf("Matricula %s encontrada.\n", matricula);
                        printf("Status: %sum estudante.\n", matriculas[i].status_Estudante ? "" : "nao ");
                        sleep(10);
                        break;
                    }
                }
                if (!matricula_valida) {
                    printf("Matricula %s nao encontrada.\n", matricula);
                    sleep(2);
                }
                break;


            case 3:

                system("clear || cls");

                printf("     ____                \n");
                printf("  __/  |_ _              \n");
                printf(" |  _     _``-.          \n");
                printf(" '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                        ____                \n");
                printf("                     __/  |_ _              \n");
                printf("  CARREGANDO         |  _     _``-.          \n");
                printf("                     '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                               ____                \n");
                printf("                                            __/  |_ _              \n");
                printf("                        CARREGANDO         |  _     _``-.          \n");
                printf("                                           '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                      ____                \n");
                printf("                                                                   __/  |_ _              \n");
                printf("                                               CARREGANDO          |  _     _``-.          \n");
                printf("                                                                   '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                                            ____                \n");
                printf("                                                                                         __/  |_ _              \n");
                printf("                                                                 CARREGANDO             |  _     _``-.          \n");
                printf("                                                                                        '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");
                
                printf("                                                                                                                     ____                \n");
                printf("                                                                                                                  __/  |_ _              \n");
                printf("                                                                                        CARREGANDO               |  _     _``-.          \n");
                printf("                                                                                                                 '-(_)---(_)--'          \n");
                
                usleep(350000);
                
                // Remover matrícula
                system("clear || cls");
                printf("+--------------------+\n");
                for (i = 0; i < total_matriculas; i++) {
                    printf("+- Matricula: %s -+\n", matriculas[i].matricula);
                }
                printf("+- Digite a matricula a ser removida (10 digitos): ");
                scanf("%s", matricula);
                matricula_valida = 0;

                for (i = 0; i < total_matriculas; i++) {
                    if (strcmp(matriculas[i].matricula, matricula) == 0) {
                        matricula_valida = 1;
                        // Remover a matrícula deslocando os elementos              
                        for (j = i; j < total_matriculas - 1; j++) {                    
                            matriculas[j] = matriculas[j + 1];
                        }
                        total_matriculas--;
                        printf("Matricula %s removida com sucesso.\n", matricula);
                        sleep(1);
                        break;
                    }
                }
                if (!matricula_valida) {
                    printf("Matricula nao encontrada.\n");
                    sleep(1); 
                }
                break;

            case 4:

                system("clear || cls");

                printf("     ____                \n");
                printf("  __/  |_ _              \n");
                printf(" |  _     _``-.          \n");
                printf(" '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                        ____                \n");
                printf("                     __/  |_ _              \n");
                printf("  CARREGANDO         |  _     _``-.          \n");
                printf("                     '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                               ____                \n");
                printf("                                            __/  |_ _              \n");
                printf("                        CARREGANDO         |  _     _``-.          \n");
                printf("                                           '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                      ____                \n");
                printf("                                                                   __/  |_ _              \n");
                printf("                                               CARREGANDO          |  _     _``-.          \n");
                printf("                                                                   '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                                            ____                \n");
                printf("                                                                                         __/  |_ _              \n");
                printf("                                                                 CARREGANDO             |  _     _``-.          \n");
                printf("                                                                                        '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");
                
                printf("                                                                                                                     ____                \n");
                printf("                                                                                                                  __/  |_ _              \n");
                printf("                                                                                        CARREGANDO               |  _     _``-.          \n");
                printf("                                                                                                                 '-(_)---(_)--'          \n");
                
                usleep(350000);
                system("clear || cls");
                // Reservar vaga
                printf("Voce tem uma matricula? (1 para sim, 0 para nao): ");
                int tem_matricula;
                scanf("%d", &tem_matricula);

                if (tem_matricula) {
                    // Se tiver matrícula
                    printf("Digite a matricula (10 digitos): ");
                    scanf("%s", matricula);
                    matricula_valida = 0;

                    for (i = 0; i < total_matriculas; i++) {
                        if (strcmp(matriculas[i].matricula, matricula) == 0) 
                        {
                            matricula_valida = 1;
                            printf("\n");
                            printf("+-----------------------------------------+\n");
                            printf("+-        Escolha o plano                -+\n");
                            printf("+- Mensal Estudante: R$ 50,00            -+\n");
                            printf("+- Mensal Funcionarios: R$ 75,00        -+\n");
                            printf("+- Rotativo estudante: R$ 5,00           -+\n");
                            printf("+- Rotativo Funcionarios: R$ 7,00       -+\n");
                            printf("+- 1. Mensal (Estudante/Funcionario)     -+\n");
                            printf("+- 2. Rotativo (Estudante/Funcionario)   -+\n");
                            printf("+- Escolha: ");
                            scanf("%d", &plano);

                            printf("\nVagas disponiveis: ");
                            for (j = 0; j < MAX_VAGAS; j++) {
                                if (vagas[j] == 0) {
                                    printf("%d ", j + 1);
                                }
                            }

                            printf("\nEscolha uma vaga: ");
                            scanf("%d", &vaga);

                            if (vaga < 1 || vaga > MAX_VAGAS || vagas[vaga - 1] == 1) {
                                printf("Vaga invalida ou ja ocupada.\n");
                            } else {
                                vagas[vaga - 1] = 1;
                                printf("\nVaga %d reservada com sucesso. ", vaga);

                                if (plano == 1) {
                                    printf("Valor a pagar: %d reais.\n", matriculas[i].status_Estudante ? 50 : 75);
                                    sleep(1);
                                } else {
                                    printf("Valor a pagar: %d reais.\n", matriculas[i].status_Estudante ? 5 : 7);
                                    sleep(1);
                                }
                            }
                            break;
                        }
                    }

                    if (!matricula_valida) {
                        printf("Matricula nao encontrada.\n");
                    }
                } else {
                    // Se não tiver matrícula, permitir a escolha de uma vaga sem cobrança
                    printf("\nVagas disponiveis: ");
                    for (j = 0; j < MAX_VAGAS; j++) {
                        if (vagas[j] == 0) {
                            printf("%d ", j + 1);
                        }
                    }

                    printf("\nEscolha uma vaga: ");
                    scanf("%d", &vaga);

                    if (vaga < 1 || vaga > MAX_VAGAS || vagas[vaga - 1] == 1) {
                        printf("\nVaga invalida ou ja ocupada.\n");
                        sleep(1);
                    } else {
                        vagas[vaga - 1] = 1;
                        printf("\nVaga %d ocupada com sucesso!! \nValor a pagar R$ 10,00 \n", vaga);
                        sleep(1);
                    }
                }
            break;


            case 5:
                system("clear || cls");

                printf("     ____                \n");
                printf("  __/  |_ _              \n");
                printf(" |  _     _``-.          \n");
                printf(" '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                        ____                \n");
                printf("                     __/  |_ _              \n");
                printf("  CARREGANDO         |  _     _``-.          \n");
                printf("                     '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                               ____                \n");
                printf("                                            __/  |_ _              \n");
                printf("                        CARREGANDO         |  _     _``-.          \n");
                printf("                                           '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                      ____                \n");
                printf("                                                                   __/  |_ _              \n");
                printf("                                               CARREGANDO          |  _     _``-.          \n");
                printf("                                                                   '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                                            ____                \n");
                printf("                                                                                         __/  |_ _              \n");
                printf("                                                                 CARREGANDO             |  _     _``-.          \n");
                printf("                                                                                        '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");
                
                printf("                                                                                                                     ____                \n");
                printf("                                                                                                                  __/  |_ _              \n");
                printf("                                                                                        CARREGANDO               |  _     _``-.          \n");
                printf("                                                                                                                 '-(_)---(_)--'          \n");
                
                usleep(350000);
                system("clear || cls");
                // Liberar vaga
                for (i = 0; i < MAX_VAGAS; i++) {
                    printf("Vaga %d: %s\n", i + 1, vagas[i] ? "Ocupada" : "Disponivel");
                }
                printf("Escolha uma vaga para liberar (1-%d): ", MAX_VAGAS);
                scanf("%d", &vaga);
                if (vaga < 1 || vaga > MAX_VAGAS || vagas[vaga - 1] == 0) {
                    printf("Vaga invalida ou ja esta disponivel.\n");
                    sleep(1);
                } else {
                    vagas[vaga - 1] = 0;
                    printf("Vaga %d liberada com sucesso.\n", vaga);
                    sleep(1);
                }
                break;

            case 6:
                system("clear || cls");

                printf("     ____                \n");
                printf("  __/  |_ _              \n");
                printf(" |  _     _``-.          \n");
                printf(" '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                        ____                \n");
                printf("                     __/  |_ _              \n");
                printf("  CARREGANDO         |  _     _``-.          \n");
                printf("                     '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                               ____                \n");
                printf("                                            __/  |_ _              \n");
                printf("                        CARREGANDO         |  _     _``-.          \n");
                printf("                                           '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                      ____                \n");
                printf("                                                                   __/  |_ _              \n");
                printf("                                               CARREGANDO          |  _     _``-.          \n");
                printf("                                                                   '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                                            ____                \n");
                printf("                                                                                         __/  |_ _              \n");
                printf("                                                                 CARREGANDO             |  _     _``-.          \n");
                printf("                                                                                        '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");
                
                printf("                                                                                                                     ____                \n");
                printf("                                                                                                                  __/  |_ _              \n");
                printf("                                                                                        CARREGANDO               |  _     _``-.          \n");
                printf("                                                                                                                 '-(_)---(_)--'          \n");
                
                usleep(350000);
                system("clear || cls");
                // Exibir status das vagas
                printf("Status das vagas:\n");
                for (i = 0; i < MAX_VAGAS; i++) {
                    printf("Vaga %d: %s\n", i + 1, vagas[i] ? "Ocupada" : "Disponivel");
                }
                sleep(10);
                break;
                
            case 0:
                system("clear || cls");

                printf("     ____                \n");
                printf("  __/  |_ _              \n");
                printf(" |  _     _``-.          \n");
                printf(" '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                        ____                \n");
                printf("                     __/  |_ _              \n");
                printf("  CARREGANDO         |  _     _``-.          \n");
                printf("                     '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                               ____                \n");
                printf("                                            __/  |_ _              \n");
                printf("                        CARREGANDO         |  _     _``-.          \n");
                printf("                                           '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                      ____                \n");
                printf("                                                                   __/  |_ _              \n");
                printf("                                               CARREGANDO          |  _     _``-.          \n");
                printf("                                                                   '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                                            ____                \n");
                printf("                                                                                         __/  |_ _              \n");
                printf("                                                                 CARREGANDO             |  _     _``-.          \n");
                printf("                                                                                        '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");
                
                printf("                                                                                                                     ____                \n");
                printf("                                                                                                                  __/  |_ _              \n");
                printf("                                                                                        CARREGANDO               |  _     _``-.          \n");
                printf("                                                                                                                 '-(_)---(_)--'          \n");
                
                usleep(350000);
                system("clear || cls");
                printf("Saindo do sistema...\n");
                menuLoop = 0;
                sleep(1);
                system("clear || cls");
                return 0;

            default:
                system("clear || cls");

                printf("     ____                \n");
                printf("  __/  |_ _              \n");
                printf(" |  _     _``-.          \n");
                printf(" '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                        ____                \n");
                printf("                     __/  |_ _              \n");
                printf("  CARREGANDO         |  _     _``-.          \n");
                printf("                     '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                               ____                \n");
                printf("                                            __/  |_ _              \n");
                printf("                        CARREGANDO         |  _     _``-.          \n");
                printf("                                           '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                      ____                \n");
                printf("                                                                   __/  |_ _              \n");
                printf("                                               CARREGANDO          |  _     _``-.          \n");
                printf("                                                                   '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");

                printf("                                                                                            ____                \n");
                printf("                                                                                         __/  |_ _              \n");
                printf("                                                                 CARREGANDO             |  _     _``-.          \n");
                printf("                                                                                        '-(_)---(_)--'          \n");

                usleep(350000);
                system("clear || cls");
                
                printf("                                                                                                                     ____                \n");
                printf("                                                                                                                  __/  |_ _              \n");
                printf("                                                                                        CARREGANDO               |  _     _``-.          \n");
                printf("                                                                                                                 '-(_)---(_)--'          \n");
                
                usleep(350000);
                system("clear || cls");
                printf("Opção invalida.\n");
                sleep(1);
                break;
        }
    }while(menuLoop != 0);

    return 0;
}
