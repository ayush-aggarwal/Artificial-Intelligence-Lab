#include<stdio.h>
char ticTacToe[3][3];
void displayTicTacToe(){
	int i,j;
	for(i = 0; i<3; i++){
		for(j = 0; j<3 ;j++){
			printf("%c\t",ticTacToe[i][j]);
		}
		printf("\n");
	}
}
char checkFinalWin(){
	if(ticTacToe[0][0] == ticTacToe[0][1] && ticTacToe[0][0] == ticTacToe[0][2] && ticTacToe[0][0]!= '_'){
		return ticTacToe[0][0];
	}
	else if(ticTacToe[1][0] == ticTacToe[1][1] && ticTacToe[1][0] == ticTacToe[1][2] && ticTacToe[1][0]!= '_'){
		return ticTacToe[1][0];
	}
	else if(ticTacToe[2][0] == ticTacToe[2][1] && ticTacToe[2][0] == ticTacToe[2][2] && ticTacToe[2][0]!= '_'){
		return ticTacToe[2][0];
	}
	else if(ticTacToe[0][0] == ticTacToe[1][0] && ticTacToe[0][0] == ticTacToe[2][0] && ticTacToe[0][0]!= '_'){
		return ticTacToe[0][0];
	}
	else if(ticTacToe[0][1] == ticTacToe[1][1] && ticTacToe[0][1] == ticTacToe[2][1] && ticTacToe[0][1]!= '_'){
		return ticTacToe[0][1];
	}
	else if(ticTacToe[0][2] == ticTacToe[1][2] && ticTacToe[0][2] == ticTacToe[2][2] && ticTacToe[0][2]!= '_'){
		return ticTacToe[0][2];
	}
	else if(ticTacToe[0][0] == ticTacToe[1][1] && ticTacToe[0][0] == ticTacToe[2][2] && ticTacToe[0][0]!= '_'){
		return ticTacToe[0][0];
	}
	else if(ticTacToe[0][2] == ticTacToe[1][1] && ticTacToe[0][2] == ticTacToe[2][0] && ticTacToe[0][2]!= '_'){
		return ticTacToe[0][2];
	}
	else{
		return ' ';
	}
}
int main(){
	int i,j,moves,row,column;
	char resultPlayer, playerIdentify = 'X';
	for(i = 0; i<3; i++){
		for(j = 0; j<3 ;j++){
			ticTacToe[i][j]='_';
		}
	}
	displayTicTacToe();
	for(moves = 0; moves < 9 ; moves++){
		printf("Please Enter Row:- ");
		scanf("%d",&row);
		printf("Please Enter Column:- ");
		scanf("%d",&column);
		if(ticTacToe[row][column] == '_'){
			ticTacToe[row][column] = playerIdentify;
			if(playerIdentify == 'X')
				playerIdentify = '0';
			else
				playerIdentify = 'X';
			displayTicTacToe();
		}
		else{
			printf("Already Place Taken\n");
			moves = moves - 1;
		}
		resultPlayer = checkFinalWin();
		if(resultPlayer != ' '){
			printf("Player with %c Wins!!\n", resultPlayer);
			break;
		}
	}
	if(moves == 9){
		printf("Match Tied\n");
	}
	return 0;
}