#include<iostream>
using namespace std;

class BTree
{

    class BTreeNode
    {
    public:
        int *keys;
        int t;
        BTreeNode **C;
        int n;
        bool leaf;

        BTreeNode(int t1, bool leaf1)
        {
            t = t1;
            leaf = leaf1;
            keys = new int[2 * t - 1];
            C = new BTreeNode *[2 * t];
            n = 0;
        }

        void insertNonFull(int k)
        {
            int i = n - 1;
            if (leaf == true)
            {
                while (i >= 0 && keys[i] > k)
                {
                    keys[i + 1] = keys[i];
                    i--;
                }
                keys[i + 1] = k;
                n = n + 1;
            }
            else
            {
                while (i >= 0 && keys[i] > k) i--;
                if (C[i + 1]->n == 2 * t - 1)
                {
                    splitChild(i + 1, C[i + 1]);
                    if (keys[i + 1] < k) i++;
                }
                C[i + 1]->insertNonFull(k);
            }
        }

        void splitChild(int i, BTreeNode *y)
        {
            BTreeNode *z = new BTreeNode(y->t, y->leaf);
            z->n = t - 1;
            for (int j = 0; j < t - 1; j++) z->keys[j] = y->keys[j + t];
            if (y->leaf == false) for (int j = 0; j < t; j++) z->C[j] = y->C[j + t];
            y->n = t - 1;
            for (int j = n; j >= i + 1; j--) C[j + 1] = C[j];
            C[i + 1] = z;
            for (int j = n - 1; j >= i; j--) keys[j + 1] = keys[j];
            keys[i] = y->keys[t - 1];
            n = n + 1;
        }
    };


    int t;
public:
    BTreeNode *root;

    BTree(int _t)
    {
        root = NULL;
        t = _t;
    }

    bool search(int k)
    {
        BTreeNode *tmp = root;
        int i = 0;
        while (tmp->leaf == false)
        {
            for (; i < tmp->n; i++)
            {
                if (k == tmp->keys[i]) return 1;
                if (k < tmp->keys[i])
                {
                    tmp = tmp->C[i];
                    i = 0;
                    break;
                }
            }
            if (i == tmp->n)
            {
                tmp = tmp->C[tmp->n];
                i = 0;
            }
        }
        for (; i < tmp->n; i++) if (k == tmp->keys[i]) return 1;
        return 0;
    }

    void insert(int k)
    {
        if (root == NULL)
        {
            root = new BTreeNode(t, true);
            root->keys[0] = k;
            root->n = 1;
        }
        else
        {
            if (root->n == 2 * t - 1)
            {
                BTreeNode *s = new BTreeNode(t, false);
                s->C[0] = root;
                s->splitChild(0, root);
                int i = 0;
                if (s->keys[0] < k) i++;
                s->C[i]->insertNonFull(k);
                root = s;
            }
            else root->insertNonFull(k);
        }
    }

    void Print()//root
    {
        BTreeNode *tmp = root;
        for (int i = 0; i < tmp->n; i++) cout << tmp->keys[i] << endl;
        cout<<endl;
        for (int i = 0; i <= tmp->n; i++) Print1(tmp->C[i]);
    }

    void Print1(BTreeNode *p)//root
    {
        BTreeNode *tmp = p;
        for (int i = 0; i < tmp->n; i++) cout << tmp->keys[i] << endl;
        cout<<endl;
        if (tmp->leaf == false) for (int i = 0; i <= tmp->n; i++) Print1(tmp->C[i]);
    }
};

int main()
{
    BTree t(4 / 2);
    t.insert(3);
    t.insert(2);
    t.insert(17);
    t.insert(9);
    t.insert(4);
    t.insert(1);
    t.insert(6);
    t.insert(7);
    t.insert(8);
    t.insert(0);
    t.insert(-1);
    t.Print();
    int k = 2;
    cout << endl;
    if (t.search(k)) cout << "+" << endl;
    else cout << "-" << endl;
    k = 15;
    if (t.search(k)) cout << "+" << endl;
    else cout << "-" << endl;
    return 0;
}