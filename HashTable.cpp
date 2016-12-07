//
//  HashTable.cpp
//

#include "HashTable.h"
#include "Flags.h"

/* **************************************************************** */

#if CONSTRUCTOR || ALL
//HashTable::HashTable(int tableSize)
//{
//    // TODO: Constructor
//}
#endif

/* **************************************************************** */

#if DESTRUCTOR || ALL
//HashTable::~HashTable()
//{
    // TODO: Destructor
//}
#endif

/* **************************************************************** */

#if INSERT || ALL
    // TODO: insert() method
#endif

/* **************************************************************** */

#if FIND || ALL
    // TODO: find() method
#endif

/* **************************************************************** */

#if REMOVE || ALL
    // TODO: remove() method
#endif

/* **************************************************************** */

#if LOADFACTOR || ALL
    // TODO: loadFactor() method
#endif

/* **************************************************************** */

#if MAXCHAINLENGTH || ALL
    // TODO: maxChainLength() method
#endif

/* **************************************************************** */

#if NUMEMPTYSLOTS || ALL
    // TODO: numEmptySlots() method
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
