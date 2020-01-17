"""
ANAGRAMS
Some practice for anagrams

Stefan Wong 2020
"""


"""
First thing that we want to so is normalize the strings somehow. For this example
we will

- Remove spaces
- Convert to lower case


"""

# Requires N log(N) since any comparison based sorting
# algorithm is going to require at least N log(N) time
# for the sorting procedure
#print(sorted(s1) == sorted(s2))

# We can create a histogram (hash table) of what we have
# seen an enusure that characters that are seen in one
# sentence are also seen in the other sentence
# NOTE: also we probably want to do the various basic checks
# about things like
# - Are the strings the same length?
# - Are any of the strings null?
# - Are any of the strings length zero?


def string_norm(s:str, ignore_space:bool=True) -> str:
    if ignore_space:c
        return s.replace(" ", "").lower()
    else:
        return s.lower()


# Constructing the histogram here takes O(2 * N) (ie: O(N)) since
# we have to walk along both string to generate the histogram.
# The lookup is also N
def is_anagram(s1:str, s2:str) -> bool:
    histogram = dict()

    if len(s1) != len(s2):
        return False

    if (len(s1) == 0) or (len(s2) == 0):
        return False

    # create a histogram of the first string
    for c in s1:
        if c in histogram:
            histogram[c] += 1
        else:
            histogram[c] = 1

    # Subtract the histogram of the second string
    for c in s2:
        if c in histogram:
            histogram[c] -= 1
        else:
            histogram[c] = 1

    for k in histogram:
        if histogram[k] != 0:
            return False

    return True



if __name__ == '__main__':
    s1 = 'fairy tales'
    s2 = 'rail safety'

    s1 = string_norm(s1)
    s2 = string_norm(s2)

    print(is_anagram(s1, s2))
