#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;
class Lidar{
    public:
        Lidar(string model = "RS-Helios-16p",int channels = 16,string range_m = "100m",string power = "8W");
        void setModel(string model);
        void setChannels(int channels);
        void setRange_m(string range_m);
        void setPower(string power);
        void print();
        void save(string url="./document/lidar.txt",bool add=false);
    private:
        string model;
        int channels;
        string range_m;
        string power;
};