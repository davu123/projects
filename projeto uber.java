import java.util.Scanner;

public class Banco {
    
    private String nomeCliente;
    private String tipoConta;
    private double saldo;

    public Banco(String nomeCliente, String tipoConta, double saldoInicial) {
        this.nomeCliente = nomeCliente;
        this.tipoConta = tipoConta;
        this.saldo = saldoInicial;
    }

    public void exibirCabecalho() {
        System.out.println("=== Dados do Cliente ===");
        System.out.println("Nome: " + nomeCliente);
        System.out.println("Tipo da Conta: " + tipoConta);
        System.out.println("Saldo Inicial: R$ " + String.format("%.2f", saldo));
        System.out.println("========================");
    }

    public void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            System.out.println("Depósito de R$ " + String.format("%.2f", valor) + " realizado com sucesso!");
        } else {
            System.out.println("Valor inválido para depósito.");
        }
    }
    
    public void sacar(double valor) {
        if (valor > 0 && saldo >= valor) {
            saldo -= valor;
            System.out.println("Saque de R$ " + String.format("%.2f", valor) + " realizado com sucesso!");
        } else if (valor > saldo) {
            System.out.println("Saldo insuficiente para realizar a operação.");
        } else {
            System.out.println("Valor inválido para saque.");
        }
    }

    public void consultarSaldo() {
        System.out.println("Saldo atual: R$ " + String.format("%.2f", saldo));
    }

    public void exibirMenu() {
        Scanner scanner = new Scanner(System.in);
        int opcao;

        do {
            System.out.println("\n=== Menu de Operações ===");
            System.out.println("1. Entrada de valor (Depositar)");
            System.out.println("2. Saída de valor (Sacar)");
            System.out.println("3. Consultar saldo");
            System.out.println("4. Finalizar aplicação");
            System.out.print("Escolha uma opção: ");

            opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    System.out.print("Digite o valor a ser depositado: R$ ");
                    double valorDeposito = scanner.nextDouble();
                    depositar(valorDeposito);
                    break;

                case 2:
                    System.out.print("Digite o valor a ser sacado: R$ ");
                    double valorSaque = scanner.nextDouble();
                    sacar(valorSaque);
                    break;

                case 3:
                    consultarSaldo();
                    break;

                case 4:
                    System.out.println("Finalizando a aplicação...");
                    break;

                default:
                    System.out.println("Opção inválida. Tente novamente.");
            }
        } while (opcao != 4);

        scanner.close();
    }

    public static void main(String[] args) {
        Banco minhaConta = new Banco("João Silva", "Conta Corrente", 1000.00);
        minhaConta.exibirCabecalho();
        minhaConta.exibirMenu();
    }
}
