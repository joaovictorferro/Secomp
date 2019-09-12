#include<stdio.h>
#include<stdlib.h>
#include <math.h>

char Matriz[3][3];
char O = 'O', X = 'X';

void print()
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j<3;j++)
		{
			printf("%c",Matriz[i][j]);
		}
		printf("\n");
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
            printf("\n\a\t\tJogador 1 e o vencedor, PARABENS!!!");
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
            printf("\n\n\n\n\a\t\tJogador 2 e o vencedor, PARABENS!!!");
            return 1;
        }

        return 0;
}
void add()
{
	int i,j;
	printf("\n\nJogador1 jogar:\n");
	printf("Digite a posição que vc queira jogador1: (linha, coluna)\n");
	scanf("%d %d",&i,&j);
	Matriz[i][j] = O;
	if(verificadorDeVencedor()){
		return ;
	}
	
	printf("\n\nJogador1 jogar:\n");
	printf("Digite a posição que vc queira jogador2: (linha, coluna)\n");
	scanf("%d %d",&i,&j);
	Matriz[i][j] = X;
	if(verificadorDeVencedor()){
		return ;
	}
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
for(n = 1;n <= 9;n++)
{
	add();
	print();
}

	return 0;
}