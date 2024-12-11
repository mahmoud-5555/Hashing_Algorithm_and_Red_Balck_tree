#include <iostream>
#include <random>
using namespace std;

template <typename T>
class SkipListNode
{
private:
    int levelCount;
    SkipListNode<T> **forward;

public:
    T value;
    int getLevelCount()
    {
        return levelCount;
    }
    SkipListNode(T value, int levelCount)
    {
        forward = new SkipListNode<T> *[levelCount];
        this->levelCount = levelCount;
        this->value = value;
    }
    SkipListNode<T> *next(int level = 0)
    {
        if (level < 0 || level >= levelCount)
        {
            throw out_of_range("Level is out of valid range.");
        }
        return forward[level];
    }
    void insertAfter(SkipListNode<T> *newNode, int level)
    {
        if (level < 0 || level >= levelCount || level >= newNode->levelCount)
        {
            throw out_of_range("Level is out of valid range.");
        }
        newNode->forward[level] = forward[level];
        forward[level] = newNode;
    }
    void setNext(SkipListNode<T> *next, int level)
    {
        if (level < 0 || level >= levelCount)
        {
            throw out_of_range("Level is out of valid range.");
        }
        forward[level] = next;
    }
    operator T() const
    {
        return value;
    }
    ~SkipListNode()
    {
        delete[] forward;
    }
};
template <typename T>
struct SkipListHeadNode
{
    SkipListNode<T> *node = nullptr;
    SkipListHeadNode<T> *nextLevelHead = nullptr;
    SkipListHeadNode<T> *prevLevelHead = nullptr;
};
template <typename T>
class SkipListHead
{
    int levelCount = 1;
    SkipListHeadNode<T> head;
    SkipListHeadNode<T> *last;
    void addLevel()
    {
        levelCount++;
        last->nextLevelHead = new SkipListHeadNode<T>();
        last->nextLevelHead->prevLevelHead = last;
        last = last->nextLevelHead;
    }
    SkipListHeadNode<T> *getLevel(int level)
    {
        if (level >= levelCount || level < 0)
        {
            throw out_of_range("Level is out of valid range.");
        }
        int currentLevel = 0;
        SkipListHeadNode<T> *current = &head;
        while (currentLevel < level)
        {
            currentLevel++;
            current = current->nextLevelHead;
        }
        return current;
    }
    void ensureLevelExist(int level)
    {
        while (this->levelCount <= level)
        {
            addLevel();
        }
    }

public:
    int getLevelCount()
    {
        return levelCount;
    }
    SkipListHeadNode<T> *getFirstLevelHead()
    {
        return &head;
    }
    SkipListHeadNode<T> *getLastLevelHead()
    {
        return last;
    }
    SkipListHeadNode<T> *insertToHead(SkipListNode<T> *node, int &level)
    {
        level = node->getLevelCount() - 1;
        ensureLevelExist(level);
        SkipListHeadNode<T> *h = getLevel(level);
        while (h && (!h->node || h->node->value > node->value))
        {
            node->setNext(h->node, level);
            h->node = node;
            level--;
            h = h->prevLevelHead;
        }
        return h;
    }
    SkipListHeadNode<T> *getSearchHead(T value, int &level, bool printPath = false)
    {
        level = levelCount - 1;
        SkipListHeadNode<T> *searchHead = last;
        while (searchHead && (!searchHead->node || searchHead->node->value > value))
        {
            if (printPath)
            {
                cout << "Level: " << level << ", next: ";
                if (searchHead->node)
                {
                    cout << *(searchHead->node) << endl;
                }
                else
                {
                    cout << "Null" << endl;
                }
            }

            level--;
            searchHead = searchHead->prevLevelHead;
        }
        return searchHead;
    }
    SkipListHead()
    {
        last = &head;
    }
    ~SkipListHead()
    {
        SkipListHeadNode<T> *current = head.nextLevelHead;
        while (current)
        {
            SkipListHeadNode<T> *temp = current->nextLevelHead;
            delete current;
            current = temp;
        }
    }
};

template <typename T>
class SkipList
{
private:
    int count = 0;
    SkipListHead<T> head;
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<> distr;
    bool shouldGoUp()
    {
        return distr(gen) > 500;
    }
    int getRandomLevelCount()
    {
        int levelCount = 1;
        while (shouldGoUp())
        {
            levelCount++;
        }
        return levelCount;
    }

public:
    SkipListNode<T> *find(T value, bool printPath = false)
    {
        int searchLevel;
        SkipListHeadNode<T> *searchHead = head.getSearchHead(value, searchLevel, printPath);
        if (!searchHead || searchLevel < 0)
        {
            return nullptr;
        }
        SkipListNode<T> *searchNode = searchHead->node;
        while (searchNode && searchLevel >= 0)
        {

            const int maxSearchLevel = searchNode->getLevelCount() - 1;
            searchLevel = maxSearchLevel < searchLevel ? maxSearchLevel : searchLevel;
            SkipListNode<T> *next = searchNode->next(searchLevel);
            if (printPath)
            {
                cout << "Level: " << searchLevel << ", visiting: " << *searchNode << endl;
                cout << "Level: " << searchLevel << ", next: ";
                if (next)
                {
                    cout << *next << endl;
                }
                else
                {
                    cout << "Null" << endl;
                }
            }
            if (*searchNode == value)
            {
                return searchNode;
            }
            else if (searchLevel == 0 && next && *next > value)
            {
                return nullptr;
            }
            while ((searchLevel > 0) && (!next || *next > value))
            {
                searchLevel--;
                next = searchNode->next(searchLevel);
                if (printPath)
                {
                    if (next)
                    {
                        cout << "Level: " << searchLevel << ", next: " << *next << endl;
                    }
                    else
                    {
                        cout << "Level: " << searchLevel << ", next: Null" << endl;
                    }
                }
            }
            searchNode = next;
        }

        return nullptr;
    }
    void printPathTo(T value)
    {
        cout << "Searching for " << value << ":" << endl;
        SkipListNode<T> *r = find(value, true);
        if (r)
        {
            cout << value << " found as " << *r << endl;
        }
        else
        {
            cout << value << " not found!" << endl;
        }
    }

    int getCount()
    {
        return count;
    }
    SkipListNode<T> *insert(T value)
    {
        if (find(value))
        {
            return nullptr;
        }

        count++;
        const int levelCount = getRandomLevelCount();
        int level = levelCount - 1;
        SkipListNode<T> *node = new SkipListNode(value, levelCount);
        SkipListHeadNode<T> *insertionHead = head.insertToHead(node, level);
        if (!insertionHead)
        {
            return node;
        }
        SkipListNode<T> *searchNode = insertionHead->node;
        while (searchNode && (level >= 0))
        {
            while (searchNode->next(level) && searchNode->next(level)->value <= value)
            {
                searchNode = searchNode->next(level);
            }

            while ((level >= 0) && (!searchNode->next(level) || searchNode->next(level)->value > value))
            {
                searchNode->insertAfter(node, level);
                level--;
            }
        }
        return node;
    }
    void print()
    {
        if (count == 0)
        {
            cout << "Skip list is empty." << endl
                 << endl;
            return;
        }

        SkipListHeadNode<T> *currentHead = head.getLastLevelHead();
        int level = head.getLevelCount() - 1;

        while (currentHead)
        {
            cout << "Level " << level << ": ";

            SkipListNode<T> *node = currentHead->node;

            while (node)
            {
                cout << *node << " ";
                node = node->next(level); // Move to the next node at this level
            }

            cout << endl;

            // Move to the next lower level
            currentHead = currentHead->prevLevelHead;
            level--;
        }
        cout << endl;
    }
    SkipList() : gen(rd()), distr(1, 1000) {}
    ~SkipList()
    {
        SkipListNode<T> *node = head.getFirstLevelHead()->node;
        while (node)
        {
            SkipListNode<T> *temp = node->next();
            delete node;
            node = temp;
        }
    }
};

int main()
{
    cout << "Skip List: " << endl;
    SkipList<int> skipList;
    bool run = true;
    while (run)
    {
        cout << "current skip list:" << endl;
        skipList.print();
        cout << "Select action:" << endl;
        cout << "1. Insert:" << endl;
        cout << "2. Delete:" << endl;
        cout << "3. find:" << endl;
        cout << "4. Exit:" << endl;
        int selection;
        cin >> selection;
        switch (selection)
        {
        case 1:
        {
            int number;
            cout << "Enter a number to insert to skip list: ";
            cin >> number;
            SkipListNode<int> *r = skipList.insert(number);
            if (r)
            {
                if (r->next())
                {
                    cout << *r << " inserted before: " << *(r->next()) << endl;
                }
                else
                {

                    cout << *r << " inserted at end of list" << endl;
                }
            }
            else
            {
                cout << number << " alread exists in list!" << endl;
            }
        }
        break;
        case 3:
        {
            int number;
            cout << "Enter a number to search for: ";
            cin >> number;
            skipList.printPathTo(number);
        }
        break;
        case 4:
            run = false;
            break;
        default:
            cout << "Invalid selection (" << selection << ")!" << endl;
            break;
        }
    }
}