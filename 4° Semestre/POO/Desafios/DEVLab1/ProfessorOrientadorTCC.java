package br.edu.iesb_poo2024_devlab1;

import java.util.ArrayList;

public class ProfessorOrientadorTCC {
	private int id;
	private int qtdVagasOrientacao;
	private ArrayList<LinhaPesquisaOrientacao> listaLinhaPesquisa;
	
	public ProfessorOrientadorTCC() {}
	
	public int getId() {
		return id;
	}
	
	public void setId(int id) {
		this.id = id;
	}
	
	public int getQtdVagasOrientacao() {
		return qtdVagasOrientacao;
	}
	
	public void setQtdVagasOrientacao(int qtdVagasOrientacao) {
		this.qtdVagasOrientacao = qtdVagasOrientacao;
	}
	
	public ArrayList<LinhaPesquisaOrientacao> getListaLinhaPesquisa() {
		return listaLinhaPesquisa;
	}
	
	public void setListaLinhaPesquisa(ArrayList<LinhaPesquisaOrientacao> listaLinhaPesquisa) {
		this.listaLinhaPesquisa = listaLinhaPesquisa;
	}
	

}
