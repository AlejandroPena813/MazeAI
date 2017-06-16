//Alejandro Pena Caicedo	
//ufID: 3712-3113

//Compiler may give a warning, but the code still solves maze.

#include"maze.h"


#define MAZE_FILE "/Users/alejandropenacaicedo/Desktop/maze/src/maze2.txt"

bool solve(Maze &M, char symbol);

bool solve(Maze &M, char symbol){
	cout<< M;
	int row,col;

	//This first if statement is the base case, if our coordinates are the final coordinates the method returns true.
	if(M.isFinish()){
		cout<< "We're Done"<< endl;
		return true;
				
	}
	//These four if statements make sure that the last last move is not in the complete opposite direction, in other words so that
	//the computer wont move back and forth. The method recursively solves the maze by moving in directions that are readily available to it, and        //then performing a depth-first search.

	if(!M.isFinish()&& symbol != 'S' && M.south()){
		M.getCurrentLocation(row,col);
		solve(M, 'N');
		}

	if(!M.isFinish()&& symbol != 'N' && M.north()){
		M.getCurrentLocation(row,col);
		solve(M, 'S');
		}

	if(!M.isFinish()&& symbol != 'E' && M.east()){
		M.getCurrentLocation(row,col);
	        solve(M, 'W');
		}

	if(!M.isFinish()&& symbol != 'W' && M.west()){
		M.getCurrentLocation(row,col);
		solve(M, 'E');
		}
	

}

int main(){
	
	Maze M;	

	M.ReadMaze(MAZE_FILE);
	int row,col;
	char symbol;
	M.getStart();
	M.getCurrentLocation(row, col);


	solve(M, symbol);
	

return 0;

}

