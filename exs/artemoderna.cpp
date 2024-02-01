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

int linhas[5123456], colunas[5123456];
int n, m, k;
int resp;

signed main(){_

    cin >> m >> n >> k;

    for(int i=0; i<k; i++){
        char c;
        int num;
        cin >> c >> num;

        if(c=='R')linhas[num] = linhas[num]^1;
        else colunas[num] = colunas[num]^1;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(linhas[i]^colunas[j]) resp++;
        }
    }

    cout << resp << endl;

    return 0;
}
