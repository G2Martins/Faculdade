/*
Verificação de Números Primos:

O método isPrimo(int numero) verifica se um número é primo. Ele faz isso usando otimizações:
Números menores ou iguais a 1 não são primos.
Números 2 e 3 são primos.
Elimina múltiplos de 2 e 3.
Verifica divisores até a raiz quadrada do número, pulando múltiplos de 6 para maior eficiência.

*/

import java.util.Scanner;

public class desafio_05 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite o valor máximo para encontrar números primos: ");
        int limite = scanner.nextInt();

        System.out.println("Números primos entre 0 e " + limite + ":");
        for (int i = 2; i <= limite; i++) {
            if (isPrimo(i)) {
                System.out.print(i + " ");
            }
        }

        scanner.close();
    }

    // Método para verificar se um número é primo
    public static boolean isPrimo(int numero) {
        if (numero <= 1) 
        {
            return false;
        }
        if (numero <= 3) 
        {
            return true;
        }

        if (numero % 2 == 0 || numero % 3 == 0) 
        {
            return false;
        }
        
        for (int i = 5; i * i <= numero; i += 6) 
        {
            if (numero % i == 0 || numero % (i + 2) == 0) 
            {
                return false;
            }
        }
        return true;
    }
}
