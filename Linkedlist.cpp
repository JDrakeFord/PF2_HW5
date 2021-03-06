//
// Created by drake on 11/3/21.
//
#include "Linkedlist.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;
Linkedlist::Linkedlist() {
    head = NULL;
    tail = NULL;
    size = 0;
}

Linkedlist::Linkedlist(unsigned int n) {
    size = n;
    tail = NULL;
    head = new Node;
    Node *iter = head;
    //Create the nodes
    for(int i = 0; i < n; i++)
    {
        iter -> data = i;
        iter -> next = new Node;
        iter -> next -> prev = iter;
        iter = iter -> next;
    }
    tail = iter -> prev;
    tail -> next = NULL;
}

Linkedlist::~Linkedlist() {
    Node *del;
    //Delete each node
    while(head != NULL)
    {
        del = head;
        head = head -> next;
        delete del;
    }
}

bool Linkedlist::empty() const {
    return (head == NULL);
}

void Linkedlist::clear() {
    Node *iter = head;
    Node *del;
    //Delete each node;
    while(iter != NULL)
    {
        del =  iter;
        iter = iter -> next;
        delete del;
    }
    head = NULL;
    tail = NULL;
}

Linkedlist::reference Linkedlist::front() {
    return head -> data;
}

Linkedlist::reference Linkedlist::back() {
    return tail -> data;
}

Linkedlist::const_reference Linkedlist::front() const {
    return head -> data;
}

Linkedlist::const_reference Linkedlist::back() const {
    return tail -> data;
}

void Linkedlist::push_back(const element_type &x) {
    if(head != NULL)
    {
        tail -> next = new Node;
        tail -> next -> prev = tail;
        tail = tail -> next;
        tail -> data = x;
        tail -> next = NULL;
    }
    //If head is null, we need to create a node for head
    else
    {
        head = new Node;
        head -> data = x;
        head -> prev = NULL;
        head -> next = NULL;
        tail = head;
    }
}

void Linkedlist::push_front(const element_type &x) {
    head -> prev = new Node;
    head -> prev -> next = head;
    head = head -> prev;
    head -> data = x;
    head -> prev = NULL;
}

void Linkedlist::pop_back() {
    if(!empty())
    {
        Node *del = tail;
        tail = tail -> prev;
        delete del;
        tail -> next = NULL;
    }
}

void Linkedlist::pop_front(){
    if(!empty())
    {
        Node *del = head;
        head = head -> next;
        delete del;
        head -> prev = NULL;
    }

}

//Lab check function
void Linkedlist::check() const {
    Node* current = head;
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    int i = 0;
    while (current != NULL)
    {
        cout << "Node "
             << setw(3) << i
             << "   "
             << "Elem: "
             << setw(3) << current-> data << "   "
             << "Address: "
             << setw(8) << current
             << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->next;
        i++;
    }
    cout << "------------------------------------------------------------------------------------------" << endl;
}

//Lab rcheck() function
void Linkedlist::rcheck() const {
    Node* current = tail;
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    int i = 0;
    while (current != NULL)
    {
        cout << "Node "
             << setw(3) << i
             << "   "
             << "Elem: "
             << setw(3) << current-> data << "   "
             << "Address: "
             << setw(8) << current
             << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->prev;
        i++;
    }
    cout << "------------------------------------------------------------------------------------------" << endl;
}

Linkedlist &Linkedlist::operator=(const Linkedlist &l) {
    clear();
    //return the empty list if l is empty
    if(l.empty())
    {
        return *this;
    }
    //Create iterator nodes for each list
    Node *iterRight = l.head;
    head = new Node;
    Node *iterLeft = head;
    //Copy nodes
    while(iterRight != NULL) {
        iterLeft->data = iterRight->data;
        iterLeft->next = new Node;
        iterLeft->next->prev = iterLeft;
        iterLeft = iterLeft->next;
        iterRight = iterRight->next;
    }
    tail = iterLeft -> prev;
    tail -> next = NULL;
    return *this;
}

void Linkedlist::insert(unsigned int pos, const element_type &x) {
    //If it isn't empty
    if(head != NULL)
    {
        //Find the node to insert
        Node *iter = head;
        for (int i = 0; i <= pos && iter->next != NULL; i++) {
            iter = iter->next;
        }
        //Insert
        Node *temp = new Node;
        temp->data = x;
        temp->prev = iter;
        temp->next = iter->next;
        iter->next = temp;
        temp->next->prev = temp;
    }
    //If it is empty, we can just call push_back(x)
    else
    {
        push_back(x);
    }


}

void Linkedlist::erase(unsigned int pos) {
    //Do nothing if it is already clear
    if(head != NULL)
    {
        //Find node to erase
        Node *iter = head;
        for(int i = 0; i < pos - 1 && iter -> next != NULL; i++)
        {
            iter = iter -> next;
        }
        //Erase
        Node *del = iter -> next;
        iter -> next = iter -> next -> next;
        iter -> next -> prev = iter;
        delete del;
    }
}
//Helper function for sort
void Linkedlist::swap(Linkedlist::Node *a, Linkedlist::Node *b) {
    int temp;
    temp = a -> data;
    a -> data = b -> data;
    b -> data = temp;
}

//Linked list bubble sort implementation
void Linkedlist::sort() {
    Node *current = head;
    bool swapped = false;
    int pos = 0;
    //Go through the list
    while (current->next != NULL) {
        //If they need to be swapped
        if (current->next->data > current->data) {
            //swap them
            swap(current, current->next);
            swapped = true;
        }
        current = current->next;
        pos++;
    }
    //If we just performed a swap, we sort again
    if (swapped)
        sort();
}



