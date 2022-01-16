#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
    int *q;
    int front;
    int rear;
    unsigned int size;
    unsigned int reserved;

    void Reserve(unsigned int new_reserved)
    {
        int *temp = q;
        q = new int[new_reserved];
        for (int i = 0; i < size && i < new_reserved; ++i)
            q[i] = temp[(front + i) % reserved];
        size = new_reserved < size ? new_reserved : size;
        front = 0;
        rear = new_reserved < size ? front : size;
        reserved = new_reserved;
        delete[] temp;
    }

public:
    Queue() : front(0), rear(0), size(0), reserved(10) { q = new int[reserved]; }
    ~Queue() { delete[] q; }

    void Push(int d)
    {
        if (size == reserved)
            Reserve(reserved * 2);
        q[(rear++) % reserved] = d;
        ++size;
    }

    int Pop()
    {
        if (Empty())
            return -1;
        --size;
        int tmp = q[front];
        front = (front + 1) % reserved;
        return tmp;
    }

    int Front()
    {
        if (Empty())
            return -1;
        return q[front];
    }

    int Back()
    {
        if (Empty())
            return -1;
        if (rear == 0)
            return q[reserved - 1];
        return q[(rear - 1) % reserved];
    }

    unsigned int Size() { return size; }
    bool Empty() { return size == 0; }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Queue q;
    int N;
    cin >> N;
    while (N)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "push")
        {
            int d;
            cin >> d;
            q.Push(d);
        }
        else if (cmd == "pop")
            cout << q.Pop() << '\n';
        else if (cmd == "size")
            cout << q.Size() << '\n';
        else if (cmd == "empty")
            cout << q.Empty() << '\n';
        else if (cmd == "front")
            cout << q.Front() << '\n';
        else if (cmd == "back")
            cout << q.Back() << '\n';
        --N;
    }
}