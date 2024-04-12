print("matrizes") 
m = [[1, 2, 3],
    [4, 5, 6],
     [7, 8, 9]] 

m1 = [[],[],[],[]] 

print(m1)

print(m)

print (m[0], "=", sum(m[0]))

def diagonal(m):
    p = 1
    for i in range(len(m[0])):
        for j in range (len(m[0])):
            if i == j: 
                p = p * m[i][j]
                print(m[i][j]) 

            return p
print("diagonal principal da matriz M" ,diagonal(m))
 
def produto(m,x):
    for i in range(len(m[0])):
        for j in range (len(m[0])):
            m[i][j] = m[i][j] * x

    return m 


def potenciaM(m,y):
    for i in range(len(m[0])):
        for j in range (len(m[0])):
            m[i][j] = m[i][j] ** y
    return m

y = 3
print("produto de m pro y e:" ,potenciaM(m,y))

