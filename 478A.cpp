// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	ll soma = 0;
	int i =0;
	int aux;
	while(i < 5){
		cin >> aux;
		soma += aux;
		i++;
	}
	if(soma % 5 == 0 && soma/5!=0){
		cout << soma/5<<endl;
	}else{
		cout << -1<<endl;
	}
	return 0;
}
