#include<stdio.h>
#include<stdlib.h>

void printar_tabuleiro(char casas[3][3])
{
	int i,j;

	for(i = 0; i < 3; i++)
	{
		printf("\t|");
		for(j = 0; j < 3; j++)
		{
			if(j == 2){
				printf(" %c |", casas[i][j]);
			}
			if ( j!= 2 ){
				printf(" %c |", casas[i][j]);
			}
			else{
				printf("\n");
				printf("\t-------------\n");
			}
		}
	}

}

void preencher_tabuleiro(char casas[3][3])
{
	int i,j;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			scanf(" %c[^/s]", &casas[i][j]);
		}
	}

	printar_tabuleiro(casas);
}

int main ()
{

char casas[3][3];

printf("\t\tSEJA BEM VIDO AO JOGO DA VELHA \n\n");

printf("\t\t\tEscolha:\n\n\t\t --1-- para X\n\t\t --2-- para O \n\n");

preencher_tabuleiro(casas);

	return 0;
}