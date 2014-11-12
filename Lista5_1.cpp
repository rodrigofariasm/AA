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

vi bfs_num[2000];
int bugs;
int colors[2000]; 
bool isBipartite(int bugs, int ind){
	if(ind == bugs-1) return true;
	queue<int> q; q.push(ind);
	
	
	colors[ind] = 1;
	bool isBipartito = true;
	//cout << ind << endl;
	while(!q.empty() && isBipartite){
		int u = q.front(); q.pop();
		for(int j = 0; j < bfs_num[u].size(); j++){
			int v  = bfs_num[u][j];
			if(colors[v] == 0){
				colors[v] = colors[u] * -1;
				q.push(v);
			}else if(colors[v] == colors[u]){
				return false;
			}
		}
	}
	
	for(int i = 0; i < bugs; i++){
	//	cout << i << " i" << endl;
		if(colors[i] == 0) return isBipartite(bugs, i);
	}
	return isBipartito;
}

int main(){
	
	int cenarios,a ,b;
	cin >> cenarios;
	for(int i = 1; i<= cenarios;i++){
		int inte;
		cin >> bugs >> inte;
		while(inte--){
			cin >> a >> b;
			scanf("%d %d", &a, %b);
			if(a != b){
				bfs_num[a-1].push_back(b-1);
				bfs_num[b-1].push_back(a-1);
			}
		}
		for(int j = 0; j < bugs; j++) colors[j] = 0;
		cout << "Scenario #" << i << ":\n";
		if(isBipartite(bugs, 0) || bugs < 3) cout << "No suspicious bugs found!\n";
		else cout << "Suspicious bugs found!\n";
		for(int i=0; i<2000;i++){
			bfs_num[i].clear();
			colors[i] = 0;
		}
	}
	return 0;
}
