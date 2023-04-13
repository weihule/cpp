#include <iostream>
#include <string>
#include <cstring>

#include "user.h"

void run(){
    std::cout << "hello111" << std::endl;
    auto *user = new User("tom", 23);
    std::string name = user->get_name();
    std::cout << "name = " << name << std::endl;
}

void test(){
    int arr[5];
    memset(arr, 0, sizeof arr);
    std::cout << sizeof(arr) << std::endl;
    std::cout << sizeof(arr) / sizeof(arr[0]) << std::endl;
}

int main() {
    run();
    test();
    return 0;
}
