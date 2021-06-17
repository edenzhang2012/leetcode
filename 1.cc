/*
如下为类型CMyString的声明，请为该类型添加赋值运算符函数
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
        if(this == &str)
            return *this;
        
        delete []m_pData;
        m_pData = NULL;

        m_pData = new char[strlen(str.m_pData) + 1];
        strncpy(m_pData, str.m_pData);
        return *this;
    }
private:
    char *m_pData;
};