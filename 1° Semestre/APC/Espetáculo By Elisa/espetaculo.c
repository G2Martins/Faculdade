#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int x = 1;         // Variável destinada a organizar os loopings do jogo.
int deu_certo = 1; // Váriavel destinada a conferir os "scanf"

int main()
{
    system("cls"); // limpar a tela inicial

    // apresentação do titulo inicial de forma dinâmica utilizando o usleep.
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                                                 ╱                                                                                    \n");
    printf("                                                                                 ╲                                                                                    \n"); // detalhes
    printf("                                                                                 ╱                                                                                    \n"); // detalhes
    printf("                                                                                 ╲                                                                                    \n"); // detalhes
    printf("                                                                                 ╱                                                                                    \n"); // detalhes
    printf("                                                                                 ╲                                                                                    \n"); // detalhes
    printf("                                                                                 ╱                                                                                    \n");

    printf("                                                                                 ╲                                                                                    \n"); // titulo
    printf("                                                                                 ╱                                                                                    \n"); // titulo
    printf("                                                                                 ╲                                                                                    \n"); // titulo
    printf("                                                                                 ╱                                                                                    \n"); // titulo
    printf("                                                                                 ╲                                                                                    \n"); // titulo
    printf("                                                                                 ╱                                                                                    \n");

    printf("                                                                                 ╲                                                                                    \n"); // subtitulo
    printf("                                                                                 ╱                                                                                    \n");
    printf("                                                                                 ╲                                                                                    \n");
    printf("__________________________________________________________________________________╲___________________________________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                                                ╱ ╱                                                                                   \n");
    printf("                                                                                ╲ ╲                                                                                   \n"); // detalhes
    printf("                                                                                ╱ ╱                                                                                   \n"); // detalhes
    printf("                                                                                ╲ ╲                                                                                   \n"); // detalhes
    printf("                                                                                ╱ ╱                                                                                   \n"); // detalhes
    printf("                                                                                ╲ ╲                                                                                   \n"); // detalhes
    printf("                                                                                ╱ ╱                                                                                   \n");

    printf("                                                                                ╲⧫╲                                                                                   \n"); // titulo
    printf("                                                                                ╱⧫╱                                                                                   \n"); // titulo
    printf("                                                                                ╲ ╲                                                                                   \n"); // titulo
    printf("                                                                                ╱⧫╱                                                                                   \n"); // titulo
    printf("                                                                                ╲ ╲                                                                                   \n"); // titulo
    printf("                                                                                ╱ ╱                                                                                   \n");

    printf("                                                                                ╲ ╲                                                                                   \n"); // subtitulo
    printf("                                                                                ╱ ╱                                                                                   \n");
    printf("                                                                                ╲ ╲                                                                                   \n");
    printf("_________________________________________________________________________________╲ ╲__________________________________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                                               ╱   ╱                                                                                  \n");
    printf("                                                                               ╲   ╲                                                                                  \n"); // detalhes
    printf("                                                                               ╱   ╱                                                                                  \n"); // detalhes
    printf("                                                                               ╲   ╲                                                                                  \n"); // detalhes
    printf("                                                                               ╱   ╱                                                                                  \n"); // detalhes
    printf("                                                                               ╲   ╲                                                                                  \n"); // detalhes
    printf("                                                                               ╱   ╱                                                                                  \n");

    printf("                                                                               ╲ ⧫ ╲                                                                                  \n"); // titulo
    printf("                                                                               ╱ ⧫ ╱                                                                                  \n"); // titulo
    printf("                                                                               ╲⧫ ⧫╲                                                                                  \n"); // titulo
    printf("                                                                               ╱ ⧫ ╱                                                                                  \n"); // titulo
    printf("                                                                               ╲⧫ ⧫╲                                                                                  \n"); // titulo

    printf("                                                                               ╱   ╱                                                                                  \n");
    printf("                                                                               ╲   ╲                                                                                  \n"); // subtitulo
    printf("                                                                               ╱   ╱                                                                                  \n");
    printf("                                                                               ╲   ╲                                                                                  \n");
    printf("________________________________________________________________________________╲   ╲_________________________________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                                              ╱     ╱                                                                                 \n");
    printf("                                                                              ╲     ╲                                                                                 \n"); // detalhes
    printf("                                                                              ╱     ╱                                                                                 \n"); // detalhes
    printf("                                                                              ╲     ╲                                                                                 \n"); // detalhes
    printf("                                                                              ╱     ╱                                                                                 \n"); // detalhes
    printf("                                                                              ╲     ╲                                                                                 \n"); // detalhes
    printf("                                                                              ╱     ╱                                                                                 \n");

    printf("                                                                              ╲⧫ ⧫ ⧫╲                                                                                 \n"); // titulo
    printf("                                                                              ╱  ⧫  ╱                                                                                 \n"); // titulo
    printf("                                                                              ╲ ⧫ ⧫ ╲                                                                                 \n"); // titulo
    printf("                                                                              ╱  ⧫  ╱                                                                                 \n"); // titulo
    printf("                                                                              ╲ ⧫ ⧫ ╲                                                                                 \n"); // titulo

    printf("                                                                              ╱     ╱                                                                                 \n");
    printf("                                                                              ╲     ╲                                                                                 \n"); // subtitulo
    printf("                                                                              ╱     ╱                                                                                 \n");
    printf("                                                                              ╲     ╲                                                                                 \n");
    printf("_______________________________________________________________________________╲     ╲________________________________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                                             ╱       ╱                                                                                \n");
    printf("                                                                             ╲       ╲                                                                                \n"); // detalhes
    printf("                                                                             ╱       ╱                                                                                \n"); // detalhes
    printf("                                                                             ╲       ╲                                                                                \n"); // detalhes
    printf("                                                                             ╱       ╱                                                                                \n"); // detalhes
    printf("                                                                             ╲       ╲                                                                                \n"); // detalhes
    printf("                                                                             ╱       ╱                                                                                \n");

    printf("                                                                             ╲ ⧫ ⧫ ⧫ ╲                                                                                \n"); // titulo
    printf("                                                                             ╱   ⧫   ╱                                                                                \n"); // titulo
    printf("                                                                             ╲  ⧫ ⧫  ╲                                                                                \n"); // titulo
    printf("                                                                             ╱   ⧫   ╱                                                                                \n"); // titulo
    printf("                                                                             ╲  ⧫ ⧫  ╲                                                                                \n"); // titulo

    printf("                                                                             ╱       ╱                                                                                \n");
    printf("                                                                             ╲       ╲                                                                                \n"); // subtitulo
    printf("                                                                             ╱       ╱                                                                                \n");
    printf("                                                                             ╲       ╲                                                                                \n");
    printf("______________________________________________________________________________╲       ╲_______________________________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                                            ╱         ╱                                                                               \n");
    printf("                                                                            ╲         ╲                                                                               \n"); // detalhes
    printf("                                                                            ╱         ╱                                                                               \n"); // detalhes
    printf("                                                                            ╲         ╲                                                                               \n"); // detalhes
    printf("                                                                            ╱         ╱                                                                               \n"); // detalhes
    printf("                                                                            ╲         ╲                                                                               \n"); // detalhes
    printf("                                                                            ╱         ╱                                                                               \n");

    printf("                                                                            ╲⧫ ⧫ ⧫ ⧫ ⧫╲                                                                               \n"); // titulo
    printf("                                                                            ╱    ⧫    ╱                                                                               \n"); // titulo
    printf("                                                                            ╲   ⧫ ⧫   ╲                                                                               \n"); // titulo
    printf("                                                                            ╱    ⧫    ╱                                                                               \n"); // titulo
    printf("                                                                            ╲   ⧫ ⧫   ╲                                                                               \n"); // titulo

    printf("                                                                            ╱         ╱                                                                               \n");
    printf("                                                                            ╲         ╲                                                                               \n"); // subtitulo
    printf("                                                                            ╱         ╱                                                                               \n");
    printf("                                                                            ╲         ╲                                                                               \n");
    printf("_____________________________________________________________________________╲         ╲______________________________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                                          ╱             ╱                                                                             \n");
    printf("                                                                          ╲             ╲                                                                             \n"); // detalhes
    printf("                                                                          ╱             ╱                                                                             \n"); // detalhes
    printf("                                                                          ╲             ╲                                                                             \n"); // detalhes
    printf("                                                                          ╱             ╱                                                                             \n"); // detalhes
    printf("                                                                          ╲             ╲                                                                             \n"); // detalhes
    printf("                                                                          ╱             ╱                                                                             \n");

    printf("                                                                          ╲  ⧫ ⧫ ⧫ ⧫ ⧫  ╲                                                                             \n"); // titulo
    printf("                                                                          ╱      ⧫      ╱                                                                             \n"); // titulo
    printf("                                                                          ╲     ⧫ ⧫     ╲                                                                             \n"); // titulo
    printf("                                                                          ╱      ⧫      ╱                                                                             \n"); // titulo
    printf("                                                                          ╲     ⧫ ⧫     ╲                                                                             \n"); // titulo

    printf("                                                                          ╱             ╱                                                                             \n");
    printf("                                                                          ╲             ╲                                                                             \n"); // subtitulo
    printf("                                                                          ╱             ╱                                                                             \n");
    printf("                                                                          ╲             ╲                                                                             \n");
    printf("___________________________________________________________________________╲             ╲____________________________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                                        ╱                 ╱                                                                           \n");
    printf("                                                                        ╲                 ╲                                                                           \n"); // detalhes
    printf("                                                                        ╱                 ╱                                                                           \n"); // detalhes
    printf("                                                                        ╲                 ╲                                                                           \n"); // detalhes
    printf("                                                                        ╱                 ╱                                                                           \n"); // detalhes
    printf("                                                                        ╲                 ╲                                                                           \n"); // detalhes
    printf("                                                                        ╱                 ╱                                                                           \n");

    printf("                                                                        ╲ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ╲                                                                           \n"); // titulo
    printf("                                                                        ╱        ⧫       ⧫╱                                                                           \n"); // titulo
    printf("                                                                        ╲ ⧫     ⧫ ⧫     ⧫ ╲                                                                           \n"); // titulo
    printf("                                                                        ╱        ⧫       ⧫╱                                                                           \n"); // titulo
    printf("                                                                        ╲ ⧫     ⧫ ⧫       ╲                                                                           \n"); // titulo

    printf("                                                                        ╱                 ╱                                                                           \n");
    printf("                                                                        ╲                 ╲                                                                           \n"); // subtitulo
    printf("                                                                        ╱                 ╱                                                                           \n");
    printf("                                                                        ╲                 ╲                                                                           \n");
    printf("_________________________________________________________________________╲                 ╲__________________________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                                      ╱                     ╱                                                                         \n");
    printf("                                                                      ╲                     ╲                                                                         \n"); // detalhes
    printf("                                                                      ╱                     ╱                                                                         \n"); // detalhes
    printf("                                                                      ╲                     ╲                                                                         \n"); // detalhes
    printf("                                                                      ╱                     ╱                                                                         \n"); // detalhes
    printf("                                                                      ╲                     ╲                                                                         \n"); // detalhes
    printf("                                                                      ╱                     ╱                                                                         \n");

    printf("                                                                      ╲ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ╲                                                                         \n"); // titulo
    printf("                                                                      ╱          ⧫       ⧫ ⧫╱                                                                         \n"); // titulo
    printf("                                                                      ╲ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ╲                                                                         \n"); // titulo
    printf("                                                                      ╱          ⧫       ⧫ ⧫╱                                                                         \n"); // titulo
    printf("                                                                      ╲ ⧫ ⧫     ⧫ ⧫       ⧫ ╲                                                                         \n"); // titulo

    printf("                                                                      ╱                     ╱                                                                         \n");
    printf("                                                                      ╲                     ╲                                                                         \n"); // subtitulo
    printf("                                                                      ╱                     ╱                                                                         \n");
    printf("                                                                      ╲                     ╲                                                                         \n");
    printf("_______________________________________________________________________╲                     ╲________________________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                                    ╱                         ╱                                                                       \n");
    printf("                                                                    ╲                         ╲                                                                       \n"); // detalhes
    printf("                                                                    ╱                         ╱                                                                       \n"); // detalhes
    printf("                                                                    ╲                         ╲                                                                       \n"); // detalhes
    printf("                                                                    ╱                         ╱                                                                       \n"); // detalhes
    printf("                                                                    ╲                         ╲                                                                       \n"); // detalhes
    printf("                                                                    ╱                         ╱                                                                       \n");

    printf("                                                                    ╲ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ╲                                                                       \n"); // titulo
    printf("                                                                    ╱⧫           ⧫       ⧫ ⧫  ╱                                                                       \n"); // titulo
    printf("                                                                    ╲ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ╲                                                                       \n"); // titulo
    printf("                                                                    ╱⧫           ⧫       ⧫ ⧫  ╱                                                                       \n"); // titulo
    printf("                                                                    ╲ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫   ╲                                                                       \n"); // titulo

    printf("                                                                    ╱                         ╱                                                                       \n");
    printf("                                                                    ╲                         ╲                                                                       \n"); // subtitulo
    printf("                                                                    ╱                         ╱                                                                       \n");
    printf("                                                                    ╲                         ╲                                                                       \n");
    printf("_____________________________________________________________________╲                         ╲______________________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                                  ╱                             ╱                                                                     \n");
    printf("                                                                  ╲                             ╲                                                                     \n"); // detalhes
    printf("                                                                  ╱                             ╱                                                                     \n"); // detalhes
    printf("                                                                  ╲                             ╲                                                                     \n"); // detalhes
    printf("                                                                  ╱                             ╱                                                                     \n"); // detalhes
    printf("                                                                  ╲                             ╲                                                                     \n"); // detalhes
    printf("                                                                  ╱                             ╱                                                                     \n");

    printf("                                                                  ╲ ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ╲                                                                     \n"); // titulo
    printf("                                                                  ╱⧫ ⧫           ⧫       ⧫ ⧫    ╱                                                                     \n"); // titulo
    printf("                                                                  ╲ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ╲                                                                     \n"); // titulo
    printf("                                                                  ╱⧫ ⧫           ⧫       ⧫ ⧫    ╱                                                                     \n"); // titulo
    printf("                                                                  ╲ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫     ╲                                                                     \n"); // titulo

    printf("                                                                  ╱                             ╱                                                                     \n");
    printf("                                                                  ╲                             ╲                                                                     \n"); // subtitulo
    printf("                                                                  ╱                             ╱                                                                     \n");
    printf("                                                                  ╲                             ╲                                                                     \n");
    printf("___________________________________________________________________╲                             ╲____________________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                                ╱                                 ╱                                                                   \n");
    printf("                                                                ╲                                 ╲                                                                   \n"); // detalhes
    printf("                                                                ╱                                 ╱                                                                   \n"); // detalhes
    printf("                                                                ╲                                 ╲                                                                   \n"); // detalhes
    printf("                                                                ╱                                 ╱                                                                   \n"); // detalhes
    printf("                                                                ╲                                 ╲                                                                   \n"); // detalhes
    printf("                                                                ╱                                 ╱                                                                   \n");

    printf("                                                                ╲   ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ╲                                                                   \n"); // titulo
    printf("                                                                ╱  ⧫ ⧫           ⧫       ⧫ ⧫     ⧫╱                                                                   \n"); // titulo
    printf("                                                                ╲ ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ╲                                                                   \n"); // titulo
    printf("                                                                ╱  ⧫ ⧫           ⧫       ⧫ ⧫     ⧫╱                                                                   \n"); // titulo
    printf("                                                                ╲   ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ╲                                                                   \n"); // titulo

    printf("                                                                ╱                                 ╱                                                                   \n");
    printf("                                                                ╲                                 ╲                                                                   \n"); // subtitulo
    printf("                                                                ╱                                 ╱                                                                   \n");
    printf("                                                                ╲                                 ╲                                                                   \n");
    printf("_________________________________________________________________╲                                 ╲__________________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                              ╱                                     ╱                                                                 \n");
    printf("                                                              ╲                                     ╲                                                                 \n"); // detalhes
    printf("                                                              ╱                                     ╱                                                                 \n"); // detalhes
    printf("                                                              ╲                                     ╲                                                                 \n"); // detalhes
    printf("                                                              ╱                                     ╱                                                                 \n"); // detalhes
    printf("                                                              ╲                                     ╲                                                                 \n"); // detalhes
    printf("                                                              ╱                                     ╱                                                                 \n");

    printf("                                                              ╲     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫ ╲                                                                 \n"); // titulo
    printf("                                                              ╱⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫╱                                                                 \n"); // titulo
    printf("                                                              ╲   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ╲                                                                 \n"); // titulo
    printf("                                                              ╱    ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫╱                                                                 \n"); // titulo
    printf("                                                              ╲     ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫ ╲                                                                 \n"); // titulo

    printf("                                                              ╱                                     ╱                                                                 \n");
    printf("                                                              ╲                                     ╲                                                                 \n"); // subtitulo
    printf("                                                              ╱                                     ╱                                                                 \n");
    printf("                                                              ╲                                     ╲                                                                 \n");
    printf("_______________________________________________________________╲                                     ╲_________________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                            ╱                                         ╱                                                               \n");
    printf("                                                            ╲                                         ╲                                                               \n"); // detalhes
    printf("                                                            ╱                                         ╱                                                               \n"); // detalhes
    printf("                                                            ╲                                         ╲                                                               \n"); // detalhes
    printf("                                                            ╱                                         ╱                                                               \n"); // detalhes
    printf("                                                            ╲                                         ╲                                                               \n"); // detalhes
    printf("                                                            ╱                                         ╱                                                               \n");

    printf("                                                            ╲ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ╲                                                               \n"); // titulo
    printf("                                                            ╱⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫  ╱                                                               \n"); // titulo
    printf("                                                            ╲ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ╲                                                               \n"); // titulo
    printf("                                                            ╱      ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫  ╱                                                               \n"); // titulo
    printf("                                                            ╲       ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫   ╲                                                               \n"); // titulo

    printf("                                                            ╱                                         ╱                                                               \n");
    printf("                                                            ╲                                         ╲                                                               \n"); // subtitulo
    printf("                                                            ╱                                         ╱                                                               \n");
    printf("                                                            ╲                                         ╲                                                               \n");
    printf("_____________________________________________________________╲                                         ╲______________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                          ╱                                             ╱                                                             \n");
    printf("                                                          ╲                                             ╲                                                             \n"); // detalhes
    printf("                                                          ╱                                             ╱                                                             \n"); // detalhes
    printf("                                                          ╲                                             ╲                                                             \n"); // detalhes
    printf("                                                          ╱                                             ╱                                                             \n"); // detalhes
    printf("                                                          ╲                                             ╲                                                             \n"); // detalhes
    printf("                                                          ╱                                             ╱                                                             \n");

    printf("                                                          ╲ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ╲                                                             \n"); // titulo
    printf("                                                          ╱  ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫    ╱                                                             \n"); // titulo
    printf("                                                          ╲ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ╲                                                             \n"); // titulo
    printf("                                                          ╱        ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫    ╱                                                             \n"); // titulo
    printf("                                                          ╲         ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫     ╲                                                             \n"); // titulo

    printf("                                                          ╱                                             ╱                                                             \n");
    printf("                                                          ╲                                             ╲                                                             \n"); // subtitulo
    printf("                                                          ╱                                             ╱                                                             \n");
    printf("                                                          ╲                                             ╲                                                             \n");
    printf("___________________________________________________________╲                                             ╲____________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                        ╱                                                 ╱                                                           \n");
    printf("                                                        ╲                                                 ╲                                                           \n"); // detalhes
    printf("                                                        ╱                                                 ╱                                                           \n"); // detalhes
    printf("                                                        ╲                                                 ╲                                                           \n"); // detalhes
    printf("                                                        ╱                                                 ╱                                                           \n"); // detalhes
    printf("                                                        ╲                                                 ╲                                                           \n"); // detalhes
    printf("                                                        ╱                                                 ╱                                                           \n");

    printf("                                                        ╲ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ╲                                                           \n"); // titulo
    printf("                                                        ╱    ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫╱                                                           \n"); // titulo
    printf("                                                        ╲ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ╲                                                           \n"); // titulo
    printf("                                                        ╱⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫╱                                                           \n"); // titulo
    printf("                                                        ╲           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ╲                                                           \n"); // titulo

    printf("                                                        ╱                                                 ╱                                                           \n");
    printf("                                                        ╲                                                 ╲                                                           \n"); // subtitulo
    printf("                                                        ╱                                                 ╱                                                           \n");
    printf("                                                        ╲                                                 ╲                                                           \n");
    printf("_________________________________________________________╲                                                 ╲__________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                      ╱                                                     ╱                                                         \n");
    printf("                                                      ╲                                                     ╲                                                         \n"); // detalhes
    printf("                                                      ╱                                                     ╱                                                         \n"); // detalhes
    printf("                                                      ╲                                                     ╲                                                         \n"); // detalhes
    printf("                                                      ╱                                                     ╱                                                         \n"); // detalhes
    printf("                                                      ╲                                                     ╲                                                         \n"); // detalhes
    printf("                                                      ╱                                                     ╱                                                         \n");

    printf("                                                      ╲ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ╲                                                         \n"); // titulo
    printf("                                                      ╱⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫╱                                                         \n"); // titulo
    printf("                                                      ╲ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ╲                                                         \n"); // titulo
    printf("                                                      ╱⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫╱                                                         \n"); // titulo
    printf("                                                      ╲ ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ╲                                                         \n"); // titulo

    printf("                                                      ╱                                                     ╱                                                         \n");
    printf("                                                      ╲                                                     ╲                                                         \n"); // subtitulo
    printf("                                                      ╱                                                     ╱                                                         \n");
    printf("                                                      ╲                                                     ╲                                                         \n");
    printf("_______________________________________________________╲                                                     ╲________________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                    ╱                                                         ╱                                                       \n");
    printf("                                                    ╲                                                         ╲                                                       \n"); // detalhes
    printf("                                                    ╱                                                         ╱                                                       \n"); // detalhes
    printf("                                                    ╲                                                         ╲                                                       \n"); // detalhes
    printf("                                                    ╱                                                         ╱                                                       \n"); // detalhes
    printf("                                                    ╲                                                         ╲                                                       \n"); // detalhes
    printf("                                                    ╱                                                         ╱                                                       \n");

    printf("                                                    ╲ ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ╲                                                       \n"); // titulo
    printf("                                                    ╱⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫  ╱                                                       \n"); // titulo
    printf("                                                    ╲ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫   ╲                                                       \n"); // titulo
    printf("                                                    ╱  ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫  ╱                                                       \n"); // titulo
    printf("                                                    ╲   ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ╲                                                       \n"); // titulo

    printf("                                                    ╱                                                         ╱                                                       \n");
    printf("                                                    ╲                                                         ╲                                                       \n"); // subtitulo
    printf("                                                    ╱                                                         ╱                                                       \n");
    printf("                                                    ╲                                                         ╲                                                       \n");
    printf("_____________________________________________________╲                                                         ╲______________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                  ╱                                                             ╱                                                     \n");
    printf("                                                  ╲                                                             ╲                                                     \n"); // detalhes
    printf("                                                  ╱                                                             ╱                                                     \n"); // detalhes
    printf("                                                  ╲                                                             ╲                                                     \n"); // detalhes
    printf("                                                  ╱                                                             ╱                                                     \n"); // detalhes
    printf("                                                  ╲                                                             ╲                                                     \n"); // detalhes
    printf("                                                  ╱                                                             ╱                                                     \n");

    printf("                                                  ╲   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ╲                                                     \n"); // titulo
    printf("                                                  ╱  ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫    ╱                                                     \n"); // titulo
    printf("                                                  ╲   ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫     ╲                                                     \n"); // titulo
    printf("                                                  ╱    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫    ╱                                                     \n"); // titulo
    printf("                                                  ╲     ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ╲                                                     \n"); // titulo

    printf("                                                  ╱                                                             ╱                                                     \n");
    printf("                                                  ╲                                                             ╲                                                     \n"); // subtitulo
    printf("                                                  ╱                                                             ╱                                                     \n");
    printf("                                                  ╲                                                             ╲                                                     \n");
    printf("___________________________________________________╲                                                             ╲____________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                                ╱                                                                 ╱                                                   \n");
    printf("                                                ╲                                                                 ╲                                                   \n"); // detalhes
    printf("                                                ╱                                                                 ╱                                                   \n"); // detalhes
    printf("                                                ╲                                                                 ╲                                                   \n"); // detalhes
    printf("                                                ╱                                                                 ╱                                                   \n"); // detalhes
    printf("                                                ╲                                                                 ╲                                                   \n"); // detalhes
    printf("                                                ╱                                                                 ╱                                                   \n");

    printf("                                                ╲⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ╲                                                   \n"); // titulo
    printf("                                                ╱    ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫╱                                                   \n"); // titulo
    printf("                                                ╲⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫       ╲                                                   \n"); // titulo
    printf("                                                ╱ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫╱                                                   \n"); // titulo
    printf("                                                ╲⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ╲                                                   \n"); // titulo

    printf("                                                ╱                                                                 ╱                                                   \n");
    printf("                                                ╲                                                                 ╲                                                   \n"); // subtitulo
    printf("                                                ╱                                                                 ╱                                                   \n");
    printf("                                                ╲                                                                 ╲                                                   \n");
    printf("_________________________________________________╲                                                                 ╲__________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                              ╱                                                                     ╱                                                 \n");
    printf("                                              ╲                                                                     ╲                                                 \n"); // detalhes
    printf("                                              ╱                                                                     ╱                                                 \n"); // detalhes
    printf("                                              ╲                                                                     ╲                                                 \n"); // detalhes
    printf("                                              ╱                                                                     ╱                                                 \n"); // detalhes
    printf("                                              ╲                                                                     ╲                                                 \n"); // detalhes
    printf("                                              ╱                                                                     ╱                                                 \n");

    printf("                                              ╲⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫ ╲                                                 \n"); // titulo
    printf("                                              ╱      ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫╱                                                 \n"); // titulo
    printf("                                              ╲⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫         ╲                                                 \n"); // titulo
    printf("                                              ╱ ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫╱                                                 \n"); // titulo
    printf("                                              ╲⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫ ╲                                                 \n"); // titulo

    printf("                                              ╱                                                                     ╱                                                 \n");
    printf("                                              ╲                                                                     ╲                                                 \n"); // subtitulo
    printf("                                              ╱                                                                     ╱                                                 \n");
    printf("                                              ╲                                                                     ╲                                                 \n");
    printf("_______________________________________________╲                                                                     ╲________________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                            ╱                                                                         ╱                                               \n");
    printf("                                            ╲                                                                         ╲                                               \n"); // detalhes
    printf("                                            ╱                                                                         ╱                                               \n"); // detalhes
    printf("                                            ╲                                                                         ╲                                               \n"); // detalhes
    printf("                                            ╱                                                                         ╱                                               \n"); // detalhes
    printf("                                            ╲                                                                         ╲                                               \n"); // detalhes
    printf("                                            ╱                                                                         ╱                                               \n");

    printf("                                            ╲⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫   ╲                                               \n"); // titulo
    printf("                                            ╱        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫  ╱                                               \n"); // titulo
    printf("                                            ╲⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ╲                                               \n"); // titulo
    printf("                                            ╱   ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫  ╱                                               \n"); // titulo
    printf("                                            ╲⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫   ╲                                               \n"); // titulo

    printf("                                            ╱                                                                         ╱                                               \n");
    printf("                                            ╲                                                                         ╲                                               \n"); // subtitulo
    printf("                                            ╱                                                                         ╱                                               \n");
    printf("                                            ╲                                                                         ╲                                               \n");
    printf("_____________________________________________╲                                                                         ╲______________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                          ╱                                                                             ╱                                             \n");
    printf("                                          ╲                                                                             ╲                                             \n"); // detalhes
    printf("                                          ╱                                                                             ╱                                             \n"); // detalhes
    printf("                                          ╲                                                                             ╲                                             \n"); // detalhes
    printf("                                          ╱                                                                             ╱                                             \n"); // detalhes
    printf("                                          ╲                                                                             ╲                                             \n"); // detalhes
    printf("                                          ╱                                                                             ╱                                             \n");

    printf("                                          ╲⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ╲                                             \n"); // titulo
    printf("                                          ╱ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫╱                                             \n"); // titulo
    printf("                                          ╲⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ╲                                             \n"); // titulo
    printf("                                          ╱     ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫╱                                             \n"); // titulo
    printf("                                          ╲⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ╲                                             \n"); // titulo

    printf("                                          ╱                                                                             ╱                                             \n");
    printf("                                          ╲                                                                             ╲                                             \n"); // subtitulo
    printf("                                          ╱                                                                             ╱                                             \n");
    printf("                                          ╲                                                                             ╲                                             \n");
    printf("___________________________________________╲                                                                             ╲____________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                        ╱                                                                                 ╱                                           \n");
    printf("                                        ╲                                                                                 ╲                                           \n"); // detalhes
    printf("                                        ╱                                                                                 ╱                                           \n"); // detalhes
    printf("                                        ╲                                                                                 ╲                                           \n"); // detalhes
    printf("                                        ╱                                                                                 ╱                                           \n"); // detalhes
    printf("                                        ╲                                                                                 ╲                                           \n"); // detalhes
    printf("                                        ╱                                                                                 ╱                                           \n");

    printf("                                        ╲  ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ╲                                           \n"); // titulo
    printf("                                        ╱ ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫╱                                           \n"); // titulo
    printf("                                        ╲  ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫ ╲                                           \n"); // titulo
    printf("                                        ╱       ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫╱                                           \n"); // titulo
    printf("                                        ╲  ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ╲                                           \n"); // titulo

    printf("                                        ╱                                                                                 ╱                                           \n");
    printf("                                        ╲                                                                                 ╲                                           \n"); // subtitulo
    printf("                                        ╱                                                                                 ╱                                           \n");
    printf("                                        ╲                                                                                 ╲                                           \n");
    printf("_________________________________________╲                                                                                 ╲__________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                      ╱                                                                                     ╱                                         \n");
    printf("                                      ╲                                                                                     ╲                                         \n"); // detalhes
    printf("                                      ╱                                                                                     ╱                                         \n"); // detalhes
    printf("                                      ╲                                                                                     ╲                                         \n"); // detalhes
    printf("                                      ╱                                                                                     ╱                                         \n"); // detalhes
    printf("                                      ╲                                                                                     ╲                                         \n"); // detalhes
    printf("                                      ╱                                                                                     ╱                                         \n");

    printf("                                      ╲    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫   ╲                                         \n"); // titulo
    printf("                                      ╱   ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫  ╱                                         \n"); // titulo
    printf("                                      ╲    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫   ╲                                         \n"); // titulo
    printf("                                      ╱         ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫  ╱                                         \n"); // titulo
    printf("                                      ╲    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ╲                                         \n"); // titulo

    printf("                                      ╱                                                                                     ╱                                         \n");
    printf("                                      ╲                                                                                     ╲                                         \n"); // subtitulo
    printf("                                      ╱                                                                                     ╱                                         \n");
    printf("                                      ╲                                                                                     ╲                                         \n");
    printf("_______________________________________╲                                                                                     ╲________________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                    ╱                                                                                         ╱                                       \n");
    printf("                                    ╲                                                                                         ╲                                       \n");
    printf("                                    ╱                                                                                         ╱                                       \n"); // detalhes
    printf("                                    ╲ ●                                                                                       ╲                                       \n"); // detalhes
    printf("                                    ╱╱│                                                                                       ╱                                       \n"); // detalhes
    printf("                                    ╲━┛                                                                                       ╲                                       \n"); // detalhes
    printf("                                    ╱                                                                                         ╱                                       \n"); // detalhes

    printf("                                    ╲ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫     ╲                                       \n"); // titulo
    printf("                                    ╱     ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫    ╱                                       \n"); // titulo
    printf("                                    ╲ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫     ╲                                       \n"); // titulo
    printf("                                    ╱           ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫    ╱                                       \n"); // titulo
    printf("                                    ╲ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ╲                                       \n"); // titulo

    printf("                                    ╱                                                                                         ╱                                       \n");
    printf("                                    ╲                                                                                         ╲                                       \n"); // subtitulo
    printf("                                    ╱                                                                                         ╱                                       \n");
    printf("                                    ╲                                                                                         ╲                                       \n");
    printf("_____________________________________╲                                                                                         ╲______________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                  ╱                                                                                             ╱                                     \n");
    printf("                                  ╲                                                                                             ╲                                     \n");
    printf("                                  ╱                                                                                             ╱                                     \n"); // detalhes
    printf("                                  ╲╲  ●                                                                                         ╲                                     \n"); // detalhes
    printf("                                  ╱ ╲╱│                                                                                         ╱                                     \n"); // detalhes
    printf("                                  ╲━━━┛                                                                                         ╲                                     \n"); // detalhes
    printf("                                  ╱                                                                                             ╱                                     \n"); // detalhes

    printf("                                  ╲ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ╲                                     \n"); // titulo
    printf("                                  ╱       ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫╱                                     \n"); // titulo
    printf("                                  ╲ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ╲                                     \n"); // titulo
    printf("                                  ╱             ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫╱                                     \n"); // titulo
    printf("                                  ╲ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ╲                                     \n"); // titulo

    printf("                                  ╱                                                                                             ╱                                     \n");
    printf("                                  ╲                                                                                             ╲                                     \n"); // subtitulo
    printf("                                  ╱                                                                                             ╱                                     \n");
    printf("                                  ╲                                                                                             ╲                                     \n");
    printf("___________________________________╲                                                                                             ╲____________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                                ╱                                                                                                 ╱                                   \n");
    printf("                                ╲                                                                                                 ╲                                   \n");
    printf("                                ╱  ♦                                                                                              ╱                                   \n"); // detalhes
    printf("                                ╲ ╱╲  ●                                                                                           ╲                                   \n"); // detalhes
    printf("                                ╱╱  ╲╱│                                                                                           ╱                                   \n"); // detalhes
    printf("                                ╲━━━━━┛                                                                                           ╲                                   \n"); // detalhes
    printf("                                ╱                                                                                                 ╱                                   \n"); // detalhes

    printf("                                ╲ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫ ╲                                   \n"); // titulo
    printf("                                ╱⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫╱                                   \n"); // titulo
    printf("                                ╲ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ╲                                   \n"); // titulo
    printf("                                ╱⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫╱                                   \n"); // titulo
    printf("                                ╲ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ╲                                   \n"); // titulo

    printf("                                ╱                                                                                                 ╱                                   \n");
    printf("                                ╲                                                                                                 ╲                                   \n"); // subtitulo
    printf("                                ╱                                                                                                 ╱                                   \n");
    printf("                                ╲                                                                                                 ╲                                   \n");
    printf("_________________________________╲                                                                                                 ╲__________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                              ╱                                                                                                     ╱                                 \n");
    printf("                              ╲                                                                                                     ╲                                 \n");
    printf("                              ╱    ♦                                                                                                ╱                                 \n"); // detalhes
    printf("                              ╲●  ╱╲  ●                                                                                             ╲                                 \n"); // detalhes
    printf("                              ╱│╲╱  ╲╱│                                                                                             ╱                                 \n"); // detalhes
    printf("                              ╲┗━━━━━━┛                                                                                             ╲                                 \n"); // detalhes
    printf("                              ╱                                                                                                     ╱                                 \n"); // detalhes

    printf("                              ╲ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫   ╲                                 \n"); // titulo
    printf("                              ╱⧫ ⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫  ╱                                 \n"); // titulo
    printf("                              ╲ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ⧫ ╲                                 \n"); // titulo
    printf("                              ╱⧫ ⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫  ╱                                 \n"); // titulo
    printf("                              ╲ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫   ╲                                 \n"); // titulo

    printf("                              ╱                                                                                                     ╱                                 \n");
    printf("                              ╲                                                                                                     ╲                                 \n"); // subtitulo
    printf("                              ╱                                                                                                     ╱                                 \n");
    printf("                              ╲                                                                                                     ╲                                 \n");
    printf("_______________________________╲                                                                                                     ╲________________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                            ╱                                                                                                         ╱                               \n");
    printf("                            ╲                                                                                                         ╲                               \n");
    printf("                            ╱      ♦                                                                                                  ╱                               \n"); // detalhes
    printf("                            ╲  ●  ╱╲  ●                                                                                               ╲                               \n"); // detalhes
    printf("                            ╱  │╲╱  ╲╱│                                                                                               ╱                               \n"); // detalhes
    printf("                            ╲  ┗━━━━━━┛                                                                                               ╲                               \n"); // detalhes
    printf("                            ╱                                                                                                         ╱                               \n"); // detalhes

    printf("                            ╲   ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫     ╲                               \n"); // titulo
    printf("                            ╱  ⧫ ⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ╱                               \n"); // titulo
    printf("                            ╲ ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ⧫   ╲                               \n"); // titulo
    printf("                            ╱  ⧫ ⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ╱                               \n"); // titulo
    printf("                            ╲   ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫     ╲                               \n"); // titulo

    printf("                            ╱                                                                                                         ╱                               \n");
    printf("                            ╲                                                                                                         ╲                               \n"); // subtitulo
    printf("                            ╱                                                                                                         ╱                               \n");
    printf("                            ╲                                                                                                         ╲                               \n");
    printf("_____________________________╲                                                                                                         ╲______________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                          ╱                                                                                                             ╱                             \n");
    printf("                          ╲                                                                                                             ╲                             \n");
    printf("                          ╱        ♦                                                                                                    ╱                             \n"); // detalhes
    printf("                          ╲    ●  ╱╲  ●                                                                                                 ╲                             \n"); // detalhes
    printf("                          ╱    │╲╱  ╲╱│                                                                                                 ╱                             \n"); // detalhes
    printf("                          ╲    ┗━━━━━━┛                                                                                                 ╲                             \n"); // detalhes
    printf("                          ╱                                                                                                             ╱                             \n"); // detalhes

    printf("                          ╲     ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫      ⧫╲                             \n"); // titulo
    printf("                          ╱    ⧫ ⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ╱                             \n"); // titulo
    printf("                          ╲   ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ⧫    ⧫╲                             \n"); // titulo
    printf("                          ╱    ⧫ ⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ╱                             \n"); // titulo
    printf("                          ╲     ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫      ⧫╲                             \n"); // titulo

    printf("                          ╱                                                                                                             ╱                             \n");
    printf("                          ╲                                                                                                             ╲                             \n"); // subtitulo
    printf("                          ╱                                                                                                             ╱                             \n");
    printf("                          ╲                                                                                                             ╲                             \n");
    printf("___________________________╲                                                                                                             ╲____________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                        ╱                                                                                                                 ╱                           \n");
    printf("                        ╲                                                                                                                 ╲                           \n");
    printf("                        ╱          ♦                                                                                                      ╱                           \n"); // detalhes
    printf("                        ╲      ●  ╱╲  ●                                                                                                   ╲                           \n"); // detalhes
    printf("                        ╱      │╲╱  ╲╱│                                                                                                   ╱                           \n"); // detalhes
    printf("                        ╲      ┗━━━━━━┛                                                                                                   ╲                           \n"); // detalhes
    printf("                        ╱                                                                                                                 ╱                           \n"); // detalhes

    printf("                        ╲       ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫      ⧫  ╲                           \n"); // titulo
    printf("                        ╱      ⧫ ⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫ ╱                           \n"); // titulo
    printf("                        ╲     ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ⧫    ⧫ ⧫╲                           \n"); // titulo
    printf("                        ╱      ⧫ ⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫ ╱                           \n"); // titulo
    printf("                        ╲       ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫      ⧫ ⧫╲                           \n"); // titulo

    printf("                        ╱                                                                                                                 ╱                           \n");
    printf("                        ╲                                                                                                                 ╲                           \n"); // subtitulo
    printf("                        ╱                                                                                                                 ╱                           \n");
    printf("                        ╲                                                                                                                 ╲                           \n");
    printf("_________________________╲                                                                                                                 ╲__________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                        ╱                                                                                                                 ╱                           \n");
    printf("                        ╲                                                                                                                 ╲                           \n");
    printf("                        ╱          ♦                                                                                                      ╱                           \n"); // detalhes
    printf("                        ╲      ●  ╱╲  ●                                                                                                   ╲                           \n"); // detalhes
    printf("                        ╱      │╲╱  ╲╱│                                                                                                   ╱                           \n"); // detalhes
    printf("                        ╲      ┗━━━━━━┛                                                                                                   ╲                           \n"); // detalhes
    printf("                        ╱                                                                                                                 ╱                           \n"); // detalhes

    printf("                        ╲       ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫      ⧫  ╲                           \n"); // titulo
    printf("                        ╱      ⧫ ⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫ ╱                           \n"); // titulo
    printf("                        ╲     ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ⧫    ⧫ ⧫╲                           \n"); // titulo
    printf("                        ╱      ⧫ ⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫ ╱                           \n"); // titulo
    printf("                        ╲       ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫      ⧫ ⧫╲                           \n"); // titulo

    printf("                        ╱                                                                                                                 ╱                           \n");
    printf("                        ╲                                                                                                                 ╲                           \n"); // subtitulo
    printf("                        ╱                                                                                                                 ╱                           \n");
    printf("                        ╲                                                                                                                 ╲                           \n");
    printf("_________________________╲                                                                                                                 ╲__________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                      ╱                                                                                                                     ╱                         \n");
    printf("                      ╲                                                                                                                     ╲                         \n");
    printf("                      ╱            ♦                                                                                                        ╱                         \n"); // detalhes
    printf("                      ╲        ●  ╱╲  ●                                                                                                     ╲                         \n"); // detalhes
    printf("                      ╱        │╲╱  ╲╱│                                                                                                     ╱                         \n"); // detalhes
    printf("                      ╲        ┗━━━━━━┛                                                                                                     ╲                         \n"); // detalhes
    printf("                      ╱                                                                                                                     ╱                         \n"); // detalhes

    printf("                      ╲         ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫      ⧫    ╲                         \n"); // titulo
    printf("                      ╱        ⧫ ⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫   ╱                         \n"); // titulo
    printf("                      ╲       ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ⧫    ⧫ ⧫  ╲                         \n"); // titulo
    printf("                      ╱        ⧫ ⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫   ╱                         \n"); // titulo
    printf("                      ╲         ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫      ⧫ ⧫ ⧫╲                         \n"); // titulo

    printf("                      ╱                                                                                                                     ╱                         \n");
    printf("                      ╲                                                                                                                     ╲                         \n"); // subtitulo
    printf("                      ╱                                                                                                                     ╱                         \n");
    printf("                      ╲                                                                                                                     ╲                         \n");
    printf("_______________________╲                                                                                                                     ╲________________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                    ╱                                                                                                                         ╱                       \n");
    printf("                    ╲                                                                                                                         ╲                       \n");
    printf("                    ╱              ♦                                                                                                          ╱                       \n"); // detalhes
    printf("                    ╲          ●  ╱╲  ●                                                                                                       ╲                       \n"); // detalhes
    printf("                    ╱          │╲╱  ╲╱│                                                                                                       ╱                       \n"); // detalhes
    printf("                    ╲          ┗━━━━━━┛                                                                                                       ╲                       \n"); // detalhes
    printf("                    ╱                                                                                                                         ╱                       \n"); // detalhes

    printf("                    ╲           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫      ⧫      ╲                       \n"); // titulo
    printf("                    ╱⧫         ⧫ ⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫     ╱                       \n"); // titulo
    printf("                    ╲ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ⧫    ⧫ ⧫    ╲                       \n"); // titulo
    printf("                    ╱⧫         ⧫ ⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫     ╱                       \n"); // titulo
    printf("                    ╲           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫      ⧫ ⧫ ⧫ ⧫╲                       \n"); // titulo

    printf("                    ╱                                                                                                                         ╱                       \n");
    printf("                    ╲                                                                                                                         ╲                       \n"); // subtitulo
    printf("                    ╱                                                                                                                         ╱                       \n");
    printf("                    ╲                                                                                                                         ╲                       \n");
    printf("_____________________╲                                                                                                                         ╲______________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                  ╱                                                                                                                             ╱                     \n");
    printf("                  ╲                                                                                                                             ╲                     \n");
    printf("                  ╱                ♦                                                                                                            ╱                     \n"); // detalhes
    printf("                  ╲            ●  ╱╲  ●                                                                                                         ╲                     \n"); // detalhes
    printf("                  ╱            │╲╱  ╲╱│                                                                                                         ╱                     \n"); // detalhes
    printf("                  ╲            ┗━━━━━━┛                                                                                                         ╲                     \n"); // detalhes
    printf("                  ╱                                                                                                                             ╱                     \n"); // detalhes

    printf("                  ╲ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫      ⧫        ╲                     \n"); // titulo
    printf("                  ╱⧫ ⧫         ⧫ ⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ╱                     \n"); // titulo
    printf("                  ╲ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ⧫    ⧫ ⧫     ⧫╲                     \n"); // titulo
    printf("                  ╱⧫ ⧫         ⧫ ⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ╱                     \n"); // titulo
    printf("                  ╲ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫      ⧫ ⧫ ⧫ ⧫  ╲                     \n"); // titulo

    printf("                  ╱                                                                                                                             ╱                     \n");
    printf("                  ╲                                                                                                                             ╲                     \n"); // subtitulo
    printf("                  ╱                                                                                                                             ╱                     \n");
    printf("                  ╲                                                                                                                             ╲                     \n");
    printf("___________________╲                                                                                                                             ╲____________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("                ╱                                                                                                                                 ╱                   \n");
    printf("                ╲                                                                                                                                 ╲                   \n");
    printf("                ╱                  ♦                                                                                                              ╱                   \n"); // detalhes
    printf("                ╲              ●  ╱╲  ●                                                                                                           ╲                   \n"); // detalhes
    printf("                ╱              │╲╱  ╲╱│                                                                                                           ╱                   \n"); // detalhes
    printf("                ╲              ┗━━━━━━┛                                                                                                           ╲                   \n"); // detalhes
    printf("                ╱                                                                                                                                 ╱                   \n"); // detalhes

    printf("                ╲ ⧫ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫      ⧫         ⧫╲                   \n"); // titulo
    printf("                ╱  ⧫ ⧫         ⧫ ⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ⧫ ╱                   \n"); // titulo
    printf("                ╲   ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ⧫    ⧫ ⧫     ⧫ ⧫╲                   \n"); // titulo
    printf("                ╱  ⧫ ⧫         ⧫ ⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ⧫ ╱                   \n"); // titulo
    printf("                ╲ ⧫ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫      ⧫ ⧫ ⧫ ⧫   ⧫╲                   \n"); // titulo

    printf("                ╱                                                                                                                                 ╱                   \n");
    printf("                ╲                                                                                                                                 ╲                   \n"); // subtitulo
    printf("                ╱                                                                                                                                 ╱                   \n");
    printf("                ╲                                                                                                                                 ╲                   \n");
    printf("_________________╲                                                                                                                                 ╲__________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("              ╱                                                                                                                                     ╱                 \n");
    printf("              ╲                                                                                                                                     ╲                 \n");
    printf("              ╱                    ♦                                                                                                                ╱                 \n"); // detalhes
    printf("              ╲                ●  ╱╲  ●                                                                                                             ╲                 \n"); // detalhes
    printf("              ╱                │╲╱  ╲╱│                                                                                                             ╱                 \n"); // detalhes
    printf("              ╲                ┗━━━━━━┛                                                                                                             ╲                 \n"); // detalhes
    printf("              ╱                                                                                                                                     ╱                 \n"); // detalhes

    printf("              ╲ ⧫ ⧫ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫      ⧫         ⧫ ⧫╲                 \n"); // titulo
    printf("              ╱    ⧫ ⧫         ⧫ ⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ⧫ ⧫ ╱                 \n"); // titulo
    printf("              ╲     ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ⧫    ⧫ ⧫     ⧫ ⧫  ╲                 \n"); // titulo
    printf("              ╱    ⧫ ⧫         ⧫ ⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ⧫ ⧫ ╱                 \n"); // titulo
    printf("              ╲ ⧫ ⧫ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫      ⧫ ⧫ ⧫ ⧫   ⧫ ⧫╲                 \n"); // titulo

    printf("              ╱                                                                                                                                     ╱                 \n");
    printf("              ╲                                                                                                                                     ╲                 \n"); // subtitulo
    printf("              ╱                                                                                                                                     ╱                 \n");
    printf("              ╲                                                                                                                                     ╲                 \n");
    printf("_______________╲                                                                                                                                     ╲________________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("            ╱                                                                                                                                         ╱               \n");
    printf("            ╲                                                                                                                                         ╲               \n");
    printf("            ╱                      ♦                                                                                                                  ╱               \n"); // detalhes
    printf("            ╲                  ●  ╱╲  ●                                                                                                               ╲               \n"); // detalhes
    printf("            ╱                  │╲╱  ╲╱│                                                                                                               ╱               \n"); // detalhes
    printf("            ╲                  ┗━━━━━━┛                                                                                                               ╲               \n"); // detalhes
    printf("            ╱                                                                                                                                         ╱               \n"); // detalhes

    printf("            ╲ ⧫ ⧫ ⧫ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫      ⧫         ⧫ ⧫ ⧫╲               \n"); // titulo
    printf("            ╱⧫     ⧫ ⧫         ⧫ ⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ⧫ ⧫   ╱               \n"); // titulo
    printf("            ╲       ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ⧫    ⧫ ⧫     ⧫ ⧫    ╲               \n"); // titulo
    printf("            ╱⧫     ⧫ ⧫         ⧫ ⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ⧫ ⧫   ╱               \n"); // titulo
    printf("            ╲ ⧫ ⧫ ⧫ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫      ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫╲               \n"); // titulo

    printf("            ╱                                                                                                                                         ╱               \n");
    printf("            ╲                                                                                                                                         ╲               \n"); // subtitulo
    printf("            ╱                                                                                                                                         ╱               \n");
    printf("            ╲                                                                                                                                         ╲               \n");
    printf("_____________╲                                                                                                                                         ╲______________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("          ╱                                                                                                                                             ╱             \n");
    printf("          ╲                                                                                                                                             ╲             \n");
    printf("          ╱                        ♦                                                                                                                    ╱             \n"); // detalhes
    printf("          ╲                    ●  ╱╲  ●                                                                                                                 ╲             \n"); // detalhes
    printf("          ╱                    │╲╱  ╲╱│                                                                                                                 ╱             \n"); // detalhes
    printf("          ╲                    ┗━━━━━━┛                                                                                                                 ╲             \n"); // detalhes
    printf("          ╱                                                                                                                                             ╱             \n"); // detalhes

    printf("          ╲ ⧫ ⧫ ⧫ ⧫ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫      ⧫         ⧫ ⧫ ⧫ ⧫╲             \n"); // titulo
    printf("          ╱⧫ ⧫     ⧫ ⧫         ⧫ ⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ⧫ ⧫     ╱             \n"); // titulo
    printf("          ╲ ⧫       ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ⧫    ⧫ ⧫     ⧫ ⧫      ╲             \n"); // titulo
    printf("          ╱⧫ ⧫     ⧫ ⧫         ⧫ ⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ⧫ ⧫     ╱             \n"); // titulo
    printf("          ╲ ⧫ ⧫ ⧫ ⧫ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫      ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫╲             \n"); // titulo

    printf("          ╱                                                                                                                                             ╱             \n");
    printf("          ╲                                                                                                                                             ╲             \n"); // subtitulo
    printf("          ╱                                                                                                                                             ╱             \n");
    printf("          ╲                                                                                                                                             ╲             \n");
    printf("___________╲                                                                                                                                             ╲____________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("        ╱                                                                                                                                                 ╱           \n");
    printf("        ╲                                                                                                                                                 ╲           \n");
    printf("        ╱                          ♦                                                                                                                      ╱           \n"); // detalhes
    printf("        ╲                      ●  ╱╲  ●                                                                                                                   ╲           \n"); // detalhes
    printf("        ╱                      │╲╱  ╲╱│                                                                                                                   ╱           \n"); // detalhes
    printf("        ╲                      ┗━━━━━━┛                                                                                                                   ╲          \n");  // detalhes
    printf("        ╱                                                                                                                                                 ╱           \n"); // detalhes

    printf("        ╲   ⧫ ⧫ ⧫ ⧫ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫      ⧫         ⧫ ⧫ ⧫ ⧫ ⧫╲           \n"); // titulo
    printf("        ╱  ⧫ ⧫     ⧫ ⧫         ⧫ ⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ⧫ ⧫     ⧫ ╱           \n"); // titulo
    printf("        ╲ ⧫ ⧫       ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ⧫    ⧫ ⧫     ⧫ ⧫       ⧫╲           \n"); // titulo
    printf("        ╱  ⧫ ⧫     ⧫ ⧫         ⧫ ⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ⧫ ⧫     ⧫ ╱           \n"); // titulo
    printf("        ╲   ⧫ ⧫ ⧫ ⧫ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫      ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫╲           \n"); // titulo

    printf("        ╱                                                                                                                                                 ╱           \n");
    printf("        ╲                                                                                                                                                 ╲           \n"); // subtitulo
    printf("        ╱                                                                                                                                                 ╱           \n");
    printf("        ╲                                                                                                                                                 ╲           \n");
    printf("_________╲                                                                                                                                                 ╲__________\n");

    usleep(50000);
    system("cls");
    printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
    printf("      ╱                                                                                                                                                     ╱         \n");
    printf("      ╲                                                                                                                                                     ╲         \n");
    printf("      ╱                            ♦                                                                                                                        ╱         \n"); // detalhes
    printf("      ╲                        ●  ╱╲  ●                                                                                                                     ╲         \n"); // detalhes
    printf("      ╱                        │╲╱  ╲╱│                                                                                                                     ╱         \n"); // detalhes
    printf("      ╲                        ┗━━━━━━┛                                                                                                                     ╲         \n"); // detalhes
    printf("      ╱                                                                                                                                                     ╱         \n"); // detalhes

    printf("      ╲ 𓇼   ⧫ ⧫ ⧫ ⧫ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫      ⧫         ⧫ ⧫ ⧫ ⧫ ⧫  ╲         \n"); // titulo
    printf("      ╱    ⧫ ⧫     ⧫ ⧫         ⧫ ⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ⧫ ⧫     ⧫ ⧫ ╱         \n"); // titulo
    printf("      ╲   ⧫ ⧫       ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ⧫    ⧫ ⧫     ⧫ ⧫       ⧫ ⧫╲         \n"); // titulo
    printf("      ╱    ⧫ ⧫     ⧫ ⧫         ⧫ ⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ⧫ ⧫     ⧫ ⧫ ╱         \n"); // titulo
    printf("      ╲ 𓇼   ⧫ ⧫ ⧫ ⧫ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫      ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫  ╲         \n"); // titulo

    printf("      ╱                                                                                                                                                     ╱         \n");
    printf("      ╲                                                                                                                                                     ╲         \n"); // subtitulo
    printf("      ╱                                                                                                                                                     ╱         \n");
    printf("      ╲                                                                                                                                                     ╲         \n");
    printf("_______╲                                                                                                                                                     ╲________\n");

    usleep(50000);

    while (x == 1)
    { // A relação x==1 estabelece o looping do menu.

        // Dados dos jogadores:
        struct jogadores_t
        {
            char nomes[20];
            int pontuacao[3];
            int total_pontos;
            int total_acertos;
            int total_erros;
        };

        struct jogadores_t nome[10];

        for (int t = 0; t <= 5; t++)
        { // Repetição para nomes dos jogadores

            nome[t].pontuacao[t] = 0;  // Pontuação original para mudar depois
            nome[t].total_acertos = 0; // Acerto original para mudar depois
            nome[t].total_erros = 0;   // Erro original para mudar depois

            for (int f = 0; f < 4; f++)
            { // Repetição para as pontuações

                // Inicialização do menu:

                system("cls");

                printf("▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅\n");
                printf("    ╱                                                                                                                                                         ╱       \n");
                printf("    ╲                                                                                                                                                         ╲       \n");
                printf("    ╱                              ♦                                                                                                                          ╱       \n"); // detalhes
                printf("    ╲                          ●  ╱╲  ●                                                                                                                       ╲       \n"); // detalhes
                printf("    ╱                          │╲╱  ╲╱│                                                                                                                       ╱       \n"); // detalhes
                printf("    ╲                          ┗━━━━━━┛                                                                                                                       ╲       \n"); // detalhes
                printf("    ╱                                                                                                                                                         ╱       \n"); // detalhes

                printf("    ╲   𓇼   ⧫ ⧫ ⧫ ⧫ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫  ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫       ⧫      ⧫         ⧫ ⧫ ⧫ ⧫ ⧫    ╲       \n"); // titulo
                printf("    ╱      ⧫ ⧫     ⧫ ⧫         ⧫ ⧫        ⧫ ⧫        ⧫ ⧫     ⧫ ⧫   ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ⧫ ⧫     ⧫ ⧫   ╱       \n"); // titulo
                printf("    ╲  𓇼  ⧫ ⧫       ⧫ ⧫       ⧫ ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫ ⧫ ⧫   ⧫ ⧫           ⧫ ⧫       ⧫ ⧫    ⧫ ⧫     ⧫ ⧫       ⧫ ⧫  ╲       \n"); // titulo
                printf("    ╱      ⧫ ⧫     ⧫ ⧫         ⧫ ⧫              ⧫ ⧫    ⧫ ⧫         ⧫ ⧫           ⧫       ⧫ ⧫     ⧫ ⧫     ⧫ ⧫     ⧫ ⧫   ⧫ ⧫     ⧫ ⧫    ⧫ ⧫       ⧫ ⧫     ⧫ ⧫   ╱       \n"); // titulo
                printf("    ╲   𓇼   ⧫ ⧫ ⧫ ⧫ ⧫           ⧫ ⧫ ⧫ ⧫    ⧫ ⧫ ⧫ ⧫      ⧫           ⧫ ⧫ ⧫ ⧫     ⧫ ⧫       ⧫       ⧫       ⧫ ⧫ ⧫ ⧫ ⧫     ⧫ ⧫ ⧫ ⧫ ⧫      ⧫ ⧫ ⧫ ⧫   ⧫ ⧫ ⧫ ⧫ ⧫    ╲       \n"); // titulo

                printf("    ╱                                                                                                                                                         ╱       \n");
                printf("    ╲                                                                                                                                                         ╲       \n");
                printf("    ╱                                             -   UM JOGO DE ADVINHAÇÃO COMO VOCÊ NUNCA VIU ANTES!! -                                                     ╱       \n"); // subtitulo
                printf("    ╲                                                                                                                                                         ╲       \n");
                printf("_____╲                                                                                                                                                         ╲______\n");

                printf("\n\n");

                printf("\t\t\t\t\t\t\t\t ᴇᴍ ᴜᴍᴀ ᴠɪʟᴀ ᴅɪsᴛᴀɴᴛᴇ, ɴᴀ ᴄɪᴅᴀᴅᴇ ᴅᴇ ᴇsᴍᴇʀᴀʟᴅᴀ, ᴇxɪsᴛɪᴀ ᴜᴍ ᴘᴀʟʜᴀᴄᴏ, sᴇᴜ ɴᴏᴍᴇ ᴇʀᴀ ʙᴀʀᴛᴏʟᴏᴍᴇᴜ.\n");
                printf("\t\t\t\t\t\t\tᴇʟᴇ ᴇʀᴀ ᴍᴜɪᴛᴏ ᴄᴏɴʜᴇᴄɪᴅᴏ ɴᴀ ᴄɪᴅᴀᴅᴇ ᴘᴏʀ sᴇᴜ ǫᴜᴀᴅʀᴏ “ᴀ ᴀᴅɪᴠɪɴʜᴀᴄᴀᴏ ᴅᴏ ʀᴇɪ” ǫᴜᴇ ɪɴᴛᴇʀᴘʀᴇᴛᴀᴠᴀ ɴᴀ ᴘʀᴀᴄᴀ ᴄᴇɴᴛʀᴀʟ.\n");
                printf("\t\t\t\t\t\tᴏ ᴇsᴘᴇᴛᴀᴄᴜʟᴏ ᴛɪɴʜᴀ ᴄᴏᴍᴏ ᴏʙᴊᴇᴛɪᴠᴏ ғᴀᴢᴇʀ ᴄᴏᴍ ǫᴜᴇ ᴏ ᴘᴜʙʟɪᴄᴏ ᴛᴇɴᴛᴀssᴇ ᴀᴄᴇʀᴛᴀʀ 3 ᴘᴀʟᴀᴠʀᴀs ᴇsᴄᴏʟʜɪᴅᴀs ᴘᴏʀ ʙᴀʀᴛᴏʟᴏᴍᴇᴜ,\n");
                printf("\t\t\t\t\t\t\t\t  ᴜᴛɪʟɪᴢᴀɴᴅᴏ, ɴᴏ ᴍᴀxɪᴍᴏ, 5 ᴅɪᴄᴀs ᴘᴀʀᴀ ᴄᴀᴅᴀ, ᴄᴏɴsɪᴅᴇʀᴀɴᴅᴏ ǫᴜᴇ ʜᴀ ᴜᴍᴀ ᴛᴇɴᴛᴀᴛɪᴠᴀ ᴘᴏʀ ᴅɪᴄᴀ.\n\n");

                printf("ᴇᴍ ᴜᴍᴀ ʙᴇʟᴀ ᴛᴀʀᴅᴇ, ᴀᴏ ᴘᴀssᴇᴀʀ ᴘᴏʀ ᴇsᴍᴇʀᴀʟᴅᴀ, ᴠᴏᴄᴇ ᴄᴏɴʜᴇᴄᴇ ʙᴀʀᴛᴏʟᴏᴍᴇᴜ, ᴇ ᴇʟᴇ ᴛᴇ ᴏғᴇʀᴇᴄᴇ ᴀ ᴄʜᴀɴᴄᴇ ᴅᴇ ᴘᴀʀᴛɪᴄɪᴘᴀʀ ᴅᴇ ᴜᴍ ᴅᴇ sᴇᴜs sʜᴏᴡs.\n");

                printf("\nGostaria de participar do show de Bartolomeu e tentar acertar um de seus enigmas? ➤ Insira 1\n");
                printf("Gostaria de sair da cidade e encerrar o jogo? ➤ Insira 2\n");
                printf("Gostaria de ver o placar? ➤ Insira 3\n");
                printf("\nInsira a frente ➤ "); // Entrada para as intruções do jogo.

                int menu = -1;
                deu_certo = scanf("%i", &menu);
                getchar();

                switch (menu)
                {
                case 1:
                {
                    x = 2; // Entra no looping da partida!
                    while (x == 2)
                    {

                        system("cls");
                        printf("----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

                        if (f == 0)
                        {
                            printf("Insira o nome do %i jogador: \n", t + 1);
                            scanf("%[^\n]s", nome[t].nomes);
                            getchar();

                            system("cls");
                            printf("\n");
                            printf("Bem vindo(a) ao ESPETACULO %s!\n", nome[t].nomes); // Apresentação inicial das regras do jogo
                            printf("INSTRUCOES DO SHOW:\n\n");

                            printf("Bartolomeu escolherá 3 palavras e você deve acertar com o minimo de dicas possíveis para acumular cada vez mais pontos!!\n");
                            printf("\tAcerto com a 1° dica = 10 pontos.\n");
                            printf("\tAcerto com a 2° dica = 8 pontos.\n");
                            printf("\tAcerto com a 3° dica = 6 pontos.\n");
                            printf("\tAcerto com a 4° dica = 4 pontos.\n");
                            printf("\tAcerto com a 5° dica = 2 pontos.\n\n");

                            printf("\nO jogo suporta até 5 jogadores!\n"); // Máximo de jogadores
                            printf("\nCada jogador pode advinhar, até, 3 palavras diferentes!!\n");
                        }

                        if (f > 0)
                        {
                            printf("Vamos começar %s", nome[t].nomes);
                        }

                        while (1)
                        {
                            printf("\nPodemos começar o show? ➤ Insira 1\n");
                            printf("Gostaria de voltar ao menu? ➤ Insira 2\n");

                            int opcao = -1;
                            printf("Insira à frente ➤ ");
                            scanf("%i", &opcao);
                            getchar();

                            switch (opcao)
                            {
                            case 1:
                            { // Sorteio da palavra.

                                x = 3; // Inicializa o looping de novas palavras
                                while (x == 3)
                                {                                                                                                                 // Looping para novas palavras
                                    char palavras[21][12] = {"ABELHA", "CANETA", "EDREDOM", "ELEFANTE", "CINTO", "CALCULADORA", "ESTRELA", '\0'}; //"GELO", "MAPA", "CASSINO", "ENVELOPE", "TESOURA", "REI", "URSO PANDA", "MALA", "AGULHA", "ASAS", "CACHORRO", "BULA", "PIPOCA", '\0'};
                                    char dicas[21][50][42] = {
                                        {"Ferrão", "Amarelo e Preto", "Polén", "Mel", "Inseto", '\0'},                                                   // Abelha
                                        {"Desenho", "Escritor", "Tinta", "Papel ", "Prova", '\0'},                                                       // Caneta
                                        {"Frio", "Cama", "Macio", "Tem de solteiro, casal, queen ou king size", "Cores e estampas", '\0'},               // Edredom
                                        {"Maior mamífero terrestre", "Acizentado", "Possui tromba", "Conhecido por sua boa memória", "Herbívoro", '\0'}, // Elefante
                                        {"Tem no carro", "Segura a calça", "Dá segurança", "Acessório de moda", "De couro...", '\0'},                    // Cinto
                                        {"Matemática", "Números", "Ábaco", "Cálculo", "Multiplicação", '\0'},                                            // Calculadora
                                        {"Tem no mar", "Tem no céu", "Tem na calçada da fama", "Usada em árvores de natal", ""}                          // Estrela
                                    };

                                    // Inicializa o gerador de palavras aleatórias
                                    srand(time(NULL));

                                    int aleatorio = rand() % 6;
                                    printf("A primeira palavra sorteada é: %s\n", palavras[aleatorio]);
                                    printf("\nVamos começar a %i rodada!!\n", f + 1);

                                    int escolha[5] = {0, 0, 0, 0, 0};   // Armazena as escolhas do jogador! Todos recebem o valor nulo para evitar erro, mas, posteriormente, serão substítuidos.
                                    int valor[7] = {10, 8, 6, 4, 2, 0}; // Estabelece quanto vale cada dica
                                    int n = 0;                          // Estabelece qual coluna do valor[5] está sendo trabalhada
                                    int j = 0;                          // Número da dica (1°, 2°, 3°...)

                                    x = 4; // Inicializa o looping de dicas
                                    while (x == 4)
                                    { // Estabelece o looping das dicas
                                        for (int i = 0; i < 5; i++)
                                        { // Laço para as escolhas dos jogadores, de dicas.

                                            if (i > 0 && i < 5)
                                            { // Para que o jogador evite de repetir dicas:
                                                printf("\nCUIDADO: Não repita os valores já utilizados\n");
                                            }

                                            // Exibindo as dicas já selecionadas nas tentativas anteriores:
                                            switch (i)
                                            {
                                            case 1:
                                                printf("Número já utilizado: %i\n", escolha[0]);
                                                break;
                                            case 2:
                                                printf("Número já utilizado: %i %i\n", escolha[0], escolha[1]);
                                                break;
                                            case 3:
                                                printf("Número já utilizado: %i %i %i\n", escolha[0], escolha[1], escolha[2]);
                                                break;
                                            case 4:
                                                printf("Número já utilizado: %i %i %i %i\n", escolha[0], escolha[1], escolha[2], escolha[3]);
                                                break;
                                            default:
                                                break;
                                            }

                                            // Conferindo a escolha do jogador:
                                            int correto = 1;
                                            while (correto == 1)
                                            {
                                                printf("Entre com um valor entre 1 e 5: ");
                                                deu_certo = scanf("%i", &escolha[i]);
                                                getchar();

                                                // Conferindo se há repetição de escolha entre as tentativas:
                                                int repetiu = 0;
                                                for (int k = 0; k < i; k++)
                                                {
                                                    if (escolha[i] == escolha[k])
                                                    {
                                                        repetiu = 1;
                                                        break;
                                                    } // if
                                                }     // for

                                                if (repetiu)
                                                {
                                                    printf("Valor já utilizado!\n");
                                                    printf("Pressione ENTER para tentar novamente...\n");
                                                    getchar();
                                                } // if(repetiu)

                                                // Conferindo se a entrada foi devidamente um inteiro:
                                                else if (deu_certo == 0)
                                                {
                                                    printf("Valor inválido!!\n");
                                                    printf("Digite um valor inteiro!!\n");
                                                    printf("Pressione ENTER para tentar novamente...\n");
                                                    getchar();
                                                } // else if

                                                // Conferindo se está fora do intervalo 1-5:
                                                else if (escolha[i] < 1 || escolha[i] > 5)
                                                {
                                                    printf("Valor inválido!!\n");
                                                    printf("Pressione ENTER para tentar novamente...\n");
                                                    getchar();
                                                } // else if

                                                // Caso o valor inserido esteja correto:
                                                else
                                                {
                                                    ;
                                                    correto = 0;
                                                    break;
                                                } // else
                                            }     // while

                                            // Informando quantos pontos vale a rodada e qual o numero da dica:
                                            printf("Valendo %i PONTOS:\n", valor[n]);
                                            printf("A %i° dica é: %s\n", j + 1, dicas[aleatorio][escolha[i] - 1]);

                                            // Salvando, em matriz, as tentativas do usúario
                                            char tentativa[20];
                                            printf("Insira a sua %i tentativa: ", j + 1);
                                            scanf("%s", tentativa);
                                            getchar();

                                            // Lendo o tamanho da tenativa do jogador:
                                            int tamanho_tentativa = strlen(tentativa);

                                            // Transforma a tentativa em letras maiúsculas afim de tornar possível a comparação.
                                            for (int l = 0; l < tamanho_tentativa; l++)
                                            {
                                                tentativa[l] = toupper(tentativa[l]);
                                            }

                                            // Comparando a tentativa e a palavra sorteada:
                                            if (strcmp(tentativa, palavras[aleatorio]) == 0)
                                            {
                                                while (1)
                                                {

                                                    // Inserindo valor a "i" que interrompa o looping de dicas.
                                                    i = 5;

                                                    printf("Parabéns, você acertou a palavra!\n");
                                                    printf("Ganhou %i pontos!!\n", valor[n]);

                                                    nome[t].pontuacao[f] = valor[n];                   // Salvando a pontuação do jogador.
                                                    nome[t].total_acertos = nome[t].total_acertos + 1; // Salvando a quantidade de acertos do jogador.

                                                    printf("\nGostaria de ver o placar? ➤ Insira 1\n");
                                                    printf("Gostaria de ir para o próximo passo? ➤ Insira 2\n");
                                                    printf("Insira à frente ➤ "); // Acesso a outras áreas do jogo.

                                                    int opcao = -1;
                                                    scanf("%i", &opcao);
                                                    getchar();

                                                    switch (opcao)
                                                    {
                                                    case 1:
                                                        x = 0;
                                                        break;
                                                    case 2:
                                                        x = 1;
                                                        break;
                                                    default:
                                                    {
                                                        printf("Opção Inválida! Pressione ENTER para tentar novamente...\n");
                                                        getchar();
                                                        break;
                                                    } // default
                                                    } // switch

                                                    if (x == 0 || x == 1)
                                                        break; // Impede o looping
                                                }              // while(1)

                                                // Inicializando o placar:
                                                if (x == 0)
                                                {
                                                    nome[t].total_pontos = nome[t].pontuacao[0] + nome[t].pontuacao[1] + nome[t].pontuacao[2]; // Estabelece o total de pontos de um jogador

                                                    printf("PLACAR --------------------------------------------------------------------------------------------------------------------------\n");
                                                    printf("Nome                                                                                             Pontuação      Acertos     Erros\n");

                                                    // Exibição dos pontos, acertos e erros:
                                                    for (int k = 0; k <= t; k++)
                                                    {
                                                        printf("%-99s %03i            %02i         %02i\n", nome[k].nomes, nome[k].total_pontos, nome[k].total_acertos, nome[k].total_erros);
                                                    } // for (int k=0; k<t; k++)

                                                    i = 5; // Para finalizar o laço de repetição das dicas.

                                                    while (1)
                                                    {
                                                        printf("\nInsira 1 para o próximo passo ➤ ");
                                                        int escolha = -1;
                                                        scanf("%i", &escolha);
                                                        getchar();

                                                        switch (escolha)
                                                        {
                                                        case 1:
                                                            break;
                                                        default:
                                                        {
                                                            printf("Valor inválido!\n");
                                                            printf("Pressione ENTER para tentar novamente...\n");
                                                            getchar();
                                                            break;
                                                        } // default
                                                        } // switch

                                                        if (escolha == 1)
                                                            break;
                                                    } // while (1)
                                                }     // if(x==0)

                                                break;
                                            } // if (strcmp(tentativa,palavras[aleatorio])==0)

                                            // Quando o jogador erra a tentativa:
                                            else
                                            {
                                                printf("\nResposta incorreta!\n");

                                                // Caso o jogador esteja já na 5° e última dica):
                                                if (n == 4)
                                                {
                                                    while (1)
                                                    {

                                                        printf("\nDessa vez você não conseguiu superar nosso astro!!\n");

                                                        nome[t].pontuacao[f] = valor[n + 1];
                                                        nome[t].total_erros = nome[t].total_erros + 1; // Salvando os erros do jogador.

                                                        printf("\nGostaria de ver o placar? ➤ Insira 1\n");
                                                        printf("Gostaria de ir para o próximo passo? ➤ Insira 2\n");
                                                        printf("Insira à frente ➤ "); // Acesso a outras áreas do jogo

                                                        int opcao = -1;
                                                        scanf("%i", &opcao);
                                                        getchar();

                                                        switch (opcao)
                                                        {
                                                        case 1:
                                                            x = 0;
                                                            break;
                                                        case 2:
                                                            x = 1;
                                                            break;
                                                        default:
                                                        {
                                                            printf("Opção Inválida! Pressione ENTER para tentar novamente...\n");
                                                            getchar();
                                                            break;
                                                        } // default
                                                        } // switch

                                                        if (x == 0 || x == 1)
                                                            break;
                                                    } // while

                                                    // Inicializando o placar:
                                                    if (x == 0)
                                                    {

                                                        nome[t].total_pontos = nome[t].pontuacao[0] + nome[t].pontuacao[1] + nome[t].pontuacao[2]; // Estabelece o total de pontos de um jogador.

                                                        printf("PLACAR --------------------------------------------------------------------------------------------------------------------------\n");
                                                        printf("Nome                                                                                             Pontuação      Acertos     Erros\n");

                                                        // Exibindo pontos, acertos e erros:
                                                        for (int k = 0; k <= t; k++)
                                                        {
                                                            printf("%-99s %03i           %02i         %02i\n", nome[k].nomes, nome[k].total_pontos, nome[k].total_acertos, nome[k].total_erros);
                                                        } // for (int k=0; k<t; k++)

                                                        i = 5; // Para finalizar o laço de repetição da dica.
                                                        while (1)
                                                        {
                                                            printf("\nInsira 1 para o próximo passo ➤ ");

                                                            int escolha = -1;
                                                            scanf("%i", &escolha);
                                                            switch (escolha)
                                                            {
                                                            case 1:
                                                                break;
                                                            default:
                                                            {
                                                                printf("Valor inválido!\n");
                                                                printf("Pressione ENTER para tentar novamente...\n");
                                                                getchar();
                                                                break;
                                                            } // default
                                                            } // switch

                                                            if (escolha == 1)
                                                                break;
                                                        } // while (1)

                                                    } // if(x==0)
                                                }     // if(n==4)

                                                // Caso o jogador ainda tenha direito a mais dicas:
                                                if (n < 4)
                                                {
                                                    while (1)
                                                    {
                                                        printf("\nGostaria de seguir para a próxima dica? ➤ Insira 1\n");
                                                        printf("Gostaria de encerrar a partida e receber 0 pontos ➤ Insira 2\n");
                                                        printf("Insira a frente ➤ ");

                                                        int escolha = -1;
                                                        scanf("%i", &escolha);
                                                        getchar();

                                                        switch (escolha)
                                                        {
                                                        case 1:
                                                            x = 4;
                                                            n = n + 1;
                                                            j = j + 1;
                                                            break; // Mantém o laço for
                                                        case 2:
                                                        {
                                                            x = 1;
                                                            i = 5; // Interrompe o laço de repetição das dicas.
                                                            nome[t].pontuacao[f] = valor[5];
                                                            nome[t].total_erros = nome[t].total_erros + 1; // Salavando os erros do jogador
                                                            break;
                                                        }
                                                        default:
                                                        {
                                                            printf("Opção Inválida! Pressione ENTER para tentar novamente\n");
                                                            getchar();
                                                        } // default
                                                        } // switch

                                                        if (escolha == 2 || escolha == 1)
                                                            break;
                                                    } // while
                                                }     // if(n<4)
                                            }         // else

                                        } // for(int i=0; i<5; i++) - Looping que reinicia!

                                        while (1)
                                        {
                                            system("cls");

                                            // Quando o jogador termina o ciclo de 3 palavras.
                                            if (f > 1)
                                            {
                                                printf("Chegamos ao final do nosso show!!\n");
                                                printf("Muito obrigada pela sua participação!\n");
                                                printf("\nVOLTE SEMPRE!!\n");

                                                printf("\nGostaria de recomeçar como outro jogador? ➤ Insira 1\n");
                                                printf("Gostaria de voltar para o menu? ➤ Insira 2\n");
                                                printf("Insira a frente ➤ "); // Acesso a outras áreas do jogo.

                                                int opcao = -1;
                                                scanf("%i", &opcao);
                                                getchar();

                                                switch (opcao)
                                                {
                                                case 1:
                                                    x = 2;
                                                    break;
                                                case 2:
                                                    x = 1;
                                                    break;
                                                default:
                                                {
                                                    printf("Opção Inválida! Pressione ENTER para tentar novamente\n");
                                                    getchar();
                                                    break;
                                                } // default
                                                } // switch
                                            }     // if(f>1)

                                            if (f < 2)
                                            {
                                                while (1)
                                                {
                                                    printf("\n\nGostaria de sortear uma nova palavra? ➤ Insira 1\n");
                                                    printf("Gostaria de recomeçar como outro jogador? ➤ Insira 2\n");
                                                    printf("Gostaria de voltar para o menu? ➤ Insira 3\n");
                                                    printf("Insira a frente ➤ "); // Acesso a outras áreas do jogo.

                                                    int opcao = -1;
                                                    scanf("%i", &opcao);
                                                    getchar();

                                                    switch (opcao)
                                                    {
                                                    case 1:
                                                        x = 3;
                                                        f = f + 1;
                                                        break; // Interrompe o while para reiniciar a dica - Inicia uma nova palavra
                                                    case 2:
                                                        x = 2;
                                                        break; // Interrompe o while para reiniciar a dica - Troca de jogador
                                                    case 3:
                                                        x = 1;
                                                        break; // Interrompe o while para reiniciar a dica - Volta para o menu
                                                    default:
                                                    {
                                                        system("cls");
                                                        printf("Opção Inválida!\n");
                                                        getchar();
                                                        system("cls");
                                                        break;
                                                    } // default
                                                    } // switch
                                                }
                                            } // if(f<2)

                                            if (x == 3 || x == 2 || x == 1)
                                                break;
                                        } // while (1)

                                    } // while (x==4)
                                }     // while (x==3) - repetição da palavra
                                break;
                            } // case 1 - (switch opção)

                            // Caso queira voltar paara o menu:
                            case 2:
                                x = 1;
                                break;

                            // Caso o valor seja inválido:
                            default:
                            {
                                x = 0;
                                printf("\nValor inválido!!\n");
                                printf("Por favor insira ENTER para tentar novamente.\n\n");
                                getchar();
                                break;
                            }
                            } // switch(opcao)

                            if (x == 1 || x == 2)
                                break;
                        } // while(1)

                        // Estabelecendo qual o próxima tela para o jogador:
                        switch (x)
                        {
                        case 2:
                            f = 0;
                            t = t + 1;
                            break; // Gera uma nova palavra.
                        default:
                            break; // Direciona para o menu.
                        }          // switch

                        if (x == 1)
                            break;
                    } // while(x==2)
                    break;
                } // case 1:

                // Finalizando o jogo a partir do menu.
                case 2:
                {
                    printf("Finalizando...");
                    sleep(1);
                    system("cls");
                    return 0;
                    break;
                }

                // Inicializando o placar - MENU
                case 3:
                {
                    system("cls");
                    nome[t].total_pontos = nome[t].pontuacao[0] + nome[t].pontuacao[1] + nome[t].pontuacao[2]; // Estabelece o total de pontos de um jogador
                    printf("PLACAR --------------------------------------------------------------------------------------------------------------------------\n");
                    printf("Nome                                                                                             Pontuação      Acertos     Erros\n");

                    if (f == 0 && t == 0)
                    {
                        printf("Não há jogadores ainda!!\n");
                    }
                    else
                    {
                        for (int k = 0; k <= t; k++)
                        {
                            printf("%-99s %03i            %02i      %02i\n", nome[k].nomes, nome[k].total_pontos, nome[k].total_acertos, nome[k].total_erros);
                        } // for (int k=0; k<t; k++)
                    }     // else

                    f = f - 1; // Evita que este passo seja considerado uma etapa do laço
                    printf("Para voltar para o menu, pressione ENTER");
                    getchar();
                    continue;
                }

                // Valores inválidos no menu
                default:
                {
                    printf("Valor inválido!!\n");
                    printf("Por favor insira ENTER para tentar novamente. ");
                    getchar(); // Entrada do usuário
                    f = f - 1; // Evita que este passo seja considerado uma etapa do laço
                    continue;
                } // default
                } // switch(menu)

                // Caso o jogador ainda tenha direito a dicas e deseja acessar o menu:
                if (f < 2)
                {
                    while (1)
                    {
                        printf("Gostaria de manter o nome do jogador para a próxima rodada? ➤ Insira 1\n");
                        printf("Gostaria de trocar de jogador para a próxima rodada? ➤ Insira 2\n");
                        printf("Gostaria de resetar o jogo e voltar para o menu ➤ Insira 3\n");
                        printf("Insira à frente ➤ ");

                        int opcao = -1;
                        scanf("%i", &opcao);
                        getchar();

                        switch (opcao)
                        {
                        case 1:
                            break;
                        case 2:
                            f = 4;
                            break;
                        case 3:
                            f = 4;
                            t = 6;
                            break;
                        default:
                        {
                            printf("Opção inválida!\n");
                            printf("Pressione ENTER para tentar novamente...\n");
                            getchar();
                        } // default
                        } // switch

                        if (opcao == 1 || opcao == 2 || opcao == 3)
                            break;
                    } // while
                }     // if (f<2)

                // Caso o jogador já tenha chegado ao máximo de palavrasa e deeseja ir ao menu:
                // O jogo incializa um novo jogador automaaticamente:
                if (f > 1)
                {
                    printf("Inicializando novo jogaddor...\n");
                    sleep(2);
                    f = 4;
                }

                // Caso o número de jogadores tenham chegado ao limite - 5 jogadores;
                if (t > 4)
                {
                    printf("\nOPS!\n");
                    printf("Você chegou ao limite de jogadores!\n");

                    nome[t].total_pontos = nome[t].pontuacao[0] + nome[t].pontuacao[1] + nome[t].pontuacao[2]; // Estabelece o total de pontos de um jogador
                    printf("PLACAR FINAL --------------------------------------------------------------------------------------------------------------------\n");
                    printf("Nome                                                                                             Pontuação      Acertos     Erros\n");

                    for (int k = 0; k <= t; k++)
                    {
                        printf("%-99s %03i            %02i      %02i\n", nome[k].nomes, nome[k].total_pontos, nome[k].total_acertos, nome[k].total_erros);
                    } // for (int k=0; k<=t; k++)")

                    while (1)
                    {
                        printf("Para resetar o jogo e voltar para o menu ➤ Insira 1");
                        printf("Para sair do jogo ➤ Insira 2");
                        printf("Insira a frente ➤ ");

                        int opcao = -1;
                        scanf("%i", &opcao);
                        getchar();

                        switch (opcao)
                        {
                        case 1:
                            t = 6;
                            f = 4;
                            break;
                        case 2:
                            printf("Finalizando...");
                            sleep(1);
                            return 0;
                        default:
                        {
                            printf("Opção inválida!\n");
                            printf("Pressione ENTER para tentar novamente...\n");
                            getchar();
                        } // default
                        } // swwitch

                        if (opcao == 1 || opcao == 2)
                            break;
                    } // while(1)
                }     // if(t>4)

            } // for (int f=0; f<4; f++)
        }     // for(int t=0; t<=5; t++)// jogador
    }         // while - menu (x==1);

    return 0;
}