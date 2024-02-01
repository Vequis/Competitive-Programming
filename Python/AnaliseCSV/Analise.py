import matplotlib.pyplot as plt
import math
import string
import os
import numpy as np

nomeArquivo = ""
linhas = []
Velocidade = []
RPM = []

def pegaDados():
    DADOSADQUIRIDOS = []

    global linhas
    global RPM
    global Velocidade

    while (len(linhas) != 0): del linhas[0]
    while (len(RPM) != 0): del RPM[0]
    while (len(Velocidade) != 0): del Velocidade[0]

    with open(nomeArquivo, 'r') as arquivo:

        DADOSADQUIRIDOS = arquivo.readlines()
        tabela = {44 : 46}

        print(DADOSADQUIRIDOS[131])

        for linha in DADOSADQUIRIDOS:
            (linhas).append(linha.translate(tabela))
        del linhas[0]
        for i in range(0, len(linhas)):
            j = 0
            pontoEVirgula = 0
            valorInicial = 0
            for caractere in linhas[i]:
                if(pontoEVirgula == 5):
                    break
                j += 1
                if(caractere == ";"):
                    pontoEVirgula += 1
                    if(pontoEVirgula == 3):
                        if(valorInicial == 0):
                            valorInicial = j + 1
                    if(pontoEVirgula == 4):
                        if (linhas[i][valorInicial:j-2] != "velocidade"):
                            Velocidade.append(round(float(linhas[i][valorInicial:j-2]), 2))
                        valorInicial = j+1
                    if(pontoEVirgula == 5):
                        if (linhas[i][valorInicial:j-2] != "RotaÃ§Ã£o do Motor"):
                            RPM.append(int(linhas[i][valorInicial:j-2]))
    
    del DADOSADQUIRIDOS
    return

def trataDados():

    indiceMaximo = Velocidade.index(max(Velocidade))
    tamanhoInicial = len(Velocidade)-1
    for indice in range(0, tamanhoInicial):
        if(Velocidade[0] == float(0) and Velocidade[1] == float(0)):
            del Velocidade[0]
            del RPM[0]
        else:
            break
    
    if(Velocidade.index(max(Velocidade)) < 250):
        indiceMaximo = Velocidade.index(max(Velocidade))
    else:
        indiceMaximo = 250
    tamanhoInicial = len(Velocidade) - 1
    for i in range(indiceMaximo, tamanhoInicial):
        del Velocidade[indiceMaximo + 1]
        del RPM[indiceMaximo + 1]

def titulo():
    i = 0
    ultimo = 0
    for c in nomeArquivo:
        if (c == '\\'):
            ultimo = i
        i += 1
    return "Curva da CVT\n" + nomeArquivo[ultimo+1:len(nomeArquivo)]

def plota():
    print(nomeArquivo)



pasta = 'C:\\Users\\Usuario\\Documents\\Competitive-Programming\\Python\\AnaliseCSV\\Sessoes'
for diretorio, subpastas, arquivos in os.walk(pasta):
    for arquivo in arquivos:
        nomeArquivo = os.path.join(os.path.realpath(diretorio), arquivo)

        pegaDados()
        trataDados()
        plota()

        plt.figure()
        plt.title(titulo())
        plt.plot(Velocidade, RPM, 'o-', color = 'tab:blue')
        plt.show()

        print(Velocidade[5])