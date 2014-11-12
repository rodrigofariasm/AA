// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <sstream>
#include <cctype>
#include <algorithm> 
#include <vector>
#include <utility>
#include <iterator>
#include <math.h>
#include <queue>

using namespace std;

void bfs(int[][] mat, )



int main(){
	int v;
	cin >> v;
	while(v!=0){
	
	int mat[v][v];
	for (int i = 0; i<v; i++){
		for (int j = 0; j < v; j++){
			mat[i][j] = 0;
		}
	}
	int last = 0, lin, col;
	cin >> lin;
	while(last != 0 || lin != 0){
		if (last == 0 && lin!=0){
			last = lin;
			while (last != 0){
				cin >>col;
				if(col != 0) mat[lin-1][col-1] = 1;
				last = col;
			}
		}
		cin >> lin;
	}
//	for (int i = 0; i<v; i++){
//		for (int j = 0; j < v; j++){
//			cout << mat[i][j] << " ";
//		}
//		cout<<endl;
//	}
	cin >> last;
	int tof[last];
	for (int i=0; i<last; i++ ){
		cin >> tof[i];
	}
	for (int i=0; i<last; i++ ){
		col = 0;
		vector<int> ina;
		for (int j = 0; j < v; j++){
			if(mat[tof[i]-1][j] == 0){
				col++; ina.push_back(j+1);
			}
		}
		cout << col;
		for(int i = 0; i < ina.size();i++){
			cout << " " << ina[i];
		}
		cout << endl;
	}
	
	cin >> v;
	
	}
	return 0;
}
