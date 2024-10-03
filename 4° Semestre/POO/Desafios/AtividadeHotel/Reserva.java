package AtividadeAvaliativaDiogo.br.edu.POO2024;

public class Reserva {
    private static int contadorReservas = 1;
    private int id;
    private Hospede hospede;
    private Quarto quarto;
    private String dataReserva;
    
    public Reserva(Hospede hospede, Quarto quarto, String dataReserva) {
        this.id = contadorReservas++;
        this.hospede = hospede;
        this.quarto = quarto;
        this.dataReserva = dataReserva;
        quarto.reservar();
    }

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }

    public Hospede getHospede() {
        return hospede;
    }
    public void setHospede(Hospede hospede) {
        this.hospede = hospede;
    }

    public Quarto getQuarto() {
        return quarto;
    }
    public void setQuarto(Quarto quarto) {
        this.quarto = quarto;
    }

    public String getDataReserva() {
        return dataReserva;
    }
    public void setDataReserva(String dataReserva) {
        this.dataReserva = dataReserva;
    }
}
