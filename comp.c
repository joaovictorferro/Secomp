#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include<time.h>

char Matriz[3][3];
char O = 'O', X = 'X';

void move_cpu_rand( char ch)
{
	int x,y;

	if(Matriz[0][0] == ' ')
	{
		Matriz[0][0] = ch;
	}
	else if(Matriz[0][2] == ' ')
	{
		Matriz[0][2] = ch;
	}
	else if(Matriz[2][0] == ' ')
	{
		Matriz[2][0] = ch;
	}
	else if(Matriz[2][2] == ' ')
	{
		Matriz[2][2] = ch;
	}
	else
	{
		do
		{
			srand(time(NULL));
			x = rand()%3;
			y = rand()%3;
		}while(Matriz[x][y] != ' ');

		Matriz[x][y] = ch;
	}     
}

int linha1( char ch )
{
	if(Matriz[0][0] == ' ')
	{
		if(((Matriz[0][1] == Matriz[0][2]) && (Matriz[0][1] != ' ')) ||
			((Matriz[1][0] == Matriz[2][0]) && (Matriz[1][0] != ' ')) ||
			((Matriz[1][1] == Matriz[2][2]) && (Matriz[1][1] != ' ')))
		{
			Matriz[0][0] = ch;
			return 1;
		}
	}

	if(Matriz[0][1] == ' ')
	{
		if(((Matriz[0][0] == Matriz[0][2]) && (Matriz[0][0] != ' ')) ||
			((Matriz[1][1] == Matriz[2][1]) && (Matriz[1][1] != ' ')))
		{
			Matriz[0][1] = ch;
			return 1;
		}
	}

	if(Matriz[0][2] == ' ')
	{
		if(((Matriz[0][1] == Matriz[0][0]) && (Matriz[0][1] != ' ')) ||
			((Matriz[1][2] == Matriz[2][2]) && (Matriz[1][2] != ' ')) ||
			((Matriz[1][1] == Matriz[2][0]) && (Matriz[1][1] != ' ')))
		{
			Matriz[0][2] = ch;
			return 1;
		}
	}

	return 0;
}

int linha2( char ch )
{
	if(Matriz[1][0] == ' ')
	{
		if(((Matriz[0][0] == Matriz[2][0]) && (Matriz[0][0] != ' ')) ||
			((Matriz[1][1] == Matriz[1][2]) && (Matriz[1][1] != ' ')))
		{
			Matriz[1][0] = ch;
			return 1;
		}
	}

	if(Matriz[1][1] == ' '){
		if(((Matriz[0][0] == Matriz[2][2]) && (Matriz[0][0] != ' ')) ||
			((Matriz[0][2] == Matriz[2][0]) && (Matriz[0][2] != ' ')) ||
			((Matriz[1][0] == Matriz[1][2]) && (Matriz[1][0] != ' ')) ||
			((Matriz[0][1] == Matriz[2][1]) && (Matriz[0][1] != ' ')))
		{
			Matriz[1][1] = ch;
			return 1;
		}
	}

	if(Matriz[1][2] == ' '){
		if(((Matriz[1][1] == Matriz[1][0]) && (Matriz[1][1] != ' ')) ||
			((Matriz[0][2] == Matriz[2][0]) && (Matriz[0][2] != ' ')))
		{
			Matriz[1][2] = ch;
			return 1;
		}
	}

	return 0;
}

int linha3( char ch )
{
	if(Matriz[2][0] == ' ')
	{
		if(((Matriz[0][0] == Matriz[1][0]) && (Matriz[0][0] != ' ')) ||
			((Matriz[2][1] == Matriz[2][2]) && (Matriz[2][1] != ' ')) ||
			((Matriz[1][1] == Matriz[0][2]) && (Matriz[1][1] != ' ')))
		{
			Matriz[2][0] = ch;
			return 1;
		}
	}

	if(Matriz[2][1] == ' ')
	{
		if(((Matriz[2][0] == Matriz[2][2]) && (Matriz[2][0] != ' ')) ||
			((Matriz[1][1] == Matriz[0][1]) && (Matriz[1][1] != ' ')))
		{
			Matriz[2][1] = ch;
			return 1;
		}
	}

	if(Matriz[2][2] == ' ')
	{
		if(((Matriz[2][1] == Matriz[2][0]) && (Matriz[2][1] != ' ')) ||
			((Matriz[0][2] == Matriz[1][2]) && (Matriz[0][2] != ' ')) ||
			((Matriz[1][1] == Matriz[0][0]) && (Matriz[1][1] != ' ')))
		{
			Matriz[2][2] = ch;
			return 1;
		}
	}

	return 0;
}

int player( char ch){

	if(linha1(ch) || linha2(ch) || linha3(ch))
	{
		return 1;
	}

	return 0;
}

void move_cpu( char ch){

	if(player( ch ))
	{
		return;
	}
	move_cpu_rand(ch);
}

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
        printf("%s", i == 2 ? "\n" : "\t---|---|---\n");
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
		Matriz[i][j] = X;
	}
	else
	{
		Matriz[i][j] = O;
	}
}

int add_player1(int cont)
{
	int i,j;
	
	printf("cont: %d\n\n", cont);
	printf("\n\nJogador1 jogar:\n");
	printf("Digite a posição que vc queira jogador1: (linha, coluna)\n");
	scanf("%d %d",&i,&j);
	verificadorPos(1,i,j);
	print();
	if(verificadorDeVencedor())
	{
		return 1;
	}
	
	if(cont < 5)
	{
		printf("\n\nCpu jogando ...\n");
		move_cpu(O);
		print();
		if(verificadorDeVencedor())
		{
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

int add_player2(int cont)
{
	int i,j;
	
	printf("\n\nCpu jogando ...\n");
	move_cpu(X);
	print();
	if(verificadorDeVencedor())
	{
		return 1;
	}
	
	if(cont < 5)
	{
		printf("cont: %d\n\n", cont);
		printf("\n\nJogador1 jogar:\n");
		printf("Digite a posição que vc queira jogador1: (linha, coluna)\n");
		scanf("%d %d",&i,&j);
		verificadorPos(2,i,j);
		print();
		if(verificadorDeVencedor())
		{
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
	int n,opc;

	iniciarMatriz();
	printf("Escolha qual player você será:\n");
	printf("1 - Player1\n");
	printf("2 - PLayer2\n");
	scanf("%d",&opc);

	if(opc == 1)
	{
		for(n = 1;n < 9;n++)
		{
			if(add_player1(n))
			{
				return 0;
			}
		}
	}
	else
	{
		for(n = 1;n < 9;n++)
		{
			if(add_player2(n))
			{
				return 0;
			}
		}
	}

	return 0;
}