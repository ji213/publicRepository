# Insertion Sort
def insertion_sort(input_array):
    for i in range(1, len(input_array)):
        j = i
        while input_array[j - 1] > input_array[j] and j > 0:
            input_array[j - 1], input_array[j] = input_array[j], input_array[j - 1]
            j -= 1


# Selection Sort
def selection_sort(input_array):
    for i in range(0, len(input_array) - 1):
        cur_min_index = i
        for j in range(i + 1, len(input_array)):
            if input_array[j] < input_array[cur_min_index]:
                cur_min_index = j

        input_array[i], input_array[cur_min_index] = input_array[cur_min_index], input_array[i]

#Merge Sort
def merge_sort(input_array):
    if len(input_array) > 1:
        left_arr = input_array[:len(input_array)//2]
        right_arr = input_array[len(input_array)//2:]

        #recursion
        merge_sort(left_arr)
        merge_sort(right_arr)

        # merge
        i = 0   # left arr indx
        j = 0   # right arr index
        k = 0   # merged arr indx

        while i < len(left_arr) and j < len(right_arr):
            if left_arr[i] < right_arr[j]:
                input_array[k] = left_arr[i]
                i += 1
            else:
                input_array[k] = right_arr[j]
                j += 1

            k += 1

        while i < len(left_arr):
            input_array[k] = left_arr[i]
            i += 1
            k += 1

        while j < len(right_arr):
            input_array[k] = right_arr[j]
            j += 1
            k += 1

# Quick Sort
def quick_sort(input_array, left, right):
    if left < right:
        partition_pos = partition(input_array, left, right)
        quick_sort(input_array, left, partition_pos - 1)
        quick_sort(input_array, partition_pos + 1, right)


# Partition for quick sort
def partition(input_array, left, right):
    i = left
    j = right - 1
    pivot = input_array[right]

    while i < j:
        while i < right and input_array[i] < pivot:
            i += 1
        while j > left and input_array[j] >= pivot:
            j -= 1

        if i < j:
            input_array[i], input_array[j] = input_array[j], input_array[i]

    if input_array[i] > pivot:
        input_array[i], input_array[right] = input_array[right], input_array[i]

    return i






# Main Logic -- Init testing examples for each algo function
# To do:
#   - Add time logging to see which algorithms perform better

arr = [2, 6, 5, 1, 3, 4]
merge_sort(arr)
print(arr)

arr = [22, 11, 88, 66, 55, 77, 44, 4]
quick_sort(arr, 0, len(arr) - 1)
print(arr)
