//
// Created by drake on 11/3/21.
//
#include "Linkedlist.h"
#include <cstdlib>
#include <iostream>

Linkedlist::Linkedlist() {
    head = NULL;
    prev = NULL;
}

Linkedlist::Linkedlist(unsigned int n) {
    prev = NULL;
    head = new Node;
    Node *iter = head;
    for(int i = 0; i < n; i++)
    {
        iter -> data = i;
        iter -> next = new Node;
        iter -> next -> prev = iter;
        iter = iter -> next;
    }
    iter = NULL;
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

void Linkedlist::check() const {
    Node *iter = head;
    while(iter -> next != NULL)
    {
        std::cout << iter -> data << " ";
        iter = iter -> next;
    }
}

