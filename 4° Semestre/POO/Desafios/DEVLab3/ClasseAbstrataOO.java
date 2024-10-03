package br.edu.iesb_poo2024_devlab3_gustavo_martins;

public abstract class ClasseAbstrataOO {
	
	protected String msg = "Essa classe é abstrata!";
	
	// Método abstrato
	public abstract void printMensagem();
	
	// Método concreto precisa inicializar o bloco
	public void metodoConcreto() {
		System.out.println("Método concreto () da Classe Abstrata");
	}
}
