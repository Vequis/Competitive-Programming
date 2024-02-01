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

using namespace std;

//1101

int p;

ll bin_pow(int a, int b){
    ll ans = 1;
    ll aux = 1;
    while(b){
        if (b%2) ans = (a*ans)%p;
        a = (a*a)%p; 
        b/=2;
    }
    return ans;
}

ll bin_pow(int a, int b){
    ll ans = 1;
    int aux = b;
    while(aux){
        if (b%2) ans = (ans * a);
        a = a*a;
        b/=2;
    }
}

int a,b;

ll mdc(int a, int b){
    if (a<b) return mdc(b,a);
    if (b==0) return a;
    return mdc(b, a%b); 
}

ll inverso_modular(int a) {
    if (mdc(a,p)!=1) return -1;
    ll ans;
    ans = bin_pow(a,p-2)%p;
    return ans;
}


int main(){_
    cin >> a >> p;

    cout << inverso_modular(a);

    return 0;
}