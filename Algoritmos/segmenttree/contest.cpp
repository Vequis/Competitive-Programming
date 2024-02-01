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

double a,b,c,d,v,m;

int main(){_

    cin >> a >> b >> c >> d;

    m = max(3.0*(a/10.0), a - a*c/250.0);
    v = max(3.0*(b/10.0), b - b*d/250.0);

    if (m>v) cout <<"Misha" << endl;
    else if (m<v) cout << "Vasya" << endl;
    else cout << "Tie" << endl;

    return 0;
}