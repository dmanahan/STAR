#ifndef GENOME_DEF
#define GENOME_DEF

#include "IncludeDefine.h"
#include "Parameters.h"
#include "PackedArray.h"
#include "SharedMemory.h"
#include "Variation.h"

class Genome {
    public:
        char *G, *sigG;
        PackedArray SA,SAinsert,SApass1,SApass2;
        PackedArray SAi;
        Variation *Var;
        
        uint nGenomeInsert, nGenomePass1, nGenomePass2, nSAinsert, nSApass1, nSApass2;
        
        ParametersGenome &pGe;
        
        
        

        Genome (Parameters &Pin );
        ~Genome();

        void freeMemory();
        void genomeLoad();

        void insertSequences();


    private:
    Parameters &P;
    key_t shmKey;
    char *shmStart;
    char *G1; //pointer -200 of G
    SharedMemory * sharedMemory;
    uint OpenStream(string name, ifstream & stream, uint size);
    void HandleSharedMemoryException(const SharedMemoryException & exc, uint64 shmSize);

};
#endif
