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
class tree_node
{
public:
    T data;
    vector<tree_node<T> *> children;
    tree_node(T data)
    {
        this->data = data;
    }
    ~tree_node()
    {
        fo(i, children.size())
        {
            delete children[i];
        }
    }
};

tree_node<int> *take_input()
{
    int root_data;
    cin >> root_data;
    tree_node<int> *root = new tree_node<int>(root_data);
    queue<tree_node<int> *> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size() != 0)
    {
        tree_node<int> *front = pending_nodes.front();
        pending_nodes.pop();
        int number_of_children;
        cin >> number_of_children;
        fo(i, number_of_children)
        {
            int child_data;
            cin >> child_data;
            tree_node<int> *child = new tree_node<int>(child_data);
            front->children.push_back(child);
            pending_nodes.push(child);
        }
    }
    return root;
}

pair<tree_node<int> *, int> helper(tree_node<int> *root)
{
    if (root == NULL)
    {
        pair<tree_node<int> *, int> ans(NULL, 0);
        return ans;
    }
    int sum = root->data;
    fo(i, root->children.size())
    {
        sum += root->children[i]->data;
    }
    pair<tree_node<int> *, int> ans(root, sum);
    fo(i, root->children.size())
    {
        pair<tree_node<int> *, int> max_child_sum = helper(root->children[i]);
        if (ans.second < max_child_sum.second)
        {
            ans = max_child_sum;
        }
    }
    return ans;
}

tree_node<int> *max_sum_node(tree_node<int> *root)
{
    return helper(root).first;
}

void solve()
{
    tree_node<int> *root = take_input();
    tree_node<int> *ans = max_sum_node(root);
    if (ans != NULL)
    {
        cout << ans->data;
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