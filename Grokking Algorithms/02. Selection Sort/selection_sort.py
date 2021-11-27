class SelectionSort:
    def sort(self, list):
        for i in range(len(list) - 1, 0, -1):
            largest = list[0]
            indx = 0
            for j in range(0, i + 1, 1):
                if list[j] > largest:
                    largest = list[j]
                    indx = j
            print('Exchanging...')
            list[indx] = list[i]
            list[i] = largest
        return list

    # def sortUsingSmallest(self, list):
    #     for i in range(len(list)):
    #         smallest = list[0]
    #         indx = 0
    #         for j in range(i+1, len(list), 1):
    #             if list[j] < smallest:
    #                 smallest = list[j]
    #                 indx = j
    #         print("Exchanging...")
    #         list[indx] = list[i]
    #         list[i] = smallest
    #     return list


if __name__ == "__main__":
    ss = SelectionSort()
    print(ss.sort([5, 3, 6, 2, 10]))

    # print(ss.sortUsingSmallest([5, 3, 6, 2, 10]))
