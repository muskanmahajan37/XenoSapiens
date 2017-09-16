//
//  Interactable.h
//  Xeno Sapient
//
//  Created by Arthur Bacon on 6/7/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#ifndef Interactable_h
#define Interactable_h

#include <stdio.h>
#include <string>
#include <functional>

namespace xs_game {
  
  /**
   * To represent a point of interest in a room that the player
   * can interact with.
   */
  class Interactable {
    
  public:
    
    /**
     * A simple constructor.
     */
    Interactable(std::string const& name) noexcept;
    
    
    /**
     * A simple constructor.
     */
    Interactable(std::string const& name, std::string const& description) noexcept;
    
    
    /**
     * A destructor
     */
    ~Interactable() noexcept;
    
    /**
     * A getter method for the name of this item.
     */
    std::string getName() const;
    
    /**
     * Set the description of an interactable.
     */
    bool setDescription(std::string description);
    
    /**
     * Get the description of an interactable.
     */
    std::string getDescription() const;
    
    /**
     * Set's this 
     */
    bool setLambda(std::function<bool()> newLambda);
    
    /**
     * Getter for the lambda in this interactable object.
     * This lambda represents the efects of using this Interactable 
     * during the game, and will modify the Model folder in some way.
     */
    std::function<bool()> getLambda() const;
    
  protected:
    
    
  private:
    
    std::string name_; /** The name of this item */
    std::string descriptoin_; /** The description of this Item */
    //TODO: Consider how to increase levels of descriptions
    
    std::function<bool()> useFunction;
    
    /*
     example function
     [](double d) -> int {
      if (d < 10) {
        return 0;
      } else {
        return d;
      }
     };
     */
    
  };
}

#endif /* Interactable_h */
