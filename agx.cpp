#include "agx.h"
#include <fstream>
using std::ofstream;
using std::ios;
using std::cout;
using std::endl;
Agx::Agx(string model,string ai,int cuda_core,int tensor_cores,
        string vram,string storage ):
        model(model),ai(ai),cuda_cores(cuda_cores),tensor_cores(tensor_cores),vram(vram),storage(storage){}
void Agx::setModel(string model){
    this->model=model;
}
void Agx::setAI(string ai){
    this->ai=ai;
}
void Agx::setCuda_cores(int cuda_cores){
    this->cuda_cores=cuda_cores;
}
void Agx::setTensor_cores(int tensor_cores){
    this->tensor_cores=tensor_cores;
}
void Agx::setVarm(string varm){
    this->vram=varm;
}
void Agx::setStorage(string storage){
    this->storage=storage;
}
void Agx::print(){
    cout << "AGX套件: " <<  endl;
    cout << "  AGX套件型号: " << model << endl;
    cout << "  AI: " << ai << endl;
    cout << "  CUDA核心: " << cuda_cores << endl;
    cout << "  Tensor CORE: " << tensor_cores << endl;
    cout << "  显存: " << vram << endl;
    cout << "  存储: " << storage << endl;

}
void Agx::save(string url,bool add){
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
    ofs << "AGX套件: " <<  endl;
    ofs << "  AGX套件型号: " << model << endl;
    ofs << "  AI: " << ai << endl;
    ofs << "  CUDA核心: " << cuda_cores << endl;
    ofs << "  Tensor CORE: " << tensor_cores << endl;
    ofs << "  显存: " << vram << endl;
    ofs << "  存储: " << storage << endl;   
}