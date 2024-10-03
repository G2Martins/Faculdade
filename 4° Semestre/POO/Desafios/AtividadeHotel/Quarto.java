package AtividadeAvaliativaDiogo.br.edu.POO2024;

public class Quarto {
    private int numero;
    private String tipo;
    private boolean reservado;
    private boolean ocupado;
    private double preco;
    private Frigobar frigobar;

    public Quarto(int numero, String tipo, boolean reservado, boolean ocupado) {
        this.numero = numero;
        this.tipo = tipo;
        this.reservado = reservado;
        this.ocupado = ocupado;
        this.frigobar = new Frigobar();
        this.preco = definirPreco(tipo); 
    }

    public int getNumero() {
        return numero;
    }
    public void setNumero(int numero) {
        this.numero = numero;
    }

    public String getTipo() {
        return tipo;
    }
    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public boolean isReservado() {
        return reservado;
    }
    public void setReservado(boolean reservado) {
        this.reservado = reservado;
    }

    public boolean isOcupado() {
        return ocupado;
    }
    public void setOcupado(boolean ocupado) {
        this.ocupado = ocupado;
    }

    public Frigobar getFrigobar() {
        return frigobar;
    }

    public double getPreco() {
        return preco;
    } 

    public boolean reservar() {
        if (!reservado && !ocupado) {
            this.reservado = true;
            return true; 
        } else {
            return false; 
        }
    }

    public void alugar() {
        if (!ocupado) {
            this.ocupado = true;
            this.reservado = false;
        }
    }

    public void liberar() {
        this.reservado = false;
        this.ocupado = false;
    }
    
    private double definirPreco(String tipo) 
    {
        switch (tipo.toLowerCase()) 
        {
            case "solteiro":
                return 100.0;
            case "casal":
                return 150.0;
            case "luxo":
                return 300.0;
            default:
                return 100.0;
        }
    }
}