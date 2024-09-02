import java.text.DecimalFormat;
import java.util.Scanner;

public class desafio_03 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Digite a velocidade do motorista:");
        double velocidade = scanner.nextDouble();

        final double VELOCIDADE = velocidade;
        DecimalFormat df = new DecimalFormat("#.00");
        scanner.close();

        if(VELOCIDADE <= 60)
        {
            System.out.println("Sem aplicação de multa");
        }else
        {
            double valorKM = VELOCIDADE - 60;
            double valorMulta = valorKM * 5;

            System.out.println("Valor a ser pago de Multa R$ " + df.format(valorMulta));
        }
    }   
}
