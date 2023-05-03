#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 1000 // Maximum size of the array

int arr[MAX_SIZE], temp[MAX_SIZE];

typedef struct {
    int left;
    int right;
} range; // A struct that holds the left and right index of the array

void merge(int left, int mid, int right) {
    int i, j, k;
    for (i = left, j = mid + 1, k = left; i <= mid && j <= right; k++) {
        if (arr[i] <= arr[j]) {
            temp[k] = array[i++]; // Copy the smaller element to temp array
        } else {
            temp[k] = array[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++]; // Copy the remaining elements from left subarray
    }
    while (j <= right) {
        temp[k++] = arr[j++]; // Copy the remaining elements from right subarray
    }
    for (k = left; k <= right; k++) {
        arr[k] = temp[k]; // Copy the merged elements back to the original array
    }
}

void *merge_sort(void *data) {
    range *r = (range *) data; // Cast the input data as a range struct
    int left = r->left;
    int right = r->right;
    if (left < right) {
        int mid = (left + right) / 2;

        pthread_t thread_left, thread_right;

        range left_range = {left, mid}; // Create a range struct for left subarray
        range right_range = {mid + 1, right}; // Create a range struct for right subarray

        pthread_create(&thread_left, NULL, merge_sort, &left_range); // Create a thread to sort left subarray
        pthread_create(&thread_right, NULL, merge_sort, &right_range); // Create a thread to sort right subarray

        pthread_join(thread_left, NULL); // Wait for the left thread to finish
        pthread_join(thread_right, NULL); // Wait for the right thread to finish

        merge(left, mid, right); // Merge the two sorted subarrays
    }
    pthread_exit(NULL); // Terminate the thread
}

int main() {
    int n, i;
    pthread_t tid;

    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    printf("Enter the elements to be sorted: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]); // Read the input array
    }

    range data = {0, n - 1}; // Create a range struct for the entire array

    pthread_create(&tid, NULL, merge_sort, &data); // Create a thread to sort the entire array
    pthread_join(tid, NULL); // Wait for the thread to finish

    printf("Sorted elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]); // Print the sorted array
    }
    printf("\n");

    return 0;
}

