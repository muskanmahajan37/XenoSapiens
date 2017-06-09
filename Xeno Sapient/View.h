//
//  View.hpp
//  Xeno Sapient
//
//  Created by Arthur Bacon on 6/8/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#ifndef View_hpp
#define View_hpp

#include <stdio.h>
#include <string>
#include <vector>


namespace xs_game {
  
  /**
   * To control the game. Takes in commands from a View object,
   * interprets them and executes changes in the model.
   */
  class View {
    
  public:
    
    /**
     * Change the current room to be the next room in the specified direction.
     * If there is no room at the specified direction then return false and don't
     * change the current room.
     */
    //bool changeRoom(std::string dir);
    
    /**
     * Get the descriptior of the specified thing "at" in the current room.
     * If this room doesn't contain object refered to with at, then a default
     * message is returned.
     */
    //std::string look(std::string at);
    
    /**
     * Displayes the given message to the screen.
     */
    void display(std::string message);
    
    /**
     * Retrieve the next full input from the user.
     */
    std::string getInput();
    
    /**
     * Retrieve the next full input from the user, then
     * parses it into tokens, split whenever a space is found.
     */
    std::vector<std::string> getTokens();
    
    /**
     * Clear the entire display area.
     */
    void clear();
    
  protected:
    
    
  private:
    
    
    
    
  };
  
}





#endif /* View_hpp */
