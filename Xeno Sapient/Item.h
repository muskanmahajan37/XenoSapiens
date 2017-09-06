//
//  Item.hpp
//  Xeno Sapient
//
//  Created by Arthur Bacon on 9/6/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <string>


namespace xs_game {
  
  class Item {
    
  public:
    
    /**
     * A simple constructor.
     */
    Item(std::string name) noexcept;
    
    /**
     * A destructor
     */
    ~Item() noexcept;
    
    /**
     * A getter method for the name of this item.
     */
    std::string getName() const;
    
  protected:
    
    
  private:
    
    std::string name_; /** The name of this item */
  };
  
}








#endif /* Item_hpp */
