#include <iostream>
using namespace std;

template <typename T>
class SkipListNode
{
public:
    int levelCount;
    SkipListNode<T> **forward;
    T value;
    SkipListNode(T value, int levelCount)
    {
        forward = new SkipListNode<T> *[levelCount];
        this->levelCount = levelCount;
    }
    SkipListNode<T> *next()
    {
        return forward[0];
    }
    ~SkipListNode()
    {
        delete[] forward;
    }
};

template <typename T>
class SkipList
{
private:
    SkipListNode<T> *head;

public:
    ~SkipList()
    {
        SkipListNode<T> *node = head;
        while (node)
        {
            SkipListNode<T> temp = node->next;
            delete node;
            node = temp;
        }
    }
};

int main()
{
    cout << "H";
}