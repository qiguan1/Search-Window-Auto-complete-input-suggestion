/*Duwei Wang, A10169673
 *Qihan Guan, A92413483 
 *Date: 2/18/16
 *PA3
 *benchdict.cpp - goes through multiple iterations of the dictionaries, 
 looking for 10 strings that are not present in the input text file. Used
 for benchmarking each of the 3 dictionaries, specifies initial start size, 
 increment, and number of iterations along with what text file to read into. 
 */

#include <fstream>
#include <unordered_set>
#include <chrono>
#include <string>
#include <iostream>
#include <unordered_map>
#include "DictionaryTrie.hpp"
#include "DictionaryBST.hpp"
#include "DictionaryHashtable.hpp"
#include "util.hpp"
#include <algorithm>
#include <iterator>

int main(int argc, char* argv[])
{
  //check for valid amount of arguments
  if (argc!=5) {
    std::cout<<"invalid number of arguments.\n";
    return -1;
  }

  ifstream in;
  Utils util;
  Timer timer;
  int min_size =atoi(argv[1]);
  int step_size = atoi(argv[2]);
  int num_iterations = atoi(argv[3]);
  //check for valid input - no neg numbers
  if (min_size<0 || step_size<0 || num_iterations <0) {
    std::cerr<<"invalid input"<<'\n';
    return -1;
  }
  //check for valid file
  in.open(argv[4], ios::in);
  if (!in.is_open()) {
    std::cout<<"invalid input file. \n";
    return -1;
  }

  in.seekg(0, ios_base::end);
  //check for empty file
  unsigned int len = in.tellg();
  if (len==0) {
    std::cout<<"file is empty. \n";
    return -1;
  }
  //seek to beginning
  in.seekg(0, ios_base::beg);
  //read line by line to find out the line count, aka number of words in dict
  in.unsetf(std::ios_base::skipws);
  unsigned line_count = std::count(
      std::istream_iterator<char>(in),
      std::istream_iterator<char>(), '\n');
  in.close();

  std::cout<<"DictionaryTrie"<<'\n';
  //iterate through the in
  for (int i=0;i<num_iterations;i++) {
    DictionaryTrie * dictTrie = new DictionaryTrie();
    in.open(argv[4], ios::in);
    in.seekg(0, ios_base::beg);
    //check if dict size is too small
    if ((int)line_count<min_size+i*step_size){
      std::cout<<"warning: dict size too small: size is "<<line_count<<'\n';
      util.load_dict(*dictTrie, in, line_count);
    }
    //otherwise, load the dictionary according to the user input
    else {
      util.load_dict(*dictTrie, in, min_size+i*step_size);
    }
    in.close();
    int test[num_iterations];
    //we decided to repeat the averaging based on what num_iterations is 
    for (int i=0;i<num_iterations;i++) {
      timer.begin_timer();
      dictTrie->find("diohsehtera at");
      dictTrie->find("zweoiwetoh");
      dictTrie->find("uhyeho ohawte a");
      dictTrie->find("btio ijoa");
      dictTrie->find("help i cant dothis");
      dictTrie->find("forever in cselabaaaaaa");
      dictTrie->find("lookatthetime");
      dictTrie->find("thisis eigthtest");
      dictTrie->find ("nowthe eleventh hour");
      dictTrie->find("finally finallydone");
      test[i] = timer.end_timer();
    }
    int result = 0;
    for (int i=0;i<num_iterations;i++) {
      result = result+test[i];
    }
    result = result/num_iterations;
    std::cout<<min_size+i*step_size<<"     "<<result<<'\n';
    //make a new dict and delete dict for every single num_iteration
    delete dictTrie;
  }

  //load the dicts one at a time, now for BST. Same process. 
  std::cout<<"DictionaryBST"<<'\n';
  for (int i=0;i<num_iterations;i++) {
    in.open(argv[4], ios::in);
    in.seekg(0, ios_base::beg);
    DictionaryBST * dictBST = new DictionaryBST();
    if ((int)line_count<min_size+i*step_size){
      std::cout<<"warning: dict size too small: size is "<<line_count<<'\n';
      util.load_dict(*dictBST, in, line_count);
    }
    else {
      util.load_dict(*dictBST, in, min_size+i*step_size);
    }
    in.close();
    int test[num_iterations];
    for (int i=0;i<num_iterations;i++) {
      timer.begin_timer();
      dictBST->find("diohsehtera at");
      dictBST->find("zweoiwetoh");
      dictBST->find("uhyeho ohawte a");
      dictBST->find("btio ijoa");
      dictBST->find("help i cant dothis");
      dictBST->find("forever in cselabaaaaaa");
      dictBST->find("lookatthetime");
      dictBST->find("thisis eigthtest");
      dictBST->find ("nowthe eleventh hour");
      dictBST->find("finally finallydone");
      test[i] = timer.end_timer();
    }
    int resultB = 0;
    for (int i=0;i<num_iterations;i++) {
      resultB = resultB+test[i];
    }
    resultB = resultB/num_iterations;
    std::cout<<min_size+i*step_size<<"     "<<resultB<<'\n';
    delete dictBST;
  }

  //now load the last dict, the hashtable. 
  std::cout<<"DictionaryHashtable"<<'\n';
  for (int i=0;i<num_iterations;i++) {
    DictionaryHashtable * dictHash = new DictionaryHashtable();
    in.open(argv[4], ios::in);
    in.seekg(0, ios_base::beg);
    if ((int)line_count<min_size+i*step_size){
      std::cout<<"warning: dict size too small: size is "<<line_count<<'\n';
      util.load_dict(*dictHash, in, line_count);
    }
    else {
      util.load_dict(*dictHash, in, min_size+i*step_size);
    }
    in.close();
    int test[num_iterations];
    for (int i=0;i<num_iterations;i++) {
      timer.begin_timer();
      dictHash->find("diohsehtera at");
      dictHash->find("zweoiwetoh");
      dictHash->find("uhyeho ohawte a");
      dictHash->find("btio ijoa");
      dictHash->find("help i cant dothis");
      dictHash->find("forever in cselabaaaaaa");
      dictHash->find("lookatthetime");
      dictHash->find("thisis eigthtest");
      dictHash->find ("nowthe eleventh hour");
      dictHash->find("finally finallydone");
      test[i] = timer.end_timer();
    }
    int resultH = 0;
    for (int i=0;i<num_iterations;i++) {
      resultH = resultH+test[i];
    }
    resultH = resultH/num_iterations;
    std::cout<<min_size+i*step_size<<"     "<<resultH<<'\n';
    delete dictHash;
  }

  //return 0 to indicate success. 
  return 0;
}
