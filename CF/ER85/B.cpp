#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t;

    int v[100005];
    vector<int> resp;

    int t2 = t;

    while(t--) {
        int n,x;
        cin >> n >> x;

        double soma=0;

        for (int i=0; i<n; i++){
            cin >> v[i];
            soma+=v[i];
        }

        sort (v, v+n);

        double media;

        bool ok=false;

        for (int i=0; i<n; i++){
            float k = n-i;
            media = soma/k;
            if (media>=x){
                resp.push_back(n-i);
                ok = true;
                break;
            } else {
                soma-=v[i];
            }
        }
        if (!ok) {
            resp.push_back(0);
        }
    }

    for (int i=0; i<t2;i++){
        cout << resp[i] << endl;
    }
    return 0;

}
