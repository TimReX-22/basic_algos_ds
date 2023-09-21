#pragma once

#include <cmath>
#include <optional>
#include <vector>

inline static float distance(
    std::vector<int> const& point1, std::vector<int> const& point2) {
    assert(point1.size() == point2.size());
    float res = 0;
    for (int i = 0; i < point1.size(); ++i) {
        res += std::pow(point1[i] - point2[i], 2);
    }
    return res;
}

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

    bool isLeaf() { return !left_ && !right_; }

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

    std::optional<std::vector<int>> nearestNeighbor(
        std::vector<int> const& search_point) const;

    std::vector<std::vector<int>> in_order_traversal() const;

   private:
    bool insert(KDNode* new_node);
    static bool insert(KDNode* root, KDNode* new_node, int depth);
    static bool contains(
        KDNode* node, std::vector<int> const& point_coord, int depth);
    static void in_order_traversal(
        KDNode* node, std::vector<std::vector<int>>& result);
    static void nearestNeighbor(
        KDNode* root, std::vector<int> const& search_point,
        std::vector<int>& closest_point, float& min_distance, int depth);

    KDNode* root_;
};