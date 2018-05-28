#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

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
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	int64_t result = MaxPairwiseProdFast(numbers);
	cout << result << "\n";
	system("PAUSE");
	return 0;
}