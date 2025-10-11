#include "stereocamera.h"
#include <fstream>
using std::endl;
using std::ios;
using std::ofstream;
 StereoCamera::StereoCamera(string model,string camera,string rgb_resolution,
        int rgb_fps,string fov,int depth_fps ):model(model),camera(camera),rgb_resolution(rgb_resolution),
        rgb_fps(rgb_fps),fov(fov),depth_fps(depth_fps){

        }
        void StereoCamera::setModel(string model){
            this->model=model;
        }
        void StereoCamera::setCamera(string camera){
            this->camera=camera;
        }
        void StereoCamera::setRgb_resolution(string rgb_resolution){
            this->rgb_resolution=rgb_resolution;
        }
        void StereoCamera::setRgb_fps(int rgb_fps){
            this->rgb_fps=rgb_fps;
        }
        void StereoCamera::setFov(string fov){
            this->fov=fov;
        }
        void StereoCamera::setDepth_fps(int depth_fps){
            this->depth_fps=depth_fps;
        }
        void StereoCamera::print(){
            cout << "双目摄像头: " <<  endl;
            cout << "  型号: " << model << endl;
            cout << "  摄像头: " << camera << endl;
            cout << "  RGB帧分辨率: " << rgb_resolution<< endl;
            cout << "  RGB帧率: " << rgb_fps<< endl;
            cout << "  FOV: " << fov<< endl;
            cout << "  深度帧率: " << depth_fps<< endl;
        }
        void StereoCamera::save(string url,bool add){
            ofstream ofs;
            if(add){
                ofs.open(url,ios::app);
            }
            else{
                ofs.open(url);
            }
            if(!(ofs.is_open())){
                cout<<"文件打开文件失败，无法保存数据"<<endl;
            }
            ofs << "双目摄像头: " <<  endl;
            ofs << "  型号: " << model << endl;
            ofs << "  摄像头: " << camera << endl;
            ofs << "  RGB帧分辨率: " << rgb_resolution<< endl;
            ofs << "  RGB帧率: " << rgb_fps<< endl;
            ofs << "  FOV: " << fov<< endl;
            ofs << "  深度帧率: " << depth_fps<< endl;
        }