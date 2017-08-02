#include <stdexcept>
#include <vector>
#include <structList.h>


void print_fit_path(BinaryTreeNode* root, int target, std::vector<int> path)
{
//    currentsum += root->m_value;
    path.push_back(root->m_value);

    bool isLeef = root->m_pLeft == nullptr && root->m_pRight == nullptr;

    if (target == root->m_value && isLeef) {
        for (auto i = path.begin(); i < path.end(); i++) {
            printf("%d\t", *i);
        }
    }

    if (target >= root->m_value) {
        if (root->m_pLeft != nullptr)
            print_fit_path(root->m_pLeft, target - root->m_value, path);
        if (root->m_pRight != nullptr)
            print_fit_path(root->m_pRight, target - root->m_value, path);
    }

    path.pop_back();  // 返回父节点之前要弹出

}

void findPath(BinaryTreeNode* root, int target)
{
    if (root == nullptr)
        throw std::runtime_error("invalid input!");

    std::vector<int> path;
    print_fit_path(root, target, path);
}
