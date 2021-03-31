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

void insert_duplicate_node(binary_tree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    insert_duplicate_node(root->left);
    binary_tree<int> *new_node = new binary_tree<int>(root->data);
    new_node->left = root->left;
    root->left = new_node;
    insert_duplicate_node(root->right);
}

void level_order(binary_tree<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<binary_tree<int> *> pending_nodes;
    pending_nodes.push(root);
    pending_nodes.push(NULL);
    while (pending_nodes.size() != 0)
    {
        binary_tree<int> *front = pending_nodes.front();
        pending_nodes.pop();
        if (front != NULL && front->left != NULL)
        {
            pending_nodes.push(front->left);
        }
        if (front != NULL && front->right != NULL)
        {
            pending_nodes.push(front->right);
        }
        if (front == NULL)
        {
            cout << endl;
            if (pending_nodes.size() != 0)
            {
                pending_nodes.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
        }
    }
}

void solve()
{
    binary_tree<int> *root = take_input();
    insert_duplicate_node(root);
    level_order(root);
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