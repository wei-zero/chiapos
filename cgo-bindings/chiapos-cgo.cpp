//
// Created by wei on 2021/7/18.
//

#include "chiapos-cgo.h"

//#include "../src/plotter_disk.hpp"
#include "../src/prover_disk.hpp"
#include "../src/verifier.hpp"

#include <iostream>

using namespace std;

Prover ProverNew(const char* filePath) {
    DiskProver* ret = new DiskProver(string(filePath));
    return (void*) ret;
}

void ProverFree(Prover p) {
    DiskProver* dp = (DiskProver*) p;
    delete dp;
}

const char* ProverGetFileName(Prover p) {
    DiskProver* dp = (DiskProver*) p;
    return dp->GetFilename().c_str();
}

void ProverGetId(Prover p, uint8_t* buffer) {
    DiskProver* dp = (DiskProver*) p;
    dp->GetId(buffer);
}

uint8_t ProverGetSize(Prover p) {
    DiskProver* dp = (DiskProver*) p;
    return dp->GetSize();
}

uint32_t ProverGetMemoSize(Prover p) {
    DiskProver* dp = (DiskProver*) p;
    return dp->GetMemoSize();
}

void ProverGetMemo(Prover p, uint8_t* buffer) {
    DiskProver* dp = (DiskProver*) p;
    dp->GetMemo(buffer);
}

void ProverGetQualitiesForChallenge(Prover p, uint8_t* challenge, uint8_t* buffer, uint64_t* count) {
    DiskProver* dp = (DiskProver*) p;
    vector<LargeBits> qualities = dp->GetQualitiesForChallenge(challenge);
    for (uint32_t i = 0; i < qualities.size(); i++) {
        uint8_t *pos = buffer+32*i;
        qualities[i].ToBytes(pos);
    }
    *count = qualities.size();
}

const char* ProverGetFullProof(Prover p, const uint8_t* challenge, uint32_t index) {
    DiskProver* dp = (DiskProver*) p;
    LargeBits bits = dp->GetFullProof(challenge, index);
    uint8_t k = dp->GetSize();
    uint8_t *proof_data = new uint8_t[8 * k];
    bits.ToBytes(proof_data);
    string s = Util::HexStr(proof_data, k * 8);
    delete []proof_data;

    return s.c_str();
}