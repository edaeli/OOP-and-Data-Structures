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
std::vector<int> heapSort(const std::vector<int>& nums) {
    std::priority_queue<int> pq;
    std::vector<int> result(nums.size());

    for (int x : nums)
        pq.push(x);

    for (int i = nums.size() - 1; i >= 0; i--) {
        result[i] = pq.top();
        pq.pop();
    }

    return result;
}

//2
int kthSmallest_maxHeap(const std::vector<int>& nums, int k) {
    if (k <= 0 || k > nums.size())
        return 0;

    std::priority_queue<int> pq; 

    for (int x : nums) {
        pq.push(x);
        if (pq.size() > k)
            pq.pop(); 
    }

    return pq.top(); 
}

//4

class MedianFinder {
private:
    std::priority_queue<int> left;

    std::priority_queue<int, std::vector<int>, std::greater<int>> right;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }
        if (left.size() > right.size()) {
            return left.top();
        }
        return right.top();
    }
};

//5


struct Point {
    int x;
    int y;
};

struct Node {
    int dist;
    Point p;
};

struct Compare {
    bool operator()(const Node& a, const Node& b) {
        return a.dist < b.dist; // max-heap
    }
};

std::vector<Point> kClosest(const std::vector<Point>& points, int k) {
    std::priority_queue<Node, std::vector<Node>, Compare> pq;

    for (const auto& pt : points) {
        int d = pt.x * pt.x + pt.y * pt.y;

        pq.push(Node{d, pt});

        if (pq.size() > k) {
            pq.pop();
        }
    }

    std::vector<Point> result;
    while (!pq.empty()) {
        result.push_back(pq.top().p);
        pq.pop();
    }

    return result;
}
