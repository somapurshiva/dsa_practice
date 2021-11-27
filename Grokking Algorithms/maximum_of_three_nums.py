def max_of_three_nums(a, b, c):
    if a > b:
        if a > c:
            print(str(a) + ' is the Maximum')
        else:
            print(str(c) + ' is the Maximum')
    else:
        if b > c:
            print(str(b) + ' is the Maximum')
        else:
            print(str(c) + ' is the Maximum')
    return


max_of_three_nums(36, 24, 36)
max_of_three_nums(89, 12, 102)