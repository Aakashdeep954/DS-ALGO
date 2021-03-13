#include <bits/stdc++.h>
using namespace std;
#define fo(i, c) for (int(i) = 0; (i) < (c); (i)++)
#define go(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define gc getchar_unlocked
#define ll long long int
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626

//---------------------------------------pair----------------------------------------------------//
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<int, string> pistr;
//---------------------------------------pair----------------------------------------------------//

//--------------------------------------vector---------------------------------------------------//
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<vl> vvl;

typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

typedef vector<string> vstr;
typedef vector<pistr> vpistr;
typedef vector<vstr> vvstr;
//---------------------------------------vector---------------------------------------------------//

//------------------------------------unordered_map-----------------------------------------------//
typedef unordered_map<int, int> umapii;
typedef unordered_map<ll, ll> umapll;
typedef unordered_map<int, vi> umapivi;

typedef unordered_map<string, int> umapstri;
typedef unordered_map<int, string> umapistr;
//------------------------------------unordered_map-----------------------------------------------//

//----------------------------------------map-----------------------------------------------------//
typedef map<int, int> mapii;
typedef map<ll, ll> mapll;
//----------------------------------------map-----------------------------------------------------//

//----------------------------------------set-----------------------------------------------------//
typedef set<int> sei;
typedef set<ll> sel;
//----------------------------------------set-----------------------------------------------------//

//----------------------------------execution time------------------------------------------------//
#define EXT cout << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl
//----------------------------------execution time------------------------------------------------//

bool is_safe(int **arr, int x, int y, int n)
{
    return x >= 0 && x < n && y >= 0 && y < n && arr[x][y];
}
void rat_in_a_maze(int **arr, int x, int y, int n, int **sol, int **visited)
{
    if (x == n - 1 && y == n - 1)
    {
        sol[x][y] = 1;
        fo(row, n)
        {
            fo(col, n)
            {
                cout << sol[row][col] << " ";
            }
            
        }
        cout << endl;
        
    }
    visited[x][y] = 1;
    sol[x][y] = 1;
    if (is_safe(arr, x + 1, y, n) && visited[x + 1][y] == 0)
    {
        rat_in_a_maze(arr, x + 1, y, n, sol, visited);
    }
    if (is_safe(arr, x, y + 1, n) && visited[x][y + 1] == 0)
    {
        rat_in_a_maze(arr, x, y + 1, n, sol, visited);
    }
    if (is_safe(arr, x - 1, y, n) && visited[x - 1][y] == 0)
    {
        rat_in_a_maze(arr, x - 1, y, n, sol, visited);
    }
    if (is_safe(arr, x, y - 1, n) && visited[x][y - 1] == 0)
    {
        rat_in_a_maze(arr, x, y - 1, n, sol, visited);
    }
    visited[x][y] = 0;
    sol[x][y] = 0;
}
void solve()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    fo(row, n)
    {
        arr[row] = new int[n];
        fo(col, n)
        {
            cin >> arr[row][col];
        }
    }
    int **sol = new int *[n];
    fo(row, n)
    {
        sol[row] = new int[n];
        fo(col, n)
        {
            sol[row][col] = 0;
        }
    }
    sol[0][0]=1;
    int **visited = new int *[n];
    fo(row, n)
    {
        visited[row] = new int[n];
        fo(col, n)
        {
            visited[row][col] = 0;
        }
    }
    rat_in_a_maze(arr, 0, 0, n, sol, visited);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}