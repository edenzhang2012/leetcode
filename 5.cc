/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

#include <iostream>
#include <stack>

class my_queue{
public:
    void Push(int data){
        s1.push(data);
    }

    int Pop(){
        int tmp;
        if(!s2.empty()){
            tmp = s2.top();
            s2.pop();
        }else{
            while(!s1.empty()){
                tmp = s1.top();
                // std::cout << " trans " << tmp << std::endl;
                s1.pop();
                s2.push(tmp);
            }

            tmp = s2.top();
            // std::cout << " push " << tmp << std::endl;
            s2.pop();
        }
        return tmp;
    }

private:
    std::stack<int> s1;
    std::stack<int> s2;
};

int main(){
    my_queue m;

    m.Push(1);
    m.Push(2);
    std::cout << "pop " << m.Pop() << std::endl;
    m.Push(3);
    m.Push(4);
    // std::cout << "pop " << m.Pop() << std::endl;
    std::cout << "pop " << m.Pop() << std::endl;
    std::cout << "pop " << m.Pop() << std::endl;
    std::cout << "pop " << m.Pop() << std::endl;

    return 0;
}