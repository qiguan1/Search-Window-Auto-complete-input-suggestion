/*Duwei Wang, A10169673
 *Qihan Guan, A92413483 
 *Date: 2/10/16
 *PA3
 *DictionaryBST.hpp - uses the C++ unordered_set for the underlying structure.
 Class itself contains a dictionarySet, a set object, that the BST uses for 
 everything.       
*/

#ifndef DICTIONARY_BST_HPP
#define DICTIONARY_BST_HPP
#include <set>
#include <string>
using namespace std;
/**
 *  The class for a dictionary ADT, implemented as a BST
 * When you implement this class, you MUST use a balanced binary
 * search tree in its implementation.  The C++ set implements 
 * a balanced BST, so we strongly suggest you use that to store 
 * the dictionary.
 */
class DictionaryBST
{
public:

  /* Create a new Dictionary that uses a BST back end */
  DictionaryBST();

  /* Insert a word into the dictionary. */
  bool insert(std::string word);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Destructor */
  ~DictionaryBST();

private:
  // Add your own data members and methods here
  // the set we operate on
  set<string> dictionarySet;
  //iterator
  const set<string>::iterator iter;
};

#endif // DICTIONARY_BST_HPP
