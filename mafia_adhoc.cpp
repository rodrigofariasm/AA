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

int main(){
	int n;
	scanf("%d", &n);
	int vetor[n];	
	for(int i = 0; i < n; i++){
		cin >> vetor[i];
	}
	vector<int> vector1 (vetor, vetor+n);
	sort (vector1.begin(), vector1.begin()+n);
	int flag = 0;
	for(int i = n - 1 ; i > 0; i--){
		int aux = vector1[i] - vector1[i-1];
		if( aux > 1){
			flag = 1;
			break;
		} 
	}
	if(flag == 1){
		cout << vector1[n-1];
	}else{
		cout << vector1[n-1] + 1;
	}
	
}
