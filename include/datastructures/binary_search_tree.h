#ifndef BASIC_ALGOS_DS_BINARY_SEARCH_TREE_H
#define BASIC_ALGOS_DS_BINARY_SEARCH_TREE_H

#include <algorithm>
#include <iostream>
#include <optional>
#include <vector>

class BinarySearchTree {
   public:
    BinarySearchTree() = default;
    BinarySearchTree(int const val) : root_(new Node(val)) {}
    BinarySearchTree(std::initializer_list<int> const& list) {
        std::vector<int> vec(list);
        std::sort(vec.begin(), vec.end());
        createBST(vec);
    }

    void insert(int const val) {
        Node* new_node = new Node(val);
        if (!root_) {
            root_ = new_node;
            return;
        }
        Node* parent = root_;
        while (true) {
            if (val >= parent->value) {
                if (!parent->right) {
                    parent->right = new_node;
                    return;
                }
                parent = parent->right;
            } else {
                if (!parent->left) {
                    parent->left = new_node;
                    return;
                }
                parent = parent->left;
            }
        }
    }

    bool deleteNode(int const val) { return deleteNode(root_, val); }

    std::optional<int> findLess(int const val) { return findLess(root_, val); }

    std::optional<int> findGreater(int const val) {
        return findGreater(root_, val);
    }
    int findLessOrEqual(int const val);
    int findGreaterOrEqual(int const val);
    int findInRange(int const low, int const high);

    size_t size() { return sizeOfTree(root_); }

    std::optional<int> root() {
        if (root_) {
            return root_->value;
        }
        return std::nullopt;
    }

    void print() { printTree(root_, 0); }

   private:
    struct Node {
        int value;
        Node* right = nullptr;
        Node* left = nullptr;

        Node(int val) : value(val) {}
    };

    static std::optional<int> findLess(Node* node, int const val) {
        if (!node) {
            return std::nullopt;
        }
        if (node->value >= val) {
            return findLess(node->left, val);
        }
        int diff = val - node->value;
        if (node->right && diff > std::abs(val - node->right->value) &&
            (std::abs(val - node->right->value) != 0 || node->right->left ||
             node->right->right)) {
            return findLess(node->right, val);
        }
        return node->value;
    }

    static std::optional<int> findGreater(Node* node, int const val) {
        if (!node) {
            return std::nullopt;
        }
        if (node->value <= val) {
            return findGreater(node->right, val);
        }
        int diff = node->value - val;
        if (node->left && diff > (node->left->value - val) &&
            (node->left->value - val) >= 0 &&
            ((node->left->value - val) != 0 || node->left->left ||
             node->left->right)) {
            return findGreater(node->left, val);
        }
        return node->value;
    }

    static size_t sizeOfTree(Node* root) {
        if (!root) {
            return 0;
        }
        if (!root->right && !root->left) {
            return 1;
        }
        size_t right = sizeOfTree(root->right);
        size_t left = sizeOfTree(root->left);
        return right > left ? right + 1 : left + 1;
    }

    static Node* deleteNode(Node* node, int const val) {
        if (!node) {
            return node;
        }

        if (val > node->value) {
            node->right = deleteNode(node->right, val);
        } else if (val < node->value) {
            node->left = deleteNode(node->left, val);
        } else {
            if (!node->right && !node->left) {
                delete node;
                return nullptr;
            } else if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMinNode(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->value);
        }
        return node;
    }

    static Node* findMinNode(Node* root) {
        if (!root->left) {
            return root;
        }
        return findMinNode(root->left);
    }

    void createBST(std::vector<int> const& vec) {
        if (vec.size() == 0) {
            return;
        }
        if (vec.size() == 1) {
            insert(vec[0]);
            return;
        }
        int median = vec.size() / 2;
        if (median & 1) {
            --median;
        }
        insert(vec[median]);
        createBST({vec.begin(), vec.begin() + median});
        if (vec.begin() + median + 1 < vec.end()) {
            createBST({vec.begin() + median + 1, vec.end()});
        }
    }

    static void printTree(Node* root, int space) {
        if (!root) {
            std::cout << " \n";
            return;
        }
        space += kPrintSpace;
        printTree(root->right, space);
        for (int i = 0; i < space; ++i) {
            std::cout << " ";
        }
        std::cout << root->value << "\n";
        printTree(root->left, space);
    }

    Node* root_ = nullptr;

    static int const kPrintSpace;
};

int const BinarySearchTree::kPrintSpace = 5;

#endif  // BASIC_ALGOS_DS_BINARY_SEARCH_TREE_H