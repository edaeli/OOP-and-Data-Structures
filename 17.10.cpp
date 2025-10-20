#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <forward_list>
#include <stdexcept>
#include <deque>



//1

void createAndFillDeque(int n){
   std::deque<int> deq;

   for(int i = 1;i <= n;i+=2){
      deq.push_back(i);
   }

   for(int i = 2;i <= n;i+=2){
      deq.push_front(i);
   }

   std::cout << "Deque: ";
   for (int x : deq)
      std::cout << x << " ";
   std::cout << std::endl;

}

//2

void removeFromBothEnds(std::deque<int> &deq,int k){
   for (int x : deq)
      std::cout << x << " ";
   std::cout << std::endl;
   for(int i = 0;i < k;i++){
      if(deq.size() == 0){
         return;
      }
      deq.pop_back();

      if(deq.size() == 0){
         return;
      }
      deq.pop_front();
      for (int x : deq)
         std::cout << x << " ";
      std::cout << std::endl;
   }
}

//3

void rotateDeque(std::deque<int> &deq,int k){
   if(k > 0){
      for(int i = 0;i < k;i++){
         int tmp = deq.back();
         deq.pop_back();
         deq.push_front(tmp);
      }
   }
   else{
      for(int i = 0;i < -k;i++){
         int tmp = deq.front();
         deq.pop_front();
         deq.push_back(tmp);
      }
   }
}

//4

class Logger{
   std::deque<std::string> s;
   int n;

public:
   Logger(int N) : n(N){}
   
   void add(std::string st){
      int size = 0;
      for(std::string x : s)
         size++;
      if(size == n){
         s.pop_front();
         s.push_back(st);
      }
      else 
         s.push_back(st);
   }

   void show(){
      for(std::string x : s){
         std::cout << x << " ";
      }
      std::cout << std::endl;
   }
};

//5

class SnakeGame {
private:
    int width, height;
    std::deque<std::pair<int, int>> snake; 
    std::pair<int, int> food;
    bool hasFood;

public:
    SnakeGame(int width, int height, int startY, int startX)
        : width(width), height(height), hasFood(false)
    {
        snake.push_back({startY, startX});
    }

    void spawnFood() {
        std::vector<std::pair<int, int>> emptyCells;

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                bool occupied = false;
                for (auto &seg : snake) {
                    if (seg.first == y && seg.second == x) {
                        occupied = true;
                        break;
                    }
                }
                if (!occupied)
                    emptyCells.push_back({y, x});
            }
        }

        if (!emptyCells.empty()) {
            food = emptyCells[std::rand() % emptyCells.size()];
            hasFood = true;
        }
    }

    bool move(int dy, int dx) {
        int newY = snake.front().first + dy;
        int newX = snake.front().second + dx;

        if (newY < 0 || newY >= height || newX < 0 || newX >= width) {
            std::cout << " snake hits the wall\n";
            return false;
        }

        for (auto &seg : snake) {
            if (seg.first == newY && seg.second == newX) {
                std::cout << " snake eats itself\n";
                return false;
            }
        }
        snake.push_front({newY, newX});

       
        if (hasFood && newY == food.first && newX == food.second) {
            hasFood = false;
            spawnFood(); 
        } else {
            snake.pop_back();
        }

        return true;
    }

    bool moveUp()    { return move(-1, 0); }
    bool moveDown()  { return move(1, 0); }
    bool moveLeft()  { return move(0, -1); }
    bool moveRight() { return move(0, 1); }

    void print() const {
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                bool printed = false;

                if (hasFood && food.first == y && food.second == x) {
                    std::cout << '*';
                    continue;
                }

                for (size_t i = 0; i < snake.size(); ++i) {
                    if (snake[i].first == y && snake[i].second == x) {
                        if (i == 0)
                            std::cout << '@'; 
                        else
                            std::cout << 'O'; 
                        printed = true;
                        break;
                    }
                }

                if (!printed)
                    std::cout << '.';
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
};

int main(){

   //1
   createAndFillDeque(10);

   std::cout << "----------------------------" << std::endl;

   //2

   std::cout << "removeFromBothEnds" << std::endl;

   std::deque<int> d = {1, 2, 3, 4, 5, 6,7,8};
   removeFromBothEnds(d, 10);
   std::cout << "Deque: ";
   for (int x : d)
      std::cout << x << " ";
   std::cout << std::endl;

   std::cout << "----------------------------" << std::endl;


   //3

   std::cout << "rotateDeque" << std::endl;
   std::deque<int> d1 = {1, 2, 3, 4, 5};
   for (int x : d1)
      std::cout << x << " ";
   std::cout << std::endl;

   std::cout << "rotate 2 : ";

   rotateDeque(d1, 2);

   for (int x : d1)
      std::cout << x << " ";
   std::cout << std::endl;


   std::cout << "rotate -3 : ";

   rotateDeque(d1, -3);

   for (int x : d1)
      std::cout << x << " ";
   std::cout << std::endl;


   std::cout << "----------------------------" << std::endl;

   //4
   std::cout << "class logger" << std::endl;

   Logger log(3);
   log.add("start");
   log.add("init");
   log.add("run");
   log.add("stop");
   log.show();

   std::cout << "----------------------------" << std::endl;

   //5

   SnakeGame game(10, 10, 5, 5);
   game.spawnFood();

   game.print();

   game.moveRight();
   game.print();

   game.moveDown();
   game.print();

   game.moveLeft();
   game.print();


   return 0;
}