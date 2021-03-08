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

void merge(ll arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    ll left[n1], right[n2];
    fo(i, n1)
    {
        left[i] = arr[start + i];
    }
    fo(j, n2)
    {
        right[j] = arr[mid + 1 + j];
    }
    int left_index = 0;
    int right_index = 0;
    int merge_index = start;
    while (left_index < n1 && right_index < n2)
    {
        if (left[left_index] <= right[right_index])
        {
            arr[merge_index++] = left[left_index++];
        }
        else
        {
            arr[merge_index++] = right[right_index++];
        }
    }
    while (left_index < n1)
    {
        arr[merge_index++] = left[left_index++];
    }
    while (right_index < n2)
    {
        arr[merge_index++] = right[right_index++];
    }
}
void partition(ll arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (end - start) / 2 + start;
    partition(arr, start, mid);
    partition(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
void solve()
{
    int n;
    cin >> n;
    ll arr[n];
    fo(i, n)
    {
        cin >> arr[i];
    }
    partition(arr, 0, n - 1);
    fo(i, n)
    {
        cout << arr[i] << " ";
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