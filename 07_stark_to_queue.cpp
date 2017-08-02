#include <stack>
#include <stdexcept>

using namespace std;

template<typename T> class CQUEUE
{
public:
    CQUEUE(void);
    ~CQUEUE(void);

    void appendTail(const T& node);
    T deletHead();

private:
    stack<T> stack1;
    stack<T> stack2;  //保存队列顺序的元素，不空则直接pop，只有空才从stack1中取元素
};

template<typename T> void CQUEUE<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template<typename T> T CQUEUE<T>::deletHead()
{
    if (stack2.empty()) {
        while (!stack1.empty()) {
            T node = stack1.top();
            stack2.push(node);
            stack1.pop();
        }
    }

    if (stack2.empty())
        throw runtime_error("queue is empty!");

    T node = stack2.top();
    stack2.pop();
    return node;
}
