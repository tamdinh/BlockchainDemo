//
// Created by Dinh Thai Minh Tam on 4/27/18.
//

#ifndef SIMPLEBLOCKCHAIN_BLOCKCHAIN_H
#define SIMPLEBLOCKCHAIN_BLOCKCHAIN_H


#include <cstdint>
#include <vector>
#include "Block.h"

class Blockchain {
public:
    Blockchain();

    void AddBlock(Block newBlock);

private:
    uint32_t _difficulty;
    vector<Block> _chain;
    Block GetLastBlock() const;

};


#endif //SIMPLEBLOCKCHAIN_BLOCKCHAIN_H
