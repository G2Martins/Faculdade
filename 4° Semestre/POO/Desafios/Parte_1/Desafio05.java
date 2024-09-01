/*
Um pequeno produtor rural quer vender dois bois para abate, pois precisa fazer receita e pagar suas despesas mensais. 
O seu funcionário selecionou 10 animais para serem pesados na esperança de que nesse grupo tenham dois animais ideiais para serem abatidos. 
Caso dois animais em condições ideias sejam encontrados, calcule a receita que o produtor irá obter com a sua venda. Caso contrário, 
informe ao produtor que um novo grupo de animais precisa ser selecionado para o processo de pesagem. 

    • O valor da arroba do boi está cotado hoje em R$ 232,60. 
    • Peso ideal do boi para abate >= 600 quilos. 
    • Cálculo da receita = Quantidade x Preço. 
    • Imprima na console o valor da receita. 
    • Imprima na console quantos bois foram pesados. 
    • Informe ao usuário se o processo teve sucesso ou não. 
 */
import java.util.ArrayList;
import java.util.Scanner;
import java.text.DecimalFormat;

public class Desafio05 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double arroba = 232.60;
        double[] boisPesados = new double[10];
        ArrayList<Double> boisIdeais = new ArrayList<>();

        System.out.println("Digite o peso dos Bois pesados:");
        for (int i = 0; i < 10; i++) 
        {
            boisPesados[i] = scanner.nextDouble();

            if (boisPesados[i] >= 600) {
                boisIdeais.add(boisPesados[i]);
            }
        }
        scanner.close();
        DecimalFormat df = new DecimalFormat("#.00");

        if (boisIdeais.size() >= 2) 
        {
            double somaPesos = 0;
            
            for (double peso : boisIdeais) 
            {
                somaPesos += peso; 
            }

            double quantidadeArrobas = somaPesos / 15;
            double receita = quantidadeArrobas * arroba;

            System.out.println("\n\n\nValor da Receita total: R$ " + df.format(receita));
            System.out.println("Foram pesados " + boisPesados.length + " bois.");
            System.out.println("Processo de pesagem teve sucesso.");

        } else {
            System.out.println("Um novo grupo de animais precisa ser selecionado para o processo de pesagem.");
        }
    }
}

