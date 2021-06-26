/*
如下为类型CMyString的声明，请为该类型添加赋值运算符函数
*/

/*
重载赋值运算符注意以下几点：
1. 返回值的类型要声明为该类型的引用，以支持连续赋值
2. 传入参数类型声明为常量引用，防止修改源数据同时防止传参时的赋值
3. 释放实例自身原有的内存，防止内存泄漏
4. 判断传入参数是否时实例自身，防止释放实例自身原有内存后传参的数据不可用
5. 考虑异常，实例申请新的内存失败时怎么办？原有的内存被释放掉，新的数据又无法复制过
    来，此时会导致实例原有数据丢失，需要单独处理
*/

#include <iostream>
#include <string.h>


class CMystring{
public:
    CMystring(char *data = NULL){
        m_pData = data;
    }
    CMystring(const CMystring& str){
        m_pData = str.m_pData;
    }
    ~CMystring(void);

    CMystring& CMystring::operator=(const CMystring& str){
        if(this != &str){
            //临时变量，if执行完就会自动调用析构函数
            CMystring temp(str);

            char *ptmp = temp.m_pData;
            temp.m_pData = m_pData;//将实例的数据内容指针赋值给临时变量
            m_pData = ptmp;
        }//析构临时变量时，顺带释放实例的数据内容

        return *this;
    }
private:
    char *m_pData;
};

int main(){

    return 0;
}