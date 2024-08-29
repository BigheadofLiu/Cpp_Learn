#include<iostream>  
using namespace std;
class cpu{
    public:
    virtual void cpu_run()=0;
};

class gpu{
     public:
    virtual void gpu_run()=0;
};

class ram{
     public:
    virtual void ram_run()=0;
};

class intel_cpu:public cpu{
    void cpu_run(){
        cout<<"intel CPU正在工作"<<endl;
    }
};
class amd_cpu:public cpu{
    void cpu_run(){
        cout<<"amd CPU正在工作"<<endl;
    }
};
class inter_gpu:public gpu{
    void gpu_run(){
        cout<<"intel GPU正在工作"<<endl;
    }
};
class invida_gpu:public gpu{
    void gpu_run(){
        cout<<"invida GPU正在工作"<<endl;
    }
};
class sdisk_ram:public ram{
    void ram_run(){
        cout<<"Sdisk ram正在工作"<<endl;
    }
};
class sumsung_ram:public ram{
    void ram_run(){
        cout<<"sumsung ram正在工作"<<endl;
    }
};

class computer{
    public:
    computer(cpu *cpu,gpu *gpu,ram *ram){ //
    m_cpu=cpu;
    m_gpu=gpu;
    m_ram=ram;
    }
    void do_work(){
    m_cpu->cpu_run();
    m_gpu->gpu_run();
    m_ram->ram_run();
    }
    ~computer(){
        if (m_cpu!=NULL)
        {
            delete m_cpu;
            /* code */
        }
        if (m_gpu!=NULL)
        {
            delete m_gpu;
            /* code */
        }
        if (m_ram!=NULL)
        {
            delete m_ram;
            /* code */
        }
        
    }
    cpu *m_cpu;
    gpu *m_gpu;
    ram *m_ram;
};
void test(){
    cpu * intel =new intel_cpu;
    cpu * amd =new amd_cpu;
    gpu * invida=new invida_gpu;
    gpu * intel_gpu=new inter_gpu;
    ram *sdisk=new sdisk_ram;
    ram *sumsung =new sumsung_ram;

    computer c1(intel,invida,sumsung); //通过实例化对象的方式
    c1.do_work(); 
    cout<<"------------------------------------"<<endl;
    computer *c2=new computer(amd,invida,sdisk); //通过指针开辟堆区内存的方式
    c2->do_work();
    delete c2;
    cout<<"------------------------------------"<<endl;
    computer *c3=new computer(new amd_cpu,new inter_gpu,new sumsung_ram); //直接使用new开启
    c3->do_work();
    c3=NULL;
    delete c3;
};
int main(){
    test();

}