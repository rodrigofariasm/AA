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
	map<long long, long long>::iterator iter;
	map<long long, long long> votos;
	int ele;
	long long voto;
	cin >> ele;
	for(int i = 0; i < ele; i++){
		cin >> voto;
		votos[voto] += 1;
	}
	long long winner;
	long long max = 0;
	for(iter = votos.begin(); iter!=votos.end(); ++iter){
		if(iter->second > max){
			max = iter->second;
			winner = iter->first;
		}
	}
	cout << winner <<endl;
	return 0;
}
