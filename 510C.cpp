#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define SZ(S) ((int) ((S).size()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { REP(_,n) cout << a[_] << ' '; cout << endl; }

int n;
int G[26][26];
int c[26];
int topo[30],top;
char mp[105][105];
int dfs(int u){
    c[u]=-1;
    REP(v, 26)
        if(G[u][v]){
            if(c[v]<0) return 0;
            else if(!c[v]&&!dfs(v)) return 0;
        }
        c[u]=1;
        topo[--top]=u;
        return 1;
}
bool toposort(){
    top=26;
    memset(c,0,sizeof(c));
    REP(u, 26)
        if(!c[u]&&!dfs(u))
            return false;
    return true;
}

int main(void){
    scanf("%d",&n);
    REP(i,n)  scanf("%s",mp[i]);
    int OK=1;
    for(int i=0;i<n-1&&OK;i++){
        int j;
        int len1=strlen(mp[i]),len2=strlen(mp[i+1]);
        for(j=0;j<min(len1,len2);j++){
            if(mp[i][j]==mp[i+1][j]) continue;
            else if(G[mp[i+1][j]-'a'][mp[i][j]-'a']) {
                OK=0;
                break;
            }
            else {
                G[mp[i][j]-'a'][mp[i+1][j]-'a']=1;
                break;
            }
        }
        if(j==min(len1,len2)&&len1>len2) OK=0;
    }
    if(!OK){
        printf("Impossible\n");
        return 0;
    }
    if(toposort()){
        REP(i, 26)
            printf("%c",topo[i]+'a');
        printf("\n");
    }
    else printf("Impossible\n");


    return 0;
}
