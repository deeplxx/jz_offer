#include <stdexcept>
#include <structList.h>


void cloneListNode(ComplexListNode* head)
{
    ComplexListNode* p = head;
//    ComplexListNode* copy = p;  // 此句copy还是跟head指向同一个节点！！！
    while (p !=nullptr) {  // 此循环将原始链表的每个节点p复制并将复制的节点n接在p之后，n的sibling初始化为null，
        // 后续这个加长的链表，奇数节点是原始链表，偶数节点是复制的链表
        // （在原始链表上做更改）
        ComplexListNode* n = new ComplexListNode();
        n->m_value = p->m_value;
        n->m_pNext = p->m_pNext;
        n->m_pSibling = nullptr;

        p->m_pNext = n;
        p = n->m_pNext;
    }
}


/**
 * @brief find_slibNode 给clone的node找slibNode
 * @param head
 */
void find_slibNode(ComplexListNode* head)
{
    ComplexListNode* p = head;
    while (p != nullptr) {
        if (p->m_pNext == nullptr)
            throw std::runtime_error("unknown error!");
        if (p->m_pSibling != nullptr) {
            p->m_pNext->m_pSibling = p->m_pSibling->m_pNext;
        }
        p = p->m_pNext->m_pNext;
    }
}

ComplexListNode* segmenList(ComplexListNode* head)
{
    if (head == nullptr)
        throw std::runtime_error("invalid input!");

    ComplexListNode* originalHead = head, *p = originalHead;
    ComplexListNode* cloneHead = head->m_pNext, *q = cloneHead;

    while (q != nullptr) {
        if (q->m_pNext != nullptr) {
            p->m_pNext = p->m_pNext->m_pNext;
            q->m_pNext = q->m_pNext->m_pNext;
        }
        p = p->m_pNext;
        q = q->m_pNext;
    }

    return cloneHead;
}


ComplexListNode* copyComplexList(ComplexListNode* head)
{
    cloneListNode(head);
    find_slibNode(head);
    return segmenList(head);
}

/*
    1.想法很好，复制一个复杂链表，可以先在原链表节点后复制一个节点，然后再分离
*/
