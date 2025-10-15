#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;
class Agx{
    public:
        Agx(string model = "AGX Xavier",string ai = "32 TOPS",int cuda_cores = 512,int tensor_cores = 64,
        string vram = "32G",string storage = "32G");
        void setModel(string model);
        void setAI(string ai);
        void setCuda_cores(int cuda_cores);
        void setTensor_cores(int tensor_cores);
        void setVarm(string varm);
        void setStorage(string storage);
        void print();
        void save(string url="./document/agx.txt",bool add=false);
    private:
        string model ;
        string ai;
        int cuda_cores;
        int tensor_cores;
        string vram;
        string storage ;
};