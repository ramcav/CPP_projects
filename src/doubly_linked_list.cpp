#include <iostream>
#include <list>
#include <string>
#include "doubly_linked_list.h"

namespace doubly_linked_list {

    Node* createNode(const std::string& value) {
        return new Node(value);
    }


    Node* insert(Node* node, Node* new_node) {
        if (node == nullptr) {
            return new_node;
        }


        if (new_node == nullptr) {
            return node;
        }

        // good
        if (node->prev) {
            new_node->prev = node->prev;
            node->prev->next = new_node;
        }


        // good
        node->prev = new_node;

        
        new_node->next = node;

        return new_node;
    };

    Node* erase(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        Node* next = node->next;

        // Removing from the head
        if (node->prev == nullptr) {
            if (node->next) {
                node->next->prev = nullptr;
            }
        } else if (!node->next) {  // Removing from the tail
            if (node->prev) {
                node->prev->next = nullptr;
            }
        } else {  // Removing from the middle
            if (node->prev && node->next) {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
        }

        delete node;
        return next;
    }

    Node* add(Node* node, Node* new_node) {

        if (node == nullptr) {
            return new_node;
        }

        if (new_node == nullptr) {
            return node;
        }

        if (node->next == nullptr) {
            new_node->next = nullptr;
        } else {
            node->next->prev = new_node;
            new_node->next = node->next;
        }

        node->next = new_node;
        new_node->prev = node;

        return new_node;

    };
}