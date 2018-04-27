//
// Created by Dinh Thai Minh Tam on 4/27/18.
//

#include "Blockchain.h"

Blockchain::Blockchain() {
    _chain.emplace_back(Block(0,"Gennesis Block"));
    _difficulty = 3;
}

void Blockchain::AddBlock(Block newBlock) {
    newBlock.prevHash = GetLastBlock().GetHash();
    newBlock.MineBlock(_difficulty);
    _chain.push_back(newBlock);
}

Block Blockchain::GetLastBlock() const {
    return _chain.back();
}