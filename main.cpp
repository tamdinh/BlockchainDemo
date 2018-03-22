#include <iostream>
#include "blockchain.h"
#include "Utilities/json.hh"

// for convenience
using json = nlohmann::json;

int main() {
    json jblock1;
    jblock1["type"] = 0; //
    jblock1["name"] = "Kimmin";
    jblock1["action"] = "Say hello";

    // instead, you could also write (which looks very similar to the JSON above)
    json jblock2 = {
            {"type", 1},
            {"happy", true},
            {"name", "Niels"},
            {"nothing", nullptr},
            {"answer", {
                           {"everything", 42}
                   }},
            {"list", {1, 0, 2}},
            {"object", {
                           {"currency", "USD"},
                         {"value", 42.99}
                   }}
    };

    auto jblock3 = R"(
        {  "happy": true,
            "pi": 3.141}
    )"_json;

    Blockchain bChain = Blockchain();

    cout << "Mining block 1..." << endl;
    bChain.AddBlock(Block(1, jblock1.dump()));

    cout << "Mining block 2..." << endl;
    bChain.AddBlock(Block(2, jblock2.dump()));

    cout << "Mining block 3..." << endl;
    bChain.AddBlock(Block(3, jblock3.dump()));


    return 0;
}