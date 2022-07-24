// https://workat.tech/problem-solving/practice/merge-two-sorted-arrays

vector<int> mergeSortedArrays(vector<int> &A, vector<int> B) {
    // Time complexity: O(max(A.size() + B.size()))
	// Space complexity: O(A.size() + B.size())
	int indexA = 0;
	int indexB = 0;
	vector<int> res(A.size() + B.size());
	int ind = 0;
	while(indexA < A.size() and indexB < B.size()) {
		if(A[indexA] <= B[indexB])
			res[ind++] = A[indexA++];
		else
			res[ind++] = B[indexB++];
	}
	while(indexA < A.size())
		res[ind++] = A[indexA++];
	while(indexB < B.size())
		res[ind++] = B[indexB++];
	return res;
}