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
Item::Item(std::string name) noexcept : name_(name)
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



