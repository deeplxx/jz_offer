#include <stdexcept>
#include <structList.h>

/* ppLastNode是一个指向要转换的树的最左端的指针 */
void convertSubTree(BinaryTreeNode* root, BinaryTreeNode** ppLastNode)
{
    if (root == nullptr)  // 在递归函数中检查节点是否为空
        return;

    BinaryTreeNode* pCurrentNode = root;
    // 遍历左子树（不同的递归，pCurrent是不同的）
    if (pCurrentNode->m_pLeft != nullptr) {
        convertSubTree(pCurrentNode->m_pLeft, ppLastNode);
    }

    // 把*ppLastNode与当前节点链接起来
    pCurrentNode->m_pLeft = *ppLastNode;
    if (*ppLastNode != nullptr) {
        (*ppLastNode)->m_pRight = pCurrentNode;
    }

    // 遍历右子树,右子树最左端节点为当前节点
    if (pCurrentNode->m_pRight != nullptr) {
        convertSubTree(pCurrentNode->m_pRight, &pCurrentNode);
    }

    // 整个子树遍历完，则上一层的根节点的左端节点为最右端节点也即此时的当前节点
    *ppLastNode = pCurrentNode;
    // 最上一层递归，最终的*ppLastNode就是整棵树的最右端节点
}

BinaryTreeNode* convert(BinaryTreeNode* root)
{
    BinaryTreeNode* pLastNode = nullptr;
    convertSubTree(root, &pLastNode);

    BinaryTreeNode* headOfDeque = pLastNode;
    while (headOfDeque != nullptr && headOfDeque->m_pLeft != nullptr) {
        headOfDeque = headOfDeque->m_pLeft;
    }

    return headOfDeque;
}
