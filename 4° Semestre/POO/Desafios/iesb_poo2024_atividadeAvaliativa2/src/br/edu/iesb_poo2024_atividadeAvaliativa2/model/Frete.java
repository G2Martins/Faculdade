package br.edu.iesb_poo2024_atividadeAvaliativa2.model;

import br.edu.iesb_poo2024_atividadeAvaliativa2.exceptions.CepInvalidoException;

public class Frete {
	public static double calcularFrete(String cep) throws CepInvalidoException {
        if (cep == null || cep.isEmpty()) {
            throw new CepInvalidoException("CEP inválido!");
        }
        
        if (cep.startsWith("1") || cep.startsWith("2") || cep.startsWith("3")) {
            return 0.0; 
        }
        return 10.50;
    }
}
