#include "Node.hpp"

class LinkedList
{
    private:
        Node* head;
        int count;

    public:
        LinkedList();
        void addEnd(string payload);
        string* toStringArray();
        string get(int index);
        void display();
};