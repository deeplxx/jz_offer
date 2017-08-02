#include <stdexcept>

struct BinaryTreeNode {
    int m_nvalue;
    BinaryTreeNode* m_pleft;
    BinaryTreeNode* m_pright;
};

BinaryTreeNode* custructorTree_core(int* startpreorder, int* endpreorder,
                                    int* startinorder, int* endinorder);

BinaryTreeNode* custructorTree(int* preorder, int* inorder, int length)
{
    if (preorder == nullptr || inorder ==nullptr || length <= 0)
        return nullptr;
    return custructorTree_core(preorder, preorder + length, inorder, inorder + length);
}

BinaryTreeNode* custructorTree_core(int* startpreorder, int* endpreorder,
                                    int* startinorder, int* endinorder)
{
    BinaryTreeNode* root(nullptr);
    root->m_nvalue = *startpreorder;
    root->m_pleft = nullptr;
    root->m_pright = nullptr;

    // 边界情况
    if (startpreorder == endpreorder) {
        if (startinorder == endinorder && *startpreorder == * startinorder)
            return root;
        else
            throw std::runtime_error("invalid input!");
    }

    // 中序遍历找root然后对子树递归
    int* root_inorder = startinorder;
    while (root_inorder != endinorder && *root_inorder != *startpreorder) {
        root_inorder++;
    }

    // 边界情况
    if (*root_inorder != *startpreorder)
        throw std::runtime_error("invalid input!");

    int leftLength = root_inorder - startinorder;
    int* left_pre_end = startpreorder + leftLength;
    if (leftLength > 0)
        custructorTree_core(startpreorder + 1, left_pre_end,
                            startinorder, root_inorder - 1);
    if (leftLength < (endpreorder - startpreorder))
        custructorTree_core(left_pre_end + 1, endpreorder,
                            root_inorder + 1, endinorder);

    return root;
}
