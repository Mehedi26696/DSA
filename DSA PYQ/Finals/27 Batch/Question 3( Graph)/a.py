

# a) The following pseudocode is intended to find the square root of a given number using the  binary search algorithm. If you notice any errors in the pseudocode, 
# then you should correct them.


def find_square_root (number) :
    start = 0
    end = number
    while start <= end :
        mid = (start + end) // 2
        if mid * mid == number :
            return mid
        if mid * mid < number :
            start = mid + 1
        else :
            end = mid - 1
    return start - 1  # or return end


print(find_square_root(9)) # 3

# Tailor the above (or corrected) pseudocode so it can be used to find the nth root.
