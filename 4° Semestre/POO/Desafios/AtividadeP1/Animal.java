package AtividadeAvaliativa1.br.edu.iesb_poo2024_atividadeAvaliativa1;

import java.util.List;

public class Animal {
    private int id;
    private int idCliente;
    private String nome;
    private int idade;
    private String sexo;
    private String especie;
    private String raca;
    private String historicoMedico;
    private List<Consulta> historicoConsultas;
    private String dadosVacinacao;
    private boolean isCadastrado;
    private String genero;
    private int peso;
    
    public Animal(int id, int idCliente, String nome, int idade, String sexo, String especie, String raca,
            String historicoMedico, List<Consulta> historicoConsultas, String dadosVacinacao, boolean isCadastrado,
            String genero, int peso) {
        this.id = id;
        this.idCliente = idCliente;
        this.nome = nome;
        this.idade = idade;
        this.sexo = sexo;
        this.especie = especie;
        this.raca = raca;
        this.historicoMedico = historicoMedico;
        this.historicoConsultas = historicoConsultas;
        this.dadosVacinacao = dadosVacinacao;
        this.isCadastrado = isCadastrado;
        this.genero = genero;
        this.peso = peso;
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }

    public int getIdCliente() {
        return idCliente;
    }
    public void setIdCliente(int idCliente) {
        this.idCliente = idCliente;
    }

    public int getPeso() {
        return peso;
    }
    public void setPeso(int peso) {
        this.peso = peso;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getSexo() {
        return sexo;
    }
    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public String getEspecie() {
        return especie;
    }
    public void setEspecie(String especie) {
        this.especie = especie;
    }

    public String getRaca() {
        return raca;
    }
    public void setRaca(String raca) {
        this.raca = raca;
    }

    public String getHistoricoMedico() {
        return historicoMedico;
    }
    public void setHistoricoMedico(String historicoMedico) {
        this.historicoMedico = historicoMedico;
    }

    public List<Consulta> getHistoricoConsultas() {
        return historicoConsultas;
    }
    public void setHistoricoConsultas(List<Consulta> historicoConsultas) {
        this.historicoConsultas = historicoConsultas;
    }

    public String getDadosVacinacao() {
        return dadosVacinacao;
    }
    public void setDadosVacinacao(String dadosVacinacao) {
        this.dadosVacinacao = dadosVacinacao;
    }

    public boolean isCadastrado() {
        return isCadastrado;
    }
    public void setCadastrado(boolean isCadastrado) {
        this.isCadastrado = isCadastrado;
    }

    public String getGenero() {
        return genero;
    }
    public void setGenero(String genero) {
        this.genero = genero;
    }

    
    public void addConsulta(Consulta consulta) {
        this.historicoConsultas.add(consulta);
    }

    public void atualizarDadosVacinacao(String dadosVacinacao) {
        this.dadosVacinacao = dadosVacinacao;
    }
}
