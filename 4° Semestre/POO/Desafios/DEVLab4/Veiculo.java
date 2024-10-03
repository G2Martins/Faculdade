package br.edu.iesb_poo2024_devlab4_gustavo_martins;

public abstract class Veiculo {
	
	protected String nrPlaca;
	protected String cor;
	protected String marca;
	protected String modelo;
	protected String tipo;
	protected boolean isExigeLicencaDiferente;

	//Abstratos
	public abstract void acelerar();
	public abstract void freiar();
	public abstract void fazerCurva();
	
	// Método Concreto
	public void emitirAlertaSonoro() {
		System.out.println(">> Alerta de colisão!");
	}
	
	
	public String getNrPlaca() {
		return nrPlaca;
	}
	public void setNrPlaca(String nrPlaca) {
		this.nrPlaca = nrPlaca;
	}
	
	public String getCor() {
		return cor;
	}
	public void setCor(String cor) {
		this.cor = cor;
	}
	
	public String getMarca() {
		return marca;
	}
	public void setMarca(String marca) {
		this.marca = marca;
	}
	
	public String getModelo() {
		return modelo;
	}
	public void setModelo(String modelo) {
		this.modelo = modelo;
	}
	
	public String getTipo() {
		return tipo;
	}
	public void setTipo(String tipo) {
		this.tipo = tipo;
	}
	
	public boolean isExigeLicencaDiferente() {
		return isExigeLicencaDiferente;
	}
	public void setExigeLicencaDiferente(boolean isExigeLicencaDiferente) {
		this.isExigeLicencaDiferente = isExigeLicencaDiferente;
	}

	
	
	
}
