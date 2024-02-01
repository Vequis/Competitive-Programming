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
#define maxn 1123456

using namespace std;

int n;
stack<int> pilha;
vi v;
int maior_dir[maxn], maior_esq[maxn];
int resp = 0;

signed main(){_

    cin >> n;

    v = vi(n+1);

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    for(int i=1; i<=n; i++){

        while(!pilha.empty() && v[pilha.top()] <= v[i]){
            maior_dir[pilha.top()] = i;
            pilha.pop();
        }

        pilha.push(i);
    }

    while(!pilha.empty()) {
        maior_dir[pilha.top()] = n+1;
        pilha.pop();
    }

    for(int i=n; i>=1; i--){

        while(!pilha.empty() && v[pilha.top()] < v[i]){
            maior_esq[pilha.top()] = i;
            pilha.pop();
        }

        pilha.push(i);
    }

    while(!pilha.empty()) {
        maior_esq[pilha.top()] = 0;
        pilha.pop();
    }

    // for(int i=1; i<=n; i++){
    //     cout << maior_dir[i] << ' ' << maior_esq[i] << endl;
    // }

    for(int i=1; i<=n; i++){
        if (i!=n)resp++;
        if (maior_dir[i] != i+1 && maior_dir[i] != n+1) resp++;
    }

    for(int i=1; i<=n; i++){
        if (maior_esq[i] != i-1 && maior_esq[i] != 0) resp++;
    }

    cout << resp << endl;

    return 0;
}
