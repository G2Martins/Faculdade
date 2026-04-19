package br.edu.iesb_poo2024_atividadeAvaliativa2.model;

public class Plano {
	private int id;
	private String nome;
	private double valor;
	private String descricao;

	public Plano(int id, String nome, double valor, String descricao) {
		this.id = id;
		this.nome = nome;
		this.valor = valor;
		this.descricao = descricao;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double getValor() {
		return valor;
	}

	public void setValor(double valor) {
		this.valor = valor;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public void incluirPlano() {
		System.out.println("Plano " + nome + " incluído com sucesso!");
	}

	public void alterarPlano() {
		System.out.println("Plano " + nome + " alterado com sucesso!");
	}

	public void cancelarPlano() {
		System.out.println("Plano " + nome + " cancelado.");
	}

}
