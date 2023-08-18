#include <iostream>

void merge(int * arr, int left, int mid, int right) {
    int size_left = mid - left + 1;
    int size_right = right - mid;

    int* arr_left = new int[size_left];
	int* arr_right = new int[size_right];

    for (int i = 0; i < size_left; i++){
        arr_left[i] = arr[left + i];
    }
    for (int i = 0; i < size_right; i++){
        arr_right[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;

    while (i < size_left && j < size_right){
        if (arr_left[i] <= arr_right[j]){
            arr[k] = arr_left[i];
            i++;
        }
		else{
            arr[k] = arr_right[j];
            j++;
        }
        k++;
    }

    while (i < size_left) {
        arr[k] = arr_left[i];
        k++;
        i++;
    }

    while (j < size_right) {
        arr[k] = arr_right[j];
        k++;
        j++;
    }

	delete[] arr_left;
	delete[] arr_right;
}

void merge_sort(int* arr, int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
	int arr[] = {5,7,9,6,3,2,4,1};
	int size = sizeof(arr) / sizeof(int);

	std::cout << "Unsorted array:" << std::endl;
	for (auto it : arr){
		std::cout << it << " ";
	}
	std::cout << std::endl;

	merge_sort(arr, 0, size - 1);

	std::cout << "Sorted array:" << std::endl;
	for (auto it : arr){
		std::cout << it << " ";
	}
	std::cout << std::endl;


	return 0;
}