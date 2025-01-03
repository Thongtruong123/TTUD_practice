// C++ program to check if the
// given array can be partitioned
// into K subsets with equal sum
#include <bits/stdc++.h>
using namespace std;

// Function to check whether
// K required partitions
// are possible or not
bool isKPartitionPossible(int arr[],
						int N, int K)
{
	if (K == 1)
		// Return true as the
		// entire array is the
		// answer
		return true;

	// If total number of
	// partitions exceeds
	// size of the array
	if (N < K)
		return false;

	int sum = 0;
	for (int i = 0; i < N; i++)
		sum += arr[i];
	// If the array sum is not
	// divisible by K
	if (sum % K != 0)
		// No such partitions are
		// possible
		return false;

	// Required sum of
	// each subset
	int target = sum / K;

	// Initialize dp array with -1
	int dp[(1 << 15)];
	for (int i = 0; i < (1 << N); i++)
		dp[i] = -1;

	// Sum of empty subset
	// is zero
	dp[0] = 0;

	// Iterate over all subsets/masks
	for (int mask = 0; mask < (1 << N); mask++) {
		// if current mask is invalid, continue
		if (dp[mask] == -1)
			continue;

		// Iterate over all array elements
		for (int i = 0; i < N; i++) {
			// Check if the current element
			// can be added to the current
			// subset/mask
			if (!(mask & (1 << i))
				&& dp[mask]
						+ arr[i]
					<= target) {
				// transition
				dp[mask | (1 << i)]
					= (dp[mask]
					+ arr[i])
					% target;
			}
		}
	}

	if (dp[(1 << N) - 1] == 0)
		return true;
	else
		return false;
}

// Driver Code
int main()
{
	int arr[] = { 2, 1, 4, 5, 3, 3 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 3;

	if (isKPartitionPossible(arr, N, K)) {
		cout << "Partitions into equal ";
		cout << "sum is possible.\n";
	}
	else {
		cout << "Partitions into equal ";
		cout << "sum is not possible.\n";
	}
}
