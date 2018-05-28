#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int64_t MaxPairwiseProdNaive(const vector<int>& numbers) {
	/*initialize result*/
	int64_t result = 0;
	/*store size of vector*/
	int n = numbers.size();
	/*loop through the vector*/
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			/*compute the product at each iteration and compare with the stored result*/
			if (((int64_t)(numbers[i])) * numbers[j] > result) {
				/*store the new product if it is bigger than the old one*/
				result = ((int64_t)(numbers[i])) * numbers[j];
			}
		}
	}
	/*retun the final value of result*/
	return result;
}

int64_t MaxPairwiseProdFast(vector<int>& numbers) {
	/* initialize result*/
	int64_t result = 0;
	/*get length of numbers list*/
	int n = numbers.size();
	/*initialize index*/
	int index = 0;
	/*search for max number index*/
	for (int i = 1; i < n; ++i) {
		if (numbers[i] > numbers[index]) {
			index = i;
		}
	}
	/*swap the last number with the max number*/
	std::swap(numbers[n - 1], numbers[index]);

	/*reset index*/
	index = 0;
	/*search for the next max number index*/
	for (int i = 1; i < n - 1; ++i) {
		if (numbers[i] > numbers[index]) {
			index = i;
		}
	}

	/*/swap the second last number with the second biggest*/
	std::swap(numbers[n - 2], numbers[index]);

	/*get result as the product of the last two numbers in list*/
	result = ((int64_t) (numbers[n - 2])) * numbers[n - 1];
	return result;
}

int main() {
	while (true) {
		int n = rand() % 10 + 2;
		cout << n << "\n";
		vector<int> a;
		for (int i = 0; i < n; ++i) {
			a.push_back(rand() % 100000);
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
		int64_t res1 = MaxPairwiseProdNaive(a);
		int64_t res2 = MaxPairwiseProdFast(a);
		if (res1 != res2) {
			cout << "Wrong answer: " << res1 << " " << res2 << "\n";
			break;
		}
		else {
			cout << "OK\n";
		}
	}
	system("PAUSE");
	return 0;
}