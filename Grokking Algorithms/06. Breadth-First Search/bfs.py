from collections import deque

graph = {"you": ["alice", "bob", "claire"], "bob": ["anuj", "peggy"], "alice": ["peggy"], "claire": ["thom", "jonny"],
         "anuj": [], "peggy": [], "thom": [], "jonny": []}


def person_is_seller(name):
    return name[-1] == 'm'


def search(name):
    search_queue = deque()
    searched = []
    search_queue += graph[name]
    while search_queue:
        person = search_queue.popleft()
        if not person in searched:
            if person_is_seller(person):
                print(person + " is a mango seller!")
                return True
            else:
                search_queue += graph[person]
                searched.append(person)
    return False


if __name__ == "__main__":
    search("you")
