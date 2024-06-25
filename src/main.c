#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#define CROSS 1
#define CIRCLE 2

int gameTable[3][3];
int token = CIRCLE;

int
main(){
	bool exit = false;
	extern int gameTable[3][3] ;

	initTable(gameTable);

	printf("Enter movement, O starts first.\n0 to exit. \n ");
	while(!exit){

		if(getUserInput() == 1){
			exit = true;
		}else{

		showTable();
		}

	}


}

int
getUserInput(){
	extern int gameTable[3][3];
	int row = 0, col = 0;
	extern int token;

	printf("Select the position: "); scanf("%d %d",&row,&col);
	printf("\n");
	gameTable[row][col] = token ;
	if(token == CIRCLE ){
		token = CROSS;
	}else{
		token = CIRCLE;
	}
	return row == 0;
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
