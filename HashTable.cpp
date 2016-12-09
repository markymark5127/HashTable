//
//  HashTable.cpp
//

#include "HashTable.h"
#include "Flags.h"

using namespace std;
/* **************************************************************** */

#if CONSTRUCTOR || ALL
HashTable::HashTable(int tableSize)
{
    // TODO: Constructor
    size = tableSize;
    table = new Node*[size];
    for(int i=0;i<size;i++)
    {
        table[i]= NULL;
    }

}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
HashTable::~HashTable()
{
    // TODO: Destructor
    delete[] table;
}
#endif

/* **************************************************************** */

#if INSERT || ALL
    // TODO: insert() method
void HashTable::insert(string x)
{

    if(!find(x))
    {
        int i;
        i = hash(x);
        Node* node = table[i];
        table[i] = new Node(x,node);
    }
}
#endif

/* **************************************************************** */

#if FIND || ALL
    // TODO: find() method
bool HashTable::find(string x)
{
    Node* node;
    int i=hash(x);
    node = table[i];
    while (node != NULL) {
        if(node->data ==x)
        {return true;}
        node = node->next;
    }
    return false;
}
#endif

/* **************************************************************** */

#if REMOVE || ALL
    // TODO: remove() method
void HashTable::remove(string x)
{
    if(find(x))
    {
        int i;
        i = hash(x);
        Node* node = table[i];
        if(table[i]->data == x)
        {
            table[i] = table[i]->next;
        }
        else if(table[i] != NULL)
        {
            while (node->next->data != x)
            {
                node = node->next;
            }
            node->next = node->next->next;
        }



    }

}
#endif

/* **************************************************************** */

#if LOADFACTOR || ALL
    // TODO: loadFactor() method
float HashTable::loadFactor()
{
    Node* node;
    float numOfNodes=0;
    for (int i = 0; i < size; i++) {

        node = table[i];
        while (node != NULL) {
            node = node->next;
            numOfNodes++;
        }
    }
    return numOfNodes/size;
}
#endif

/* **************************************************************** */

#if MAXCHAINLENGTH || ALL
    // TODO: maxChainLength() method
void HashTable::maxChainLength(int& maxLength, int& maxSlotIndex)
{
    Node* node;
    int maxLen=0;
    int maxSlot=0;
    int currLen=0;
    float numOfNodes=0;
    for (int i = 0; i < size; i++) {

        node = table[i];
        while (node != NULL) {
            node = node->next;
            currLen++;
        }
        if(currLen > maxLen)
        {
            maxLen = currLen;
            maxSlot = i;
        }
        currLen = 0;
    }
    maxLength = maxLen;
    maxSlotIndex = maxSlot;
}
#endif

/* **************************************************************** */

#if NUMEMPTYSLOTS || ALL
    // TODO: numEmptySlots() method
int HashTable::numEmptySlots()
{
    int numEmpty=0;
    for (int i = 0; i < size; i++) {
        if (table[i] == NULL) {
            numEmpty++;
        }
    }
    return numEmpty;
}
#endif

/* **************************************************************** */



/* **************************************************************** */
/* Do NOT modify anything below this line                           */
/* **************************************************************** */

#ifndef BUILD_LIB
unsigned int HashTable::hash(std::string x) {
    unsigned int hashCode = 0;
    std::string::iterator it;
    for (it=x.begin(); it < x.end(); it ++) {
        hashCode = *it + (hashCode << 5) - hashCode;
    }
    return hashCode % size;
}


void HashTable::printHashTable() {
    std::stringstream ss;
    printHashTableToStream(ss);
    std::cout << ss.str();
}


void HashTable::printHashTableToStream(std::stringstream& ss) {
    Node* node;
    // Iterate over table
    for (int i = 0; i < size; i++) {
        ss << "[" << i << "]: ";
        // Iterate over list
        node = table[i];
        while (node != NULL) {
            ss << node->data << " -> ";
            node = node->next;
        }
        ss << "NULL" << std::endl;
    }
}
#endif
