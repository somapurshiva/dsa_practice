class QuickSort:
    def sort(self, list):
        if len(list) < 2:
            return list
        else:
            pivot = list[0]
            less = [i for i in list[1:] if i <= pivot]
            greater = [i for i in list[1:] if i > pivot]
            return self.sort(less) + [pivot] + self.sort(greater)


if __name__ == "__main__":
    qs = QuickSort()
    print(qs.sort([5, 3, 6, 2, 10]))