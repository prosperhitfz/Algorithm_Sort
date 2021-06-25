def merge_sort(alist):
    for i in range(1, len(alist)):
        for low in range(0, len(alist)):
            mid = low + i
            height = min(low + 2 * i, len(alist))
            if mid < height:
                left = seq[low:mid]
                right = seq[mid:height]
                alist[low:height] = merge(left, right)
            low += 2 * i
        i *= 2
    return alist


def merge(left, right):
    result = []
    while left and right:
        if left[0] <= right[0]:
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))

    if left:
        result += left
    if right:
        result += right
    return result


if __name__ == '__main__':
    seq = [5, 4, 3, 0, 1, 2, 7, 5, 11, 9]
    print(merge_sort(seq))
