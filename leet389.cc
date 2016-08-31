#include <iostream>
#include <string>
using namespace std;

char findTheDifference(string s, string t) {
    char res = 'a';
    int letters[26] = {0};
    int temp = 0;
    for(int i = 0; i < s.length(); ++i){
        temp = s[i]-97;
        ++letters[temp];
    }
    for(int i = 0; i < 26; ++i)
        cout<<letters[i]<<" ";
    cout<<endl;

    for(int i = 0; i < t.length(); ++i){
        temp = t[i] - 97;
        --letters[temp];
    }
    for(int i = 0; i < 26; ++i)
        cout<<letters[i]<<" ";
    cout<<endl;
    int i = 0;
    while(i<26){
        if(letters[i]!=0){
            char res = (char)(i + 97);
            cout<<res<<endl;
            return res;
        }
        ++i;
    }
    return res;
}

int main(){
    string a = "abcd";
    string b = "abcde";
    char c = findTheDifference(a,b);
    cout<<c<<endl;       
    return 0;
}