// Rodrigo Farias de Macêdo

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
list<int> nb;

void trocaZero(bool x){
    list<int>::iterator it2 = nb.begin();
    if(x) it2++;
    int i = 0;
    for(list<int>::reverse_iterator it = nb.rbegin(); it != nb.rend(); ++it){
        if(i > SZ(nb)/2) break;
        if(*it==0 && *it2 != *it){
            *it = *it2;
            *it2 = 0;
        }
        i++;
    }
}

void makenum(int sum){
    int a = sum/9, b = sum%9;
    if(b!=0) nb.push_back(b);
    REP(i, a) nb.push_back(9);
    EACH(it,nb)cout << *it ;
    cout << endl;
}

void update(int dif){
    if(dif > 0){
        for (list<int>::reverse_iterator it = nb.rbegin(); it != nb.rend(); ++it){
            if(9-*it > 0 && dif > 9-*it){
                dif -= (9-*it);
                *it = 9;
            }else if(9-*it > 0 && dif <= 9-*it){
                *it += dif;
                dif = 0;
                return;
            }
        }
        while(dif != 0){
            int a = dif/9, b = dif%9;
            REP(j, a){ nb.push_front(9); dif-= 9;}
            if(b!=0)  nb.push_front(b); dif-= b;
            return;
        }
    }
    if(dif == 0){
        int aux2 = -1;
        for(list<int>::reverse_iterator it = nb.rbegin(); it != nb.rend(); ++it){
            if(9 - *it > 0 && aux2 != 0 && it!= nb.rbegin()){
             *it = *it+1;
              --it;
              *it = *it -1;
              ++it;
              if(++it==nb.rend()) trocaZero(true);
              return;
            }
            aux2= *it;
        }
        trocaZero(false);
        EACH(it, nb){
            if(*it > 0){
                *it = *it-1;
                break;
            }
        }
        nb.push_front(1);
        return;
    }
    if(dif < 0){
        int difa = 0;
        list<int>::reverse_iterator it;
        for(it = nb.rbegin(); it != nb.rend(); ++it){
            if(9 - *it > 0 && difa > abs(dif) ){
                *it = *it +1;
                if (difa+dif-1!=0) update(difa + dif-1);
                return;
            }else{ difa+=*it; *it = 0;}
        }
        if(it == nb.rend()){
            EACH(it2,nb) *it2 = 0 ;
            nb.push_front(1);
            if(difa+dif-1 != 0) update(difa+dif-1);
        }
    }
}

int main() {
    scanf("%d", &n);
    int aux, last = 0;
    scanf("%d", &aux);
    makenum(aux);
    n--;
    while(n--){
        last = aux;
        scanf("%d", &aux);
        update(aux-last);
        EACH(it,nb)cout << *it ;
        cout << endl;
    }
    return 0;
}
