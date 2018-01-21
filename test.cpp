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

int main(int argc, char* argv[])
{
	ifstream in;

	DictionaryBST dict1;
	DictionaryHashtable dict2;

	DictionaryTrie * dict3 = new DictionaryTrie();

	DictionaryBST * dict5 = new DictionaryBST();

	DictionaryHashtable * dict6 = new DictionaryHashtable();

	Utils util;
	in.open(argv[1], ios::in);
	util.load_dict(*dict3, in);
	in.close();
       // bool a = dict3->insert("jhweraoih", 235);
//	cerr<<"BST"<<a<<'\n';
	bool b = dict3->find("jhweraoih");
	cerr<<"BST"<<b<<'\n';
	cerr<<dict3->find("cheer")<<" find IN bigDICT cheer"<<'\n';
	cerr<<dict3->find("halcyon")<<" find BIN bigDICT halcyon"<<'\n';
   //     cerr<<dict3->insert("abamps", 5634)<<" insert dup IN DICT abamps"<<'\n';
   cerr<<dict3->find("abamps")<<" find IN DICT abamps"<<'\n';


//dict3->insert("e", 235);
 cerr<<dict3->find("e")<<" find e"<<'\n';



std::cerr<<"prefix c"<<'\n';
std::vector<string> tempa42= dict3->predictCompletions("c", 10);
for (unsigned int i=0;i<tempa42.size();i++) {
cout<<tempa42.at(i)<<'\n';
}

std::cerr<<"prefix b"<<'\n';
std::vector<string> tempa42a= dict3->predictCompletions("b", 10);
for (unsigned int i=0;i<tempa42a.size();i++) {
cout<<tempa42a.at(i)<<'\n';
}

/*

std::cerr<<"prefix co"<<'\n';
std::vector<string> tempa44145= dict3->predictCompletions("co", 5);
for (unsigned int i=0;i<tempa44145.size();i++) {
cout<<tempa44145.at(i)<<'\n';
}

 * "come" with frequency 709087
"could" with frequency 681109
"couldnt" with frequency 282249
"country" with frequency 226940
"company" with frequency 207990
 * 

std::cerr<<"prefix cou"<<'\n';
std::vector<string> tempa42= dict3->predictCompletions("cou", 5);
for (unsigned int i=0;i<tempa42.size();i++) {
cout<<tempa42.at(i)<<'\n';
}


"could" with frequency 681109
"couldnt" with frequency 282249
"country" with frequency 226940
"course" with frequency 113235
"could nt" with frequency 86214 <-- non-unique answers here!
 *
 * 
std::cerr<<"prefix coun"<<'\n';
std::vector<string> tempa52= dict3->predictCompletions("coun", 5);
for (unsigned int i=0;i<tempa52.size();i++) {
cout<<tempa52.at(i)<<'\n';
}

"country" with frequency 226940
"count" with frequency 31711
"county" with frequency 23303
"countian" with frequency 14718
"counts" with frequency 13556 <-- non-unique answers here!
 *
 * 



"be" with frequency 12756143
"but" with frequency 1954127
"by" with frequency 1531322
"bart" with frequency 900093
"because" wth frequency 494698 


std::cerr<<"prefix: able"<<'\n';
 std::vector<string> temp11= dict3->predictCompletions("able", 2134);     
for (unsigned int i=0;i<temp11.size();i++) {
cout<<temp11.at(i)<<'\n';
}


std::cerr<<"prefix a "<<'\n';
std::vector<string> temp445= dict3->predictCompletions("a", 30);
for (unsigned int i=0;i<temp445.size();i++) {
cout<<temp445.at(i)<<'\n';
}

std::cerr<<"prefix abandon "<<'\n';
std::vector<string> temp4= dict3->predictCompletions("abandon", 2134);
for (unsigned int i=0;i<temp4.size();i++) {
cout<<temp4.at(i)<<'\n';
}



std::cerr<<"prefix: abamps"<<'\n';
 std::vector<string> temp= dict3->predictCompletions("abamps", 2134);     
for (unsigned int i=0;i<temp.size();i++) {
cout<<temp.at(i)<<'\n';
}


std::cerr<<"prefix: abducted"<<'\n';
 std::vector<string> temp111= dict3->predictCompletions("abducted", 2134);     
for (unsigned int i=0;i<temp111.size();i++) {
cout<<temp111.at(i)<<'\n';
}



std::cerr<<"prefix: ab "<<'\n';
 std::vector<string> temp1= dict3->predictCompletions("ab", 2134);
for (unsigned int i=0;i<temp1.size();i++) {
cout<<temp1.at(i)<<'\n';
}


std::cerr<<"prefix: abam"<<'\n';
 std::vector<string> temp2= dict3->predictCompletions("abam", 2134);
for (unsigned int i=0;i<temp2.size();i++) {
cout<<temp2.at(i)<<'\n';
}


std::cerr<<"prefix: not"<<'\n';
 std::vector<string> temp32= dict3->predictCompletions("not", 5);
for (unsigned int i=0;i<temp32.size();i++) {
cout<<temp32.at(i)<<'\n';
}

std::cerr<<"prefix aban"<<'\n';
 std::vector<string> temp3= dict3->predictCompletions("aban", 2134);
for (unsigned int i=0;i<temp3.size();i++) {
cout<<temp3.at(i)<<'\n';
}



 	in.open(argv[1], ios::in);

	util.load_dict(dict1, in);
	in.close();

	in.open(argv[1], ios::in);
	in.seekg(0, ios_base::beg);
	util.load_dict(dict2, in);
	cerr<<"loaded Hash"<<'\n';
	in.close();

	in.open(argv[1], ios::in);
	in.seekg(0, ios_base::beg);
	util.load_dict(*dict3, in);
	cerr<<"loaded MultiwayTrie"<<'\n';
	in.close();


	in.open(argv[1], ios::in);
	in.seekg(0, ios_base::beg);
	util.load_dict(*dict5, in);
	cerr<<"loaded BST 'new'"<<'\n';
	in.close();


	in.open(argv[1], ios::in);
	in.seekg(0, ios_base::beg);
	util.load_dict(*dict6, in);
	cerr<<"loaded Hash 'new'"<<'\n';
	in.close();


	bool a = dict1.insert("jhweraoih");
	cerr<<"BST"<<a<<'\n';
	bool b = dict1.find("jhweraoih");
	cerr<<"BST"<<b<<'\n';
	cerr<<dict1.find("abandonments")<<" find BST IN DICT abandonments"<<'\n';
	cerr<<dict1.find("abamps")<<" find BST IN DICT abamps"<<'\n';
        cerr<<dict1.insert("abamps")<<" insert dup BST IN DICT abamps"<<'\n';
	 

	bool a2 = dict2.insert("jhweraoih");
	cerr<<"Hash"<<a2<<'\n';
	bool b2 = dict2.find("jhweraoih");
	cerr<<"hash"<<b2<<'\n';
	cerr<<dict2.find("abandonment")<<" find HASH IN DICT abandonment"<<'\n';
	cerr<<dict2.find("abandon")<<" find HASH IN DICT abandon"<<'\n';
cerr<<dict2.insert("abandon")<<" dup insert HASH IN DICT abandon"<<'\n';


	bool a54 = dict3->insert("f", 2);

std::cerr<<"prefix: able"<<'\n';
 std::vector<string> temp11= dict3->predictCompletions("able", 2134);     
for (unsigned int i=0;i<temp11.size();i++) {
cout<<temp11.at(i)<<'\n';
}


std::cerr<<"prefix abandon "<<'\n';
std::vector<string> temp4= dict3->predictCompletions("abandon", 2134);
for (unsigned int i=0;i<temp4.size();i++) {
cout<<temp4.at(i)<<'\n';
}



std::cerr<<"prefix: abamps"<<'\n';
 std::vector<string> temp= dict3->predictCompletions("abamps", 2134);     
for (unsigned int i=0;i<temp.size();i++) {
cout<<temp.at(i)<<'\n';
}


std::cerr<<"prefix: abducted"<<'\n';
 std::vector<string> temp111= dict3->predictCompletions("abducted", 2134);     
for (unsigned int i=0;i<temp111.size();i++) {
cout<<temp111.at(i)<<'\n';
}



std::cerr<<"prefix: ab "<<'\n';
 std::vector<string> temp1= dict3->predictCompletions("ab", 2134);
for (unsigned int i=0;i<temp1.size();i++) {
cout<<temp1.at(i)<<'\n';
}


std::cerr<<"prefix: abam"<<'\n';
 std::vector<string> temp2= dict3->predictCompletions("abam", 2134);
for (unsigned int i=0;i<temp2.size();i++) {
cout<<temp2.at(i)<<'\n';
}


std::cerr<<"prefix: not"<<'\n';
 std::vector<string> temp32= dict3->predictCompletions("not", 5);
for (unsigned int i=0;i<temp32.size();i++) {
cout<<temp32.at(i)<<'\n';
}
	cerr<<"trie inserting f result is   "<<a54<<'\n';
	bool b6 = dict3->find("f");
	cerr<<"trie find f result is   "<<b6<<'\n';


	bool a3 = dict3->insert("jhweraoih", 235);
	cerr<<"trie inserting jhweraoih for first time   "<<a3<<'\n';
	bool b3 = dict3->find("jhweraoih");
	cerr<<"trie find jhweraoih for first time  "<<b3<<'\n';
	cerr<<dict3->find("abandoners")<<"Multiwaytrie in dict abandoners"<<'\n';


	bool a8 = dict3->insert("jhweraoih", 235);
	cerr<<"trie dup"<<a8<<'\n';

	DictionaryTrie * dict4 = new DictionaryTrie();

	delete dict4;


	bool c = dict5->insert("aahgtae er f");
	cerr<<"BST"<<c<<'\n';
	bool d = dict5->find("aahgtae er f");
	cerr<<"BST"<<d<<'\n';
	cerr<<dict5->find("abamps")<<"BST in dict abamps"<<'\n';
	cerr<<dict5->find("abandoning")<<" abandoning BST in dict"<<'\n';

	bool c1 = dict6->insert("aahgtae er f awet");
	cerr<<"Hash"<<c1<<'\n';
	bool d1 = dict6->find("aahgtae er f awer");
	cerr<<"Hash"<<d1<<'\n';
	bool d2 = dict6->find("abamps");
	cerr<<"Hash in dict abamps"<<d2<<'\n';
	cerr<<dict6->find("abandoners")<<"BST in dict abandoners"<<'\n';
*/

	delete dict5;
	delete dict6;

	delete dict3;

}


