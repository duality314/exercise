class MyLinkedList
{
public:
    // 还有几个疑问。
    struct linkedNode
    {
        linkedNode *next;
        int val;
        linkedNode(linkedNode *p = nullptr, int x = 0) : next(p), val(x) {}
    };

    MyLinkedList()
    {
        linkedNode *vHead = new linkedNode(nullptr, 0);
        _size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index > size)
        {
            return -1;
        }
        else
        {
            int curindex = 0;
            while (curindex != index)
            {
            }
        }
    }

    void addAtHead(int val)
    {
    }

    void addAtTail(int val)
    {
    }

    void addAtIndex(int index, int val)
    {
    }

    void deleteAtIndex(int index)
    {
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */