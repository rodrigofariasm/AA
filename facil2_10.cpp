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
#include <queue>

using namespace std;


int main(){
	int c;
	cin >>c ;
	while(c!=0){
		int desc[c-1];
		queue<int> baralho;
		for(int i =0; i<c;i++){
			baralho.push(i+1);
		}
		for(int i = 0; i<c-1; i++){
			desc[i] = baralho.front();
			baralho.pop();
			baralho.push(baralho.front());
			baralho.pop();
		}
		cout << "Discarded cards:";
		for(int i = 0; i<c-1; i++){
			cout << " " << desc[i];
			if(i!=c-2) cout <<',';
		}
		cout <<"\nRemaining card: " << baralho.front()<< endl;
		cin >> c;
	}
	
}    
