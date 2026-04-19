package br.edu.iesb_poo2024_atividadeAvaliativa2.controller;

import java.util.ArrayList;
import java.util.List;

import br.edu.iesb_poo2024_atividadeAvaliativa2.model.Produto;

public class ProdutoController {
	private List<Produto> produtos;

	public ProdutoController() {
		this.produtos = new ArrayList<>();
	}

	// Adicionar produtos a partir da Main
	public void adicionarProduto(Produto produto) {
		produtos.add(produto);
	}

	// Listar todos os produtos
	public List<Produto> processarListagemProdutos() {
		return produtos;
	}

	// Buscar produto por ID
	public Produto processarDetalhesProduto(int id) {
		for (Produto produto : produtos) {
			if (produto.getId() == id) {
				return produto;
			}
		}
		return null; // Produto não encontrado
	}
}
