//
// Created by zhaoyue on 2020/11/11.
//

#include <atomic>

template<typename T>
struct node{
    T m_data;
    node* next = nullptr;
    node(const T& data) : m_data{data}{

    }
};

template<typename T>
class mystack{
public:
    void push(const T& data){
        node<T>* new_node{new node<T>(data)};
        // put the current value of head into new_node->next
        new_node->next = head.load(std::memory_order_relaxed);
        // now make new_node the new head, but if the head
        // is no longer what's stored in new_node->next
        // (some other thread must have inserted a node just now)
        // then put that new head into new_node->next and try again
        while (!head.compare_exchange_weak(new_node->next, new_node, std::memory_order_release, std::memory_order_relaxed)){
            ;// the body of the loop is empty
        }
        // Note: the above use is not thread-safe in at least
        // GCC prior to 4.8.3 (bug 60272), clang prior to 2014-05-05 (bug 18899)
        // MSVC prior to 2014-03-17 (bug 819819). The following is a workaround:
        //      node<T>* old_head = head.load(std::memory_order_relaxed);
        //      do {
        //          new_node->next = old_head;
        //       } while(!head.compare_exchange_weak(old_head, new_node,
        //                                           std::memory_order_release,
        //                                           std::memory_order_relaxed));

    }
private:
    std::atomic<node<T>*> head;
};

int main(){
    mystack<int>    s;
    s.push(1);
    s.push(2);
    s.push(3);
}