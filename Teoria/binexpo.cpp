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

using namespace std;

int power(int a, int b){
    int ans = 1;
    while(b){
        if (b%2) ans *= a;
        a*=a;
        b/=2;
    }
    return ans;
}

int power2(int a, int b){
    if (!b) return 1;
    int ans = power2(a, b/2);
    ans *= ans;
    if (b%2) ans*=a;
    return ans;
}

int main(){_
    int a, b;
    cin >> a >> b;

    cout << power2(a, b) << endl;

    return 0;
}