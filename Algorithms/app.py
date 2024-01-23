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




arr = [2, 6, 5, 1, 3, 4]
selection_sort(arr)
print(arr)
