package AtividadeAvaliativa1.br.edu.iesb_poo2024_atividadeAvaliativa1;

import java.util.List;

public class Secretaria extends Pessoa {
    private int id;
    private String cpf;
    private String turnoTrabalho;
    private List<Cliente> clientes;
    
    public Secretaria(String nome, String endereco, String telefone, String email, int id, String cpf, String turnoTrabalho, List<Cliente> clientes) {
        super(nome, endereco, telefone, email);
        this.id = id;
        this.cpf = cpf;
        this.turnoTrabalho = turnoTrabalho;
        this.clientes = clientes;
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }

    public String getCpf() {
        return cpf;
    }
    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getTurnoTrabalho() {
        return turnoTrabalho;
    }
    public void setTurnoTrabalho(String turnoTrabalho) {
        this.turnoTrabalho = turnoTrabalho;
    }

    public void cadastrarCliente(Cliente cliente) {
        clientes.add(cliente);
        System.out.println("Cliente cadastrado: " + cliente.getNome());
    }

    public void cadastrarAnimal(Animal animal) {
        System.out.println("Animal cadastrado: " + animal.getNome());
    }

    public void atualizarCadastroCliente(Cliente cliente) {
        System.out.println("Cadastro do cliente atualizado: " + cliente.getNome());
    }

    public void atualizarCadastroAnimal(Animal animal) {
        System.out.println("Cadastro do animal atualizado: " + animal.getNome());
    }

    public void agendarConsulta(Agendamento agendamento) {
        System.out.println("\nConsulta agendada para o animal ID: " + agendamento.getIdPet());
    }

    public void cancelarConsulta(Agendamento agendamento) {
        agendamento.alterarStatusAgendamento("Cancelada");
        System.out.println("\nConsulta com ID " + agendamento.getId() + " foi cancelada.");
    }

    public void buscarCliente(int id) {
        for (Cliente cliente : clientes) {
            if (cliente.getId() == id) {
                System.out.println("\nCliente encontrado: " + cliente.getNome());
                return;
            }
        }
        System.out.println("\nCliente com ID " + id + " não encontrado.");
    }
}
