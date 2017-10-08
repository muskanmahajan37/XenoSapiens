//
//  ConvoNode.cpp
//  Xeno Sapient
//
//  Created by Arthur Bacon on 6/7/17.
//  Copyright © 2017 Arthur Bacon. All rights reserved.
//

#include "ConvoNode.h"



using namespace xs_game;




ConvoNode::ConvoNode(std::ifstream inFile) {
  std::string x;
  bool finishdBeforeText = false;
  while(getline(inFile, x)) {
    if (!finishdBeforeText) {
      // If we have NOT finished the beforeText field
      
      if (x.length() == 1 && x.at(0) == '=') {
        // If we found the first decision tag,
        finishdBeforeText = true;
      } else {
        // We haven't found the decision tag
        beforeText.append(x);
      }
    } else {
      // If we have finished the before text field
      
      if (x.length() == 1 && x.at(0) == '=') {
        // If we found the closing tag for the decision
        break;
      }
      // Else
      // If we have finished the before text field
      parceDecisionLine(x);
    } // End if
  } // End while(getline(...))
} // End constructor

ConvoNode::ConvoNode(std::string fileName) : ConvoNode(std::ifstream(fileName)) { }


void ConvoNode::parceDecisionLine(const std::string& line) {
  
  int openIndex = 0;
  
  bool setRequirements = false;
  bool setEdge = false;
  bool setChange = false;
  bool setPlayerSelectOptions = false;
  
  // Read the line one char at a time
  for (int i = 0; i < line.length(); i++) {
    
    // Look for an open meta data tag
    if (line.at(i) == '{' || line.at(i) == '(' || line.at(i) == '[') {
      
      openIndex = i;
      
      if (!setPlayerSelectOptions) {
        // If we have NOT set the playerSelectOptions for this line
        
        playerSelectOptions.push_back(line.substr(0, i + 1));
        setPlayerSelectOptions = true;
      }
      
      
    // Depending on the closing metadata tag, add the specific data to this object
    } else if (line.at(i) == '}' && !setEdge) {
      // If we find a closing link tag
      int substrDist = i - openIndex - 1;
      std::shared_ptr<std::string> temp = std::make_shared<std::string>(line.substr(openIndex + 1, substrDist));
      edges.push_back(temp);
      setEdge = true;
      
    } else if (line.at(i) == ']' && !setRequirements) {
      // If we find a closing requirements tag
      int substrDist = i - openIndex - 1;
      requirements.push_back(stringToPair(line.substr(openIndex + 1, substrDist)));
      setRequirements = true;
      
    } else if (line.at(i) == ')' && !setChange) {
      // If we find a closing changes tag
      int substrDist = i - openIndex - 1;
      changes.push_back(stringToPair(line.substr(openIndex + 1, substrDist)));
      setChange = true;
    }
  }
  
  // If nothing has been set yet then make sure to push back a blank value to keep the arrays equal in size.
  if (!setEdge) {
    edges.push_back(nullptr);
  }
  if (!setRequirements) {
    requirements.push_back(nullptr);
  }
  if (!setChange) {
    changes.push_back(nullptr);
  }
}


std::shared_ptr<std::pair<std::string, bool> > ConvoNode::stringToPair(const std::string& pairString) {
  int commaIndex = 0;
  std::string key;
  bool value = false;
  for (int i = 0; i < pairString.length(); i++) {
    if (pairString.at(i) == ',') {
      key = pairString.substr(0, i);
      commaIndex = i;
      break;
    }
  }
  
  if (commaIndex == 0) {
    // We never found a comma, crash everything
    throw std::length_error("No comma found");
  }
  // else
  
  if (pairString.at(commaIndex + 1) == 't' ||
      pairString.at(commaIndex + 1) == 'T' ||
      pairString.at(commaIndex + 2) == 't' ||
      pairString.at(commaIndex + 2) == 'T') {
    value = true;
  }
  
  std::shared_ptr<std::pair<std::string, bool> > result = std::make_shared<std::pair<std::string, bool> > (key, value);
  
  return result;
}

std::string ConvoNode::read(const std::map<std::string, bool>& modelVars) {
  std::string result;
  
  result += "----------------------------------------\n";
  result += beforeText + "\n";
  int optionDisplayNumber = 1;
  for (int i = 0; i < edges.size(); i++) { // All relevent field vectors should be the same size
    if (check(modelVars, requirements.at(i))) {
      // If the requirements are met
      result += "(" + std::to_string(optionDisplayNumber) + ") ";
      optionDisplayNumber += 1;
      result += playerSelectOptions.at(i) + "\n";
    }
  }
  
  return result;
}

bool ConvoNode::check(const std::map<std::string, bool> &modelVars, std::shared_ptr<std::pair<std::string, bool> > toBeChecked) {
  if (toBeChecked == nullptr || toBeChecked == NULL) {
    return true;
  }
  return modelVars.at(toBeChecked->first) == toBeChecked->second;
}


std::shared_ptr<ConvoNode> ConvoNode::followGraph(int option) {
  if (edges.at(option) == nullptr || edges.at(option) == NULL) {
    return nullptr;
  }

  return std::make_shared<ConvoNode>(edges.at(option));
}



