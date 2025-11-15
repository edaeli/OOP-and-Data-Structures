#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>


//1

std::vector<int> removeDuplicates(std::vector<int> vec){
    std::set<int> s(vec.begin(), vec.end());   
    return std::vector<int>(s.begin(), s.end());
}

//2

std::vector<int> findIntersection(std::vector<int> vec1, std::vector<int> vec2){
    std::set<int> s1(vec1.begin(),vec1.end());
    std::set<int> s2(vec2.begin(),vec2.end());

    std::vector<int> res;
    for(int x : s1){
        for(int y : s2){
            if(x == y)
                res.push_back(x);
        }
    }

    return res;

}

//3

bool isSubset(std::vector<int> subset,std::vector<int> superset){
    std::set<int> s1(subset.begin(),subset.end());
    std::set<int> s2(superset.begin(),superset.end());

    for(int x : s1){
        if(!(s2.count(x))){
            return false;
        }
    }
    return true;
}


//4


std::vector<int> findMissingNumbers(std::vector<int> vec,int n){
    std::set<int> s(vec.begin(),vec.end());
    std::vector<int> res;

    for(int i = 1;i <= n;i++){
        if(!s.count(i))
            res.push_back(i);
    }
    return res;
}

//5

int findClosest(std::set<int> s,int target){
    if (s.empty()) 
        return -1;

    auto it = s.lower_bound(target);

    int right =  *it;
    int left  =  *std::prev(it);

    int diffLeft  = std::abs(target - left);
    int diffRight = std::abs(target - right);

    if (diffLeft == diffRight) 
        return left;  

    if(diffLeft < diffRight)
        return left;
    return right;
}


//6

int rangeCount(std::set<int> s,int low,int high){
    int count = 0;
    auto itLow = s.lower_bound(low);
    auto itHigh = s.upper_bound(high);

    for (auto it = itLow; it != itHigh; it++) 
        count++;

    return count;
}   

//7

std::vector<int> symmetricDifference(std::vector<int> vec1,std::vector<int> vec2){
    std::set<int> s1(vec1.begin(),vec1.end());
    std::set<int> s2(vec2.begin(),vec2.end());
    
    std::vector<int> res;

    for(int x : s1){
        if(s2.find(x) == s2.end())
            res.push_back(x);
    }

    for(int x : s2){
        if(s1.find(x) == s1.end())
            res.push_back(x);
    }

    std::sort(res.begin(),res.end());

    return res;

}

//8

int firstRepeating(std::vector<int> vec){
    std::set<int> s;

    for(int x : vec){
        if(s.find(x) != s.end())
            return x;
        s.insert(x);
    }    

    return -1;
}

//9

int removeRange(std::set<int> &s,int low,int high){
    auto itLow = s.lower_bound(low);
    auto itHigh = s.upper_bound(high);

    int count = rangeCount(s,low,high);

    s.erase(itLow,itHigh);

    return count;
}

//10

bool hasAllCodes(const std::string &s, int k) {
    if (s.size() < std::pow(2, k)) {
        return false;
    }
    std::string result;
    std::set<std::string> st;
    for (int i = 0; i < s.size() - k; i++) {
        result = s.substr(i, k);
        st.insert(result);
    }
    return st.size() == std::pow(2, k);
}

int main(){
    //1
    std::cout << "remove dup" << std::endl;
    std::vector<int> nums = {4, 2, 5, 2, 3, 4, 1};
    auto result = removeDuplicates(nums);
    for (int x : result)
        std::cout << x << " ";

    std::cout << std::endl;
    std::cout<<"-----------------"<<std::endl;

    //2

    std::cout << "Intersection" << std::endl;

    std::vector<int> arr1 = {1, 2, 3, 4, 5};
    std::vector<int> arr2 = {3, 4, 5, 6, 7};
    auto res = findIntersection(arr1, arr2);

    for (int x : res)
        std::cout << x << " ";

    std::cout << std::endl;

    std::cout<<"-----------------"<<std::endl;

    //3

    std::cout << "subset"<<std::endl;

    std::vector<int> subset = {1, 3, 5};
    std::vector<int> superset = {1, 2, 3, 4, 5};
    std::cout << isSubset(subset, superset) << '\n';  // 1 (true)

    std::vector<int> subset2 = {1, 6};
    std::cout << isSubset(subset2, superset) << '\n';  // 0 (false)

    std::cout<<"-----------------"<<std::endl;

    //4

    std::cout << "Missing numbers" << std::endl;

    std::vector<int> num = {1, 3, 5, 6};
    auto result4 = findMissingNumbers(num, 6);

    for (int x : result4)
        std::cout << x << " ";

    std::cout << std::endl;



    std::cout<<"-----------------"<<std::endl;



    //5
    std::cout << "closest" << std::endl;

    std::set<int> s = {1, 5, 10, 15, 20};
    std::cout << findClosest(s, 12) << '\n';  // 10
    std::cout << findClosest(s, 13) << '\n';   // 15

    std::cout<<"-----------------"<<std::endl;

    //6

    std::cout << "range" << std::endl;

    std::set<int> s6 = {1, 3, 5, 7, 9, 11, 13, 15};
    std::cout << rangeCount(s6, 5, 11) << '\n'; 


    std::cout << "----------------" << std::endl;

    //7

    std::vector<int> arr17 = {1, 2, 3, 4};
    std::vector<int> arr27 = {3, 4, 5, 6};
    auto result7 = symmetricDifference(arr17, arr27);
    // result: {1, 2, 5, 6}

    for (int x : result7)
        std::cout << x << " ";

    std::cout << std::endl;



    std::cout<<"-----------------"<<std::endl;

    //8

    std::vector<int> nums8 = {1, 2, 3, 4, 2, 5, 6, 3};
    std::cout << firstRepeating(nums8) << '\n';  // 2

    std::cout<<"-----------------"<<std::endl;

    //9

    std::set s9 = {1, 3, 5, 7, 9, 11, 13, 15};
    int removed = removeRange(s9, 5, 11);
    std::cout << removed << '\n';  // 4

    // s теперь содержит: {1, 3, 13, 15}

    for (int x : s9)
        std::cout << x << " ";

    std::cout << std::endl;



    std::cout<<"-----------------"<<std::endl;

    //10

    std::cout << hasAllCodes("00110110", 2) << '\n';  // 1 (true)
    // Двоичные коды длины 2: "00", "01", "10", "11"
    // Все найдены: "00" (индекс 0), "01" (индекс 1), "11" (индекс 5), "10" (индекс 3)

    std::cout << hasAllCodes("0110", 1) << '\n';      // 1 (true)
    // Двоичные коды длины 1: "0" и "1"
    // Оба присутствуют в строке

    std::cout << hasAllCodes("0110", 2) << '\n';      // 0 (false)
    // Двоичные коды длины 2: "00", "01", "10", "11"
    // Отсутствует "00"

    std::cout << hasAllCodes("0000000001011100", 4) << '\n';  // 0 (false)
    // Не все 16 возможных кодов длины 4 присутствуют



}