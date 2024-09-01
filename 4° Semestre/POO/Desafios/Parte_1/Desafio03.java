import java.text.DecimalFormat;
import java.util.Scanner;

public class Desafio03 {
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        System.out.println("Digite o valor de m: ");
        double m = scanner.nextDouble();

        System.out.println("Digite o valor de x: ");
        double x = scanner.nextDouble();
        
        System.out.println("Digite o valor de n: ");
        double n = scanner.nextDouble();
        
        scanner.close();
        double y = m * x + n;

        DecimalFormat df = new DecimalFormat("#.00");

        System.out.println("Valor da equação reduzida da reta y = " + df.format(y));
    }
}
