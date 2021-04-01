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
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int> *take_input()
{
    int root_data;
    cin >> root_data;
    if (root_data == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(root_data);
    queue<BinaryTreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size() != 0)
    {
        BinaryTreeNode<int> *current_node = pending_nodes.front();
        pending_nodes.pop();
        int left_child, right_child;
        cin >> left_child;
        if (left_child != -1)
        {
            BinaryTreeNode<int> *left_node = new BinaryTreeNode<int>(left_child);
            current_node->left = left_node;
            pending_nodes.push(left_node);
        }
        cin >> right_child;
        if (right_child != -1)
        {
            BinaryTreeNode<int> *right_node = new BinaryTreeNode<int>(right_child);
            current_node->right = right_node;
            pending_nodes.push(right_node);
        }
    }
    return root;
}

BinaryTreeNode<int> *helper(BinaryTreeNode<int> *root, int k_1, int k_2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == k_1 || root->data == k_2)
    {
        return root;
    }

    BinaryTreeNode<int> *left = helper(root->left, k_1, k_2);
    BinaryTreeNode<int> *right = helper(root->right, k_1, k_2);

    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    else if (left != NULL && right == NULL)
    {
        return left;
    }
    else if (right != NULL && left == NULL)
    {
        return right;
    }
    else
    {
        return root;
    }
}

int lca(BinaryTreeNode<int> *root, int k_1, int k_2)
{
    BinaryTreeNode<int> *ans = helper(root, k_1, k_2);
    if (ans == NULL)
    {
        return -1;
    }
    else
    {
        return ans->data;
    }
}

void solve()
{
    BinaryTreeNode<int> *root = take_input();
    int k_1, k_2;
    cin >> k_1 >> k_2;
    cout << lca(root, k_1, k_2) << endl;
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