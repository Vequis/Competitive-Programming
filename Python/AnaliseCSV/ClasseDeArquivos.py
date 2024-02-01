import matplotlib.pyplot as plt
import math
import string
import os
import numpy as np
from zipfile import ZipFile

class PlotDeArquivo(object):
    def __init__(self, nomeArquivo = "%s", linhas = [], RPM = [], Velocidade = []):
        self.nomeArquivo = nomeArquivo
        self.linhas = linhas
        self.Velocidade = Velocidade
        self.RPM = RPM


    def pegaDados(self):
        with open(self.nomeArquivo, 'r') as arquivo:
            DADOSADQUIRIDOS = arquivo.readlines()
            tabela = {44 : 46}
            arquivo.close()

            for linha in DADOSADQUIRIDOS:
                (self.linhas).append(linha.translate(tabela))

            del self.linhas[0]
            
            velAtual = 0.0
            
            for i in range(0, len(self.linhas)):
                j = 0
                pontoEVirgula = 0
                valorInicial = 0
                for caractere in self.linhas[i]:
                    if(pontoEVirgula == 5):
                        break
                    j += 1
                    if(caractere == ";"):
                        pontoEVirgula += 1
                        if(pontoEVirgula == 3):
                            if(valorInicial == 0):
                                valorInicial = j + 1
                        if(pontoEVirgula == 4):
                            velAtual = round(float(self.linhas[i][valorInicial:j-2]), 2)
                            #self.Velocidade.append(velAtual)
                            valorInicial = j+1
                            
                        if(pontoEVirgula == 5):
                            rpmAtual = int(self.linhas[i][valorInicial:j-2])
                            if ((rpmAtual < 7500 ) or velAtual == 0):
                                self.RPM.append(rpmAtual)
                                self.Velocidade.append(velAtual)
            

    def trataDados(self):
        indiceMaximo = self.Velocidade.index(max(self.Velocidade))
        tamanhoInicial = len(self.Velocidade)-1
        for indice in range(0, tamanhoInicial):
            if(self.Velocidade[0] == float(0) and self.Velocidade[1] == float(0)):
                del self.Velocidade[0]
                del self.RPM[0]
            else:
                break
        
        if(self.Velocidade.index(max(self.Velocidade)) < 250):
            indiceMaximo = self.Velocidade.index(max(self.Velocidade))
        else:
            indiceMaximo = 250
        tamanhoInicial = len(self.Velocidade) - 1
        for i in range(indiceMaximo, tamanhoInicial):
            del self.Velocidade[indiceMaximo + 1]
            del self.RPM[indiceMaximo + 1]

    def titulo(self):
        i = 0
        ultimo = 0
        for c in self.nomeArquivo:
            if (c == '\\'):
                ultimo = i
            i += 1
        return "Curva da CVT\n" + self.nomeArquivo[ultimo+1:len(self.nomeArquivo)]

    def plota(self):
        print(self.nomeArquivo)

        plt.figure()
        plt.title(objeto.titulo())
        plt.plot(objeto.Velocidade, objeto.RPM, 'o-', color = 'tab:blue')

    def salva(self):
        nome = pasta + "\\" + (objeto.titulo())[13:len(objeto.titulo())] + ".png"
        plt.savefig(nome, bbox_inches='tight')

    def __repr__(self):
     return "Use a funcao plota()"

    def __del__(self):
        while (len(self.linhas) != 0): del self.linhas[0]
        while (len(self.RPM) != 0): del self.RPM[0]
        while (len(self.Velocidade) != 0): del self.Velocidade[0]


#Coloque aqui a pasta que contem todos os CSVs a serem analisados
pasta = 'C:\\Users\\Usuario\\Documents\\Competitive-Programming\\Python\\AnaliseCSV\\Sessoes'

#Deixe em branco caso não queira que o programa extraia um .zip
localZip = ""
#localZip = "Downloads\\Arquivos CSV-20230111T132904Z-001.zip"

if (localZip != ""):
    with ZipFile(localZip, 'r') as zObject: 
        zObject.extractall(pasta)

for diretorio, subpastas, arquivos in os.walk(pasta):
    for arquivo in arquivos:
        objeto = PlotDeArquivo(os.path.join(os.path.realpath(diretorio), arquivo))

        objeto.pegaDados()
        objeto.trataDados()
        objeto.plota()
        #objeto.salva()

        del objeto

#.show ficou só no final pq eu queria que ele já abrisse todas as janelas de uma só vez
plt.show()
