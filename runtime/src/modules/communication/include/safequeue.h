#ifndef SAFE_QUEUE_H
#define SAFE_QUEUE_H

#include <queue>
#include <condition_variable>
#include <mutex>
#include <algorithm>

template <class T>
class SafeQueue
{
public:
    SafeQueue() : m_mutex(), m_queue(), m_condition() {}
    ~SafeQueue() {}

    void append(T t) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_queue.push(std::move(t));
        m_condition.notify_one();
    }

    T dequeue() {
        std::unique_lock<std::mutex> lock(m_mutex);
        while (m_queue.empty())
            m_condition.wait(lock);
        T val = m_queue.front();
        m_queue.pop();
        return val;
    }

    void clear() {
        std::unique_lock<std::mutex> lock(m_mutex);
        std::queue<T> empty;
        std::swap(m_queue, empty);
    }

private:
    mutable std::mutex m_mutex;
    std::queue<T> m_queue;
    std::condition_variable m_condition;
};

#endif
