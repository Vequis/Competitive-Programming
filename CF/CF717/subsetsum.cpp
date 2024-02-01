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

int tabs[101][10000];

int iss(int a[], int soma, int n){
    if (soma == 0){
        return 1;
    }

    if (n<=0){
        return 0;
    }

    if (tabs[n-1][soma]!=-1){
        return tabs[n-1][soma];
    }

    if (a[n-1] > soma){
        return tabs[n-1][soma] = iss(a, soma, n-1);
    } else {
        return tabs[n-1][soma] = iss(a, soma, n-1) || iss(a, soma-a[n-1], n-1);
    }
}

int a[100], siz, sum;

int main(){_
    cin >> siz;
    for (int i=0; i<siz; i++){
        cin >> a[i];
    }

    memset(tabs, -1, sizeof(tabs));

    cin >> sum;

    if(iss(a,sum,siz)){
        cout << "da" << endl;
    } else {
        cout << "nao da" << endl;
    }

    return 0;
}