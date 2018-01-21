/*Duwei Wang, A10169673
 *Qihan Guan, A92413483 
 *Date: 2/10/16
 *PA3
 *DictionaryBST.cpp -properly defines insert, find, destructor. dicitonaryBST
 uses the C++ set for the underlying structure.     
*/

#include "util.hpp"
#include "DictionaryBST.hpp"

/* Create a new Dictionary that uses a BST back end 
 * Nothing is in constructor*/
DictionaryBST::DictionaryBST(){
}

/* Insert a word into the dictionary. 
 * returns boolean - true or false
 * inserts a string */
bool DictionaryBST::insert(std::string word) {
  //if we didn't find word, return true
  if(dictionarySet.find(word)==dictionarySet.end()) {       
    dictionarySet.insert(word);
    return true;
  }
  //else, don't return 
  return false;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const {
  return dictionarySet.find(word)!=dictionarySet.end();
}


/* Destructor */
DictionaryBST::~DictionaryBST(){
  dictionarySet.clear();
}
