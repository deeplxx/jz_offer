#include <stdexcept>
#include <structList.h>


bool equalTree(BinaryTreeNode* a, BinaryTreeNode* b);

bool is_subTree(BinaryTreeNode* A, BinaryTreeNode* B)
{
    bool result = false;
    if (A == nullptr && B == nullptr)
        result = true;

    if (A != nullptr && B != nullptr) {
        if (A->m_value == B->m_value)
            result = equalTree(A, B);
        if (!result)
            result = is_subTree(A->m_pLeft, B);
        if (!result)
            result = is_subTree(A->m_pRight, B);
    }

    return result;
}

bool equalTree(BinaryTreeNode* a, BinaryTreeNode* b)
{
    if (b == nullptr)
        return true;
    else if (a == nullptr)
        return false;

    // 前两个判断语句已经完成了a和b是空的情况，后续是a和b非空的情况
    if (a->m_value != b->m_value)  // 因为要递归，所以函数必须要判断a和b的值是否相等
        return false;
    return equalTree(a->m_pLeft, b->m_pLeft) && equalTree(a->m_pRight, b->m_pRight);
}

/**
  逻辑：
    1.先判断A的值是否等于B，
    2.相等则判断A与B结构是否相同
    3.不等或不同则递归左子树和右子树判断
*/
