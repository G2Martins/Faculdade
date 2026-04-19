package br.edu.iesb_poo2024_atividadeAvaliativa2.model;

public class Usuario extends Pessoa {
	private int id;
	private String cep;
	private int planoID;

	public Usuario(int id, String nome, String cpf, String email, String cep, int planoID) {
		super();
		this.id = id;
		this.nome = nome;
		this.cpf = cpf;
		this.email = email;
		this.cep = cep;
		this.planoID = planoID;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getCep() {
		return cep;
	}

	public void setCep(String cep) {
		this.cep = cep;
	}

	public int getPlanoID() {
		return planoID;
	}

	public void setPlanoID(int planoID) {
		this.planoID = planoID;
	}

}
