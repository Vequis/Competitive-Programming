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
int n, k;

int vazias(int inter){
    if (inter <= 0){
        return 0;
    }
    else if (inter==1){
        return 1; 
    } else if (inter ==2 and k == 0){
        return 2;
    } else {
        int var = inter;
        return vazias(var-k-1) +1;
    }
}

int main(int argc, const char * argv[]) {

    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    for (int i=0; i<t ;i++){
        cin >> n >> k;

        string s;
        cin >> s;

        int dist;
        int cont = 0;
        int atual = -1;
        bool primeiro = true;
        for (int j=0; j<n; j++){
            if (s[j] == '1'){
                dist = j-atual-1;
                if (atual == -1){
                    cont+=vazias(dist-k);
                    primeiro = false;
                } else {
                    cont+=vazias(dist-2*k);
                }

                atual = j;
            }
        }

        dist = n-atual-1;

        if (primeiro) cont+=vazias(dist);
        else cont+=vazias(dist-k);

        cout << cont << endl;
    }

	return 0;
}
