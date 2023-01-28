import random

nomes = open('nomes_aleatorios.txt', 'r')
arquivo = open("arquivo_correto.txt", "w")
disciplinas = ["Portugues", "Matematica",
               "Biologia", "Geometria", "Programacao"]
i = 0
for nomes_arquivo in nomes.readlines():
    nome_correto = nomes_arquivo.replace(" ", "")
    arquivo.write(str(i)+'\n')
    arquivo.writelines(nome_correto)
    arquivo.write(str(random.randint(1, 30))+'\n')
    arquivo.write(str(random.randint(1, 12))+'\n')
    arquivo.write(str(random.randint(1990, 2023))+'\n')
    for disciplinas_nomes in disciplinas:
        arquivo.write(disciplinas_nomes+'\n')
        for x in range(0, 4):
            nota = round(random.uniform(0, 10), 2)
            arquivo.write(str(nota)+'\n')
        arquivo.write(str(0)+'\n')
    i += 1
nomes.close()
arquivo.close()
