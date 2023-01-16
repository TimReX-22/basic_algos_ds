// Implementation of a FIFO queue
#ifndef BASIC_ALGOS_DS_QUEUE_H
#define BASIC_ALGOS_DS_QUEUE_H

#include <optional>

template <typename T>
class Queue {
   public:
    Queue() = default;
    Queue(std::initializer_list<T> const& list) : vector(list) {}
    Queue(Queue const& rhs) = default;

    Queue& operator=(Queue const& rhs) = default;

    void enqueue(T val) { vector.push_back(val); }
    std::optional<T> dequeue() {
        if (empty()) {
            return std::nullopt;
        }
        T last = vector[size() - 1];
        vector.pop_back();
        return last;
    }

    T front() { return vector.front(); }
    T back() { return vector.back(); }
    bool empty() { return vector.size() == 0; }
    size_t size() { return vector.size(); }

   private:
    std::vector<T> vector;
};
#endif  // BASIC_ALGOS_DS_QUEUE_H