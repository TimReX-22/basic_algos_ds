#ifndef BASIC_ALGOS_DS_QUEUE_H
#define BASIC_ALGOS_DS_QUEUE_H

#include <iostream>
#include <optional>

template <typename T>
class Queue {
   public:
    Queue() : capacity_(kDefaultCapacity), count_(0), front_(0), rear_(-1) {
        arr_ = new T[capacity_];
    }

    explicit Queue(int const size)
        : capacity_(size), count_(0), front_(0), rear_(-1) {
        arr_ = new T[capacity_];
    }

    explicit Queue(std::initializer_list<T> const& list)
        : capacity_(kDefaultCapacity),
          count_(list.size()),
          front_(0),
          rear_(list.size() - 1) {
        arr_ = new T[capacity_];
        int i = 0;
        for (auto& element : list) {
            arr_[i] = element;
            ++i;
        }
    }

    Queue(int const size, std::initializer_list<T> const& list)
        : capacity_(size),
          count_(list.size()),
          front_(0),
          rear_(list.size() - 1) {
        arr_ = new T[capacity_];
        int i = 0;
        for (auto& element : list) {
            arr_[i] = element;
            ++i;
        }
    }
    ~Queue() { delete[] arr_; }
    Queue(Queue const& rhs) = default;

    Queue& operator=(Queue const& rhs) = default;

    bool enqueue(T val) {
        ++rear_;
        ++count_;
        if (full()) {
            return false;
        }
        arr_[rear_] = val;
        return true;
    }

    std::optional<T> dequeue() {
        if (empty()) {
            return std::nullopt;
        }
        T first_elem = arr_[front_];
        ++front_;
        --count_;
        return first_elem;
    }

    std::optional<T> peek() {
        if (empty()) {
            return std::nullopt;
        }
        return arr_[front_];
    }

    T front() { return arr_[front_]; }
    T back() { return arr_[rear_]; }
    bool empty() { return count_ == 0; }
    bool full() { return size() == capacity_; }
    size_t size() { return count_; }

   private:
    T* arr_;
    int capacity_;
    int count_;
    int front_;
    int rear_;

    static int const kDefaultCapacity;
};

template <typename T>
int const Queue<T>::kDefaultCapacity = 1000;

#endif  // BASIC_ALGOS_DS_QUEUE_H