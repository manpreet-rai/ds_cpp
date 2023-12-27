/* Integer based linked list implementation
 * Created by Manpreet Rai on 12/26/2023
 * Open source under GPL v2 license
 */

#include <iostream>
#include "LinkedList.h"

/// Node class implementation
Node::Node(): val(0), next(nullptr), prev(nullptr) {}
Node::Node(int val): val(val), next(nullptr), prev(nullptr) {}
Node::Node(int val, Node* next): val(val), next(next), prev(nullptr) {}
Node::Node(int val, Node* next, Node* prev): val(val), next(next), prev(prev) {}

/**
 * Returns node's data value
 * @return int
 */
int Node::get_val() const {
    return this->val;
}

/**
 * Returns pointer to next node
 * @return Node*
 */
Node* Node::get_next() const {
    return this->next;
}

/**
 * Returns pointer to previous node
 * @return Node*
 */
Node* Node::get_prev() const {
    return this->prev;
}

/**
 * Set's value of node's data
 * @param int value
 */
void Node::set_val(int value) {
    this->val = value;
}

/**
 * Set's next pointer of node
 * @param Node* next
 */
void Node::set_next(Node *new_next) {
    this->next = new_next;
}

/**
 * Set's previous pointer of node
 * @param Node* prev
 */
void Node::set_prev(Node *new_prev) {
    this->prev = new_prev;
}


/// LinkedList class implementation
LinkedList::LinkedList(): head(nullptr), tail(nullptr) {}

/**
 * Returns head node for linked list
 * @return Node*
 */
Node* LinkedList::get_head() const {
    return this->head;
}

/**
 * Returns tail node for linked list
 * @return Node*
 */
Node* LinkedList::get_tail() const {
    return this->tail;
}

/**
 * Set's head node for linked list
 * @param Node* head
 */
void LinkedList::set_head(Node* node) {
    this->head = node;
}

/**
 * Set's tail node for linked list
 * @param Node* tail
 */
void LinkedList::set_tail(Node* node) {
    this->tail = node;
}

/**
 * Creates new node at end of list
 * @param int value
 */
void LinkedList::insert_node(int value) {
    // Create new node
    Node* node = new Node(value);

    // Check if head exists/ else assign new node as head and tail
    if (this->get_head() == nullptr) { this->set_head(node); this->set_tail(node); return; }

    // Otherwise, insert node at end
    this->get_tail()->set_next(node);
    node->set_prev(this->get_tail());

    this->set_tail(node);
}

/**
 * Updates node at specified position with new data
 * @param int position
 * @param int value
 */
void LinkedList::update_node(int position, int value) const {
    if (this->get_head() == nullptr) { std::cout << "Update failed: list empty\n"; return; }

    Node* temp = this->get_head();
    int i = 0;
    while (i != position) {
        temp = temp->get_next();
        if (temp == nullptr) { std::cout << "Update failed: node not found\n"; return; }
        ++i;
    }

    temp->set_val(value);
}

/**
 * Outputs linked list to console
 */
void LinkedList::print_list() const {
    if (this->get_head() == nullptr) { std::cout << "<>" << '\n'; return; }

    Node* temp = this->get_head();
    std::cout << "< ";
    while (temp != nullptr) {
        std::cout << temp->get_val() << ' ';
        temp = temp->get_next();
    }
    std::cout << ">\n";
}

/**
 * Deletes node at specified position
 * @param int position
 */
void LinkedList::delete_node(int position) {
    if (this->get_head() == nullptr) return;

    Node* temp = this->get_head();
    int i = 0;
    while (i != position) {
        temp = temp->get_next();
        if (temp == nullptr) return;
        ++i;
    }

    if (temp == this->get_head()) {
        this->set_head(temp->get_next());
        if (temp->get_next() != nullptr) temp->get_next()->set_prev(nullptr);
    }
    else if (temp->get_next() == nullptr) {
        temp->get_prev()->set_next(nullptr);
        this->set_tail(temp->get_prev());
    }
    else {
        temp->get_prev()->set_next(temp->get_next());
        temp->get_next()->set_prev(temp->get_prev());
    }
}

/**
 * Returns size of linked list
 * @return int
 */
int LinkedList::size() const {
    if (this->get_head() == nullptr) return 0;

    Node* temp = this->get_head();
    int i = 1;
    while (temp->get_next() != nullptr) { temp = temp->get_next(); ++i; }
    return i;
}

