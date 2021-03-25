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

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Stack
{
    // Define the data members
    Node *head;
    int size;

public:
    Stack()
    {
        // Implement the Constructor
        head = NULL;
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function
        return size == 0;
    }

    void push(int element)
    {
        // Implement the push() function
        Node *newnode = new Node(element);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
        size++;
    }

    int pop()
    {
        // Implement the pop() function
        if (head == NULL)
        {
            return -1;
        }
        else
        {
            int data = head->data;
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
            return data;
        }
    }

    int top()
    {
        // Implement the top() function
        if (head == NULL)
        {
            return -1;
        }
        return head->data;
    }
};

void solve(Stack *st)
{
    int choice, input;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cin >> input;
        st->push(input);
        break;
    case 2:
        cout << st->pop() << "\n";
        break;
    case 3:
        cout << st->top() << "\n";
        break;
    case 4:
        cout << st->getSize() << "\n";
        break;
    default:
        cout << ((st->isEmpty()) ? "true\n" : "false\n");
        break;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Stack *st = new Stack();
    int q;
    cin >> q;
    while (q--)
    {
        solve(st);
    }
}
