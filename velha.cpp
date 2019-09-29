 #include<bits/stdc++.h> 
using namespace std; 

struct Move 
{ 
	int linha, coluna; 
}; 

char Matriz[3][3];
char player = 'x', opponent = 'o'; 

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

void iniMatriz()
{
	for(int i = 0;i<3;i++)
	{
		for(int j = 0; j < 3;j++)
		{
			Matriz[i][j] = ' ';
		}
	}
}

// This function returns true if there are moves 
// remaining on the Matriz. It returns false if 
// there are no moves left to play. 
bool isMovesLeft() 
{ 
	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			if (Matriz[i][j]=='_')
			{
				return true;
			} 
		}  
	}
	return false; 
} 

// This is the evaluation function as discussed 
// in the previous article ( http://goo.gl/sJgv68 ) 
int evaluate() 
{ 
	// Checking for linhas for X or O victory. 
	for (int linha = 0; linha<3; linha++) 
	{ 
		if (Matriz[linha][0] == Matriz[linha][1] && Matriz[linha][1] == Matriz[linha][2]) 
		{ 
			if (Matriz[linha][0] == player)
			{
				return +10;
			}  
			else if (Matriz[linha][0] == opponent)
			{
				return -10;
			}  
		} 
	} 

	// Checking for colunaumns for X or O victory. 
	for (int coluna = 0; coluna<3; coluna++) 
	{ 
		if (Matriz[0][coluna] == Matriz[1][coluna] && Matriz[1][coluna] == Matriz[2][coluna]) 
		{ 
			if (Matriz[0][coluna] == player)
			{
				return +10;
			}  
			else if (Matriz[0][coluna] == opponent)
			{
				return -10;
			}  
		} 
	} 

	// Checking for Diagonals for X or O victory. 
	if (Matriz[0][0] == Matriz[1][1] && Matriz[1][1] == Matriz[2][2]) 
	{ 
		if (Matriz[0][0] == player)
		{
			return +10;
		}  
		else if (Matriz[0][0] == opponent)
		{
			return -10;
		}  
	} 

	if (Matriz[0][2] == Matriz[1][1] && Matriz[1][1] == Matriz[2][0]) 
	{ 
		if (Matriz[0][2] == player)
		{
			return +10;
		}  
		else if (Matriz[0][2] == opponent)
		{
			return -10;
		}  
	} 

	// Else if none of them have won then return 0 
	return 0; 
} 

// This is the minimax function. It considers all 
// the possible ways the game can go and returns 
// the value of the Matriz 
int minimax(int depth, bool isMax) 
{ 
	int score = evaluate(); 

	// If Maximizer has won the game return his/her 
	// evaluated score 
	if (score == 10) 
		return score; 

	// If Minimizer has won the game return his/her 
	// evaluated score 
	if (score == -10) 
		return score; 

	// If there are no more moves and no winner then 
	// it is a tie 
	if (isMovesLeft()==false) 
		return 0; 

	// If this maximizer's move 
	if (isMax) 
	{ 
		int best = -1000; 

		// Traverse all cells 
		for (int i = 0; i<3; i++) 
		{ 
			for (int j = 0; j<3; j++) 
			{ 
				// Check if cell is empty 
				if (Matriz[i][j]==' ') 
				{ 
					// Make the move 
					Matriz[i][j] = player; 

					// Call minimax recursively and choose 
					// the maximum value 
					best = max( best, minimax(depth+1, !isMax) ); 

					// Undo the move 
					Matriz[i][j] = ' '; 
				} 
			} 
		} 
		return best; 
	} 

	// If this minimizer's move 
	else
	{ 
		int best = 1000; 

		// Traverse all cells 
		for (int i = 0; i<3; i++) 
		{ 
			for (int j = 0; j<3; j++) 
			{ 
				// Check if cell is empty 
				if (Matriz[i][j]==' ') 
				{ 
					// Make the move 
					Matriz[i][j] = opponent; 

					// Call minimax recursively and choose 
					// the minimum value 
					best = min(best, 
						minimax(depth+1, !isMax)); 

					// Undo the move 
					Matriz[i][j] = ' '; 
				} 
			} 
		} 
		return best; 
	} 
} 

// This will return the best possible move for the player 
Move findBestMove(char Matriz[3][3]) 
{ 
	int bestVal = -1000; 
	Move bestMove; 
	bestMove.linha = -1; 
	bestMove.coluna = -1; 

	// Traverse all cells, evaluate minimax function for 
	// all empty cells. And return the cell with optimal 
	// value. 
	for (int i = 0; i<3; i++) 
	{ 
		for (int j = 0; j<3; j++) 
		{ 
			// Check if cell is empty 
			if (Matriz[i][j]==' ') 
			{ 
				// Make the move 
				Matriz[i][j] = player; 

				// compute evaluation function for this 
				// move. 
				int moveVal = minimax(0, false); 

				// Undo the move 
				Matriz[i][j] = ' '; 

				// If the value of the current move is 
				// more than the best value, then update 
				// best/ 
				if (moveVal > bestVal) 
				{ 
					bestMove.linha = i; 
					bestMove.coluna = j; 
					bestVal = moveVal; 
				} 
			} 
		} 
	} 

	printf("The value of the best Move is : %d\n\n", 
			bestVal); 

	return bestMove; 
} 

void jogador()
{
	int l, c;

	printf("Jogue pf:\n");
	scanf("%d %d",&l,&c);
	Matriz[l][c] = player;
}
// Driver code 
int main() 
{ 
	iniMatriz();
	for(int i = 0; i < 8; i++)
	{
		jogador();
		print();
		Move bestMove = findBestMove(Matriz); 
		Matriz[bestMove.linha][bestMove.coluna] = opponent;
		print();
	}
	return 0; 
} 
