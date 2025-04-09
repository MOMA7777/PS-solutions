#include <bits/stdc++.h>
using namespace std;

/*


    Bijectivity and String Splitting in cpp :-
    -------------------------------------------

    1- Bijectivity is one to one means every letter->word
    and every word->letter, no letter/word has to empty and take 
    more than one.

    thats why 1 map isn't enough we have to make one for letters
    and one for words (cause words also must remain the condition...)

    2- Splitting String into words, numbers and Eliminating 
    the spaces

    is Quit easy using `istringstream` which avoid the space and take 
    the parts where no spaces

    string s = dog cat cat dog
    istringstrea iss (s) ==> iss [ string(dog), string(cat), string(cat), string(dog) ]

    but to make operations on it u need to extract each string using normal string

    string word
    while (iss >> word) 'like that!'



 * */

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> letter;
        unordered_map<string, char> word;

        istringstream iss;
        string token;

        int i = 0, n = pattern.size();
        while (iss >> token) {
            if ( i >= n ) return false;

            char c = pattern[i];

            if (letter.count(c) && letter[c] != token) return false;
            if (word.count(token) && word[token] != c) return false;

            letter[c] = token;
            word[token] = c;
            i++;
        }

        return i == n;
    }
};



int main() {
    

    return 0;
}
