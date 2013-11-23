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
	long long n, k, l=1, w;
	cin >> n >> k;
	long long mid, pot =1, r = n, aux = n;
	while( r >= l){
		int lines = 0;
		mid = l + (r-l)/2;
//		printf("mid %d\n", mid);
		w = mid;
		lines = lines + w;
		while(w!=0){
			w = mid/pow(k, pot);
			lines = lines + w;
			pot++;
//			printf("pow %d lines %d \n", w, lines);
		}
		pot = 1;
//		printf("%d %d\n", lines, w);
//		printf("l %d r %d\n", l, r);
//		if(r < l) break;
		if(lines == n){
			aux =mid;
			break;
		}else if(lines > n){
			aux = mid;
 			r = mid-1;
		}else if(lines < n){
			l = mid + 1;
		}
//		printf("%d aux\n", aux);
		lines = 0;
	}
	cout << aux << endl;
	
}
