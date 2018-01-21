/*Duwei Wang, A10169673
 *Qihan Guan, A92413483 
 *Date: 2/19/16
 *PA3
 *DictionaryTrie.cpp - defines methods that are part of the DictionaryTrie,
 the constructor, destructor, insert, find, predict. DictionaryTrie is a 
 multiway tree that contains non duplicate lower case (with space) words 
 in a dictionary.   
 */

#include "DictionaryTrie.hpp"
#include <unordered_set>
#include <iostream>
#include <vector>
#include <algorithm>

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
  //make a new root
  root = new TrieNode();
}

/*the helper to destructor for DictionaryTrie - deletes nodes
 *takes in a TrieNode pointer, returns nothing*/
void DictionaryTrie::deleteAll(TrieNode* curr) {
  if (!curr) {
    return;
  }
  if (curr->getChild()) {
    for (auto iter = (curr->getChild())->begin(); iter!=(curr->getChild())->end();iter++) {
      if(*iter) {
	deleteAll(*iter);
      }
    }
  }
  delete curr;
}



/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq) {
  if (freq<=0 || word.empty()) {
    return false;
  }
  if (!(std::string::npos!=word.find_first_of("abcdefghijklmnopqrstuvwxyz "))){
    return false;
  }
  //start from root
  TrieNode* curr = root;
  //if root is empty
  if (root->getText()=='\0') {
    root->setText(word.at(0));
    //if word is length of 1, root is a word
    if (word.length()==1) {
      root->setText(word.at(0));
      root->setIsWord(true);
      root->setWord(word);
      root->setFreq(freq);
    }
  }

  //inserting word
  for(unsigned int i =0; i < word.length(); i++) {
    //if root is null - empty tree
    //else, tree is not empty
    //try to see if letter is in tree already using private method
    TrieNode* temp = curr->findMatch(word.at(i));
    //if a match has been found, pointer gets assigned to current 
    if(temp) {
      curr = temp;
    }
    //else you create a new node 
    if (!temp) {
      TrieNode* ptr = new TrieNode();
      ptr->setText(word.at(i));
      (curr->getChild())->push_back(ptr);
      curr = ptr;
    }
    //if we are on the last letter of word, and it's already in tree
    if(curr->getIsWord() == true && i==(word.length()-1)) {
      //curr->setText(word.at(i));
      return false;
    }
    //if we're at last letter, node is in tree, but word is not in tree
    if(i == (word.length() -1) && curr->getIsWord()==false) {
      //curr->setText(word.at(i));
      curr->setWord(word); 
      curr->setIsWord(true);
      curr->setFreq(freq);
    }  
  }
  //logic is set so that we're supposed to return true if not 
  //returned false already
  return true;   
}

/*it finds all the words starting with prefix
  takes in the vector of children and num_completions
  returns nothing */
void DictionaryTrie::findWords(std::vector<TrieNode*> curr, int num_completions){
  if (curr.empty()) {
    return;
  }
  //loop through the children vector
  for (auto iter = curr.begin(); iter!=curr.end();iter++) {
    //grab the word and maintain the size of pqueue to not
    //exceed the max num_completions 
    if(*iter) {
      if((*iter)->getIsWord()==true){
        //if the size of pqueue reaches max num_completions
	if ((int)pqueue.size()==num_completions){
	  if (*(*iter)<*(pqueue.top())){
	    pqueue.push(*iter);
	    pqueue.pop();
	  }
	}
	else{
	  pqueue.push(*iter);
	}

      }
      //recursive call findWords 
      findWords(*((*iter)->getChild()), num_completions);
    }
  }
}

/* Takes in a string word Return true if word is 
 * in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const {
  //check if the word is valid
  if (word.empty()) {
    return false;
  }
  if (!(std::string::npos!=word.find_first_of("abcdefghijklmnopqrstuvwxyz "))){
    return false;
  }

  //start at root
  TrieNode* curr = root;
  if (root->getChild()->empty()) {
    if (root->getText()==word[0] && word.length()==1) { 
      return true;
    }
    else return false;
  }
  //travel through the word
  for(unsigned int i = 0; i < word.length(); i++) {
    TrieNode* ptr = curr->findMatch(word[i]);
    //if match not found, findMatch returns null pointer
    if(ptr == NULL) {
      return false;
    }
    else curr = ptr;
  }
  //if we're on the last node, and flag is 'true', return true
  if(curr->getIsWord() == true) return true;
  else return false;
  return false;
}

/* Takes in a string prefix, returns pointer to last node of prefix*/
TrieNode * DictionaryTrie::findPrefix(std::string prefix){
  //start at root
  TrieNode* curr = root;
  //travel through the word
  for(unsigned int i = 0; i < prefix.length(); i++) {
    TrieNode* ptr = curr->findMatch(prefix[i]);
    //if match not found, findMatch returns null pointer
    if(ptr == NULL) {
      return NULL;
    }
    else curr = ptr;
  }
  if (curr) {
    if (curr->getIsWord()==true){
      pqueue.push(curr);
    }
  }
  return curr;
}

/* Return up to num_completions of the most frequent completions
 * of the prefix, such that the completions are words in the dictionary.
 * These completions should be listed from most frequent to least.
 * If there are fewer than num_completions legal completions, this
 * function returns a vector with as many completions as possible.
 * If no completions exist, then the function returns a vector of size 0.
 * The prefix itself might be included in the returned words if the prefix
 * is a word (and is among the num_completions most frequent completions
 * of the prefix)
 */
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix,
    unsigned int num_completions){
  //the vector of words we want to return
  std::vector<std::string> words;
  words.clear();
  //check if prefix and num_completions is valid
  if (num_completions<=0 || prefix.empty()) {
    return words;
  }
  if (!(std::string::npos!=prefix.find_first_of
	("abcdefghijklmnopqrstuvwxyz "))){
    return words;
  }
  //start at root
  TrieNode* curr;
  //now curr points to the last word of the prefix
  curr = findPrefix(prefix);
  if (curr){ 
    //if curr has children 
    if (!(curr->getChild()->empty())) {
      std::vector<TrieNode *> * temp = curr->getChild();
      //call findWords on the children vector
      findWords(*temp, num_completions);
      while(!pqueue.empty()) {
	words.push_back(pqueue.top()->getWord());
	pqueue.pop();
      }
      //reverse the vector to get correct order before return 
      std::reverse(words.begin(), words.end());
      return words;
    }
  }
  return words;
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){
  //call on helper method
  this->deleteAll(root);
}



