package br.edu.iesb_poo2024_exerciciop1_gustavo_martins;

public class Main {
	

    public static void main(String[] args) {
        Veiculo veiculo = new Veiculo("Audi", "R8", "OTM2E19", 2023, 10000.22, "Gustavo", "093120989-80");
        OrdemServico ordemServico = new OrdemServico(1, "Jose", "Bruno", false, false, "Aro arranhado");

        veiculo.printInformacoesCompletas();

        EntregaVeiculoCliente entrega = new EntregaVeiculoCliente(1, "Tudo ok com o carro", "Gustavo");
        entrega.isEntregaFinalizada(ordemServico);


        EntregaVeiculoCliente novaEntrega = entrega.cadastrarEntrega(2, "Ana", "Tudo perfeito");
        System.out.println("Nova entrega cadastrada para o cliente: " + novaEntrega.getNomeCliente());
    }
}
