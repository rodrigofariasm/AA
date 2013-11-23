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

int search(int A[], int key, int imin, int imax){
	int valor = -1;
	while (imax >= imin){
	    int imid = (imin + imax)/2;
	    if(A[imid] == key){
	     	valor = imid;
	     	imax = imid - 1;
		}else if (A[imid] < key){
			imin = imid + 1;
    	}else{
    	    imax = imid - 1;
    	}
    }
 
  return valor;
	
}


int main(){
	long long t, s;
	scanf("%lld %lld", &t, &s);
	int ele[t];
	int x, aux;
	for (int i = 0; i < t; i++){
		scanf("%d", &ele[i]);
	}
	for (int i = 0; i < s ; i++){
		scanf("%d", &aux);		
		x = search(ele, aux, 0, t-1);
//		while(x != -1 && ele[x-1] == aux){
//			x--;
//		}
		printf("%d\n", x);
	}
}
