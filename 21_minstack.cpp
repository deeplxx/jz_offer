#include <stack>
#include <stdexcept>
#include <cassert>

template<typename T> struct MinStack {
    std::stack<T> m_data;
    std::stack<T> m_min;

    void push(const T& value);
    void pop();
    T min();
};

template<typename T> void MinStack<T>::push(const T& value)
{
    m_data.push(value);

    if (m_min.size() == 0 || value < m_min.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
}

template<typename T> void MinStack<T>::pop()
{
//    if (m_data.size() == 0)
//        throw std::runtime_error("stack is already empty!");
    assert (m_data.size() > 0);

    m_data.pop();
    m_min.pop();
}

template<typename T> T MinStack<T>::min()
{
    assert(m_data.size() > 0);

    return m_min.top();
}

