#include <Hash.h>
#include "Block.h"

int main() {
    Block * block;
    block = new Block(0,"OK Genesis Block");
    cout << "Block hash:"<< block->GetHash() << endl;
    string hashof = sha256("Xem thu the nao");
    cout << hashof;
    delete  block;
    return 0;

}