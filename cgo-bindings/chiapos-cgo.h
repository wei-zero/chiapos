//
// Created by wei on 2021/7/18.
//
// Defines CGO interfaces
#ifndef CHIAPOS_CHIAPOS_CGO_H
#define CHIAPOS_CHIAPOS_CGO_H

#include "stdint.h"

#if defined (_MSC_VER)
#define API __declspec(dllexport)
#else
#define API extern
#endif

#ifdef __cplusplus
extern "C" {
#endif
    /* Prover */
    typedef void* Prover;
    API Prover ProverNew(const char* filePath);
    API void ProverFree(Prover p);
    API const char* ProverGetFileName(Prover p);
    API void ProverGetId(Prover p, uint8_t* buffer);
    API uint8_t ProverGetSize(Prover p);
    API uint32_t ProverGetMemoSize(Prover p);
    API void ProverGetMemo(Prover p, uint8_t* buffer);
    // Return list of quality string, which is sha256 each
    API void ProverGetQualitiesForChallenge(Prover p, uint8_t* challenge, uint8_t* buffer, uint32_t * count);
    // Return hex of 60*k bit string
    API const uint8_t* ProverGetFullProof(Prover p, const uint8_t* challenge, uint32_t index);

    /* Verifier */
    typedef void* VerifierGo;
    API VerifierGo VerifierGoNew();
    API void VerifierGoFree(VerifierGo p);
    API const uint8_t* VerifierValidateProof(VerifierGo verifier, const uint8_t* id, uint8_t k,
                                         const uint8_t* challenge,const uint8_t* proof_bytes,
                                         uint16_t proof_size);

    /* Debug */
    API void ThrowException(int8_t ec);
    API void CatchException(int8_t ec);
#ifdef __cplusplus
}
#endif

#endif  // CHIAPOS_CHIAPOS_CGO_H
