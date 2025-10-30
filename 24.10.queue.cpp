#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <queue>

//1

std::string hotPotato( std::vector<std::string> players, int K) {
    std::queue<std::string> q;

    for (auto name : players) {
        q.push(name);
    }

    while (q.size() > 1) {
        for (int i = 0; i < K; i++) {
            std::string player = q.front();
            q.pop();
            q.push(player);
        }

        q.pop();
    }
    return q.front();
}

//2


std::vector<std::string> generateBinaryNumbers(int N) {
    std::vector<std::string> result;
    std::queue<std::string> q;

    q.push("1");

    for (int i = 0; i < N; i++) {
        std::string s = q.front();
        q.pop();

        result.push_back(s);

        q.push(s + "0");
        q.push(s + "1");
    }

    return result;
}

//3

int timeRequiredToBuy(std::vector<int> tickets, int k) {
    std::queue<std::pair<int,int>> q; 

    for (int i = 0; i < tickets.size(); i++) {
        q.push({i, tickets[i]});
    }

    int time = 0;

    while (!q.empty()) {
        auto [index, remaining] = q.front();
        q.pop();

        remaining--;
        time++;

        if (index == k && remaining == 0) {
            return time;
        }

        if (remaining > 0) {
            q.push({index, remaining});
        }
    }

    return time; 
}



int main(){
    //1


    std::vector<std::string> players = {"Alice", "Bob", "Charlie", "David"};
    std::cout << hotPotato(players, 7) << '\n'; 

    std::cout << "-----------------" << std::endl;

    //2

    int N = 5;
    auto result = generateBinaryNumbers(N);

    for (const auto& s : result) {
        std::cout << s << " ";
    }
    std::cout << "\n";

    std::cout << "-------------------" << std::endl;

    //3

    std::vector<int> tickets1 = {2, 3, 2};
    std::cout << timeRequiredToBuy(tickets1, 2) << '\n';  

    std::vector<int> tickets2 = {5, 1, 1, 1};
    std::cout << timeRequiredToBuy(tickets2, 0) << '\n'; 
}
