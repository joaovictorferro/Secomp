import os

"""
    Matriz global que representa o tabuleiro do jogo;
"""
global matriz
matriz = [[' ', ' ', ' '], [' ', ' ', ' '], [' ', ' ', ' ']]

"""
    Função que verifica se o movimento continuará a partidad ou resultará em vitória, empate ou derrota;
    Retorna um inteiro que representa a "pontuação" do tabuleiro, onde 10 representa vitória, -10 derrota e 0 empate;
"""
def evaluate(cpu, player):
    for i in range(0,3):
        if matriz[i][0] == matriz[i][1] == matriz[i][2]:
            if matriz[i][0] == cpu: 
                return 10 
            elif matriz[i][0] == player:
                return -10

    for j in range(0,3):
        if matriz[0][j] == matriz[1][j] == matriz[2][j]:
            if matriz[0][j] == cpu: 
                return 10
            elif matriz[0][j] == player:
                return -10
                
    if matriz[0][0] == matriz[1][1] == matriz[2][2]:
        if matriz[0][0] == cpu:
            return 10
        elif matriz[0][0] == player:
            return -10
            
    if matriz[0][2] == matriz[1][1] == matriz[2][0]:
        if matriz[0][2] == cpu:
            return 10
        elif matriz[0][2] == player:
            return -10
            
    return 0


"""
    Função que verifica se ainda há movimentos disponíveis;
    Retorna um valor booleano informando se há ou não movimentos;
"""
def isMovesLeft():
	for i in range(0,3):
		for j in range(0,3):
			if matriz[i][j] == ' ':
				return True
	return False


"""
    Função que calcula a melhor posição a ser jogada;
    Retorna um inteiro que representa a "pontuação" da casa desejada, onde 10 representa vitória, -10 derrota e 0 empate;
"""
def minimax(profundidade, isMax, cpu):
    player = 'O'
    if cpu == 'O':
        player = 'X'

    score = evaluate(cpu, player)
    if score == 10:
        return score

    if score == -10:
        return score

    if isMovesLeft() == False:
        return 0 

    if isMax == True:
        best = -1000
        for i in range(0,3):
            for j in range(0,3):
                if matriz[i][j] == ' ':
                    matriz[i][j] = cpu
                    best = max(best, minimax(profundidade+1, not isMax, cpu))
                    matriz[i][j] = ' '
        return best 

    else:
        best = 1000
        for i in range(0,3):
            for j in range(0,3):
                if matriz[i][j] == ' ':
                    matriz[i][j] = player
                    best = min(best, minimax(profundidade+1, not isMax, cpu))
                    matriz[i][j] = ' '
        return best  

"""
    Função que encontra a melhor posição a ser jogada pela CPU;
    Retorna uma lista com o valor da linha e coluna do movimento;
"""
def findBestMove(cpu):
    bestValue = -1000; move = [-1,-1]
    for i in range(0,3):
        for j in range(0,3):
            if matriz[i][j] == ' ':
                matriz[i][j] = cpu
                moveValue = minimax(0, False, cpu)
                matriz[i][j] = ' '
                if moveValue > bestValue:
                    move[0] = i
                    move[1] = j
                    bestValue = moveValue

    return move


"""
    Função que imprime as posições do tabuleiro;
    Função sem valor de retorno;
"""
def posicoes():
    aux = 1
    print("Posicoes do jogo:\n")
    for i in range(0,3):
        print("\t", end='')
        for j in range(0,3):
            if j == 2:
                print(" %d" %aux)
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
    if pos == 1:
        x = 0; y = 0;
    elif pos == 2:
        x = 0; y = 1;
    elif pos == 3:
        x = 0; y = 2;
    elif pos == 4:
        x = 1; y = 0;
    elif pos == 5:
        x = 1; y = 1;
    elif pos == 6:
        x = 1; y = 2;
    elif pos == 7:
        x = 2; y = 0;
    elif pos == 8:
        x = 2; y = 1;
    elif pos == 9:
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
    print("Bem vindo(a) ao Jogo da Velha da Oficina de Teoria dos Jogos!")
    check = ' '
  
    while check == ' ':
        posicoes()
        mapa()
        pos = int(input("Digite o valor de uma posicao no tabuleiro: "))
        jogada(pos, 'O')
        check = verificar()
        if check != ' ':
            break
        if velha() == True:
            break
        os.system('cls' if os.name == 'nt' else 'clear')
        posCPU = findBestMove('X')
        jogadaCPU(posCPU[0], posCPU[1], 'X')
        check = verificar()
        if velha() == True:
            break
    
    os.system('cls' if os.name == 'nt' else 'clear')
    print("\n")
    mapa()

    if check == 'O':
        print("\tJogador 1 venceu!!\n")
    elif check == 'X':
        print("\tJogador 2 venceu!!\n")
    else:
        print("\tDeu velha!!\n")

    a = input("\n\n\nPressione ENTER para encerrar!")


#----------------------------------
main()