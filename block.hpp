#pragma once

#include <cstdint>
#include <iostream>
#include <string>
#include "sha256.hpp"
#include <sstream>
#include <vector>
#include "json.hpp"

// for convenience
using json = nlohmann::json;
// for convenience

namespace kmj{

class Block
{
public:
  Block(uint64_t nIndexIn, const std::string &DataIn);
  std::vector<std::string> CalculateHash() const;
  Block Mine(uint64_t _Difficulty, std::string _WalletAddress);
  std::string GetHash();
  std::string mPrevHash;
protected:

private:

  uint64_t mIndex;
  uint64_t mNonce;
  std::string mData;
  std::vector<std::string> mHash;

  std::string mSender;
  std::string mRecipient;
  float mAmount;
  time_t mTime;
};

}
