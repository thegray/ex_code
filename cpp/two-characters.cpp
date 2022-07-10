/*
https://www.hackerrank.com/challenges/two-characters/problem

example input:
10
beabeefeab

example output:
5
*/

int alternate(string s) {
    unordered_set<char> ss; 
    for (char c : s) {
        ss.insert(c);
    }
    int max = 0;
    unordered_set<char>::iterator itr; 
    for (itr = ss.begin(); itr != ss.end(); itr++) {
        for (unordered_set<char>::iterator itr2 = next(itr, 1); itr2 != ss.end(); itr2++) {
            int locallen = 0;
            char a = ' ';
            //cout << "1: " << *itr << ", 2: " << *itr2 << endl;
            for (int x = 0; x < s.length(); x++) {                
                if (s[x] == (*itr) || s[x] == (*itr2)) {
                    if (a == ' '){
                        //cout << s[x];
                        a = s[x];
                        locallen++;
                    }
                    else {
                        if (s[x] != a) {
                            locallen++;
                            a = s[x];
                            //cout << s[x];
                        } else { //invalid string
                            //cout << s[x] << "-break";
                            locallen = 0;
                            break;
                        }                            
                    }
                }
            }
            //cout << " -- " << locallen << endl;
            if (max < locallen)
                max = locallen;
        }        
    }
    return max;
}