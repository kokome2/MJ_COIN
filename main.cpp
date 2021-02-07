#include "blockchain.hpp"

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

namespace logging = boost::log;
 
void init()
{
    logging::core::get()->set_filter(
        logging::trivial::severity >= logging::trivial::info);
}

int main(int argc, char* argv[]){

    kmj::blockchain::getInstance();
    init();
    BOOST_LOG_TRIVIAL(info) << "Mining block 1...";

    for (int i = 2; i < 10; ++i)
    {
        std::stringstream text_log;
        text_log << "Mining block " << i << "...";
        kmj::Block b = kmj::Block(i, text_log.str());
        std::string myWallet = kmj::sha256("sldkfjsadklfjlkasdjflkadsjf;lkajsdflasdjk");
        kmj::blockchain::getInstance().AddBlock(b, myWallet);
        BOOST_LOG_TRIVIAL(info) << text_log.str();
    }

    return 0;
}