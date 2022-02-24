#include <iostream>
#include <set>

using namespace std;

class Node
{
private:
    int key; // value as key
    Node *pLeft;
    Node *pRight;

public:
    Node(int key) : key(key), pLeft(nullptr), pRight(nullptr) {}

    int GetKey() const { return key; }

    Node *GetLeft() const { return pLeft; }
    Node *GetRight() const { return pRight; }

    void SetLeft(Node *node) { pLeft = node; }
    void SetRight(Node *node) { pRight = node; }
};

class BST
{
private:
    Node *root;

    void Delete(Node *root)
    {
        if (root)
        {
            Delete(root->GetLeft());
            Delete(root->GetRight());
            delete root;
        }
    }

public:
    BST() : root(nullptr) {}
    ~BST() { Delete(root); }
    void Add(int key)
    {
        if (root == nullptr)
        {
            root = new Node(key);
            return;
        }

        Node *search = root, *prev_search = nullptr;
        while (search)
        {
            prev_search = search;
            if (key > search->GetKey())
                search = search->GetRight();
            else if (key < search->GetKey())
                search = search->GetLeft();
            else
                return;
        }
        Node *new_node = new Node(key);
        if (key > prev_search->GetKey())
            prev_search->SetRight(new_node);
        else
            prev_search->SetLeft(new_node);
    }

    bool Find(int key) const
    {
        Node *search = root;
        while (search)
        {
            if (key > search->GetKey())
                search = search->GetRight();
            else if (key < search->GetKey())
                search = search->GetLeft();
            else
                return true;
        }
        return false;
    }
};

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M, temp;
    set<int> s;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        s.insert(temp);
    }

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> temp;
        cout << (s.find(temp) != s.end()) << '\n';
    }
}