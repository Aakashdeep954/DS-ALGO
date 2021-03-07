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

void bin_search(ll start, ll end, int n, ll arr[], ll &max_candy, ll k)
{
    if (start <= end)
    {
        ll mid = (start + end) / 2;
        ll count = 0;
        fo(i, n)
        {
            count += arr[i] / mid;
        }
        if (count >= k)
        {
            max_candy = mid;
            start = mid + 1;
            bin_search(start, end, n, arr, max_candy, k);
        }
        else
        {
            end = mid - 1;
            bin_search(start, end, n, arr, max_candy, k);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    ll k;
    cin >> k;
    ll arr[n];
    ll sum = 0;
    fo(i, n)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    ll candy_div = sum / k;
    ll max_candy = 0;
    bin_search(1, candy_div, n, arr, max_candy, k);
    cout << max_candy << endl;
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