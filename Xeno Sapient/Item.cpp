//
//  Item.cpp
//  Xeno Sapient
//
//  Created by Arthur Bacon on 9/6/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#include "Item.h"


using namespace xs_game;

/**
 * A simple constructor.
 */
Item::Item(std::string const& name) noexcept : name_(name)
{
  descriptoin_ = name + " Does NOT have a description";
}

/**
 * A simple constructor.
 */
Item::Item(std::string const& name, std::string const& description) noexcept : name_(name), descriptoin_(description)
{
  
}

/**
 * A destructor
 */
Item::~Item() noexcept
{
  //TODO:
}

std::string Item::getName() const {
  return name_;
}

std::string Item::getDescription() const {
  return descriptoin_;
}



