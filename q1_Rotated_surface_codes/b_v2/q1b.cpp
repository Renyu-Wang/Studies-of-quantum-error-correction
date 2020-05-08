#include<iostream>
#include<tuple>             //for multiple returens of a function
#include <itpp/itbase.h>    //for vectors and matrixes
#include <chrono>           //for showing run-time
#include "q1b_func.hpp"     //separation of functions from main file
//#include <itpp/base/gf2mat.h> //for binary matrix

//compile with g++ -std=c++11 `itpp-config --cflags` q1b_func.cpp q1b.cpp -o q1b `itpp-config --libs`

int main(int argc, char **argv){
    itpp::Parser parser;
    parser.init(argc,argv);
    int a = 1, b = 2, n = 6;
    parser.get(a,"a");
    parser.get(b,"b");
    parser.get(n,"n");

    int r = 0;
    //std::tie(a, b, n) = input();
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
        itpp::GF2mat gr(n,2*n);
        gr = write_gs(a, b, n);
        //r = num_indep(a, b, n, gr);
        r = gr.row_rank();
        std::cout << "There are " << r << " Independent generaters." << "\n";
        std::cout << "There is(are) " << n-r << " encoded qubit(s)." << "\n";
    }
    //end recording calculation time
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    //show run-time
    std::chrono::duration<double, std::milli> time_span = (end - start)/1000;
    std::cout << "Run-time " << time_span.count() << " seconds.\n";
}
