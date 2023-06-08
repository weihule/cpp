#include <iostream>
#include <string>
#include <exception>

class MyString{
public:
    MyString(const char* str){

    }

    // 防止利用隐式类型转换的方式来初始化对象
    explicit MyString(int ){

    }
};

class Point{
public:
    int x,y;
    explicit Point(int x=1,int y=2):x(x), y(y){}
};

void display(const Point& p){
    std::cout << "p.x = " << p.x << "\tp.y = " << p.y << std::endl;
}

void test01(){
    MyString ms("abcd");
    MyString ms2(10);

    // MyString ms3 = 10;

    display(Point(1));
}

void test02(){
    char a = '1';
    auto b = static_cast<double>(a);
    std::cout << "b = " << b << std::endl;
}

class Base{
public:
    virtual void func() = 0;
};
class Son:public Base{
    void func() override{
        std::cout << "Son was recalled" << std::endl;
    }
};
class Other{};

void test03(){
    Base* base = new Son;
    Son* son = nullptr;

    // 上行转换(son -> base)
    auto base2 = static_cast<Base*>(son);

    // 下行转换(base -> son), 不安全, CLion会提示
    // 如果发生了多态，那么转换总是安全的
    auto son2 = dynamic_cast<Son*>(base);
}

void test04(){
    const int*p = nullptr;
    int* np = const_cast<int*>(p);

    int* p2 = nullptr;
    const int* np2 = const_cast<int*>(p2);

    // 不能对非指针或引用转换
    const int a = 10;
    // int b = const_cast<int>(a);
}


class Person{
public:
    explicit Person(int a){
        m_a = a;
        std::cout << m_a << "Person default constructor was recalled" << std::endl;
    }

    ~Person(){
        std::cout << m_a << "Person default destructor was recalled" << std::endl;
    }

    int m_a;
};

double myDivision(double a, double b){
    if(b == 0){

        Person p1(10);
        Person p2(20);

        throw (double)-1;
    }
    return a / b;
}

void test05(){
    try{
        double res = myDivision(10, 0);
        std::cout << "res = " << res << std::endl;
    }
    catch(double){
        std::cout << "double exception" << std::endl;
    }
}

class MyException{
public:
    MyException(){
        std::cout << "MyException constructor was recalled" << std::endl;
    }

    MyException(const MyException&){
        std::cout << "MyException copy constructor was recalled" << std::endl;
    }

    ~MyException(){
        std::cout << "MyException destructor was recalled" << std::endl;
    }
};

void doWork(){
    throw MyException();
}

void test06(){
    try{
        doWork();
    }
    // 这里是拷贝构造（为提高代码效率，改引用传递）
    // catch(MyException e)
    catch(MyException &e)
    {
        std::cout << "Custom Exception catch" << std::endl;
    }
}

class CustomException:public std::exception{
public:
    explicit CustomException(const char* str){
        // const char* 可以隐式类型转换为string，反之不行
        this->m_error = str;
    }

    [[nodiscard]] const char *what() const noexcept override{
        return this->m_error.c_str();
    }
private:
    std::string m_error;
};

class People{
public:
    int m_age;
    explicit People(int age){
        if (age < 0 || age >= 150){
            throw CustomException("Age must be between 0 and 150 years old");
        }
        this->m_age = age;
    }
};

void test07(){
    try{
        People p(170);
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
}

void test08(){
    // string -> const char* 需要借助c_str()来实现
    std::string str1 = "hello world";
    const char* c_str1 = str1.c_str();
    std::cout << (*c_str1) << std::endl;

    // const char* -> string 直接可以隐式转换
    const char* c_str2 = "yes or no";
    std::string str2 = c_str2;
    std::cout << (str2) << std::endl;
}

void test09(){
    char a = std::cin.get();
    // std::cin.putback(a);

    char buf[1024] = {0};
    // std::cin.getline，换行符不在缓冲区，也不会被buf取走，而是直接扔掉
    std::cin.getline(buf, 1024);

    // 验证我们的回车符是否还在缓冲区
//    char a = std::cin.get();
//    if (a == '\n'){
//        std::cout << "enter remained" << std::endl;
//    }
//    else{
//        std::cout << "enter not remained" << std::endl;
//    }

    std::cout << buf << std::endl;
}

void test10(){
    std::string str = "hello world";

    for (int i = 0; i < str.size(); i++){
        std::cout << i << " " << str[i] << " " << str.at(i) << std::endl;
    }
}

void test11(){
    std::string str = "he is@ a@ good boy";
    str = str.replace(str.find('a'), 2, "#");
    std::cout << str << std::endl;
}

int main(){
    test11();

    std::cin.get();
    return 1;
}
