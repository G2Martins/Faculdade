package AtividadeAvaliativaDiogo.br.edu.POO2024;

import java.util.ArrayList;

public class Hotel {
    private ArrayList<Quarto> quartos;
    private ArrayList<Servico> servicos;
    private ArrayList<Hospede> hospedes;
    private ArrayList<Reserva> reservas;

    public Hotel() {
        quartos = new ArrayList<>();
        servicos = new ArrayList<>();
        hospedes = new ArrayList<>();
        reservas = new ArrayList<>();
    }

    public ArrayList<Quarto> getQuartos() {
        return quartos;
    }
    public void setQuartos(ArrayList<Quarto> quartos) {
        this.quartos = quartos;
    }

    public ArrayList<Servico> getServicos() {
        return servicos;
    }
    public void setServicos(ArrayList<Servico> servicos) {
        this.servicos = servicos;
    }

    public ArrayList<Hospede> getHospedes() {
        return hospedes;
    }
    public void setHospedes(ArrayList<Hospede> hospedes) {
        this.hospedes = hospedes;
    }

    public ArrayList<Reserva> getReservas() {
        return reservas;
    }
    public void setReservas(ArrayList<Reserva> reservas) {
        this.reservas = reservas;
    }


    public void cadastrarHospede(Hospede hospede) {
        hospedes.add(hospede);
    }

    public void adicionarQuarto(Quarto quarto) {
        quartos.add(quarto);
    }

    public void adicionarServico(Servico servico) {
        servicos.add(servico);
    }

    public Quarto buscarQuartoDisponivel() {
        for (Quarto quarto : quartos) {
            if (!quarto.isOcupado() && !quarto.isReservado()) {
                return quarto;
            }
        }
        return null;
    }

    public void realizarReserva(Hospede hospede, Quarto quarto, String dataReserva) {
        Reserva reserva = new Reserva(hospede, quarto, dataReserva);
        reservas.add(reserva);
    }
}
