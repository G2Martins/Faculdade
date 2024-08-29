/*
Receba do usuário via console uma sequência de números inteiros até que 5 números ímpares sejam lidos. 
Imprima o primeiro número ímpar lido. 
Imprima o último número ímpar lido. 
Imprima quantas vezes o laço precisou ser repetido. 
Crie duas variáveis auxiliares para armazenar o primeiro e o último valor ímpar encontrado.  
*/
import java.util.Scanner;

public class Desafio02 {
    
    public static void main(String[] args)
    {
        // Lendo os dados de Entrada:
        Scanner scanner = new Scanner(System.in);
        int contadorImpares = 0;
        int contadorLaco = 0;

        while (contadorImpares < 5 ) 
        {
            System.out.print("Digite um número inteiro: ");
            int numero = scanner.nextInt();
            contadorLaco++;

            if (numero % 2 == 1) {
                contadorImpares++;
            }   
        }
        
        
        System.out.println("O laço foi repetido " + contadorLaco);
        scanner.close();
    }
}
