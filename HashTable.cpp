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
    int i;
    i = hash(x);
    cout<<i<<"' is what \"i\" is";
    Node *node = table[i];
    while (node->data != "")
    {
        if(node->next == NULL)
        {

            node->next = new Node("",NULL);
        }
        else{}
    }
    node->data = x;
}
#endif

/* **************************************************************** */

#if FIND || ALL
    // TODO: find() method
bool HashTable::find(string x)
{
    int i = hash(x);
    return table[i];
}
#endif

/* **************************************************************** */

#if REMOVE || ALL
    // TODO: remove() method
void HashTable::remove(string x)
{
    i = hash(element);
    hash_table_array[i] = NULL;
}
#endif

/* **************************************************************** */

#if LOADFACTOR || ALL
    // TODO: loadFactor() method
float HashTable::loadFactor()
{
}
#endif

/* **************************************************************** */

#if MAXCHAINLENGTH || ALL
    // TODO: maxChainLength() method
void HashTable::maxChainLength(int& maxLength, int& maxSlotIndex)
{
}
#endif

/* **************************************************************** */

#if NUMEMPTYSLOTS || ALL
    // TODO: numEmptySlots() method
int HashTable::numEmptySlots()
{
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
