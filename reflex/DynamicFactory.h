//c++反射类

#ifndef __DYNAMIC_FACTORY_H__  
#define __DYNAMIC_FACTORY_H__  
  
#ifdef __GNUC__  
#include <cxxabi.h>  
#endif  
  
#include <assert.h>  
#include <string.h>  
#include <stdlib.h>  
#include <map>  
#include <string>  
#include <typeinfo>  
#include <iostream>


using namespace std;


  
// 动态对象基类  
class DynamicObject  
{  
public:  
    DynamicObject() {}  
    virtual ~DynamicObject() {}  
};  
  
// 动态对象创建工厂  
class DynamicFactory  
{  
public:  
  
    typedef DynamicObject* (*CreateFunction)();  
  
    static DynamicFactory & Instance()  
    {  
        static DynamicFactory fac;  
        return fac;  
    }  
  
    // 解析类型名称（转换为 A::B::C 的形式）  
    static std::string ReadTypeName(const char * name)  
    {  
		cout << "entry ReadTypeName, name:" << name << endl;

	#ifndef __GNUC__  
	
        const char * p = strstr(name, " ");  
        if (p)  
        {  
            size_t prev_len = (size_t)(p - name);  
            if (memcmp(name, "class", prev_len) == 0 ||  
                memcmp(name, "struct", prev_len) == 0 ||  
                memcmp(name, "enum", prev_len) == 0 ||  
                memcmp(name, "union", prev_len) == 0)  
            {  
                p += 1;  
                return std::string(p);  
            }  
        }  
  
        return std::string(name);
		
	#else  
	
        char * real_name = abi::__cxa_demangle(name, nullptr, nullptr, nullptr);  
             std::string real_name_string(real_name);  
             free(real_name);  
		return real_name_string;  
		
	#endif  
    }  
  
    bool Regist(const char * name, CreateFunction func)  
    {  
        if (!func)  
        {  
            return false;  
        }  
        std::string type_name = ReadTypeName(name);
		cout << "type_name:" << type_name << endl;
		
        return _create_function_map.insert(std::make_pair(type_name, func)).second;  
    }  
  
    DynamicObject * Create(const std::string & type_name)  
    {  
        if (type_name.empty())  
        {  
            return NULL;  
        }  
  
        std::map<std::string, CreateFunction>::iterator it = _create_function_map.find(type_name);  
        if (it == _create_function_map.end())  
        {  
            return NULL;  
        }  
  
        return it->second();  
    }  
  
    template<typename T>  
    T * Create(const std::string & type_name)  
    {  
        DynamicObject * obj = Create(type_name);  
        if (!obj)  
        {  
            return NULL;  
        }  
		
        T * real_obj = dynamic_cast<T*>(obj);  
        if (!real_obj)  
        {  
            delete obj;  
            return NULL;  
        }  
		
        return real_obj;  
    }  
  
public:  
  
    std::map<std::string, CreateFunction> _create_function_map;  
};  


// 动态对象创建器  
template<typename T>  
class DynamicCreate : public DynamicObject  
{  
public:  
    static DynamicObject * CreateObject()  
    {  
        return new T();  
    }  

    struct Registor  
    {  
        Registor()  
        {  
			cout << "entry Registor()" << endl;

			if (!DynamicFactory::Instance().Regist(typeid(T).name(), CreateObject))  
            {  
                assert(false);  
            }  
        }  
  
        inline void do_nothing() const { }
    };  
  
    static Registor s_registor;  
  
public:
	
    DynamicCreate()  
    {  
        s_registor.do_nothing();  //这里必须调用s_registor的某个方法,否则编译器不会创建s_registor对象.模板类和非模板类不同，非模板类不用这样.
    }  
  
    virtual ~DynamicCreate()  
    {  
        s_registor.do_nothing();  
    }  
};  


template <typename T>  
typename DynamicCreate<T>::Registor DynamicCreate<T>::s_registor;  



#endif  