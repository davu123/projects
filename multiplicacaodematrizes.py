def multiply_matrices(matrix1, matrix2): 
    rows1 = len(matrix1)
    cols1 = len(matrix1[0])
    rows2 = len(matrix2)
    cols2 = len(matrix2[0])

    if cols1 != rows2:
        raise ValueError("numero de colunas em matrix1 deve ser igual ao numero de linhas em matrix2")

    result = [[0 for _ in range(cols2)] for _ in range(rows1)]

    for i in range(rows1):
        for j in range(cols2):
            for k in range(cols1):
                result[i][j] += matrix1[i][k] * matrix2[k][j]

    return result

matrix_a = [
    [2, 3],
    [4, 5],
    [6, 7]
]

matrix_b = [
    [8, 9, 10],
    [11, 12, 13]
]

result_matrix = multiply_matrices(matrix_a, matrix_b)

for row in result_matrix:
    print(row)

