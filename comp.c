#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

char Matriz[3][3];
char O = 'O', X = 'X';

void move_cpu_rand( char ch)
{
	int x,y;

	if(Matriz[1][1] == ' ')
	{
		Matriz[1][1] = ch;
	}
	else if(Matriz[0][0] == ' ')
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

int move_cpu_ganhar(char ch)
{
	int l;
	for(l=0;l<3;l++)
	{
		if(((Matriz[0][l] == Matriz[2][l]) && Matriz[1][l] == ' '))
		{
			if(Matriz[0][l] == ch && Matriz[2][l] == ch)
			{
				Matriz[1][l] = ch;
				return 1;
			}
		}
	}

	for(l=0;l<3;l++)
	{
		if(((Matriz[0][l] == Matriz[1][l]) && Matriz[2][l] == ' '))
		{
			if(Matriz[0][l] == ch && Matriz[1][l] == ch)
			{
				Matriz[2][l] = ch;
				return 1;
			}
		}
	}

	for(l=0;l<3;l++)
	{
		if(((Matriz[0][l] == Matriz[1][l]) && Matriz[2][l] == ' '))
		{
			if(Matriz[0][l] == ch && Matriz[1][l] == ch)
			{
				Matriz[2][l] = ch;
				return 1;
			}
		}
	}

	if(((Matriz[0][0] == Matriz[2][2]) && Matriz[1][1] == ' '))
	{
		if(Matriz[0][0] == ch && Matriz[2][2] == ch)
		{
			Matriz[1][1] = ch;
			return 1;
		}
	}

	if(((Matriz[0][2] == Matriz[2][0]) && Matriz[1][1] == ' '))
	{
		if(Matriz[0][2] == ch && Matriz[2][0] == ch)
		{
			Matriz[1][1] = ch;
			return 1;
		}
	}	

	if(((Matriz[0][0] == Matriz[1][1]) && Matriz[2][2] == ' '))
	{
		if(Matriz[0][0] == ch && Matriz[1][1] == ch)
		{
			Matriz[2][2] = ch;
			return 1;
		}
	}

	if(((Matriz[0][2] == Matriz[1][1]) && Matriz[2][0] == ' '))
	{
		if(Matriz[0][2] == ch && Matriz[1][1] == ch)
		{
			Matriz[2][0] = ch;
			return 1;
		}
	}

	if(((Matriz[2][0] == Matriz[1][1]) && Matriz[0][2] == ' '))
	{
		if(Matriz[2][0] == ch && Matriz[1][1] == ch)
		{
			Matriz[0][2] = ch;
			return 1;
		}
	}

	if(((Matriz[2][2] == Matriz[1][1]) && Matriz[0][0] == ' '))
	{
		if(Matriz[2][2] == ch && Matriz[1][1] == ch)
		{
			Matriz[0][0] = ch;
			return 1;
		}
	}

	return 0;
}

int move_cpu_estrategia(char ch)
{
	if((Matriz[2][0] == Matriz[1][2]) && Matriz[0][1] == ' ')
	{
		if((Matriz[2][0] != ' ' && Matriz[1][2] != ' ') && (Matriz[2][0] != ch && Matriz[1][2] != ch))
		{
			Matriz[0][1] = ch;
			return 1;
		}
	}

	if((Matriz[1][1] == Matriz[2][2]) ||
		(Matriz[1][1] == Matriz[0][2]) ||
		(Matriz[1][1] == Matriz[2][0]))
	{
		if((Matriz[1][1] != ' ' && Matriz[2][2] != ' ') && (Matriz[1][1] != ch && Matriz[2][2] != ch))
		{
			move_cpu_rand(ch);
			return 1;
		}
		if((Matriz[1][1] != ' ' && Matriz[0][2] != ' ') && (Matriz[1][1] != ch && Matriz[0][2] != ch))
		{
			move_cpu_rand(ch);
			return 1;
		}
		if((Matriz[1][1] != ' ' && Matriz[2][0] != ' ') && (Matriz[1][1] != ch && Matriz[2][0] != ch))
		{
			move_cpu_rand(ch);
			return 1;
		}
	}
	if(((Matriz[0][0] == Matriz[1][1]) && Matriz[1][0] == ' ') ||
		((Matriz[0][0] == Matriz[1][1]) && Matriz[0][1] == ' '))
	{
		if(((Matriz[0][0] == ch && Matriz[1][1] == ch) && Matriz[1][0] == ' '))
		{
			Matriz[1][0] = ch;
			return 1;
		}
		if(((Matriz[0][0] == ch && Matriz[1][1] == ch) && Matriz[0][1] == ' '))
		{
			Matriz[0][1] = ch;
			return 1;
		}
	}

	if(((Matriz[0][2] == Matriz[1][1]) && Matriz[1][2] == ' ')||
		((Matriz[0][2] == Matriz[1][1]) && Matriz[0][1] == ' '))
	{
		if((Matriz[0][2] == ch && Matriz[1][1] == ch) && Matriz[1][2] == ' ')
		{
			Matriz[1][2] = ch;
			return 1;
		}
		if((Matriz[0][2] == ch && Matriz[1][1] == ch) && Matriz[0][1] == ' ')
		{
			Matriz[0][1] = ch;
			return 1;
		}	
	}

	if(((Matriz[0][0] == Matriz[2][2]) && Matriz[1][0] == ' ') ||
		((Matriz[0][2] == Matriz[2][0]) && Matriz[1][0] == ' '))
	{
		if((((Matriz[0][0] != ch && Matriz[2][2] != ch) && Matriz[1][0] == ' ') && Matriz[0][0] != ' ') && Matriz[2][2] != ' ')
		{
			Matriz[1][0] = ch;
			return 1;
		}
		if((((Matriz[0][2] != ch && Matriz[2][0] != ch) && Matriz[1][0] == ' ') && Matriz[0][2] != ' ') && Matriz[2][0] != ' ')
		{
			Matriz[1][0] = ch;
			return 1;
		}
	}

	if(((Matriz[1][0] == ch && Matriz[1][1] == ch) && Matriz[0][1] == ' ') && Matriz[2][1] == ' ')
	{
		Matriz[0][1] = ch;
		return 1;
	}

	if(Matriz[1][2] == Matriz[2][1])
	{
		if(((Matriz[1][2] != ch && Matriz[2][1] != ch) && Matriz[1][2] != ' ') && Matriz[2][1] != ' ')
		{
			Matriz[0][2] = ch;
			return 1;
		}
	}

	return 0;
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
			((Matriz[0][2] == Matriz[2][0]) && (Matriz[0][2] != ' '))||
			((Matriz[0][2] == Matriz[2][2]) && (Matriz[0][2] != ' ')))
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

int defender( char ch)
{

	if(linha1(ch) || linha2(ch) || linha3(ch))
	{
		return 1;
	}

	return 0;
}

void move_cpu( char ch, int cont)
{
	if (cont == 1)
	{
		move_cpu_rand(ch);
		return ;
	}
	if (move_cpu_ganhar(ch))
	{
		return ;
	}

	if(defender( ch ))
	{
		return;
	}

	if(move_cpu_estrategia(ch))
	{
		return ;
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
		printf("\t%s", i == 2 ? " " : "---|---|---\n");
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
		printf("\n\a\t\tJogador 2 e o vencedor, PARABENS!!!\n\n\n");
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
		printf("\n\n\n\n\a\t\tJogador 1 e o vencedor, PARABENS!!!\n\n\n");
		return 1;
	}

	return 0;
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

int add_player1(int cont)
{
	int i;
	
	printPadrao();
	printf("\n\nJogador1 jogar:\n");
	printf("Digite a posição que vc queira jogador1\n");
	scanf("%d",&i);
	jogada(i,X);
	print();

	if(verificadorDeVencedor())
	{
		return 1;
	}
	
	if(cont < 5)
	{
		printf("\n\nCpu jogando ...\n");
		move_cpu(O,cont);
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
	move_cpu(X,cont);
	print();

	if(verificadorDeVencedor())
	{
		return 1;
	}
	
	if(cont < 5)
	{
		printPadrao();
		printf("\n\nJogador1 jogar:\n");
		printf("Digite a posição que vc queira jogador2:\n");
		scanf("%d",&i);
		jogada(i,O);
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