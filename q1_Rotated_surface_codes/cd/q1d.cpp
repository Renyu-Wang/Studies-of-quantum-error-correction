#include<iostream>
#include<cmath>
#include<tuple>             //for multiple returens of a function
#include <itpp/itbase.h>    //for vectors and matrixes
#include <chrono>           //for showing run-time
#include "q1d_func.hpp"     //separation of functions from main file
//#include <itpp/base/gf2mat.h> //for binary matrix

//compile with 

int main(int argc, char **argv){
    itpp::Parser parser;
    parser.init(argc,argv);
    int a = 1, b = 1, n = 5;
    parser.get(a,"a");
    parser.get(b,"b");
    parser.get(n,"n");

    //std::tie(a, b, n) = input();
    //start recording calculation time
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    //input value of a, b, n and check if they fit the conditions
    if (2*a+b >= n && n > 30){
        std::cout << "Violate condition (2a+b < n) or (n <= 30).\n";
        
        std::tie(a, b, n) = input();
    }
   
    else{
        //find locations that shows same number
        itpp::mat loc(n,2);
        loc = write_l(a, b, n);
        std::cout << loc << "\n";
        
        //calculate distance of the locations
        itpp::vec d2(n-1);
        int x, y, d;
        for (int i=0; i<n-1; i++){
            x = loc(i+1,0)-loc(i,0);
            y = loc(i+1,1)-loc(i,1);
            d2(i) = pow(x, 2) + pow(y,2);
        }

        //find the distance of the code
        if ( (x+y)%2 == 0 ){
           d =  y;
        }
        else{
            d = abs(x + y);
        }
        std::cout << d2 << "\n";
        std::cout << d << "\n";

        
    }
    //end recording calculation time
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    //show run-time
    std::chrono::duration<double, std::milli> time_span = (end - start)/1000;
    std::cout << "Run-time " << time_span.count() << " seconds.\n";
}
