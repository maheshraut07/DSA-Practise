n = int(input("enter the number of elements you want in the list : "))

arr = []

for i in range(n):
    num = int(input(f"enter the number{i+ 1}"))
    arr.append(num)
    
def selection_sort(arr):
    for i in range(n):
        min_index = i
        
        for j in range(i+1 , n):
            if (arr[j] < arr[min_index]):
                min_index = j
        arr[i],arr[min_index] = arr[min_index],arr[i]
    
    return arr

print("the list after performing the selection sort is : ", selection_sort(arr))