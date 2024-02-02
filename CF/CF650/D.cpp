#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>


int max1 = 1e9;

using namespace std;

bool ordem(pair<int,char> a, pair<int,char> b){
    return a.first > b.first;
}

int main(int argc, const char * argv[]) {

    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(NULL);
        
    int t;
    cin >> t;

    for (int i=0; i<t; i++){
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        pair<int,char> vetor[26];
        for (int j=0; j<n; j++){
            int a = s[j] - 'a';
            vetor[a].first++;
        }

        sort(vetor, vetor+n, ordem);

        string aux;
        while(true){
            if (n%k!=0 and k%n!=0) {
                n--;
                continue;
            }

            if (k>=n){
                cout << n << endl;
                break;
            } else {
                int cont = 0;
                int fator = n/k;
                for (int j=0; j<26; j++){
                    if (vetor[j].first < fator){break;}
                    else {
                        cont += (vetor[j].first)/fator;
                    }
                    if (cont>=k) break;
                }

                // cout << cont << endl;
                // cout << "CONT ^^ " << endl;

                // cout << n << " " <<  k << endl;

                if (cont>=k){
                    // cout << "AQUI O " << endl;
                    cout << n << endl;
                    break;
                } else n--;
            }
        }
    }

	return 0;
}
