#pragma once
#include "tire.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
class Student{
    public:
        Student(string id,string name);
        void setId(string id);
        void setName(string name);
        void print();
        void save(string url);
    private:
        std::string id;
        std::string name;
};