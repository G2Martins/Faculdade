package br.edu.iesb_poo2024_devlab1;

import java.util.Date;

public class Aluno extends Pessoa {
	private int id;
	private String nrMatricula;
	private String nomeCurso;
	private int  nrSemestre;
	private Date dtMatricula;
	
	public Aluno() {}
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getNrMatricula() {
		return nrMatricula;
	}
	public void setNrMatricula(String nrMatricula) {
		this.nrMatricula = nrMatricula;
	}
	public String getNomeCurso() {
		return nomeCurso;
	}
	public void setNomeCurso(String nomeCurso) {
		this.nomeCurso = nomeCurso;
	}
	public int getNrSemestre() {
		return nrSemestre;
	}
	public void setNrSemestre(int nrSemestre) {
		this.nrSemestre = nrSemestre;
	}
	public Date getDtMatricula() {
		return dtMatricula;
	}
	public void setDtMatricula(Date dtMatricula) {
		this.dtMatricula = dtMatricula;
	}
}
