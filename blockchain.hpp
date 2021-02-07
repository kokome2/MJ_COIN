#pragma once
#include <cstdint>
#include <vector>
#include "block.hpp"


namespace kmj{

class blockchain{

public:
    static blockchain& getInstance();
    blockchain();
    void AddBlock(Block _New, std::string _WalletAddress);
    Block GetLastBlock() const;
protected:

private:
    uint64_t mDifficulty;
    std::vector<Block> mChain;
};

}