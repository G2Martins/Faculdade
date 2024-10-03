package br.edu.iesb_poo2024_exerciciop1_gustavo_martins;

public class OrdemServico {
	
	private int numeroOS;
	private String nomeResponsavelTecnico;
	private String nomeMecanico;
	private boolean isAutorizadoLavagem;
	private boolean isOSfinalizada = false;
	private String relatosDefeitoCliente;
	
	public OrdemServico(int numeroOS, String nomeResponsavelTecnico, String nomeMecanico, boolean isAutorizadoLavagem,
			boolean isOSfinalizada, String relatosDefeitoCliente) {
		super();
		this.numeroOS = numeroOS;
		this.nomeResponsavelTecnico = nomeResponsavelTecnico;
		this.nomeMecanico = nomeMecanico;
		this.isAutorizadoLavagem = isAutorizadoLavagem;
		this.isOSfinalizada = isOSfinalizada;
		this.relatosDefeitoCliente = relatosDefeitoCliente;
	}
	public int getNumeroOS() {
		return numeroOS;
	}
	public void setNumeroOS(int numeroOS) {
		this.numeroOS = numeroOS;
	}
	
	public String getNomeResponsavelTecnico() {
		return nomeResponsavelTecnico;
	}
	public void setNomeResponsavelTecnico(String nomeResponsavelTecnico) {
		this.nomeResponsavelTecnico = nomeResponsavelTecnico;
	}
	
	public String getNomeMecanico() {
		return nomeMecanico;
	}
	public void setNomeMecanico(String nomeMecanico) {
		this.nomeMecanico = nomeMecanico;
	}
	
	public boolean isAutorizadoLavagem() {
		return isAutorizadoLavagem;
	}
	public void setAutorizadoLavagem(boolean isAutorizadoLavagem) {
		this.isAutorizadoLavagem = isAutorizadoLavagem;
	}
	
	public boolean isOSfinalizada() {
		return isOSfinalizada;
	}
	public void setOSfinalizada(boolean isOSfinalizada) {
		this.isOSfinalizada = isOSfinalizada;
	}
	
	public String getRelatosDefeitoCliente() {
		return relatosDefeitoCliente;
	}
	public void setRelatosDefeitoCliente(String relatosDefeitoCliente) {
		this.relatosDefeitoCliente = relatosDefeitoCliente;
	}
	
}
