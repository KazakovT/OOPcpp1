#include <iostream>
#include <string>

template <class T>
class Container {
public:
    struct Node {
        T value{};
        Node* next;
        Node* prev;
        Node() { next = prev = NULL; }
    };
    
private:    
    Node* Head;
    Node* Tail;
    int count;
public:
    class Iterator {
    public:

        Iterator(Node* first) { data = first; }
        Iterator operator++() { Iterator itr = *this; data = data->next; return itr; };
        bool operator!=(const Iterator&  lhs) const { return data != lhs.data; }
        T& operator*() { return data->value; }
        
    protected:
        Node* data;
    };

    Iterator begin() const { return Iterator(Head); }
    Iterator end() const { return Iterator(Tail->next); }
    Container();
    void AddFirst(T value);
    void AddLast(T value);
    void DeleteFirst();
    void DeleteLast();
    T GiveFirst();
    T GiveLast();
    int GiveCount();    
    void SwapCont(Container* second);
    void Swap();
    void Detour();
    ~Container();
};



template <class T> Container<T>::Container() {
    count = 0;
    Head = Tail = NULL;
}

template <class T> void Container<T>::AddFirst(T value) {
    Node* cur = new Node;                                     
    cur->value = value;  
    count++;
    if (Head == NULL)                    
    {
        cur->next = NULL;
        cur->prev = NULL;
        Head = Tail = cur;
                            
    }
    else 
    {
        Head->prev = cur;
        cur->next = Head;  
        Head = cur;
        Head->prev = NULL;
    }
}
template <class T> void Container<T>::AddLast(T value) {
    Node* cur = new Node;   
    cur->value = value;
    this->count++;
    if (Head == NULL)
    {
        cur->next = NULL;
        cur->prev = NULL;
        Head = Tail = cur;

    }
    else
    {
        cur->prev = Tail;
        Tail->next = cur;
        Tail = cur;
        Tail->next = NULL;
    }
}
template <class T> void Container<T>::DeleteFirst() {
    if (count != 0) {
        if (count == 1) {
            Tail=Head = NULL;
            delete Head;
            count--;
            return;
        }
        Node* cur = Head;
        Head = Head->next;
        Head->prev = NULL;
        count--;
        delete cur;
        return;
    }
    throw "Zero elements!";
}
template <class T> void Container<T>::DeleteLast() {
    if (count != 0) {
        if (count == 1) {
            Tail=Head = NULL;
            delete Head;
            count--;
            return;
        }
        Node* cur = Tail;
        Tail = Tail->prev;
        Tail->next = NULL;
        count--;
        delete cur;
        return;
    }  
    throw "Zero elements!";
}
template <class T> T Container<T>::GiveFirst() {
    if(Head!=NULL)
    return this->Head->value;
    throw "Zero elements!";
}
template <class T> T Container<T>::GiveLast() {
    if(Tail!=NULL)
    return this->Tail->value;
    throw "Zero elements!";
}
template <class T> int Container<T>::GiveCount() {
    return count;
}
template <class T> Container<T>::~Container() {
    while (count != 0) {
        DeleteFirst();
    }
}
template <class T> void Container<T>::SwapCont(Container* second) {
    int val = count;
    count = second->count;
    second->count = val;
    Node* cur = Head;
    Head = second->Head;
    second->Head = cur;
    cur = Tail;
    Tail = second->Tail;
    second->Tail = cur;
}
template <class T> void Container<T>::Swap() {
    if (Head != NULL) {
        Node* cur = Head;
        Node* neew = cur->prev;
        for (int i = 0; i < count; i++) {
            neew = cur->prev;
            cur->prev = cur->next;
            cur->next = neew;
            cur = cur->prev;
        }
        cur = Head;
        Head = Tail;
        Tail = cur;
    }
}
template <class T> void Container<T>::Detour() {
    for (Container<T>::Iterator i = this->begin(), end = this->end(); i != end; ++i)
    {
        std::cout << *i <<std::endl;
       
    }
}

