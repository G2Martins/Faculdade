package br.edu.iesb_poo2024_atividadeAvaliativa2.model;

import br.edu.iesb_poo2024_atividadeAvaliativa2.exceptions.CepInvalidoException;

public class Endereco {
	private int idUsuario;
    private String cep;
    private String logradouro;
    private String bairro;
    private String cidade;
    private double valorFrete;
	
    public Endereco(int idUsuario, String cep, String logradouro, String bairro, String cidade, double valorFrete) {
		this.idUsuario = idUsuario;
		this.cep = cep;
		this.logradouro = logradouro;
		this.bairro = bairro;
		this.cidade = cidade;
		this.valorFrete = valorFrete;
	}

	public int getIdUsuario() {
		return idUsuario;
	}

	public void setIdUsuario(int idUsuario) {
		this.idUsuario = idUsuario;
	}

	public String getCep() {
		return cep;
	}

	public void setCep(String cep) {
		this.cep = cep;
	}

	public String getLogradouro() {
		return logradouro;
	}

	public void setLogradouro(String logradouro) {
		this.logradouro = logradouro;
	}

	public String getBairro() {
		return bairro;
	}

	public void setBairro(String bairro) {
		this.bairro = bairro;
	}

	public String getCidade() {
		return cidade;
	}

	public void setCidade(String cidade) {
		this.cidade = cidade;
	}

	public double getValorFrete() {
		return valorFrete;
	}

	public void setValorFrete(double valorFrete) {
		this.valorFrete = valorFrete;
	}
    
	public void atualizarFrete() throws CepInvalidoException {
        this.valorFrete = Frete.calcularFrete(this.cep);
    }
    
	 @Override
	 public String toString() 
	 {
		 return "Endereço [idUsuario=" + idUsuario + ", cep=" + cep + ", logradouro=" + logradouro +
	               ", bairro=" + bairro + ", cidade=" + cidade + ", valorFrete=" + valorFrete + "]";
	 }
    
}
