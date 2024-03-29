import os

"""
    Matriz global que representa o tabuleiro do jogo;
"""
global matriz
matriz = [[' ', ' ', ' '], [' ', ' ', ' '], [' ', ' ', ' ']]


"""
    Escreva a função que encontrará a posição a ser jogada pela cpu;
    Deve retornar uma lista com a linha e coluna a ser jogada;
"""
def estrategia(cpu):
    """ insira sua função de estratégia aqui """


"""
    Função que imprime as posições do tabuleiro;
    Função sem valor de retorno;
"""
def posicoes():
    aux = 7
    print("   Posicoes do jogo:\n")
    for i in range(0,3):
        print("\t", end='')
        for j in range(0,3):
            if j == 2:
                print(" %d" %aux)
                aux = 3 if i == 0 else 0
            else:
                print(" %d" %aux + " |", end='')
            aux += 1
        if i == 2:
            print()
        else:
            print("\t---|---|---")


"""
    Função que imprime o estado atual do tabuleiro;
    Função sem valor de retorno;
"""
def mapa():
    for i in range(0,3):
        print("\t", end='')
        for j in range(0,3):
            if j == 2:
                print(" %c" %matriz[i][j] + " ")
            else:
                print(" %c" %matriz[i][j] + " |", end='')
        if i == 2:
            print()
        else:
            print("\t---|---|---")


"""
    Função que executa o movimento proposto pela CPU;
    Função sem valor de retorno;
"""
def jogadaCPU(x, y, cpu):
    matriz[x][y] = cpu


"""
    Função que executa o movimento pedido pelo jogador;
    Função sem valor de retorno;
"""
def jogada(pos, player):
    if pos == 7:
        x = 0; y = 0;
    elif pos == 8:
        x = 0; y = 1;
    elif pos == 9:
        x = 0; y = 2;
    elif pos == 4:
        x = 1; y = 0;
    elif pos == 5:
        x = 1; y = 1;
    elif pos == 6:
        x = 1; y = 2;
    elif pos == 1:
        x = 2; y = 0;
    elif pos == 2:
        x = 2; y = 1;
    elif pos == 3:
        x = 2; y = 2;
    else:
        print("Movimento invalido, tente novamente!\n");
        aux = int(input("Digite o valor de uma posicao no tabuleiro: "))
        jogada(aux, player);
    
    if matriz[x][y] != ' ':
        print("Movimento invalido, tente novamente!\n");
        aux = int(input("Digite o valor de uma posicao no tabuleiro: "))
        jogada(aux, player);
    else:
        matriz[x][y] = player


"""
    Função que verifica o vencedor da partida;
    Retorna o caracter usado pelo vencedor ou um espaço, representando que o jogo está em andamento;
"""
def verificar():
    for i in range(0,3):
        if matriz[i][0] == matriz[i][1] == matriz[i][2]:
            return matriz[i][0]

    for i in range(0,3):
        if matriz[0][i] == matriz[1][i] == matriz[2][i]:
            return matriz[0][i]

    if matriz[0][0] == matriz[1][1] == matriz[2][2]:
        return matriz[0][0]

    if matriz[0][2] == matriz[1][1] == matriz[2][0]:
        return matriz[0][2]

    return ' '


"""
    Função que verifica se houve empate no jogo;
    Retorna um valor booleano;
"""
def velha():
    for i in range(0,3):
        for j in range(0,3):
            if matriz[i][j] == ' ':
                return False
    return True


"""
    Função principal, que chama as funções necessárias para o jogo;
    Função sem valor de retorno;
"""
def main():
    os.system('cls' if os.name == 'nt' else 'clear')
    print("Bem vindo(a) ao Jogo da Velha da Oficina de Teoria dos Jogos!")
    check = ' '
    player = (input("\nPor favor, selecione X ou O: ")).upper()
    while player != 'X' and player != 'O':
        print("Opção inválida!")
        player = (input("\nPor favor, selecione X ou O: ")).upper()
    cpu = 'O'
    if player == 'O':
        cpu = 'X'

    op = (input("\nDeseja começar? (s/n) ")).upper()
    while op != 'S' and op != 'N':
        print("Opção inválida!")
        op = (input("\nDeseja começar? (s/n) ")).upper()

    if op == 'S':
        os.system('cls' if os.name == 'nt' else 'clear')
        posicoes()
        mapa()
        pos = int(input("Digite o valor de uma posicao no tabuleiro: "))
        jogada(pos, player)

    while check == ' ':
        posCPU = estrategia(cpu)
        jogadaCPU(posCPU[0], posCPU[1], cpu)
        check = verificar()
        if check != ' ':
            break
        if velha() == True:
            break
        os.system('cls' if os.name == 'nt' else 'clear')
        posicoes()
        mapa()
        pos = int(input("Digite o valor de uma posicao no tabuleiro: "))
        jogada(pos, player)
        if velha() == True:
            break
    
    os.system('cls' if os.name == 'nt' else 'clear')
    print("\n")
    mapa()

    if check == 'O':
        print("\tCPU venceu!!\n")
    elif check == 'X':
        print("\tParabéns, você venceu!!\n")
    else:
        print("\tDeu velha!!\n")

    a = input("\n\n\nPressione ENTER para encerrar!")


#----------------------------------
main()
