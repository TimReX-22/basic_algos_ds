#pragma once

#include <vector>

class KDPoint {
   public:
    KDPoint() = default;
    explicit KDPoint(std::vector<int> const& point)
        : coord_(point), size_(point.size()) {}
    KDPoint(std::vector<int> const& point, unsigned int const size)
        : coord_(point), size_(size) {
        if (size_ != coord_.size()) {
            throw std::invalid_argument(
                "size and length of point vector must match!");
        }
    }

    int size() { return size_; }

   private:
    std::vector<int> const coord_;
    unsigned int size_ = 0;
};

class KDNode {
   public:
    KDNode() : left_(nullptr), right_(nullptr){};
    explicit KDNode(std::vector<int> const& point)
        : point_(point), left_(nullptr), right_(nullptr){};

    KDNode(std::vector<int> const& point, KDNode* left, KDNode* right)
        : point_(point), left_(left), right_(right){};

    KDNode* left() { return left_; }
    KDNode* right() { return right_; }
    void set_left(KDNode* node) { left_ = node; }
    void set_right(KDNode* node) { right_ = node; }

    unsigned int k() { return point_.size(); }
    int at(int idx) { return point_.at(idx); }
    bool is_equal(std::vector<int> point) const { return point == point_; }
    std::vector<int> point() { return point_; }

   private:
    std::vector<int> const point_;
    KDNode *left_, *right_;
};

class KDTree {
   public:
    KDTree() : root_(nullptr) {}
    KDTree(KDNode* root) : root_(root) {}

    bool insert(std::vector<int> const& new_point_coord);
    bool contains(std::vector<int> const& point_coord) const;

    std::vector<std::vector<int>> in_order_traversal() const;

   private:
    bool insert(KDNode* new_node);
    static bool insert(KDNode* root, KDNode* new_node, int depth);
    static bool contains(
        KDNode* node, std::vector<int> const& point_coord, int depth);
    static void in_order_traversal(
        KDNode* node, std::vector<std::vector<int>>& result);

    KDNode* root_;
};