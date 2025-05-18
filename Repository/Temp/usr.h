#include <string>
#include <iostream>
using namespace std;

/********* Begin *********/

class User {

public:
    
    string name;

    int book;

    static int user_count, book_count;

    static void GetState();

    User(string name, int book) {
        this->name = name;
        this->book = book;
        User::user_count++;
        User::book_count += book;
        std::cout << this->name << ' ' << this->book << " 进入" << endl;
    }

    ~User() {
        User::user_count--;
        User::book_count -= this->book;
        std::cout << this->name << ' ' << this->book << " 离开" << endl;
    }
};

int User::user_count = 0, User::book_count = 0;

void User::GetState() {
    std::cout << "书店人数:" << User::user_count;
    std::cout << ",书店共享书数量:" << User::book_count;
    std::cout << ",人均共享数量:" << User::book_count / User::user_count << endl;
}

/********* End *********/