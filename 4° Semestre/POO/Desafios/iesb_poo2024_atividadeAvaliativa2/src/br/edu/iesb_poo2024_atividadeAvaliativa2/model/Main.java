package br.edu.iesb_poo2024_atividadeAvaliativa2.model;

import java.util.List;

import br.edu.iesb_poo2024_atividadeAvaliativa2.controller.CarrinhoController;
import br.edu.iesb_poo2024_atividadeAvaliativa2.controller.PlanoController;
import br.edu.iesb_poo2024_atividadeAvaliativa2.controller.ProdutoController;
import br.edu.iesb_poo2024_atividadeAvaliativa2.exceptions.CarrinhoVazioException;
import br.edu.iesb_poo2024_atividadeAvaliativa2.exceptions.CepInvalidoException;

public class Main {

	public static void main(String[] args) {
		try {
			System.out.println("=====================================");
			System.out.println("Gustavo Martins Gripaldi - 2312082034");
			System.out.println("=====================================\n\n");
			
			// 1. Criar usuário
			Usuario usuario = new Usuario(1, "Gustavo", "09376285180", "gustavogripaldi@outlook.com", "71925-720", 1);
			System.out.println("Usuário criado: " + usuario.getNome() + ", CEP: " + usuario.getCep());

			// 2. Criar endereço do usuário
			Endereco endereco = new Endereco(usuario.getId(), usuario.getCep(), "Rua 22 Sul", "Àguas Claras",
					"Brasília", 0.0 // Valor inicial do frete
			);
			endereco.atualizarFrete(); // Atualiza o valor do frete
			System.out.println("Endereço do usuário: " + endereco);

			// 3. Criar um plano e processar a inclusão/alteração
			Plano plano = new Plano(1, "Plano Premium", 29.99, "Acesso ilimitado a todos os recursos");
			PlanoController planoController = new PlanoController(plano);
			planoController.processarInclusao("Plano Básico", 19.99, "Acesso básico aos recursos");
			planoController.processarAlteracao("Plano Avançado", 49.99, "Recursos avançados");
			System.out.println("Plano atualizado para: " + plano.getNome() + ", Preço: R$ " + plano.getValor());

			// 4. Adicionar produtos ao ProdutoController
			ProdutoController produtoController = new ProdutoController();
			produtoController.adicionarProduto(new Produto(1, "Smartphone Samsung Galaxy", 1500.00));
			produtoController.adicionarProduto(new Produto(2, "Notebook Dell Inspiron", 3500.00));
			produtoController.adicionarProduto(new Produto(3, "Fone de Ouvido JBL", 250.00));
			produtoController.adicionarProduto(new Produto(4, "Smart TV LG 50", 2800.00));

			// Listar produtos disponíveis
			System.out.println("\nLista de produtos disponíveis:");
			List<Produto> produtos = produtoController.processarListagemProdutos();
			for (Produto p : produtos) {
				System.out.println("ID: " + p.getId() + ", Nome: " + p.getNome() + ", Preço: R$ " + p.getPreco());
			}

			// Exibir detalhes de um produto específico
			Produto produtoDetalhe = produtoController.processarDetalhesProduto(2);
			if (produtoDetalhe != null) {
				System.out.println("\nDetalhes do Produto ID 2: " + produtoDetalhe.getNome() + ", Preço: R$ "
						+ produtoDetalhe.getPreco());
			} else {
				System.out.println("Produto não encontrado.");
			}

			// 5. Criar carrinho e adicionar produtos
			Carrinho carrinho = new Carrinho(usuario.getId());
			CarrinhoController carrinhoController = new CarrinhoController(carrinho);

			carrinhoController.processarAdicaoProduto(produtoController.processarDetalhesProduto(1)); // Galaxy
			carrinhoController.processarAdicaoProduto(produtoController.processarDetalhesProduto(2)); // Dell
			carrinhoController.processarAdicaoProduto(produtoController.processarDetalhesProduto(3)); // JBL

			System.out.println("\nProdutos adicionados ao carrinho do usuário " + usuario.getNome());

			// Exibir produtos no carrinho
			System.out.println("\nProdutos no carrinho:");
			for (Produto produto : carrinho.getProdutos()) {
				System.out.println("ID: " + produto.getId() + ", Nome: " + produto.getNome() + ", Preço: R$ "
						+ produto.getPreco());
			}

			// 6. Calcular total do carrinho e adicionar frete
			try {
				double totalCarrinho = carrinhoController.calcularTotal();
				double frete = endereco.getValorFrete(); // Obtém o valor do frete atualizado pelo endereço

				System.out.println("\nResumo do Carrinho:");
				System.out.println("Total dos Produtos: R$ " + totalCarrinho);
				System.out.println("Frete: R$ " + frete);
				System.out.println("Total Geral (Produtos + Frete): R$ " + (totalCarrinho + frete));
			} catch (CarrinhoVazioException e) {
				System.err.println("Erro: O carrinho está vazio!");
			}

		} catch (CepInvalidoException e) {
			System.err.println("Erro: " + e.getMessage());
		} catch (Exception e) {
			System.err.println("Erro inesperado: " + e.getMessage());
		}
	}
}
