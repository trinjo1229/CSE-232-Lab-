#include<iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

double fn(double x){
    double x_value; 
    x_value = -6*(x*x) + (5*x) + 3;
    
    return x_value;
}

double integral(double x){
    double integral_val; 
    integral_val = -2*(x*x*x) + 2.5*(x*x) + (3*x);
    
    return integral_val;
}

double trapezoid(double a, double b, long n){
  double delta_x;
  double temp_v;
  double area=0;
  
  delta_x = (b - a) / n;
  double s = std::abs((fn(b)-fn(a))/2);
  temp_v = 0;
  
  for(int i=0; i<n;i++){
    temp_v=a+i*2*delta_x;
    
    area+=fn(temp_v);
  }
  
  return std::abs(area*s);  
}
int main(){
 double a;
 double b;
 double tolerance;
 long n;
 cin>>a>>b>>tolerance>>n;
while(true){
    double tolerance;
    double diff;
    double integralA=integral(a);
    double integralB=integral(b);
    double trap=trapezoid(a,b,n);
    double x=integralB-integralA;
    diff = std::abs(x-trap);
    cout<<std::fixed<<std::setprecision(4);
    if(diff < tolerance){
        cout<<"Trap count: "<<n<<", "<<"estimate:"<<trap<<", "<<"exact:"<<trap<<", "<<"tolerance:"<<tolerance<<endl;
        break;
    }
    else{
         cout<<"Intermeditate Result:"<<trap<<", "<<"traps:"<<n<<", "<<"diff:"<<diff<<endl;
         n*=2;
        
    }
    }
}