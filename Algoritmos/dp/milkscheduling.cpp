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

int n;
int resposta;
int resp[11234];
vii v;

bool cmp(ii a, ii b){
    return a.fs>b.fs;
}

signed main(){

    cin >> n;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        v.eb(a, b);
    }

    sort(all(v), cmp);

    for(int i=0; i<n; i++){
        int cnt=v[i].sc;
        while(cnt!=0 && resp[cnt]!=0) cnt--;
        if(cnt!=0) {
            // cout << cnt << endl;
            resposta+=v[i].fs;
            resp[cnt] = 1;
        }
    }

    cout << resposta << endl;

    return 0;
}
