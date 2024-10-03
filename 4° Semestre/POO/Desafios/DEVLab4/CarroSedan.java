package br.edu.iesb_poo2024_devlab4_gustavo_martins;

public class CarroSedan extends VeiculoPasseio {

	public void metodoEspecificoCarroSedan() 
	{
		if(super.isVeiculoLigado()) {
			System.out.println("O carro está ligado!");
		}
	}

	@Override
	public int obterQuilometragemAtual() {
		// TODO Auto-generated method stub
		return 0;
	}
	
	
}
