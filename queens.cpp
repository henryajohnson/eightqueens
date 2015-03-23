#include <iostream>

using namespace std;


void printBoard(bool **board, int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cout << ((board[i][j]) ? "Q " : ". ");
		}
		cout << endl;
	}
	return;
}


bool checkConflict(bool **board, int row, int col, int size, bool direction){
	//Returns true if there is a conflict
	if(board[row][col]){ // if there is a queen at this point, return false
		return true;
	}else{
		if(row==0){ //if we are at the top row and no conflicts, return false since we can go up higher
			return false;
		}
		if(direction){
			if((col+1) < size){ //if we won't go out of range going up, go up
				return checkConflict(board, row-1, col+1, size, direction);
			}
			return false;
		}else{
			if( col > 0){
				return checkConflict(board, row-1, col-1, size, direction);
			}
			return false;
		}
	}	
}

void permutation(bool **board, int size, int row, bool *column){
	if(row == size){

		cout << endl << "Solution: " << endl;
		printBoard(board, size);
		cout << endl<< " ----------- " << endl;
		
	}else{
		for(int i=0; i<size; i++){
			if(!column[i]){
				column[i] = true;
				board[row][i] = true;
				if(!(checkConflict(board, row-1, i+1, size, true) || checkConflict(board, row-1, i-1, size, false)) ){
					permutation(board, size, (row+1), column);
				}
				column[i] = false;
				board[row][i] = false;
			}
		}
	}
}

void permuteQueens(int size){
	bool **board;
	board = new bool *[size];
	for(int i=0; i<size; i++){
		board[i] = new bool[size];
	}
	bool *column = new bool[size];
	
	for(int j=0; j<size; j++){
		board[0][j] = true;
		column[j] = true;
		permutation(board, size, 1, column);
		board[0][j] = false;
		column[j] = false;
	}


	for(int i=0; i<size; i++){
		delete board[i];
	}
	delete board, column;
	return;
}


int main(){
	cout << "How many queens? " << endl;
	int queens;
	cin >> queens;
	cout << "We have " << queens << " queens" << endl;
	permuteQueens(queens);

}