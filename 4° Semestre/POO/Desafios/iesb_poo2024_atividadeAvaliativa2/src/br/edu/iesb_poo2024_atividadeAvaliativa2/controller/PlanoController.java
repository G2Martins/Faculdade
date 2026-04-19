package br.edu.iesb_poo2024_atividadeAvaliativa2.controller;

import br.edu.iesb_poo2024_atividadeAvaliativa2.model.Plano;

public class PlanoController {
	private Plano planoModel;

	public PlanoController(Plano planoModel) {
		this.planoModel = planoModel;
	}

	public void processarInclusao(String nome, double valor, String descricao) {
		planoModel.setNome(nome);
		planoModel.setValor(valor);
		planoModel.setDescricao(descricao);
		planoModel.incluirPlano();
	}

	public void processarAlteracao(String nome, double valor, String descricao) {
		planoModel.setNome(nome);
		planoModel.setValor(valor);
		planoModel.setDescricao(descricao);
		planoModel.alterarPlano();
	}
}
