def rearrange(arr):
    for i in range(1, len(arr)):
        if (i % 2 == 0 and arr[i-1] < arr[i]) or (i % 2 != 0 and arr[i-1] > arr[i]):
            temp = arr[i]
            arr[i] = arr[i-1]
            arr[i-1] = temp
    for i in range(len(arr)):
        print(arr[i])


rearrange([12, 15, 21, 35, 2, 5, 17, 56, 41, 80, 1, 10])
