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

void bin_search(int arr[], int start, int end, int cows, int &max, int n)
{

    if (start <= end)
    {
        int mid = (end - start) / 2 + start;
        int cow_pointer = 0;
        int cows_left = cows - 1;
        fo(i, n)
        {
            if (arr[i] - arr[cow_pointer] >= mid)
            {
                cows_left--;
                cow_pointer = i;
            }
            if (cows_left == 0)
            {
                break;
            }
        }
        if (cows_left > 0)
        {
            end = mid - 1;
            bin_search(arr, start, end, cows, max, n);
        }
        else if (cows_left == 0)
        {
            max = mid;
            start = mid + 1;
            bin_search(arr, start, end, cows, max, n);
        }
    }
}
void solve()
{
    int n, cows;
    cin >> n >> cows;
    int arr[n];
    fo(i, n)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int max = 0;
    bin_search(arr, 0, arr[n - 1], cows, max, n);
    cout << max << endl;
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
