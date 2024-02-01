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

int caotica(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    return (n-1)*(caotica(n-1) + caotica(n-2));
}

int fatorial(int n){
    if(n==1) return 1;
    return fatorial(n-1)*n;
}

int mdc(int a, int b){
    if(b>a) swap(a,b);
    if(b==0) return a;
    return mdc(b, a%b);
}

signed main(){_

    int n;
    cin >>  n;

    int a = caotica(n), b=fatorial(n);
    int divisor = mdc(a, b);
    cout << a/divisor << '/' << b/divisor;

    return 0;
}
