#include <iostream>

using namespace std;

int input(){
    cout << "Give me an Integer for prime factorization: ";
    int p;
    cin >> p;
    return p;
}

int main(){
    int p = input();
 
    for(int i = 2; i * i <= p; i++){
        int count = 0;
        while(p % i == 0){
            count++;
            p = p/i;        
        }
        if(count > 0){
            cout << i << "^" << count << " ";
        }
    }
    if(p > 1){
        cout << p << "^1";
    }
}