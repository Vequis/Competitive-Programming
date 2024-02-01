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

int multi(int a, int b){
    return (a*b)%MODN;
}

int atual, resp;
string s;
string alvo = "chokudai";

int cnt[112345][8];

signed main(){_

    cin >> s;

    for(int i=sz(s) - 1; i>=0; i--){
        if(s[i] == 'i'){
            cnt[i][7] = (cnt[i+1][7] + 1)%MODN;
        } else {
            cnt[i][7] = cnt[i+1][7];
        }
        for(int j=sz(alvo)-2; j>=0; j--){
            if(s[i] == alvo[j]){
                cnt[i][j] = (cnt[i+1][j] + cnt[i][j+1])%MODN;
            } else {
                cnt[i][j] = cnt[i+1][j];
            }
        }
    }

    cout << cnt[0][0] << endl;

    return 0;
}
