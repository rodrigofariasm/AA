// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n;
vector<ll> a;

ll dist(int a, int b){
	return min(abs(a-b), 24 - abs(a- b));
}

void read(){
    while(!(cin >> n).eof()){
    	vector<ll> aux (a);
    	aux.resize(n);
    	int j = 0;
		while (j < n){
			cin >> aux[j];
			j++;
		}
		
		sort(aux.begin(), aux.begin()+n);
		int menor = 13;
		int l = 0; int r = n-1;
		while(r-l > 1){
			if(dist(aux[r],aux[l]) < dist(aux[l+1],aux[l]) && dist(aux[r],aux[l]) < dist(aux[r],aux[r-1])){
				l++;
				r--;
				if(dist(aux[r],aux[l]) < menor) menor = dist(aux[r],aux[l]);
			}else if(dist(aux[r],aux[r-1]) < dist(aux[l+1],aux[l])){
				r -=2;
				if(dist(aux[r],aux[r-1]) < menor) menor = dist(aux[r],aux[r-1]);
			}else{
				l+=2;
				if(dist(aux[l+1],aux[l]) < menor) menor = dist(aux[l+1],aux[l]);
			}
			cout << "menor = " << menor << " l = " << l << " r= " << r << endl;
		}
		if(dist(aux[r], aux[l])< menor) menor = dist(aux[r], aux[l]);
		cout << menor << endl;
    }
    
    
}

int main(){
	ios_base::sync_with_stdio(0);
    read();
    
    return 0;
}
