#define CATCH_CONFIG_MAIN
#include "../include/animals.h"
#include "catch.hpp"

constexpr const float accuracy = 0.0001f;

TEST_CASE("Test Dog class", "[dog]") {
    Dog dog1(20.7, "Male", "Golden", 3, "Buddy", Dog::Breed::LABRADOR_RETRIEVERS);
    REQUIRE(Approx(dog1.GetMass()).epsilon(accuracy) == 20.7);
    REQUIRE(strcmp(dog1.GetSex(), "Male") == 0);
    REQUIRE(strcmp(dog1.GetColor(), "Golden") == 0);
    REQUIRE(dog1.GetAge() == 3);
    REQUIRE(strcmp(dog1.GetName(), "Buddy") == 0);
    REQUIRE(dog1.GetRace() == Dog::Breed::LABRADOR_RETRIEVERS);
    REQUIRE(strcmp(dog1.WhatDoesSay(), "Woof") == 0);

    Dog dog2(dog1);
    REQUIRE(Approx(dog2.GetMass()).epsilon(accuracy) == 20.7);
    REQUIRE(strcmp(dog2.GetSex(), "Male") == 0);
    REQUIRE(strcmp(dog2.GetColor(), "Golden") == 0);
    REQUIRE(dog2.GetAge() == 3);
    REQUIRE(strcmp(dog2.GetName(), "Buddy") == 0);
    REQUIRE(dog2.GetRace() == Dog::Breed::LABRADOR_RETRIEVERS);
    REQUIRE(strcmp(dog2.WhatDoesSay(), "Woof") == 0);

    Dog dog3 = std::move(dog2);
    REQUIRE(Approx(dog3.GetMass()).epsilon(accuracy) == 20.7);
    REQUIRE(strcmp(dog3.GetSex(), "Male") == 0);
    REQUIRE(strcmp(dog3.GetColor(), "Golden") == 0);
    REQUIRE(dog3.GetAge() == 3);
    REQUIRE(strcmp(dog3.GetName(), "Buddy") == 0);
    REQUIRE(dog3.GetRace() == Dog::Breed::LABRADOR_RETRIEVERS);
    REQUIRE(strcmp(dog3.WhatDoesSay(), "Woof") == 0);
    REQUIRE(dog2.GetMass() == 0.0);
    REQUIRE(dog2.GetSex() == nullptr);
    REQUIRE(dog2.GetColor() == nullptr);
    REQUIRE(dog2.GetAge() == 0);
    REQUIRE(dog2.GetName() == nullptr);

    dog1.SetMass(25.1);
    REQUIRE(Approx(dog1.GetMass()).epsilon(accuracy) == 25.1);
    dog1.SetSex("Female");
    REQUIRE(strcmp(dog1.GetSex(), "Female") == 0);
    dog1.SetAge(5);
    REQUIRE(dog1.GetAge() == 5);
    dog1.SetColor("Brown");
    REQUIRE(strcmp(dog1.GetColor(), "Brown") == 0);
    dog1.SetName("Max");
    REQUIRE(strcmp(dog1.GetName(), "Max") == 0);
    dog1.SetRace(Dog::Breed::GOLDEN_RETRIEVERS);
    REQUIRE(dog1.GetRace() == Dog::Breed::GOLDEN_RETRIEVERS);

    Dog dog4;
    dog4 = dog1;
    REQUIRE(Approx(dog4.GetMass()).epsilon(accuracy) == 25.1);
    REQUIRE(strcmp(dog4.GetSex(), "Female") == 0);
    REQUIRE(strcmp(dog4.GetColor(), "Brown") == 0);
    REQUIRE(dog4.GetAge() == 5);
    REQUIRE(strcmp(dog4.GetName(), "Max") == 0);
    REQUIRE(dog4.GetRace() == Dog::Breed::GOLDEN_RETRIEVERS);

    Dog dog5;
    dog5 = std::move(dog4);
    REQUIRE(Approx(dog5.GetMass()).epsilon(accuracy) == 25.1);
    REQUIRE(strcmp(dog5.GetSex(), "Female") == 0);
    REQUIRE(strcmp(dog5.GetColor(), "Brown") == 0);
    REQUIRE(dog5.GetAge() == 5);
    REQUIRE(strcmp(dog5.GetName(), "Max") == 0);
    REQUIRE(dog5.GetRace() == Dog::Breed::GOLDEN_RETRIEVERS);
    REQUIRE(dog4.GetMass() == 0.0);
    REQUIRE(dog4.GetSex() == nullptr);
    REQUIRE(dog4.GetColor() == nullptr);
    REQUIRE(dog4.GetAge() == 0);
    REQUIRE(dog4.GetName() == nullptr);
}

TEST_CASE("Test Fox class", "[fox]") {
    Fox fox1(7.5, "Female", "Red", 4, "Foxy", Fox::TypeFox::RED_FOX);
    REQUIRE(Approx(fox1.GetMass()).epsilon(accuracy) == 7.5);
    REQUIRE(strcmp(fox1.GetSex(), "Female") == 0);
    REQUIRE(strcmp(fox1.GetColor(), "Red") == 0);
    REQUIRE(fox1.GetAge() == 4);
    REQUIRE(strcmp(fox1.GetName(), "Foxy") == 0);
    REQUIRE(fox1.GetType() == Fox::TypeFox::RED_FOX);
    REQUIRE(strcmp(fox1.WhatDoesSay(), "Ring-ding-ding-ding-dingeringeding!") == 0);

    Fox fox2(fox1);
    REQUIRE(Approx(fox2.GetMass()).epsilon(accuracy) == 7.5);
    REQUIRE(strcmp(fox2.GetSex(), "Female") == 0);
    REQUIRE(strcmp(fox2.GetColor(), "Red") == 0);
    REQUIRE(fox2.GetAge() == 4);
    REQUIRE(strcmp(fox2.GetName(), "Foxy") == 0);
    REQUIRE(fox2.GetType() == Fox::TypeFox::RED_FOX);
    REQUIRE(strcmp(fox2.WhatDoesSay(), "Ring-ding-ding-ding-dingeringeding!") == 0);

    Fox fox3 = std::move(fox2);
    REQUIRE(Approx(fox3.GetMass()).epsilon(accuracy) == 7.5);
    REQUIRE(strcmp(fox3.GetSex(), "Female") == 0);
    REQUIRE(strcmp(fox3.GetColor(), "Red") == 0);
    REQUIRE(fox3.GetAge() == 4);
    REQUIRE(strcmp(fox3.GetName(), "Foxy") == 0);
    REQUIRE(fox3.GetType() == Fox::TypeFox::RED_FOX);
    REQUIRE(strcmp(fox3.WhatDoesSay(), "Ring-ding-ding-ding-dingeringeding!") == 0);
    REQUIRE(fox2.GetMass() == 0.0);
    REQUIRE(fox2.GetSex() == nullptr);
    REQUIRE(fox2.GetColor() == nullptr);
    REQUIRE(fox2.GetAge() == 0);
    REQUIRE(fox2.GetName() == nullptr);

    fox1.SetMass(8.2);
    REQUIRE(Approx(fox1.GetMass()).epsilon(accuracy) == 8.2);
    fox1.SetSex("Male");
    REQUIRE(strcmp(fox1.GetSex(), "Male") == 0);
    fox1.SetAge(3);
    REQUIRE(fox1.GetAge() == 3);
    fox1.SetColor("Gray");
    REQUIRE(strcmp(fox1.GetColor(), "Gray") == 0);
    fox1.SetName("Finn");
    REQUIRE(strcmp(fox1.GetName(), "Finn") == 0);
    fox1.SetType(Fox::TypeFox::GRAY_FOX);
    REQUIRE(fox1.GetType() == Fox::TypeFox::GRAY_FOX);

    Fox fox4;
    fox4 = fox1;
    REQUIRE(Approx(fox4.GetMass()).epsilon(accuracy) == 8.2);
    REQUIRE(strcmp(fox4.GetSex(), "Male") == 0);
    REQUIRE(strcmp(fox4.GetColor(), "Gray") == 0);
    REQUIRE(fox4.GetAge() == 3);
    REQUIRE(strcmp(fox4.GetName(), "Finn") == 0);
    REQUIRE(fox4.GetType() == Fox::TypeFox::GRAY_FOX);

    Fox fox5;
    fox5 = std::move(fox4);
    REQUIRE(Approx(fox5.GetMass()).epsilon(accuracy) == 8.2);
    REQUIRE(strcmp(fox5.GetSex(), "Male") == 0);
    REQUIRE(strcmp(fox5.GetColor(), "Gray") == 0);
    REQUIRE(fox5.GetAge() == 3);
    REQUIRE(strcmp(fox5.GetName(), "Finn") == 0);
    REQUIRE(fox5.GetType() == Fox::TypeFox::GRAY_FOX);
    REQUIRE(fox4.GetMass() == 0.0);
    REQUIRE(fox4.GetSex() == nullptr);
    REQUIRE(fox4.GetColor() == nullptr);
    REQUIRE(fox4.GetAge() == 0);
    REQUIRE(fox4.GetName() == nullptr);
}
