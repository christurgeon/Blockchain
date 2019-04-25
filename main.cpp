#include <iostream>
#include "Blockchain.h"

// Replicated this from: https://davenash.com/2017/10/build-a-blockchain-with-c
// RUN: g++ -o TestChain *.cpp -std=c++11

int main() {
  // Informs the user that mining has begun.
  // Continues when a valid hash is found.
  Blockchain bChain = Blockchain();

  std::cout << "Mining block 1..." << std::endl;
  bChain.addBlock(Block(1, "Block 1 Data"));

  std::cout << "Mining block 2..." << std::endl;
  bChain.addBlock(Block(2, "Block 2 Data"));

  std::cout << "Mining block 3..." << std::endl;
  bChain.addBlock(Block(3, "Block 3 Data"));

  // Add more blocks, or change the stored data.

  return 0;
}
