# lab-8-

![Screenshot from 2023-04-11 19-43-04](https://user-images.githubusercontent.com/104758930/231202812-89b8fe99-a48d-4e61-9e55-25b08d293050.png)


# Summary 
The code is an implementation of the merge sort algorithm using multi-threading with POSIX threads in C programming language. The main function prompts the user to enter the number of elements to be sorted and the elements themselves. Then it creates a range struct containing the left and right indices of the array to be sorted and passes it to the merge_sort function to be sorted using multi-threading. The merge_sort function recursively divides the array into two halves and creates two threads, one to sort each half. After the two threads have finished, the merge function is called to merge the two sorted halves into a single sorted array. Finally, the main function joins the merge_sort thread and prints the sorted elements.
