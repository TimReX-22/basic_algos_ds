#include "kd_tree.h"

bool KDTree::insert(std::vector<int> const& new_point_coord) {
    KDNode* new_node = new KDNode(new_point_coord);
    return insert(new_node);
}

bool KDTree::insert(KDNode* new_node) {
    if (!root_) {
        root_ = new_node;
        return true;
    }
    if (root_->k() != new_node->k()) {
        return false;
    }
    return insert(root_, new_node, 0);
}

bool KDTree::insert(KDNode* root, KDNode* new_node, int depth) {
    int plane = depth % root->k();
    if (root->at(plane) < new_node->at(plane)) {
        if (!root->right()) {
            root->set_right(new_node);
            return true;
        }
        return insert(root->right(), new_node, depth + 1);
    } else if (root->point() != new_node->point()) {
        if (!root->left()) {
            root->set_left(new_node);
            return true;
        }
        return insert(root->left(), new_node, depth + 1);
    }
    return false;
}

bool KDTree::contains(std::vector<int> const& point_coord) const {
    if (!root_ || root_->k() != point_coord.size()) {
        return false;
    }
    return contains(root_, point_coord, 0);
}

bool KDTree::contains(
    KDNode* node, std::vector<int> const& point_coord, int depth) {
    if (node->is_equal(point_coord)) {
        return true;
    }
    int plane = depth % node->k();
    if (node->at(plane) < point_coord[plane]) {
        return node->right() && contains(node->right(), point_coord, depth + 1);
    } else {
        return node->left() && contains(node->left(), point_coord, depth + 1);
    }
}

std::vector<std::vector<int>> KDTree::in_order_traversal() const {
    std::vector<std::vector<int>> result;
    in_order_traversal(root_, result);
    return result;
}

void KDTree::in_order_traversal(
    KDNode* node, std::vector<std::vector<int>>& result) {
    if (!node) {
        return;
    }
    in_order_traversal(node->left(), result);
    result.push_back(node->point());
    in_order_traversal(node->right(), result);
}

std::optional<std::vector<int>> KDTree::nearestNeighbor(
    std::vector<int> const& search_point) const {
    if (!root_ || root_->k() != search_point.size()) {
        return std::nullopt;
    }
    std::vector<int> closest_point = root_->point();
    float min_distance = std::numeric_limits<float>::max();
    nearestNeighbor(root_, search_point, closest_point, min_distance, 0);
    return closest_point;
}

void KDTree::nearestNeighbor(
    KDNode* root, std::vector<int> const& search_point,
    std::vector<int>& closest_point, float& min_distance, int depth) {
    float current_distance = distance(root->point(), search_point);
    if (current_distance < min_distance) {
        min_distance = current_distance;
        closest_point = root->point();
    }
    int plane = depth % root->k();
    if (root->at(plane) < search_point[plane]) {
        if (!root->right()) {
            return;
        } else {
            nearestNeighbor(
                root->right(), search_point, closest_point, min_distance,
                depth + 1);
            float distance_hyperplane =
                std::pow(root->at(plane) - search_point[plane], 2);
            if (distance_hyperplane > min_distance && root->left()) {
                nearestNeighbor(
                    root->left(), search_point, closest_point, min_distance,
                    depth + 1);
            }
        }
    } else {
        if (!root->left()) {
            return;
        } else {
            nearestNeighbor(
                root->left(), search_point, closest_point, min_distance,
                depth + 1);
            float distance_hyperplane =
                std::pow(root->at(plane) - search_point[plane], 2);
            if (distance_hyperplane > min_distance && root->right()) {
                nearestNeighbor(
                    root->right(), search_point, closest_point, min_distance,
                    depth + 1);
            }
        }
    }
}
