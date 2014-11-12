// Rodrigo Farias de Macêdo
//string::empty
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
#include <set>

using namespace std;


int mat[26][26];

void dfs(int u){
    if(mat[u][u] == 2);
    else{
    mat[u][u] = 2;
        for (int i = 0; i < 26; i++){
            if(mat[u][i] == 1){
                dfs(i);
            }
        }
    }
}


int main(){
	
   
  	int cases;
    cin >>cases;
    while(cases--){
        cout << endl;
        char v;
        cin >> v;
        int n = v-64, a, b;

        for (int i = 0; i< n; i++){
            for (int j = 0; j< n; j++){
                mat[i][j] = 0;
            }
        }
        while(true){
        	std::string line;  	
            std::getline(std::cin, line);
            if(line.empty())break;
            a = line[0]-64; b = line[1] - 64;
            mat[a-1][b-1] = 1;
            mat[b-1][a-1] = 1;
            
        }
//        for (int i = 0; i< n; i++){
//            for (int j = 0; j< n; j++){
//                cout << mat[i][j]<< " ";
//            }
//            cout << endl;
//        }
//        cout << n << " n\n";
        for(int i = 0; i < n; i++){
            mat[i][i] = 0;
        }
        int c = 0;
        for (int i = 0; i < n; i++){
            if(mat[i][i] == 0){
                c++;
                dfs(i);
            }
        }
        cout<<"\n" << c << endl;
    }

}

