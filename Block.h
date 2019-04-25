#include <cstdint>
#include <string>
#include <ctime>

class Block {

  public:
    Block(uint32_t indexIn, const std::string &dataIn); // const reference
    std::string previousHash;
    std::string getHash();
    void mineBlock(uint32_t difficulty);

  private:
    uint32_t index;
    uint64_t nonce; // arbitrary number that can be used just once in a cyptographic communication
    std::string data;
    std::string hash;
    std::time_t time;

    std::string calculateHash() const; // const means it cannot change any of the vars in Block class
};
