//
// Created by Dinh Thai Minh Tam on 4/24/18.
//

#include "Block.h"

Block::Block(uint32_t index, const string &data) {
    this->_nonce = -1;
    this->_timeStamp = time(nullptr);
    this->_index = index;
    this->_blockdata = data;
}

string Block::GetHash() {
    return std::string();
}

void Block::MineBlock(uint32_t difficulty) {

}

string Block::CalculateHash() const {
    return std::string();
}
