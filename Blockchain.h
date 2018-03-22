//
// Created by Dinh Thai Minh Tam on 1/30/18.
//

#ifndef SIMPLEBLOCKCHAININC_BLOCKCHAIN_H
#define SIMPLEBLOCKCHAININC_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

class Blockchain {
public:
    Blockchain();

    void AddBlock(Block newBlock);

private:
    uint32_t difficulty;
    vector<Block> chain;
    Block GetLastBlock() const;

};


#endif //SIMPLEBLOCKCHAININC_BLOCKCHAIN_H
