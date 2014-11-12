// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm> 
#include <vector>

using namespace std;

int mat[3][3];
int result[3][3];

void acendeLuzes(){
	
	for (int i = 0; i < 3; i++){
		for(int j=0; j<3; j++){
			if(mat[i][j] % 2 == 1){
				if (result[i][j] == 1) result[i][j] = 0;
				else result[i][j] = 1;
				if(i == 0){
					if(j == 0){
						if (result[i+1][j] == 1) result[i+1][j] = 0;
						else result[i+1][j] = 1;
						if (result[i][j+1] == 1) result[i][j+1] = 0;
						else result[i][j+1] = 1;
					}else if(j == 2){
						if (result[i+1][j] == 1) result[i+1][j] = 0;
						else result[i+1][j] = 1;
						if (result[i][j-1] == 1) result[i][j-1] = 0;
						else result[i][j-1] = 1;
					}else{
						if (result[i+1][j] == 1) result[i+1][j] = 0;
						else result[i+1][j] = 1;
						if (result[i][j+1] == 1) result[i][j+1] = 0;
						else result[i][j+1] = 1;
						if (result[i][j-1] == 1) result[i][j-1] = 0;
						else result[i][j-1] = 1;
					}
				}else if(i == 2){
					if(j == 0){
						if (result[i-1][j] == 1) result[i-1][j] = 0;
						else result[i-1][j] = 1;
						if (result[i][j+1] == 1) result[i][j+1] = 0;
						else result[i][j+1] = 1;
					}else if(j == 2){
						if (result[i-1][j] == 1) result[i-1][j] = 0;
						else result[i-1][j] = 1;
						if (result[i][j-1] == 1) result[i][j-1] = 0;
						else result[i][j-1] = 1;
					}else{
						if (result[i-1][j] == 1) result[i-1][j] = 0;
						else result[i-1][j] = 1;
						if (result[i][j-1] == 1) result[i][j-1] = 0;
						else result[i][j-1] = 1;
						if (result[i][j+1] == 1) result[i][j+1] = 0;
						else result[i][j+1] = 1;
					}
				}else{
					if(j == 0){
						if (result[i+1][j] == 1) result[i+1][j] = 0;
						else result[i+1][j] = 1;
						if (result[i][j+1] == 1) result[i][j+1] = 0;
						else result[i][j+1] = 1;
						if (result[i-1][j] == 1) result[i-1][j] = 0;
						else result[i-1][j] = 1;
					}else if(j == 2){
						if (result[i+1][j] == 1) result[i+1][j] = 0;
						else result[i+1][j] = 1;
						if (result[i][j-1] == 1) result[i][j-1] = 0;
						else result[i][j-1] = 1;
						if (result[i-1][j] == 1) result[i-1][j] = 0;
						else result[i-1][j] = 1;
					}else{
						if (result[i+1][j] == 1) result[i+1][j] = 0;
						else result[i+1][j] = 1;
						if (result[i][j+1] == 1) result[i][j+1] = 0;
						else result[i][j+1] = 1;
						if (result[i-1][j] == 1) result[i-1][j] = 0;
						else result[i-1][j] = 1;
						if (result[i][j-1] == 1) result[i][j-1] = 0;
						else result[i][j-1] = 1;
					}
				}
			
			}
		}
		
	}
}



int main(){
	for (int i = 0; i<3; i++){
		cin >> mat[i][0] >>  mat[i][1] >> mat[i][2];
		result[i][0] = 1, result[i][1] = 1, result[i][2] = 1;
	}
	acendeLuzes();
	for (int i = 0; i<3; i++){
		cout << result[i][0] << result[i][1] << result[i][2] << endl;
	}
	
	
	return 0;
}
