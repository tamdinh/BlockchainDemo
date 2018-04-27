//
// Created by Dinh Thai Minh Tam on 4/24/18.
//

#include "Block.h"
#include "Hash.h"

Block::Block(uint32_t index, const string &data) {
    this->_nonce = -1;
    this->_timeStamp = time(nullptr);
    this->_index = index;
    this->_blockData = data;
}

string Block::GetHash() {
    return this->_hash;
}

void Block::MineBlock(uint32_t difficulty) {
    char cstr[difficulty + 1];
    for (uint32_t i = 0; i < difficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[difficulty] = '\0';

    string str(cstr);

    do {
        _nonce++;
        _hash = CalculateHash();
        // cout << "Debug hash test : " << _blockHash << endl;
    } while (_hash.substr(0, difficulty) != str);

    cout << "Block mined: " << _hash << endl;
}

string Block::CalculateHash() const {
    stringstream ss;
    ss << _index << _timeStamp << _blockData << _nonce << this->prevHash;
    return sha256(ss.str());
}

uint32_t Block::GetHeight() {
    return _index;
}
