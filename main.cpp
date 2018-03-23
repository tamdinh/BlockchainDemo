#include <iostream>
#include "Blockchain.h"
#include "utilities/json.hh"

// for convenience
using json = nlohmann::json;

int main() {

    Blockchain bChain = Blockchain();

    cout << "Mining block 1..." << endl;
    bChain.AddBlock(Block(1, "Block 1"));

    cout << "Mining block 2..." << endl;
    bChain.AddBlock(Block(2, "Block 2"));
//
//    cout << "Mining block 3..." << endl;
//    bChain.AddBlock(Block(3, jblock3.dump()));

//    cout << "Block 1 " << jblock1.dump() << endl;
//    cout << "Block 2 " << jblock2.dump() << endl;

    return 0;
}