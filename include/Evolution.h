/**
 * @author Bruno Pinto
 * @date 27.11.19
 * @version 1.0
 *
 * @brief data struct for Population.h
 *
 * alpha represent the number of mutation   at each generation
 * beta  represent the number of cloning    at each generation
 * gamma represent the number of generation at each generation
 */

#ifndef ALGOGEN_EVOLUTION_H
#define ALGOGEN_EVOLUTION_H
namespace genAlgo {
    typedef struct {
        int alpha;   // mutation
        int beta;    // cloning
        int gamma;   // generation
    } Evolution;

    int getSum(const Evolution &);
    /**
     * @return alpha + beta + gamma
     */

}
#endif //ALGOGEN_EVOLUTION_H
