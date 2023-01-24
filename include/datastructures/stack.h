#ifndef BASIC_ALGOS_DS_STACK_H
#define BASIC_ALGOS_DS_STACK_H

#include <initializer_list>
#include <iostream>
#include <optional>

template <typename T>
class Stack {
   public:
    Stack() = default;

    explicit Stack(T val) { head_ = tail_ = new Node(val); }

    explicit Stack(std::initializer_list<T> list) {
        for (T const& elem : list) {
            insert(elem);
        }
    }

    void insert(T val) {
        Node* new_node = new Node(val);
        if (!head_) {
            head_ = tail_ = new_node;
            return;
        }
        tail_->next = new_node;
        tail_ = new_node;
    }

    std::optional<T> pop() {
        if (!head_) {
            return std::nullopt;
        }
        Node* node = head_;
        Node* prev = nullptr;
        while (node != tail_) {
            prev = node;
            node = node->next;
        }
        T val = tail_->value;
        tail_ = prev;
        if (tail_) {
            tail_->next = nullptr;
        } else {
            head_ = nullptr;
        }
        return val;
    }

    void print() const {
        Node* node = head_;
        while (node) {
            std::cout << node->value;
            if (node->next) {
                std::cout << " -> ";
            }
            node = node->next;
        }
        std::cout << "\n";
    }

   private:
    struct Node {
        T value;
        Node* next = nullptr;

        Node(T val) : value(val) {}
    };

    Node* head_ = nullptr;
    Node* tail_ = nullptr;
};

#endif  // BASIC_ALGOS_DS_STACK_H