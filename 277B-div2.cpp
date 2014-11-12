// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int r, c;
int o[104][104], b[104][104];
int rm[104], cm[104];

bool testalinha(int a){
	for(int i = 0; i<c;i++){
		if(b[a][i]!= 1){
			rm[a] = 0;
			return false;
		}
	}
	
	rm[a] = 1;
	return true;
}

bool testacoluna(int a){
	for(int i = 0; i<r;i++){
		if(b[i][a]!= 1){
			cm[a] = 0;
			return false;
		}
	}
	for (int j = 0; j< r; j++){
		if(rm[j] == 1){
			o[j][a] =1;
		}else{
			o[j][a] =0;
		}
	}
	cm[a] = 1;
	return true;
}


void solve(){
	//achar o a;
	for(int i = 0; i < r;i++){
		testalinha(i);
	}
	for(int i = 0; i < c;i++){
		testacoluna(i);
	}
	
}


int main(){
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> b[i][j];
		}
	}
	solve();
	string s;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(b[i][j] == 1 && rm[i] == 0 && cm[j] == 0) {
				s= "NO"; 
				break;break;	
			}
		}
	}
	if(s.compare("NO") == 0){
		cout << s << endl;
	}else{
		cout << "YES" << endl;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
			if(j != c-1 ){
				cout << o[i][j] << " ";	
			}else{
				cout << o[i][j] << endl;	
			}
		}
	}
		
	}
	
	return 0;
}
