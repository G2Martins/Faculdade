package br.edu.iesb_poo2024_devlab3_gustavo_martins;

public class ClasseConcreta extends ClasseAbstrataOO {

	@Override
	public void printMensagem() {
		
		System.out.println(">> printMensagem(): " + getClass());
	}

	@Override
	public void metodoConcreto() {
		System.out.println(">> metodoConcreto(): " + getClass());
	}

	
}
