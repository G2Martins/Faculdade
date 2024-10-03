package br.edu.iesb_poo2024_exerciciop1_gustavo_martins;

public class Veiculo {
	private String marca;
	private String modelo;
	private String placa;
	private int ano;
	private double quilometragemTotal;
	private String nomeProprietario;
	private String cpfProprietario;
	
	
	public Veiculo(String marca, String modelo, String placa, int ano, double quilometragemTotal,
			String nomeProprietario, String cpfProprietario) {
		super();
		this.marca = marca;
		this.modelo = modelo;
		this.placa = placa;
		this.ano = ano;
		this.quilometragemTotal = quilometragemTotal;
		this.nomeProprietario = nomeProprietario;
		this.cpfProprietario = cpfProprietario;
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
	
	public String getPlaca() {
		return placa;
	}
	public void setPlaca(String placa) {
		this.placa = placa;
	}
	
	public int getAno() {
		return ano;
	}
	public void setAno(int ano) {
		this.ano = ano;
	}
	
	public double getQuilometragemTotal() {
		return quilometragemTotal;
	}
	public void setQuilometragemTotal(double quilometragemTotal) {
		this.quilometragemTotal = quilometragemTotal;
	}
	
	public String getNomeProprietario() {
		return nomeProprietario;
	}
	public void setNomeProprietario(String nomeProprietario) {
		this.nomeProprietario = nomeProprietario;
	}
	
	public String getCpfProprietario() {
		return cpfProprietario;
	}
	public void setCpfProprietario(String cpfProprietario) {
		this.cpfProprietario = cpfProprietario;
	} 
	
	public boolean isVeiculoCadastrado(String placa) {
	        return this.placa.equals(placa);
	}

	public void printInformacoesCompletas() 
	{
		System.out.println("Marca: " + this.marca);
		System.out.println("Modelo: " + this.modelo);
	    System.out.println("Placa: " + this.placa);
	    System.out.println("Ano: " + this.ano);
	    System.out.println("Quilometragem: " + this.quilometragemTotal);
	    System.out.println("Proprietário: " + this.nomeProprietario);
	    System.out.println("CPF: " + this.cpfProprietario);
	    }
	}

	
	
