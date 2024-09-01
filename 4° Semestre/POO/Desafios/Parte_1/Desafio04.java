import java.util.Scanner;

public class Desafio04 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] numeros = new int[10];
        int menorInt, maiorInt;

        System.out.println("Digite 10 números inteiros: ");
        numeros[0] = scanner.nextInt();
        menorInt = numeros[0];
        maiorInt = numeros[0];

        for (int i = 1; i < 10; i++) {
            numeros[i] = scanner.nextInt();

            if (numeros[i] < menorInt) {
                menorInt = numeros[i];
            }
            if (numeros[i] > maiorInt) {
                maiorInt = numeros[i];
            }
        }

        scanner.close();

        System.out.println("\nMenor valor: " + menorInt);
        System.out.println("Maior valor: " + maiorInt);
    }
}
