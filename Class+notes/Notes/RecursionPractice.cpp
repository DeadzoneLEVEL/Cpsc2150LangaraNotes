#include <iostream>
#include <vector>
#include <cmath>

void forward(int n);
void backward(int n);
int sumR(int n);
int sumDigits(int n);
int maxR(const std::vector<int> &v,int i = 0);
void revV(std::vector<int> &v,int i = 0);

void forward(int n){
    if(n==-1){
        return;
    }
    forward(n-1);
    std::cout<<n<<" ";
}
void backward(int n){
    if(n==-1){
        return;
    }
    std::cout<<n<<" ";
    backward(n-1);
}

int sumR(int n){
    if(n<=0){
        return 0;
    }
    return n+sumR(n-1);
}
int sumDigits(int n){
    if(n<=0){
        return 0;
    }
    // std::cout<<n%10<<"\n";
    return (n%10)+sumDigits(n/10);
}

int maxR(const std::vector<int> &v,int i){
    if(i==v.size()-1){
        return v[i];
    }
    int result=maxR(v,i+1);
    if(v[i]>result){
        result=v[i];
    }
    return result;
}

void revV(std::vector<int> &v,int i ){
    if(i==(v.size()-1)/2){
        return;
    }
    int tmp=v[i];
    v[i]=v[(v.size()-1)-i];
    v[(v.size()-1)-i]=tmp;
    revV(v,i+1);
}

int fib(int n){
    if(n<=1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}

int gcd(int m,int n){
    if(m%n==0){
        return n;
    }
    gcd(n,m%n);
}
double sumSeries(double i){
    if(i==double(1)){
        return double(1);
    }
    std::cout<<1/i<<std::endl;
    return (double(1)/i)+(double(1)/sumSeries(i-double(1)));
}

int main(){
//   int n;
//   std::vector<int> v = {3,16,2,19,7,11,3};
//   std::cout <<"Enter an positive integer:";
//   std::cin >> n;
//   forward(n);
//   std::cout << std::endl;
//   backward(n);
//   std::cout << std::endl; 
//   std::cout << sumR(n) << std::endl;
//   std::cout <<"Enter an positive integer:";
//   std::cin >> n;
//   std::cout << sumDigits(n) << std::endl;
//   std::cout << "Max in vector = " << maxR(v) << std::endl; 
//   std::cout << "[";
//   for(auto i:v){
//     std::cout << i << ",";
//   }  
//   std::cout << "]" << std::endl;
//   revV(v);
//   std::cout << "The vector is now reversed" << std::endl;
//   std::cout << "[";
//   for(auto i:v){
//     std::cout << i << ",";
//   }  
//   std::cout << "]" << std::endl;

//   std::cout<<gcd(12,24)<<std::endl;
    // for(int i=1;i<=10;i++){
    //     std::cout<<i<<": ";
    //     std::cout<<sumSeries(i)<<std::endl;
    // }
    std::cout<<"This:"<<sumSeries(3)<<std::endl;
  return 0; 
   
}