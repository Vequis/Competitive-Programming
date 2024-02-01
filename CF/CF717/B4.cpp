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
     
    int t, n;
    vi v;
    int var, prov;
     
    int main(){_
     
        cin >> t;
        while(t--){
            cin >> n;
            v = vi(n+1);
        
            for (int i=0; i<n; i++){
                cin >> v[i];
            }

            var = 0;
            for (int i=n-1; i>=1; i--){
                var = var^v[i];
                prov = var;
                for (int j=0; j<=i-1; j++){
                    prov = prov^v[j];
                    if (prov==0 and j!=i-1){
                        prov = var;
                    }
                }

                if (prov==0){
                    cout << "YES" << endl;
                    break;
                }

                if(i==1){
                    cout << "NO" << endl;
                }
            }

            v.clear();
        }
     
     
     
        return 0;
    }