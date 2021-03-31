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
template <typename T>
class binary_tree
{
public:
    T data;
    binary_tree<T> *left;
    binary_tree<T> *right;
    binary_tree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

binary_tree<int>* construct_bst(int arr[], int start, int end){
    if(start>end){
        return NULL;
    }
    int middle = (start + end)/2;
    binary_tree<int>* root = new binary_tree<int>(arr[middle]);
    root->left=construct_bst(arr,start,middle-1);
    root->right = construct_bst(arr,middle+1,end);
    return root;
}

void pre_order(binary_tree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
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
    binary_tree<int> *root = construct_bst(arr, 0, n-1);
    pre_order(root);
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