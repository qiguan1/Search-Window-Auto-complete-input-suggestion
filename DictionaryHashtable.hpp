/*Duwei Wang, A10169673
 *Qihan Guan, A92413483
 *Date: 2/10/16
 *PA3
 *DictionaryHashtable.hpp -uses the C++ unordered_set for the underlying 
 structure and has one as a private variable.      
 */


#ifndef DICTIONARY_HASHTABLE_HPP
#define DICTIONARY_HASHTABLE_HPP

#include <string>
#include <unordered_set>

/**
 * The class for a dictionary ADT, implemented as a Hashtable
 * When you implement this class, you MUST use a Hashtable
 * in its implementation.  The C++ unordered_set implements 
 * a Hashtable, so we strongly suggest you use that to store 
 * the dictionary.
 */
class DictionaryHashtable
{
public:

  /* Create a new Dictionary that uses a Hashset back end */
  DictionaryHashtable();

  /* Insert a word into the dictionary. */
  bool insert(std::string word);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Destructor */
  ~DictionaryHashtable();

private:
  // Add your own data members and methods here
  //the unordered_set that will be manipulated
   std::unordered_set<std::string> dictionaryUnS;

};

#endif // DICTIONARY_HASHTABLE_HPP
