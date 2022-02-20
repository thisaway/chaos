//TypePromotion.h
#ifndef CHAOS_ARITHMETIC_TYPEPROMOTION_H
#define CHAOS_ARITHMETIC_TYPEPROMOTION_H

namespace chaos {

template<typename T>
struct PrecisionTraits {
  enum {
    rank = 0,
    known = 0
  };
};

#define PRECISION_SET(t, r)  \
template<>  \
struct PrecisionTraits<t> {  \
  enum {  \
    rank = r,  \
    known = 1  \
  };  \
};

PRECISION_SET(int, 100)
PRECISION_SET(float, 700)
PRECISION_SET(double, 800)

#undef PRECISION_SET

template<typename T>
struct AutopromoteTraits {
    typedef T valueType;
};

#define AUTOPROMOTE(t1, t2)  \
template<>  \
struct AutopromoteTraits<t1>{  \
    typedef t2 valueType;  \
};

AUTOPROMOTE(bool, int)
AUTOPROMOTE(char, int)

#undef AUTOPROMOTE

template<typename T1, typename T2, int promoteToT1>
struct PromoteTo {
    typedef T1 valueType;
};

template<typename T1, typename T2>
struct PromoteTo<T1, T2, 0> {
    typedef T2 valueType;
};

template<typename T1ori, typename T2ori>
struct PromoteTraits {
    typedef typename AutopromoteTraits<T1ori>::valueType T1;
    typedef typename AutopromoteTraits<T2ori>::valueType T2;

    enum {
    T1IsBetter = int(PrecisionTraits<T1>::rank) > int(PrecisionTraits<T2>::rank),
    knowBothRanks = PrecisionTraits<T1>::known && PrecisionTraits<T2>::known,

    knowT1butNotT2 = PrecisionTraits<T1>::known && !(PrecisionTraits<T2>::known),
    knowT2butNotT1 =  PrecisionTraits<T2>::known && !(PrecisionTraits<T1>::known),
    T1IsLarger = sizeof(T1) >= sizeof(T2),

    defaultPromotion = knowT1butNotT2 ? false : (knowT2butNotT1 ? true : T1IsLarger),

    promoteToT1 = (knowBothRanks ? T1IsBetter : defaultPromotion) ? 1 : 0
  };

 public:
  typedef typename PromoteTo<T1,T2,promoteToT1>::valueType valueType;
};

}  //namespace

#endif