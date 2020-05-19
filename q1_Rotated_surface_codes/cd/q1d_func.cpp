#include<iostream>
#include<tuple>
#include <itpp/itbase.h>
//#include <itpp/base/gf2mat.h>

//input value of a, b, n
std::tuple<int, int, int> input(){

    int a2, b2, n2;
    std::cout << "Enter the value of a = \n";
    std::cin >> a2;
    std::cout << "Enter the value of b = \n";
    std::cin >> b2;
    std::cout << "Enter the value of n = \n";
    std::cin >> n2;

    return std::make_tuple(a2, b2, n2);
} 

//write the n gs
itpp::GF2mat write_gs(int a3,int b3, int n3){

    itpp::GF2mat gr(n3,2*n3);
    itpp::bvec g(2*n3);

    g.zeros();
    //gr.zeros();

    for (int i = 0; i < n3; i++){
        g(i%n3) = 1;
        g((i+2*a3+b3)%n3) = 1;
        g((i+a3)%n3+n3) = 1;
        g((i+a3+b3)%n3+n3) = 1;

        gr.set_row(i,g);
        //std::cout << "g = " << g.left(n) << "|" << g.right(n) << "\n";
        g.zeros();
    }

    return gr;
}

//write lattice 
itpp::mat write_l(int a4,int b4, int n4){

    itpp::mat l(n4,n4);
    itpp::mat loc(n4,2);
    l.zeros();
    int k = 0;

    for (int i = n4-1; i >= 0 ; i--){
        for (int j = 0; j < n4; j++){
            l(i,j) = (1 + j*a4 + ((n4-1)-i)*(a4+b4))%n4; 
            if (l(i,j)==1){
                k = k + 1;
                loc(k-1,0) = i;
                loc(k-1,1) = j;
            }       
        }
    }

    std::cout << l << "\n";
    return loc;
}

//find the number of indipendent generators
double num_indep(int a4, int b4, int n4, itpp::GF2mat gr2){

    int m = n4;
    int c = 0;
    itpp::bvec g(2*n4);

    for (int i = 0; i < m; i++){ 

        for (int j = 0; j < m; j++){ 

            if (i != j){

                c = 0;
                g.zeros();

                for (int k = 0; k < 2*n4; k++){
                
                    g(k) = ( (int)gr2(i,k) + (int)gr2(j,k) ) % 2;
                
                }               

                for (int l = 0; l < m; l++){

                    if (g == gr2.get_row(l)){
                        c = c + 1;
                    }
     
                } 

                if (c == 0){
                    m = m + 1;
                    gr2.set_size(m, 2*n4, true);
                    gr2.set_row(m-1,g);
                }
            }
            
        }
    }

    return log2(m+1); 

}