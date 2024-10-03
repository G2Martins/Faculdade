package AtividadeAvaliativa1.br.edu.iesb_poo2024_atividadeAvaliativa1;

import java.util.Date;

public class Agendamento {
    private int id;
    private Date data;
    private String horario;
    private String objetivoConsulta;
    private String statusAgendamento;
    private int idCliente;
    private int idPet;
    private int idVeterinario;
    
    public Agendamento(int id, Date data, String horario, String objetivoConsulta, String statusAgendamento,
            int idCliente, int idPet, int idVeterinario) {
        this.id = id;
        this.data = data;
        this.horario = horario;
        this.objetivoConsulta = objetivoConsulta;
        this.statusAgendamento = statusAgendamento;
        this.idCliente = idCliente;
        this.idPet = idPet;
        this.idVeterinario = idVeterinario;
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }

    public Date getData() {
        return data;
    }
    public void setData(Date data) {
        this.data = data;
    }

    public String getHorario() {
        return horario;
    }
    public void setHorario(String horario) {
        this.horario = horario;
    }

    public String getObjetivoConsulta() {
        return objetivoConsulta;
    }
    public void setObjetivoConsulta(String objetivoConsulta) {
        this.objetivoConsulta = objetivoConsulta;
    }

    public String getStatusAgendamento() {
        return statusAgendamento;
    }
    public void setStatusAgendamento(String statusAgendamento) {
        this.statusAgendamento = statusAgendamento;
    }

    public int getIdCliente() {
        return idCliente;
    }
    public void setIdCliente(int idCliente) {
        this.idCliente = idCliente;
    }

    public int getIdPet() {
        return idPet;
    }
    public void setIdPet(int idPet) {
        this.idPet = idPet;
    }

    public int getIdVeterinario() {
        return idVeterinario;
    }
    public void setIdVeterinario(int idVeterinario) {
        this.idVeterinario = idVeterinario;
    }

    public void alterarAgendamento(Date novaData, String novoHorario, String novoObjetivoConsulta) {
        this.data = novaData;
        this.horario = novoHorario;
        this.objetivoConsulta = novoObjetivoConsulta;
        System.out.println("Agendamento alterado para nova data: " + novaData + " e horário: " + novoHorario);
    }

    public void alterarStatusAgendamento(String novoStatus) {
        this.statusAgendamento = novoStatus;
        System.out.println("Status do agendamento ID " + id + " alterado para: " + novoStatus + "\n");
    }
}
