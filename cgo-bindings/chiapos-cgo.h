//
// Created by wei on 2021/7/18.
//
// Defines CGO interfaces
#ifndef CHIAPOS_CHIAPOS_CGO_H
#define CHIAPOS_CHIAPOS_CGO_H

#include "stdint.h"
#ifdef __cplusplus
extern "C" {
#endif
    // Prover
    typedef void* Prover;
    Prover ProverNew(const char* filePath);
    void ProverFree(Prover p);
    const char* ProverGetFileName(Prover p);
    void ProverGetId(Prover p, uint8_t* buffer);
    uint8_t ProverGetSize(Prover p);
    uint32_t ProverGetMemoSize(Prover p);
    void ProverGetMemo(Prover p, uint8_t* buffer);
    // Return list of quality string, which is sha256 each
    void ProverGetQualitiesForChallenge(Prover p, uint8_t* challenge, uint8_t* buffer, uint64_t* count);
    // Return hex of 60*k bit string
    const char* ProverGetFullProof(Prover p, const uint8_t* challenge, uint32_t index);

#ifdef __cplusplus
}
#endif

#endif  // CHIAPOS_CHIAPOS_CGO_H
