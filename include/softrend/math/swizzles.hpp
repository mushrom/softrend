/* Generated with a python script:
#!/usr/bin/python3

from itertools import combinations_with_replacement
from itertools import permutations

out = set();

for i in [2, 3, 4]:
    for charset in ["xyzw", "rgba"]:
        for thing in combinations_with_replacement(charset, i):
            comb = permutations(thing, i)
            for x in comb:
                out.add(x)

for thing in out:
    params = ""
    count = 0;

    while count < len(thing):
        params += thing[count] + "()";
        if count + 1 < len(thing):
            params += ", "
        count += 1;

    print("constexpr vec<T, %d> %4s() { return vec<T, %d>(%s); }"
            % (len(thing), "".join(thing), len(thing), params))
*/

constexpr vec<T, 2>   br() { return vec<T, 2>(b(), r()); }
constexpr vec<T, 4> wyxw() { return vec<T, 4>(w(), y(), x(), w()); }
constexpr vec<T, 3>  zxw() { return vec<T, 3>(z(), x(), w()); }
constexpr vec<T, 4> xwxx() { return vec<T, 4>(x(), w(), x(), x()); }
constexpr vec<T, 4> agaa() { return vec<T, 4>(a(), g(), a(), a()); }
constexpr vec<T, 4> xzzz() { return vec<T, 4>(x(), z(), z(), z()); }
constexpr vec<T, 4> bara() { return vec<T, 4>(b(), a(), r(), a()); }
constexpr vec<T, 4> bgar() { return vec<T, 4>(b(), g(), a(), r()); }
constexpr vec<T, 4> wyxx() { return vec<T, 4>(w(), y(), x(), x()); }
constexpr vec<T, 4> yxww() { return vec<T, 4>(y(), x(), w(), w()); }
constexpr vec<T, 3>  zxx() { return vec<T, 3>(z(), x(), x()); }
constexpr vec<T, 3>  xwz() { return vec<T, 3>(x(), w(), z()); }
constexpr vec<T, 3>  yxz() { return vec<T, 3>(y(), x(), z()); }
constexpr vec<T, 4> gbgb() { return vec<T, 4>(g(), b(), g(), b()); }
constexpr vec<T, 4> xxyy() { return vec<T, 4>(x(), x(), y(), y()); }
constexpr vec<T, 2>   zw() { return vec<T, 2>(z(), w()); }
constexpr vec<T, 4> rbgb() { return vec<T, 4>(r(), b(), g(), b()); }
constexpr vec<T, 3>  xxx() { return vec<T, 3>(x(), x(), x()); }
constexpr vec<T, 4> bbgr() { return vec<T, 4>(b(), b(), g(), r()); }
constexpr vec<T, 4> rgag() { return vec<T, 4>(r(), g(), a(), g()); }
constexpr vec<T, 4> arrb() { return vec<T, 4>(a(), r(), r(), b()); }
constexpr vec<T, 4> zwzx() { return vec<T, 4>(z(), w(), z(), x()); }
constexpr vec<T, 3>  bgr() { return vec<T, 3>(b(), g(), r()); }
constexpr vec<T, 3>  abr() { return vec<T, 3>(a(), b(), r()); }
constexpr vec<T, 4> gbbb() { return vec<T, 4>(g(), b(), b(), b()); }
constexpr vec<T, 4> wwzx() { return vec<T, 4>(w(), w(), z(), x()); }
constexpr vec<T, 3>  wzz() { return vec<T, 3>(w(), z(), z()); }
constexpr vec<T, 4> gbga() { return vec<T, 4>(g(), b(), g(), a()); }
constexpr vec<T, 4> zyxy() { return vec<T, 4>(z(), y(), x(), y()); }
constexpr vec<T, 4> yyzy() { return vec<T, 4>(y(), y(), z(), y()); }
constexpr vec<T, 4> wxxy() { return vec<T, 4>(w(), x(), x(), y()); }
constexpr vec<T, 4> rbga() { return vec<T, 4>(r(), b(), g(), a()); }
constexpr vec<T, 4> xyxz() { return vec<T, 4>(x(), y(), x(), z()); }
constexpr vec<T, 2>   yz() { return vec<T, 2>(y(), z()); }
constexpr vec<T, 3>  bar() { return vec<T, 3>(b(), a(), r()); }
constexpr vec<T, 4> gbba() { return vec<T, 4>(g(), b(), b(), a()); }
constexpr vec<T, 4> zxxy() { return vec<T, 4>(z(), x(), x(), y()); }
constexpr vec<T, 3>  ggb() { return vec<T, 3>(g(), g(), b()); }
constexpr vec<T, 4> xxwy() { return vec<T, 4>(x(), x(), w(), y()); }
constexpr vec<T, 4> brrb() { return vec<T, 4>(b(), r(), r(), b()); }
constexpr vec<T, 4> grgg() { return vec<T, 4>(g(), r(), g(), g()); }
constexpr vec<T, 4> agar() { return vec<T, 4>(a(), g(), a(), r()); }
constexpr vec<T, 4> rrgg() { return vec<T, 4>(r(), r(), g(), g()); }
constexpr vec<T, 4> rggb() { return vec<T, 4>(r(), g(), g(), b()); }
constexpr vec<T, 4> rbaa() { return vec<T, 4>(r(), b(), a(), a()); }
constexpr vec<T, 4> abba() { return vec<T, 4>(a(), b(), b(), a()); }
constexpr vec<T, 4> yzxy() { return vec<T, 4>(y(), z(), x(), y()); }
constexpr vec<T, 4> raar() { return vec<T, 4>(r(), a(), a(), r()); }
constexpr vec<T, 4> zzyz() { return vec<T, 4>(z(), z(), y(), z()); }
constexpr vec<T, 4> yxyz() { return vec<T, 4>(y(), x(), y(), z()); }
constexpr vec<T, 3>  rag() { return vec<T, 3>(r(), a(), g()); }
constexpr vec<T, 3>  gab() { return vec<T, 3>(g(), a(), b()); }
constexpr vec<T, 4> ggga() { return vec<T, 4>(g(), g(), g(), a()); }
constexpr vec<T, 3>  yzy() { return vec<T, 3>(y(), z(), y()); }
constexpr vec<T, 4> rgga() { return vec<T, 4>(r(), g(), g(), a()); }
constexpr vec<T, 4> gbrg() { return vec<T, 4>(g(), b(), r(), g()); }
constexpr vec<T, 4> zyzx() { return vec<T, 4>(z(), y(), z(), x()); }
constexpr vec<T, 4> rbrg() { return vec<T, 4>(r(), b(), r(), g()); }
constexpr vec<T, 4> zzwy() { return vec<T, 4>(z(), z(), w(), y()); }
constexpr vec<T, 4> gbgr() { return vec<T, 4>(g(), b(), g(), r()); }
constexpr vec<T, 4> rbgr() { return vec<T, 4>(r(), b(), g(), r()); }
constexpr vec<T, 4> brbg() { return vec<T, 4>(b(), r(), b(), g()); }
constexpr vec<T, 4> xyzx() { return vec<T, 4>(x(), y(), z(), x()); }
constexpr vec<T, 2>   xx() { return vec<T, 2>(x(), x()); }
constexpr vec<T, 4> xxyz() { return vec<T, 4>(x(), x(), y(), z()); }
constexpr vec<T, 4> wzwy() { return vec<T, 4>(w(), z(), w(), y()); }
constexpr vec<T, 3>  gaa() { return vec<T, 3>(g(), a(), a()); }
constexpr vec<T, 4> xwxy() { return vec<T, 4>(x(), w(), x(), y()); }
constexpr vec<T, 4> arrr() { return vec<T, 4>(a(), r(), r(), r()); }
constexpr vec<T, 2>   rb() { return vec<T, 2>(r(), b()); }
constexpr vec<T, 4> gbbr() { return vec<T, 4>(g(), b(), b(), r()); }
constexpr vec<T, 4> zzxw() { return vec<T, 4>(z(), z(), x(), w()); }
constexpr vec<T, 4> wyxy() { return vec<T, 4>(w(), y(), x(), y()); }
constexpr vec<T, 4> rbbr() { return vec<T, 4>(r(), b(), b(), r()); }
constexpr vec<T, 3>  zxy() { return vec<T, 3>(z(), x(), y()); }
constexpr vec<T, 4> aarg() { return vec<T, 4>(a(), a(), r(), g()); }
constexpr vec<T, 3>  agg() { return vec<T, 3>(a(), g(), g()); }
constexpr vec<T, 3>  xxy() { return vec<T, 3>(x(), x(), y()); }
constexpr vec<T, 4> yxwy() { return vec<T, 4>(y(), x(), w(), y()); }
constexpr vec<T, 4> yyzz() { return vec<T, 4>(y(), y(), z(), z()); }
constexpr vec<T, 4> wxxz() { return vec<T, 4>(w(), x(), x(), z()); }
constexpr vec<T, 3>  wyw() { return vec<T, 3>(w(), y(), w()); }
constexpr vec<T, 2>   zy() { return vec<T, 2>(z(), y()); }
constexpr vec<T, 2>   ra() { return vec<T, 2>(r(), a()); }
constexpr vec<T, 3>  ggr() { return vec<T, 3>(g(), g(), r()); }
constexpr vec<T, 4> xxxw() { return vec<T, 4>(x(), x(), x(), w()); }
constexpr vec<T, 4> grbg() { return vec<T, 4>(g(), r(), b(), g()); }
constexpr vec<T, 4> brrr() { return vec<T, 4>(b(), r(), r(), r()); }
constexpr vec<T, 4> rgbb() { return vec<T, 4>(r(), g(), b(), b()); }
constexpr vec<T, 4> bbrb() { return vec<T, 4>(b(), b(), r(), b()); }
constexpr vec<T, 4> ggbb() { return vec<T, 4>(g(), g(), b(), b()); }
constexpr vec<T, 4> ywyw() { return vec<T, 4>(y(), w(), y(), w()); }
constexpr vec<T, 4> xxxx() { return vec<T, 4>(x(), x(), x(), x()); }
constexpr vec<T, 4> arbg() { return vec<T, 4>(a(), r(), b(), g()); }
constexpr vec<T, 4> yzwx() { return vec<T, 4>(y(), z(), w(), x()); }
constexpr vec<T, 2>   wz() { return vec<T, 2>(w(), z()); }
constexpr vec<T, 4> xzyw() { return vec<T, 4>(x(), z(), y(), w()); }
constexpr vec<T, 4> yyxx() { return vec<T, 4>(y(), y(), x(), x()); }
constexpr vec<T, 3>  gar() { return vec<T, 3>(g(), a(), r()); }
constexpr vec<T, 4> ggba() { return vec<T, 4>(g(), g(), b(), a()); }
constexpr vec<T, 4> wyzx() { return vec<T, 4>(w(), y(), z(), x()); }
constexpr vec<T, 4> bbra() { return vec<T, 4>(b(), b(), r(), a()); }
constexpr vec<T, 4> xzyx() { return vec<T, 4>(x(), z(), y(), x()); }
constexpr vec<T, 3>  yzz() { return vec<T, 3>(y(), z(), z()); }
constexpr vec<T, 4> zxzx() { return vec<T, 4>(z(), x(), z(), x()); }
constexpr vec<T, 4> wxzx() { return vec<T, 4>(w(), x(), z(), x()); }
constexpr vec<T, 4> baab() { return vec<T, 4>(b(), a(), a(), b()); }
constexpr vec<T, 4> wzxw() { return vec<T, 4>(w(), z(), x(), w()); }
constexpr vec<T, 3>  rgb() { return vec<T, 3>(r(), g(), b()); }
constexpr vec<T, 4> ywww() { return vec<T, 4>(y(), w(), w(), w()); }
constexpr vec<T, 4> aggg() { return vec<T, 4>(a(), g(), g(), g()); }
constexpr vec<T, 4> xwxz() { return vec<T, 4>(x(), w(), x(), z()); }
constexpr vec<T, 2>   rr() { return vec<T, 2>(r(), r()); }
constexpr vec<T, 4> ragg() { return vec<T, 4>(r(), a(), g(), g()); }
constexpr vec<T, 4> wyxz() { return vec<T, 4>(w(), y(), x(), z()); }
constexpr vec<T, 4> zyzy() { return vec<T, 4>(z(), y(), z(), y()); }
constexpr vec<T, 4> yzzw() { return vec<T, 4>(y(), z(), z(), w()); }
constexpr vec<T, 3>  zwx() { return vec<T, 3>(z(), w(), x()); }
constexpr vec<T, 4> agbg() { return vec<T, 4>(a(), g(), b(), g()); }
constexpr vec<T, 2>   xy() { return vec<T, 2>(x(), y()); }
constexpr vec<T, 4> xzww() { return vec<T, 4>(x(), z(), w(), w()); }
constexpr vec<T, 4> gabg() { return vec<T, 4>(g(), a(), b(), g()); }
constexpr vec<T, 4> yxxw() { return vec<T, 4>(y(), x(), x(), w()); }
constexpr vec<T, 4> ggrg() { return vec<T, 4>(g(), g(), r(), g()); }
constexpr vec<T, 3>  xxz() { return vec<T, 3>(x(), x(), z()); }
constexpr vec<T, 4> rgrg() { return vec<T, 4>(r(), g(), r(), g()); }
constexpr vec<T, 4> rabg() { return vec<T, 4>(r(), a(), b(), g()); }
constexpr vec<T, 4> baaa() { return vec<T, 4>(b(), a(), a(), a()); }
constexpr vec<T, 3>  rga() { return vec<T, 3>(r(), g(), a()); }
constexpr vec<T, 3>  rab() { return vec<T, 3>(r(), a(), b()); }
constexpr vec<T, 3>  aag() { return vec<T, 3>(a(), a(), g()); }
constexpr vec<T, 4> yyyw() { return vec<T, 4>(y(), y(), y(), w()); }
constexpr vec<T, 4> zwzz() { return vec<T, 4>(z(), w(), z(), z()); }
constexpr vec<T, 4> rrga() { return vec<T, 4>(r(), r(), g(), a()); }
constexpr vec<T, 4> wwzz() { return vec<T, 4>(w(), w(), z(), z()); }
constexpr vec<T, 4> gbrb() { return vec<T, 4>(g(), b(), r(), b()); }
constexpr vec<T, 4> bggg() { return vec<T, 4>(b(), g(), g(), g()); }
constexpr vec<T, 4> rbrb() { return vec<T, 4>(r(), b(), r(), b()); }
constexpr vec<T, 4> ggbr() { return vec<T, 4>(g(), g(), b(), r()); }
constexpr vec<T, 4> zzxy() { return vec<T, 4>(z(), z(), x(), y()); }
constexpr vec<T, 4> rgbr() { return vec<T, 4>(r(), g(), b(), r()); }
constexpr vec<T, 4> bbrr() { return vec<T, 4>(b(), b(), r(), r()); }
constexpr vec<T, 3>  raa() { return vec<T, 3>(r(), a(), a()); }
constexpr vec<T, 4> bgbg() { return vec<T, 4>(b(), g(), b(), g()); }
constexpr vec<T, 3>  www() { return vec<T, 3>(w(), w(), w()); }
constexpr vec<T, 3>  wyy() { return vec<T, 3>(w(), y(), y()); }
constexpr vec<T, 4> aarb() { return vec<T, 4>(a(), a(), r(), b()); }
constexpr vec<T, 4> gbra() { return vec<T, 4>(g(), b(), r(), a()); }
constexpr vec<T, 3>  zzw() { return vec<T, 3>(z(), z(), w()); }
constexpr vec<T, 4> xwzx() { return vec<T, 4>(x(), w(), z(), x()); }
constexpr vec<T, 4> rbra() { return vec<T, 4>(r(), b(), r(), a()); }
constexpr vec<T, 4> garr() { return vec<T, 4>(g(), a(), r(), r()); }
constexpr vec<T, 3>  agb() { return vec<T, 3>(a(), g(), b()); }
constexpr vec<T, 4> brba() { return vec<T, 4>(b(), r(), b(), a()); }
constexpr vec<T, 4> xxxy() { return vec<T, 4>(x(), x(), x(), y()); }
constexpr vec<T, 3>  zzx() { return vec<T, 3>(z(), z(), x()); }
constexpr vec<T, 3>  bbg() { return vec<T, 3>(b(), b(), g()); }
constexpr vec<T, 4> ywyy() { return vec<T, 4>(y(), w(), y(), y()); }
constexpr vec<T, 4> yzwy() { return vec<T, 4>(y(), z(), w(), y()); }
constexpr vec<T, 3>  yyw() { return vec<T, 3>(y(), y(), w()); }
constexpr vec<T, 3>  xzx() { return vec<T, 3>(x(), z(), x()); }
constexpr vec<T, 3>  grb() { return vec<T, 3>(g(), r(), b()); }
constexpr vec<T, 4> baar() { return vec<T, 4>(b(), a(), a(), r()); }
constexpr vec<T, 4> aara() { return vec<T, 4>(a(), a(), r(), a()); }
constexpr vec<T, 3>  rgr() { return vec<T, 3>(r(), g(), r()); }
constexpr vec<T, 4> grbb() { return vec<T, 4>(g(), r(), b(), b()); }
constexpr vec<T, 4> wyzy() { return vec<T, 4>(w(), y(), z(), y()); }
constexpr vec<T, 4> rrbb() { return vec<T, 4>(r(), r(), b(), b()); }
constexpr vec<T, 4> xzyy() { return vec<T, 4>(x(), z(), y(), y()); }
constexpr vec<T, 3>  aga() { return vec<T, 3>(a(), g(), a()); }
constexpr vec<T, 4> zxzy() { return vec<T, 4>(z(), x(), z(), y()); }
constexpr vec<T, 4> zyzz() { return vec<T, 4>(z(), y(), z(), z()); }
constexpr vec<T, 4> abgg() { return vec<T, 4>(a(), b(), g(), g()); }
constexpr vec<T, 4> wxzy() { return vec<T, 4>(w(), x(), z(), y()); }
constexpr vec<T, 4> xyzz() { return vec<T, 4>(x(), y(), z(), z()); }
constexpr vec<T, 2>   xz() { return vec<T, 2>(x(), z()); }
constexpr vec<T, 3>  gra() { return vec<T, 3>(g(), r(), a()); }
constexpr vec<T, 4> grba() { return vec<T, 4>(g(), r(), b(), a()); }
constexpr vec<T, 4> gbag() { return vec<T, 4>(g(), b(), a(), g()); }
constexpr vec<T, 4> rrba() { return vec<T, 4>(r(), r(), b(), a()); }
constexpr vec<T, 4> wzxy() { return vec<T, 4>(w(), z(), x(), y()); }
constexpr vec<T, 4> yzyz() { return vec<T, 4>(y(), z(), y(), z()); }
constexpr vec<T, 4> zwyw() { return vec<T, 4>(z(), w(), y(), w()); }
constexpr vec<T, 4> rbrr() { return vec<T, 4>(r(), b(), r(), r()); }
constexpr vec<T, 4> abag() { return vec<T, 4>(a(), b(), a(), g()); }
constexpr vec<T, 4> wwyw() { return vec<T, 4>(w(), w(), y(), w()); }
constexpr vec<T, 4> yzzy() { return vec<T, 4>(y(), z(), z(), y()); }
constexpr vec<T, 2>   ab() { return vec<T, 2>(a(), b()); }
constexpr vec<T, 4> yxxy() { return vec<T, 4>(y(), x(), x(), y()); }
constexpr vec<T, 4> aarr() { return vec<T, 4>(a(), a(), r(), r()); }
constexpr vec<T, 4> agbb() { return vec<T, 4>(a(), g(), b(), b()); }
constexpr vec<T, 3>  agr() { return vec<T, 3>(a(), g(), r()); }
constexpr vec<T, 4> grrg() { return vec<T, 4>(g(), r(), r(), g()); }
constexpr vec<T, 4> gabb() { return vec<T, 4>(g(), a(), b(), b()); }
constexpr vec<T, 2>   aa() { return vec<T, 2>(a(), a()); }
constexpr vec<T, 4> zxxx() { return vec<T, 4>(z(), x(), x(), x()); }
constexpr vec<T, 4> rrrg() { return vec<T, 4>(r(), r(), r(), g()); }
constexpr vec<T, 4> rgrb() { return vec<T, 4>(r(), g(), r(), b()); }
constexpr vec<T, 4> rabb() { return vec<T, 4>(r(), a(), b(), b()); }
constexpr vec<T, 4> xxwx() { return vec<T, 4>(x(), x(), w(), x()); }
constexpr vec<T, 4> yzwz() { return vec<T, 4>(y(), z(), w(), z()); }
constexpr vec<T, 4> ggag() { return vec<T, 4>(g(), g(), a(), g()); }
constexpr vec<T, 3>  grr() { return vec<T, 3>(g(), r(), r()); }
constexpr vec<T, 3>  wwy() { return vec<T, 3>(w(), w(), y()); }
constexpr vec<T, 4> yzxx() { return vec<T, 4>(y(), z(), x(), x()); }
constexpr vec<T, 4> xwzy() { return vec<T, 4>(x(), w(), z(), y()); }
constexpr vec<T, 4> yyxz() { return vec<T, 4>(y(), y(), x(), z()); }
constexpr vec<T, 4> grbr() { return vec<T, 4>(g(), r(), b(), r()); }
constexpr vec<T, 4> rrbr() { return vec<T, 4>(r(), r(), b(), r()); }
constexpr vec<T, 4> wyzz() { return vec<T, 4>(w(), y(), z(), z()); }
constexpr vec<T, 4> agba() { return vec<T, 4>(a(), g(), b(), a()); }
constexpr vec<T, 4> gaba() { return vec<T, 4>(g(), a(), b(), a()); }
constexpr vec<T, 4> ggra() { return vec<T, 4>(g(), g(), r(), a()); }
constexpr vec<T, 3>  zzy() { return vec<T, 3>(z(), z(), y()); }
constexpr vec<T, 4> raba() { return vec<T, 4>(r(), a(), b(), a()); }
constexpr vec<T, 4> rgra() { return vec<T, 4>(r(), g(), r(), a()); }
constexpr vec<T, 4> zxzz() { return vec<T, 4>(z(), x(), z(), z()); }
constexpr vec<T, 4> yxzw() { return vec<T, 4>(y(), x(), z(), w()); }
constexpr vec<T, 3>  aaa() { return vec<T, 3>(a(), a(), a()); }
constexpr vec<T, 4> bgbb() { return vec<T, 4>(b(), g(), b(), b()); }
constexpr vec<T, 3>  xzy() { return vec<T, 3>(x(), z(), y()); }
constexpr vec<T, 3>  yww() { return vec<T, 3>(y(), w(), w()); }
constexpr vec<T, 4> wxzz() { return vec<T, 4>(w(), x(), z(), z()); }
constexpr vec<T, 3>  yyy() { return vec<T, 3>(y(), y(), y()); }
constexpr vec<T, 4> yxzx() { return vec<T, 4>(y(), x(), z(), x()); }
constexpr vec<T, 4> aaab() { return vec<T, 4>(a(), a(), a(), b()); }
constexpr vec<T, 4> ywxw() { return vec<T, 4>(y(), w(), x(), w()); }
constexpr vec<T, 4> wzwx() { return vec<T, 4>(w(), z(), w(), x()); }
constexpr vec<T, 4> xxzw() { return vec<T, 4>(x(), x(), z(), w()); }
constexpr vec<T, 3>  bbb() { return vec<T, 3>(b(), b(), b()); }
constexpr vec<T, 4> bgba() { return vec<T, 4>(b(), g(), b(), a()); }
constexpr vec<T, 3>  zwz() { return vec<T, 3>(z(), w(), z()); }
constexpr vec<T, 3>  rrb() { return vec<T, 3>(r(), r(), b()); }
constexpr vec<T, 2>   ar() { return vec<T, 2>(a(), r()); }
constexpr vec<T, 3>  arg() { return vec<T, 3>(a(), r(), g()); }
constexpr vec<T, 4> xxzx() { return vec<T, 4>(x(), x(), z(), x()); }
constexpr vec<T, 4> xzxw() { return vec<T, 4>(x(), z(), x(), w()); }
constexpr vec<T, 4> aaaa() { return vec<T, 4>(a(), a(), a(), a()); }
constexpr vec<T, 4> yxwx() { return vec<T, 4>(y(), x(), w(), x()); }
constexpr vec<T, 3>  bba() { return vec<T, 3>(b(), b(), a()); }
constexpr vec<T, 2>   zx() { return vec<T, 2>(z(), x()); }
constexpr vec<T, 4> zwww() { return vec<T, 4>(z(), w(), w(), w()); }
constexpr vec<T, 4> abgb() { return vec<T, 4>(a(), b(), g(), b()); }
constexpr vec<T, 4> agbr() { return vec<T, 4>(a(), g(), b(), r()); }
constexpr vec<T, 4> zwyy() { return vec<T, 4>(z(), w(), y(), y()); }
constexpr vec<T, 3>  rra() { return vec<T, 3>(r(), r(), a()); }
constexpr vec<T, 4> rabr() { return vec<T, 4>(r(), a(), b(), r()); }
constexpr vec<T, 4> wwww() { return vec<T, 4>(w(), w(), w(), w()); }
constexpr vec<T, 4> rgrr() { return vec<T, 4>(r(), g(), r(), r()); }
constexpr vec<T, 4> wwyy() { return vec<T, 4>(w(), w(), y(), y()); }
constexpr vec<T, 4> zzzw() { return vec<T, 4>(z(), z(), z(), w()); }
constexpr vec<T, 4> gbab() { return vec<T, 4>(g(), b(), a(), b()); }
constexpr vec<T, 4> rbab() { return vec<T, 4>(r(), b(), a(), b()); }
constexpr vec<T, 4> abbb() { return vec<T, 4>(a(), b(), b(), b()); }
constexpr vec<T, 4> bbar() { return vec<T, 4>(b(), b(), a(), r()); }
constexpr vec<T, 4> wzzw() { return vec<T, 4>(w(), z(), z(), w()); }
constexpr vec<T, 3>  wxw() { return vec<T, 3>(w(), x(), w()); }
constexpr vec<T, 4> zzzx() { return vec<T, 4>(z(), z(), z(), x()); }
constexpr vec<T, 4> xwzz() { return vec<T, 4>(x(), w(), z(), z()); }
constexpr vec<T, 4> abga() { return vec<T, 4>(a(), b(), g(), a()); }
constexpr vec<T, 4> zyyw() { return vec<T, 4>(z(), y(), y(), w()); }
constexpr vec<T, 4> xyyw() { return vec<T, 4>(x(), y(), y(), w()); }
constexpr vec<T, 4> wyyw() { return vec<T, 4>(w(), y(), y(), w()); }
constexpr vec<T, 4> gggb() { return vec<T, 4>(g(), g(), g(), b()); }
constexpr vec<T, 4> bgbr() { return vec<T, 4>(b(), g(), b(), r()); }
constexpr vec<T, 4> gbaa() { return vec<T, 4>(g(), b(), a(), a()); }
constexpr vec<T, 4> barr() { return vec<T, 4>(b(), a(), r(), r()); }
constexpr vec<T, 3>  xzz() { return vec<T, 3>(x(), z(), z()); }
constexpr vec<T, 4> xyyx() { return vec<T, 4>(x(), y(), y(), x()); }
constexpr vec<T, 4> zxyw() { return vec<T, 4>(z(), x(), y(), w()); }
constexpr vec<T, 4> wxyw() { return vec<T, 4>(w(), x(), y(), w()); }
constexpr vec<T, 4> aaar() { return vec<T, 4>(a(), a(), a(), r()); }
constexpr vec<T, 4> wzyz() { return vec<T, 4>(w(), z(), y(), z()); }
constexpr vec<T, 4> rrrb() { return vec<T, 4>(r(), r(), r(), b()); }
constexpr vec<T, 3>  bbr() { return vec<T, 3>(b(), b(), r()); }
constexpr vec<T, 4> brgg() { return vec<T, 4>(b(), r(), g(), g()); }
constexpr vec<T, 4> ggab() { return vec<T, 4>(g(), g(), a(), b()); }
constexpr vec<T, 4> yxzy() { return vec<T, 4>(y(), x(), z(), y()); }
constexpr vec<T, 3>  rrr() { return vec<T, 3>(r(), r(), r()); }
constexpr vec<T, 4> rrra() { return vec<T, 4>(r(), r(), r(), a()); }
constexpr vec<T, 4> abrg() { return vec<T, 4>(a(), b(), r(), g()); }
constexpr vec<T, 4> abgr() { return vec<T, 4>(a(), b(), g(), r()); }
constexpr vec<T, 4> bgrg() { return vec<T, 4>(b(), g(), r(), g()); }
constexpr vec<T, 4> ggaa() { return vec<T, 4>(g(), g(), a(), a()); }
constexpr vec<T, 4> babg() { return vec<T, 4>(b(), a(), b(), g()); }
constexpr vec<T, 4> xxzy() { return vec<T, 4>(x(), x(), z(), y()); }
constexpr vec<T, 4> gbar() { return vec<T, 4>(g(), b(), a(), r()); }
constexpr vec<T, 4> zzxx() { return vec<T, 4>(z(), z(), x(), x()); }
constexpr vec<T, 4> rbar() { return vec<T, 4>(r(), b(), a(), r()); }
constexpr vec<T, 4> abbr() { return vec<T, 4>(a(), b(), b(), r()); }
constexpr vec<T, 4> zyxz() { return vec<T, 4>(z(), y(), x(), z()); }
constexpr vec<T, 3>  xyw() { return vec<T, 3>(x(), y(), w()); }
constexpr vec<T, 3>  wyx() { return vec<T, 3>(w(), y(), x()); }
constexpr vec<T, 3>  arb() { return vec<T, 3>(a(), r(), b()); }
constexpr vec<T, 4> zxxz() { return vec<T, 4>(z(), x(), x(), z()); }
constexpr vec<T, 4> zwwy() { return vec<T, 4>(z(), w(), w(), y()); }
constexpr vec<T, 4> argg() { return vec<T, 4>(a(), r(), g(), g()); }
constexpr vec<T, 3>  xyx() { return vec<T, 3>(x(), y(), x()); }
constexpr vec<T, 4> xxwz() { return vec<T, 4>(x(), x(), w(), z()); }
constexpr vec<T, 4> gggr() { return vec<T, 4>(g(), g(), g(), r()); }
constexpr vec<T, 4> rggr() { return vec<T, 4>(r(), g(), g(), r()); }
constexpr vec<T, 4> zzzy() { return vec<T, 4>(z(), z(), z(), y()); }
constexpr vec<T, 4> grag() { return vec<T, 4>(g(), r(), a(), g()); }
constexpr vec<T, 4> yzxz() { return vec<T, 4>(y(), z(), x(), z()); }
constexpr vec<T, 4> rrag() { return vec<T, 4>(r(), r(), a(), g()); }
constexpr vec<T, 4> rgab() { return vec<T, 4>(r(), g(), a(), b()); }
constexpr vec<T, 4> ywyx() { return vec<T, 4>(y(), w(), y(), x()); }
constexpr vec<T, 4> wzzy() { return vec<T, 4>(w(), z(), z(), y()); }
constexpr vec<T, 3>  wxy() { return vec<T, 3>(w(), x(), y()); }
constexpr vec<T, 4> zyww() { return vec<T, 4>(z(), y(), w(), w()); }
constexpr vec<T, 3>  ara() { return vec<T, 3>(a(), r(), a()); }
constexpr vec<T, 4> zyyy() { return vec<T, 4>(z(), y(), y(), y()); }
constexpr vec<T, 4> xyww() { return vec<T, 4>(x(), y(), w(), w()); }
constexpr vec<T, 4> wyww() { return vec<T, 4>(w(), y(), w(), w()); }
constexpr vec<T, 4> rarg() { return vec<T, 4>(r(), a(), r(), g()); }
constexpr vec<T, 4> xyyy() { return vec<T, 4>(x(), y(), y(), y()); }
constexpr vec<T, 4> zxww() { return vec<T, 4>(z(), x(), w(), w()); }
constexpr vec<T, 4> rgaa() { return vec<T, 4>(r(), g(), a(), a()); }
constexpr vec<T, 4> zzwz() { return vec<T, 4>(z(), z(), w(), z()); }
constexpr vec<T, 4> wxww() { return vec<T, 4>(w(), x(), w(), w()); }
constexpr vec<T, 4> wzwz() { return vec<T, 4>(w(), z(), w(), z()); }
constexpr vec<T, 4> grgb() { return vec<T, 4>(g(), r(), g(), b()); }
constexpr vec<T, 4> gagg() { return vec<T, 4>(g(), a(), g(), g()); }
constexpr vec<T, 4> rrgb() { return vec<T, 4>(r(), r(), g(), b()); }
constexpr vec<T, 4> wzxx() { return vec<T, 4>(w(), z(), x(), x()); }
constexpr vec<T, 4> ywwx() { return vec<T, 4>(y(), w(), w(), x()); }
constexpr vec<T, 3>  zxz() { return vec<T, 3>(z(), x(), z()); }
constexpr vec<T, 4> aagg() { return vec<T, 4>(a(), a(), g(), g()); }
constexpr vec<T, 4> xwyw() { return vec<T, 4>(x(), w(), y(), w()); }
constexpr vec<T, 4> yxwz() { return vec<T, 4>(y(), x(), w(), z()); }
constexpr vec<T, 4> yzzx() { return vec<T, 4>(y(), z(), z(), x()); }
constexpr vec<T, 4> xzwx() { return vec<T, 4>(x(), z(), w(), x()); }
constexpr vec<T, 2>   zz() { return vec<T, 2>(z(), z()); }
constexpr vec<T, 4> grga() { return vec<T, 4>(g(), r(), g(), a()); }
constexpr vec<T, 4> yxxx() { return vec<T, 4>(y(), x(), x(), x()); }
constexpr vec<T, 4> brgb() { return vec<T, 4>(b(), r(), g(), b()); }
constexpr vec<T, 4> gaag() { return vec<T, 4>(g(), a(), a(), g()); }
constexpr vec<T, 3>  arr() { return vec<T, 3>(a(), r(), r()); }
constexpr vec<T, 4> yyyx() { return vec<T, 4>(y(), y(), y(), x()); }
constexpr vec<T, 4> zwxw() { return vec<T, 4>(z(), w(), x(), w()); }
constexpr vec<T, 4> brbb() { return vec<T, 4>(b(), r(), b(), b()); }
constexpr vec<T, 4> wwxw() { return vec<T, 4>(w(), w(), x(), w()); }
constexpr vec<T, 4> abrb() { return vec<T, 4>(a(), b(), r(), b()); }
constexpr vec<T, 4> zzzz() { return vec<T, 4>(z(), z(), z(), z()); }
constexpr vec<T, 4> rgar() { return vec<T, 4>(r(), g(), a(), r()); }
constexpr vec<T, 2>   bg() { return vec<T, 2>(b(), g()); }
constexpr vec<T, 4> brga() { return vec<T, 4>(b(), r(), g(), a()); }
constexpr vec<T, 4> ywzw() { return vec<T, 4>(y(), w(), z(), w()); }
constexpr vec<T, 3>  wwx() { return vec<T, 3>(w(), w(), x()); }
constexpr vec<T, 4> bgag() { return vec<T, 4>(b(), g(), a(), g()); }
constexpr vec<T, 3>  xyy() { return vec<T, 3>(x(), y(), y()); }
constexpr vec<T, 4> xwww() { return vec<T, 4>(x(), w(), w(), w()); }
constexpr vec<T, 4> bbgg() { return vec<T, 4>(b(), b(), g(), g()); }
constexpr vec<T, 4> abra() { return vec<T, 4>(a(), b(), r(), a()); }
constexpr vec<T, 4> xzzw() { return vec<T, 4>(x(), z(), z(), w()); }
constexpr vec<T, 4> baba() { return vec<T, 4>(b(), a(), b(), a()); }
constexpr vec<T, 3>  xww() { return vec<T, 3>(x(), w(), w()); }
constexpr vec<T, 3>  bgg() { return vec<T, 3>(b(), g(), g()); }
constexpr vec<T, 3>  yxw() { return vec<T, 3>(y(), x(), w()); }
constexpr vec<T, 4> argb() { return vec<T, 4>(a(), r(), g(), b()); }
constexpr vec<T, 3>  yyx() { return vec<T, 3>(y(), y(), x()); }
constexpr vec<T, 4> bbbg() { return vec<T, 4>(b(), b(), b(), g()); }
constexpr vec<T, 4> grgr() { return vec<T, 4>(g(), r(), g(), r()); }
constexpr vec<T, 4> rrgr() { return vec<T, 4>(r(), r(), g(), r()); }
constexpr vec<T, 4> xywy() { return vec<T, 4>(x(), y(), w(), y()); }
constexpr vec<T, 4> grab() { return vec<T, 4>(g(), r(), a(), b()); }
constexpr vec<T, 4> rrab() { return vec<T, 4>(r(), r(), a(), b()); }
constexpr vec<T, 4> arbb() { return vec<T, 4>(a(), r(), b(), b()); }
constexpr vec<T, 4> aabg() { return vec<T, 4>(a(), a(), b(), g()); }
constexpr vec<T, 3>  wzw() { return vec<T, 3>(w(), z(), w()); }
constexpr vec<T, 4> arga() { return vec<T, 4>(a(), r(), g(), a()); }
constexpr vec<T, 3>  rar() { return vec<T, 3>(r(), a(), r()); }
constexpr vec<T, 4> xyxw() { return vec<T, 4>(x(), y(), x(), w()); }
constexpr vec<T, 4> brgr() { return vec<T, 4>(b(), r(), g(), r()); }
constexpr vec<T, 4> agag() { return vec<T, 4>(a(), g(), a(), g()); }
constexpr vec<T, 4> ywwy() { return vec<T, 4>(y(), w(), w(), y()); }
constexpr vec<T, 2>   yw() { return vec<T, 2>(y(), w()); }
constexpr vec<T, 4> raag() { return vec<T, 4>(r(), a(), a(), g()); }
constexpr vec<T, 4> gbrr() { return vec<T, 4>(g(), b(), r(), r()); }
constexpr vec<T, 4> graa() { return vec<T, 4>(g(), r(), a(), a()); }
constexpr vec<T, 4> rraa() { return vec<T, 4>(r(), r(), a(), a()); }
constexpr vec<T, 4> arba() { return vec<T, 4>(a(), r(), b(), a()); }
constexpr vec<T, 4> zzxz() { return vec<T, 4>(z(), z(), x(), z()); }
constexpr vec<T, 4> brbr() { return vec<T, 4>(b(), r(), b(), r()); }
constexpr vec<T, 4> zwyx() { return vec<T, 4>(z(), w(), y(), x()); }
constexpr vec<T, 4> xzwy() { return vec<T, 4>(x(), z(), w(), y()); }
constexpr vec<T, 4> xwyy() { return vec<T, 4>(x(), w(), y(), y()); }
constexpr vec<T, 4> abrr() { return vec<T, 4>(a(), b(), r(), r()); }
constexpr vec<T, 4> aggb() { return vec<T, 4>(a(), g(), g(), b()); }
constexpr vec<T, 4> wwyx() { return vec<T, 4>(w(), w(), y(), x()); }
constexpr vec<T, 4> gagb() { return vec<T, 4>(g(), a(), g(), b()); }
constexpr vec<T, 4> yyww() { return vec<T, 4>(y(), y(), w(), w()); }
constexpr vec<T, 4> ragb() { return vec<T, 4>(r(), a(), g(), b()); }
constexpr vec<T, 3>  wyz() { return vec<T, 3>(w(), y(), z()); }
constexpr vec<T, 4> yyyy() { return vec<T, 4>(y(), y(), y(), y()); }
constexpr vec<T, 4> yxyw() { return vec<T, 4>(y(), x(), y(), w()); }
constexpr vec<T, 3>  xyz() { return vec<T, 3>(x(), y(), z()); }
constexpr vec<T, 4> yywx() { return vec<T, 4>(y(), y(), w(), x()); }
constexpr vec<T, 4> zwxy() { return vec<T, 4>(z(), w(), x(), y()); }
constexpr vec<T, 4> ggrb() { return vec<T, 4>(g(), g(), r(), b()); }
constexpr vec<T, 4> xxxz() { return vec<T, 4>(x(), x(), x(), z()); }
constexpr vec<T, 3>  aab() { return vec<T, 3>(a(), a(), b()); }
constexpr vec<T, 4> wwxy() { return vec<T, 4>(w(), w(), x(), y()); }
constexpr vec<T, 4> agga() { return vec<T, 4>(a(), g(), g(), a()); }
constexpr vec<T, 4> ywyz() { return vec<T, 4>(y(), w(), y(), z()); }
constexpr vec<T, 4> gaga() { return vec<T, 4>(g(), a(), g(), a()); }
constexpr vec<T, 4> arrg() { return vec<T, 4>(a(), r(), r(), g()); }
constexpr vec<T, 4> raga() { return vec<T, 4>(r(), a(), g(), a()); }
constexpr vec<T, 4> gbbg() { return vec<T, 4>(g(), b(), b(), g()); }
constexpr vec<T, 4> rbbg() { return vec<T, 4>(r(), b(), b(), g()); }
constexpr vec<T, 4> bggb() { return vec<T, 4>(b(), g(), g(), b()); }
constexpr vec<T, 4> xxyw() { return vec<T, 4>(x(), x(), y(), w()); }
constexpr vec<T, 4> xzyz() { return vec<T, 4>(x(), z(), y(), z()); }
constexpr vec<T, 4> grar() { return vec<T, 4>(g(), r(), a(), r()); }
constexpr vec<T, 4> rrar() { return vec<T, 4>(r(), r(), a(), r()); }
constexpr vec<T, 4> arbr() { return vec<T, 4>(a(), r(), b(), r()); }
constexpr vec<T, 4> xzzy() { return vec<T, 4>(x(), z(), z(), y()); }
constexpr vec<T, 4> bgga() { return vec<T, 4>(b(), g(), g(), a()); }
constexpr vec<T, 4> yyzw() { return vec<T, 4>(y(), y(), z(), w()); }
constexpr vec<T, 4> wxxw() { return vec<T, 4>(w(), x(), x(), w()); }
constexpr vec<T, 3>  ggg() { return vec<T, 3>(g(), g(), g()); }
constexpr vec<T, 3>  ywx() { return vec<T, 3>(y(), w(), x()); }
constexpr vec<T, 4> brrg() { return vec<T, 4>(b(), r(), r(), g()); }
constexpr vec<T, 4> wzxz() { return vec<T, 4>(w(), z(), x(), z()); }
constexpr vec<T, 4> ywwz() { return vec<T, 4>(y(), w(), w(), z()); }
constexpr vec<T, 2>   ba() { return vec<T, 2>(b(), a()); }
constexpr vec<T, 3>  gbg() { return vec<T, 3>(g(), b(), g()); }
constexpr vec<T, 4> ywxx() { return vec<T, 4>(y(), w(), x(), x()); }
constexpr vec<T, 3>  bgb() { return vec<T, 3>(b(), g(), b()); }
constexpr vec<T, 4> yzzz() { return vec<T, 4>(y(), z(), z(), z()); }
constexpr vec<T, 4> bgaa() { return vec<T, 4>(b(), g(), a(), a()); }
constexpr vec<T, 4> bbbb() { return vec<T, 4>(b(), b(), b(), b()); }
constexpr vec<T, 4> aggr() { return vec<T, 4>(a(), g(), g(), r()); }
constexpr vec<T, 4> xzwz() { return vec<T, 4>(x(), z(), w(), z()); }
constexpr vec<T, 3>  wzy() { return vec<T, 3>(w(), z(), y()); }
constexpr vec<T, 4> yxxz() { return vec<T, 4>(y(), x(), x(), z()); }
constexpr vec<T, 4> gagr() { return vec<T, 4>(g(), a(), g(), r()); }
constexpr vec<T, 4> ragr() { return vec<T, 4>(r(), a(), g(), r()); }
constexpr vec<T, 4> xzxx() { return vec<T, 4>(x(), z(), x(), x()); }
constexpr vec<T, 4> yyyz() { return vec<T, 4>(y(), y(), y(), z()); }
constexpr vec<T, 2>   ww() { return vec<T, 2>(w(), w()); }
constexpr vec<T, 4> aabb() { return vec<T, 4>(a(), a(), b(), b()); }
constexpr vec<T, 2>   yy() { return vec<T, 2>(y(), y()); }
constexpr vec<T, 4> gabr() { return vec<T, 4>(g(), a(), b(), r()); }
constexpr vec<T, 3>  bga() { return vec<T, 3>(b(), g(), a()); }
constexpr vec<T, 4> ggrr() { return vec<T, 4>(g(), g(), r(), r()); }
constexpr vec<T, 4> zwwx() { return vec<T, 4>(z(), w(), w(), x()); }
constexpr vec<T, 4> bbba() { return vec<T, 4>(b(), b(), b(), a()); }
constexpr vec<T, 3>  yzw() { return vec<T, 3>(y(), z(), w()); }
constexpr vec<T, 3>  aar() { return vec<T, 3>(a(), a(), r()); }
constexpr vec<T, 4> wwwx() { return vec<T, 4>(w(), w(), w(), x()); }
constexpr vec<T, 3>  wwz() { return vec<T, 3>(w(), w(), z()); }
constexpr vec<T, 4> bggr() { return vec<T, 4>(b(), g(), g(), r()); }
constexpr vec<T, 4> yywy() { return vec<T, 4>(y(), y(), w(), y()); }
constexpr vec<T, 4> abab() { return vec<T, 4>(a(), b(), a(), b()); }
constexpr vec<T, 4> aaba() { return vec<T, 4>(a(), a(), b(), a()); }
constexpr vec<T, 4> wzzx() { return vec<T, 4>(w(), z(), z(), x()); }
constexpr vec<T, 3>  wxx() { return vec<T, 3>(w(), x(), x()); }
constexpr vec<T, 4> xwxw() { return vec<T, 4>(x(), w(), x(), w()); }
constexpr vec<T, 3>  zzz() { return vec<T, 3>(z(), z(), z()); }
constexpr vec<T, 4> zyyx() { return vec<T, 4>(z(), y(), y(), x()); }
constexpr vec<T, 4> wyyx() { return vec<T, 4>(w(), y(), y(), x()); }
constexpr vec<T, 4> raaa() { return vec<T, 4>(r(), a(), a(), a()); }
constexpr vec<T, 3>  yyz() { return vec<T, 3>(y(), y(), z()); }
constexpr vec<T, 3>  xxw() { return vec<T, 3>(x(), x(), w()); }
constexpr vec<T, 4> abaa() { return vec<T, 4>(a(), b(), a(), a()); }
constexpr vec<T, 4> zxyx() { return vec<T, 4>(z(), x(), y(), x()); }
constexpr vec<T, 4> ggbg() { return vec<T, 4>(g(), g(), b(), g()); }
constexpr vec<T, 4> rgbg() { return vec<T, 4>(r(), g(), b(), g()); }
constexpr vec<T, 4> grrb() { return vec<T, 4>(g(), r(), r(), b()); }
constexpr vec<T, 4> bbrg() { return vec<T, 4>(b(), b(), r(), g()); }
constexpr vec<T, 4> zwzw() { return vec<T, 4>(z(), w(), z(), w()); }
constexpr vec<T, 4> wxyx() { return vec<T, 4>(w(), x(), y(), x()); }
constexpr vec<T, 4> wwzw() { return vec<T, 4>(w(), w(), z(), w()); }
constexpr vec<T, 4> rbbb() { return vec<T, 4>(r(), b(), b(), b()); }
constexpr vec<T, 4> bagg() { return vec<T, 4>(b(), a(), g(), g()); }
constexpr vec<T, 3>  ywy() { return vec<T, 3>(y(), w(), y()); }
constexpr vec<T, 4> agrg() { return vec<T, 4>(a(), g(), r(), g()); }
constexpr vec<T, 4> bbbr() { return vec<T, 4>(b(), b(), b(), r()); }
constexpr vec<T, 4> garg() { return vec<T, 4>(g(), a(), r(), g()); }
constexpr vec<T, 4> grra() { return vec<T, 4>(g(), r(), r(), a()); }
constexpr vec<T, 4> aabr() { return vec<T, 4>(a(), a(), b(), r()); }
constexpr vec<T, 4> ywxy() { return vec<T, 4>(y(), w(), x(), y()); }
constexpr vec<T, 4> arra() { return vec<T, 4>(a(), r(), r(), a()); }
constexpr vec<T, 4> zwyz() { return vec<T, 4>(z(), w(), y(), z()); }
constexpr vec<T, 4> rbba() { return vec<T, 4>(r(), b(), b(), a()); }
constexpr vec<T, 4> baag() { return vec<T, 4>(b(), a(), a(), g()); }
constexpr vec<T, 3>  rgg() { return vec<T, 3>(r(), g(), g()); }
constexpr vec<T, 4> wwyz() { return vec<T, 4>(w(), w(), y(), z()); }
constexpr vec<T, 4> xzxy() { return vec<T, 4>(x(), z(), x(), y()); }
constexpr vec<T, 4> abar() { return vec<T, 4>(a(), b(), a(), r()); }
constexpr vec<T, 4> yywz() { return vec<T, 4>(y(), y(), w(), z()); }
constexpr vec<T, 3>  rbg() { return vec<T, 3>(r(), b(), g()); }
constexpr vec<T, 3>  gbb() { return vec<T, 3>(g(), b(), b()); }
constexpr vec<T, 2>   wy() { return vec<T, 2>(w(), y()); }
constexpr vec<T, 3>  gga() { return vec<T, 3>(g(), g(), a()); }
constexpr vec<T, 4> wwwy() { return vec<T, 4>(w(), w(), w(), y()); }
constexpr vec<T, 3>  zyw() { return vec<T, 3>(z(), y(), w()); }
constexpr vec<T, 4> brra() { return vec<T, 4>(b(), r(), r(), a()); }
constexpr vec<T, 4> zyzw() { return vec<T, 4>(z(), y(), z(), w()); }
constexpr vec<T, 3>  brg() { return vec<T, 3>(b(), r(), g()); }
constexpr vec<T, 4> xyzw() { return vec<T, 4>(x(), y(), z(), w()); }
constexpr vec<T, 2>   xw() { return vec<T, 2>(x(), w()); }
constexpr vec<T, 3>  zyx() { return vec<T, 3>(z(), y(), x()); }
constexpr vec<T, 3>  gba() { return vec<T, 3>(g(), b(), a()); }
constexpr vec<T, 4> grrr() { return vec<T, 4>(g(), r(), r(), r()); }
constexpr vec<T, 4> rrrr() { return vec<T, 4>(r(), r(), r(), r()); }
constexpr vec<T, 4> arag() { return vec<T, 4>(a(), r(), a(), g()); }
constexpr vec<T, 4> yzyw() { return vec<T, 4>(y(), z(), y(), w()); }
constexpr vec<T, 4> ggar() { return vec<T, 4>(g(), g(), a(), r()); }
constexpr vec<T, 4> zywx() { return vec<T, 4>(z(), y(), w(), x()); }
constexpr vec<T, 4> wyyy() { return vec<T, 4>(w(), y(), y(), y()); }
constexpr vec<T, 4> yzyx() { return vec<T, 4>(y(), z(), y(), x()); }
constexpr vec<T, 4> xywx() { return vec<T, 4>(x(), y(), w(), x()); }
constexpr vec<T, 4> yxzz() { return vec<T, 4>(y(), x(), z(), z()); }
constexpr vec<T, 4> wywx() { return vec<T, 4>(w(), y(), w(), x()); }
constexpr vec<T, 4> zxyy() { return vec<T, 4>(z(), x(), y(), y()); }
constexpr vec<T, 3>  ywz() { return vec<T, 3>(y(), w(), z()); }
constexpr vec<T, 4> zxwx() { return vec<T, 4>(z(), x(), w(), x()); }
constexpr vec<T, 4> wxyy() { return vec<T, 4>(w(), x(), y(), y()); }
constexpr vec<T, 4> wxwx() { return vec<T, 4>(w(), x(), w(), x()); }
constexpr vec<T, 4> zwzy() { return vec<T, 4>(z(), w(), z(), y()); }
constexpr vec<T, 4> ywxz() { return vec<T, 4>(y(), w(), x(), z()); }
constexpr vec<T, 4> brag() { return vec<T, 4>(b(), r(), a(), g()); }
constexpr vec<T, 4> xxzz() { return vec<T, 4>(x(), x(), z(), z()); }
constexpr vec<T, 3>  grg() { return vec<T, 3>(g(), r(), g()); }
constexpr vec<T, 4> wwzy() { return vec<T, 4>(w(), w(), z(), y()); }
constexpr vec<T, 4> rrbg() { return vec<T, 4>(r(), r(), b(), g()); }
constexpr vec<T, 4> yzww() { return vec<T, 4>(y(), z(), w(), w()); }
constexpr vec<T, 4> xzxz() { return vec<T, 4>(x(), z(), x(), z()); }
constexpr vec<T, 4> xwyx() { return vec<T, 4>(x(), w(), y(), x()); }
constexpr vec<T, 3>  gbr() { return vec<T, 3>(g(), b(), r()); }
constexpr vec<T, 4> yyxw() { return vec<T, 4>(y(), y(), x(), w()); }
constexpr vec<T, 4> wyzw() { return vec<T, 4>(w(), y(), z(), w()); }
constexpr vec<T, 2>   gg() { return vec<T, 2>(g(), g()); }
constexpr vec<T, 4> zwwz() { return vec<T, 4>(z(), w(), w(), z()); }
constexpr vec<T, 4> bagb() { return vec<T, 4>(b(), a(), g(), b()); }
constexpr vec<T, 4> agrb() { return vec<T, 4>(a(), g(), r(), b()); }
constexpr vec<T, 4> zxzw() { return vec<T, 4>(z(), x(), z(), w()); }
constexpr vec<T, 4> garb() { return vec<T, 4>(g(), a(), r(), b()); }
constexpr vec<T, 4> rgba() { return vec<T, 4>(r(), g(), b(), a()); }
constexpr vec<T, 4> zwxx() { return vec<T, 4>(z(), w(), x(), x()); }
constexpr vec<T, 4> wwwz() { return vec<T, 4>(w(), w(), w(), z()); }
constexpr vec<T, 4> wxzw() { return vec<T, 4>(w(), x(), z(), w()); }
constexpr vec<T, 4> wwxx() { return vec<T, 4>(w(), w(), x(), x()); }
constexpr vec<T, 4> bgrb() { return vec<T, 4>(b(), g(), r(), b()); }
constexpr vec<T, 4> babb() { return vec<T, 4>(b(), a(), b(), b()); }
constexpr vec<T, 4> wzzz() { return vec<T, 4>(w(), z(), z(), z()); }
constexpr vec<T, 3>  wxz() { return vec<T, 3>(w(), x(), z()); }
constexpr vec<T, 2>   ag() { return vec<T, 2>(a(), g()); }
constexpr vec<T, 4> zyyz() { return vec<T, 4>(z(), y(), y(), z()); }
constexpr vec<T, 4> baga() { return vec<T, 4>(b(), a(), g(), a()); }
constexpr vec<T, 4> agra() { return vec<T, 4>(a(), g(), r(), a()); }
constexpr vec<T, 4> ywzx() { return vec<T, 4>(y(), w(), z(), x()); }
constexpr vec<T, 4> gara() { return vec<T, 4>(g(), a(), r(), a()); }
constexpr vec<T, 4> xyyz() { return vec<T, 4>(x(), y(), y(), z()); }
constexpr vec<T, 4> wyyz() { return vec<T, 4>(w(), y(), y(), z()); }
constexpr vec<T, 3>  zww() { return vec<T, 3>(z(), w(), w()); }
constexpr vec<T, 4> xwwx() { return vec<T, 4>(x(), w(), w(), x()); }
constexpr vec<T, 3>  zyy() { return vec<T, 3>(z(), y(), y()); }
constexpr vec<T, 4> bgra() { return vec<T, 4>(b(), g(), r(), a()); }
constexpr vec<T, 4> zxyz() { return vec<T, 4>(z(), x(), y(), z()); }
constexpr vec<T, 3>  rbb() { return vec<T, 3>(r(), b(), b()); }
constexpr vec<T, 3>  abg() { return vec<T, 3>(a(), b(), g()); }
constexpr vec<T, 4> xyzy() { return vec<T, 4>(x(), y(), z(), y()); }
constexpr vec<T, 4> xzzx() { return vec<T, 4>(x(), z(), z(), x()); }
constexpr vec<T, 4> wxyz() { return vec<T, 4>(w(), x(), y(), z()); }
constexpr vec<T, 4> zywy() { return vec<T, 4>(z(), y(), w(), y()); }
constexpr vec<T, 3>  xwx() { return vec<T, 3>(x(), w(), x()); }
constexpr vec<T, 3>  yxx() { return vec<T, 3>(y(), x(), x()); }
constexpr vec<T, 4> yzyy() { return vec<T, 4>(y(), z(), y(), y()); }
constexpr vec<T, 4> wywy() { return vec<T, 4>(w(), y(), w(), y()); }
constexpr vec<T, 4> bbag() { return vec<T, 4>(b(), b(), a(), g()); }
constexpr vec<T, 3>  brb() { return vec<T, 3>(b(), r(), b()); }
constexpr vec<T, 3>  rba() { return vec<T, 3>(r(), b(), a()); }
constexpr vec<T, 3>  bag() { return vec<T, 3>(b(), a(), g()); }
constexpr vec<T, 4> zxwy() { return vec<T, 4>(z(), x(), w(), y()); }
constexpr vec<T, 4> arab() { return vec<T, 4>(a(), r(), a(), b()); }
constexpr vec<T, 4> wxwy() { return vec<T, 4>(w(), x(), w(), y()); }
constexpr vec<T, 4> rarb() { return vec<T, 4>(r(), a(), r(), b()); }
constexpr vec<T, 3>  wzx() { return vec<T, 3>(w(), z(), x()); }
constexpr vec<T, 4> xwzw() { return vec<T, 4>(x(), w(), z(), w()); }
constexpr vec<T, 4> barg() { return vec<T, 4>(b(), a(), r(), g()); }
constexpr vec<T, 4> xyxx() { return vec<T, 4>(x(), y(), x(), x()); }
constexpr vec<T, 3>  bra() { return vec<T, 3>(b(), r(), a()); }
constexpr vec<T, 4> bagr() { return vec<T, 4>(b(), a(), g(), r()); }
constexpr vec<T, 4> agrr() { return vec<T, 4>(a(), g(), r(), r()); }
constexpr vec<T, 2>   yx() { return vec<T, 2>(y(), x()); }
constexpr vec<T, 4> aaag() { return vec<T, 4>(a(), a(), a(), g()); }
constexpr vec<T, 4> araa() { return vec<T, 4>(a(), r(), a(), a()); }
constexpr vec<T, 3>  xzw() { return vec<T, 3>(x(), z(), w()); }
constexpr vec<T, 4> rara() { return vec<T, 4>(r(), a(), r(), a()); }
constexpr vec<T, 4> bgrr() { return vec<T, 4>(b(), g(), r(), r()); }
constexpr vec<T, 4> babr() { return vec<T, 4>(b(), a(), b(), r()); }
constexpr vec<T, 4> zzyw() { return vec<T, 4>(z(), z(), y(), w()); }
constexpr vec<T, 4> brab() { return vec<T, 4>(b(), r(), a(), b()); }
constexpr vec<T, 3>  rrg() { return vec<T, 3>(r(), r(), g()); }
constexpr vec<T, 4> yyxy() { return vec<T, 4>(y(), y(), x(), y()); }
constexpr vec<T, 4> wzyw() { return vec<T, 4>(w(), z(), y(), w()); }
constexpr vec<T, 4> aagb() { return vec<T, 4>(a(), a(), g(), b()); }
constexpr vec<T, 4> zzyx() { return vec<T, 4>(z(), z(), y(), x()); }
constexpr vec<T, 4> gbgg() { return vec<T, 4>(g(), b(), g(), g()); }
constexpr vec<T, 4> rbgg() { return vec<T, 4>(r(), b(), g(), g()); }
constexpr vec<T, 4> yxyx() { return vec<T, 4>(y(), x(), y(), x()); }
constexpr vec<T, 4> wzyx() { return vec<T, 4>(w(), z(), y(), x()); }
constexpr vec<T, 3>  zyz() { return vec<T, 3>(z(), y(), z()); }
constexpr vec<T, 4> gaab() { return vec<T, 4>(g(), a(), a(), b()); }
constexpr vec<T, 3>  rbr() { return vec<T, 3>(r(), b(), r()); }
constexpr vec<T, 4> braa() { return vec<T, 4>(b(), r(), a(), a()); }
constexpr vec<T, 4> argr() { return vec<T, 4>(a(), r(), g(), r()); }
constexpr vec<T, 2>   gb() { return vec<T, 2>(g(), b()); }
constexpr vec<T, 4> ywzy() { return vec<T, 4>(y(), w(), z(), y()); }
constexpr vec<T, 4> aaga() { return vec<T, 4>(a(), a(), g(), a()); }
constexpr vec<T, 4> zywz() { return vec<T, 4>(z(), y(), w(), z()); }
constexpr vec<T, 4> xwwy() { return vec<T, 4>(x(), w(), w(), y()); }
constexpr vec<T, 4> rbag() { return vec<T, 4>(r(), b(), a(), g()); }
constexpr vec<T, 4> abbg() { return vec<T, 4>(a(), b(), b(), g()); }
constexpr vec<T, 4> xxyx() { return vec<T, 4>(x(), x(), y(), x()); }
constexpr vec<T, 4> xywz() { return vec<T, 4>(x(), y(), w(), z()); }
constexpr vec<T, 3>  brr() { return vec<T, 3>(b(), r(), r()); }
constexpr vec<T, 4> wywz() { return vec<T, 4>(w(), y(), w(), z()); }
constexpr vec<T, 2>   bb() { return vec<T, 2>(b(), b()); }
constexpr vec<T, 4> gaaa() { return vec<T, 4>(g(), a(), a(), a()); }
constexpr vec<T, 3>  zwy() { return vec<T, 3>(z(), w(), y()); }
constexpr vec<T, 4> zxwz() { return vec<T, 4>(z(), x(), w(), z()); }
constexpr vec<T, 4> arar() { return vec<T, 4>(a(), r(), a(), r()); }
constexpr vec<T, 4> bgab() { return vec<T, 4>(b(), g(), a(), b()); }
constexpr vec<T, 4> zyxw() { return vec<T, 4>(z(), y(), x(), w()); }
constexpr vec<T, 2>   ga() { return vec<T, 2>(g(), a()); }
constexpr vec<T, 3>  xwy() { return vec<T, 3>(x(), w(), y()); }
constexpr vec<T, 3>  yxy() { return vec<T, 3>(y(), x(), y()); }
constexpr vec<T, 4> wxwz() { return vec<T, 4>(w(), x(), w(), z()); }
constexpr vec<T, 4> rarr() { return vec<T, 4>(r(), a(), r(), r()); }
constexpr vec<T, 4> gggg() { return vec<T, 4>(g(), g(), g(), g()); }
constexpr vec<T, 4> rggg() { return vec<T, 4>(r(), g(), g(), g()); }
constexpr vec<T, 4> zyxx() { return vec<T, 4>(z(), y(), x(), x()); }
constexpr vec<T, 4> yyzx() { return vec<T, 4>(y(), y(), z(), x()); }
constexpr vec<T, 4> wxxx() { return vec<T, 4>(w(), x(), x(), x()); }
constexpr vec<T, 4> bbgb() { return vec<T, 4>(b(), b(), g(), b()); }
constexpr vec<T, 4> zxxw() { return vec<T, 4>(z(), x(), x(), w()); }
constexpr vec<T, 3>  abb() { return vec<T, 3>(a(), b(), b()); }
constexpr vec<T, 4> xxww() { return vec<T, 4>(x(), x(), w(), w()); }
constexpr vec<T, 3>  gag() { return vec<T, 3>(g(), a(), g()); }
constexpr vec<T, 4> xwyz() { return vec<T, 4>(x(), w(), y(), z()); }
constexpr vec<T, 4> yzxw() { return vec<T, 4>(y(), z(), x(), w()); }
constexpr vec<T, 4> xyxy() { return vec<T, 4>(x(), y(), x(), y()); }
constexpr vec<T, 4> brar() { return vec<T, 4>(b(), r(), a(), r()); }
constexpr vec<T, 4> bbga() { return vec<T, 4>(b(), b(), g(), a()); }
constexpr vec<T, 4> bbab() { return vec<T, 4>(b(), b(), a(), b()); }
constexpr vec<T, 4> aagr() { return vec<T, 4>(a(), a(), g(), r()); }
constexpr vec<T, 3>  bab() { return vec<T, 3>(b(), a(), b()); }
constexpr vec<T, 3>  aba() { return vec<T, 3>(a(), b(), a()); }
constexpr vec<T, 4> zwxz() { return vec<T, 4>(z(), w(), x(), z()); }
constexpr vec<T, 2>   wx() { return vec<T, 2>(w(), x()); }
constexpr vec<T, 4> wwxz() { return vec<T, 4>(w(), w(), x(), z()); }
constexpr vec<T, 4> gaar() { return vec<T, 4>(g(), a(), a(), r()); }
constexpr vec<T, 4> agab() { return vec<T, 4>(a(), g(), a(), b()); }
constexpr vec<T, 2>   rg() { return vec<T, 2>(r(), g()); }
constexpr vec<T, 4> barb() { return vec<T, 4>(b(), a(), r(), b()); }
constexpr vec<T, 4> zzww() { return vec<T, 4>(z(), z(), w(), w()); }
constexpr vec<T, 3>  yzx() { return vec<T, 3>(y(), z(), x()); }
constexpr vec<T, 4> raab() { return vec<T, 4>(r(), a(), a(), b()); }
constexpr vec<T, 4> bbaa() { return vec<T, 4>(b(), b(), a(), a()); }
constexpr vec<T, 2>   gr() { return vec<T, 2>(g(), r()); }
constexpr vec<T, 4> zzyy() { return vec<T, 4>(z(), z(), y(), y()); }
constexpr vec<T, 4> ywzz() { return vec<T, 4>(y(), w(), z(), z()); }
constexpr vec<T, 4> wzww() { return vec<T, 4>(w(), z(), w(), w()); }
constexpr vec<T, 3>  baa() { return vec<T, 3>(b(), a(), a()); }
constexpr vec<T, 4> zzwx() { return vec<T, 4>(z(), z(), w(), x()); }
constexpr vec<T, 4> yxyy() { return vec<T, 4>(y(), x(), y(), y()); }
constexpr vec<T, 4> wzyy() { return vec<T, 4>(w(), z(), y(), y()); }
constexpr vec<T, 4> xwwz() { return vec<T, 4>(x(), w(), w(), z()); }
