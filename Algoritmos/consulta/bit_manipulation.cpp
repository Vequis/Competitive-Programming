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
#define int long long // -> solução divina

using namespace std;

// ALL FROM CPH https://cses.fi/book/book.pdf

signed main(){_

    // REPRESENTAÇÕES
    int a = 0b1011; // 11 -> 0x0B
        // Leading zeros não influenciam
    cout << "a: " << a << endl; // imprime 11
    cout << "a em binario: " << bitset<16>(a) << endl;

    int b = 0b0101;
    int result;

    // OPERAÇÕES
    result = a;
    result |= b; // OR
    result &= b; // AND
    result ^= b; // XOR

    // CONFERIR PARIDADE
    result = a&1; // == 0 se for par
    result = a&((1<<3)-1); // conferir se e div por 2^k

    // COMPLEMENTO 2
    int a_complement_2 = ~a + 1;
    cout << "Complemento de 2 de a: " << a_complement_2 << endl;

    a = 24;
    // SET SINGLE BITS
    result = a | (1 << 4); // set 4-th bit to 1
    result = a & ~(1 << 4); // set 4-th bit to 0
    result = a & (a-1); // set last one bit of x to 0  
    result = a & -a; // set all one bit of x to 0, except the last one bit  
    result = a | (a-1); // fill all zeroes after 1


    // ADDITIONAL FUNCTIONS
    int x = 5328; // 00000000000000000001010011010000
    cout << __builtin_clzll(x) << "\n"; // 19 or 51(ll) - count leading zeros
    cout << __builtin_ctzll(x) << "\n"; // 4 - count trailing zeros
    cout << __builtin_popcountll(x) << "\n"; // 5 - number of bits = 1
    cout << __builtin_parityll(x) << "\n"; // 1 - the parity of numbers of 1
    cout << endl;

    // SUBSETS
    // Represent if a number between 0 and n-1 with a set-bit in i-th lsb
    // a & b - intersection
    // a | b - union A U B
    // ~a - which elements are not in A
    // A \ B - a & ~b

    // y represents all subsets of X
    int y = 0;
    int xk = 0b01100110;
    cout << xk << endl;
    do {
        cout << y << endl;
    } while (y=(y-xk)&xk);

    // HAMMING
    result = __builtin_popcount(a xor b);
    // 27x faster than passing through the whole stirng

    // cout << bitset<5>(a) << endl;
    // cout << bitset<5>(a-1) << endl;
    // cout << bitset<5>(result) << endl;


    return 0;
}