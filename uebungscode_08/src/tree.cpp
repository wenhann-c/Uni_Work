#include <memory>
#include <iostream>
#include <queue>
#include <vector>
#include <datenstrukturen/binarytree.hpp>

namespace Datenstrukturen {
    
    // Initialize the class Treenode
    TreeNode::TreeNode(int data) :
    data_(data), left_child(nullptr), right_child(nullptr)
    {
    }

    // Initialize the tree
    BinaryTree::BinaryTree(int root_data)
    {
        root = std::make_shared<TreeNode>(root_data);
    }

    // Get the data that is stored by set data function
    int TreeNode::get_data() const {
        return data_;
    }

    // Stored the chosen data into the node
    void TreeNode::set_data(int data) {
        data_ = data;
    }

    // Get the left node of the chosen node
    TreeNodeptr TreeNode::get_left_child() const {
        if (left_child == nullptr) {
            return nullptr;
        }
        else {
            return left_child;
        }
    }

    // Get the right node of the chosen node
    TreeNodeptr TreeNode::get_right_child() const {
        if (right_child == nullptr) {
            return nullptr;
        }
        else {
            return right_child;
        }
    }

    // Set the data of the left node
    void TreeNode::set_left_child(int data) {
        if (left_child == nullptr){
          left_child = std::make_shared<TreeNode>(data);
        }
        else {
            left_child->data_ = data;
        }
    }

    // Set the data of the right node
    void TreeNode::set_right_child(int data) {
        if (right_child == nullptr){
          right_child = std::make_shared<TreeNode>(data);
        }
        else {
            right_child->data_ = data;
        }
    }

    // Remove the left node of the chosen node
    void TreeNode::remove_left_child() {
        if (left_child == nullptr) {
            std::cout << "There is no left child" << std::endl;
        }
        else {
            left_child = nullptr;
        }
    }

    // Remove the right node of the chosen node
    void TreeNode::remove_right_child() {
        if (right_child == nullptr) {
            std::cout << "There is no right child" << std::endl;
        }
        else {
            right_child = nullptr;
        }
    }

    // Get the root ndoe of the bianry tree structure
    TreeNodeptr BinaryTree::get_root() const {
        return root;
    }

    // Print the Binary tree structure
    void BinaryTree::print() const {
        // Declared queue
        std::queue<TreeNodeptr> queue;
        // The root node is pushed into the queue
        queue.push(root);
        // Check if the queue is all cleared
        while (queue.empty() == false) {
            // Declared the first element of the queue as top
            TreeNodeptr top = queue.front();
            // Print the data of top
            std::cout << top->get_data() << std::endl;
            // Delete the first element of queue
            queue.pop();
            // Pushes top's left node to the queue (if exists)
            if (top->get_left_child()) {
                queue.push(top->get_left_child());
            }
            // Pushes top's right node to the queue (if exists)
            if (top->get_right_child()) {
                queue.push(top->get_right_child());
            }
        }
    }
}
