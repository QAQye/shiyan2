#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::string;
class Tire{
    public:
        Tire(string model="公路轮/麦克纳姆轮",string size="175mm");
        void setModel(string model);
        void setSize(string size);
        void print();
        void save(string url="./document/tire.txt",bool add=false);
    private:
        string model;
        string size;
};