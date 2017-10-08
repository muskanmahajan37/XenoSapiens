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
#include <sstream>
#include <fstream>




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
     * A consutructor that takes a flie that represents the root of the convo, and creates
     */
    ConvoNode(std::ifstream inFile);
    
    /**
     * A constructor that takes in just a file name
     */
    ConvoNode(std::string fileName);
    
    /**
     * Returns the text to be read/ displayed at this poin in the converastion graph
     */
    //std::string read();
    
    /**
     * Condition displays text, bsed off of the passed in modelVars. This will NOT
     * modify the model vars.
     */
    std::string read(const std::map<std::string, bool>& modelVars);
    
    /**
     * Folows the graph in the target direction. The operation is 0 indexed.
     * Will NOT do any validity checking with a model object.
     */
    std::shared_ptr<ConvoNode> followGraph(int option);
    
  protected:
    
    
  private:
    /**
     * A helper for the constructor that builds this node obj one player decisision line at a time
     */
    void parceDecisionLine(const std::string& line);
    /**
     * A helper for the parceDecisionLine function that converts a string in the form "key, value" or "key,value" into a pair for a map
     */
    std::shared_ptr<std::pair<std::string, bool> > stringToPair(const std::string& pairString);
    /**
     * Checks if the requirements are met in the given dictionary
     */
    bool check(const std::map<std::string, bool>& modelVars, std::shared_ptr<std::pair<std::string, bool> > toBeChecked);
    
    
    std::string beforeText; // Text that displays before the player options. The main beef of the convo/sceene
    
    /////////////////////
    // Fields related to player selection
    /** The requirements that must be true to display the playerSelectOption */
    std::vector<std::shared_ptr<std::pair<std::string, bool> > > requirements; // null => no requirements
    
    /** The change that will be made to the model vars if this option is selected */
    std::vector<std::shared_ptr<std::pair<std::string, bool> > > changes;      // null => no changes
    
    /** The file name of the next convonode object */
    std::vector<std::shared_ptr<std::string> > edges; // The directions the player can take, each element is a file name
    std::vector<std::string> playerSelectOptions; // The text for the options the player can select
    
    
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























