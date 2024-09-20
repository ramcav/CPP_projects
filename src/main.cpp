#include <iostream>
#include "doubly_linked_list.h"

int main() {
    using namespace doubly_linked_list;


    // Running createNode
    Node* head = createNode("Apple");
    
    // Adding nodes after the head
    Node* bananaNode = add(head, createNode("Banana"));
    
    Node* cherryNode = add(bananaNode, createNode("Cherry"));
    
    // Inserting node before the second node
    insert(bananaNode, createNode("Grapes"));


    // Do a forward traversal and print all vals
    std::cout << "Forward traversal:" << std::endl;
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        if (current->next == nullptr) {
            break;  // Stop at the last node
        }
        current = current->next;
    }
    std::cout << std::endl;

    // Remove node containing banana val
    std::cout << "Erasing Banana..." << std::endl;
    erase(bananaNode);

    // Print again
    std::cout << "Forward traversal after erase:" << std::endl;
    current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    while (current != nullptr) {
        Node* temp = current;
        current = current->prev;
        delete temp;
    }

    return 0;
}
