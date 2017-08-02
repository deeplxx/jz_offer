#ifndef STRUCT_H
#define STRUCT_H

struct BinaryTreeNode {
    int m_value;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};


struct ListNode {
    int m_value;
    ListNode* m_pNext;
};


struct DeListNode {
    int m_value;
    DeListNode* m_pNext;
    DeListNode* m_pFront;
};


struct ComplexListNode {
    int m_value;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
};

#endif // STRUCT_H
