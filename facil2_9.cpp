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
	int x, mod;
	cin >> x;
	int nb[x];
	for(int i = 0; i < x; i++){
		int aux;
		cin >> aux;
		nb[i] = aux%2;
	}
	if(nb[0] == nb[1]) mod = nb[0];
	else if(nb[0] == nb[2]) mod = nb[0];
	else mod = nb[1];
	for(int i = 0; i < x; i++){
		if(nb[i]%2 != mod){
			cout << i+1 << endl;
			break;
		}
	}
	
}    
