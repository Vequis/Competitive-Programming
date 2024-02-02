#include <bits/stdc++.h>
#include <string.h>

using namespace std;

#define max 10000

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

    int n, t;
    cin >> n >> t;

    int cont = 0;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a; 
        if (a + t <= 5 ) {
            cont++;
        }
    }

    cout << (cont/3) << endl;

  return 0;
}