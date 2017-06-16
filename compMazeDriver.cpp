#include"maze.h"

// Edit the code here to change maze file.
#define MAZE_FILE "/Users/alejandropenacaicedo/Desktop/maze/src/maze.txt"


bool solve1(Maze &M);
bool solve(Maze &M, char symbol);


bool solve1(Maze &M){
	M.ReadMaze(MAZE_FILE);
	int row,col;
	char symbol;
	M.getStart();
	M.getCurrentLocation(row, col);

	solve(M, symbol);

	}

bool solve(Maze &M, char symbol){
	cout<< M;
	int row,col;

	
	if(M.isFinish()){
		cout<< "We're Done"<< endl;
		return M.isFinish();
		
	}
	if(symbol != 'S' && M.south()){
		M.getCurrentLocation(row,col);
		solve(M, 'N');
		}

	if(symbol != 'N' && M.north()){
		M.getCurrentLocation(row,col);
		solve(M, 'S');
		}

	if(symbol != 'E' && M.east()){
		M.getCurrentLocation(row,col);
	        solve(M, 'W');
		}

	if(symbol != 'W' && M.west()){
		M.getCurrentLocation(row,col);
		solve(M, 'E');
		}
	

}

int main(){
	
	Maze M;	

	solve1(M);
	

return 0;

}
