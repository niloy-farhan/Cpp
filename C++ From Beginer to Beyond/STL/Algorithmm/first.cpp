#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>


class Person{
private:
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age)
        :name{name}, age{age}{}

    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const {
        return(this->name == rhs.name && this->age == rhs.age);
    }

};

void find_test(){
    std::cout<<"\n=======================================\n";
    std::vector<int> vec {1,2,3,4,5};

    auto loc = std::find(std::begin(vec), std::end(vec), 5);

    if(loc != std::end(vec))
        std::cout <<"Found the number: " <<*loc <<std::endl;
    else
        std::cout <<"Couldn't find the number" <<std::endl;
}

int main(){


    return 0;
}