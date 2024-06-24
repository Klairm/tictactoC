#include <stdio.h>
#include <string.h>


const int CROSS = 1;
const int CIRCLE = 2;

int gameTable[3][3];

int
main(){

	extern int gameTable[3][3] ;

	initTable(gameTable);

	showTable();



}

void
showTable(){
	for(int row = 0; row < 3; row++){
		for(int column = 0; column < 3; column++){
			printf("- ");

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
