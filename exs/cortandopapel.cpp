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
const int MAXN = (1<<20);

using namespace std;

// Notação: -2: buraco; 0: nada; +2 Ponta

vii v;
int vetor[MAXN];

int maior(int ind, int sent){
    if (v[ind].fs > v[ind+sent].fs ) return 1;
    else if (v[ind].fs < v[ind+sent].fs) return -1;
    else return maior(ind+sent, sent);
}

int main(){_

    int n;
    cin >> n;

    v.eb(0,0);

    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        v.eb(x, i);
    }
    v.eb(0,n+1);

    for (int i=1; i<=n; i++){
        vetor[i] = maior(i, 1) + maior(i, -1);
        cout << vetor[i] << ' ';
    }
    cout << endl;

    sort(all(v));

    ll ans = 2;
    ll atual = 0;

    int ant = 0;

    for (int i=2; i<=n+1; i++){
        // if (v[i].fs != ant){
        atual-=vetor[v[i].sc]/2;
        ans = max(ans, atual);
        // }
        ant = v[i].fs;
        cout << vetor[v[i].sc]/2 << ' ';
    }

    cout << ans << endl;

    return 0;
}