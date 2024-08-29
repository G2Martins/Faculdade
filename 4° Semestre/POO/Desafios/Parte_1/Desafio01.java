/*
Receba do usuário via console uma sequência de números inteiros até que Use o comando while. 3 números pares 
sejam lidos. Imprima quantas vezes o laço precisou ser repetido. 
*/
import java.util.Scanner;

public class Desafio01 {

    public static void main()
    {
        // Lendo os dados de Entrada:
        Scanner scanner = new Scanner(System.in);
        int contadorPares = 0;
        int contadorLaco = 0;

        while (contadorPares < 3 ) 
        {
            System.out.print("Digite um número inteiro: ");
            int numero = scanner.nextInt();
            contadorLaco++;

            if (numero % 2 == 0) {
                contadorPares++;
            }   
        }
        
        
        System.out.println("O laço foi repetido " + contadorLaco);
        scanner.close();
    }
}
     