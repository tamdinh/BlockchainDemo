//
// Created by Dinh Thai Minh Tam on 4/24/18.
//

#ifndef SIMPLEBLOCKCHAIN_BLOCK_H
#define SIMPLEBLOCKCHAIN_BLOCK_H


#include <cstdint>
#include <iostream>

using namespace std;

class Block {

    public:
    /// Contructors
    Block(uint32_t index, const string &data);

    string prevHash;

    /**
     *     Get current Hash of this block
     */
    string GetHash();

    /**
     * Get Block's Height in blockchain
     * @return
     */
    uint32_t GetHeight();

    /**
     * Use POW for mining here.
     * @param difficulty
     */
    void MineBlock(uint32_t difficulty);

private :
        uint32_t _index;
        int16_t  _nonce;
        string _blockData;
        string _hash;
        time_t _timeStamp;

        // methods
        string CalculateHash() const;
};


#endif //SIMPLEBLOCKCHAIN_BLOCK_H
