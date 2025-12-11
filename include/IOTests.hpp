#ifndef IOTESTS_HPP
#define IOTESTS_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <ostream>
#include <string>

void PointTest() {
    struct Point {
        int x;
        int y;
    };

    std::vector<Point> points;
    while (points.size() < 7) {
        Point p{0, 0};
        std::cout << "Enter the x coordinate: ";
        std::cin >> p.x;
        std::cout << "Enter the y coordinate: ";
        std::cin >> p.y;
        points.push_back(p);
    }

    std::ofstream file("mydata.txt");

    for (const auto &p : points) {
        file << "(" << p.x << ", " << p.y << ")\n";
    }

    file.close();
    std::vector<Point> processed;
    std::ifstream ifile("mydata.txt");
    std::string line;

    while (std::getline(ifile, line)) {
        std::cout << line << "\n";
        Point p{0, 0};
        bool set_x = false;

        for (char c : line) {
            if (!std::isdigit(c)) { continue; }

            if (set_x) {
                p.y = c - '0';

                break;
            } else {
                p.x = c - '0';
                set_x = true;
            }
        }

        processed.push_back(p);
    }

    for (const auto &p : processed) {
        std::cout << p.x << ", " << p.y << "\n";
    }
}

void IOTest() {
    int birth_year = 2006;
    std::cout << birth_year << " in dec\t" << std::hex << birth_year << "in hex\t" << std::oct << birth_year << "in oct\n";
    std::cout << std::dec << (2025 - birth_year);
    int a, b, c, d;
    std::cin >> a >> std::oct >> b >> std::hex >> c >> d;
    std::cout << a << "\t" << b << "\t" << c << "\t" << d << "\n";
    double num = 1234567.89;
    std::cout << std::defaultfloat << num << " " << std::fixed << " " << num << " " << std::scientific << num << "\n";
    PointTest();
}

void ToLower() {
    std::ifstream ifile("beforelower.txt");

    if (!ifile) {
        return;
    }

    std::ofstream ofile("afterlower.txt");
    std::string line;
    
    while (std::getline(ifile, line)) {
        std::string lower = "";

        for (char c : line) {
            lower += std::tolower(c);
        }

        ofile << lower << "\n";
    }
}

void FindLinesWithWord(std::string file_name, std::string word) {
    std::ifstream ifile(file_name);
    
    if (!ifile) {
        return;
    }

    std::string line;
    int i = 1;

    while (std::getline(ifile, line)) {
        if (line.find(word) != std::string::npos) {
            std::cout << "Line number " << i << " contains the word: " << line << "\n";
        }

        i++;
    }
}

void RemoveVowelsFromFile(std::string file_name) {
    std::ifstream ifile(file_name);
    
    if (!ifile) {
        return;
    }

    std::string output;
    std::string line;

    while (std::getline(ifile, line)) {
        for (char c : line) {
            char check = std::tolower(c);

            if (check == 'a' || check == 'e' || check == 'i' || check == 'o' || check == 'u') { continue; }

            output += c;
        }

        output += "\n";
    }

    std::ofstream ofile(file_name);
    ofile << output;
}

struct Person {
    Person() {};
    Person(const std::string &first_name, const std::string &second_name, const int &age) {
        if (age < 0 || age >= 150) {
            throw std::runtime_error("NO!");
        }

        auto CheckStr = [&](const std::string &str) {
            for (const char &c : str) {
                if (!std::isalnum(c)) {
                    throw std::runtime_error("NO!");
                }
            }
        };

        CheckStr(first_name);
        CheckStr(second_name);

        this->first_name = first_name;
        this->second_name = second_name;
        this->age = age;
    }

    std::string GetFirstName() const { return first_name; }
    std::string GetSecondName() const { return second_name; }
    int GetAge() const { return age; }

private:
    std::string first_name;
    std::string second_name;
    int age;
};

std::istream &operator>>(std::istream &is, Person &p) {
    std::string first_name, second_name;
    int age;
    std::cout << "Enter first name: ";

    if (!(is >> first_name)) { return is; }

    std::cout << "Enter second name: ";

    if (!(is >> second_name)) { return is; }

    std::cout << "Enter age: ";

    if (!(is >> age)) { return is; }

    p = Person{first_name, second_name, age};

    return is;
}

std::ostream &operator<<(std::ostream &os, Person p) {
    return os << "Name: " << p.GetFirstName() << " " << p.GetSecondName() << ", Age: " << p.GetAge() << "\n";
}

void PersonTest() {
    Person p = {"Goofy", "Dog", 63};
    std::cout << p << "\n";
    std::vector<Person> people;
    for (int i = 0; i < 3; i++) {
        Person n;
        std::cin >> n;
        people.push_back(n);
    }

    for (const Person &p : people) {
        std::cout << p;
    }
}

#endif 