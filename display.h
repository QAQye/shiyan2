#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cout;
class Display{
    public:
    Display(string size = "11.6",string model = "super");
    void setSize(string size);
    void setModel(string model);
    void print();
    void save(string url="./document/display.txt",bool add=false);
    private:
        string size ;
        string model ;
};