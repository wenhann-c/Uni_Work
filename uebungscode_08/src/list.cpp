#include <memory>
#include <iostream>
#include <datenstrukturen/list.hpp>

namespace Datenstrukturen {
    
    // Initialize the class ListNode
    ListNode::ListNode(int data) :
        data_(data), next(nullptr)
    {
    }
    
    // Initialize the list
    List::List() :
        head(nullptr)
    {
    }
    
    // Insert x in the front as the head
    ListNodeptr List::insert_front(const int x) {
        ListNodeptr a = std::make_shared<ListNode>(x);
        // if (!head) {
        //     head = a;

        //     return head;
        // }
        a->next = head;
        head = a;

        return head;
    }

    // Insert x after the chosen pointer
    ListNodeptr List::insert_after(const ListNodeptr& pred, const int x) {
        ListNodeptr a = std::make_shared<ListNode>(x);
        a->next = pred->next;
        pred->next = a;

        return (*pred).next;
    }    

    // Remove the first in list and change the head
    ListNodeptr List::remove_front() {
        if (!head) {
            return nullptr;
        }
        ListNodeptr removed = head;
        head = head->next;

        return removed;
    }

    // Remove whatever that is after the chosen pointer
    ListNodeptr List::remove_after(const ListNodeptr& pred) {
        if (!head) {
            return nullptr;
        }
        ListNodeptr removed = pred->next;
        pred->next = removed->next;

        return removed;
    }

    // Get the next node of the chosen pointer
    ListNodeptr List::next(const ListNodeptr& n) const {
        if (n->next != nullptr) {
            std::cout << n->next->data_ << std::endl;
        }
        else {
            std::cout << "null" << std::endl;
        }
        return n->next;
    }

    // Print the list
    void List::print() const {
        ListNodeptr current = head;
        while (current) {
            std::cout << current-> data_ << "->";
            current = current->next;
        }
        std::cout << "null" << std::endl;
    }
  
}

