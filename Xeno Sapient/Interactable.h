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
#include <map>
#include <memory>

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
    bool setLambda(std::function<bool(std::shared_ptr<std::map<std::string, bool> >)> newLambda);
    /**
     * Below is a breif description of this... garbage looking type
     *
     * std::function<                       - The type is a lambda function, first and formost
     *               bool                   - The lambda returns a bool type
     *               (std::shared_ptr<                         - The lambda takes in a shared pointer...
     *                                std::map<                - of type Map...
     *                                         std::string,    - which pairs strings...
     *                                         bool            - to bool values
     *                                        >
     *                               >
     *               )
     *              >
     */
    
    /**
     * Getter for the lambda in this interactable object.
     * This lambda represents the efects of using this Interactable 
     * during the game, and will modify the Model folder in some way.    
     */
    std::function<bool(std::shared_ptr<std::map<std::string, bool> >)> getLambda() const;
    /**
     * Below is a breif description of this... garbage looking type
     *
     * std::function<                       - The type is a lambda function, first and formost
     *               bool                   - The lambda returns a bool type
     *               (std::shared_ptr<                         - The lambda takes in a shared pointer...
     *                                std::map<                - of type Map...
     *                                         std::string,    - which pairs strings...
     *                                         bool            - to bool values
     *                                        >
     *                               >
     *               )
     *              >
     */
    
    
  protected:
    
    
  private:
    
    std::string name_; /** The name of this item */
    std::string descriptoin_; /** The description of this Item */
    //TODO: Consider how to increase levels of descriptions
    
    /**
     * This is the function that will be run when the player 'uses' an interactabl.
     * Below is a breif description of this... garbage looking type
     * 
     * std::function<                       - The type is a lambda function, first and formost
     *               bool                   - The lambda returns a bool type
     *               (std::shared_ptr<                         - The lambda takes in a shared pointer...
     *                                std::map<                - of type Map...
     *                                         std::string,    - which pairs strings...
     *                                         bool            - to bool values
     *                                        >
     *                               >
     *               )
     *              >
     */
    std::function<bool(std::shared_ptr<std::map<std::string, bool> >)> useFunction;
    
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
