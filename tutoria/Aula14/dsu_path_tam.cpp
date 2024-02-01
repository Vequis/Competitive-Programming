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
#define MAX (1<<20)

using namespace std;

int n;
int tam[MAX], pai[MAX];

int init(int m){
    for (int i=1; i<=m; i++){
        tam[i] = 1;
        pai[i] = i;
    }
}

int find(int u){
    if (u == pai[u]) return pai[u];
    return pai[u] = find(pai[u]);
}

int uniao(int u, int v){
    u = find(u);//u vira o representante de u
    v = find(v);//u vira o representante de u
    if (tam[u] > tam[v])
        pai[v] = u;
        tam[u] += tam[v];
    else {
        pai[u] = v;
        tam[v] += tam[u];
    } 
}

int main(){_

    cin >> n;

    init(n); 

    return 0;
}