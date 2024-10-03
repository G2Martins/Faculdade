package br.edu.iesb_poo2024_devlab1;

import java.util.Date;

public class TrabalhoConclusaoCurso {
	private int id;
	private String titulo;
	private String objetivo;
	private Date dtInicio;
	private Date dtConclusao;
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getTitulo() {
		return titulo;
	}
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}
	public String getObjetivo() {
		return objetivo;
	}
	public void setObjetivo(String objetivo) {
		this.objetivo = objetivo;
	}
	public Date getDtInicio() {
		return dtInicio;
	}
	public void setDtInicio(Date dtInicio) {
		this.dtInicio = dtInicio;
	}
	public Date getDtConclusao() {
		return dtConclusao;
	}
	public void setDtConclusao(Date dtConclusao) {
		this.dtConclusao = dtConclusao;
	}
	public ProfessorOrientadorTCC getOrientadorTCC() {
		return orientadorTCC;
	}
	public void setOrientadorTCC(ProfessorOrientadorTCC orientadorTCC) {
		this.orientadorTCC = orientadorTCC;
	}
	public Aluno getAlunoAutorTCC() {
		return alunoAutorTCC;
	}
	public void setAlunoAutorTCC(Aluno alunoAutorTCC) {
		this.alunoAutorTCC = alunoAutorTCC;
	}
	private ProfessorOrientadorTCC orientadorTCC;
	private Aluno alunoAutorTCC;
}
