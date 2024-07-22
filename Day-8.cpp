#include <bits/stdc++.h>
using namespace std;

// Rabin-Karp Algorithm for Pattern Searching
class KarpRabin
{
private:
    const int PRIME = 101;

    double calculateHash(const string &str)
    {
        double hash = 0;
        for (int i = 0; i < str.length(); ++i)
        {
            hash += str[i] * std::pow(PRIME, i);
        }
        return hash;
    }

    double updateHash(double prevHash, char oldChar, char newChar, int patternLength)
    {
        double newHash = (prevHash - oldChar) / PRIME;
        newHash = newHash + newChar * std::pow(PRIME, patternLength - 1);
        return newHash;
    }

public:
    void search(const std::string &text, const std::string &pattern)
    {
        int patternLength = pattern.length();
        double patternHash = calculateHash(pattern);
        double textHash = calculateHash(text.substr(0, patternLength));

        for (int i = 0; i <= text.length() - patternLength; ++i)
        {
            if (textHash == patternHash)
            {
                if (text.substr(i, patternLength) == pattern)
                {
                    std::cout << "Pattern found at index " << i << std::endl;
                }
            }

            if (i < text.length() - patternLength)
            {
                textHash = updateHash(textHash, text[i], text[i + patternLength], patternLength);
            }
        }
    }
};

// Print Anagrams Together
vector<vector<string>> Anagrams(vector<string> &strs)
{

    unordered_map<string, vector<int>> mp;

    for (int i = 0; i < strs.size(); i++)
    {
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        mp[temp].push_back(i);
    }

    vector<vector<string>> ans;

    for (auto it : mp)
    {
        vector<string> temp;
        for (auto x : it.second)
            temp.push_back(strs[x]);

        ans.push_back(temp);
    }

    return ans;
}

// 9. Group Anagrams
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    map<string, vector<string>> mp;

    for (auto str : strs)
    {
        string s = str;
        sort(s.begin(), s.end());
        mp[s].push_back(str);
    }

    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}

// 227. Basic Calculator II
int calculate(string s)
{
    stack<int> st;
    char sign = '+';
    int n = s.size();
    int res = 0, tmp = 0;
    for (long long int i = 0; i < n; i++)
    {
        char ch = s[i];

        if (isdigit(ch))
        {
            long long val = 0;
            while (i < n && isdigit(s[i]))
            {
                val = val * 10 + s[i] - '0';
                i++;
            }
            i--;
            if (sign == '+')
            {
                st.push(val);
            }
            else if (sign == '-')
            {
                st.push(-val);
            }
            else if (sign == '*')
            {
                int a = st.top();
                st.pop();
                int ans = a * val;
                st.push(ans);
            }
            else if (sign == '/')
            {
                int a = st.top();
                st.pop();
                int ans = a / val;
                st.push(ans);
            }
        }
        else if (ch != ' ')
        {
            sign = ch;
        }
    }

    long long sum = 0;
    while (st.size() > 0)
    {
        sum += st.top();
        st.pop();
    }
    return sum;
}
int main()
{
    KarpRabin kr;
    std::string text = "this is a test text";
    std::string pattern = "test";
    kr.search(text, pattern);
    return 0;
}
