import random

num_ex = int(input("Entre o número de exercícios: "))
obrigatorios = input("Entre os exercícios obrigatórios, separados por vírgula: ")
# Exercícios obrigatórios - Lista 1: [2, 3, 8, 11, 15, 16, 20, 22, 23, 27, 32, 33, 38, 42, 49, 51, 52, 54, 55, 56, 57, 58, 60]
# Exercícios obrigatórios - Lista 2: [2, 3, 5, 6, 8, 11, 13, 14, 15, 17, 18, 19, 20, 21, 24, 26, 27, 30, 31, 32]
# Exercícios obrigatórios - Lista 3 (todos os 18): [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18]
# Exercícios obrigatórios - Lista 4 (todos os 16): [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
# Exercícios obrigatórios - Lista 5 (todos os 13): [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]
# Exercícios obrigatórios - Lista 6 (todos os 14): [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]
# Exercícios obrigatórios - Lista 7 (todos os 15): [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]

obrigatorios = obrigatorios.split(",")
obrigatorios = [int(i) for i in obrigatorios]
opcionais = [i for i in range(1,num_ex+1) if i not in obrigatorios]
print("Exercícios obrigatórios:", obrigatorios)
print("Exercícios opcionais:", opcionais)

# Sorteio dos números

print("\nSorteio dos números: ")
membros = ['Adair', 'Luis', 'Matheus', 'Waldemir']
sorteio = {}
for i in range(1, len(membros) + 1):
    aluno = random.choice(membros)
    # print(aluno + ":", i)
    sorteio[aluno] = i
    membros.remove(aluno)
#else:
    # print(membros[0] + ":", 4)
membros = ['Adair', 'Luis', 'Matheus', 'Waldemir']
for nome in membros:
    print(nome + ":", sorteio[nome])

'''
adair_num = random.randint(1,4)
luis_num = random.randint(1,4)
while luis_num == adair_num:
    luis_num = random.randint(1,4)
matheus_num = random.randint(1,4)
while matheus_num == luis_num or matheus_num == adair_num:
    matheus_num = random.randint(1,4)
waldemir_num = random.randint(1,4)
while waldemir_num == matheus_num or waldemir_num == luis_num or waldemir_num == adair_num:
    waldemir_num = random.randint(1,4)
print("\nSorteio dos números: ")
print("Adair:", adair_num,"\nLuis:", luis_num, "\nMatheus:", matheus_num, "\nWaldemir:", waldemir_num)
'''

'''
adair_num, luis_num, matheus_num, waldemir_num = random.randint(1,4), random.randint(1,4), random.randint(1,4), random.randint(1,4)
while adair_num == luis_num or adair_num == matheus_num or adair_num == waldemir_num or luis_num == matheus_num or luis_num == waldemir_num or matheus_num == waldemir_num:
    adair_num, luis_num, matheus_num, waldemir_num = random.randint(1,4), random.randint(1,4), random.randint(1,4), random.randint(1,4)
print("\nSorteio dos números: ")
print("Adair:", adair_num,"\nLuis:", luis_num, "\nMatheus:", matheus_num, "\nWaldemir:", waldemir_num)
'''

# Obrigatórios
Aluno_1, Aluno_2, Aluno_3, Aluno_4, taken = [], [], [], [], []
obrctr = obrigatorios.copy()
for i in range(1,5):
    j = 0
    while j in range(len(obrctr)):
        if i == 1:
            Aluno_1.append(obrctr[j])
            taken.append(obrctr[j])
            j += 4
        elif i == 2:
            Aluno_2.append(obrctr[j])
            taken.append(obrctr[j])
            j += 3
        elif i == 3:
            Aluno_3.append(obrctr[j])
            taken.append(obrctr[j])
            j += 2
        elif i == 4:
            Aluno_4.append(obrctr[j])
            taken.append(obrctr[j])
            j += 1
        else:
            break
    else:
        obrctr = [k for k in obrctr if k not in taken]

print()
print(len(obrigatorios), "exercícios obrigatórios.")
print("Aluno_1:", Aluno_1)
print("Aluno_2:", Aluno_2)
print("Aluno_3:", Aluno_3)
print("Aluno_4:", Aluno_4)

# Opcionais
Aluno_1, Aluno_2, Aluno_3, Aluno_4, taken = [], [], [], [], []
opcctr = opcionais.copy()
for i in range(1,5):
    j = 0
    while j in range(len(opcctr)):
        if i == 1:
            Aluno_1.append(opcctr[j])
            taken.append(opcctr[j])
            j += 4
        elif i == 2:
            Aluno_2.append(opcctr[j])
            taken.append(opcctr[j])
            j += 3
        elif i == 3:
            Aluno_3.append(opcctr[j])
            taken.append(opcctr[j])
            j += 2
        elif i == 4:
            Aluno_4.append(opcctr[j])
            taken.append(opcctr[j])
            j += 1
        else:
            break
    else:
        opcctr = [k for k in opcctr if k not in taken]

print()
print(len(opcionais), "exercícios opcionais.")
print("Aluno_1:", Aluno_1)
print("Aluno_2:", Aluno_2)
print("Aluno_3:", Aluno_3)
print("Aluno_4:", Aluno_4)