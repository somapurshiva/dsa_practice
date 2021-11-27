import json


class BinarySearch():

    def binary_search(self, list, item):
        low = 0
        high = len(list) - 1

        while low <= high:
            mid = int((low + high) / 2)
            guess = list[mid]

            if guess == item:
                return mid
            if guess < item:
                low = mid + 1
            else:
                high = mid - 1
        return None


if __name__ == "__main__":
    with open("items.json", "r") as file:
        data = json.load(file)

    simple_list = data["simple_list"]
    list_with_10_items = data["list_with_10_items"]
    list_with_100_items = data["list_with_100_items"]
    list_with_1000_items = data["list_with_1000_items"]

    bs = BinarySearch()

    print(bs.binary_search(simple_list, 3))
    print(bs.binary_search(simple_list, 27))

    print(bs.binary_search(list_with_10_items, 18))
    print(bs.binary_search(list_with_10_items, 15))

    print(bs.binary_search(list_with_100_items, 276))
    print(bs.binary_search(list_with_100_items, 350))

    print(bs.binary_search(list_with_1000_items, 4524))
    print(bs.binary_search(list_with_1000_items, 4526))
