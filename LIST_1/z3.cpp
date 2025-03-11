#include <iostream>

int fib(int n){
    if (n >= 2){
        int a = 0;
        int b = 1;
        int c;
        for(int i = 2; i<=n; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
    return n;
}

int fib2(int n){
    if (n >= 2){
        return fib2(n-1) + fib(n-2);
    }
    return n;
}



int main(){
    int n = 6;
    int ret = fib(n);
    std::cout<< ret << std::endl;
}