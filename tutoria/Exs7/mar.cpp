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
#define MAX (1<<10) //2^10 = 1024

using namespace std;

int psa[110][110], a[110][110];
int n, xi, xf, yi, yf;
ll cont;

int main(){_

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> xi >> xf >> yi >> yf;
        a[yi][xi]+=1;
        a[yi][xf]-=1;
        a[yf][xi]-=1;
        a[yf][xf]+=1;

    }

    for (int i=1; i<=101; i++){
        for (int j=1; j<=101; j++){
            psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + a[i][j];
            // cout << psa[i][j] << ' ';
            if (psa[i][j]) cont++;
        }
    }

    cout << cont << endl;

    return 0;
}