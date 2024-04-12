def add(x, y):
    return x + y

def subtract(x, y):
    return x - y

def multiply(x, y):
    return x * y

def divide(x, y):
    if y != 0:
        return x / y
    else:
        return "não é possível dividir por zero."

print("escolha a operação:")
print("1. adição")
print("2. subtração")
print("3. multiplicação")
print("4. divisão")

escolha = input("digite a opção (1/2/3/4): ")

num1 = float(input("digite o primeiro número: "))
num2 = float(input("digite o segundo número: "))

if escolha == '1':
    print(num1, "+", num2, "=", add(num1, num2))
elif escolha == '2':
    print(num1, "-", num2, "=", subtract(num1, num2))
elif escolha == '3':
    print(num1, "*", num2, "=", multiply(num1, num2))
elif escolha == '4':
    print(num1, "/", num2, "=", divide(num1, num2))
else:
    print("opção inválida")                                 
    
