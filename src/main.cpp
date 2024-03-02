#include "../include/animals.h"

#define PRINT_MASS(text, mass) {std::cout << text << mass << std::endl;}
#define PRINT_SEX(text, sex) {if (sex != nullptr) std::cout << text << sex << std::endl; else std::cout << text << "nullptr" << std::endl;}
#define PRINT_COLOR(text, color) {if (color != nullptr) std::cout << text << color << std::endl; else std::cout << text << "nullptr" << std::endl;}
#define PRINT_AGE(text, age) {std::cout << text << age << std::endl;}
#define PRINT_NAME(text, name) {if (name != nullptr) std::cout << text << name << std::endl; else std::cout << text << "nullptr" << std::endl;}
#define PRINT_RACE(text, race) {std::cout << text << race << std::endl;}
#define PRINT_VOICE(text, voice) {std::cout << text << voice << std::endl;}
#define PRINT_TYPE(text, type) {std::cout << text << type << std::endl;}

int main() {
    std::cout << "Create dog1" << std::endl;

    Dog dog1(20.7, "Male", "Golden", 3, "Buddy", Dog::Breed::LABRADOR_RETRIEVERS);
    PRINT_MASS("Dog 1 mass: ", dog1.GetMass());
    PRINT_SEX("Dog 1 sex: ", dog1.GetSex());
    PRINT_COLOR("Dog 1 color: ", dog1.GetColor());
    PRINT_AGE("Dog 1 age: ", dog1.GetAge());
    PRINT_NAME("Dog 1 name: ", dog1.GetName());
    PRINT_RACE("Dog 1 race: ", dog1.GetRace());
    PRINT_VOICE("Dog 1 says: ", dog1.WhatDoesSay());
    std::cout << std::endl;

    std::cout << "Create Dog2 using copy-constructor" << std::endl;

    Dog dog2(dog1);
    PRINT_MASS("Dog 2 mass: ", dog2.GetMass());
    PRINT_SEX("Dog 2 sex: ", dog2.GetSex());
    PRINT_COLOR("Dog 2 color: ", dog2.GetColor());
    PRINT_AGE("Dog 2 age: ", dog2.GetAge());
    PRINT_NAME("Dog 2 name: ", dog2.GetName());
    PRINT_RACE("Dog 2 race: ", dog2.GetRace());
    PRINT_VOICE("Dog 2 says: ", dog2.WhatDoesSay());
    std::cout << std::endl;

    std::cout << "Create dog3 using move-constructor" << std::endl;

    Dog dog3 = std::move(dog2);
    PRINT_MASS("Dog 3 mass: ", dog3.GetMass());
    PRINT_SEX("Dog 3 sex: ", dog3.GetSex());
    PRINT_COLOR("Dog 3 color: ", dog3.GetColor());
    PRINT_AGE("Dog 3 age: ", dog3.GetAge());
    PRINT_NAME("Dog 3 name: ", dog3.GetName());
    PRINT_RACE("Dog 3 race: ", dog3.GetRace());
    PRINT_VOICE("Dog 3 says: ", dog3.WhatDoesSay());
    PRINT_MASS("Dog 2 mass after move: ", dog2.GetMass());
    PRINT_SEX("Dog 2 sex after move: ", dog2.GetSex());
    PRINT_COLOR("Dog 2 color after move: ", dog2.GetColor());
    PRINT_AGE("Dog 2 age after move: ", dog2.GetAge());
    PRINT_NAME("Dog 2 name after move: ", dog2.GetName());
    std::cout << std::endl;

    std::cout << "Update dog1" << std::endl;

    dog1.SetMass(25.1);
    dog1.SetSex("Female");
    dog1.SetAge(5);
    dog1.SetColor("Brown");
    dog1.SetName("Max");
    dog1.SetRace(Dog::Breed::GOLDEN_RETRIEVERS);
    PRINT_MASS("Dog 1 new mass: ", dog1.GetMass());
    PRINT_SEX("Dog 1 new sex: ", dog1.GetSex());
    PRINT_AGE("Dog 1 new age: ", dog1.GetAge());
    PRINT_COLOR("Dog 1 new color: ", dog1.GetColor());
    PRINT_NAME("Dog 1 new name: ", dog1.GetName());
    PRINT_RACE("Dog 1 new race: ", dog1.GetRace());
    std::cout << std::endl;

    std::cout << "Create dog4 using copy operator" << std::endl;

    Dog dog4;
    dog4 = dog1;
    PRINT_MASS("Dog 4 mass: ", dog4.GetMass());
    PRINT_SEX("Dog 4 sex: ", dog4.GetSex());
    PRINT_COLOR("Dog 4 color: ", dog4.GetColor());
    PRINT_AGE("Dog 4 age: ", dog4.GetAge());
    PRINT_NAME("Dog 4 name: ", dog4.GetName());
    PRINT_RACE("Dog 4 race: ", dog4.GetRace());
    std::cout << std::endl;

    std::cout << "Create dog5 using move operator" << std::endl;

    Dog dog5;
    dog5 = std::move(dog4);
    PRINT_MASS("Dog 5 mass: ", dog5.GetMass());
    PRINT_SEX("Dog 5 sex: ", dog5.GetSex());
    PRINT_COLOR("Dog 5 color: ", dog5.GetColor());
    PRINT_AGE("Dog 5 age: ", dog5.GetAge());
    PRINT_NAME("Dog 5 name: ", dog5.GetName());
    PRINT_RACE("Dog 5 race: ", dog5.GetRace());
    PRINT_MASS("Dog 4 mass after move: ", dog4.GetMass());
    PRINT_SEX("Dog 4 sex after move: ", dog4.GetSex());
    PRINT_COLOR("Dog 4 color after move: ", dog4.GetColor());
    PRINT_AGE("Dog 4 age after move: ", dog4.GetAge());
    PRINT_NAME("Dog 4 name after move: ", dog4.GetName());
    std::cout << std::endl;

    std::cout << "Create fox1" << std::endl;

    Fox fox1(7.5, "Female", "Red", 4, "Foxy", Fox::TypeFox::RED_FOX);
    PRINT_MASS("Fox 1 mass: ", fox1.GetMass());
    PRINT_SEX("Fox 1 sex: ", fox1.GetSex());
    PRINT_COLOR("Fox 1 color: ", fox1.GetColor());
    PRINT_AGE("Fox 1 age: ", fox1.GetAge());
    PRINT_NAME("Fox 1 name: ", fox1.GetName());
    PRINT_RACE("Fox 1 type: ", fox1.GetType());
    PRINT_VOICE("Fox 1 says: ", fox1.WhatDoesSay());
    std::cout << std::endl;

    std::cout << "Create fox2 using copy-constructor" << std::endl;

    Fox fox2(fox1);
    PRINT_MASS("Fox 2 mass: ", fox2.GetMass());
    PRINT_SEX("Fox 2 sex: ", fox2.GetSex());
    PRINT_COLOR("Fox 2 color: ", fox2.GetColor());
    PRINT_AGE("Fox 2 age: ", fox2.GetAge());
    PRINT_NAME("Fox 2 name: ", fox2.GetName());
    PRINT_RACE("Fox 2 type: ", fox2.GetType());
    PRINT_VOICE("Fox 2 says: ", fox2.WhatDoesSay());
    std::cout << std::endl;

    std::cout << "Create fox3 using move-constructor" << std::endl;

    Fox fox3 = std::move(fox2);
    PRINT_MASS("Fox 3 mass: ", fox3.GetMass());
    PRINT_SEX("Fox 3 sex: ", fox3.GetSex());
    PRINT_COLOR("Fox 3 color: ", fox3.GetColor());
    PRINT_AGE("Fox 3 age: ", fox3.GetAge());
    PRINT_NAME("Fox 3 name: ", fox3.GetName());
    PRINT_RACE("Fox 3 type: ", fox3.GetType());
    PRINT_VOICE("Fox 3 says: ", fox3.WhatDoesSay());
    PRINT_MASS("Fox 2 mass after move: ", fox2.GetMass());
    PRINT_SEX("Fox 2 sex after move: ", fox2.GetSex());
    PRINT_COLOR("Fox 2 color after move: ", fox2.GetColor());
    PRINT_AGE("Fox 2 age after move: ", fox2.GetAge());
    PRINT_NAME("Fox 2 name after move: ", fox2.GetName());
    std::cout << std::endl;

    std::cout << "Update fox1" << std::endl;

    fox1.SetMass(8.2);
    fox1.SetSex("Male");
    fox1.SetAge(3);
    fox1.SetColor("Gray");
    fox1.SetName("Finn");
    fox1.SetType(Fox::TypeFox::GRAY_FOX);
    PRINT_MASS("Fox 1 new mass: ", fox1.GetMass());
    PRINT_SEX("Fox 1 new sex: ", fox1.GetSex());
    PRINT_AGE("Fox 1 new age: ", fox1.GetAge());
    PRINT_COLOR("Fox 1 new color: ", fox1.GetColor());
    PRINT_NAME("Fox 1 new name: ", fox1.GetName());
    PRINT_RACE("Fox 1 new type: ", fox1.GetType());
    std::cout << std::endl;

    std::cout << "Create fox4 using copy operator" << std::endl;

    Fox fox4;
    fox4 = fox1;
    PRINT_MASS("Fox 4 mass: ", fox4.GetMass());
    PRINT_SEX("Fox 4 sex: ", fox4.GetSex());
    PRINT_COLOR("Fox 4 color: ", fox4.GetColor());
    PRINT_AGE("Fox 4 age: ", fox4.GetAge());
    PRINT_NAME("Fox 4 name: ", fox4.GetName());
    PRINT_RACE("Fox 4 type: ", fox4.GetType());
    std::cout << std::endl;

    std::cout << "Create fox5 using move operator" << std::endl;

    Fox fox5;
    fox5 = std::move(fox4);
    PRINT_MASS("Fox 5 mass: ", fox5.GetMass());
    PRINT_SEX("Fox 5 sex: ", fox5.GetSex());
    PRINT_COLOR("Fox 5 color: ", fox5.GetColor());
    PRINT_AGE("Fox 5 age: ", fox5.GetAge());
    PRINT_NAME("Fox 5 name: ", fox5.GetName());
    PRINT_RACE("Fox 5 type: ", fox5.GetType());
    PRINT_MASS("Fox 4 mass after move: ", fox4.GetMass());
    PRINT_SEX("Fox 4 sex after move: ", fox4.GetSex());
    PRINT_COLOR("Fox 4 color after move: ", fox4.GetColor());
    PRINT_AGE("Fox 4 age after move: ", fox4.GetAge());
    PRINT_NAME("Fox 4 name after move: ", fox4.GetName());

    return EXIT_SUCCESS;
}
