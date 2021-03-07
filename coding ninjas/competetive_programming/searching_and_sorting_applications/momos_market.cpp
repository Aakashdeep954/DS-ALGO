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
typedef string str;

//---------------------------------------pair----------------------------------------------------//
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<int, str> pistr;
//---------------------------------------pair----------------------------------------------------//

//--------------------------------------vector---------------------------------------------------//
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<vl> vvl;

typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

typedef vector<str> vstr;
typedef vector<pistr> vpistr;
typedef vector<vstr> vvstr;
//---------------------------------------vector---------------------------------------------------//

//------------------------------------unordered_map-----------------------------------------------//
typedef unordered_map<int, int> umapii;
typedef unordered_map<ll, ll> umapll;
typedef unordered_map<int, vi> umapivi;

typedef unordered_map<str, int> umapstri;
typedef unordered_map<int, str> umapistr;
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

int bin_search(int arr[], ll x, int start, int end)
{
    int index = -1;
    if (start <= end)
    {
        int mid = (start + end) / 2;
        if (x == arr[mid])
        {
            return mid;
        }
        else if (mid > 0 && x > arr[mid - 1] && x < arr[mid])
        {
            return mid - 1;
        }
        else if (arr[mid] < x)
        {
            index = bin_search(arr, x, mid + 1, end);
        }
        else if (arr[mid] > x)
        {
            index = bin_search(arr, x, start, mid - 1);
        }
    }

    return index;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    fo(i, n)
    {
        cin >> arr[i];
    }
    go(i, 1, n)
    {
        arr[i] += arr[i - 1];
    }
    int q;
    cin >> q;
    fo(i, q)
    {
        ll x;
        cin >> x;
        int index = bin_search(arr, x, 0, n - 1);
        if (index != -1)
        {
            cout << index + 1 << " " << x - arr[index] << endl;
        }
        else
        {
            cout << "0"
                 << " " << x << endl;
        }
    }
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