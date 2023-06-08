
#ifndef NEW_PROJ_USER_H
#define NEW_PROJ_USER_H

#include <iostream>
#include <string>

class User{
private:
    int m_age;
    std::string m_name;
public:
    User(std::string, int);

    std::string get_name();
};


#endif //NEW_PROJ_USER_H
