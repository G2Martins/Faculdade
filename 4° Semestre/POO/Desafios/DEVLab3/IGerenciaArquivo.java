package br.edu.iesb_poo2024_devlab3_gustavo_martins;

public interface IGerenciaArquivo {
	
	public static final String TIPO_ARQUIVO_CSV = ".csv";
	public static final String TIPO_ARQUIVO_TXT = ".txt";
	
	public void lerArquivoDisco(String pathArquivo, boolean isPrint);
}
