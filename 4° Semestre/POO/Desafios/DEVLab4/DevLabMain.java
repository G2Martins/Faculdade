package br.edu.iesb_poo2024_devlab4_gustavo_martins;

public class DevLabMain {

	public static void main(String[] args) {
		
		// Exemplo 1
		VeiculoTransporte veiculoTransporte = new VeiculoTransporte();
		veiculoTransporte.emitirAlertaSonoro();

		// Exemplo 2
		CarroSedan carroSedan = new CarroSedan();
		carroSedan.setCor("Branco");
		carroSedan.setMarca("VW");
		
		// Modos de implementção de herança com classe Abstrata
		Veiculo veiculoPasseio = new  VeiculoPasseio();
		Veiculo veiculoTransporte1 = new VeiculoTransporte();
		Veiculo veiculoUtilitario = new VeiculoUtilitario();
		
		IGerenciaConfiguracoesVeiculo gerenciaVeiculoPasseio = new VeiculoPasseio();
		System.out.println(">> Quilometragem atual do veiculo de Passeio: " + gerenciaVeiculoPasseio.obterQuilometragemAtual());
		
		IGerenciaConfiguracoesVeiculo gerenciaVeiculoSedan = new CarroSedan();
		System.out.println(">> Quilometragem atual do veiculo de Passeio: " + gerenciaVeiculoSedan.obterQuilometragemAtual());
	
	
	
	
	}

}
