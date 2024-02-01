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

using namespace std;

vii itens(3000);
int memo[3000][3000]; //capacidade / ultimo index

int n, s;
void dp(int x){
    for(int i=1; i<=x; i++){
        for(int j=1; j<=n; j++){
            ii p = itens[j];
            if (i-p.fs < 0) {
                memo[i][j] = memo[i][j-1];
                continue;
            }
            memo[i][j] = max(memo[i-p.fs][j-1] + p.sc, memo[i][j-1]);
        }
    }
}


signed main(){_

    cin >> s >> n;

    for(int i=1; i<=n; i++){
        int a, b;
        cin >> a >> b;
        itens[i] = {a,b};
    }

    dp(s);

    // for(int i=1; i<=s; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << memo[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    cout << memo[s][n] << endl;

    return 0;
}
