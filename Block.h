//
// Created by Dinh Thai Minh Tam on 1/30/18.
//

#ifndef SIMPLEBLOCKCHAININC_BLOCK_H
#define SIMPLEBLOCKCHAININC_BLOCK_H

#include <cstdint>
#include <iostream>

using namespace std;

class Block {

public:
    Block(uint32_t index, const string &data);
    string prevHash;
    string GetHash();
    /**
     * Demo for POW
     * @param difficulty
     */
    void MineBlock(uint32_t difficulty);

private:
    uint32_t _index;
    int16_t _nonce;
    string _blockData;
    string _blockHash;
    time_t _timeStamp;
    string CalculateHash() const;
};


#endif //SIMPLEBLOCKCHAININC_BLOCK_H
