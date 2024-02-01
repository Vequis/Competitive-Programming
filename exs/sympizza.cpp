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

int mdc(int a, int b){
    if(b>a) swap(a,b);
    if (!b) return a;
    return mdc(b, a%b);
}

double r;
int r1,r2;
char c;

int main(){_

    cin >> r1 >> c >> r2;
    r1 = r1*100 + r2;

    cout << 36000/mdc(r1,36000) << endl;

    return 0;
}