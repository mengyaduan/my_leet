#include <iostream>
#include <string>
#include <vector>
using namespace std;
    
    bool isSame(string a, string b){
        int letter[26]={0};
        for(int i =0;i<a.length(); ++i){
            int cnt = a[i] - 97;
            ++letter[cnt];
        }
        for(int i =0;i<b.length(); ++i){
            int cnt = b[i]-97;
            if(letter[cnt]!=0)
                return true;
        }
        return false;
    }

    int maxProduct(vector<string>& words) {
        int n = words.size();
        int max = 0;
        int head = 0;
        while(head < n-1){
            int temp = 0;
            for(int i = head+1; i < n; ++i){
                if( !isSame(words[head],words[i]) ){
                    temp = words[head].length() * words[i].length();
                    if(temp > max){
                        max = temp;
                    }
                }
            }
            head++;
        }
        return max;
    }


int main(int argc, char const *argv[])
{
    vector<string> v;
    // string a[] = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    // string a[] = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    string a[] = {"a", "aa", "aaa", "aaaa"};


    int n = 4;
    for (int i = 0; i < n; ++i)
    {
        v.push_back(a[i]);
    }
    int x = maxProduct(v);
    cout<<x<<endl;
    return 0;
}