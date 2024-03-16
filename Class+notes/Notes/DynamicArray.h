#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>

class vect{
    public:
        vect();
        vect(int);
        int size();
        void add(int);
        int operator[](int);
        friend std::ostream& operator<<(std::ostream &out,const vect &v);
        ~vect();
        vect(vect &v);
        vect operator=(const vect &v);
    private:
        int space;
        int sizes; 
        int* arr;
};

std::ostream& operator<<(std::ostream &out,const vect &v){
    out<<"{";
    for(int i=0;i<v.sizes;i++){
        out<<v.arr[i];
        if(i+1!=v.sizes){
            out<<",";
        }
    }
    out<<"}"<<std::endl;
    return out;
}

int vect::operator[](int x){
    if(x>sizes){
        x=sizes;
    }
    return arr[x];
}
vect::vect(){
    arr=new int[10];
    sizes=0;
    space=10;
}

vect::vect(int x){
    arr=new int[x];
    sizes=x;
    space=x;
    for(int i=0;i<x;i++){
        arr[i]=0;
    }
}

int vect::size(){
    return sizes;
}

void vect::add(int x){
    if(sizes==space){
        space=(space*2)+1;
        int *brr=new int[space];
        for(int i=0;i<sizes;i++){
            brr[i]=arr[i];
        }
        delete[]arr;
        arr=brr;
    }
    arr[sizes++]=x;
}

vect::~vect(){
    delete[]arr;
    std::cerr<<"DELETE\n";
}

vect::vect(vect &v){
    this->space=v.space;
    this->sizes=v.sizes;
    this->arr=new int[v.space];
    for(int i=0;i<sizes;i++){
        this->arr[i]=v.arr[i];
    }
    std::cerr<<"COPY\n";
}

vect vect::operator=(const vect &v){
    if(this==&v){
        return *this;
    }
    delete[]arr;
    this->space=v.space;
    this->sizes=v.sizes;
    this->arr=new int[v.space];
    for(int i=0;i<sizes;i++){
        this->arr[i]=v.arr[i];
    }
    std::cerr<<"ASSIGNMENT\n";
    return *this;
}

#endif