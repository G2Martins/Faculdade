package AtividadeAvaliativa1.br.edu.iesb_poo2024_atividadeAvaliativa1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;

public class Main {
    public static void main(String[] args) 
    {
        Cliente cliente1 = new Cliente("Mayron Malaquias", "Rua 12 Sul", "9463-8806", "mayron.oliveira@iesb.edu.br", 1, "553.123.634-80", new ArrayList<>());

        Secretaria secretaria1 = new Secretaria("Maria do Carmo", "SQN 102 Bloco B", "9532-8213", "mariaCarmo@gmail.com", 1, "987.634.313-20", "Manhã", new ArrayList<>());
        
        Animal animal1 = new Animal(1, cliente1.getId(), "Thanos", 2, "M", "Cachorro", "American buly", "Saudável", new ArrayList<>(), "Vacinação completa", false, "Masculino", 40);
        
        Veterinario veterinario1 = new Veterinario("Dra. Luisa Massae", "SQS 102 Bloco D", "9884-6675", "luisa.massae@gmail.com", 1, "022.362.313-04", "77820VP", "77813VP", "Clinica Geral");
        
        secretaria1.cadastrarCliente(cliente1);
        cliente1.adicionarAnimal(animal1.getId());
        secretaria1.cadastrarAnimal(animal1);

        Agendamento agendamento1 = new Agendamento(1, new Date(), "10:00", "Check-up estado Febril e dor nas costas", "Pendente", cliente1.getId(), animal1.getId(), veterinario1.getId());
        secretaria1.agendarConsulta(agendamento1);

        List<String> examesSolicitados = Arrays.asList("Raio-X", "Sangue");
        Consulta consulta1 = new Consulta(1, "Febre e coluna com dores", "Antibiótico e Antiflamatório", examesSolicitados, new ArrayList<>(), "Em andamento", animal1.getId(), agendamento1.getId());

        veterinario1.realizarConsulta(consulta1);
        veterinario1.solicitarExames(animal1, "Raio-X e Exame de Sangue");

        List<String> resultadosExames = Arrays.asList("Raio-X normal", "Sangue ok");
        consulta1.registrarResultadosExames(resultadosExames);
        veterinario1.registrarResultadosExames(animal1, "Raio-X normal, Sangue ok");

        animal1.addConsulta(consulta1);

        consulta1.alterarStatusConsulta("Concluída");
        agendamento1.alterarStatusAgendamento("Concluído");

        Animal animal2 = new Animal(2, cliente1.getId(), "Barto", 3, "M", "Cachorro", "Spitz Alemão", "Saudável", new ArrayList<>(), "Vacinação completa", false, "Masculino", 4);
        cliente1.adicionarAnimal(animal2.getId());
        secretaria1.cadastrarAnimal(animal2);

        cliente1.listarAnimais();

        Agendamento agendamento2 = new Agendamento(2, new Date(), "16:00", "Verificar feridas na barriga", "Pendente", cliente1.getId(), animal2.getId(), veterinario1.getId());
        secretaria1.agendarConsulta(agendamento2);
        secretaria1.cancelarConsulta(agendamento2);

        secretaria1.buscarCliente(3);
        secretaria1.buscarCliente(1);
    }
}
