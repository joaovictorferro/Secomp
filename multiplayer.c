#include<stdio.h>
#include<stdlib.h>
#include <math.h>

char Matriz[3][3];
char O = 'O', X = 'X';

void print()
{
	int i,j;

	for(i = 0; i < 3; i++)
	{
		printf("\t");
		for(j = 0; j < 3; j++)
		{
			printf(" %c %c", Matriz[i][j], j == 2 ? '\n' : '|');
		}
		printf("\t%s", i == 2 ? " " : "---|---|---\n");
	}

}

int verificadorDeVencedor()
{
	if((Matriz[0][0]==O && Matriz[0][1]==O && Matriz[0][2]==O)||
		(Matriz[1][0]==O && Matriz[1][1]==O && Matriz[1][2]==O)||
		(Matriz[2][0]==O && Matriz[2][1]==O && Matriz[2][2]==O)||
		(Matriz[0][0]==O && Matriz[1][0]==O && Matriz[2][0]==O)||
		(Matriz[0][1]==O && Matriz[1][1]==O && Matriz[2][1]==O)||
		(Matriz[0][2]==O && Matriz[1][2]==O && Matriz[2][2]==O)||
		(Matriz[0][0]==O && Matriz[1][1]==O && Matriz[2][2]==O)||
		(Matriz[0][2]==O && Matriz[1][1]==O && Matriz[2][0]==O))
	{
		printf("\n\a\t\tJogador 2 é o vencedor, PARABENS!!!\n\n\n");
		return 1;
	}
	if((Matriz[0][0]==X && Matriz[0][1]==X && Matriz[0][2]==X)||
		(Matriz[1][0]==X && Matriz[1][1]==X && Matriz[1][2]==X)||
		(Matriz[2][0]==X && Matriz[2][1]==X && Matriz[2][2]==X)||
		(Matriz[0][0]==X && Matriz[1][0]==X && Matriz[2][0]==X)||
		(Matriz[0][1]==X && Matriz[1][1]==X && Matriz[2][1]==X)||
		(Matriz[0][2]==X && Matriz[1][2]==X && Matriz[2][2]==X)||
		(Matriz[0][0]==X && Matriz[1][1]==X && Matriz[2][2]==X)||
		(Matriz[0][2]==X && Matriz[1][1]==X && Matriz[2][0]==X))
	{
		printf("\n\n\n\n\a\t\tJogador 1 é o vencedor, PARABENS!!!\n\n\n");
		return 1;
	}

	return 0;
}

void verificadorPos(int jogador,int i, int j)
{
	while((Matriz[i][j] != ' ') || ((i < 0 || i > 8) && (j < 0 || j > 8)))
	{
		printf("Jogada invalida\n");
		printf("jogue novamente por favor jogador %d!!\n\n",jogador);
		scanf("%d %d",&i,&j);
	}

	if(jogador == 1)
	{
		Matriz[i][j] = O;
	}
	else
	{
		Matriz[i][j] = X;
	}
}

void printPadrao()
{
	printf("\n");
	printf("\t 7 | 8 | 9 \n");
	printf("\t---|---|---\n");
	printf("\t 4 | 5 | 6 \n");
	printf("\t---|---|---\n");
	printf("\t 1 | 2 | 3 \n");
}

void jogada(int pos, char player)
{
	int x,y,aux;
	if (pos == 7)
	{	
        x = 0; y = 0;
	}
    else if (pos == 8)
    {
        x = 0; y = 1;
    }
    else if (pos == 9)
    {
        x = 0; y = 2;
    }
    else if (pos == 4)
    {
        x = 1; y = 0;
    }
    else if (pos == 5)
    {
        x = 1; y = 1;
    }
    else if (pos == 6)
    {
        x = 1; y = 2;
    }
    else if (pos == 1)
    {
        x = 2; y = 0;
    }
    else if (pos == 2)
    {
        x = 2; y = 1;
    }
    else if (pos == 3)
    {
        x = 2; y = 2;
    }
    else
    {
    	printf("\nMovimento invalido, tente novamente!");
        printf("\nDigite o valor de uma posicao no tabuleiro: ");
        scanf("%d",&aux);
        jogada(aux, player);
    }
    
    if (Matriz[x][y] != ' ')
    {
		printf("\nMovimento invalido, tente novamente!");
        printf("\nDigite o valor de uma posicao no tabuleiro: ");
        scanf("%d",&aux);
        jogada(aux, player);
    }
    else
    {
        Matriz[x][y] = player;
    }
}

int add(int cont)
{
	int i;

	printPadrao();
	printf("\n\nJogador1 jogar:\n");
	printf("Digite a posição que você queira jogador1\n");
	scanf("%d",&i);
	jogada(i,X);
	print();
	if(verificadorDeVencedor()){
		return 1;
	}
	
	if(cont < 5)
	{
		printPadrao();
		printf("\n\nJogador2 jogar:\n");
		printf("Digite a posição que você queira jogador2\n");
		scanf("%d",&i);
		jogada(i,O);
		print();
		if(verificadorDeVencedor()){
			return 1;
		}
	}
	else
	{
		printf("\n\tDeu velha !!!\n");
		return 1;
	}
	return 0;
}

void iniciarMatriz()
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			Matriz[i][j] = ' ';
		}
	}
}

int main ()
{
	int n;
	iniciarMatriz();
	for(n = 1;n < 9;n++)
	{
		if(add(n)){
			return 0;
		}
	}
	return 0;
}