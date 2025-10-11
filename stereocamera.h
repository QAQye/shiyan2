#pragma once
#include "tire.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
class StereoCamera{
    public:
        StereoCamera(string model = "RealSense D435i",string camera = "D430",string rgb_resolution = "1920*1080",
        int rgb_fps = 30,string fov = "87*58",int depth_fps = 90);
        void setModel(string model);
        void setCamera(string camera);
        void setRgb_resolution(string rgb_resolution);
        void setRgb_fps(int rgb_fps);
        void setFov(string fov);
        void setDepth_fps(int depth_fps);
        void print();
        void save(string url="./document/stereocamera.txt",bool add=false);
    private:
        string model = "RealSense D435i";
        string camera = "D430";
        string rgb_resolution = "1920*1080";
        int rgb_fps = 30;
        string fov = "87*58";
        int depth_fps = 90;
};