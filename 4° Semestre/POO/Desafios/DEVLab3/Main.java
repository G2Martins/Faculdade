package br.edu.iesb_poo2024_devlab3_gustavo_martins;

public class Main {

	public static void main(String[] args) {
		
		// Mais Genérico
		ClasseAbstrataOO concreta1 = new ClasseConcreta();
		concreta1.printMensagem();
		concreta1.metodoConcreto();
		System.out.println(concreta1.msg);
		concreta1.msg = "Essa classe nao é abstrata!";
		System.out.println(concreta1.msg);
		
		System.out.println("\n ----------- ");
		
		// Mais Especializado
		ClasseConcreta2 concreta2 = new ClasseConcreta2();	
		concreta2.printMensagem();
		concreta2.metodoConcreto();
		
		System.out.println("\n ----------- ");
		
		System.out.println(IGerenciaArquivo.TIPO_ARQUIVO_CSV);	
		// Não pode alterar
		// IGerenciaArquivo = " "
		ClasseConcreta3 concreta3 = new ClasseConcreta3();
		concreta3.lerArquivoDisco(null, false);
	
	}

}
