package AtividadeAvaliativa1.br.edu.iesb_poo2024_atividadeAvaliativa1;

import java.util.List;

public class Consulta {
    private int id;
    private String sintomas;
    private String tratamentos;
    private List<String> examesSolicitados;
    private List<String> resultadosExames;
    private String statusConsulta;
    private int idAnimal;
    private int idAgendamento;
    
    public Consulta(int id, String sintomas, String tratamentos, List<String> examesSolicitados,
            List<String> resultadosExames, String statusConsulta, int idAnimal, int idAgendamento) {
        this.id = id;
        this.sintomas = sintomas;
        this.tratamentos = tratamentos;
        this.examesSolicitados = examesSolicitados;
        this.resultadosExames = resultadosExames;
        this.statusConsulta = statusConsulta;
        this.idAnimal = idAnimal;
        this.idAgendamento = idAgendamento;
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }

    public String getSintomas() {
        return sintomas;
    }
    public void setSintomas(String sintomas) {
        this.sintomas = sintomas;
    }

    public String getTratamentos() {
        return tratamentos;
    }
    public void setTratamentos(String tratamentos) {
        this.tratamentos = tratamentos;
    }

    public List<String> getExamesSolicitados() {
        return examesSolicitados;
    }
    public void setExamesSolicitados(List<String> examesSolicitados) {
        this.examesSolicitados = examesSolicitados;
    }

    public List<String> getResultadosExames() {
        return resultadosExames;
    }
    public void setResultadosExames(List<String> resultadosExames) {
        this.resultadosExames = resultadosExames;
    }

    public String getStatusConsulta() {
        return statusConsulta;
    }
    public void setStatusConsulta(String statusConsulta) {
        this.statusConsulta = statusConsulta;
    }

    public int getIdAnimal() {
        return idAnimal;
    }
    public void setIdAnimal(int idAnimal) {
        this.idAnimal = idAnimal;
    }

    public int getIdAgendamento() {
        return idAgendamento;
    }
    public void setIdAgendamento(int idAgendamento) {
        this.idAgendamento = idAgendamento;
    }


    public void registrarSintomas(String sintomas) {
        this.sintomas = sintomas;
    }

    public void registrarTratamento(String tratamento) {
        this.tratamentos = tratamento;
    }

    public void registrarExamesSolicitados(List<String> exames) {
        this.examesSolicitados = exames;
    }

    public void registrarResultadosExames(List<String> resultados) {
        this.resultadosExames = resultados;
    }

    public void alterarStatusConsulta(String novoStatus) {
        this.statusConsulta = novoStatus;
        System.out.println("\nStatus da Consulta ID " + id + " alterado para: " + novoStatus);
    }

}
