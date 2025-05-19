#include<iostream>
#include<vector>

using namespace std;

vector<int> input(){
    cout << "Berechnen wir einen Quader mit folgenden Laengen: [Laenge, Hoehe, Breite] \n";
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> in = {a, b, c};
    return in;    
}

int volume(vector<int> in){
    int v = 1;
    for(int i = 0; i < in.size(); i++){
        v = v * in[i]; 
    }
    return v;
}

void output(int v, vector<int> in){
    cout<< "Der gesuchte Quader mit den Laengen " << in[0] << ", " << in[1] << " und " << in[2]
        << " hat ein Volumen von " << v << " Volumeneinheiten.";
}

int main(){
vector<int> p = input();
output(volume(p), p);
}