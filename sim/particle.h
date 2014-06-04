#ifndef PARTICLE_H
#define PARTICLE_H

#include <array>

#include "alg/algorithm.h"
#include "sim/movement.h"
#include "sim/node.h"

class Particle
{
public:
    Particle(Algorithm* _algorithm, const int _orientation, const Node _head, const int _tailDir = -1);
    Particle(const Particle& other);
    virtual ~Particle();

    Particle& operator=(const Particle& other);

    Movement executeAlgorithm(std::array<const Flag*, 10>& inFlag);
    void apply();
    void discard();

    const Flag* getFlagForNode(Node node);

    Node tail() const;
    Node nodeIncidentToLabel(const int label) const;
    Node nodeReachedViaLabel(const int label) const;
    int labelOfNode(const Node node) const;

    template<int n> static int posMod(const int a);

public:
    int orientation; // global direction
    Node head;
    int tailDir; // global direction

protected:
    Algorithm* algorithm;
    Algorithm* newAlgorithm;
};

template<int n> int Particle::posMod(const int a)
{
    return (a % n + n) % n;
}

#endif // PARTICLE_H
