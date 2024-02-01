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

ll x,y, a, b;
ll cont;

int main(){_

    cin >> x >> y >> a >> b;

    while(x < b/(a-1) && x < y/a){
        x = a*x;
        cont++;
    }
    if (x<y) cont+=(y-x)/b;
    if ((y-x)%b == 0 && x < y) cont--; 

    cout << cont << endl;

    return 0;
}