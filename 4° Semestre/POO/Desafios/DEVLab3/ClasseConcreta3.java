package br.edu.iesb_poo2024_devlab3_gustavo_martins;

public class ClasseConcreta3 implements IGerenciaArquivo {

	@Override
	public void lerArquivoDisco(String pathArquivo, boolean isPrint) {
		System.out.println(">> " + getClass());
		
	}

}
