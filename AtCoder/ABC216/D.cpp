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
#define maxn 212345

using namespace std;

vi topo[maxn];
int n, m, ult;
stack<int> pilha[maxn];
stack<int> ordem;
int cnt;

signed main(){_

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        int k;
        cin >> k;
        for(int i=1; i<=k; i++){

            int num;
            cin >> num;

            pilha.push(num);

        }

        ult = pilha.top();

        topo[ult].pb(i);
        if(sz(topo[ult]) == 2) ordem.push(ult);
    }

    cnt=0;
    while(!ordem.empty()){

    }

    return 0;
}

