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

int main() {
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	int64_t result = MaxPairwiseProdNaive(numbers);
	cout << result << "\n";
	system("PAUSE");
	return 0;
}