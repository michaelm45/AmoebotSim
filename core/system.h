// Defines a base particle system and its iterators, primarily serving the
// purpose of defining functions to be overridden by subclasses.

#ifndef AMOEBOTSIM_SIM_SYSTEM_H
#define AMOEBOTSIM_SIM_SYSTEM_H

#include <QMutex>

#include <deque>
#include <set>
#include "core/node.h"
#include "core/particle.h"

class System {
 public:
  // Default constructor and destructor. TODO: not sure if we need these.
  System();
  virtual ~System();

  // Signatures for functions which activate particles. Must be overridden by
  // any system subclasses; see amoebotsystem.h for more detailed documentation.
  virtual void activate() = 0;
  virtual void activateParticleAt(Node node) = 0;

  // Returns the number of particles in the system. Must be overridden by any
  // system subclasses.
  virtual unsigned int size() const = 0;

  // Returns the number of tiles in the system.
  virtual unsigned int numTiles() const = 0;

  // Returns a reference to the particle at the specified index. Must be
  // overridden by any system subclasses.
  virtual const Particle& at(int i) const = 0;

  // Signatures for functions measuring the progress of the system. These all
  // return default values at this level; see amoebotsystem.h for more detailed
  // documentation.
  // LEGACY: leaderElectionRounds, weakBounds, and strongBounds are only used
  // in LegacySystem and should not be used going forward. TODO: remove?
  virtual unsigned int numMovements() const;
  virtual unsigned int numRounds() const;
  virtual unsigned int leaderElectionRounds() const;
  virtual unsigned int weakBounds() const;
  virtual unsigned int strongBounds() const;

  virtual bool hasTerminated() const;


};

#endif  // AMOEBOTSIM_SIM_SYSTEM_H
