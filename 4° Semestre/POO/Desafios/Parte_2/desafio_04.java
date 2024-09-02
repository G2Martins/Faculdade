public class desafio_04 {
    public static void main(String[] args) {
        int quantidade = 15;
        long[] fibonacci = new long[quantidade];

        // Inicializa os primeiros dois números da sequência
        if (quantidade > 0) fibonacci[0] = 0;
        if (quantidade > 1) fibonacci[1] = 1;

        // Calcula os números seguintes
        for (int i = 2; i < quantidade; i++) {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }

        // Exibe os números da sequência de Fibonacci
        System.out.println("Os primeiros " + quantidade + " números da sequência de Fibonacci são:");
        for (int i = 0; i < quantidade; i++) {
            System.out.print(fibonacci[i] + " ");
        }
    }
}
