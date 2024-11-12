#include<bits/stdc++.h>
using namespace std;

void printboard(int board[][100],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool issafe(int board[][100],int n,int i,int j){
	int row=i;
	while(row>=0){                  
		if(board[row][j]){
			return false;
		}
		row--;
	}
		
	row=i;
	int col=j;
	while(row>=0 && col<n){                   
			if(board[row][col]) return false;
			row--;
			col++;
	}
	
	row=i;
	col=j;
	while(row>=0 && col>=0){
		if(board[row][col]) return false;
		row--;
		col--;
	}                              
	return true;
}

bool PlaceNQueen(int board[][100],int n,int curr_row){
	if(curr_row==n){
		printboard(board,n);
		return true;
	}
	
	for(int j=0;j<n;j++){
		if(issafe(board,n,curr_row,j)){
			board[curr_row][j]=1;
			bool ans = PlaceNQueen(board,n,curr_row+1);
			if(ans){
				return true;
			}
			board[curr_row][j]=0;
		}
	}
	return false;
	
}

int main(){
	cout<<"Enter size of board:";
	int n;
	cin>>n;
	
	int board[100][100]={};
	PlaceNQueen(board,n,0);
	return 0;
}