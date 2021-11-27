def smallestNonConstructibleValue(arr):
    arr.sort()
    maxVal = 0
    for i in range(len(arr)):
        if arr[i] > maxVal + 1:
            return maxVal + 1
        else:
            maxVal += arr[i]
    return maxVal


print(smallestNonConstructibleValue([12, 2, 1, 15, 2, 4]))
print(smallestNonConstructibleValue([1, 1, 1, 1, 1, 5, 10, 25]))
