import java.util.Scanner;

public class desafio_02 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rodaPrograma = 1;

        while (rodaPrograma == 1) {
            System.out.println("--Digite o símbolo da operação desejada--");
            System.out.println("== + Adição                            ==");
            System.out.println("== - Subtração                         ==");
            System.out.println("== / Divisão                           ==");
            System.out.println("== * Multiplicação                     ==");
            System.out.print("== Operação: ");
            String operacao = scanner.nextLine();

            double x = 0, y = 0;

            if (operacao.equals("+") || operacao.equals("-") || operacao.equals("/") || operacao.equals("*")) {
                System.out.print("Digite o valor de x: ");
                x = scanner.nextDouble();
                System.out.print("Digite o valor de y: ");
                y = scanner.nextDouble();
                scanner.nextLine();
            }

            switch (operacao) {
                case "+":
                    double soma = x + y;
                    System.out.println("\n\n" + x + " + " + y + " = " + soma);
                    break;

                case "-":
                    double subtracao = x - y;
                    System.out.println("\n\n" + x + " - " + y + " = " + subtracao);
                    break;

                case "/":
                    if (y != 0) {
                        double divisao = x / y;
                        System.out.println("\n\n" + x + " / " + y + " = " + divisao);
                    } else {
                        System.out.println("Erro: Divisão por zero não permitida.");
                    }
                    break;

                case "*":
                    double multiplicacao = x * y;
                    System.out.println("\n\n" + x + " * " + y + " = " + multiplicacao);
                    break;

                default:
                    System.out.println("Operação inválida. Tente novamente.");
                    break;
            }

            System.out.print("\n\nDeseja realizar outra operação? (1 - Sim, 0 - Não): ");
            rodaPrograma = scanner.nextInt();
            scanner.nextLine();

           
        }

        scanner.close();
        System.out.println("Programa encerrado.");
    }
}
