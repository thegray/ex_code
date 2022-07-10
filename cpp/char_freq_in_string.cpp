/*
this problem is coming from making anagrams case in hr
count the frequency of the same chars in two strings

https://www.hackerrank.com/challenges/ctci-making-anagrams/problem
 */

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int number_needed(string a, string b) {
    auto count = 0;
    vector<int> freq(26, 0);
    for (auto c : a) 
    { //count freq of each char in string 1, 
      //keep it in a vector using index determined by current char - 'a'
      //increase the count of the char
        ++freq[c - 'a']; 
    }
    for (auto c : b) { --freq[c - 'a']; } // decrease the count of the existing char in vector
    for (auto val : freq) { count += abs(val); } // sum up all the value
    return count;
}
