#include<iostream>
#include<tuple>             //for multiple returens of a function
#include <itpp/itbase.h>    //for vectors and matrixes
#include <chrono>           //for showing run-time
#include "q1b_func.hpp"     //separation of functions from main file

//compile with g++ -std=c++11 `itpp-config --cflags` q1b_func.cpp q1b.cpp -o q1b `itpp-config --libs`

int main(){

    int a = 0, b = 0, n = 0;
    std::tie(a, b, n) = input();
    //start recording calculation time
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    //input value of a, b, n and check if they fit the conditions
    if (2*a+b >= n && n > 30){
        std::cout << "Violate condition (2a+b < n) or (n <= 30).\n";
        
        std::tie(a, b, n) = input();
    }
    //find the number of indipendent generators
    else{
        //std::cout << "The gs are: " << write_gs(a, b, n) << "\n";
        itpp::mat gr(n,2*n);
        gr = write_gs(a, b, n);
        std::cout << "There are " << num_indep(a, b, n, gr) << " Independent generaters." << "\n";
    }
    //end recording calculation time
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    //show run-time
    std::chrono::duration<double, std::milli> time_span = (end - start)/1000;
    std::cout << "Run-time " << time_span.count() << " seconds.\n";
}
