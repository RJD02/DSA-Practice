#include <bits/stdc++.h>
using namespace std;

class Polynomial {
	
public:
	map<int, int> coefficient;
	void setCoefficient(int deg, int coeff) {
		coefficient[deg] = coeff;
	}
	int getCoefficient(int deg) {
		return coefficient[deg];
	}
	void print() {
		for(auto i: coefficient) {
			if(i.second == 0) continue;
			cout << i.second << "x" << i.first << " ";
		}
	}
	Polynomial add(Polynomial p) {
		Polynomial res;
		for(auto i: p.coefficient) {
			if(coefficient[i.first] != 0) {
				res.coefficient[i.first] = i.second + coefficient[i.first];
			} else {
				res.coefficient[i.first] = i.second;
			}
		}
		for(auto i: coefficient) {
			if(res.coefficient[i.first] != 0) continue;
			else res.coefficient[i.first] = i.second;
		}
		return res;
	}
	Polynomial subtract(Polynomial p) {
		Polynomial res;
		for(auto i: coefficient) {
			res.coefficient[i.first] += i.second;
		}
		for(auto i: p.coefficient) {
			res.coefficient[i.first] -= i.second;
		}
		
		return res;
	}
	Polynomial multiply(Polynomial p) {
		Polynomial res;
		// int size = max(p.coefficient.size(), coefficient.size());
		for(int i = 0; i < coefficient.size(); i++) {
			for(int j = 0; j < p.coefficient.size(); j++)
				res.coefficient[i + j] += p.coefficient[j] * coefficient[i];
		}
		return res;
	}
};

 int main() {
    int count1,count2,choice;
    cin >> count1;
 
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
 
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
 
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
 
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
 
    cin >> count2;
 
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
 
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
 
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
 
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
 
    cin >> choice;
 
    Polynomial result;
    switch(choice) {

    // Add
    case 1:
        result = first.add(second);
        result.print();
        break;

    // Subtract
    case 2 :
        result = first.subtract(second);
        result.print();
        break;

    // Multiply
    case 3 :
        result = first.multiply(second);
        result.print();
        break;
    }
 
    return 0;

 }