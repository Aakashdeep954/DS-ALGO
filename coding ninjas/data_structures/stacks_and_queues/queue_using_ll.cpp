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

class Queue
{
    // Define the data members
    Node *head;
    Node *tail;
    int size;

public:
    Queue()
    {
        // Implement the Constructor
        head = NULL;
        tail = NULL;
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

    void enqueue(int data)
    {
        // Implement the enqueue() function
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        size++;
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (head == NULL)
        {
            return -1;
        }
        int data = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return data;
    }

    int front()
    {
        // Implement the front() function
        if (head == NULL)
        {
            return -1;
        }
        return head->data;
    }
};

void solve(Queue *q)
{
    int choice, input;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cin >> input;
        q->enqueue(input);
        break;
    case 2:
        cout << q->dequeue() << "\n";
        break;
    case 3:
        cout << q->front() << "\n";
        break;
    case 4:
        cout << q->getSize() << "\n";
        break;
    default:
        cout << ((q->isEmpty()) ? "true\n" : "false\n");
        break;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Queue *q = new Queue();
    int t;
    cin >> t;
    while (t--)
    {
        solve(q);
    }
}