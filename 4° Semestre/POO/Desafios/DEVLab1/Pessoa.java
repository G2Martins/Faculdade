package br.edu.iesb_poo2024_devlab1;
import java.util.Date;

public class Pessoa {
	private int id;
    protected String nome;
    protected String sobreNome;
    protected Date dtNascimento;
    
    // Construtor padrão
	public Pessoa() {}
	
	public Pessoa(int id, String nome, String sobreNome, Date dtNascimento) {
        super();
		this.id = id;
		this.nome = nome;
		this.sobreNome = sobreNome;
		this.dtNascimento = dtNascimento;
	}
    
    public int getId() {
        return id;
    }
    
    public void setId(int id) {
        this.id = id;
    }
    
    public String getNome() {
        return nome;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    public String getSobreNome() {
        return sobreNome;
    }
    
    public void setSobreNome(String sobreNome) {
        this.sobreNome = sobreNome;
    }
    
    public Date getDtNascimento() {
        return dtNascimento;
    }
    
    public void setDtNascimento(Date dtNascimento) {
        this.dtNascimento = dtNascimento;
    }
    
    
    
}
	
	
	
	
