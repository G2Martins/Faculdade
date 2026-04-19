package br.edu.iesb_poo2024_atividadeAvaliativa2.controller;

import br.edu.iesb_poo2024_atividadeAvaliativa2.exceptions.CepInvalidoException;
import br.edu.iesb_poo2024_atividadeAvaliativa2.model.Endereco;

public class EnderecoController {
	private Endereco enderecoModel;

	public EnderecoController(Endereco endereco) {
		this.enderecoModel = endereco;
	}

	public void atualizarEndereco(String novoCep, String novoLogradouro, String novoBairro, String novaCidade)
			throws CepInvalidoException {
		enderecoModel.setCep(novoCep);
		enderecoModel.setLogradouro(novoLogradouro);
		enderecoModel.setBairro(novoBairro);
		enderecoModel.setCidade(novaCidade);
		enderecoModel.atualizarFrete(); // Recalcula o frete automaticamente ao atualizar o CEP
		System.out.println("Endereço atualizado com sucesso: " +enderecoModel);
	}

	public void atualizarFrete() throws CepInvalidoException {
		enderecoModel.atualizarFrete(); // Atualiza o frete com base no CEP atual
		System.out.println("Frete atualizado com sucesso. Novo valor: R$ " + enderecoModel.getValorFrete());
	}

	public Endereco buscarEndereco() {
		return enderecoModel; // Retorna o endereço atual
	}

	public void exibirEndereco() {
		System.out.println("Endereço atual: " + enderecoModel);
	}
}
