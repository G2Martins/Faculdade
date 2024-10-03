package br.edu.iesb_poo2024_devlab1;

import java.util.Date;

public class CoordenadorCurso extends Pessoa {
	private int id;
	private String departamento;
	private Date dtContracao;
	
	public CoordenadorCurso() {}
	
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getDepartamento() {
		return departamento;
	}
	public void setDepartamento(String departamento) {
		this.departamento = departamento;
	}
	public Date getDtContracao() {
		return dtContracao;
	}
	public void setDtContracao(Date dtContracao) {
		this.dtContracao = dtContracao;
	}
}
