package br.edu.iesb_poo2024_atividadeAvaliativa2.model;

import java.util.ArrayList;
import java.util.List;

public class Carrinho {
	private int usuarioID;
	private List<Produto> produtos;

	public Carrinho(int usuarioID) {
		this.usuarioID = usuarioID;
		this.produtos = new ArrayList<>();
	}

	public int getUsuarioID() {
		return usuarioID;
	}

	public void setUsuarioID(int usuarioID) {
		this.usuarioID = usuarioID;
	}

	public List<Produto> getProdutos() {
		return produtos;
	}

	public void adicionarProduto(Produto produto) {
		produtos.add(produto);
	}

	public void removerProduto(Produto produto) {
		if (produtos.contains(produto)) {
			produtos.remove(produto);
		} else {
			System.err.println("Produto não está no carrinho.");
		}
	}

	public boolean estaVazio() {
		return produtos.isEmpty();
	}

	public double calcularTotal() {
		double total = 0.0;
		for (Produto produto : produtos) {
			total += produto.getPreco();
		}
		return total;
	}
}
