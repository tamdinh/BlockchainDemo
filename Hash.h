//
// Created by Dinh Thai Minh Tam on 1/31/18.
//

#ifndef SIMPLEBLOCKCHAININC_HASH_H
#define SIMPLEBLOCKCHAININC_HASH_H

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include <openssl/sha.h>
#include <openssl/ripemd.h>

using namespace std;

string sha256(const string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}




#endif //SIMPLEBLOCKCHAININC_HASH_H
