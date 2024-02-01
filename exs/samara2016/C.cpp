#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x)  (x).begin() , (x).end()
#define fs first
#define sc second
#define ii pair<int, int>
#define vii vector<ii>
#define endl '\n'
#define ll long long int
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina
#define maxn 1000100
using namespace std;

int raiz[maxn];

signed main(){_

    int p;
    cin >> p;

    memset(raiz, -1, sizeof(raiz));

    for(int i=0; i<p; i++){
        int atual = (i*i)%p;
        if(raiz[atual] == -1){
            raiz[atual] = i;
        }
    }

    for(int i=0; i<=p-1; i++){
        cout << raiz[i] << ' ';
    }

    return 0;
}
