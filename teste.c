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
		printf("\t|");
		for(j = 0; j < 3; j++)
		{
			if(j == 2){
				printf(" %c |", Matriz[i][j]);
			}
			if ( j!= 2 ){
				printf(" %c |", Matriz[i][j]);
			}
			else{
				printf("\n");
				printf("\t-------------\n");
			}
		}
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
		printf("\n\a\t\tJogador 1 e o vencedor, PARABENS!!!\n\n\n");
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
		printf("\n\n\n\n\a\t\tJogador 2 e o vencedor, PARABENS!!!\n\n\n");
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

int add(int cont)
{
	int i,j;
	printf("cont: %d\n\n", cont);
	printf("\n\nJogador1 jogar:\n");
	printf("Digite a posição que vc queira jogador1: (linha, coluna)\n");
	scanf("%d %d",&i,&j);
	verificadorPos(1,i,j);
	print();
	if(verificadorDeVencedor()){
		return 1;
	}
	
	if(cont < 5)
	{
		printf("\n\nJogador2 jogar:\n");
		printf("Digite a posição que vc queira jogador2: (linha, coluna)\n");
		scanf("%d %d",&i,&j);
		verificadorPos(2,i,j);
		print();
		if(verificadorDeVencedor()){
			return 1;
		}
	}
	else
	{
		printf("\tDeu velha !!!\n");
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