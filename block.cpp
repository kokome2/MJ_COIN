#include "block.hpp"

namespace kmj{

Block::Block(uint64_t nIndexIn, const std::string &sDataIn) {
    mNonce = -1;
    mTime = time(nullptr);
    mHash = CalculateHash();
}

std::string Block::GetHash(){
  return mHash[0];
}

Block Block::Mine(uint64_t nDifficulty, std::string WalletAddress){
  mSender = "SYSTEM";
  mRecipient = WalletAddress;
  mAmount = 5;

  char cstr[nDifficulty + 1];
  for (uint64_t i = 0; i < nDifficulty; ++i){
    cstr[i] = '0';
  }

  cstr[nDifficulty] = '\0';

  std::string str(cstr);

  while (mHash[0].substr(0, nDifficulty) != str){
    mNonce++;
    mHash = CalculateHash();
  }

  std::cout << "Block mined: " << mHash[0] << std::endl;
  std::cout << "Block detail: " << mHash[1] << std::endl;

  Block result(mIndex, mData);

  result.mIndex = mIndex;
  result.mNonce = mNonce;
  result.mData = mData;
  result.mSender = mSender;
  result.mRecipient = mRecipient;
  result.mAmount = mAmount;
  result.mTime = mTime;
  result.mHash = mHash;
  return result;
}

inline std::vector<std::string> Block::CalculateHash() const {
  json b;

  b["index"] = mIndex;
  b["timestamp"] = mTime;
  b["transactions"][0]["sender"] = mSender;
  b["transactions"][0]["recipient"] = mRecipient;
  b["transactions"][0]["amount"] = mAmount;
  b["proof"] = mData;
  b["previous_hash"] = mPrevHash;
  b["nonce"] = mNonce;

  std::vector<std::string> result(2);
  result[0] = sha256(b.dump());
  result[1] = b.dump();

  return result;
}

}