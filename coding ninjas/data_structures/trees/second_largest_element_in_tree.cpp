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
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        fo(i, children.size())
        {
            delete children[i];
        }
    }
};

TreeNode<int> *take_input()
{
    int root_data;
    cin >> root_data;
    TreeNode<int> *root = new TreeNode<int>(root_data);
    queue<TreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size() != 0)
    {
        TreeNode<int> *front = pending_nodes.front();
        pending_nodes.pop();
        int number_of_children;
        cin >> number_of_children;
        fo(i, number_of_children)
        {
            int child_data;
            cin >> child_data;
            TreeNode<int> *child = new TreeNode<int>(child_data);
            front->children.push_back(child);
            pending_nodes.push(child);
        }
    }
    return root;
}

pair<TreeNode<int> *, TreeNode<int> *> helper(TreeNode<int> *root)
{
    pair<TreeNode<int> *, TreeNode<int> *> ans(root, NULL);
    fo(i, root->children.size())
    {
        pair<TreeNode<int> *, TreeNode<int> *> child_ans = helper(root->children[i]);
        if (ans.first->data < child_ans.first->data)
        {
            ans.second = ans.first;
            ans.first = child_ans.first;
            if (child_ans.second!=NULL && ans.second->data < child_ans.second->data)
            {
                ans.second = child_ans.second;
            }
        }
        else if (ans.first->data > child_ans.first->data)
        {
            if(ans.second==NULL || child_ans.first->data > ans.second->data){
                ans.second=child_ans.first;
            }
        }
        else
        {
            if(ans.second==NULL){
                if(child_ans.second!=NULL){
                    ans.second=child_ans.second;
                }
            }   
            else if (child_ans.second !=NULL && child_ans.second->data > ans.second->data)
            {
                ans.second = child_ans.second;
            }
        }
    }
    return ans;
}

TreeNode<int> *second_largest_element(TreeNode<int> *root)
{
    return helper(root).second;
}

void solve()
{
    TreeNode<int> *root = take_input();
    TreeNode<int> *ans = second_largest_element(root);
    if (ans != NULL)
    {
        cout << ans->data << endl;
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