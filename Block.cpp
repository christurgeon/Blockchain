#include <iostream>
#include <string>
#include <sstream>
#include "Block.h"
#include "sha256.h"

/**
 * - Constructor for a Block in the Blockchain, has a nonce for
 *   cryptographic purposes and a time value.
 */
Block::Block(uint32_t indexIn, const std::string &dataIn) : index(indexIn), data(dataIn) {
  nonce = -1;
  time = std::time(nullptr);
}

/**
 * - An accessor method to get the hash of a Block
 */
std::string Block::getHash() {
  return hash;
}


/**
 * - Creates a string of all zeros and length of difficulty.
 * - The front portion of the hash is compared to the string of
 *   zeros untul there is match. New hashes are generated with
 *   each iteration of the loop.
 *   @modifies: this
 *   @effect: block object acquires new hash
 *   @effect: message is sent to output buffer to say block is mined
 */
void Block::mineBlock(uint32_t difficulty) {
  std::string allZeros(difficulty, '0');
  while (hash.substr(0, difficulty) != allZeros) {
    nonce++;
    hash = calculateHash();
  }
  std::cout << "Block mined: " << hash << std::endl;
}


/**
 * - Calculate a hash using the sha256 algorithm.
 * - Start by appending values to the stream.
 *   @returns: sha256 hash value for the Block data
 */
inline std::string Block::calculateHash() const {
  // The inline keyword makes code more efficient as compiler places the
  // the method's instructions inline wherever the method is called.
  // This cuts down on method calls.
  std::stringstream ss;
  ss << index << time << data << nonce << previousHash;
  return sha256(ss.str());
}
