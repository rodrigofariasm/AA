// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <algorithm> 
#include <vector>
#include <iterator>
#include <math.h>
using namespace std;

int main(){
	int n, m, aux, min = 0, max = 0;
	cin >> n >> m;
	vector<int> scores, scores2;
	for (int i = 0; i < n ; i++){
		cin >> aux;
		scores.push_back(aux);
	}
	for (int i = 0; i < n ; i++){
		cin >> aux;
		scores2.push_back(aux);
 	}
 	sort(scores.begin(), scores.end());
 	sort(scores2.begin(), scores2.end());
 	for (int i = 0; i < n ; i++){
		scores[i] += scores2[i];
	}
 	
 	
	for(int i = 0; i < n; i++){
		if(scores[i] >= m){
			max = n - i; min = 1; break;
		}
	}
	cout << min << " " << max << endl;	
	return 0;
}
