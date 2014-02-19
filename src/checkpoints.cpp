// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 iCoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (  0, hashGenesisBlockOfficial )
			(  10, uint256("0x37123389e62e569cb8c6ea11ab93e4be8382b82323cbc0f017af1b94216ef13e"))
			(  50, uint256("0x58854ad0d27533eb2691c6580971e6945e950a4419117bed750b68064bf4d9ed"))
			(  100, uint256("0x597f8bea37d5885c80c0e64b9a70ed58aa7acddf94940b205a2049098e9ec14b"))
			(  500, uint256("0xa48c1e8d7a57dff9872930e8bc729b86ed8ee0ddb8631b4e9e67112d0db57c88"))
			(  1000, uint256("0xd7340ba3046b16eacef10ceec5de73e8f3ff55c33e33fff6b6d4e8bc311b07fc"))
			(  2000, uint256("0x23881c119e17bece6815f4b675fb390e36ba01d6dc447b28dc5ee21e081b872b"))
			(  2500, uint256("0x51f13e1ba91021cc7e8c40850055c660edbfe9977cb45c78e73299c817ecb749"))
			(  3000, uint256("0xb799e01f438c33760ec227c1f76fadeaa4e95bf76fa80ebb1e6fb538c5736164"))
			(  5000, uint256("0xff23a10acfc927be366c9a7f41dd60b0a9e5123fe0296239b7b660e6557921d1"))
			(  5200, uint256("0xff53a9ca9d94ced77dd60f044e23b28eca04fcb63c3583dafa6a0f3169a15e06"))
			(  7000, uint256("0x90dc96799b1932e0ddbe3651c326008bcea1213ec5ec4f4d9d1f66dd9fdceac6"))
			(  10000, uint256("0xc6f81a9e8095276e97904299f54da9d33c470aed4ab2cfd1b5fc326658d47667"))
			(  15000, uint256("0xa0858cdc8c2742df69bf9b31143f83b1d9c833bf77a998624068fd11fd242658"))
			(  17500, uint256("0xdf7f7219cdb74f4909ad7ecb94a71cc0e3edd59ec3014f6b6dc8c97d6196fcc0"))
			(  20000, uint256("0x294fb9c63ea77744ba95850459368133c5630c3fe7dd26b44929b15364bdfc32"))
			(  22500, uint256("0x11080b7c18e97c3f2e38be8bc4b7ef30ca408b0c608cf5a5014d39b8fe18e654"))
			(  25000, uint256("0xa21bb7f5772e1d8c425b281faf57c79985a370f8b576024e08000205ed0f89da"))
			(  26540, uint256("0xcf71be7a3d0d68515a11eb2aeb14e9ae813ebe8e9f39cf12b8a3f639c9cb1d8f"))
			;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
		// return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
	
        return mapCheckpoints.rbegin()->first;
		// return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
				// return NULL;
        }
        return NULL;
    }
}
