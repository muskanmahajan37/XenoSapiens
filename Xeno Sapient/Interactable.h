//
//  Interactable.h
//  Xeno Sapient
//
//  Created by Arthur Bacon on 6/7/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#ifndef Interactable_h
#define Interactable_h

#include <string.h>

namespace xs_game {
  
  /**
   * To represent a point of interest in a room that the player
   * can interact with.
   */
  class Interactable {
    
  public:
    
  virtual std::string description() const = 0;
    
  protected:
    
    
  private:
    
  };
}

#endif /* Interactable_h */
