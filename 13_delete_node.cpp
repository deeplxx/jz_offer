#include <stdexcept>

struct ListNode {
    int m_nvalue;
    ListNode* m_pNext;
};

void delete_node(ListNode* head, ListNode* n)
{
    if (n == nullptr || head == nullptr)
        throw std::runtime_error("invalid error");

    if (n->m_pNext != nullptr) {
        n->m_nvalue = n->m_pNext->m_nvalue;
        n->m_pNext = n->m_pNext->m_pNext;
        delete n->m_pNext;
        n->m_pNext = nullptr;
    } else if (n == head) {
        delete n;
        n = nullptr;
    } else {
        ListNode* p = head;
        while (p->m_pNext != n) {
            p = p->m_pNext;
        }

        p->m_pNext = nullptr;
        delete n;
        n = nullptr;  // 没此句则会产生悬浮指针
    }
}
