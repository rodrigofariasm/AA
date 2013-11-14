// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm> 


using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	string magnet;
	string aux;
	int groups = 1;
	cin >> magnet;
	for (int i = 1; i < n; i++){
		cin >> aux;
		if(magnet != aux){
			groups ++;
			magnet = aux;
		}
		
	}
	cout << groups;
	return 0;
}
