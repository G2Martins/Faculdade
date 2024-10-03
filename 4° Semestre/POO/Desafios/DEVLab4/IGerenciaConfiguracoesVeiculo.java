package br.edu.iesb_poo2024_devlab4_gustavo_martins;

public interface IGerenciaConfiguracoesVeiculo {
	public int obterQuilometragemAtual();
	public int obterQuilometragemRevisao();
	public void emitirAlertaRevisao();
	public void emitirAlertaAcidente();
}
