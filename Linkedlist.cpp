//
// Created by drake on 11/3/21.
//
#include "Linkedlist.h"
#include <cstdlib>
#include <iostream>

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

void Linkedlist::push_back(const element_type &x) {
    if(head != NULL)
    {
        tail -> next = new Node;
        tail -> next -> prev = tail;
        tail = tail -> next;
        tail -> data = x;
        tail -> next = NULL;
    }
    else
    {
        head = new Node;
        head -> data = x;
        head -> prev = NULL;
        head -> next = NULL;
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
    Node *del = tail;
    tail = tail -> prev;
    delete del;
    tail -> next = NULL;
}

void Linkedlist::pop_front(){
    Node *del = head;
    head = head -> next;
    delete del;
    head -> prev = NULL;
}

void Linkedlist::check() const {
    Node *iter = head;
    while(iter != NULL)
    {
        std::cout << iter -> data << " ";
        iter = iter -> next;
    }
    std::cout << std::endl;
}

void Linkedlist::rcheck() const {
    Node *iter = tail;
    while(iter != NULL)
    {
        std::cout << iter -> data << " ";
        iter = iter -> prev;
    }
    std::cout << std::endl;
}
//TODO produces a double free() error
Linkedlist &Linkedlist::operator=(const Linkedlist &l) {
    clear();
    if(l.empty())
    {
        return *this;
    }
    Node *iterRight = l.head;
    head = new Node;
    Node *iterLeft = head;
    while(iterRight != NULL)
    {
        iterLeft -> data = iterRight -> data;
        iterLeft -> next = new Node;
        iterLeft -> next -> prev = iterLeft;
        iterLeft = iterLeft -> next;
        iterRight = iterRight -> next;
    }
    return *this;
}

void Linkedlist::insert(unsigned int pos, const element_type &x) {
    if(head != NULL)
    {
        Node *iter = head;
        for (int i = 0; i <= pos && iter->next != NULL; i++) {
            iter = iter->next;
        }
        Node *temp = new Node;
        temp->data = x;
        temp->prev = iter;
        temp->next = iter->next;
        iter->next = temp;
        temp->next->prev = temp;
    }
    else
    {
        std::cout << "Pushing back x!" << std::endl;
        push_back(x);
    }


}

void Linkedlist::erase(unsigned int pos) {
    if(head != NULL)
    {
        Node *iter = head;
        for(int i = 0; i < pos - 1 && iter -> next != NULL; i++)
        {
            iter = iter -> next;
        }
        Node *del = iter -> next;
        iter -> next = iter -> next -> next;
        iter -> next -> prev = iter;
        delete del;
    }
}

void Linkedlist::sort() {

}
