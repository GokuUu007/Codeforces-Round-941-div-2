/* 

    ॐ हौं जूं सः ॐ भूर्भुवः स्वः 
    ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय मामृतात् 
    ॐ स्वः भुवः भूः ॐ सः जूं हौं ॐ

   @Author  : Akshat Madhavan
   @Country : INDIA 
   
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
#include "debug.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif


template<class T>void output (vector<T> &a) {for (auto &x : a) {cout << x << ' ';}cout << '\n';}
template<typename T> void chmin (T &a, T b) {if (a > b) swap(a, b);}
template<typename T> void chmax (T &a, T b) {if (a < b) swap(a, b);}



bool solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        for (int j = 0; j < m; ++j) {
            a[i][j] = s[j] == 'B';
        }
    }

    if (a[0][0] == a[n - 1][m - 1]) {
        return 1;
    }

    auto checkRow = [&] (int p, int c) ->bool {
        int ok = 0;
        for (int i = 0; i < m; ++i) {
            ok |= a[p][i] == c;
        }
        return ok;
    };

    auto checkCol = [&] (int p, int c) ->bool {
        int ok = 0;
        for (int i = 0; i < n; ++i) {
            ok |= a[i][p] == c;
        }
        return ok;
    };

    if ((checkRow(0, a[n - 1][m - 1]) && checkCol(0, a[n - 1][m - 1])) || (checkRow(n - 1, a[0][0]) && checkCol(m - 1, a[0][0]))) {
        return 1;
    }

    return 0;
} 


int32_t main() {
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE   
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);  
    #endif  

    int tc = 1;
    cin >> tc;
    for (int cases = 1; cases <= tc; ++cases) {
        // solve();
        cout << (solve() ? "YES\n" : "NO\n");
        // cout << "Case # " << cases;
    } 

    #ifndef ONLINE_JUDGE
        double timeTaken = 1000.0 * clock() / CLOCKS_PER_SEC;
        cout << "\n[Finished in " << timeTaken << "ms]";
        cerr << "\n[Finished in " << timeTaken << "ms]";
    #endif

    return 0;
}

//JAI SHREE RAM !!!!
