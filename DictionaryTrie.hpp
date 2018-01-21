/*Duwei Wang, A10169673
 *Qihan Guan, A92413483
 *Date: 2/10/16
 *PA3
 *DictionaryTrie.hpp - defines all methods, and variables. DictionaryTrie is a 
 multiway tree that contains non duplicate lower case (with space) words 
 in a dictionary. Also contains the DictionaryNode class in its entirety.    
 */
#ifndef DICTIONARY_TRIE_HPP
#define DICTIONARY_TRIE_HPP
#include <vector>
#include <string>
#include <vector>
#include <queue>

/**
 *  The class for a DictionaryTrie node, and it contains the 
 *  ALPHABET_SIZE, isWord marker, the vector containing its children,
 *  the 'letter' it has, and the frequency.  
 */
class TrieNode{
  private: 
    const int ALPHABET_SIZE = 27; 
    bool isWord;  //only the last letter in the word returns true
    std::vector<TrieNode*> child = std::vector<TrieNode*>
      (ALPHABET_SIZE, (TrieNode*)0);  //Its children
    char text;    //the LETTER
    unsigned int freq;   //how many examples of this word there is
    std::string word; //the whole WORD - only in the last letter 
  public:
    //these are small short helper methods
    TrieNode(){isWord = false; text='\0'; freq = 0; word = "\0";}
    ~TrieNode() {child.clear();}
    void setText(char str){text = str;}
    void setFreq(unsigned int num){freq = num;}
    void setWord(std::string str){word = str;}
    std::string getWord(){return word;}
    void setIsWord(bool val){isWord = val;}
    char getText() {return this->text;}
    unsigned int getFreq(){return freq;}
    bool getIsWord(){return isWord;}
    //returns pointer to the children vector
    std::vector<TrieNode*> * getChild() {return &child;}

    //findMatch private method, part of TNode. Goes through
    //the node's children to try to find a match. 
    TrieNode* findMatch(char ch){
      if (child.size()<1) {
	return NULL;
      }
      for(unsigned int j = 0; j < child.size(); j++) {
	TrieNode* ptr = child.at(j);
	if(ptr!=NULL && ptr->getText() == ch) {
	  return ptr;
	}
      }
      return NULL;
    }
    //delete the vector 
    void deleteVector() {
      child.clear();}

    //less than comparison for the TrieNode
    bool operator<(const TrieNode& other){
      //if counts are different, compare counts
      if (freq!=other.freq) return freq>other.freq;
      //
      return text<other.text;
    }
};

//comparator class for priority queue
class TrieNodePtrComp{
  public:
    bool operator()(TrieNode*& a, TrieNode*& b) const{
      return *a < *b;
    }
};

/**
 *  The class for a dictionary ADT, implemented as a trie
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie, but you must use one or the other.
 *
 */
class DictionaryTrie
{
  public:

    /* Create a new Dictionary that uses a Trie back end */
    DictionaryTrie();

    /* Insert a word with its frequency into the dictionary.
     * Return true if the word was inserted, and false if it
     * was not (i.e. it was already in the dictionary or it was
     * invalid (empty string) */
    bool insert(std::string word, unsigned int freq);

    /* Return true if word is in the dictionary, and false otherwise */
    bool find(std::string word) const;

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
    std::vector<std::string>
      predictCompletions(std::string prefix, unsigned int num_completions);

    /* Destructor */
    ~DictionaryTrie();




  private:
    TrieNode * root;
    //helper method for destructor
    void deleteAll(TrieNode* curr);
    //priority queue for perdictCompletions, storing the words
    std::priority_queue<TrieNode*, std::vector<TrieNode*>, 
      TrieNodePtrComp> pqueue;
    //recursively find all words that match the prefix
    void findWords(std::vector<TrieNode*> curr, int num_completions);
    //traverse to the last letter of the prefix and return that pointer
    TrieNode * findPrefix(std::string prefix); 
    //return the root
    TrieNode * returnRoot() {
      return this->root;
    }
};


#endif // DICTIONARY_TRIE_HPP
