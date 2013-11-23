// Rodrigo Farias de Macêdo


#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <map>
#include <algorithm> 
#include <vector>
#include <iterator>
#include <utility>
using namespace std;
	
vector<int> chimps;

int main(){
	std::ios_base::sync_with_stdio(false);
	int c, q, aux;
	scanf("%d", &c);

	
	for (int i = 0; i < c; i++){
		cin >> aux;
		chimps.push_back(aux);
	}
	scanf("%d", &q);
	vector<int>::iterator low, up;
	for (int i = 0; i < q; i++){
		cin >> aux;
		low = lower_bound(chimps.begin(), chimps.end(), aux);
		up = upper_bound(chimps.begin(), chimps.end(), aux);
		if(low!=chimps.begin() && *(low-1)<aux)
			printf("%d ", *(low-1));
		else printf("X ");
		if(up!=chimps.end() && *(up)>aux)
			printf("%d\n",*up);
		else printf("X\n");
	}
	return 0;
}
