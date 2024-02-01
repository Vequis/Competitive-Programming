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
// #define int long long -> solução divina?

using namespace std;

char c;
int n, t, x;
vi resp;
vi v;

int main(){_

    v = vi(111);
    resp = vi(111);

    cin >> n;

    t=1;
    for(int i=0; i<n; i++){
        cin >> c >> x;
        if(c=='R'){
            v[x] = t;
            t++;
        } else if (c=='E'){
            resp[x] += t-v[x];
            v[x] = 0;
            t++;
        } else if (c=='T'){
            t+=x-1;
        }
    }


    for(int i=1; i<=100; i++){
        if (v[i]!=0){
            cout << i << ' ' << -1 << endl;
        } else if(resp[i]!=0){
            cout << i << ' ' << resp[i] << endl;
        }
    }

    return 0;
}
