#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <sstream>
#include <cctype>


//1

std::map<int, int> countFrequency(std::vector<int> nums){
    std::map<int,int> freqs;
    for(auto x : nums){
        freqs[x]++;
    }
    return freqs;
}

//2

std::map<char, std::vector<std::string>> groupByFirstChar(std::vector<std::string> strs){
    std::map<char, std::vector<std::string>> mp;
    for(auto x : strs){
        char first = x[0];
        mp[first].push_back(x);
    }
    return mp;
}

//3
std::map<std::string, int> mergeMaps(std::map<std::string, int> mp1,std::map<std::string, int> mp2){
    std::map<std::string, int> res;
    for(auto x : mp1){
        res[x.first] = x.second; 
    }

    for(auto x : mp2){
        res[x.first] += x.second;
    }
    return res;
}

//4

int firstUniqueChar(std::string s){
    std::map<char,int> m;
    for(char c : s){
        m[c]++;
    }

    for(int i = 0; i < (int)s.size(); i++){
        if(m[s[i]] == 1)
            return i;
    }

    return -1;

}


//5

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> words){
    std::map<std::string, std::vector<std::string>> mp;

    for(std::string x : words){
        std::string key = x;
        std::sort(key.begin(),key.end());
        mp[key].push_back(x);
    }

    std::vector<std::vector<std::string>> res;
    for(auto p : mp){
        res.push_back(p.second);
    }
    return res;
}

//6 

std::vector<int> topKFrequent(std::vector<int> vec0,int k){
    std::map<int,int> mp;

    for(int x : vec0){
        mp[x]++;
    }

    std::vector<std::pair<int,int>> vec(mp.begin(), mp.end());

    std::sort(vec.begin(), vec.end(),
              [](const auto& a, const auto& b) {
                  return a.second > b.second;  
              });

    std::vector<int> result;
    for (int i = 0; i < k && i < vec.size(); i++) {
        result.push_back(vec[i].first);
    }

    return result;

}

//7
bool isIsomorphic(std::string s,std::string t) {
    if (s.size() != t.size()) 
        return false;

    std::map<char, char> st;  
    std::map<char, char> ts;  

    for (int i = 0; i < s.size(); i++) {
        char a = s[i];
        char b = t[i];

        if (st.count(a)) {
            if (st[a] != b)   
                return false;
        } else {
            st[a] = b;      
        }

        if (ts.count(b)) {
            if (ts[b] != a)
                return false;
        } else {
            ts[b] = a;
        }
    }

    return true;
}

//8

#include <vector>
#include <map>
#include <algorithm>

std::vector<int> arrayRankTransform(std::vector<int> arr) {
    if (arr.empty()) 
        return {};

    std::vector<int> sorted = arr;

    std::sort(sorted.begin(), sorted.end());

    std::map<int, int> rank;
    int r = 1;

    for (int x : sorted) {
        if (rank.count(x) == 0) {
            rank[x] = r;
            r++;
        }
    }

    std::vector<int> result;
    result.reserve(arr.size());

    for (int x : arr) {
        result.push_back(rank[x]);
    }

    return result;
}

//9

int rangeSumMap(std::map<int,int> mp, int left, int right){
    int s = 0;


    for(auto x : mp){
        if(x.first >= left && x.first <=right){
            s += x.second;
        }
    }

    return s;
}

//11

std::string mostFrequentWord(std::string text) {
    std::map<std::string, int> freq;

    std::string word;

    for (char c : text) {
        if (std::isalpha(c)) {
            word += std::tolower(c);   
        } else {
            if (!word.empty()) {        
                freq[word]++;
                word.clear();
            }
        }
    }

    if (!word.empty()) {
        freq[word]++;
    }

    int bestCount = 0;
    std::string bestWord;

    for (auto &p : freq) {
        if (p.second > bestCount) {
            bestCount = p.second;
            bestWord = p.first;
        }
    }

    return bestWord;
}


//12

int removeInfrequent(std::map<std::string, int> &freq, int threshold) {
    int removed = 0;

    for (auto it = freq.begin(); it != freq.end(); it++) {
        if (it->second < threshold) {
            it = freq.erase(it); 
            removed++;
        } 
    }

    return removed;
}











int main(){
    //1
    std::vector<int> nums = {4, 2, 3, 4, 2, 3, 4, 3, 1, 4};
    auto result = countFrequency(nums);
    // result: {1: 1, 2: 2, 3: 3, 4: 4}
    for(auto x : result){
        std::cout << x.first << ": " << x.second << std::endl;
    }
    std::cout << std::endl;

    std::cout << "-------------------" << std::endl;

    //2

    std::vector<std::string> words = {"apple", "banana", "apricot", "cherry", "avocado"};
    auto result2 = groupByFirstChar(words);
    // result: {'a': ["apple", "apricot", "avocado"], 'b': ["banana"], 'c': ["cherry"]} 

    for (auto x : result2) {
        std::cout << x.first << ": ";
        for (auto s : x.second) {
            std::cout << s << " ";
        }
        std::cout << std::endl;;
    }
    std::cout << std::endl;

    std::cout << "-------------------" << std::endl;

    //3

    std::map<std::string, int> map1 = {{"a", 1}, {"b", 2}, {"c", 3}};
    std::map<std::string, int> map2 = {{"b", 3}, {"c", 4}, {"d", 5}};
    auto result3 = mergeMaps(map1, map2);
    // result: {{"a", 1}, {"b", 5}, {"c", 7}, {"d", 5}}

    for(auto x : result3){
        std::cout << x.first << ": " << x.second << std::endl;
    }
    std::cout << std::endl;

    std::cout << "-------------------" << std::endl;

    //4
    std::string s = "leetcode";
    std::cout << firstUniqueChar(s) << '\n';  // 0 ('l')

    std::string s2 = "loveleetcode";
    std::cout << firstUniqueChar(s2) << '\n';  // 2 ('v')
    
    std::cout << "----------------------" << std::endl;

    //5
    std::vector<std::string> words5 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto result5 = groupAnagrams(words5);
    // result: [["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]


    //6

    std::vector<int> nums6 = {1, 1, 1, 2, 2, 3};
    auto result6 = topKFrequent(nums6, 2);
    // result: {1, 2}

    //9

    std::map<int, int> m10 = {{1, 10}, {3, 20}, {5, 30}, {7, 40}};
    std::cout << rangeSumMap(m10, 3, 7) << '\n';  // 90 (20 + 30 + 40)
    std::cout << rangeSumMap(m10, 2, 4) << '\n';  // 20 (только ключ 3)

    std::cout << "-------------------" << std::endl;

}