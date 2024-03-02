// Copyright 2024 by Contributors
#include "../include/animals.h"

// Class Animal
Animal::Animal(const float& mass, const char* sex,
        const char* color, const uint32_t& age)
        : mass_(mass), age_(age) {
    size_t size_color = strlen(color) + 1;
    color_ = new char[size_color];
    snprintf(color_, size_color, "%s", color);
    size_t size = strlen(sex) + 1;
    sex_ = new char[size];
    snprintf(sex_, size, "%s", sex);
}

Animal::Animal(const Animal& other) : mass_(other.mass_), age_(other.age_) {
    size_t size_sex = strlen(other.sex_) + 1;
    sex_ = new char[size_sex];
    snprintf(sex_, size_sex, "%s", other.sex_);

    size_t size_color = strlen(other.color_) + 1;
    color_ = new char[size_color];
    snprintf(color_, size_color, "%s", other.color_);
}

Animal::Animal(Animal&& other) noexcept
        : mass_(std::move(other.mass_)), sex_(std::move(other.sex_)),
        color_(std::move(other.color_)), age_(std::move(other.age_)) {
    other.mass_ = 0.0;
    other.sex_ = nullptr;
    other.color_ = nullptr;
    other.age_ = 0;
}

Animal::~Animal() {
    delete[] sex_;
    delete[] color_;
}

float Animal::GetMass() const {
    return mass_;
}

char* Animal::GetSex() const {
    return sex_;
}

uint32_t Animal::GetAge() const {
    return age_;
}

char* Animal::GetColor() const {
    return color_;
}

void Animal::SetMass(const float& mass) {
    mass_ = mass;
}

void Animal::SetSex(const char* sex) {
    if (sex_ != nullptr) delete[] sex_;
    size_t size = strlen(sex) + 1;
    sex_ = new char[size];
    snprintf(sex_, size, "%s", sex);
}

void Animal::SetAge(const uint32_t& age) {
    age_ = age;
}

void Animal::SetColor(const char* color) {
    if (color_ != nullptr) delete[] color_;
    size_t size = strlen(color) + 1;
    color_ = new char[size];
    snprintf(color_, size, "%s", color);
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        SetMass(other.mass_);
        SetSex(other.sex_);
        SetAge(other.age_);
        SetColor(other.color_);
    }
    return *this;
}

Animal& Animal::operator=(Animal&& other) noexcept {
    if (this != &other) {
        std::swap(this->mass_, other.mass_);
        std::swap(this->sex_, other.sex_);
        std::swap(this->color_, other.color_);
        std::swap(this->age_, other.age_);

        other.mass_ = 0.0;
        other.sex_ = nullptr;
        other.color_ = nullptr;
        other.age_ = 0;
    }
    return *this;
}

// Class Dog
Dog::Dog(const float& mass, const char* sex,
        const char* color, const uint32_t& age,
        const char* name, const Breed& race)
        : Animal(mass, sex, color, age), race_(race) {
    size_t size = strlen(name) + 1;
    name_ = new char[size];
    snprintf(name_, size, "%s", name);
}

Dog::Dog(const Dog& other)
        : Animal(other), race_(other.race_) {
    size_t size = strlen(other.name_) + 1;
    name_ = new char[size];
    snprintf(name_, size, "%s", other.name_);
}

Dog::Dog(Dog&& other) noexcept : Animal(std::move(other)), name_(std::move(other.name_)),
        race_(std::move(other.race_)) {
    other.name_ = nullptr;
    other.race_ = Breed::UNDEFINED;
}

Dog::~Dog() {
    delete[] name_;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        SetName(other.name_);
        SetRace(other.race_);
    }
    return *this;
}

Dog& Dog::operator=(Dog&& other) noexcept {
    if (this != &other) {
        Animal::operator=(std::move(other));
        std::swap(this->name_, other.name_);
        std::swap(this->race_, other.race_);
        other.name_ = nullptr;
        other.race_ = Breed::UNDEFINED;
    }
    return *this;
}

char* Dog::GetName() const {
    return name_;
}

Dog::Breed Dog::GetRace() const {
    return race_;
}

void Dog::SetName(const char* name) {
    if (name_ != nullptr) delete[] name_;
    size_t size = strlen(name) + 1;
    name_ = new char[size];
    snprintf(name_, size, "%s", name);
}

void Dog::SetRace(const Breed& race) {
    race_ = race;
}

const char* Dog::WhatDoesSay() const {
    return "Woof";
}

// Class Fox
Fox::Fox(const float& mass, const char* sex,
        const char* color, const uint32_t& age,
        const char* name, const TypeFox& type)
        : Animal(mass, sex, color, age), type_(type) {
    size_t size = strlen(name) + 1;
    name_ = new char[size];
    snprintf(name_, size, "%s", name);
}

Fox::Fox(const Fox& other) : Animal(other), type_(other.type_) {
    size_t size = strlen(other.name_) + 1;
    name_ = new char[size];
    snprintf(name_, size, "%s", other.name_);
}

Fox::Fox(Fox&& other) noexcept : Animal(std::move(other)),
        name_(std::move(other.name_)), type_(std::move(other.type_)) {
    other.name_ = nullptr;
    other.type_ = TypeFox::UNDEFINED;
}

Fox::~Fox() {
    delete[] name_;
}

Fox& Fox::operator=(const Fox& other) {
    if (this != &other) {
        Animal::operator=(other);
        SetName(other.name_);
        SetType(other.type_);
    }
    return *this;
}

Fox& Fox::operator=(Fox&& other) noexcept {
    if (this != &other) {
        Animal::operator=(std::move(other));
        std::swap(this->name_, other.name_);
        std::swap(this->type_, other.type_);
        other.name_ = nullptr;
        other.type_ = TypeFox::UNDEFINED;
    }
    return *this;
}

char* Fox::GetName() const {
    return name_;
}

Fox::TypeFox Fox::GetType() const {
    return type_;
}

uint64_t Fox::GetNumberRabbitsEaten() const {
    return numberRabbitsEaten_;
}

void Fox::SetName(const char* name) {
    if (name_ != nullptr) delete[] name_;
    size_t size = strlen(name) + 1;
    name_ = new char[size];
    snprintf(name_, size, "%s", name);
}

void Fox::SetType(const TypeFox& type) {
    type_ = type;
}

void Fox::Eat() {
    numberRabbitsEaten_++;
}

const char* Fox::WhatDoesSay() const {
    switch (type_) {
        case TypeFox::RED_FOX:
            return "Ring-ding-ding-ding-dingeringeding!";
        case TypeFox::ARCTIC_FOX:
            return "Wa-pa-pa-pa-pa-pa-pow!";
        case TypeFox::FENNEC_FOX:
            return "Hatee-hatee-hatee-ho!";
        case TypeFox::GRAY_FOX:
            return "Joff-tchoff-tchoffo-tchoffo-tchoff!";
        case TypeFox::KIT_FOX:
            return "Fraka-kaka-kaka-kaka-kow!";
        default:
            return "Fox&&Dogs";
    }
}

// Перегрузка оператора << для enum класса Dog::Breed (addition)
std::ostream& operator<<(std::ostream& os, const Dog::Breed& breed) {
    switch(breed) {
        case Dog::Breed::LABRADOR_RETRIEVERS:
            os << "Labrador Retrievers";
            break;
        case Dog::Breed::GOLDEN_RETRIEVERS:
            os << "Golden Retrievers";
            break;
        case Dog::Breed::SPITZ:
            os << "Spitz";
            break;
        case Dog::Breed::POODLES:
            os << "Poodles";
            break;
        case Dog::Breed::BULLDOGS:
            os << "Bulldogs";
            break;
        case Dog::Breed::ROTTWEILERS:
            os << "Rottweilers";
            break;
        case Dog::Breed::BEAGLES:
            os << "Beagles";
            break;
        case Dog::Breed::DACHSHUNDS:
            os << "Dachshunds";
            break;
        case Dog::Breed::BOXERS:
            os << "Boxers";
            break;
        case Dog::Breed::HAVANESE:
            os << "Havanese";
            break;
        default:
            os << "Unknown";
            break;
    }
    return os;
}

// Перегрузка оператора << для enum класса Fox::TypeFox (addition)
std::ostream& operator<<(std::ostream& os, const Fox::TypeFox& type) {
    switch(type) {
        case Fox::TypeFox::GRAY_FOX:
            os << "Gray Fox";
            break;
        case Fox::TypeFox::RED_FOX:
            os << "Red Fox";
            break;
        case Fox::TypeFox::FENNEC_FOX:
            os << "Fennec Fox";
            break;
        case Fox::TypeFox::ARCTIC_FOX:
            os << "Arctic Fox";
            break;
        case Fox::TypeFox::KIT_FOX:
            os << "Kit Fox";
            break;
        default:
            os << "Unknown";
            break;
    }
    return os;
}
