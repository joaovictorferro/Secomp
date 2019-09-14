global matriz
matriz = [[' ', ' ', ' '], [' ', ' ', ' '], [' ', ' ', ' ']]

def posicoes():
    aux = 1
    print("\tPosicoes do jogo:\n")
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

def verificar():
    for i in range(0,3):
        if matriz[i][0] == matriz[i][1] == matriz[i][2]:
            return matriz[i][0]

    for i in range(0,3):
        if matriz[0][i] == matriz[1][i] == matriz[2][i]:
            return matriz[0][i];

    if matriz[0][0] == matriz[1][1] == matriz[2][2]:
        return matriz[0][0];

    if matriz[0][2] == matriz[1][1] == matriz[2][0]:
        return matriz[0][2];

    return ' ';

def main():
    print("Bem vindo(a) ao Jogo da Velha da Oficina de Teoria dos Jogos!")
    check = ' '
    jogadas = 1
    posicoes()
    
    while jogadas <= 9:
        mapa()
        pos = int(input("Digite o valor de uma posicao no tabuleiro: "))
        jogada(pos, 'X')
        print()
        check = verificar()
        if check != ' ':
            break
        mapa()
        pos = int(input("Digite o valor de uma posicao no tabuleiro: "))
        jogada(pos, 'O')
        check = verificar()
        if check != ' ':
            break
        jogadas += 1
    
    mapa()

    if check == 'X':
        print("\tJogador 1 venceu!!\n")
    elif check == 'O':
        print("\tJogador 2 venceu!!\n")
    else:
        print("\tDeu velha!!\n")

    a = input("\n\n\nPressione qualquer tecla para encerrar!")
    

#----------------------------------
main()
