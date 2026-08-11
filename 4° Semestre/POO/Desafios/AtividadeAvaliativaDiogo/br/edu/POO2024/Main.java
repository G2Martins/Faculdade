package AtividadeAvaliativaDiogo.br.edu.POO2024;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Hotel hotel = new Hotel();
        Fatura faturaHospede = new Fatura();

        hotel.adicionarQuarto(new Quarto(101, "Solteiro", false, false));
        hotel.adicionarQuarto(new Quarto(102, "Casal", false, false));
        hotel.adicionarQuarto(new Quarto(103, "Luxo", false, false));

        hotel.adicionarServico(new Servico(1, "Restaurante", 50.0));
        hotel.adicionarServico(new Servico(2, "Lavanderia", 30.0));
        hotel.adicionarServico(new Servico(3, "Passar Roupa", 15.0));

        boolean running = true;

        while (running) {
            System.out.println("\n1. Cadastrar hóspede");
            System.out.println("2. Alugar quarto");
            System.out.println("3. Reservar quarto");
            System.out.println("4. Consumir frigobar");
            System.out.println("5. Solicitar serviço");
            System.out.println("6. Quitar fatura");
            System.out.println("7. Liberar Quarto");
            System.out.println("0. Sair");

            int opcao = scanner.nextInt();
            scanner.nextLine();

            switch (opcao) {
                case 1:
                    // Cadastrar hóspede
                    System.out.println("Nome do hóspede: ");
                    String nome = scanner.nextLine();

                    System.out.println("CPF do hóspede: ");
                    String cpf = scanner.nextLine();

                    System.out.println("Endereço do hóspede: ");
                    String endereco = scanner.nextLine();

                    System.out.println("Telefone do hóspede:");
                    String telefone = scanner.nextLine();

                    Hospede hospede = new Hospede(nome, cpf, endereco, telefone);
                    hotel.cadastrarHospede(hospede);
                    System.out.println("Hóspede cadastrado com sucesso!");
                    break;

                case 2:
                    // Alugar quarto
                    System.out.println("Digite o CPF do hóspede: ");
                    String cpfHospedeAluguel = scanner.nextLine();

                    Hospede hospedeAluguel = null;
                    for (Hospede h : hotel.getHospedes()) {
                        if (h.getCpf().equals(cpfHospedeAluguel)) {
                            hospedeAluguel = h;
                            break;
                        }
                    }

                    if (hospedeAluguel != null) {
                        System.out.println("Quartos disponíveis:");
                        for (Quarto q : hotel.getQuartos()) {
                            if (!q.isOcupado() && !q.isReservado()) {
                                System.out.println("Quarto " + q.getNumero() + " - Tipo: " + q.getTipo() + " - Preço: R$" + q.getPreco());
                            }
                        }

                        System.out.println("Digite o número do quarto que deseja alugar:");
                        int numeroQuartoAluguel = scanner.nextInt();
                        scanner.nextLine();

                        Quarto quartoAlugado = null;
                        for (Quarto q : hotel.getQuartos()) {
                            if (q.getNumero() == numeroQuartoAluguel) {
                                quartoAlugado = q;
                                break;
                            }
                        }

                        if (quartoAlugado != null && !quartoAlugado.isOcupado() && !quartoAlugado.isReservado()) {
                            quartoAlugado.alugar();
                            faturaHospede.adicionarDiaria(quartoAlugado.getPreco());

                            System.out.println("Quarto " + quartoAlugado.getNumero() + " alugado com sucesso para "
                                    + hospedeAluguel.getNome() + "!");
                            System.out.println("Preço da diária: R$" + quartoAlugado.getPreco());
                        } else {
                            System.out.println("Quarto não disponível para aluguel.");
                        }
                    } else {
                        System.out.println("Hóspede não encontrado. Certifique-se de que o CPF está correto.");
                    }
                    break;

                case 3:
                    // Reservar quarto
                    System.out.println("Nome do hóspede para a reserva: ");
                    String nomeReserva = scanner.nextLine();
                    Hospede hospedeReserva = null;

                    for (Hospede h : hotel.getHospedes()) {
                        if (h.getNome().equals(nomeReserva)) {
                            hospedeReserva = h;
                            break;
                        }
                    }

                    if (hospedeReserva != null) {
                        System.out.println("Data da reserva (dd/mm/aaaa): ");
                        String dataReserva = scanner.nextLine();

                        Quarto quartoParaReserva = hotel.buscarQuartoDisponivel();
                        if (quartoParaReserva != null) {
                            quartoParaReserva.reservar(); // Marcar como reservado
                            hotel.realizarReserva(hospedeReserva, quartoParaReserva, dataReserva);
                            System.out.println("Quarto " + quartoParaReserva.getNumero() + " reservado para "
                                    + hospedeReserva.getNome() + " na data " + dataReserva);
                        } else {
                            System.out.println("Nenhum quarto disponível para reserva.");
                        }
                    } else {
                        System.out.println("Hóspede não encontrado.");
                    }
                    break;

                case 4:
                    // Consumir frigobar
                    System.out.println("Digite o número do quarto:");
                    int numeroQuartoFrigobar = scanner.nextInt();
                    scanner.nextLine();

                    Quarto quartoFrigobar = null;
                    for (Quarto q : hotel.getQuartos()) {
                        if (q.getNumero() == numeroQuartoFrigobar) {
                            quartoFrigobar = q;
                            break;
                        }
                    }

                    if (quartoFrigobar != null && quartoFrigobar.isOcupado()) {
                        System.out.println("Itens disponíveis no frigobar:");
                        for (Frigobar.ItemFrigobar item : quartoFrigobar.getFrigobar().getItens()) {
                            System.out
                                    .println("ID: " + item.getId() + " - " + item.getNome() + ": R$" + item.getPreco());
                        }

                        System.out.println("Digite o ID do item que deseja consumir:");
                        int idItemConsumir = scanner.nextInt();
                        scanner.nextLine();

                        System.out.println("Digite a quantidade do item:");
                        int quantidade = scanner.nextInt();
                        scanner.nextLine();

                        boolean itemEncontrado = false;
                        for (Frigobar.ItemFrigobar item : quartoFrigobar.getFrigobar().getItens()) {
                            if (item.getId() == idItemConsumir) {
                                double totalItem = item.getPreco() * quantidade;
                                faturaHospede.adicionarFrigobar(totalItem);
                                System.out.println("Item " + item.getNome() + " (Quantidade: " + quantidade
                                        + ") adicionado à fatura, total: R$" + totalItem);
                                itemEncontrado = true;
                                break;
                            }
                        }

                        if (!itemEncontrado) {
                            System.out.println("Item não encontrado.");
                        }
                    } else {
                        System.out.println("Quarto não encontrado ou não está ocupado.");
                    }
                    break;
                case 5:
                    // Solicitar serviço
                    System.out.println("Digite o número do quarto:");
                    int numeroQuartoServico = scanner.nextInt();
                    scanner.nextLine();

                    Quarto quartoServico = null;
                    for (Quarto q : hotel.getQuartos()) {
                        if (q.getNumero() == numeroQuartoServico) {
                            quartoServico = q;
                            break;
                        }
                    }

                    if (quartoServico != null && quartoServico.isOcupado()) {
                        System.out.println("Serviços disponíveis: ");
                        for (Servico servico : hotel.getServicos()) {
                            System.out.println("- " + servico.getTipo() + ": R$" + servico.getValor());
                        }

                        System.out.println("Digite o tipo de serviço desejado: ");
                        String tipoServico = scanner.nextLine();

                        Servico servicoSolicitado = null;
                        for (Servico servico : hotel.getServicos()) {
                            if (servico.getTipo().equalsIgnoreCase(tipoServico)) {
                                servicoSolicitado = servico;
                                break;
                            }
                        }

                        if (servicoSolicitado != null) {
                            faturaHospede.adicionarServico(servicoSolicitado); // Adiciona o serviço à fatura
                            System.out.println("Serviço " + servicoSolicitado.getTipo() + " adicionado na fatura.");
                        } else {
                            System.out.println("Serviço não encontrado.");
                        }
                    } else {
                        System.out.println("Quarto não encontrado ou não está ocupado.");
                    }
                    break;

                case 6:
                    // Quitar fatura
                    System.out.println("Digite o número do quarto para quitar a fatura:");
                    int numeroQuartoQuitar = scanner.nextInt();
                    scanner.nextLine();

                    Quarto quartoQuitar = null;
                    for (Quarto q : hotel.getQuartos()) {
                        if (q.getNumero() == numeroQuartoQuitar) {
                            quartoQuitar = q;
                            break;
                        }
                    }

                    if (quartoQuitar != null && quartoQuitar.isOcupado()) {
                        double total = faturaHospede.calcularTotal(); // Calcula o total da fatura
                        System.out.println("Total a pagar: R$" + total);
                        faturaHospede.quitar(); // Quita a fatura
                        System.out.println("Fatura quitada com sucesso.");
                    } else {
                        System.out.println("Quarto não encontrado ou não está ocupado.");
                    }
                    break;

                case 7:
                    System.out.println("Status dos Quartos:");
                    for (Quarto quarto : hotel.getQuartos()) {
                        String status = quarto.isOcupado() ? "Ocupado" : "Disponível";
                        System.out.println("Quarto " + quarto.getNumero() + " - Tipo: " + quarto.getTipo()
                                + " - Status: " + status);
                    }

                    System.out.println("\nDigite o número do quarto que deseja liberar:");
                    int numeroQuartoLiberar = scanner.nextInt();
                    scanner.nextLine();

                    Quarto quartoLiberar = null;
                    for (Quarto q : hotel.getQuartos()) {
                        if (q.getNumero() == numeroQuartoLiberar) {
                            quartoLiberar = q;
                            break;
                        }
                    }

                    if (quartoLiberar != null) {
                        if (quartoLiberar.isOcupado()) {
                            quartoLiberar.liberar();
                            System.out.println("Quarto " + quartoLiberar.getNumero() + " foi liberado com sucesso!");
                        } else {
                            System.out.println("Quarto " + quartoLiberar.getNumero() + " já está disponível.");
                        }
                    } else {
                        System.out.println("Quarto não encontrado.");
                    }
                    break;

                case 0:
                    running = false;
                    break;

                default:
                    System.out.println("Opção inválida.");
                    break;
            }
        }
        scanner.close();
    }
}
