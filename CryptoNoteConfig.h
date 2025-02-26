// Copyright (c) 2011-2017 The Cryptonote developers
// Copyright (c) 2014-2017 XDN developers
// Copyright (c) 2016-2017 BXC developers
// Copyright (c) 2017 Royalties developers
// Copyright (c) 2017 Wayang developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

//pragma once not working so using belo
#ifndef CRYPTONOTECONFIG
#define CRYPTONOTECONFIG

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

  const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 600000000;
  const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 600000000;
  const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 2000000000;
  const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x252d79; // addresses start with "intu"
  const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;
  const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;
  const uint64_t CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE           = 10; //corrected from 100

  const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 30; //

  // MONEY_SUPPLY - total number coins to be generated
  const uint64_t MONEY_SUPPLY                                  = (uint64_t)(10000000); //-1
  const uint32_t MANDATORY_TRANSACTION                         = 0;
  const uint32_t KILL_HEIGHT                                   = 0;
  const uint64_t TAIL_EMISSION_REWARD                          = 0;
  const size_t CRYPTONOTE_COIN_VERSION                         = 0;
  const bool ZAWY_DIFFICULTY_V2                          	   = 0;
  const unsigned EMISSION_SPEED_FACTOR                         = 20; // was 18
  const uint64_t GENESIS_BLOCK_REWARD                          = 1000;
  static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

  const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
  const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 60000; //was 10000 size of block (bytes) after which reward for block calculated using block size
  const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 20000; //was 10000
  const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
  const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 2; //was 8
  // COIN - number of smallest units in one coin
  const uint64_t POINT                                         = UINT64_C(1000);        // pow(10, 3)
  const uint64_t COIN                                          = UINT64_C(2000000000000);     // pow(10, 6)
  const uint64_t MINIMUM_FEE                                   = UINT64_C(100);        // pow(10, 3)
  const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(10);         // pow(10, 2)
  // Use 0 for default max transaction size limit
  const uint64_t MAX_TRANSACTION_SIZE_LIMIT                    = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 125 / 100 - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE;
  const uint64_t DEFAULT_FEE                                   = MINIMUM_FEE;

  const uint64_t DIFFICULTY_TARGET                             = 120; // seconds
  const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
  const size_t   DIFFICULTY_WINDOW                             = 720; // 50 blocks
  const size_t   DIFFICULTY_CUT                                = 60;  // 5 timestamps to cut after sorting
  const size_t   DIFFICULTY_LAG                                = 15; //1
  static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

  const uint64_t DEPOSIT_MIN_AMOUNT                            = 100 * COIN;
  const uint32_t DEPOSIT_MIN_TERM                              = 12000; //~1 month
  const uint32_t DEPOSIT_MAX_TERM                              = 1 * 12 * 12000; //~1 year
  const uint64_t DEPOSIT_MIN_TOTAL_RATE_FACTOR                 = 0; //rate is constant
  const uint64_t DEPOSIT_MAX_TOTAL_RATE                        = 25; //percentage rate for DEPOSIT_MAX_TERM
  static_assert(DEPOSIT_MIN_TERM > 0, "Bad DEPOSIT_MIN_TERM");
  static_assert(DEPOSIT_MIN_TERM <= DEPOSIT_MAX_TERM, "Bad DEPOSIT_MAX_TERM");
  static_assert(DEPOSIT_MIN_TERM * DEPOSIT_MAX_TOTAL_RATE > DEPOSIT_MIN_TOTAL_RATE_FACTOR, "Bad DEPOSIT_MIN_TOTAL_RATE_FACTOR or DEPOSIT_MAX_TOTAL_RATE");

  const uint64_t MULTIPLIER_FACTOR                             = 250; //early depositor multiplier
  const uint32_t END_MULTIPLIER_BLOCK                          = 3600; //block at which the multiplier ceases to be applied

  const size_t   MAX_BLOCK_SIZE_INITIAL                        = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 10;
  const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
  const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

  const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
  const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

  const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = (60 * 60 * 14); //seconds, 14 hours
  const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = (60 * 60 * 24); //seconds, one day
  const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

  const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 10;
  const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
  const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

  const uint64_t UPGRADE_HEIGHT                                = 1;
  const unsigned UPGRADE_VOTING_THRESHOLD                      = 50;               // percent
  const size_t   UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
  const size_t   UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
  static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
  static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

  const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "intu-blocks.dat";
  const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "intu-blockindexes.dat";
  const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "intu-blockscache.dat";
  const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "intu-poolstate.bin";
  const char     P2P_NET_DATA_FILENAME[]                       = "intu-p2pstate.bin";
  const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "intu-blockchainindices.dat";
  const char     MINER_CONFIG_FILE_NAME[]                      = "intu-miner_conf.json";
  } // parameters

  const uint64_t START_BLOCK_REWARD                            = (UINT64_C(10) * parameters::POINT);
  const uint64_t ICO_BLOCK_REWARD	                       = (UINT64_C(50201467440) * parameters::COIN); // 50.2 billion ICO
  const uint64_t MAX_BLOCK_REWARD                              = (UINT64_C(2) * parameters::COIN);
  const uint64_t REWARD_INCREASE_INTERVAL                      = (UINT64_C(2640));


const char     CRYPTONOTE_NAME[Empire]                             = "intucoin";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff0001904e029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101128f6e2f5ff1cc0d95bf80839501c07d79fcb80726f3ca8cdc094b0e2d89dfd3";

const uint32_t GENESIS_NONCE                                 = 70;
const uint64_t GENESIS_TIMESTAMP                             = 1515479625;

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  500;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              = 17236;
const int      RPC_DEFAULT_PORT                              = 18236;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 1024 * 1024; // 2 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 30;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 5000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "8f80f9a5a434a9f1510d13336228debfee9c918ce505efe225d8c94d045fa115";

const std::initializer_list<const char*> SEED_NODES = {
   "140.82.29.104:17236",
   "45.77.160.124:17236",
   "77.93.206.165:17236",
   "45.77.178.125:17236"
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {
    //{ 1, "cbce7c37dbad257d29a3bfa93ec1f7b92434b9b806d40d01cb04d0ad2e451735" },
      { 1, "[checkpoint block see on checkpoint list]" },
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS

#endif
