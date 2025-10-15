#pragma once
#include <string>
#include <iostream>
using std::string;
using std::cout;
class IMU9{
    public:
        IMU9(string model = "CH110",string vendor = "NXP");
        void setModel(string model);
        void setVendor(string vendor);
        void print();
        void save(string url="./document/imu9.txt",bool add=false);
    private:
        string model;
        string vendor;
        
};