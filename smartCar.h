#pragma once
#include <iostream>
#include "agx.h"
#include "battery.h"
#include "chassis.h"
#include "display.h"
#include "imu9.h"
#include "lidar.h"
#include "stereocamera.h"
using std::cout;
class Smartcar{
    public:
        Smartcar();
        Smartcar(string id,Chassis chassis,Agx agx,StereoCamera camera,Lidar lidar,IMU9 imu,
        Display display,Battery battery);
        string alloctId();
        void setId(string id);
        void print();
        void save(string url="./document/smartcar.txt",bool add=false);
    private:
        string id;
        Chassis chassis;
        Agx agx;
        StereoCamera camera;
        Lidar lidar;
        IMU9 imu;
        Display display;
        Battery battery;
};
