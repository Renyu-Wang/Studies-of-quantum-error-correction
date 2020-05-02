//g[i] = X[i]Z[i+a]Z[i+a+b]X[i+2a+b]
//g[j] = X[j]Z[j+a]Z[j+a+b]X[j+2a+b]
//acw = anticommute with, cw = commute with


#include <iostream>

int i, j, a, b;

case (a = b) {

    if 1 (j == i+a) {
        //X[i]..Z[i+a]..Z[i+a+b]..X[i+2a+b]
        //......X[j]....Z[j+a]....Z[j+a+b]...X[j+2a+b]
        X[j]        acw     Z[i+a]
        Z[j+a]      cw      Z[i+a+b]
        Z[j+a+b]    acw     X[i+2a+b]

        rest X, Z cw I => g[i] cw g[j]
    }

    if 2 (j == i+a+b) {
        //X[i]..Z[i+a]..Z[i+a+b]..X[i+2a+b]
        //..............X[j]......Z[j+a]....Z[j+a+b]...X[j+2a+b]
        X[j]        acw     Z[i+a+b]
        Z[j+a]      acw      Z[i+2a+b]

        rest X, Z cw I => g[i] cw g[j]
    }

    if 3 (j+2a+b == i+a){
        //................X[i].......Z[i+a]...Z[i+a+b]...X[i+2a+b]
        //X[j]...Z[j+a]...Z[j+a+b]...X[j+2a+b]
        => switch i ,j = if 2
    }

    if 4 (j+2a+b == i+a){
        //........X[i]....Z[i+a]....Z[i+a+b]..X[i+2a+b]
        //X[j]....Z[j+a]..Z[j+a+b]..X[j+2a+b]
        => switch i ,j = if 1
    }


}
case (a != b) {

    if 1 (j == i + a) {
        //X[i]..Z[i+a]....Z[i+a+b]..X[i+2a+b]
        //......X[j]....Z[j+a]......Z[j+a+b]...X[j+2a+b]
        X[j]        acw     Z[i+a]
        Z[j+a+b]    acw     X[i+2a+b]

        rest X, Z cw I => g[i] cw g[j]

    } 

    if 2 (j == i + a + b) {
        //X[i]..Z[i+a]..Z[i+a+b]..X[i+2a+b]
        //..............X[j]......Z[j+a]....Z[j+a+b]...X[j+2a+b]
        X[j]        acw     Z[i+a+b]
        Z[j+a]      acw      Z[i+2a+b]

        rest X, Z cw I => g[i] cw g[j]
    }

    if 3 (j+2a+b == i+a){
        //................X[i].......Z[i+a]...Z[i+a+b]...X[i+2a+b]
        //X[j]...Z[j+a]...Z[j+a+b]...X[j+2a+b]
        => switch i ,j = if 2
    }

    if 4 (j+2a+b == i+a){
        //........X[i]...Z[i+a].....Z[i+a+b]..X[i+2a+b]
        //X[j]....Z[j+a]..Z[j+a+b]..X[j+2a+b]
        => switch i ,j = if 1
    }
} 

=> g[i] always cw g[j] for any int i, j, a, b
      

