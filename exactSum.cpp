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
	int books;
	while(scanf("%d", &books) != EOF){
		vector<int> price;
		int money, x;
		for(int i = 0; i<books; i++){
			cin >> x;
			price.push_back(x);
		}
		scanf("%d", &money);
		int l, r;
		sort(price.begin(), price.end());
		int i, j, dif = 1000001, mid;
		
		for (int k = books; k >= 0 ; k--){
			l=0;
			r = k-1;
			int aux = price[r];
		
			if(r <= 0){
				break;
			}
	//		cout << aux;
			while(r >= l){
				mid = (l+r)/2;
				if(price[mid] + aux == money){
					int aux2 = price[mid];
					if(aux > aux2){
						if(aux - aux2 < dif){
							i = aux2; j = aux;
						}
					}else{
						if(aux2 - aux < dif){
							i = aux; j = aux2;
						}
					}
					break;
				}else if(price[mid] + aux > money){
					r = mid -1;
				}else{
					l = mid +1;
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", i, j);
	
	}
	
	return 0;
}
