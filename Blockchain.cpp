//
// Created by Dinh Thai Minh Tam on 1/30/18.
//

#include "Blockchain.h"

Blockchain::Blockchain() {
    chain.emplace_back(Block(0,"Gennesis Block"));
    difficulty = 4;
}

void Blockchain::AddBlock(Block newBlock) {
    newBlock.prevHash = GetLastBlock().GetHash();
    newBlock.MineBlock(difficulty);
    chain.push_back(newBlock);
}

Block Blockchain::GetLastBlock() const {
    return chain.back();
}