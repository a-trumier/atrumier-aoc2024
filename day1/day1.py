"""
Takes two lists of equal length, l1 and l2, and returns the distance between.
"""
def find_list_difference(l1: list, l2: list) -> int:
    assert len(l1) == len(l2)

    total_dist = 0
    c = 0
    while c < len(l1):
        total_dist += abs(l1[c] - l2[c])
        c += 1

    return total_dist


def find_list_similarity(l1: list, l2: list) -> int:
    assert len(l1) == len(l2)

    total_similarity = 0
    for i in l1:
        appearances = 0
        for j in l2:
            if (i == j):
                appearances += 1
        total_similarity += appearances * i

    return total_similarity

f = open("input.txt", "r")

list1 = []
list2 = []

for line in f:
    nums = line.split("   ")
    list1.append(int(nums[0]))
    list2.append(int(nums[1]))

list1.sort()
list2.sort()


test1 = [3, 4, 2, 1, 3, 3]
test2 = [4, 3, 5, 3, 9, 3]

test1.sort()
test2.sort()

print("Total distance found, test: " + str(find_list_difference(test1, test2)))
print("Total distance found, true: " + str(find_list_difference(list1, list2)))

print("Total similarity found,test: " + str(find_list_similarity(test1, test2)))
print("Total similarity found,true: " + str(find_list_similarity(list1, list2)))
