//
// Created by Dinh Thai Minh Tam on 1/30/18.
//

#include <sstream>
#include "Block.h"
#include "Hash.h"

Block::Block(uint32_t index, const string &data) : _index(index), _blockData(data) {
    this->_nonce = -1;
    this->_timeStamp = time(nullptr);
}

string Block::GetHash() {
    return _blockHash;
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
        _blockHash = CalculateHash();
        // cout << "Debug hash test : " << _blockHash << endl;
    } while (_blockHash.substr(0, difficulty) != str);

    cout << "Block mined: " << _blockHash << endl;
}

string Block::CalculateHash() const {
    stringstream ss;
    ss << _index << _timeStamp << _blockData << _nonce << this->prevHash;
    return sha256(ss.str());
}
