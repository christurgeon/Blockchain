#include "Blockchain.h"

Blockchain::Blockchain() {
  // 1. The emplace_back vector method adds a new element to the end
  // 2. The difficulty process determines how hard it is to perform Proof of Work
  //    Essentially the number of consecutive 0s
  // 3. need to add first block to reference called "Genesis Block"
  chain.emplace_back(Block(0, "Genesis Block"));
  difficulty = 2;
}

/**
 * - To complete the process of adding the block to the blockchain, the
 *   previous hash must be set for the new Block and then the block is mined
 *   and added to the blockchain.
 */
void Blockchain::addBlock(Block newBlock) {
  newBlock.previousHash = getLastBlock().getHash();
  newBlock.mineBlock(difficulty);
  chain.push_back(newBlock);
}

/**
 * - This method returns the last Block in the Blockchain
 *   @returns: the most recently added Block
 */
Block Blockchain::getLastBlock() const {
  return chain.back();
}
