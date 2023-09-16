#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    int num[3] {0, 0, 0};
    string word;
    cout << "Enter words (q to quit):\n";
    while (1)
    {
        cin >> word;
        if (word == "q")
        {
            break;
        }
        else if (isalpha(word[0]))
        {
            switch (word[0] + 0)
            {
            case 'a' + 0:
            case 'e' + 0:
            case 'i' + 0:
            case 'o' + 0:
            case 'u' + 0:
                ++num[0];
                break;
            default:
                ++num[1];
                break;
            }
        }
        else
        {
            ++num[2];
        }
    }
    cout << num[0] << " words beginning with vowels\n"
         << num[1] << " words beginning with consonants\n"
         << num[2] << " others";
    return 0;
}