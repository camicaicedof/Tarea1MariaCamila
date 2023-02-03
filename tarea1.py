"""
María Camila Caicedo Flórez
Código: 8977474
"""
#### Punto 1 ####

def verificarDiagonales (matriz):
  variableToF= True
  i=0
  j=len(matriz)-1
  while i < len(matriz) and variableToF == True:
    if matriz[i][i] != matriz[i][j]:
      variableToF = False
    j-=1
    i+=1
  return variableToF
    
#### Punto 2 ####
def esCapicua (listaCap):
    variableToF= True
    j=len(listaCap)-1
    i=0
    while i < len(listaCap) and variableToF==True: 
        if listaCap[i]!=listaCap[j]:
            variableToF= False
        i+=1
        j-=1
    return variableToF

#### Punto 3 ####
def diferenciaListas (lista1,lista2):
    lista3=[]
    for i in range (0,len(lista2)):
        if lista2[i] in lista1:
            lista3.append(lista2[i])
    for i in range (0,len(lista3)):
        if lista3[i] in lista1:
            lista1.remove(lista3[i])    
    return lista1

def leerImprimir ():
    inputInicial=int(input())
    for i in range (0,inputInicial):
        lista1=[int(a) for a in input().split()]
        lista1.remove(lista1[0])
        lista2=[int(a) for a in input().split()]
        lista2.remove(lista2[0])
        listaRetorno=diferenciaListas(lista1,lista2)
        for j in range (0,len(listaRetorno)):
            if  j < len(listaRetorno)-1:
                print("%d, " % listaRetorno[j], end="")
            elif j == len(listaRetorno)-1:
                print("%d" % listaRetorno[j])
leerImprimir()
#### Punto 4 ####
def calcularPrimos (numero):
    variableToF=True
    i=2
    while i < numero and variableToF==True:
        if numero % i == 0:
            variableToF=False
        i += 1
    return variableToF

def mostrarPrimos (numero):
    primos=[]
    sumaPrimos=[]
    for i in range (1,numero):
        n=i
        suma=0
        variable=calcularPrimos(i)
        if variable== True:
            primos.append(i)
            while n != 0:
                suma+= n%10
                n= n //10
            variableSuma=calcularPrimos(suma)
            if variableSuma == True:
                sumaPrimos.append(i)
    for i in range (0,len(primos)):
        if i < len(primos)-1:
            print("--> "+str(primos[i])+",")
        elif i == len(primos)-1:
            print("--> "+str(primos[i]))
    for i in range (0,len(sumaPrimos)):
        sumaPrimos[i]=str(sumaPrimos[i])
    print()
    print("Números entre 1 y",numero, "con suma de dígitos con valor primo:")
    print(", ".join(sumaPrimos))

#### Punto 5 ####
def sumarValoresMatriz (matDisp, listaTup):
    suma=0
    for i in range (0,len(listaTup)):
        if listaTup[i][0] in matDisp:
            for j in range (0,len(matDisp[listaTup[i][0]])):
                if listaTup[i][1] == matDisp[listaTup[i][0]][j][0]:
                    suma += matDisp[listaTup[i][0]][j][1]
    return suma
