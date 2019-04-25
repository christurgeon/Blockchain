#include <cstdint>
#include <vector>
#include "Block.h"

class Blockchain {

  public:
    Blockchain();
    void addBlock(Block newBlock);

  private:
    uint32_t difficulty;
    std::vector<Block> chain;
    Block getLastBlock() const;
    
};
