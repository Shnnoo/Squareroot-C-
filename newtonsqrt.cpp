#include<iostream>
#include<iomanip>
using namespace std;
double pow(double, int);
double absolute(double);
double sqrt(double) ;
double guess(double);

int main()
{
    double x;
    cout<<"Enter the value you want its roots: "<<setprecision(16);
    cin>>x;
    cout<<sqrt(x)<<"\n";
    return 0;
}

double pow(double x, int n)
{
    /* r = x*x*x*x*x*x*x...... n times */
    double r =1;
    for(;0<n;n--) r *=x; //for not taking too much of space from memory
    return r;
}
double absolute(double n)
{
    n = (n>0)? n: n*-1;
    return n;
}
double sqrt(double a)    // a is the number we looking for its root sqrt(a)
{
    double t,x=guess(a); // t is an temprory variable to compare the value after the method and before
                    // x the root value which change contiously till reach and certain amount the intialization is 1
                    // but by guessing it will take less time
    do
    {
        t=x;
        x=(x*x+a)*1.0/(2*x);
    }while( !(t == x)  && !(absolute(t-x) <= 0.0000000000000009) );
    return x;
}
double guess(double a)
{
    int i=1;
    while (int(a)%int(pow((i+1),2)) == int(a)) i++;

    return (i*i-a>i)? i+1:i;
}