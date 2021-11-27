class InsertionSort:
    def sort(self, list):
        for k in range(1, len(list), 1):
            y = list[k]
            indx = k
            for i in range(k-1, -1, -1):
                if y >= list[i]:
                    break
                indx = indx - 1
                list[i+1] = list[i]
            list[indx] = y
        return list


if __name__ == "__main__":
    ins = InsertionSort()
    print(ins.sort([5, 3, 6, 2, 10]))
