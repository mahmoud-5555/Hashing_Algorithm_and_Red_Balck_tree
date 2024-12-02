#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T value;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;
    bool isRed = true;
};

template <class T>
class RedBlackTree
{
    Node<T> *root = nullptr;

    void replaceNode(Node<T> *oldNode, Node<T> *newNode)
    {
        if (oldNode == root)
            root = newNode;
        else if (oldNode == oldNode->parent->left)
            oldNode->parent->left = newNode;
        else
            oldNode->parent->right = newNode;

        if (newNode != nullptr)
            newNode->parent = oldNode->parent;
    }

    Node<T> *getMinimum(Node<T> *node)
    {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    void FixDelete(Node<T> *node)
    {
        while (node != root && (node == nullptr || !node->isRed))
        {
            if (node == node->parent->left)
            {
                Node<T> *sibling = node->parent->right;

                if (sibling != nullptr && sibling->isRed)
                {
                    sibling->isRed = false;
                    node->parent->isRed = true;
                    leftRotate(node->parent);
                    sibling = node->parent->right;
                }

                if ((sibling->left == nullptr || !sibling->left->isRed) && (sibling->right == nullptr || !sibling->right->isRed))
                {
                    sibling->isRed = true;
                    node = node->parent;
                }
                else
                {
                    if (sibling->right == nullptr || !sibling->right->isRed)
                    {
                        sibling->left->isRed = false;
                        sibling->isRed = true;
                        rightRotate(sibling);
                        sibling = node->parent->right;
                    }

                    sibling->isRed = node->parent->isRed;
                    node->parent->isRed = false;

                    if (sibling->right != nullptr)
                        sibling->right->isRed = false;

                    leftRotate(node->parent);
                    node = root;
                }
            }
            else
            {
                Node<T> *sibling = node->parent->left;

                if (sibling != nullptr && sibling->isRed)
                {
                    sibling->isRed = false;
                    node->parent->isRed = true;
                    rightRotate(node->parent);
                    sibling = node->parent->left;
                }

                if ((sibling->right == nullptr || !sibling->right->isRed) &&
                    (sibling->left == nullptr || !sibling->left->isRed))
                {
                    sibling->isRed = true;
                    node = node->parent;
                }
                else
                {
                    if (sibling->left == nullptr || !sibling->left->isRed)
                    {
                        if (sibling->right != nullptr)
                            sibling->right->isRed = false;

                        sibling->isRed = true;
                        leftRotate(sibling);
                        sibling = node->parent->left;
                    }

                    sibling->isRed = node->parent->isRed;
                    node->parent->isRed = false;

                    if (sibling->left != nullptr)
                        sibling->left->isRed = false;

                    rightRotate(node->parent);
                    node = root;
                }
            }
        }

        if (node != nullptr)
            node->isRed = false;
    }

    void leftRotate(Node<T> *node)
    {
        Node<T> *newParent = node->right;
        node->right = newParent->left;

        if (newParent->left != nullptr)
            newParent->left->parent = node;

        newParent->parent = node->parent;

        if (node->parent == nullptr)
            root = newParent;
        else if (node == node->parent->left)
            node->parent->left = newParent;
        else
            node->parent->right = newParent;

        newParent->left = node;
        node->parent = newParent;
    }

    void rightRotate(Node<T> *node)
    {
        Node<T> *newParent = node->left;
        node->left = newParent->right;

        if (newParent->right != nullptr)
            newParent->right->parent = node;

        newParent->parent = node->parent;

        if (node->parent == nullptr)
            root = newParent;
        else if (node == node->parent->left)
            node->parent->left = newParent;
        else
            node->parent->right = newParent;

        newParent->right = node;
        node->parent = newParent;
    }

    void FixInsert(Node<T> *node)
    {
        while (node != root && node->parent->isRed)
        {
            if (node->parent == node->parent->parent->left)
            {
                Node<T> *uncle = node->parent->parent->right;
                if (uncle != nullptr && uncle->isRed)
                {
                    node->parent->isRed = false;
                    uncle->isRed = false;
                    node->parent->parent->isRed = true;
                    node = node->parent->parent;
                }
                else
                {
                    if (node == node->parent->right)
                    {
                        node = node->parent;
                        leftRotate(node);
                    }
                    node->parent->isRed = false;
                    node->parent->parent->isRed = true;
                    rightRotate(node->parent->parent);
                }
            }
            else
            {
                Node<T> *uncle = node->parent->parent->left;
                if (uncle != nullptr && uncle->isRed)
                {
                    node->parent->isRed = false;
                    uncle->isRed = false;
                    node->parent->parent->isRed = true;
                    node = node->parent->parent;
                }
                else
                {
                    if (node == node->parent->left)
                    {
                        node = node->parent;
                        rightRotate(node);
                    }
                    node->parent->isRed = false;
                    node->parent->parent->isRed = true;
                    leftRotate(node->parent->parent);
                }
            }
        }
        root->isRed = false;
    }

    void print(Node<T> *node, int depth = 0)
    {
        if (node != nullptr)
        {
            for (int i = 0; i < depth; i++)
                cout << "  ";

            cout << node->value << (node->isRed ? "(r)\n" : "(b)\n");

            print(node->left, depth + 1);
            print(node->right, depth + 1);
        }
    }

public:
    void Insert(T value)
    {
        Node<T> *newNode = new Node<T>();
        newNode->value = value;

        if (root == nullptr)
        {
            root = newNode;
            root->isRed = false;
            return;
        }

        Node<T> *parent = nullptr;
        Node<T> *current = root;

        while (current != nullptr)
        {
            parent = current;
            if (value < current->value)
                current = current->left;
            else
                current = current->right;
        }

        newNode->parent = parent;
        if (value < parent->value)
            parent->left = newNode;
        else
            parent->right = newNode;

        FixInsert(newNode);
    }

    void Delete(T value)
    {
        Node<T> *target = root;
        Node<T> *replacement = nullptr;
        bool targetOriginalColor = true;

        while (target != nullptr && target->value != value)
        {
            if (value < target->value)
                target = target->left;
            else
                target = target->right;
        }

        if (target == nullptr)
        {
            cout << "not found\n";
            return;
        }

        targetOriginalColor = target->isRed;

        if (target->left == nullptr)
        {
            replacement = target->right;
            replaceNode(target, target->right);
        }
        else if (target->right == nullptr)
        {
            replacement = target->left;
            replaceNode(target, target->left);
        }
        else
        {
            Node<T> *successor = getMinimum(target->right);
            targetOriginalColor = successor->isRed;
            replacement = successor->right;

            if (successor->parent != target)
            {
                replaceNode(successor, successor->right);
                successor->right = target->right;
                if (successor->right != nullptr)
                    successor->right->parent = successor;
            }

            replaceNode(target, successor);
            successor->left = target->left;
            if (successor->left != nullptr)
                successor->left->parent = successor;
            successor->isRed = target->isRed;
        }

        if (!targetOriginalColor && replacement != nullptr)
            FixDelete(replacement);
    }

    void print()
    {
        print(root);
    }
};
int main()
{
    RedBlackTree<int> rbt;
    rbt.Insert(200);
    rbt.Insert(158);
    rbt.Insert(2500);
    rbt.Insert(555);
    rbt.Insert(00);
    rbt.Insert(0);
    rbt.print();

    rbt.Delete(50);
    rbt.print();

    rbt.Delete(0);
    rbt.print();

    return 0;
}
