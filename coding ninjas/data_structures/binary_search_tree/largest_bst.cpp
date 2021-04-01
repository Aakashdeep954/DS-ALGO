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

binary_tree<int> *take_input()
{
    int root_data;
    cin >> root_data;
    if (root_data == -1)
    {
        return NULL;
    }
    binary_tree<int> *root = new binary_tree<int>(root_data);
    queue<binary_tree<int> *> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size() != 0)
    {
        binary_tree<int> *current_node = pending_nodes.front();
        pending_nodes.pop();
        int left_child, right_child;
        cin >> left_child;
        if (left_child != -1)
        {
            binary_tree<int> *left_node = new binary_tree<int>(left_child);
            current_node->left = left_node;
            pending_nodes.push(left_node);
        }
        cin >> right_child;
        if (right_child != -1)
        {
            binary_tree<int> *right_node = new binary_tree<int>(right_child);
            current_node->right = right_node;
            pending_nodes.push(right_node);
        }
    }
    return root;
}

class container
{
public:
    int min;
    int max;
    int height;
    bool is_bst;
    container(int min, int max, int height, bool is_bst)
    {
        this->min = min;
        this->max = max;
        this->height = height;
        this->is_bst = is_bst;
    }
};

container largest_bst(binary_tree<int> *root)
{
    container ans(INT_MAX, INT_MIN, 0, true);
    if (root == NULL)
    {
        return ans;
    }
    container left = largest_bst(root->left);
    container right = largest_bst(root->right);

    if (left.is_bst == false || right.is_bst == false || root->data < left.max || root->data > right.min)
    {
        ans.is_bst = false;
        ans.height = max(left.height, right.height);
        return ans;
    }
    ans.min = min(root->data, min(left.min, right.min));
    ans.max = max(root->data, max(left.max, right.max));
    ans.height = max(left.height, right.height) + 1;
    return ans;
}

void solve()
{
    binary_tree<int> *root = take_input();
    cout << largest_bst(root).height << endl;
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