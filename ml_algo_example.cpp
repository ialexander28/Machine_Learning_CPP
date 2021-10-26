#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
  
// This header file contains all C++ libraries
// stdout library for printing values 
bool custom_sort(double a, double b) /* this custom sort function sorts based on the minimum absolute value */
{
    double a1=abs(a-0);
    double b1=abs(b-0);
    return a1<b1;
}
int main()
{
/*Intialization Phase*/
double x[] = {1, 2, 3, 4, 5};    // defining x values
double y[] = {1, 3, 3, 2, 5};    // defining y values
std::vector<double>error;             // array to store all error values
double devi;
double b0 = 0;                   //initializing b0
double b1 = 0;                   //initializing b1
double learnRate = 0.01;             //initializing error rate
 
/*Training Phase*/
for (int i = 0; i < 20; i ++) {   // Since there are five values and four epochs are needed, run a for loop 20 times.
    int index = i % 5;              // This accesses the index after each epoch
    double p = b0 + b1 * x[index];  // calculating prediction
    devi = p - y[index];              // calculating error
    b0 = b0 - learnRate * devi;         // updating b0
    b1 = b1 - learnRate * devi * x[index];// updating b1
    std::cout<<"B0="<<b0<<" "<<"B1="<<b1<<" "<<"error="<<devi<< '\n';// printing values after every update
    error.push_back(devi);
}
sort(error.begin(),error.end(),custom_sort); // error values used to sort the data
std::cout<<"Optimal end values are: "<<"B0="<<b0<<" "<<"B1="<<b1<<" "<<"error=" <<error[0] << '\n';

/*Testing Phase*/
std::cout<<"Enter a test x value";
double test;
std::cin>>test;
double pred=b0+b1*test;
std::cout<< '\n';
std::cout<<"The value predicted by the model= "<<pred;

}