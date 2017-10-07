//
//  ConversationGraph.h
//  Xeno Sapient
//
//  Created by Arthur Bacon on 10/7/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#ifndef ConversationGraph_h
#define ConversationGraph_h

#include <string>
#include <memory>
#include <map>
#include <vector>


namespace xs_game {
  
  /**
   *
   */
  // TODO: I need to be able to
  //  1) conditionally display text
  //      - condations based off of model variables
  //  2) Modify model variables
  //  3) Travel down certain decision paths conditionally.
  class ConvoNode {
    
  public:
    
    /**
     * Returns the text to be read/ displayed at this poin in the converastion graph
     */
    std::string read();
    
    /**
     * Condition displays text, bsed off of the passed in modelVars. This will NOT
     * modify the model vars.
     */
    std::string read(const std::map<std::string, bool>& modelVars);
    
    /**
     * Folows the graph in the target direction.
     * For edges, the 'option' input is ignored.
     * For nodes, the opetion is 0 indexed.
     */
    std::shared_ptr<ConvoNode> followGraph(int option);
    
  protected:
    
    
  private:
    
    
    std::vector<std::shared_ptr<ConvoNode> > edges; // The directions in the conversation the player can take
    std::vector<std::string> playerSelectOptions; // The text for the options the player can select
    std::string beforeText; // Text that displays before the player options. The main beef of the convo/sceene
    
    std::vector<std::pair<std::string, bool> > requirements;
    
    std::vector<std::pair<std::string, bool> > changes;
    
    
  };
  
}


/*
 
 consider this:
 
 In the controller, we get the root of the conversation/ cutsceene graph
 
 We 'run' it, handing over i/o control over to the graph, passing over a refrence to the model's vars.
 The model's vars should exist in this new controller object, not in the ConversationGraph object.
 
 From there, we travel the graph:
 
 Edges are easy, just conditionally display then move to the next
 
 Nodes are more dificult:
 - conditionally display options    [ X X _ _ X ]   Actual [ 0 1 2 3 4 ]    Displayed [ 1 2 3 ]  { 0 1 4 }
 - player selects option i
 -  i -= 1
 - if i is a valid option, select it
 - if i is NOT a valid option
 - keep moving forward untill we find a valid option,
 - The player means that one, folow the edge/ display the edge then move to the next node
 
 Lets say the node option will modify the model vars
 
 Then once we select it (but before we travel down the selected edge) we must modify the vars
 But now, we have the 'actual' number that the player selected
 Call some function that takes in the actuall index of the edge,
 this function looks up in a different array a pair object of <string, bool> and will update the model vars to that
 
 This must be done for every node option, at least, we must check if the actuall index has a change to be made
 
 
 Lets say the change is the model compas object?
 Let's deal with that later...
 
 
 
 
 Whats the difference vetween an edge and a node?
 
 An edge only has 1 option
 
 A node has multiple
 
 Well, isn't an edge just a type of node?
 
 So what if we only have nodes? Each node points to the next node @ target direction?
 
 
 Only 1 type makes things easy...
 
 
 */



#endif /* ConversationGraph_h */






















