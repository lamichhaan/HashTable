//File: <hashtable.h>
// Name: <Angat Lamichhane>
// Class: <CSIS 352>
// Program: <Assignment 8>
// Date: <05/03/2016>
// this is tempelated hash table  class

# ifndef _HASHTABLE_H_
# define _HASHTABLE_H_

# include <iostream>
# include <vector>
# include <list>
# include <stdexcept>
using namespace std;

template <class hashType>
class HashTable 
{
public:
  HashTable(const int tableSize,int (*hash)(const hashType&));
  // This is the constructor for the hash table class
  // precondition: none
  // postcondition: size of list is set
  // input: none
  //output: none
  
  int Collisions();
  // this is collisions method
  // precondition: none
  // postcondition:none
  // input: none
  //output: integer value
  
  void insert(const hashType& a);
  // this is insert method
  // precondition: hash table should not be full
  // postcondition: item is inserted
  // input: hashType
  //output: none
  
  bool search(const hashType& a);
  // this is search method
  // precondition: none
  // postcondition: none
  // input: none
  //output: boolean value
  
  void retrieve(hashType& a);
  // this is retrieve method
  // precondition: item exists
  // postcondition: none
  // input: hashType
  //output: none
  
  int (*hashValue)(const hashType&);
  // this is hashValue pointer to hash function
  // precondition: none
  // postcondition: size of list is set
  // input: none
  //output: a integer value
  
  int hash(const hashType&)const;
  // this is hash method
  // precondition: none
  // postcondition: value is set to an object
  // input: hashType
  //output: none
  
private:
  vector <list <hashType> >  aList;
  

};

#endif
/*************************************************************/
template <class hashType>
int HashTable <hashType> :: hash(const hashType& a)const
{
  return hashValue(a);
}


template <class hashType>
HashTable <hashType> :: HashTable(const int tableSize,int (*hash)(const hashType& a))
{
  if (tableSize <= 0)
    throw range_error("hash table is already full!");
  aList.resize(tableSize);
  hashValue = hash;
}

template <class hashType>
void HashTable <hashType> :: insert(const hashType &a)
{
  aList[hash(a)].push_back(a);
}
template <class hashType>
bool HashTable<hashType> :: search (const hashType& a)
{
  bool flag = false;
  typename list<hashType> :: iterator p;
  for (int i = 0;i<aList.size();i++)
  {
    for (p = aList[i].begin();p!=aList[i].end();p++)
    {
      if (*p == a)
	flag = true;
    }
  }
  return flag;
  
}

template <class hashType>
void HashTable<hashType> :: retrieve(hashType& a)
{
  typename list <hashType> :: iterator p;
  int index = 0;
  for (int i =0;i<aList.size();i++)
  {
    for (p = aList[i].begin();p!=aList[i].end();p++)
      if (*p ==a)
      {
	index = i;
	break;
      }
  }
  a.setValue(index);
}

template <class hashType>
int HashTable<hashType> :: Collisions()
{
  int ct = 0;
  int ct1 = 0;
  int exactCollisons;
  
  for(int i = 0;i<aList.size();i++)
  {
    if (!aList[i].empty())
    {
      ct++;
      ct1 += aList[i].size();
    }
  }
  exactCollisons = ct1 - ct;
  return exactCollisons;
}