#pragma once
#include "tire.h"
#include <vector>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::vector;
class Chassis{
    public:
        Chassis(string id="",string model= "SCOUT MINI",int wheelbase_mm = 451,int track_mm = 490,int min_clearance_mm = 115,int min_turn_radius = 0,
        string drive = "四轮四驱",string max_range = "10KM");
        void setId(string id);
        void setModel(string model);
        void setWheelbase_mm(int wheelbase_mm);
        void setTrack_mm(int track_mm);
        void setMin_clearance_mm(int min_clearance_mm);
        void setMin_turn_radius(int min_turn_radius);
        void setDrive(string drive);
        void setMax_range(string max_range);
        string allocateid();
        void print();
        void save(string url="./document/chassis.txt",bool add=false);
    private:
        string id;
        string model;
        int wheelbase_mm;
        int track_mm;
        int min_clearance_mm;
        int min_turn_radius;
        string drive;
        string max_range;
        vector<Tire *> tires;
};