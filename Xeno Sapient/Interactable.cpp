//
//  Interactable.cpp
//  Xeno Sapient
//
//  Created by Arthur Bacon on 9/6/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#include "Interactable.h"


using namespace xs_game;

/**
 * A simple constructor.
 */
Interactable::Interactable(std::string const& name) noexcept : name_(name)
{
  descriptoin_ = name + " Does NOT have a description. Interactable.";
  useFunction = []() { return true; };
}

/**
 * A simple constructor.
 */
Interactable::Interactable(std::string const& name, std::string const& description) noexcept : name_(name), descriptoin_(description)
{
  
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













