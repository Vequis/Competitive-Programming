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

int n, m, num;
int mat[51][51];
ll resp;

ll pot(int n){
    if (n<0){
        cout << "deu erro!!" << endl;
        return 10000;
    }
    if(n==0) return 1;
    return 2*pot(n-1);
}

int main(){_

    cin >> n >> m;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> num;
            mat[i][0]+=num; //Quantos pretos tem na linha 1;
            mat[0][j]+=num;
            mat[i][j] = num;
        }
    }

    // for (int i=1; i<=n; i++){
    //     cout << mat[i][0] << ' ' << mat[0][i] << endl;
    // }

    for (int i=1; i<=n; i++){
        resp += pot(mat[i][0]);
        resp += pot(m - mat[i][0]);
        resp -= 2;
        // cout << resp << endl;
    }

    for (int j=1; j<=m; j++){
        resp += pot(mat[0][j]);
        resp += pot(n - mat[0][j]);
        resp -= (n + 2);
        // cout << resp << endl;
    }

    cout << resp << endl;

    return 0;
}