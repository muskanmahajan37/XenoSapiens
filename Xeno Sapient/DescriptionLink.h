//
//  DescriptionLink.h
//  Xeno Sapient
//
//  Created by Arthur Bacon on 7/2/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#ifndef DescriptionLink_h
#define DescriptionLink_h

#include <stdio.h>

namespace xs_game {
  
  /**
   * To represent a link between two description objects.
   * Most commonly used to build dialogue trees or player choice 
   * structures.
   */
  class DescriptionLink {
    
  public:
    
    /*
     * Read this 
     */
    
    
  protected:
    
  private:
    
    std::string description;
    
    std::map<std::string, std::shared_ptr<DescriptionLink>> connection;
  
    
  };
  
}



#endif /* DescriptionLink_h */
