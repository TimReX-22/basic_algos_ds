#ifndef BASIC_ALGOS_DS_LINKED_LIST_H
#define BASIC_ALGOS_DS_LINKED_LIST_H

#include <initializer_list>
#include <iostream>
#include <optional>

template <typename T>
class LinkedList {
   public:
    LinkedList() = default;
    explicit LinkedList(int const val) {
        Node* node = new Node(val);
        head_ = tail_ = node;
    }
    LinkedList(std::initializer_list<T> list) {
        for (auto const& elem : list) {
            insert(elem);
        }
    }

    void insert(T val) {
        Node* new_node = new Node(val);
        if (!head_) {
            head_ = new_node;
            tail_ = new_node;
            return;
        }
        tail_->next = new_node;
        tail_ = new_node;
    }

    void insertAt(int const k, T val) {
        if (k < 0) {
            throw std::invalid_argument(
                "Index out of bounds, must be greater zero!");
        }
        int idx = 0;
        Node* node = head_;
        Node* prev = nullptr;
        Node* new_node = new Node(val);
        if (k == size()) {
            tail_->next = new_node;
            tail_ = new_node;
            return;
        }
        if (k > size()) {
            throw std::invalid_argument("Indox out of bounds, to big!");
        }
        while (node) {
            if (idx == k) {
                new_node->next = node;
                if (prev) {
                    prev->next = new_node;
                } else {
                    head_ = new_node;
                }
                return;
            }
            prev = node;
            node = node->next;
            ++idx;
        }
    }

    void removeByKey(T const key) {
        Node* node = head_;
        Node* prev = nullptr;
        while (node) {
            if (node->value == key) {
                if (prev) {
                    prev->next = node->next;
                } else {
                    head_ = node->next;
                }
                if (tail_ == node) {
                    tail_ = prev;
                }
                delete node;
                return;
            }
            prev = node;
            node = node->next;
        }
        throw std::invalid_argument("Key is not in List!");
    }
    void removeByIdx(int const idx) {
        if (idx < 0 || idx >= size()) {
            throw std::invalid_argument("Index out of Bounds!");
        }
        Node* node = head_;
        Node* prev = nullptr;
        int i = 0;
        while (node) {
            if (i == idx) {
                if (prev) {
                    prev->next = node->next;
                } else {
                    head_ = node->next;
                }
                if (tail_ == node) {
                    tail_ = prev;
                }
                delete node;
                return;
            }
            prev = node;
            node = node->next;
            ++i;
        }
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

    T& operator[](int const k) const {
        if (k < 0) {
            throw std::invalid_argument("Index out of bounds!");
        }
        Node* node = head_;
        int idx = 0;
        while (node) {
            if (idx == k) {
                break;
            }
            node = node->next;
            ++idx;
        }
        if (!node) {
            throw std::invalid_argument("Index out of bounds!");
        }
        return node->value;
    }

    T& at(int const k) const { return (*this)[k]; }

    bool empty() const { return !head_; }
    size_t size() const {
        size_t size = 0;
        Node* node = head_;
        while (node) {
            ++size;
            node = node->next;
        }
        return size;
    }

    std::optional<T> front() const {
        return head_ ? std::optional<T>{head_->value} : std::nullopt;
    }
    std::optional<T> back() const {
        return tail_ ? std::optional<T>{tail_->value} : std::nullopt;
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

#endif  // BASIC_ALGOS_DS_LINKED_LIST_H