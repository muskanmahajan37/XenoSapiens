//
//  Player.h
//  Xeno Sapient
//
//  Created by Arthur Bacon on 6/7/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <list>
#include "Item.h"

namespace xs_game {
  
  /**
   * To represent the player. Contains all details about 
   * the player (invintory, previous actions, moral compass, etc.)
   */
  class Player {
    
  public:
    
    
  protected:
    
    
  private:

    int compass;                // the current moral level of the player
    std::list<Item> invintory;  // list of currently heald items
    
  };
}

#endif /* Player_h */
