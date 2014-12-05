// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	vector<int> t1, t2, t3;
	int n, x;
	int aux = 1;
	cin >> n;
	while(aux <= n){
		cin >> x;
		if(x == 1){
			t1.push_back(aux);
		}else if(x == 2){
			t2.push_back(aux);
		}else if(x == 3){
			t3.push_back(aux);
		}
		aux++;
	}
	int a = min(t1.size(), min(t2.size(), t3.size()));
	cout << a << endl;
	for(int i = 0; i < a ; i++){
		cout << t1[i] << " " << t2[i] << " " << t3[i];
		if(i+1 < a){
			cout << endl;
		}
	}
	
}
