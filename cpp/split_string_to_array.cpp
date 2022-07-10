#include <bits/stdc++.h>

using namespace std;

vector<string> split1(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

vector<string> split2(string input)
{
    istringstream buf(input);
    istream_iterator<std::string> beg(buf), end;
    vector<std::string> tokens(beg, end); // done!
    return tokens;
}

vector<int> splitStringToInt(string input) // DAMN NEAT!
{
    int number;
    stringstream iss(input);
    vector<int> tokens;
    while (iss >> number)
    {
        tokens.push_back(number);
    }
    return tokens;
}

int main()
{
    string str = "This is a string";

    vector<string> tokens;

    string input;

    while (getline(std::cin, input))
    {
        if (input.empty())
            break;

        if (input == "1")
        {
            tokens = split1(str);
        }
        else if (input == "2")
        {
            tokens = split2(str);
        }
    }

    for(auto& s: tokens)
        std::cout << '"' << s << '"' << '\n';

    return 0;
}