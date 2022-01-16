#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

struct Person {
    int age;
    std::string name;

    Person(int n, std::string s) : age(n), name(s) {}
};
bool is_younger(const Person& person1, const Person& person2);

int main() {
    int N;
    std::cin >> N;

    std::vector<Person> people;
    for(int i = 0; i != N; ++i){
        int age; std::string name;
        std::cin >> age >> name;

        people.push_back(Person(age, name));
    }

    std::stable_sort(people.begin(), people.end(), is_younger);

    for(Person person : people)
        std::cout << person.age << " " << person.name << "\n";
}

bool is_younger(const Person& person1, const Person& person2) {
    return person1.age < person2.age;
}