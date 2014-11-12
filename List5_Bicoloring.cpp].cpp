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

bool isBipartite(long long bugs){
	queue<long long> q; q.push(0);
	int colors[bugs]; colors[0] = 0;
	for(int i = 0; i < bugs; i++) colors[i] = -1;
	bool isBipartite = true;
	while(!q.empty() && isBipartite){
		int u = q.front(); q.pop();
		for(int j = 0; j < bfs_num[u].size(); j++){
			int v  = bfs_num[u][j];
//			cout << colors[v] << " v " << v << endl;
//			cout << colors[u] << " u " << u << endl;
			if(colors[v] == -1){
				colors[v] = 1-colors[u];
				q.push(v);
			}else if(colors[v] == colors[u]){
				isBipartite = false; break;
			}
		}
	}
	return isBipartite;
}

int main(){
	int n;
	cin >> n;
	while(n != 0){
		int inte, a, b;
		cin >> inte;
		while(inte--){
			cin >> a >> b;
			bfs_num[a].push_back(b);
			bfs_num[b].push_back(a);
		}
		//cout << "Scenario #" << i << ":\n";
		if(isBipartite(n)) cout << "BICOLORABLE.\n";
		else cout << "NOT BICOLORABLE.\n";
		for(int i=0; i<2000;i++){
			bfs_num[i].clear();
		}
		cin >> n;
	}
	
	return 0;
}
