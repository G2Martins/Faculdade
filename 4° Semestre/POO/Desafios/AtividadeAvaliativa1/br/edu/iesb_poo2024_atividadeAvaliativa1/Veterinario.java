package AtividadeAvaliativa1.br.edu.iesb_poo2024_atividadeAvaliativa1;

public class Veterinario extends Pessoa {
    private int id;
    private String cpf;
    private String nrCRMV;
    private String nrCFMV;
    private String especialidade;
    
    public Veterinario(String nome, String endereco, String telefone, String email, int id, String cpf, String nrCRMV, String nrCFMV, String especialidade) {
        super(nome, endereco, telefone, email);
        this.id = id;
        this.cpf = cpf;
        this.nrCRMV = nrCRMV;
        this.nrCFMV = nrCFMV;
        this.especialidade = especialidade;
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

    public String getNrCRMV() {
        return nrCRMV;
    }
    public void setNrCRMV(String nrCRMV) {
        this.nrCRMV = nrCRMV;
    }

    public String getNrCFMV() {
        return nrCFMV;
    }
    public void setNrCFMV(String nrCFMV) {
        this.nrCFMV = nrCFMV;
    }

    public String getEspecialidade() {
        return especialidade;
    }
    public void setEspecialidade(String especialidade) {
        this.especialidade = especialidade;
    }

    public void realizarConsulta(Consulta consulta) {
        System.out.println("Consulta realizada para o animal ID: " + consulta.getIdAnimal());
    }

    public void solicitarExames(Animal animal, String exames) {
        System.out.println("Exames solicitados para o animal: " + animal.getNome() + ". Exames: " + exames);
    }

    public void registrarResultadosExames(Animal animal, String resultados) {
        System.out.println("Resultados dos exames do animal: " + animal.getNome() + ". Resultados: " + resultados);
    }
}
