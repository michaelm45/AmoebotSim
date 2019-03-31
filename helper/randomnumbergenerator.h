// Helper class to generate randomness.

#ifndef AMOEBOTSIM_HELPER_RANDOMNUMBERGENERATOR_H_
#define AMOEBOTSIM_HELPER_RANDOMNUMBERGENERATOR_H_

#include <algorithm>
#include <chrono>
#include <random>

class RandomNumberGenerator {
 public:
  RandomNumberGenerator();

 protected:
  static int randInt(const int from, const int toNotIncluding);
  static int randDir();
  static float randFloat(const float from, const float toNotIncluding);
  static double randDouble(const double from, const double toNotIncluding);
  static bool randBool(const double trueProb = 0.5);

 private:
  static std::mt19937 rng;
};

inline RandomNumberGenerator::RandomNumberGenerator() {
  static bool initialized = false;
  if(!initialized) {
    uint32_t seed;
    std::random_device device;
    if(device.entropy() <= 0) {
      auto duration = std::chrono::high_resolution_clock::now() -
                      std::chrono::high_resolution_clock::time_point::min();
      seed = duration.count();
    } else {
        std::uniform_int_distribution<uint32_t>
            dist(std::numeric_limits<uint32_t>::min(),
                 std::numeric_limits<uint32_t>::max());
        seed = dist(device);
    }
    rng.seed(seed);
    initialized = true;
  }
}

inline int RandomNumberGenerator::randInt(const int from,
                                          const int toNotIncluding) {
  std::uniform_int_distribution<int> dist(from, toNotIncluding - 1);
  return dist(rng);
}

inline int RandomNumberGenerator::randDir() {
  return randInt(0, 12);
}

inline float RandomNumberGenerator::randFloat(const float from,
                                              const float toNotIncluding) {
  std::uniform_real_distribution<float> dist(from, toNotIncluding);
  return dist(rng);
}

inline double RandomNumberGenerator::randDouble(const double from,
                                                const double toNotIncluding) {
  std::uniform_real_distribution<double> dist(from, toNotIncluding);
  return dist(rng);
}

inline bool RandomNumberGenerator::randBool(const double trueProb) {
  return (randDouble(0, 1) < trueProb);
}

#endif // AMOEBOTSIM_HELPER_RANDOMNUMBERGENERATOR_H_
