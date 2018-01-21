/*Duwei Wang, A10169673
 *Qihan Guan, A92413483 
 *Date: 2/10/16
 *PA3
 *DictionaryHashtable.cpp -properly defines insert, find, destructor.
 uses the C++ unordered_set for the underlying structure.     
 */

#include "util.hpp"
#include "DictionaryHashtable.hpp"

/* Create a new Dictionary that uses a Hashset back end 
 * is empty*/
DictionaryHashtable::DictionaryHashtable(){}

/* Insert a word into the dictionary.
 * returns true if successful, false if not (duplicate, etc)
 * takes in a string  */
bool DictionaryHashtable::insert(std::string word) {
  unsigned int size = dictionaryUnS.size();
  dictionaryUnS.insert(word);
  //the unordered_set automatically rejects duplicates 
  if (dictionaryUnS.size()==size) {
    return false;
  }
  return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const {
  //make iterator
  std::unordered_set<std::string>::const_iterator got = 
    dictionaryUnS.find (word);
  //if iterator reached the end, it means it did not find 
  if ( got == dictionaryUnS.end() ) {
    return false;
  }
  return true;
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable() {
  dictionaryUnS.clear();
}
