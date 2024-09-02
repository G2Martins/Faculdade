import java.util.Scanner;

public class desafio_01 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Digite o valor de x: ");
        int x = scanner.nextInt();

        System.out.println("Digite o valor de y: ");
        int y = scanner.nextInt();
        
        System.out.println("Digite o valor de z: ");
        int z = scanner.nextInt();
        
        scanner.close();

        if (x + y > z && x + z > y && y + z > x) 
        {
            if (x == y && y == z) {
                System.out.println("O triângulo é equilátero.");
            } else if (x == y || x == z || y == z) {
                System.out.println("O triângulo é isósceles.");
            } else {
                System.out.println("O triângulo é escaleno.");
            }
        } else{
            System.out.println("Os valores fornecidos não podem formar um triângulo.");
        }
    }
}
