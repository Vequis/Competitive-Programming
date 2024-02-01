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

using namespace std;

float d;
ll r, x, y;
ll resp = 0, soma;

int main(){_

    cin >> r >> x >> y;
    soma = x*x;
    soma+=y*y;
    d= sqrt(soma);
    // cout << soma << ' ' << d << endl;
    if (d<r){
        cout << 2 << endl;
        return 0;
    }
    while(d>0){
        resp++;
        d-=r;
    }

    cout << resp << endl;

    return 0;
}