def mergesort(list1, list2):
    list3 = []
    i = 0
    j = 0
    while i < len(list1) and j < len(list2):
        if list1[i] <= list2[j]:
            list3.append(list1[i])
            i += 1
        else:
            list3.append(list2[j])
            j += 1
    list3 += list1[i:]
    list3 += list2[j:]
    return list3


def mergelist(nums1, nums2):
    nums1 += nums2
    nums1.sort()
    return nums1




b = [1,4,5,8,9]
a = [2,3,6]
###print(len(a))
print(mergesort(a, b))
print(mergelist(a,b))