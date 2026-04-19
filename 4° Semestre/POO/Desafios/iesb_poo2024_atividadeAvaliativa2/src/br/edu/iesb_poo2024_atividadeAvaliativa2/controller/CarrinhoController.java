package br.edu.iesb_poo2024_atividadeAvaliativa2.controller;

import br.edu.iesb_poo2024_atividadeAvaliativa2.exceptions.CarrinhoVazioException;
import br.edu.iesb_poo2024_atividadeAvaliativa2.model.Carrinho;
import br.edu.iesb_poo2024_atividadeAvaliativa2.model.Produto;

public class CarrinhoController {
	private Carrinho carrinho;

	public CarrinhoController(Carrinho carrinho) {
		this.carrinho = carrinho;
	}

	public void processarAdicaoProduto(Produto produto) {
		carrinho.adicionarProduto(produto);
		System.out.println("Produto adicionado ao carrinho: " + produto.getNome());
	}

	public void processarRemocaoProduto(Produto produto) {
		carrinho.removerProduto(produto);
		System.out.println("Produto removido do carrinho: " + produto.getNome());
	}

	public double calcularTotal() throws CarrinhoVazioException {
		if (carrinho.estaVazio()) {
			throw new CarrinhoVazioException("O carrinho está vazio!");
		}
		return carrinho.calcularTotal();
	}
}
