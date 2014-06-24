#ifndef HEXAGON_H
#define HEXAGON_H

#include "alg/algorithm.h"
class HexFlag;
class System;

class Hexagon : public Algorithm
{
public:
    enum class State {
        Finished,
        Leader,
        Follower,
        Idle,
        Seed
    };
    Hexagon(const State _state);
    Hexagon(const Hexagon& other);
    virtual ~Hexagon();
    static System* instance(const int size, const double holeProb);
    virtual Algorithm* clone();
    virtual bool isDeterministic() const;

protected:
    virtual Movement execute(std::array<const Flag*, 10>& flags);
    
    int isPointedAt(); // 

    void setState(State _state);
    bool neighborInState(int direction, State _state);
    bool hasNeighborInState(State _state);
    int firstNeighborInState(State _state);

    int getMoveDir(); 
    void setContractDir(const int contractDir);
    int updatedFollowDir() const;

    int unsetFollowIndicator() const;
    void setFollowIndicatorLabel(const int label);
    bool tailReceivesFollowIndicator() const;
    bool followIndicatorMatchState(State _state) const;
    
protected:
    std::array<const HexFlag*, 10> inFlags;
    std::array<HexFlag*, 10> outFlags;
    State state;
    int followDir;
};

class HexFlag : public Flag
{
public:
    HexFlag();
    HexFlag(const HexFlag& other);
    Hexagon::State state;
    bool point; //
    bool followIndicator;
    int contractDir;
};

#endif // HEXAGON_H
