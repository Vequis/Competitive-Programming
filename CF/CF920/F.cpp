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

//dei uma roubadinha olhando o editorial
//pensar que o que multiplica é
//(i - l + 1)
int psa[112345];
int pasa[112345];

signed main(){_

    int t;
    cin >> t;

    while(t--) {

        psa[0] = 0;
        pasa[0] = 0;

        int n;
        cin >> n;

        int q;
        cin >> q;

        for(int i = 1; i <=n; i++) {
            int a;
            cin >> a;
            psa[a] = psa[a-1] + a;
            pasa[a] = psa[a-1] + a*i;
        }

        while(q--) {
            
        }
    }

    return 0;
}
