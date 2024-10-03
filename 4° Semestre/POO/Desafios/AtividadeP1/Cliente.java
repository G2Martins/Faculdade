package AtividadeAvaliativa1.br.edu.iesb_poo2024_atividadeAvaliativa1;

import java.util.List;

public class Cliente extends Pessoa {
    private int id;
    private String cpf;
    private List<Integer> idPet;
    
    public Cliente(String nome, String endereco, String telefone, String email, int id, String cpf, List<Integer> idPet) {
        super(nome, endereco, telefone, email);
        this.id = id;
        this.cpf = cpf;
        this.idPet = idPet;
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

    public List<Integer> getIdPet() {
        return idPet;
    }
    public void setIdPet(List<Integer> idPet) {
        this.idPet = idPet;
    }
    
    
    public void adicionarAnimal(int idPet) {
        this.idPet.add(idPet);
    }
    
    public void removerAnimal(int idPet) 
    {
        if (this.idPet.contains(idPet)) 
        {
            this.idPet.remove(Integer.valueOf(idPet)); 
        } else {
            System.out.println("Animal com ID " + idPet + " não encontrado.");
        }
    }

    public void listarAnimais() 
    {
        if (idPet.isEmpty()) 
        {
            System.out.println("Nenhum animal registrado para este cliente.");
        } else {
            System.out.println("\nAnimais do cliente " + getNome() + ":");
            
            for (int id : idPet) 
            {
                System.out.println("ID do Animal: " + id);
            }
        }
    }

    public void atualizarDadosPessoais(String endereco, String telefone, String email) 
    {
        setEndereco(endereco);
        setTelefone(telefone);
        setEmail(email);
    }
}
