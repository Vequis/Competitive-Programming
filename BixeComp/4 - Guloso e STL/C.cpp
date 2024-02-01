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
    // #define int long long -> solução divina?

    using namespace std;

    priority_queue<ii, vii, greater<ii> > pq;

    int t, n;
    int a,b, resp, fim;

    int main(){_

        cin >> t;

        while(t--){
            cin >> n;

            for (int i=0; i<n; i++){
                cin >> a >> b;
                pq.push({a,b});
            }   

            resp = 0;
            fim = 0;

            for (int i=0; i<n; i++){
                ii par = pq.top();
                pq.pop();

                // cout << i << ' ' <<  par.fs << ' ' << par.sc << endl;

                if (par.fs >= fim) {
                    resp++;
                    fim = par.sc;
                } else {
                    if (par.sc < fim){
                        fim = par.sc;
                    }
                }
            }

            cout << resp << endl;
        }

        return 0;
    }