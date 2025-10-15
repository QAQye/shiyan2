#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cout;
class Battery
{
private:
    string parameter;
    string output;
    string charge_time;
public:
    Battery(string parameter = "24V/15Ah",string output = "24V",string charge_time = "2H");
    void setParameter(string parameter);
    void setOutput(string output);
    void setCarge_time(string charge_time);
    void print();
    void save(string url="./document/battery.txt",bool add=false);
};