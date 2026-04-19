package br.edu.iesb_poo2024_atividadeAvaliativa1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;

import br.edu.iesb_poo2024_atividadeAvaliativa1.exceptions.ClienteNaoEncontradoException;

public class Main {
    public static void main(String[] args) 
    {
    	try {
    		System.out.println("Gustavo Martins Gripaldi - 2312082034\n");
    		
    		Cliente cliente1 = new Cliente("Mayron Malaquias", "Rua 12 Sul", "9463-8806", "mayron.oliveira@iesb.edu.br", 1, "553.123.634-80", new ArrayList<>());

            Secretaria secretaria1 = new Secretaria("Maria do Carmo", "SQN 102 Bloco B", "9532-8213", "mariaCarmo@gmail.com", 1, "987.634.313-20", "Manhã", new ArrayList<>());

            Animal animal1 = new Animal(1, cliente1.getId(), "Thanos", 2, "M", "Cachorro", "American Bully", "Saudável", new ArrayList<>(), "Vacinação completa", false, "Masculino", 40);

            Veterinario veterinario1 = new Veterinario("Dra. Luisa Massae", "SQS 102 Bloco D", "9884-6675", "luisa.massae@gmail.com", 1, "022.362.313-04", "77820VP", "77813VP", "Clinica Geral");
    		
            // Cadastra cliente e animal
            secretaria1.cadastrarCliente(cliente1);
            cliente1.adicionarAnimal(animal1.getId());
            secretaria1.cadastrarAnimal(animal1);
    		
            // Agenda consulta
            Agendamento agendamento1 = new Agendamento(1, new Date(), "10:00", "Check-up estado Febril e dor nas costas", "Pendente", cliente1.getId(), animal1.getId(), veterinario1.getId());
            secretaria1.agendarConsulta(agendamento1);
            
            // Realiza consulta e solicita exames
            List<String> examesSolicitados = Arrays.asList("Raio-X", "Sangue");
            Consulta consulta1 = new Consulta(1, "Febre e coluna com dores", "Antibiótico e Antiflamatório", examesSolicitados, new ArrayList<>(), "Em andamento", animal1.getId(), agendamento1.getId());

            veterinario1.realizarConsulta(consulta1);
            veterinario1.solicitarExames(animal1, "Raio-X e Exame de Sangue");
    		
            // Registra resultados dos exames
            List<String> resultadosExames = Arrays.asList("Raio-X normal", "Sangue ok");
            consulta1.registrarResultadosExames(resultadosExames);
            veterinario1.registrarResultadosExames(animal1, "Raio-X normal, Sangue ok");
            
            animal1.addConsulta(consulta1);
            
            // Altera o status da consulta e do agendamento
            consulta1.alterarStatusConsulta("Concluída");
            agendamento1.alterarStatusAgendamento("Concluído");
            
            // Cadastra um novo animal para o cliente
            Animal animal2 = new Animal(2, cliente1.getId(), "Barto", 3, "M", "Cachorro", "Spitz Alemão", "Saudável", new ArrayList<>(), "Vacinação completa", false, "Masculino", 4);
            cliente1.adicionarAnimal(animal2.getId());
            secretaria1.cadastrarAnimal(animal2);
            
            // Lista os animais do cliente
            cliente1.listarAnimais();
            
            // Agenda e cancela consulta para o segundo animal
            Agendamento agendamento2 = new Agendamento(2, new Date(), "16:00", "Verificar feridas na barriga", "Pendente", cliente1.getId(), animal2.getId(), veterinario1.getId());
            secretaria1.agendarConsulta(agendamento2);
            secretaria1.cancelarConsulta(agendamento2);
            System.out.println("\n");
            
            // Busca cliente com ID inexistente (tratamento de exceção)
            try {
                secretaria1.buscarCliente(3); // Esse ID não existe
            } catch (ClienteNaoEncontradoException ce) {
                System.out.println(ce.getMessage());
            }
            
            // Busca cliente com ID existente
            try {
                secretaria1.buscarCliente(1); // Esse ID existe
            } catch (ClienteNaoEncontradoException ce) {
                System.out.println(ce.getMessage());
            }
    		
			
		} catch (Exception me) {
			me.printStackTrace();
		}
    }
}
