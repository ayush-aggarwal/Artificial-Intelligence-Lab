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
int checkWinMove(char w)
{
	if(ticTacToe[0][0]=='_'&& ((ticTacToe[0][1]==w&&ticTacToe[0][2]==w)||(ticTacToe[1][0]==w&&ticTacToe[2][0]==w)||(ticTacToe[1][1]==w&&ticTacToe[2][2]==w))){
		ticTacToe[0][0] = '0';
		return 1;
	}
	if(ticTacToe[0][1]=='_'&& ((ticTacToe[0][0]==w&&ticTacToe[0][2]==w)||(ticTacToe[1][1]==w&&ticTacToe[2][1]==w))){
		ticTacToe[0][1] = '0';
		return 1;
	}
	if(ticTacToe[0][2]=='_'&& ((ticTacToe[0][0]==w&&ticTacToe[0][1]==w)||(ticTacToe[1][2]==w&&ticTacToe[2][2]==w)||(ticTacToe[1][0]==w&&ticTacToe[1][1]==w))){
		ticTacToe[0][2] = '0';
		printf("here\n\n\n\n");
		return 1;
	}
	if(ticTacToe[1][0]=='_'&& ((ticTacToe[1][1]==w&&ticTacToe[1][2]==w)||(ticTacToe[0][0]==w&&ticTacToe[2][0]==w))){
		ticTacToe[1][0] = '0';
		return 1;
	}
	if(ticTacToe[1][1]=='_'&& ((ticTacToe[1][0]==w&&ticTacToe[1][2]==w)||(ticTacToe[0][1]==w&&ticTacToe[2][1]==w)||(ticTacToe[0][0]==w&&ticTacToe[2][2]==w)||(ticTacToe[2][0]==w&&ticTacToe[0][2]==w))){
		ticTacToe[1][1] = '0';
		return 1;
	}
	if(ticTacToe[1][2]=='_'&& ((ticTacToe[1][0]==w&&ticTacToe[1][1]==w)||(ticTacToe[0][2]==w&&ticTacToe[2][2]==w))){
		ticTacToe[1][2] = '0';
		return 1;
	}
	if(ticTacToe[2][0]=='_'&& ((ticTacToe[2][1]==w&&ticTacToe[2][2]==w)||(ticTacToe[0][0]==w&&ticTacToe[1][0]==w)||(ticTacToe[1][1]==w&&ticTacToe[0][2]==w))){
		ticTacToe[2][0] = '0';
		return 1;
	}
	if(ticTacToe[2][1]=='_'&& ((ticTacToe[2][0]==w&&ticTacToe[2][2]==w)||(ticTacToe[0][1]==w&&ticTacToe[1][1]==w))){
		ticTacToe[2][1] = '0';
		return 1;
	}
	if(ticTacToe[2][2]=='_'&& ((ticTacToe[2][0]==w&&ticTacToe[2][1]==w)||(ticTacToe[0][2]==w&&ticTacToe[1][2]==w)||(ticTacToe[0][0]==w&&ticTacToe[1][1]==w))){
		ticTacToe[2][2] = '0';
		return 1;
	}
	return 0;
}
void makeComputerMove(){
	int i,j, f = 0;
	printf("\nComputer\n");
	if(!checkWinMove('0')){
		if(!checkWinMove('X')){
			for(i = 0; i<3 ;i++){
				for(j = 0; j<3; j++){
					if(ticTacToe[i][j] == '_'){
						ticTacToe[i][j] = '0';
						f = 1;
						break;
					}
				}
				if(f == 1){
					break;
				}
			}
		}
	}
	displayTicTacToe();
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
void main(){
	int i,j, moves, row, column;
	char resultPlayer;
	for(i = 0; i<3; i++){
		for(j = 0; j<3; j++){
			ticTacToe[i][j] = '_';
		}
	}
	displayTicTacToe();
	for(moves = 0 ;moves < 9 ; moves+=2){
		printf("Player\n");
		printf("Row:- ");
		scanf("%d",&row);
		printf("Column:- ");
		scanf("%d",&column);
		if(ticTacToe[row][column] == '_'){
			ticTacToe[row][column] = 'X';
			displayTicTacToe();
		}
		else{
			printf("Already Place Taken\n");
			moves = moves - 2;
		}
		makeComputerMove();
		resultPlayer = checkFinalWin();
		if(resultPlayer != ' '){
			printf("Player with %c Wins!!\n", resultPlayer);
			break;
		}
	}
	if(moves == 9){
		printf("Match Tied\n");
	}
}