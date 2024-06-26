#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CROSS 1
#define CIRCLE 2

int gameTable[3][3];
int token = CIRCLE; // TODO: Use struct for token, saving the token shape and their position

int
main(){
	bool exit = false;
	extern int gameTable[3][3] ;

	initTable(gameTable);
	printf("Enter movement, O starts first.\n0 to exit. \n ");
	while(!exit){

		if(processTable() == 1){
			exit = true;
		}else{

		showTable();
		}

	}


}

int
processTable(){
	extern int gameTable[3][3];
	extern int token;
	
	int row = -1, col = -1;

	printf("Select the position (%s).\n ",(token == CIRCLE ? "O" : "X")); 

	getUserInput(&row,&col);
	gameTable[row][col] = token ;
	
	if(checkWin(token,row,col) == 1){
		return 1;
	}
	if(token == CIRCLE ){
		token = CROSS;
	}else{
		token = CIRCLE;
	}

	return row == -1 || col == -1;
}

int checkWin(int token,int row, int col){
 	return checkHorizontalWin(token,row) == 1 || checkVerticalWin(token,col) == 1;
}

int checkHorizontalWin(int token,int row){
	extern int gameTable[3][3];
	int tFound = 0;
	for(int col = 0; col < 3; col++){
		if(gameTable[row][col] == token){
			tFound++;
		}

	}
	return tFound == 3;
}

int checkVerticalWin(int token,int col){
	return false;
}


void
getUserInput(int* row, int* col){
	*row = getInt(*row,"Enter row position: ") - 1;
	*col = getInt(*col,"Enter col position: ") - 1;

  
}

int
getInt(int uInt,char* msg){
	while(uInt < 0 || uInt > 3) {
  		printf("%s ",msg); scanf("%d",&uInt);

  	}

	return uInt;


}


void
showTable(){
	extern int gameTable[3][3];

	for(int row = 0; row < 3; row++){
		for(int column = 0; column < 3; column++){
			switch(gameTable[row][column]){
				case CIRCLE: printf("O "); break;
				case CROSS: printf("X "); break;
				default: 
					printf("- ");
				break;
			}

		}
		printf("\n");
	}


}
void 
initTable(int gameTable[3][3]){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			 gameTable[i][j] = 0;
		}
	}
}
