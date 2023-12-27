#include <iostream>
#include "LinkedList/LinkedList.h"

int main() {
    std::cout << "Welcome to Linked List" << std::endl;

    // Create linked list
    LinkedList linkedList;

    // Add or update data to list
    linkedList.insert_node(5);
    linkedList.insert_node(7);
    linkedList.update_node(0, 1);

    // Output list
    linkedList.print_list();

    // Get size of list
    int s = linkedList.size();
    std::cout << "Size: " << s << '\n';

    // Delete node from list
    linkedList.delete_node(0);
    linkedList.print_list();

    return 0;
}
