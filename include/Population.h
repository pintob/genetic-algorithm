/**
 * @author Bruno Pinto
 * @date 27.11.19
 * @version 1.0
 *
 * @brief An implementation of genetic algorithm.
 *
 * Template class for genetic algorithm (without merging).
 *
 * The template class T needing to implement (cf. /template/SortedArray.cpp):
 *   double score();
 *  -> return the score of the individual
 *   void mut();
 *  -> make random modification on the instance of T
 *   void shuffle();
 *  -> shuffle element of the instance of T
 *   void fill(T& dest);
 *  -> fill dest with the element of this
 *   + constructor of copy
 *
 */

/**
 * Population synopsis
 *
 *
 * class Population{
 * public:
 *     Population(T &base, Evolution &evo, TypeOfProblem type);
 *     ~Population();
 *     int getGeneration();
 *      -> return the number of the current generation
 *     void evolve();
 *      -> apply evolution parameter on the current generation to try to improve individual
 *     const std::pair<T *, double> &operator[](int i);
 *      -> return the nth better individual (T*) and it score(double).
 *         the T* is read-only (if you change it your can have super funny feature)
 *     Population&operator++();
 *      -> basically call evolve() once
 *     Population&operator+=(int nbGen);
 *      -> basically call evolve() nb times
 * }
 *
 */

#ifndef ALGOGEN_POPULATION_H
#define ALGOGEN_POPULATION_H

#include <algorithm>
#include <functional>
#include <type_traits>
#include <vector>
#include "Evolution.h"

namespace genAlgo {

    enum class TypeOfProblem {
        Maximisation,
        Minimisation
    };

    template<class T>
    class Population {
    public:
        Population(T &base, Evolution &evo, TypeOfProblem type) {
            _type = type;
            _darwin = evo;
            T *tmp;
            for (int i = 0; i < getSum(_darwin); i++) {
                tmp = new T(base);
                _populations.push_back(std::make_pair(tmp, 0));
                (*_populations[i].first).shuffle();
                updateScore(i);
            }
            sortPopulation();
        }

        virtual ~Population() {
            for (auto t: _populations) {
                delete (t.first);
            }
        }

        virtual int getGeneration() {
            return _nbGeneration;
        }

        virtual void evolve() {
            _nbGeneration++;

            for (int i = _darwin.beta; i < _darwin.beta + _darwin.alpha; i++) {
                (*_populations[i - _darwin.beta].first).fill(*_populations[i].first);
                (_populations[i].second) = (_populations[i - _darwin.beta].second); // same as update score but fast

            }

            for (int i = _darwin.alpha + _darwin.beta; i != _darwin.beta - 1; i--) {
                (*_populations[i].first).mut();
                updateScore(i);
            }

            for (int i = _darwin.alpha + _darwin.beta; i < getSum(_darwin); i++) {

                (*_populations[i].first).shuffle();
                updateScore(i);
            }
            sortPopulation();
        }

        virtual const std::pair<const T *, double> &operator[](int i) {
            return _populations[i];
        }

        virtual Population&operator++(){
            evolve();
            return *this;
        }

        virtual Population&operator+=(int nbGen){
            for(int i = 0; i < nbGen; i++){
                ++(*this);
            }
            return *this;
        }

    private:

        std::vector<std::pair<T *, double>> _populations;
        // _populations.size() = _darwin.alpha + _darwin.beta + _darwin.gamma
        TypeOfProblem _type;
        Evolution _darwin;
        int _nbGeneration;

        void sortPopulation() {
            std::sort(_populations.begin(), _populations.end(),
                      [this](std::pair<T *, double> a, std::pair<T *, double> b) {
                          if (_type == TypeOfProblem::Maximisation)
                              return a.second > b.second;
                          return a.second < b.second;
                      });
        }

        void updateScore(int index) {
            _populations[index].second = (*_populations[index].first).score();
        }

    };
}
#endif //ALGOGEN_POPULATION_H
