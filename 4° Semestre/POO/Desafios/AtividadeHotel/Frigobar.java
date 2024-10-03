package AtividadeAvaliativaDiogo.br.edu.POO2024;

import java.util.ArrayList;
import java.util.List;

public class Frigobar {
    private List<ItemFrigobar> itens;

    public Frigobar() {
        this.itens = new ArrayList<>();
        itens.add(new ItemFrigobar(1, "Refrigerante", 5.0));
        itens.add(new ItemFrigobar(2, "Água", 2.0));
        itens.add(new ItemFrigobar(3, "Cerveja", 8.0));
        itens.add(new ItemFrigobar(4, "Snacks", 3.5));
    }

    public List<ItemFrigobar> getItens() {
        return itens;
    }

    public static class ItemFrigobar {
        private int id;
        private String nome;
        private double preco;

        public ItemFrigobar(int id, String nome, double preco) {
            this.id = id;
            this.nome = nome;
            this.preco = preco;
        }

        public int getId() {
            return id;
        }

        public String getNome() {
            return nome;
        }

        public double getPreco() {
            return preco;
        }
    }
}