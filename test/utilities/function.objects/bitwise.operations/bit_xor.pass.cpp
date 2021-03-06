//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <functional>

// bit_xor

#include <functional>
#include <type_traits>
#include <cassert>

int main()
{
    typedef std::bit_xor<int> F;
    const F f = F();
    static_assert((std::is_base_of<std::binary_function<int, int, int>, F>::value), "");
    assert(f(0xEA95, 0xEA95) == 0);
    assert(f(0xEA95, 0x58D3) == 0xB246);
    assert(f(0x58D3, 0xEA95) == 0xB246);
    assert(f(0x58D3, 0) == 0x58D3);
    assert(f(0xFFFF, 0x58D3) == 0xA72C);
#if _LIBCPP_STD_VER > 11
    typedef std::bit_xor<> F2;
    const F2 f2 = F2();
    assert(f(0xEA95, 0xEA95) == 0);
    assert(f(0xEA95L, 0xEA95) == 0);
    assert(f(0xEA95, 0xEA95L) == 0);

    assert(f(0xEA95, 0x58D3) == 0xB246);
    assert(f(0xEA95L, 0x58D3) == 0xB246);
    assert(f(0xEA95, 0x58D3L) == 0xB246);

    assert(f(0x58D3, 0xEA95) == 0xB246);
    assert(f(0x58D3L, 0xEA95) == 0xB246);
    assert(f(0x58D3, 0xEA95L) == 0xB246);

    assert(f(0x58D3, 0) == 0x58D3);
    assert(f(0x58D3L, 0) == 0x58D3);
    assert(f(0x58D3, 0L) == 0x58D3);

    assert(f(0xFFFF, 0x58D3) == 0xA72C);
    assert(f(0xFFFFL, 0x58D3) == 0xA72C);
    assert(f(0xFFFF, 0x58D3L) == 0xA72C);
#endif
}
