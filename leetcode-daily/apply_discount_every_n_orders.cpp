#include <bits/stdc++.h>
using namespace std;

class Cashier {
public:
	int discount, currentOrder, n;
	unordered_map<int, int> price;
	Cashier(int n, int discount, vector<int> &products, vector<int> &prices) {
		this->discount = discount;
		currentOrder = 1;
		this->n = n;
		for(int i = 0; i < products.size(); i++)
			price[products[i]] = prices[i];
	}

	double getBill(vector<int> product, vector<int> amount) {
		double bill = 0;
	for(int i = 0; i < product.size(); i++) {
			bill += price[product[i]] * amount[i];
		}
		if(currentOrder == n) {
			bill = bill * ((100 - discount) / 100.0);
			currentOrder = 1;
		} else {
			currentOrder++;
		}
		return bill;
	}
};