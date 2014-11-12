 // Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <utility>
#include <iterator>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<long long> vi;



int main(){
	int memo[10100], mSum;
	int N, aux;
	scanf("%d", &N);
	while(N!=0){
		mSum = 0;
		for(int j = 1;j <= N; j++){
			cin >> aux;
			aux = aux + memo[j-1];
			memo[j] = aux;
			if(aux < 0){
				memo[j] = 0;
			}
			if (aux > mSum){
				mSum = aux;
			}
			
		}
//		for(int k = 1; k <= N;k++){
//			cout << memo[k];
//		}
		if(mSum>0){
			printf("The maximum winning streak is %d.\n", mSum);
		}else{
			printf("Losing streak.\n");
		}
		scanf("%d", &N);
	}	
	
}
