package AtividadeAvaliativaDiogo.br.edu.POO2024;

import java.util.ArrayList;

public class Fatura {
    private ArrayList<Double> diarias;
    private ArrayList<Servico> servicos;
    private ArrayList<Double> frigobar;
    private boolean quitada;
    
    public Fatura() {
        this.diarias = new ArrayList<>();
        this.servicos = new ArrayList<>();
        this.frigobar = new ArrayList<>();
        this.quitada = false;
    }

    public ArrayList<Double> getDiarias() {
        return diarias;
    }
    public void setDiarias(ArrayList<Double> diarias) {
        this.diarias = diarias;
    }

    public ArrayList<Servico> getServicos() {
        return servicos;
    }
    public void setServicos(ArrayList<Servico> servicos) {
        this.servicos = servicos;
    }

    public ArrayList<Double> getFrigobar() {
        return frigobar;
    }
    public void setFrigobar(ArrayList<Double> frigobar) {
        this.frigobar = frigobar;
    }

    public boolean isQuitada() {
        return quitada;
    }
    public void setQuitada(boolean quitada) {
        this.quitada = quitada;
    }

    public void adicionarDiaria(double valor) {
        diarias.add(valor);
    }

    public void adicionarServico(Servico servico) {
        servicos.add(servico);
    }

    public void adicionarFrigobar(double valor) {
        frigobar.add(valor);
    }

    public double calcularTotal() {
        double total = 0;
        for (double diaria : diarias) {
            total += diaria;
        }
        for (Servico servico : servicos) {
            total += servico.getValor();
        }
        for (double item : frigobar) {
            total += item;
        }
        return total;
    }

    public void quitar() {
        this.quitada = true;
    }
}
