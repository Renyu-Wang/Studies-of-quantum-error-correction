#include<iostream>
#include<itpp/itbase.h>
#include<cmath>

//compile: g++ `itpp-config --cflags` -o mat matrix.cpp `itpp-config --libs` for itpp lib

int main(){
    int n = 10, a = 1, b = 3, c = 0;
    itpp::mat gr(n,2*n);
    itpp::vec g(2*n);

    g.zeros();
    gr.zeros();

    for (int i = 0; i < n; i++){
        g(i%n) = 1;
        g((i+2*a+b)%n) = 1;
        g((i+a)%n+n) = 1;
        g((i+a+b)%n+n) = 1;

        gr.set_row(i,g);
        g.zeros();
    }

    //std::cout << gr << "\n";

    int m = n;

    for (int i = 0; i < m; i++){ 

        for (int j = 0; j < m; j++){ 

            if (i != j){

                c = 0;
                g.zeros();

                for (int k = 0; k < 2*n; k++){
                
                    g(k) = ( (int)gr(i,k) + (int)gr(j,k) ) % 2;
                
                }               

                for (int l = 0; l < m; l++){

                    if (g == gr.get_row(l)){
                        c = c + 1;
                    }
     
                } 

                if (c == 0){
                    m = m + 1;
                    gr.set_size(m, 2*n, true);
                    gr.set_row(m-1,g);
                }
            }
            
        }
    }

    std::cout << "m = " << m << "\n";
    std::cout << "There are" << log2(m+1) << "Independent generaters." << "\n";
}






