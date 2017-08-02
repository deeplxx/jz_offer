#include <stdexcept>
#include <vector>

struct BinaryTree {
    int m_value;
    BinaryTree* m_Left;
    BinaryTree* m_Right;
};

void print_fit_path(BinaryTree* root, int target, std::vector<int> path)
{
//    currentsum += root->m_value;
    path.push_back(root->m_value);

    bool isLeef = root->m_Left == nullptr && root->m_Right == nullptr;

    if (target == root->m_value && isLeef) {
        for (auto i = path.begin(); i < path.end(); i++) {
            printf("%d\t", *i);
        }
    }

    if (target >= root->m_value) {
        if (root->m_Left != nullptr)
            print_fit_path(root->m_Left, target - root->m_value, path);
        if (root->m_Right != nullptr)
            print_fit_path(root->m_Right, target - root->m_value, path);
    }

    path.pop_back();  // 返回父节点之前要弹出

}

void findPath(BinaryTree* root, int target)
{
    if (root == nullptr)
        throw std::runtime_error("invalid input!");

    std::vector<int> path;
    print_fit_path(root, target, path);
}
