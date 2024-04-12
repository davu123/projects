def func07():
    try:
        x = int(input("Digite quantos alunos você quer colocar na lista: "))
    except ValueError as e:
        print(f"Erro: {e}")
        x = 0

    alunos = []
    notas = []

    for i in range(x):
        aluno = input("Digite o nome do aluno: ")
        try:
            nota = float(input("Qual a nota do aluno?: "))
        except ValueError as e:
            print(f"Erro: {e}")
            nota = 0.0
        alunos.append(aluno)
        notas.append(nota)

    dicionario_notas = {}
    for i in range(len(alunos)):
        dicionario_notas[alunos[i]] = notas[i]
    return dicionario_notas


dicionario_notas = func07()
print(dicionario_notas) 

