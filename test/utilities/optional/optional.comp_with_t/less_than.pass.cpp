//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <optional>

// template <class T> constexpr bool operator<(const optional<T>& x, const T& v);
// template <class T> constexpr bool operator<(const T& v, const optional<T>& x);

#include <optional>

#if _LIBCPP_STD_VER > 11

struct X
{
    int i_;

    constexpr X(int i) : i_(i) {}
};

namespace std
{

template <>
struct less<X>
{
    constexpr
    bool
    operator()(const X& x, const X& y) const
    {
        return x.i_ < y.i_;
    }
};

}

#endif

int main()
{
#if _LIBCPP_STD_VER > 11

    {
    typedef X T;
    typedef std::optional<T> O;
    
    constexpr T val(2);
    constexpr O o1;     // disengaged
    constexpr O o2{1};  // engaged
    constexpr O o3{val};  // engaged

    static_assert (   o1 < T(1) , "" );
    static_assert ( !(o2 < T(1)), "" );
    static_assert ( !(o3 < T(1)), "" );
    static_assert (   o2 < T(2) , "" );
    static_assert (   o2 < T(val), "" );
    static_assert (   o3 < T(3) , "" );

    static_assert (  !(T(1) < o1), "" );
    static_assert (  !(T(1) < o2), "" );
    static_assert (    T(1) < o3 , "" );
    static_assert (  !(T(2) < o2), "" );
    static_assert (!(T(val) < o2), "" );
    static_assert (  !(T(3) < o3), "" );
    }
#endif
}
