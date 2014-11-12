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

int memo[20100], a, b, mSum;

int main(){
	int aux;
	int nrotas, stops;
	scanf("%d", &nrotas);
	for(int i = 0;i < nrotas; i++){
		scanf("%d", &stops);
		int ma = 0, mb=0;
		a = 0, b = 0, mSum = 0;
		for (int j = 1; j < stops; j++){
			scanf("%d", &aux);
			aux = aux + memo[j-1];
			if(aux < 0){
				a = j; b =j;
				memo[j] = 0;
			}
			if(aux > 0){
				memo[j] = aux;
				if(mSum < aux){
					mSum = aux;
					b = j;
					ma = a, mb = b;
				}else if(mSum == aux){
					b=j;
					if(b-a > mb-ma){
						ma = a, mb = b;
					}
				}
			}

		}
//		for(int k = 0; k < stops;k++){
//			cout << memo[k];
//		}
		if(mSum>0){
				printf("The nicest part of route %d is between stops %d and %d\n", i+1, ma+1, mb+1);
			}else{
				printf("Route %d has no nice parts\n", i+1);
			}
	}	
	
}
