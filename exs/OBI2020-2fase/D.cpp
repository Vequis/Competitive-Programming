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

int t, n, x; 
vi v;
double menor=INF;
double dist[MAX];

int main(){_

    cin >> t >> n;
    v.pb(0);

    for (int i=0; i<n ;i++){
        cin >> x;
        v.pb(x);
    }

    v.pb(t);

    sort(all(v));

    cout << fixed;
    cout.precision(2);

    for (int i=1; i<=n; i++){
        double a = v[i-1], b=v[i], c = v[i+1];
        if (i==1) dist[i] = b + (c - b)/2;
        else if (i==n) dist[i] = t - b + (b - a)/2;
        else dist[i] += (b - a)/2 + (c - b)/2;

        // cout << v[i] << ' ' << dist[i] << endl;

        if (dist[i] < menor) menor = dist[i];
    }

    cout << menor << endl;

    return 0;
}