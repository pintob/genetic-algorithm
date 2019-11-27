/**
 * @author Bruno Pinto
 * @date 27.11.19
 * @version 1.0
 */

#include "../include/Evolution.h"
namespace genAlgo {
    int getSum(const Evolution &evo) {
        return evo.alpha + evo.beta + evo.gamma;
    }
}