//
//  Interactable.cpp
//  Xeno Sapient
//
//  Created by Arthur Bacon on 9/6/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#include "Interactable.h"

#include <iostream>

using namespace xs_game;

/**
 * A simple constructor.
 */
Interactable::Interactable(std::string const& name) noexcept : name_(name)
{
  descriptoin_ = name + " Does NOT have a description. Interactable.";
  useFunction = [](){ std::cout << "USED AN INTERACTABLE\n"; return true;};
}

/**
 * A simple constructor.
 */
Interactable::Interactable(std::string const& name, std::string const& description) noexcept : name_(name), descriptoin_(description)
{
  useFunction = [](){ std::cout << "USED AN INTERACTABLE\n"; return true;};
}

/**
 * A destructor
 */
Interactable::~Interactable() noexcept
{
  //TODO:
}

std::string Interactable::getName() const {
  return name_;
}

bool Interactable::setDescription(std::string description) {
  descriptoin_ = description;
  return true;
}

std::string Interactable::getDescription() const {
  return descriptoin_;
}


bool Interactable::setLambda(std::function<bool()> newLambda) {
  useFunction = newLambda;
  return true;
}




std::function<bool()> Interactable::getLambda() const {
  return useFunction;
}













