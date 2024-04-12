class pessoa():
    nome = "pedro"
    idade = 23

def imprime(p):
    print("nome: " ,p.nome) 
    print("idade: " ,p.idade) 

def retornaIR(p):
    if pessoa.salario <= 2000:
        return 0
    elif pessoa.salario <= 5000:
        return pessoa.salario * 0.1
    else:
        return pessoa.salario * 0.2

    
print("programacao POO - orientacao ao objeto")
p = pessoa()
print(p.imprime())
print(p.retornaIR()) 
