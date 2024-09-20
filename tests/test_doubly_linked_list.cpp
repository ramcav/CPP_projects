#include <gtest/gtest.h>
#include <list>
#include <string>
#include "doubly_linked_list.h"

namespace doubly_linked_list {

    TEST(DoublyLinkedListTest, TestInsert) {
        std::list<std::string> l = {"Apple", "Banana", "Cherry"};
        Node* head, *node_1, *node_2, *node;

        node_2 = createNode("Cherry");
        node_1 = insert(node_2, createNode("Banana"));
        head = insert(node_1, createNode("Apple"));

        auto node_l = l.begin();
        ASSERT_EQ(head->val, *node_l);

        node = head->next;
        ASSERT_EQ(node->val, *(++node_l));

        node = node->next;
        ASSERT_EQ(node->val, *(++node_l));

        // Free all allocated nodes (start from head, traverse through next)
        node = head;
        while (node != nullptr) {
            Node* temp = node;
            node = node->next;
            delete temp;
        }
    }

    TEST(DoublyLinkedListTest, TestErase) {
        std::list<std::string> l = {"Apple", "Banana", "Cherry"};
        Node* head, *node_1, *node_2;

        node_2 = createNode("Cherry");
        node_1 = insert(node_2, createNode("Banana"));
        head = insert(node_1, createNode("Apple"));

        // Test erasing the head
        head = erase(head);
        EXPECT_EQ(head->val, "Banana");
        EXPECT_EQ(head->prev, nullptr);

        // Test erasing the middle node (Banana)
        head = erase(head); 
        EXPECT_EQ(head->val, "Cherry");
        EXPECT_EQ(head->prev, nullptr); 

        // Test erasing the last node (Cherry)
        head = erase(head);
        EXPECT_EQ(head, nullptr);

        // No need to free nodes as all were erased
    }

    TEST(DoublyLinkedListTest, TestAdd) {
        std::list<std::string> l = {"Apple", "Banana", "Cherry"};
        Node* head, *node_1, *node_2, *node;

        head = createNode("Apple");
        node_1 = add(head, createNode("Banana"));
        node_2 = add(node_1, createNode("Cherry"));

        auto node_l = l.begin();
        ASSERT_EQ(head->val, *node_l);

        node = head->next;
        ASSERT_EQ(node->val, *(++node_l));

        node = node->next;
        ASSERT_EQ(node->val, *(++node_l));

        // Free all allocated nodes (start from head, traverse through next)
        node = head;
        while (node != nullptr) {
            Node* temp = node;
            node = node->next;
            delete temp;
        }
    }

}