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

int pt1, pt2, n;
ll resp, soma1, soma2;
vi v;

int main(){_

    cin >> n;

    v = vi(n);

    for (int i=0; i<n; i++) cin >>v[i];

    soma1 = v[0];
    soma2 = v[n-1];

    pt2 = n-1;

    while(pt1<pt2){
        // cout << soma1 << ' ' << soma2 << endl;
        if (soma1 > soma2) {
            pt2--;
            soma2+=v[pt2];
        } else if (soma1<soma2){
            pt1++;
            soma1+=v[pt1];
        } else {
            resp=soma1;
            pt1++;
            soma1+=v[pt1];
        }
    }

    cout << resp << endl;

    return 0;
}