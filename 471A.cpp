// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<int> a;
int main(){
	for(int i = 0; i<6;i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.begin()+6);
	if(a[0] == a[3]){
		if(a[4] == a[5]){
			cout << "Elephant" << endl;
		}else{
			cout << "Bear" << endl;
		}
	}else if(a[1] == a[4]){
		if(a[0] == a[5]){
			cout << "Elephant" << endl;
		}else{
			cout << "Bear" << endl;
		}
	}else if(a[2] == a[5]){
		if(a[0] == a[1]){
			cout << "Elephant" << endl;
		}else{
			cout << "Bear" << endl;
		}
	}else{
		cout << "Alien" << endl;
	}
	return 0;
}
