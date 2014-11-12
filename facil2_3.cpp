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
#include <set>
#include <map>


using namespace std;



int main(){
	vector<long long> s;
	map<long long, string> alunos;
	int jogadores, times;
	string jogador; long long hab;
	cin >> jogadores >> times;
	for(int i = 0; i < jogadores; i++){
		cin >> jogador >> hab;
		alunos[hab] = jogador;
		s.push_back(hab);
	}
	vector<string> teams[times];
	sort(s.begin(), s.end());
	int asd = 0;
	for(int i = s.size()-1; i >= 0; i--){
		int x = asd%times;
		teams[x].push_back(alunos[s[i]]);
		asd++;
	}	
	for(int i = 1; i <= times;i++){
		cout << "Time " << i<<endl;
		sort(teams[i-1].begin(), teams[i-1].end());
		for(int j = 0; j < teams[i-1].size() ; j++){
			cout << teams[i-1][j] << endl;
		}
		cout << endl;
	}
}
