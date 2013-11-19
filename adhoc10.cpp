// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm> 
#include <map>

using namespace std;

int main(){
	int n, q;
	map<int, int> pos;
	long long v= 0, p=0;
	scanf("%d", &n);
	int aux;
	for(int i = 0; i < n; i++){
		cin >> aux;
		pos[aux] = i+1;
	}
	scanf("%d", &q);
	int queries[q];
	for(int i = 0; i < q; i++){
		cin >> queries[i];
	}
	for(int i = 0; i < q; i++){
		v += pos[queries[i]];
		p += n - pos[queries[i]] + 1;
		
	}
	cout << v << " " << p;	
}
