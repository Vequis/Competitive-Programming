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
    #define int long long
     
    using namespace std;
     
    signed main(){_
     
        int t;
        cin >> t;
     
        while(t--) {
            string s;
            cin >> s;
     
            vi v(sz(s) + 5);
     
            int tam = 0;
     
            int resp = 1;
     
            for (char c : s) {
                if (c == '+') {
                    if (tam == 0) v[tam] = 1;
                    else v[tam] = -1;
                    tam++;
                } else if (c=='-') {
                    tam--;
                    if (v[tam] == 1 and tam != 0) {
                        v[tam-1] = 1;
                    }
                } else if (c=='1') {
                    int it = tam-1;
                    while(v[it] == -1) {
                        it--;
                    }
     
                    if (v[it] == 0) resp = 0;
     
                    v[tam - 1] = 1;
                } else {
                    if (tam <= 1){
                        resp = 0;
                        continue;
                    } 
     
                    int it = tam - 1;
                    if (v[it] == 1) resp = 0;
                    v[it] = 0;
                }
     
                // for(int i = 0; i < tam; i++) cout << v[i];
                // cout << endl;
            }
     
            if(resp) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
     
        return 0;
    }