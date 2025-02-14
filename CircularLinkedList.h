#ifndef CIRCULARLINKEDLIST_H_INC
#define CIRCULARLINKEDLIST_H_INC

template<typename T>
class CircularLinkedList
{
    private:

    class Node
    {
        public:

        //stored element
        T element;
        //the pointer to the next Node
        Node* next;

        Node(const T& elem, Node* nxt = nullptr)
        :
        element{elem},
        next{nxt}
        {
        }

        //copy constructor
        Node(const Node &node)
        : 
        element{node.element},
        next{node.next}
        {
        }

        //assignment operator overload
        Node operator=(Node const&node)
        {
            Node new_node;

            new_node.element = element;
            new_node.next = next;

            return new_node;
        }

    };

    //the number of elements in the circular linked list
    int sz{0};
    //the pointer to the last node of the circular linked list
    Node* tail{nullptr};
    
    public:

    //the node we're currently at in the circular linked list
    Node* current_node{nullptr};

    //default constructor
    CircularLinkedList()
    {
        if(tail != nullptr)
        {
            current_node = tail->next;
        }
    }

    //returns how many elements are in the circular linked list
    int get_size() const
    {
        return sz;
    }

    //returns if the circular linked list is empty
    bool empty() const
    {
        return sz == 0;
    }

    //returns the first element in the circular linked list (can be modified)
    T& front()
    {
        return tail->next->element;
    }

    //returns the first element in the circular linked list (cannot be modified)
    const T& front() const
    {
        return tail->next->element;
    }

    //returns the last element in the circular linked list (can be modified)
    T& back()
    {
        return tail->element;
    }

    //returns the last element in the circular linked list (cannot be modified)
    const T& back() const
    {
        return tail->element;
    }

    //adds a new element to the front of the circular linked list
    void push_front(const T& elem)
    {
        if(sz == 0)
        {
            tail = new Node(elem);
            tail->next = tail;
        }
        else
        {
            tail->next = new Node(elem, tail->next);
        }
        sz++;

        if(current_node == nullptr)
        {
            current_node = tail->next;
        }
    }

    //add element to back of the circular linked list
    void push_back(const T& elem)
    {
        push_front(elem);
        tail = tail->next;
    }

    //remove element from the front of the circular linked list
    void pop_front()
    {
        Node* head = tail->next;
        
        if(head == tail)
        {
            tail = nullptr;
            current_node = nullptr;
        }
        else
        {
            tail->next = head->next;
            
            if(current_node == head)
            {
                current_node = head->next;
            }
        }
        
        delete head;
        sz--;
    }

    //moves the first element to the back of the circular linked list
    void rotate()
    {
        if(tail != nullptr)
        {
            tail = tail->next;
        }
    }

    //updates the current node we're at to the next node
    void step()
    {
        if(current_node != nullptr)
        {
            current_node = current_node->next;
        }
    }

};

#endif
