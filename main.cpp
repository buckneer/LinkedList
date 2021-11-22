#include <iostream>

using namespace std;

// Create a new structure "item"
struct item {

    // Data to be displayed
    int data;

    // pointer to the next item
    item* next;
};

// Class LinkedList that can be called
class LinkedList {

private:
    item *head, *tail;


public:

    // Class constructor
    LinkedList() {
        // Head is the first item of linked list
        head = NULL;

        // Tail is the last
        tail = NULL;
    }

    // Add item at the end
    void add_node(int n) {

        // We allocate the memory by using new keyword
        item *tmp = new item;

        // data is given to tmp item, data is 1,
        // and next is empty, since this is going to be last item
        tmp->data = n;
        tmp->next = NULL;

        // We check if there are any nodes in list
        if(head == NULL) {

            // if not, then add temp as head and tail
            head = tmp;
            tail = tmp;
        } else {

            // We are going to set tail->next as this new temporary item
            tail->next = tmp;

            // And then, add it as tail, since this is the last item in the list
            tail = tail->next;
        }

    }

    item* getHead() {
        return head;
    }

    void del(item *beforeDel) {
        item* temp;
        temp = beforeDel->next;
        beforeDel->next = temp->next;
        delete temp;
    }



    // Printing linked list (simple)
    void print() {
        // Initialise temporary structure
        item *tmp;

        // Add first element to it.
        tmp = head;

        // Iterate over list to print out data
        while (tmp != NULL) {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
};


int main() {

    LinkedList linkedList;
    int n, x;

    cout << "How many items?" << endl;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Item number: " << i << endl;
        cin >> x;
        linkedList.add_node(x);
    }



    linkedList.print();

    cout << "You are the smartest man alive!";


    return 0;
}
