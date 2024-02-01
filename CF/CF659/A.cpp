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

int t, n, tam;
string st1, st2;
int a1, a2;

int main(){_
    cin >> t;

    for (int i=0; i<t; i++){
        st1 = "aaaaaaaaaaa";
        cin >> n ;
        
        cout << st1 << endl;

        for (int j=0; j<n; j++){
            cin >> a1;
            st2 = st1;
            if (st2[a1] != 'z') st2[a1]++;
            else st2[a1] = 'a';
            st1 = st2;
            cout << st1 << endl;
        }
    }

    return 0;
}