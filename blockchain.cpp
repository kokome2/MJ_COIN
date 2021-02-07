#include "blockchain.hpp"

namespace kmj
{

    blockchain &blockchain::getInstance(){
        static blockchain pinstance;
        return pinstance;
    }

    blockchain::blockchain() {
        mChain.emplace_back(Block(0, "Zero Block"));
        mDifficulty = 5;
    }

    void blockchain::AddBlock(Block bNew, std::string WalletAddress){
        bNew.mPrevHash = GetLastBlock().GetHash();
        Block b = bNew.Mine(mDifficulty, WalletAddress);
        mChain.push_back(b);
    }

    Block blockchain::GetLastBlock() const{
        return mChain.back();
    }

} // namespace kmj
