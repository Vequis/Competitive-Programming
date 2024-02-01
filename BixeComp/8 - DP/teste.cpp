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
int n, q, atual;
int memo[312345][3];
int h[312345], custo[312345];

int minLL(int a, int b){
    if(a<b) return a;
    else return b;
}

int dp(int tabua, int aumento){
    if(tabua == 0 or tabua>n) return 0;

    if(memo[tabua][aumento] != -1) return memo[tabua][aumento];

    int resp = LLONG_MAX1;
    for(int i=0; i<3; i++){
        if(h[tabua] + aumento == h[tabua-1]+i) continue;
        atual =(custo[tabua]);
        atual *=aumento;
        atual += dp(tabua-1, i);
        resp = minLL(resp,atual);
        cout << '*' << atual << " " << resp << endl;
    } 

    return memo[tabua][aumento] = resp;
}


signed main(){_

    cout << minLL(INT_MAX + INT_MAX, INT_MAX*3) << endl;

    cin >> q;


    while(q--){
        cin >> n;
        memset(memo, -1, sizeof(memo));


        n=100;
        for(int i = 1; i<=n; i++){
            int a=1000000000, b=1000000000;
            // cin >> a >> b;
            h[i] = a;
            custo[i] = b;
        }

        for(int i=1; i<=n; i++){
            for(int j=0; j<=2; j++){
                cout << dp(i, j) << "<" << endl;
            }
            cout << endl;
        }

        cout << minLL(minLL(dp(n, 0), dp(n,1)), dp(n, 2)) << endl;
    }

    return 0;
}
