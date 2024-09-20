#include<string>

namespace doubly_linked_list {
    struct Node {
        std::string val;
        Node* next;
        Node* prev;

        Node(std::string value = "", Node* next_ptr = nullptr, Node* prev_ptr = nullptr)
            : val(value), next(next_ptr), prev(prev_ptr) {}

    };

    /**
     * @brief Creates a node
     * @param value The value of the node to be created
     * @return The created
     */

    Node* createNode(const std::string& value);

    /**
    * @brief Insert a node before a given node. If the given node is nullptr,
    insert at the beginning.↪→
    * @param node The node before which to insert
    * @param new_node The node to insert
    * @return The inserted node
    */
    Node* insert(Node* node, Node* new_node);

    /**
    * @brief Delete a node from the list
    * @param n The node to delete
    * @return The next node
    */
    Node* erase(Node* node);

    /**
    * @brief Add a node after a given node.
    * @param p The node after which to add
    * @param n The node to add
    * @return The added node
    */
    Node* add(Node* p, Node* n);


    /**
     *@brief Test node insertion
    */
    void test_insert();

}