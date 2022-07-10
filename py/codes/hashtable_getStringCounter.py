## https://www.hackerrank.com/challenges/ctci-ransom-note/problem

from collections import Counter, defaultdict

# WOW SO PYTHONIC!!
def ransom_note(magazine, ransom):
    return (Counter(ransom) - Counter(magazine)) == {}

# using defaultdict (default value set to param, in this case int) 
def ransom_note2(magazine, ransom):
    dicty = defaultdict(int)
    for word in magazine:
        dicty[word]+=1
    print(dicty)
    for word in ransom: 
        if dicty[word]==0:
            return False # if one word from ransom didn't exist in magz, then this case must be False
        dicty[word] -= 1
    return True 

# using dictionary
def ransom_note3(magazine, ransom):
    dicty = dict()
    for w in magazine:
        if w in dicty:
            dicty[w] += 1
        else:
            dicty[w] = 1
    for w in ransom:
        if dicty[w] == 0:
            return False
        dicty[w] -= 1
    return True

# using dictionary and get
def ransom_note4(magazine, ransom):
    dicty = dict()
    for w in magazine:
        dicty[w] = dicty.get(w, 0) + 1
    for w in ransom:
        if dicty[w] == 0:
            return False
        dicty[w] -= 1
    return True

def TestUsingGet(magazine):
    d = dict()
    for w in magazine:
        print(w, d.get(w, 0))
        d[w] = d.get(w, 0) + 1
    print(d)


if __name__ == '__main__':
    magazine = ['give', 'me', 'one', 'grand', 'today', 'night', 'give']
    ransom = ['give', 'one', 'grand', 'today']
    TestUsingGet(magazine)

    answer = ransom_note4(magazine, ransom)
    if(answer):
        print("Yes")
    else:
        print("No")

