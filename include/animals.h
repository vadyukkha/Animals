// Copyright 2024 by Contributors
#pragma once
#ifndef INCLUDE_ANIMALS_H
#define INCLUDE_ANIMALS_H

#include <string.h>
#include <stdint.h>
#include <iostream>
#include <string>

constexpr const char* __UNDEFINED__ = "Undefined";

class Animal {
 public:
    explicit Animal(
        const float& mass = 0.0,
        const char* sex = __UNDEFINED__,
        const char* color = __UNDEFINED__,
        const uint32_t& age = 0);

    Animal(const Animal& other);
    Animal(Animal&& other) noexcept;
    virtual ~Animal();

    void SetMass(const float& mass);
    void SetSex(const char* sex);
    void SetAge(const uint32_t& age);
    void SetColor(const char* color);

    float GetMass() const;
    char* GetSex() const;
    uint32_t GetAge() const;
    char* GetColor() const;

    Animal& operator=(const Animal& other);
    Animal& operator=(Animal&& other) noexcept;

    virtual const char* WhatDoesSay() const = 0;

 protected:
    float mass_;
    char* sex_;
    char* color_;
    uint32_t age_;
};

class Dog : public Animal {
 public:
    enum class Breed : uint16_t {
        UNDEFINED, LABRADOR_RETRIEVERS,
        GOLDEN_RETRIEVERS, SPITZ,
        POODLES, BULLDOGS,
        ROTTWEILERS, BEAGLES,
        DACHSHUNDS, BOXERS, HAVANESE};
    friend std::ostream& operator<<(std::ostream& os, const Dog::Breed& breed);

    explicit Dog(
        const float& mass = 0.0,
        const char* sex = __UNDEFINED__,
        const char* color = __UNDEFINED__,
        const uint32_t& age = 0,
        const char* name = __UNDEFINED__,
        const Breed& race = Breed::UNDEFINED);

    Dog(const Dog& other);
    Dog(Dog&& other) noexcept;
    ~Dog();

    char* GetName() const;
    Breed GetRace() const;

    void SetName(const char* name);
    void SetRace(const Breed& race);

    Dog& operator=(const Dog& other);
    Dog& operator=(Dog&& other) noexcept;

    const char* WhatDoesSay() const override;

 private:
    char* name_;
    Breed race_;
};

class Fox : public Animal {
 public:
    enum class TypeFox : uint16_t {
        UNDEFINED, GRAY_FOX, RED_FOX,
        FENNEC_FOX, ARCTIC_FOX, KIT_FOX};
    friend std::ostream& operator<<(std::ostream& os, const Fox::TypeFox& type);

    explicit Fox(
        const float& mass = 0.0,
        const char* sex = __UNDEFINED__,
        const char* color = __UNDEFINED__,
        const uint32_t& age = 0,
        const char* name = __UNDEFINED__,
        const TypeFox& type = TypeFox::UNDEFINED);

    Fox(const Fox& other);
    Fox(Fox&& other) noexcept;
    ~Fox();

    char* GetName() const;
    TypeFox GetType() const;
    uint64_t GetNumberRabbitsEaten() const;

    void SetName(const char* name);
    void SetType(const TypeFox& type);

    Fox& operator=(const Fox& other);
    Fox& operator=(Fox&& other) noexcept;

    void Eat();
    const char* WhatDoesSay() const override;

 private:
    char* name_;
    TypeFox type_;
    uint64_t numberRabbitsEaten_;
};

#endif  // INCLUDE_ANIMALS_H
