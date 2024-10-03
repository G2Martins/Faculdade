package br.edu.iesb_poo2024_exerciciop1_gustavo_martins;


public class EntregaVeiculoCliente 
{

	private int entregaID;
	private String relatoCliente;
	private String nomeCliente;
	
	public EntregaVeiculoCliente(int entregaID, String relatoCliente, String nomeCliente) {
		super();
		this.entregaID = entregaID;
		this.relatoCliente = relatoCliente;
		this.nomeCliente = nomeCliente;
	}

	public int getEntregaID() {
		return entregaID;
	}
	public void setEntregaID(int entregaID) {
		this.entregaID = entregaID;
	}
	
	public String getRelatoCliente() {
		return relatoCliente;
	}
	public void setRelatoCliente(String relatoCliente) {
		this.relatoCliente = relatoCliente;
	}

	
	public String getNomeCliente() {
		return nomeCliente;
	}
	public void setNomeCliente(String nomeCliente) {
		this.nomeCliente = nomeCliente;
	}
	
	public boolean isEntregaFinalizada(OrdemServico ordemServico) 
	{
		if(ordemServico.isOSfinalizada()) 
		{
	     System.out.println("Entrega Realizada");
	     return true;
	    } else 
	    {
	    	System.out.println("Entrega Não Realizada");
	        return false;
	    }
	 }

	    public EntregaVeiculoCliente cadastrarEntrega(int entregaID, String nome, String relato) {
	        return new EntregaVeiculoCliente(entregaID, relato, nome);
	    }
}


