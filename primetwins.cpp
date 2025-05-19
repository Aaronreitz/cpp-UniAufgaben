#include<iostream>

bool primetest(int p){
    bool prim = true;
    if(p < 2){
        prim = false;
    }
    for(int i = 2; i*i <= p; i++){
        if(p % i == 0){
            prim = false;
        }
    }
    return prim;
}

int main(){
    int count = 0 ;
    const int max = 100000;
    for(int i = 2; i<= max; i++){
        if(primetest(i) && primetest(i+2)){
            std::cout << i << " & " << i+2 << "\n";
            count++;
        }
    }
    std::cout << "\n" << "Es gibt " << count << " Primzahlpaare bis " << max;
}