/* Integer based linked list implementation
 * Created by Manpreet Rai on 12/26/2023
 * Open source under GPL v2 license
 */

#ifndef DS_CPP_LINKEDLIST_H
#define DS_CPP_LINKEDLIST_H

class Node {
public:
    // Constructors
    Node();
    explicit Node(int value);
    explicit Node(int value, Node* next);
    explicit Node(int value, Node* next, Node* prev);

    // Getter member functions
    [[nodiscard]] int get_val() const;
    [[nodiscard]] Node* get_next() const;
    [[nodiscard]] Node* get_prev() const;

    // Setter member functions
    void set_val(int value);
    void set_next(Node* next);
    void set_prev(Node* prev);

private:
    // Data members
    int val{};
    Node* next{};
    Node* prev{};
};

class LinkedList {
public:
    // Constructors
    LinkedList();

    // Member functions
    [[nodiscard]] Node* get_head() const;
    [[nodiscard]] Node* get_tail() const;
    void set_head(Node* head);
    void set_tail(Node* tail);
    void insert_node(int value);
    void update_node(int position, int value) const;
    void print_list() const;
    void delete_node(int position);
    [[nodiscard]] int size() const;

private:
    Node* head;
    Node* tail;
};


#endif //DS_CPP_LINKEDLIST_H
