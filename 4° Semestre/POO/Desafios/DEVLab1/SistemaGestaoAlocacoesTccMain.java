package br.edu.iesb_poo2024_devlab1;

import java.util.ArrayList;

/*
 Instituição: IESB
 Disciplina: Programação Orientada a objetos (POO)
 Objetivo: Fornecer conhecimentos e práticas de programção orientada a objetos.
 Professor: Bruno Miranda [bruno.marcos@iesb.edu.br]
 Data: 2024/25
 
 # Prática DevLab1 - Trabalhando com classes, objetos e Herança em Java
*/

public class SistemaGestaoAlocacoesTccMain {

	public static void main(String[] args) {
		// Cadastrados básicos do Professor e do Aluno
		Professor professor = new Professor();
		professor.setNome("João");
		professor.setCargoProfessor("Professor Assistente");
		
		Aluno aluno = new Aluno();
		aluno.setNome("Maria");
		aluno.setNrSemestre(7);
		aluno.setNomeCurso("Ciência da Computação");
		
		// Cadastro da linha de pesquisa e do orientador
		LinhaPesquisaOrientacao linhaPesquisa = new LinhaPesquisaOrientacao(1, "Desenvolvimento de Software", "Técnicas de desenvolvimento em OO");
		
		ArrayList<LinhaPesquisaOrientacao> listaLinhasPesquisa = new ArrayList<LinhaPesquisaOrientacao>();
		listaLinhasPesquisa.add(linhaPesquisa);
		
		ProfessorOrientadorTCC orientadorTCC = new ProfessorOrientadorTCC();
		orientadorTCC.setQtdVagasOrientacao(2);
		orientadorTCC.setListaLinhaPesquisa(listaLinhasPesquisa);
		
		//Cadastro do TCC 
		TrabalhoConclusaoCurso tcc = new TrabalhoConclusaoCurso();
		tcc.setAlunoAutorTCC(aluno);
		tcc.setOrientadorTCC(orientadorTCC);
		tcc.setTitulo("Implementação de Sistema de informação para a empresa XYZ");
		
		System.out.println("Professor Cadastrado: " + professor.getNome());
		System.out.println("Aluno Cadastrado " + aluno.getNome());
		System.out.println("TCC Cadastrado: d" + tcc.getTitulo());
		
	}
}
