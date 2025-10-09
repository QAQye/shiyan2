#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::string;
class Tire{
    public:
        Tire();
        Tire(string model,string size);
        void setModel(string model);
        void setSize(string size);
        void printinfo();
        void saveToDocument();
    private:
        string model="公路轮/麦克纳姆轮";
        string size="175mm";
};