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
	int i = 0;
	scanf("%d", &n);
	int vetor[n-1];
	while(n > 1){
		cin >> vetor[i];
		n--;
		i++;
	}

	int e, f;
	scanf("%d %d", &e, &f);
	int soma=0;
	for(int k = e-1; k < f-1 ; k++){
		soma+= vetor[k];
	}
	cout << soma;
	return 0;
	
}
