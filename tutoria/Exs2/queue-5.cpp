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

vector<int> fib(100100);
int n,k;

int add(int a, int b){
    return a%1000007+b%1000007;
}

int main(){_
    int t;
    cin >> t;

    fib[1] = 0;
    fib[2] = 1;
    
    for (int i=0; i<t; i++){
        fib = vi(100100);

        cin >> k >> n;

        for (int j=1; j<=k; j++){
            fib[j] = j-1;
            fib[k+1] += j-1; 
        }

        for (int j=k+2; j<=n; j++){
            fib[j] = add(fib[j-1], fib[j-1]);
            fib[j] -= fib[j-(k+1)];

            fib[j] %= 1000007;
            if (fib[j] < 0) fib[j]+=1000007;
        }

        cout << fib[n] << endl;
        fib.clear();
    }

    return 0;
}