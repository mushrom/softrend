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

constexpr vec<T, 2>   br() const { return vec<T, 2>(b(), r()); }
constexpr vec<T, 4> wyxw() const { return vec<T, 4>(w(), y(), x(), w()); }
constexpr vec<T, 3>  zxw() const { return vec<T, 3>(z(), x(), w()); }
constexpr vec<T, 4> xwxx() const { return vec<T, 4>(x(), w(), x(), x()); }
constexpr vec<T, 4> agaa() const { return vec<T, 4>(a(), g(), a(), a()); }
constexpr vec<T, 4> xzzz() const { return vec<T, 4>(x(), z(), z(), z()); }
constexpr vec<T, 4> bara() const { return vec<T, 4>(b(), a(), r(), a()); }
constexpr vec<T, 4> bgar() const { return vec<T, 4>(b(), g(), a(), r()); }
constexpr vec<T, 4> wyxx() const { return vec<T, 4>(w(), y(), x(), x()); }
constexpr vec<T, 4> yxww() const { return vec<T, 4>(y(), x(), w(), w()); }
constexpr vec<T, 3>  zxx() const { return vec<T, 3>(z(), x(), x()); }
constexpr vec<T, 3>  xwz() const { return vec<T, 3>(x(), w(), z()); }
constexpr vec<T, 3>  yxz() const { return vec<T, 3>(y(), x(), z()); }
constexpr vec<T, 4> gbgb() const { return vec<T, 4>(g(), b(), g(), b()); }
constexpr vec<T, 4> xxyy() const { return vec<T, 4>(x(), x(), y(), y()); }
constexpr vec<T, 2>   zw() const { return vec<T, 2>(z(), w()); }
constexpr vec<T, 4> rbgb() const { return vec<T, 4>(r(), b(), g(), b()); }
constexpr vec<T, 3>  xxx() const { return vec<T, 3>(x(), x(), x()); }
constexpr vec<T, 4> bbgr() const { return vec<T, 4>(b(), b(), g(), r()); }
constexpr vec<T, 4> rgag() const { return vec<T, 4>(r(), g(), a(), g()); }
constexpr vec<T, 4> arrb() const { return vec<T, 4>(a(), r(), r(), b()); }
constexpr vec<T, 4> zwzx() const { return vec<T, 4>(z(), w(), z(), x()); }
constexpr vec<T, 3>  bgr() const { return vec<T, 3>(b(), g(), r()); }
constexpr vec<T, 3>  abr() const { return vec<T, 3>(a(), b(), r()); }
constexpr vec<T, 4> gbbb() const { return vec<T, 4>(g(), b(), b(), b()); }
constexpr vec<T, 4> wwzx() const { return vec<T, 4>(w(), w(), z(), x()); }
constexpr vec<T, 3>  wzz() const { return vec<T, 3>(w(), z(), z()); }
constexpr vec<T, 4> gbga() const { return vec<T, 4>(g(), b(), g(), a()); }
constexpr vec<T, 4> zyxy() const { return vec<T, 4>(z(), y(), x(), y()); }
constexpr vec<T, 4> yyzy() const { return vec<T, 4>(y(), y(), z(), y()); }
constexpr vec<T, 4> wxxy() const { return vec<T, 4>(w(), x(), x(), y()); }
constexpr vec<T, 4> rbga() const { return vec<T, 4>(r(), b(), g(), a()); }
constexpr vec<T, 4> xyxz() const { return vec<T, 4>(x(), y(), x(), z()); }
constexpr vec<T, 2>   yz() const { return vec<T, 2>(y(), z()); }
constexpr vec<T, 3>  bar() const { return vec<T, 3>(b(), a(), r()); }
constexpr vec<T, 4> gbba() const { return vec<T, 4>(g(), b(), b(), a()); }
constexpr vec<T, 4> zxxy() const { return vec<T, 4>(z(), x(), x(), y()); }
constexpr vec<T, 3>  ggb() const { return vec<T, 3>(g(), g(), b()); }
constexpr vec<T, 4> xxwy() const { return vec<T, 4>(x(), x(), w(), y()); }
constexpr vec<T, 4> brrb() const { return vec<T, 4>(b(), r(), r(), b()); }
constexpr vec<T, 4> grgg() const { return vec<T, 4>(g(), r(), g(), g()); }
constexpr vec<T, 4> agar() const { return vec<T, 4>(a(), g(), a(), r()); }
constexpr vec<T, 4> rrgg() const { return vec<T, 4>(r(), r(), g(), g()); }
constexpr vec<T, 4> rggb() const { return vec<T, 4>(r(), g(), g(), b()); }
constexpr vec<T, 4> rbaa() const { return vec<T, 4>(r(), b(), a(), a()); }
constexpr vec<T, 4> abba() const { return vec<T, 4>(a(), b(), b(), a()); }
constexpr vec<T, 4> yzxy() const { return vec<T, 4>(y(), z(), x(), y()); }
constexpr vec<T, 4> raar() const { return vec<T, 4>(r(), a(), a(), r()); }
constexpr vec<T, 4> zzyz() const { return vec<T, 4>(z(), z(), y(), z()); }
constexpr vec<T, 4> yxyz() const { return vec<T, 4>(y(), x(), y(), z()); }
constexpr vec<T, 3>  rag() const { return vec<T, 3>(r(), a(), g()); }
constexpr vec<T, 3>  gab() const { return vec<T, 3>(g(), a(), b()); }
constexpr vec<T, 4> ggga() const { return vec<T, 4>(g(), g(), g(), a()); }
constexpr vec<T, 3>  yzy() const { return vec<T, 3>(y(), z(), y()); }
constexpr vec<T, 4> rgga() const { return vec<T, 4>(r(), g(), g(), a()); }
constexpr vec<T, 4> gbrg() const { return vec<T, 4>(g(), b(), r(), g()); }
constexpr vec<T, 4> zyzx() const { return vec<T, 4>(z(), y(), z(), x()); }
constexpr vec<T, 4> rbrg() const { return vec<T, 4>(r(), b(), r(), g()); }
constexpr vec<T, 4> zzwy() const { return vec<T, 4>(z(), z(), w(), y()); }
constexpr vec<T, 4> gbgr() const { return vec<T, 4>(g(), b(), g(), r()); }
constexpr vec<T, 4> rbgr() const { return vec<T, 4>(r(), b(), g(), r()); }
constexpr vec<T, 4> brbg() const { return vec<T, 4>(b(), r(), b(), g()); }
constexpr vec<T, 4> xyzx() const { return vec<T, 4>(x(), y(), z(), x()); }
constexpr vec<T, 2>   xx() const { return vec<T, 2>(x(), x()); }
constexpr vec<T, 4> xxyz() const { return vec<T, 4>(x(), x(), y(), z()); }
constexpr vec<T, 4> wzwy() const { return vec<T, 4>(w(), z(), w(), y()); }
constexpr vec<T, 3>  gaa() const { return vec<T, 3>(g(), a(), a()); }
constexpr vec<T, 4> xwxy() const { return vec<T, 4>(x(), w(), x(), y()); }
constexpr vec<T, 4> arrr() const { return vec<T, 4>(a(), r(), r(), r()); }
constexpr vec<T, 2>   rb() const { return vec<T, 2>(r(), b()); }
constexpr vec<T, 4> gbbr() const { return vec<T, 4>(g(), b(), b(), r()); }
constexpr vec<T, 4> zzxw() const { return vec<T, 4>(z(), z(), x(), w()); }
constexpr vec<T, 4> wyxy() const { return vec<T, 4>(w(), y(), x(), y()); }
constexpr vec<T, 4> rbbr() const { return vec<T, 4>(r(), b(), b(), r()); }
constexpr vec<T, 3>  zxy() const { return vec<T, 3>(z(), x(), y()); }
constexpr vec<T, 4> aarg() const { return vec<T, 4>(a(), a(), r(), g()); }
constexpr vec<T, 3>  agg() const { return vec<T, 3>(a(), g(), g()); }
constexpr vec<T, 3>  xxy() const { return vec<T, 3>(x(), x(), y()); }
constexpr vec<T, 4> yxwy() const { return vec<T, 4>(y(), x(), w(), y()); }
constexpr vec<T, 4> yyzz() const { return vec<T, 4>(y(), y(), z(), z()); }
constexpr vec<T, 4> wxxz() const { return vec<T, 4>(w(), x(), x(), z()); }
constexpr vec<T, 3>  wyw() const { return vec<T, 3>(w(), y(), w()); }
constexpr vec<T, 2>   zy() const { return vec<T, 2>(z(), y()); }
constexpr vec<T, 2>   ra() const { return vec<T, 2>(r(), a()); }
constexpr vec<T, 3>  ggr() const { return vec<T, 3>(g(), g(), r()); }
constexpr vec<T, 4> xxxw() const { return vec<T, 4>(x(), x(), x(), w()); }
constexpr vec<T, 4> grbg() const { return vec<T, 4>(g(), r(), b(), g()); }
constexpr vec<T, 4> brrr() const { return vec<T, 4>(b(), r(), r(), r()); }
constexpr vec<T, 4> rgbb() const { return vec<T, 4>(r(), g(), b(), b()); }
constexpr vec<T, 4> bbrb() const { return vec<T, 4>(b(), b(), r(), b()); }
constexpr vec<T, 4> ggbb() const { return vec<T, 4>(g(), g(), b(), b()); }
constexpr vec<T, 4> ywyw() const { return vec<T, 4>(y(), w(), y(), w()); }
constexpr vec<T, 4> xxxx() const { return vec<T, 4>(x(), x(), x(), x()); }
constexpr vec<T, 4> arbg() const { return vec<T, 4>(a(), r(), b(), g()); }
constexpr vec<T, 4> yzwx() const { return vec<T, 4>(y(), z(), w(), x()); }
constexpr vec<T, 2>   wz() const { return vec<T, 2>(w(), z()); }
constexpr vec<T, 4> xzyw() const { return vec<T, 4>(x(), z(), y(), w()); }
constexpr vec<T, 4> yyxx() const { return vec<T, 4>(y(), y(), x(), x()); }
constexpr vec<T, 3>  gar() const { return vec<T, 3>(g(), a(), r()); }
constexpr vec<T, 4> ggba() const { return vec<T, 4>(g(), g(), b(), a()); }
constexpr vec<T, 4> wyzx() const { return vec<T, 4>(w(), y(), z(), x()); }
constexpr vec<T, 4> bbra() const { return vec<T, 4>(b(), b(), r(), a()); }
constexpr vec<T, 4> xzyx() const { return vec<T, 4>(x(), z(), y(), x()); }
constexpr vec<T, 3>  yzz() const { return vec<T, 3>(y(), z(), z()); }
constexpr vec<T, 4> zxzx() const { return vec<T, 4>(z(), x(), z(), x()); }
constexpr vec<T, 4> wxzx() const { return vec<T, 4>(w(), x(), z(), x()); }
constexpr vec<T, 4> baab() const { return vec<T, 4>(b(), a(), a(), b()); }
constexpr vec<T, 4> wzxw() const { return vec<T, 4>(w(), z(), x(), w()); }
constexpr vec<T, 3>  rgb() const { return vec<T, 3>(r(), g(), b()); }
constexpr vec<T, 4> ywww() const { return vec<T, 4>(y(), w(), w(), w()); }
constexpr vec<T, 4> aggg() const { return vec<T, 4>(a(), g(), g(), g()); }
constexpr vec<T, 4> xwxz() const { return vec<T, 4>(x(), w(), x(), z()); }
constexpr vec<T, 2>   rr() const { return vec<T, 2>(r(), r()); }
constexpr vec<T, 4> ragg() const { return vec<T, 4>(r(), a(), g(), g()); }
constexpr vec<T, 4> wyxz() const { return vec<T, 4>(w(), y(), x(), z()); }
constexpr vec<T, 4> zyzy() const { return vec<T, 4>(z(), y(), z(), y()); }
constexpr vec<T, 4> yzzw() const { return vec<T, 4>(y(), z(), z(), w()); }
constexpr vec<T, 3>  zwx() const { return vec<T, 3>(z(), w(), x()); }
constexpr vec<T, 4> agbg() const { return vec<T, 4>(a(), g(), b(), g()); }
constexpr vec<T, 2>   xy() const { return vec<T, 2>(x(), y()); }
constexpr vec<T, 4> xzww() const { return vec<T, 4>(x(), z(), w(), w()); }
constexpr vec<T, 4> gabg() const { return vec<T, 4>(g(), a(), b(), g()); }
constexpr vec<T, 4> yxxw() const { return vec<T, 4>(y(), x(), x(), w()); }
constexpr vec<T, 4> ggrg() const { return vec<T, 4>(g(), g(), r(), g()); }
constexpr vec<T, 3>  xxz() const { return vec<T, 3>(x(), x(), z()); }
constexpr vec<T, 4> rgrg() const { return vec<T, 4>(r(), g(), r(), g()); }
constexpr vec<T, 4> rabg() const { return vec<T, 4>(r(), a(), b(), g()); }
constexpr vec<T, 4> baaa() const { return vec<T, 4>(b(), a(), a(), a()); }
constexpr vec<T, 3>  rga() const { return vec<T, 3>(r(), g(), a()); }
constexpr vec<T, 3>  rab() const { return vec<T, 3>(r(), a(), b()); }
constexpr vec<T, 3>  aag() const { return vec<T, 3>(a(), a(), g()); }
constexpr vec<T, 4> yyyw() const { return vec<T, 4>(y(), y(), y(), w()); }
constexpr vec<T, 4> zwzz() const { return vec<T, 4>(z(), w(), z(), z()); }
constexpr vec<T, 4> rrga() const { return vec<T, 4>(r(), r(), g(), a()); }
constexpr vec<T, 4> wwzz() const { return vec<T, 4>(w(), w(), z(), z()); }
constexpr vec<T, 4> gbrb() const { return vec<T, 4>(g(), b(), r(), b()); }
constexpr vec<T, 4> bggg() const { return vec<T, 4>(b(), g(), g(), g()); }
constexpr vec<T, 4> rbrb() const { return vec<T, 4>(r(), b(), r(), b()); }
constexpr vec<T, 4> ggbr() const { return vec<T, 4>(g(), g(), b(), r()); }
constexpr vec<T, 4> zzxy() const { return vec<T, 4>(z(), z(), x(), y()); }
constexpr vec<T, 4> rgbr() const { return vec<T, 4>(r(), g(), b(), r()); }
constexpr vec<T, 4> bbrr() const { return vec<T, 4>(b(), b(), r(), r()); }
constexpr vec<T, 3>  raa() const { return vec<T, 3>(r(), a(), a()); }
constexpr vec<T, 4> bgbg() const { return vec<T, 4>(b(), g(), b(), g()); }
constexpr vec<T, 3>  www() const { return vec<T, 3>(w(), w(), w()); }
constexpr vec<T, 3>  wyy() const { return vec<T, 3>(w(), y(), y()); }
constexpr vec<T, 4> aarb() const { return vec<T, 4>(a(), a(), r(), b()); }
constexpr vec<T, 4> gbra() const { return vec<T, 4>(g(), b(), r(), a()); }
constexpr vec<T, 3>  zzw() const { return vec<T, 3>(z(), z(), w()); }
constexpr vec<T, 4> xwzx() const { return vec<T, 4>(x(), w(), z(), x()); }
constexpr vec<T, 4> rbra() const { return vec<T, 4>(r(), b(), r(), a()); }
constexpr vec<T, 4> garr() const { return vec<T, 4>(g(), a(), r(), r()); }
constexpr vec<T, 3>  agb() const { return vec<T, 3>(a(), g(), b()); }
constexpr vec<T, 4> brba() const { return vec<T, 4>(b(), r(), b(), a()); }
constexpr vec<T, 4> xxxy() const { return vec<T, 4>(x(), x(), x(), y()); }
constexpr vec<T, 3>  zzx() const { return vec<T, 3>(z(), z(), x()); }
constexpr vec<T, 3>  bbg() const { return vec<T, 3>(b(), b(), g()); }
constexpr vec<T, 4> ywyy() const { return vec<T, 4>(y(), w(), y(), y()); }
constexpr vec<T, 4> yzwy() const { return vec<T, 4>(y(), z(), w(), y()); }
constexpr vec<T, 3>  yyw() const { return vec<T, 3>(y(), y(), w()); }
constexpr vec<T, 3>  xzx() const { return vec<T, 3>(x(), z(), x()); }
constexpr vec<T, 3>  grb() const { return vec<T, 3>(g(), r(), b()); }
constexpr vec<T, 4> baar() const { return vec<T, 4>(b(), a(), a(), r()); }
constexpr vec<T, 4> aara() const { return vec<T, 4>(a(), a(), r(), a()); }
constexpr vec<T, 3>  rgr() const { return vec<T, 3>(r(), g(), r()); }
constexpr vec<T, 4> grbb() const { return vec<T, 4>(g(), r(), b(), b()); }
constexpr vec<T, 4> wyzy() const { return vec<T, 4>(w(), y(), z(), y()); }
constexpr vec<T, 4> rrbb() const { return vec<T, 4>(r(), r(), b(), b()); }
constexpr vec<T, 4> xzyy() const { return vec<T, 4>(x(), z(), y(), y()); }
constexpr vec<T, 3>  aga() const { return vec<T, 3>(a(), g(), a()); }
constexpr vec<T, 4> zxzy() const { return vec<T, 4>(z(), x(), z(), y()); }
constexpr vec<T, 4> zyzz() const { return vec<T, 4>(z(), y(), z(), z()); }
constexpr vec<T, 4> abgg() const { return vec<T, 4>(a(), b(), g(), g()); }
constexpr vec<T, 4> wxzy() const { return vec<T, 4>(w(), x(), z(), y()); }
constexpr vec<T, 4> xyzz() const { return vec<T, 4>(x(), y(), z(), z()); }
constexpr vec<T, 2>   xz() const { return vec<T, 2>(x(), z()); }
constexpr vec<T, 3>  gra() const { return vec<T, 3>(g(), r(), a()); }
constexpr vec<T, 4> grba() const { return vec<T, 4>(g(), r(), b(), a()); }
constexpr vec<T, 4> gbag() const { return vec<T, 4>(g(), b(), a(), g()); }
constexpr vec<T, 4> rrba() const { return vec<T, 4>(r(), r(), b(), a()); }
constexpr vec<T, 4> wzxy() const { return vec<T, 4>(w(), z(), x(), y()); }
constexpr vec<T, 4> yzyz() const { return vec<T, 4>(y(), z(), y(), z()); }
constexpr vec<T, 4> zwyw() const { return vec<T, 4>(z(), w(), y(), w()); }
constexpr vec<T, 4> rbrr() const { return vec<T, 4>(r(), b(), r(), r()); }
constexpr vec<T, 4> abag() const { return vec<T, 4>(a(), b(), a(), g()); }
constexpr vec<T, 4> wwyw() const { return vec<T, 4>(w(), w(), y(), w()); }
constexpr vec<T, 4> yzzy() const { return vec<T, 4>(y(), z(), z(), y()); }
constexpr vec<T, 2>   ab() const { return vec<T, 2>(a(), b()); }
constexpr vec<T, 4> yxxy() const { return vec<T, 4>(y(), x(), x(), y()); }
constexpr vec<T, 4> aarr() const { return vec<T, 4>(a(), a(), r(), r()); }
constexpr vec<T, 4> agbb() const { return vec<T, 4>(a(), g(), b(), b()); }
constexpr vec<T, 3>  agr() const { return vec<T, 3>(a(), g(), r()); }
constexpr vec<T, 4> grrg() const { return vec<T, 4>(g(), r(), r(), g()); }
constexpr vec<T, 4> gabb() const { return vec<T, 4>(g(), a(), b(), b()); }
constexpr vec<T, 2>   aa() const { return vec<T, 2>(a(), a()); }
constexpr vec<T, 4> zxxx() const { return vec<T, 4>(z(), x(), x(), x()); }
constexpr vec<T, 4> rrrg() const { return vec<T, 4>(r(), r(), r(), g()); }
constexpr vec<T, 4> rgrb() const { return vec<T, 4>(r(), g(), r(), b()); }
constexpr vec<T, 4> rabb() const { return vec<T, 4>(r(), a(), b(), b()); }
constexpr vec<T, 4> xxwx() const { return vec<T, 4>(x(), x(), w(), x()); }
constexpr vec<T, 4> yzwz() const { return vec<T, 4>(y(), z(), w(), z()); }
constexpr vec<T, 4> ggag() const { return vec<T, 4>(g(), g(), a(), g()); }
constexpr vec<T, 3>  grr() const { return vec<T, 3>(g(), r(), r()); }
constexpr vec<T, 3>  wwy() const { return vec<T, 3>(w(), w(), y()); }
constexpr vec<T, 4> yzxx() const { return vec<T, 4>(y(), z(), x(), x()); }
constexpr vec<T, 4> xwzy() const { return vec<T, 4>(x(), w(), z(), y()); }
constexpr vec<T, 4> yyxz() const { return vec<T, 4>(y(), y(), x(), z()); }
constexpr vec<T, 4> grbr() const { return vec<T, 4>(g(), r(), b(), r()); }
constexpr vec<T, 4> rrbr() const { return vec<T, 4>(r(), r(), b(), r()); }
constexpr vec<T, 4> wyzz() const { return vec<T, 4>(w(), y(), z(), z()); }
constexpr vec<T, 4> agba() const { return vec<T, 4>(a(), g(), b(), a()); }
constexpr vec<T, 4> gaba() const { return vec<T, 4>(g(), a(), b(), a()); }
constexpr vec<T, 4> ggra() const { return vec<T, 4>(g(), g(), r(), a()); }
constexpr vec<T, 3>  zzy() const { return vec<T, 3>(z(), z(), y()); }
constexpr vec<T, 4> raba() const { return vec<T, 4>(r(), a(), b(), a()); }
constexpr vec<T, 4> rgra() const { return vec<T, 4>(r(), g(), r(), a()); }
constexpr vec<T, 4> zxzz() const { return vec<T, 4>(z(), x(), z(), z()); }
constexpr vec<T, 4> yxzw() const { return vec<T, 4>(y(), x(), z(), w()); }
constexpr vec<T, 3>  aaa() const { return vec<T, 3>(a(), a(), a()); }
constexpr vec<T, 4> bgbb() const { return vec<T, 4>(b(), g(), b(), b()); }
constexpr vec<T, 3>  xzy() const { return vec<T, 3>(x(), z(), y()); }
constexpr vec<T, 3>  yww() const { return vec<T, 3>(y(), w(), w()); }
constexpr vec<T, 4> wxzz() const { return vec<T, 4>(w(), x(), z(), z()); }
constexpr vec<T, 3>  yyy() const { return vec<T, 3>(y(), y(), y()); }
constexpr vec<T, 4> yxzx() const { return vec<T, 4>(y(), x(), z(), x()); }
constexpr vec<T, 4> aaab() const { return vec<T, 4>(a(), a(), a(), b()); }
constexpr vec<T, 4> ywxw() const { return vec<T, 4>(y(), w(), x(), w()); }
constexpr vec<T, 4> wzwx() const { return vec<T, 4>(w(), z(), w(), x()); }
constexpr vec<T, 4> xxzw() const { return vec<T, 4>(x(), x(), z(), w()); }
constexpr vec<T, 3>  bbb() const { return vec<T, 3>(b(), b(), b()); }
constexpr vec<T, 4> bgba() const { return vec<T, 4>(b(), g(), b(), a()); }
constexpr vec<T, 3>  zwz() const { return vec<T, 3>(z(), w(), z()); }
constexpr vec<T, 3>  rrb() const { return vec<T, 3>(r(), r(), b()); }
constexpr vec<T, 2>   ar() const { return vec<T, 2>(a(), r()); }
constexpr vec<T, 3>  arg() const { return vec<T, 3>(a(), r(), g()); }
constexpr vec<T, 4> xxzx() const { return vec<T, 4>(x(), x(), z(), x()); }
constexpr vec<T, 4> xzxw() const { return vec<T, 4>(x(), z(), x(), w()); }
constexpr vec<T, 4> aaaa() const { return vec<T, 4>(a(), a(), a(), a()); }
constexpr vec<T, 4> yxwx() const { return vec<T, 4>(y(), x(), w(), x()); }
constexpr vec<T, 3>  bba() const { return vec<T, 3>(b(), b(), a()); }
constexpr vec<T, 2>   zx() const { return vec<T, 2>(z(), x()); }
constexpr vec<T, 4> zwww() const { return vec<T, 4>(z(), w(), w(), w()); }
constexpr vec<T, 4> abgb() const { return vec<T, 4>(a(), b(), g(), b()); }
constexpr vec<T, 4> agbr() const { return vec<T, 4>(a(), g(), b(), r()); }
constexpr vec<T, 4> zwyy() const { return vec<T, 4>(z(), w(), y(), y()); }
constexpr vec<T, 3>  rra() const { return vec<T, 3>(r(), r(), a()); }
constexpr vec<T, 4> rabr() const { return vec<T, 4>(r(), a(), b(), r()); }
constexpr vec<T, 4> wwww() const { return vec<T, 4>(w(), w(), w(), w()); }
constexpr vec<T, 4> rgrr() const { return vec<T, 4>(r(), g(), r(), r()); }
constexpr vec<T, 4> wwyy() const { return vec<T, 4>(w(), w(), y(), y()); }
constexpr vec<T, 4> zzzw() const { return vec<T, 4>(z(), z(), z(), w()); }
constexpr vec<T, 4> gbab() const { return vec<T, 4>(g(), b(), a(), b()); }
constexpr vec<T, 4> rbab() const { return vec<T, 4>(r(), b(), a(), b()); }
constexpr vec<T, 4> abbb() const { return vec<T, 4>(a(), b(), b(), b()); }
constexpr vec<T, 4> bbar() const { return vec<T, 4>(b(), b(), a(), r()); }
constexpr vec<T, 4> wzzw() const { return vec<T, 4>(w(), z(), z(), w()); }
constexpr vec<T, 3>  wxw() const { return vec<T, 3>(w(), x(), w()); }
constexpr vec<T, 4> zzzx() const { return vec<T, 4>(z(), z(), z(), x()); }
constexpr vec<T, 4> xwzz() const { return vec<T, 4>(x(), w(), z(), z()); }
constexpr vec<T, 4> abga() const { return vec<T, 4>(a(), b(), g(), a()); }
constexpr vec<T, 4> zyyw() const { return vec<T, 4>(z(), y(), y(), w()); }
constexpr vec<T, 4> xyyw() const { return vec<T, 4>(x(), y(), y(), w()); }
constexpr vec<T, 4> wyyw() const { return vec<T, 4>(w(), y(), y(), w()); }
constexpr vec<T, 4> gggb() const { return vec<T, 4>(g(), g(), g(), b()); }
constexpr vec<T, 4> bgbr() const { return vec<T, 4>(b(), g(), b(), r()); }
constexpr vec<T, 4> gbaa() const { return vec<T, 4>(g(), b(), a(), a()); }
constexpr vec<T, 4> barr() const { return vec<T, 4>(b(), a(), r(), r()); }
constexpr vec<T, 3>  xzz() const { return vec<T, 3>(x(), z(), z()); }
constexpr vec<T, 4> xyyx() const { return vec<T, 4>(x(), y(), y(), x()); }
constexpr vec<T, 4> zxyw() const { return vec<T, 4>(z(), x(), y(), w()); }
constexpr vec<T, 4> wxyw() const { return vec<T, 4>(w(), x(), y(), w()); }
constexpr vec<T, 4> aaar() const { return vec<T, 4>(a(), a(), a(), r()); }
constexpr vec<T, 4> wzyz() const { return vec<T, 4>(w(), z(), y(), z()); }
constexpr vec<T, 4> rrrb() const { return vec<T, 4>(r(), r(), r(), b()); }
constexpr vec<T, 3>  bbr() const { return vec<T, 3>(b(), b(), r()); }
constexpr vec<T, 4> brgg() const { return vec<T, 4>(b(), r(), g(), g()); }
constexpr vec<T, 4> ggab() const { return vec<T, 4>(g(), g(), a(), b()); }
constexpr vec<T, 4> yxzy() const { return vec<T, 4>(y(), x(), z(), y()); }
constexpr vec<T, 3>  rrr() const { return vec<T, 3>(r(), r(), r()); }
constexpr vec<T, 4> rrra() const { return vec<T, 4>(r(), r(), r(), a()); }
constexpr vec<T, 4> abrg() const { return vec<T, 4>(a(), b(), r(), g()); }
constexpr vec<T, 4> abgr() const { return vec<T, 4>(a(), b(), g(), r()); }
constexpr vec<T, 4> bgrg() const { return vec<T, 4>(b(), g(), r(), g()); }
constexpr vec<T, 4> ggaa() const { return vec<T, 4>(g(), g(), a(), a()); }
constexpr vec<T, 4> babg() const { return vec<T, 4>(b(), a(), b(), g()); }
constexpr vec<T, 4> xxzy() const { return vec<T, 4>(x(), x(), z(), y()); }
constexpr vec<T, 4> gbar() const { return vec<T, 4>(g(), b(), a(), r()); }
constexpr vec<T, 4> zzxx() const { return vec<T, 4>(z(), z(), x(), x()); }
constexpr vec<T, 4> rbar() const { return vec<T, 4>(r(), b(), a(), r()); }
constexpr vec<T, 4> abbr() const { return vec<T, 4>(a(), b(), b(), r()); }
constexpr vec<T, 4> zyxz() const { return vec<T, 4>(z(), y(), x(), z()); }
constexpr vec<T, 3>  xyw() const { return vec<T, 3>(x(), y(), w()); }
constexpr vec<T, 3>  wyx() const { return vec<T, 3>(w(), y(), x()); }
constexpr vec<T, 3>  arb() const { return vec<T, 3>(a(), r(), b()); }
constexpr vec<T, 4> zxxz() const { return vec<T, 4>(z(), x(), x(), z()); }
constexpr vec<T, 4> zwwy() const { return vec<T, 4>(z(), w(), w(), y()); }
constexpr vec<T, 4> argg() const { return vec<T, 4>(a(), r(), g(), g()); }
constexpr vec<T, 3>  xyx() const { return vec<T, 3>(x(), y(), x()); }
constexpr vec<T, 4> xxwz() const { return vec<T, 4>(x(), x(), w(), z()); }
constexpr vec<T, 4> gggr() const { return vec<T, 4>(g(), g(), g(), r()); }
constexpr vec<T, 4> rggr() const { return vec<T, 4>(r(), g(), g(), r()); }
constexpr vec<T, 4> zzzy() const { return vec<T, 4>(z(), z(), z(), y()); }
constexpr vec<T, 4> grag() const { return vec<T, 4>(g(), r(), a(), g()); }
constexpr vec<T, 4> yzxz() const { return vec<T, 4>(y(), z(), x(), z()); }
constexpr vec<T, 4> rrag() const { return vec<T, 4>(r(), r(), a(), g()); }
constexpr vec<T, 4> rgab() const { return vec<T, 4>(r(), g(), a(), b()); }
constexpr vec<T, 4> ywyx() const { return vec<T, 4>(y(), w(), y(), x()); }
constexpr vec<T, 4> wzzy() const { return vec<T, 4>(w(), z(), z(), y()); }
constexpr vec<T, 3>  wxy() const { return vec<T, 3>(w(), x(), y()); }
constexpr vec<T, 4> zyww() const { return vec<T, 4>(z(), y(), w(), w()); }
constexpr vec<T, 3>  ara() const { return vec<T, 3>(a(), r(), a()); }
constexpr vec<T, 4> zyyy() const { return vec<T, 4>(z(), y(), y(), y()); }
constexpr vec<T, 4> xyww() const { return vec<T, 4>(x(), y(), w(), w()); }
constexpr vec<T, 4> wyww() const { return vec<T, 4>(w(), y(), w(), w()); }
constexpr vec<T, 4> rarg() const { return vec<T, 4>(r(), a(), r(), g()); }
constexpr vec<T, 4> xyyy() const { return vec<T, 4>(x(), y(), y(), y()); }
constexpr vec<T, 4> zxww() const { return vec<T, 4>(z(), x(), w(), w()); }
constexpr vec<T, 4> rgaa() const { return vec<T, 4>(r(), g(), a(), a()); }
constexpr vec<T, 4> zzwz() const { return vec<T, 4>(z(), z(), w(), z()); }
constexpr vec<T, 4> wxww() const { return vec<T, 4>(w(), x(), w(), w()); }
constexpr vec<T, 4> wzwz() const { return vec<T, 4>(w(), z(), w(), z()); }
constexpr vec<T, 4> grgb() const { return vec<T, 4>(g(), r(), g(), b()); }
constexpr vec<T, 4> gagg() const { return vec<T, 4>(g(), a(), g(), g()); }
constexpr vec<T, 4> rrgb() const { return vec<T, 4>(r(), r(), g(), b()); }
constexpr vec<T, 4> wzxx() const { return vec<T, 4>(w(), z(), x(), x()); }
constexpr vec<T, 4> ywwx() const { return vec<T, 4>(y(), w(), w(), x()); }
constexpr vec<T, 3>  zxz() const { return vec<T, 3>(z(), x(), z()); }
constexpr vec<T, 4> aagg() const { return vec<T, 4>(a(), a(), g(), g()); }
constexpr vec<T, 4> xwyw() const { return vec<T, 4>(x(), w(), y(), w()); }
constexpr vec<T, 4> yxwz() const { return vec<T, 4>(y(), x(), w(), z()); }
constexpr vec<T, 4> yzzx() const { return vec<T, 4>(y(), z(), z(), x()); }
constexpr vec<T, 4> xzwx() const { return vec<T, 4>(x(), z(), w(), x()); }
constexpr vec<T, 2>   zz() const { return vec<T, 2>(z(), z()); }
constexpr vec<T, 4> grga() const { return vec<T, 4>(g(), r(), g(), a()); }
constexpr vec<T, 4> yxxx() const { return vec<T, 4>(y(), x(), x(), x()); }
constexpr vec<T, 4> brgb() const { return vec<T, 4>(b(), r(), g(), b()); }
constexpr vec<T, 4> gaag() const { return vec<T, 4>(g(), a(), a(), g()); }
constexpr vec<T, 3>  arr() const { return vec<T, 3>(a(), r(), r()); }
constexpr vec<T, 4> yyyx() const { return vec<T, 4>(y(), y(), y(), x()); }
constexpr vec<T, 4> zwxw() const { return vec<T, 4>(z(), w(), x(), w()); }
constexpr vec<T, 4> brbb() const { return vec<T, 4>(b(), r(), b(), b()); }
constexpr vec<T, 4> wwxw() const { return vec<T, 4>(w(), w(), x(), w()); }
constexpr vec<T, 4> abrb() const { return vec<T, 4>(a(), b(), r(), b()); }
constexpr vec<T, 4> zzzz() const { return vec<T, 4>(z(), z(), z(), z()); }
constexpr vec<T, 4> rgar() const { return vec<T, 4>(r(), g(), a(), r()); }
constexpr vec<T, 2>   bg() const { return vec<T, 2>(b(), g()); }
constexpr vec<T, 4> brga() const { return vec<T, 4>(b(), r(), g(), a()); }
constexpr vec<T, 4> ywzw() const { return vec<T, 4>(y(), w(), z(), w()); }
constexpr vec<T, 3>  wwx() const { return vec<T, 3>(w(), w(), x()); }
constexpr vec<T, 4> bgag() const { return vec<T, 4>(b(), g(), a(), g()); }
constexpr vec<T, 3>  xyy() const { return vec<T, 3>(x(), y(), y()); }
constexpr vec<T, 4> xwww() const { return vec<T, 4>(x(), w(), w(), w()); }
constexpr vec<T, 4> bbgg() const { return vec<T, 4>(b(), b(), g(), g()); }
constexpr vec<T, 4> abra() const { return vec<T, 4>(a(), b(), r(), a()); }
constexpr vec<T, 4> xzzw() const { return vec<T, 4>(x(), z(), z(), w()); }
constexpr vec<T, 4> baba() const { return vec<T, 4>(b(), a(), b(), a()); }
constexpr vec<T, 3>  xww() const { return vec<T, 3>(x(), w(), w()); }
constexpr vec<T, 3>  bgg() const { return vec<T, 3>(b(), g(), g()); }
constexpr vec<T, 3>  yxw() const { return vec<T, 3>(y(), x(), w()); }
constexpr vec<T, 4> argb() const { return vec<T, 4>(a(), r(), g(), b()); }
constexpr vec<T, 3>  yyx() const { return vec<T, 3>(y(), y(), x()); }
constexpr vec<T, 4> bbbg() const { return vec<T, 4>(b(), b(), b(), g()); }
constexpr vec<T, 4> grgr() const { return vec<T, 4>(g(), r(), g(), r()); }
constexpr vec<T, 4> rrgr() const { return vec<T, 4>(r(), r(), g(), r()); }
constexpr vec<T, 4> xywy() const { return vec<T, 4>(x(), y(), w(), y()); }
constexpr vec<T, 4> grab() const { return vec<T, 4>(g(), r(), a(), b()); }
constexpr vec<T, 4> rrab() const { return vec<T, 4>(r(), r(), a(), b()); }
constexpr vec<T, 4> arbb() const { return vec<T, 4>(a(), r(), b(), b()); }
constexpr vec<T, 4> aabg() const { return vec<T, 4>(a(), a(), b(), g()); }
constexpr vec<T, 3>  wzw() const { return vec<T, 3>(w(), z(), w()); }
constexpr vec<T, 4> arga() const { return vec<T, 4>(a(), r(), g(), a()); }
constexpr vec<T, 3>  rar() const { return vec<T, 3>(r(), a(), r()); }
constexpr vec<T, 4> xyxw() const { return vec<T, 4>(x(), y(), x(), w()); }
constexpr vec<T, 4> brgr() const { return vec<T, 4>(b(), r(), g(), r()); }
constexpr vec<T, 4> agag() const { return vec<T, 4>(a(), g(), a(), g()); }
constexpr vec<T, 4> ywwy() const { return vec<T, 4>(y(), w(), w(), y()); }
constexpr vec<T, 2>   yw() const { return vec<T, 2>(y(), w()); }
constexpr vec<T, 4> raag() const { return vec<T, 4>(r(), a(), a(), g()); }
constexpr vec<T, 4> gbrr() const { return vec<T, 4>(g(), b(), r(), r()); }
constexpr vec<T, 4> graa() const { return vec<T, 4>(g(), r(), a(), a()); }
constexpr vec<T, 4> rraa() const { return vec<T, 4>(r(), r(), a(), a()); }
constexpr vec<T, 4> arba() const { return vec<T, 4>(a(), r(), b(), a()); }
constexpr vec<T, 4> zzxz() const { return vec<T, 4>(z(), z(), x(), z()); }
constexpr vec<T, 4> brbr() const { return vec<T, 4>(b(), r(), b(), r()); }
constexpr vec<T, 4> zwyx() const { return vec<T, 4>(z(), w(), y(), x()); }
constexpr vec<T, 4> xzwy() const { return vec<T, 4>(x(), z(), w(), y()); }
constexpr vec<T, 4> xwyy() const { return vec<T, 4>(x(), w(), y(), y()); }
constexpr vec<T, 4> abrr() const { return vec<T, 4>(a(), b(), r(), r()); }
constexpr vec<T, 4> aggb() const { return vec<T, 4>(a(), g(), g(), b()); }
constexpr vec<T, 4> wwyx() const { return vec<T, 4>(w(), w(), y(), x()); }
constexpr vec<T, 4> gagb() const { return vec<T, 4>(g(), a(), g(), b()); }
constexpr vec<T, 4> yyww() const { return vec<T, 4>(y(), y(), w(), w()); }
constexpr vec<T, 4> ragb() const { return vec<T, 4>(r(), a(), g(), b()); }
constexpr vec<T, 3>  wyz() const { return vec<T, 3>(w(), y(), z()); }
constexpr vec<T, 4> yyyy() const { return vec<T, 4>(y(), y(), y(), y()); }
constexpr vec<T, 4> yxyw() const { return vec<T, 4>(y(), x(), y(), w()); }
constexpr vec<T, 3>  xyz() const { return vec<T, 3>(x(), y(), z()); }
constexpr vec<T, 4> yywx() const { return vec<T, 4>(y(), y(), w(), x()); }
constexpr vec<T, 4> zwxy() const { return vec<T, 4>(z(), w(), x(), y()); }
constexpr vec<T, 4> ggrb() const { return vec<T, 4>(g(), g(), r(), b()); }
constexpr vec<T, 4> xxxz() const { return vec<T, 4>(x(), x(), x(), z()); }
constexpr vec<T, 3>  aab() const { return vec<T, 3>(a(), a(), b()); }
constexpr vec<T, 4> wwxy() const { return vec<T, 4>(w(), w(), x(), y()); }
constexpr vec<T, 4> agga() const { return vec<T, 4>(a(), g(), g(), a()); }
constexpr vec<T, 4> ywyz() const { return vec<T, 4>(y(), w(), y(), z()); }
constexpr vec<T, 4> gaga() const { return vec<T, 4>(g(), a(), g(), a()); }
constexpr vec<T, 4> arrg() const { return vec<T, 4>(a(), r(), r(), g()); }
constexpr vec<T, 4> raga() const { return vec<T, 4>(r(), a(), g(), a()); }
constexpr vec<T, 4> gbbg() const { return vec<T, 4>(g(), b(), b(), g()); }
constexpr vec<T, 4> rbbg() const { return vec<T, 4>(r(), b(), b(), g()); }
constexpr vec<T, 4> bggb() const { return vec<T, 4>(b(), g(), g(), b()); }
constexpr vec<T, 4> xxyw() const { return vec<T, 4>(x(), x(), y(), w()); }
constexpr vec<T, 4> xzyz() const { return vec<T, 4>(x(), z(), y(), z()); }
constexpr vec<T, 4> grar() const { return vec<T, 4>(g(), r(), a(), r()); }
constexpr vec<T, 4> rrar() const { return vec<T, 4>(r(), r(), a(), r()); }
constexpr vec<T, 4> arbr() const { return vec<T, 4>(a(), r(), b(), r()); }
constexpr vec<T, 4> xzzy() const { return vec<T, 4>(x(), z(), z(), y()); }
constexpr vec<T, 4> bgga() const { return vec<T, 4>(b(), g(), g(), a()); }
constexpr vec<T, 4> yyzw() const { return vec<T, 4>(y(), y(), z(), w()); }
constexpr vec<T, 4> wxxw() const { return vec<T, 4>(w(), x(), x(), w()); }
constexpr vec<T, 3>  ggg() const { return vec<T, 3>(g(), g(), g()); }
constexpr vec<T, 3>  ywx() const { return vec<T, 3>(y(), w(), x()); }
constexpr vec<T, 4> brrg() const { return vec<T, 4>(b(), r(), r(), g()); }
constexpr vec<T, 4> wzxz() const { return vec<T, 4>(w(), z(), x(), z()); }
constexpr vec<T, 4> ywwz() const { return vec<T, 4>(y(), w(), w(), z()); }
constexpr vec<T, 2>   ba() const { return vec<T, 2>(b(), a()); }
constexpr vec<T, 3>  gbg() const { return vec<T, 3>(g(), b(), g()); }
constexpr vec<T, 4> ywxx() const { return vec<T, 4>(y(), w(), x(), x()); }
constexpr vec<T, 3>  bgb() const { return vec<T, 3>(b(), g(), b()); }
constexpr vec<T, 4> yzzz() const { return vec<T, 4>(y(), z(), z(), z()); }
constexpr vec<T, 4> bgaa() const { return vec<T, 4>(b(), g(), a(), a()); }
constexpr vec<T, 4> bbbb() const { return vec<T, 4>(b(), b(), b(), b()); }
constexpr vec<T, 4> aggr() const { return vec<T, 4>(a(), g(), g(), r()); }
constexpr vec<T, 4> xzwz() const { return vec<T, 4>(x(), z(), w(), z()); }
constexpr vec<T, 3>  wzy() const { return vec<T, 3>(w(), z(), y()); }
constexpr vec<T, 4> yxxz() const { return vec<T, 4>(y(), x(), x(), z()); }
constexpr vec<T, 4> gagr() const { return vec<T, 4>(g(), a(), g(), r()); }
constexpr vec<T, 4> ragr() const { return vec<T, 4>(r(), a(), g(), r()); }
constexpr vec<T, 4> xzxx() const { return vec<T, 4>(x(), z(), x(), x()); }
constexpr vec<T, 4> yyyz() const { return vec<T, 4>(y(), y(), y(), z()); }
constexpr vec<T, 2>   ww() const { return vec<T, 2>(w(), w()); }
constexpr vec<T, 4> aabb() const { return vec<T, 4>(a(), a(), b(), b()); }
constexpr vec<T, 2>   yy() const { return vec<T, 2>(y(), y()); }
constexpr vec<T, 4> gabr() const { return vec<T, 4>(g(), a(), b(), r()); }
constexpr vec<T, 3>  bga() const { return vec<T, 3>(b(), g(), a()); }
constexpr vec<T, 4> ggrr() const { return vec<T, 4>(g(), g(), r(), r()); }
constexpr vec<T, 4> zwwx() const { return vec<T, 4>(z(), w(), w(), x()); }
constexpr vec<T, 4> bbba() const { return vec<T, 4>(b(), b(), b(), a()); }
constexpr vec<T, 3>  yzw() const { return vec<T, 3>(y(), z(), w()); }
constexpr vec<T, 3>  aar() const { return vec<T, 3>(a(), a(), r()); }
constexpr vec<T, 4> wwwx() const { return vec<T, 4>(w(), w(), w(), x()); }
constexpr vec<T, 3>  wwz() const { return vec<T, 3>(w(), w(), z()); }
constexpr vec<T, 4> bggr() const { return vec<T, 4>(b(), g(), g(), r()); }
constexpr vec<T, 4> yywy() const { return vec<T, 4>(y(), y(), w(), y()); }
constexpr vec<T, 4> abab() const { return vec<T, 4>(a(), b(), a(), b()); }
constexpr vec<T, 4> aaba() const { return vec<T, 4>(a(), a(), b(), a()); }
constexpr vec<T, 4> wzzx() const { return vec<T, 4>(w(), z(), z(), x()); }
constexpr vec<T, 3>  wxx() const { return vec<T, 3>(w(), x(), x()); }
constexpr vec<T, 4> xwxw() const { return vec<T, 4>(x(), w(), x(), w()); }
constexpr vec<T, 3>  zzz() const { return vec<T, 3>(z(), z(), z()); }
constexpr vec<T, 4> zyyx() const { return vec<T, 4>(z(), y(), y(), x()); }
constexpr vec<T, 4> wyyx() const { return vec<T, 4>(w(), y(), y(), x()); }
constexpr vec<T, 4> raaa() const { return vec<T, 4>(r(), a(), a(), a()); }
constexpr vec<T, 3>  yyz() const { return vec<T, 3>(y(), y(), z()); }
constexpr vec<T, 3>  xxw() const { return vec<T, 3>(x(), x(), w()); }
constexpr vec<T, 4> abaa() const { return vec<T, 4>(a(), b(), a(), a()); }
constexpr vec<T, 4> zxyx() const { return vec<T, 4>(z(), x(), y(), x()); }
constexpr vec<T, 4> ggbg() const { return vec<T, 4>(g(), g(), b(), g()); }
constexpr vec<T, 4> rgbg() const { return vec<T, 4>(r(), g(), b(), g()); }
constexpr vec<T, 4> grrb() const { return vec<T, 4>(g(), r(), r(), b()); }
constexpr vec<T, 4> bbrg() const { return vec<T, 4>(b(), b(), r(), g()); }
constexpr vec<T, 4> zwzw() const { return vec<T, 4>(z(), w(), z(), w()); }
constexpr vec<T, 4> wxyx() const { return vec<T, 4>(w(), x(), y(), x()); }
constexpr vec<T, 4> wwzw() const { return vec<T, 4>(w(), w(), z(), w()); }
constexpr vec<T, 4> rbbb() const { return vec<T, 4>(r(), b(), b(), b()); }
constexpr vec<T, 4> bagg() const { return vec<T, 4>(b(), a(), g(), g()); }
constexpr vec<T, 3>  ywy() const { return vec<T, 3>(y(), w(), y()); }
constexpr vec<T, 4> agrg() const { return vec<T, 4>(a(), g(), r(), g()); }
constexpr vec<T, 4> bbbr() const { return vec<T, 4>(b(), b(), b(), r()); }
constexpr vec<T, 4> garg() const { return vec<T, 4>(g(), a(), r(), g()); }
constexpr vec<T, 4> grra() const { return vec<T, 4>(g(), r(), r(), a()); }
constexpr vec<T, 4> aabr() const { return vec<T, 4>(a(), a(), b(), r()); }
constexpr vec<T, 4> ywxy() const { return vec<T, 4>(y(), w(), x(), y()); }
constexpr vec<T, 4> arra() const { return vec<T, 4>(a(), r(), r(), a()); }
constexpr vec<T, 4> zwyz() const { return vec<T, 4>(z(), w(), y(), z()); }
constexpr vec<T, 4> rbba() const { return vec<T, 4>(r(), b(), b(), a()); }
constexpr vec<T, 4> baag() const { return vec<T, 4>(b(), a(), a(), g()); }
constexpr vec<T, 3>  rgg() const { return vec<T, 3>(r(), g(), g()); }
constexpr vec<T, 4> wwyz() const { return vec<T, 4>(w(), w(), y(), z()); }
constexpr vec<T, 4> xzxy() const { return vec<T, 4>(x(), z(), x(), y()); }
constexpr vec<T, 4> abar() const { return vec<T, 4>(a(), b(), a(), r()); }
constexpr vec<T, 4> yywz() const { return vec<T, 4>(y(), y(), w(), z()); }
constexpr vec<T, 3>  rbg() const { return vec<T, 3>(r(), b(), g()); }
constexpr vec<T, 3>  gbb() const { return vec<T, 3>(g(), b(), b()); }
constexpr vec<T, 2>   wy() const { return vec<T, 2>(w(), y()); }
constexpr vec<T, 3>  gga() const { return vec<T, 3>(g(), g(), a()); }
constexpr vec<T, 4> wwwy() const { return vec<T, 4>(w(), w(), w(), y()); }
constexpr vec<T, 3>  zyw() const { return vec<T, 3>(z(), y(), w()); }
constexpr vec<T, 4> brra() const { return vec<T, 4>(b(), r(), r(), a()); }
constexpr vec<T, 4> zyzw() const { return vec<T, 4>(z(), y(), z(), w()); }
constexpr vec<T, 3>  brg() const { return vec<T, 3>(b(), r(), g()); }
constexpr vec<T, 4> xyzw() const { return vec<T, 4>(x(), y(), z(), w()); }
constexpr vec<T, 2>   xw() const { return vec<T, 2>(x(), w()); }
constexpr vec<T, 3>  zyx() const { return vec<T, 3>(z(), y(), x()); }
constexpr vec<T, 3>  gba() const { return vec<T, 3>(g(), b(), a()); }
constexpr vec<T, 4> grrr() const { return vec<T, 4>(g(), r(), r(), r()); }
constexpr vec<T, 4> rrrr() const { return vec<T, 4>(r(), r(), r(), r()); }
constexpr vec<T, 4> arag() const { return vec<T, 4>(a(), r(), a(), g()); }
constexpr vec<T, 4> yzyw() const { return vec<T, 4>(y(), z(), y(), w()); }
constexpr vec<T, 4> ggar() const { return vec<T, 4>(g(), g(), a(), r()); }
constexpr vec<T, 4> zywx() const { return vec<T, 4>(z(), y(), w(), x()); }
constexpr vec<T, 4> wyyy() const { return vec<T, 4>(w(), y(), y(), y()); }
constexpr vec<T, 4> yzyx() const { return vec<T, 4>(y(), z(), y(), x()); }
constexpr vec<T, 4> xywx() const { return vec<T, 4>(x(), y(), w(), x()); }
constexpr vec<T, 4> yxzz() const { return vec<T, 4>(y(), x(), z(), z()); }
constexpr vec<T, 4> wywx() const { return vec<T, 4>(w(), y(), w(), x()); }
constexpr vec<T, 4> zxyy() const { return vec<T, 4>(z(), x(), y(), y()); }
constexpr vec<T, 3>  ywz() const { return vec<T, 3>(y(), w(), z()); }
constexpr vec<T, 4> zxwx() const { return vec<T, 4>(z(), x(), w(), x()); }
constexpr vec<T, 4> wxyy() const { return vec<T, 4>(w(), x(), y(), y()); }
constexpr vec<T, 4> wxwx() const { return vec<T, 4>(w(), x(), w(), x()); }
constexpr vec<T, 4> zwzy() const { return vec<T, 4>(z(), w(), z(), y()); }
constexpr vec<T, 4> ywxz() const { return vec<T, 4>(y(), w(), x(), z()); }
constexpr vec<T, 4> brag() const { return vec<T, 4>(b(), r(), a(), g()); }
constexpr vec<T, 4> xxzz() const { return vec<T, 4>(x(), x(), z(), z()); }
constexpr vec<T, 3>  grg() const { return vec<T, 3>(g(), r(), g()); }
constexpr vec<T, 4> wwzy() const { return vec<T, 4>(w(), w(), z(), y()); }
constexpr vec<T, 4> rrbg() const { return vec<T, 4>(r(), r(), b(), g()); }
constexpr vec<T, 4> yzww() const { return vec<T, 4>(y(), z(), w(), w()); }
constexpr vec<T, 4> xzxz() const { return vec<T, 4>(x(), z(), x(), z()); }
constexpr vec<T, 4> xwyx() const { return vec<T, 4>(x(), w(), y(), x()); }
constexpr vec<T, 3>  gbr() const { return vec<T, 3>(g(), b(), r()); }
constexpr vec<T, 4> yyxw() const { return vec<T, 4>(y(), y(), x(), w()); }
constexpr vec<T, 4> wyzw() const { return vec<T, 4>(w(), y(), z(), w()); }
constexpr vec<T, 2>   gg() const { return vec<T, 2>(g(), g()); }
constexpr vec<T, 4> zwwz() const { return vec<T, 4>(z(), w(), w(), z()); }
constexpr vec<T, 4> bagb() const { return vec<T, 4>(b(), a(), g(), b()); }
constexpr vec<T, 4> agrb() const { return vec<T, 4>(a(), g(), r(), b()); }
constexpr vec<T, 4> zxzw() const { return vec<T, 4>(z(), x(), z(), w()); }
constexpr vec<T, 4> garb() const { return vec<T, 4>(g(), a(), r(), b()); }
constexpr vec<T, 4> rgba() const { return vec<T, 4>(r(), g(), b(), a()); }
constexpr vec<T, 4> zwxx() const { return vec<T, 4>(z(), w(), x(), x()); }
constexpr vec<T, 4> wwwz() const { return vec<T, 4>(w(), w(), w(), z()); }
constexpr vec<T, 4> wxzw() const { return vec<T, 4>(w(), x(), z(), w()); }
constexpr vec<T, 4> wwxx() const { return vec<T, 4>(w(), w(), x(), x()); }
constexpr vec<T, 4> bgrb() const { return vec<T, 4>(b(), g(), r(), b()); }
constexpr vec<T, 4> babb() const { return vec<T, 4>(b(), a(), b(), b()); }
constexpr vec<T, 4> wzzz() const { return vec<T, 4>(w(), z(), z(), z()); }
constexpr vec<T, 3>  wxz() const { return vec<T, 3>(w(), x(), z()); }
constexpr vec<T, 2>   ag() const { return vec<T, 2>(a(), g()); }
constexpr vec<T, 4> zyyz() const { return vec<T, 4>(z(), y(), y(), z()); }
constexpr vec<T, 4> baga() const { return vec<T, 4>(b(), a(), g(), a()); }
constexpr vec<T, 4> agra() const { return vec<T, 4>(a(), g(), r(), a()); }
constexpr vec<T, 4> ywzx() const { return vec<T, 4>(y(), w(), z(), x()); }
constexpr vec<T, 4> gara() const { return vec<T, 4>(g(), a(), r(), a()); }
constexpr vec<T, 4> xyyz() const { return vec<T, 4>(x(), y(), y(), z()); }
constexpr vec<T, 4> wyyz() const { return vec<T, 4>(w(), y(), y(), z()); }
constexpr vec<T, 3>  zww() const { return vec<T, 3>(z(), w(), w()); }
constexpr vec<T, 4> xwwx() const { return vec<T, 4>(x(), w(), w(), x()); }
constexpr vec<T, 3>  zyy() const { return vec<T, 3>(z(), y(), y()); }
constexpr vec<T, 4> bgra() const { return vec<T, 4>(b(), g(), r(), a()); }
constexpr vec<T, 4> zxyz() const { return vec<T, 4>(z(), x(), y(), z()); }
constexpr vec<T, 3>  rbb() const { return vec<T, 3>(r(), b(), b()); }
constexpr vec<T, 3>  abg() const { return vec<T, 3>(a(), b(), g()); }
constexpr vec<T, 4> xyzy() const { return vec<T, 4>(x(), y(), z(), y()); }
constexpr vec<T, 4> xzzx() const { return vec<T, 4>(x(), z(), z(), x()); }
constexpr vec<T, 4> wxyz() const { return vec<T, 4>(w(), x(), y(), z()); }
constexpr vec<T, 4> zywy() const { return vec<T, 4>(z(), y(), w(), y()); }
constexpr vec<T, 3>  xwx() const { return vec<T, 3>(x(), w(), x()); }
constexpr vec<T, 3>  yxx() const { return vec<T, 3>(y(), x(), x()); }
constexpr vec<T, 4> yzyy() const { return vec<T, 4>(y(), z(), y(), y()); }
constexpr vec<T, 4> wywy() const { return vec<T, 4>(w(), y(), w(), y()); }
constexpr vec<T, 4> bbag() const { return vec<T, 4>(b(), b(), a(), g()); }
constexpr vec<T, 3>  brb() const { return vec<T, 3>(b(), r(), b()); }
constexpr vec<T, 3>  rba() const { return vec<T, 3>(r(), b(), a()); }
constexpr vec<T, 3>  bag() const { return vec<T, 3>(b(), a(), g()); }
constexpr vec<T, 4> zxwy() const { return vec<T, 4>(z(), x(), w(), y()); }
constexpr vec<T, 4> arab() const { return vec<T, 4>(a(), r(), a(), b()); }
constexpr vec<T, 4> wxwy() const { return vec<T, 4>(w(), x(), w(), y()); }
constexpr vec<T, 4> rarb() const { return vec<T, 4>(r(), a(), r(), b()); }
constexpr vec<T, 3>  wzx() const { return vec<T, 3>(w(), z(), x()); }
constexpr vec<T, 4> xwzw() const { return vec<T, 4>(x(), w(), z(), w()); }
constexpr vec<T, 4> barg() const { return vec<T, 4>(b(), a(), r(), g()); }
constexpr vec<T, 4> xyxx() const { return vec<T, 4>(x(), y(), x(), x()); }
constexpr vec<T, 3>  bra() const { return vec<T, 3>(b(), r(), a()); }
constexpr vec<T, 4> bagr() const { return vec<T, 4>(b(), a(), g(), r()); }
constexpr vec<T, 4> agrr() const { return vec<T, 4>(a(), g(), r(), r()); }
constexpr vec<T, 2>   yx() const { return vec<T, 2>(y(), x()); }
constexpr vec<T, 4> aaag() const { return vec<T, 4>(a(), a(), a(), g()); }
constexpr vec<T, 4> araa() const { return vec<T, 4>(a(), r(), a(), a()); }
constexpr vec<T, 3>  xzw() const { return vec<T, 3>(x(), z(), w()); }
constexpr vec<T, 4> rara() const { return vec<T, 4>(r(), a(), r(), a()); }
constexpr vec<T, 4> bgrr() const { return vec<T, 4>(b(), g(), r(), r()); }
constexpr vec<T, 4> babr() const { return vec<T, 4>(b(), a(), b(), r()); }
constexpr vec<T, 4> zzyw() const { return vec<T, 4>(z(), z(), y(), w()); }
constexpr vec<T, 4> brab() const { return vec<T, 4>(b(), r(), a(), b()); }
constexpr vec<T, 3>  rrg() const { return vec<T, 3>(r(), r(), g()); }
constexpr vec<T, 4> yyxy() const { return vec<T, 4>(y(), y(), x(), y()); }
constexpr vec<T, 4> wzyw() const { return vec<T, 4>(w(), z(), y(), w()); }
constexpr vec<T, 4> aagb() const { return vec<T, 4>(a(), a(), g(), b()); }
constexpr vec<T, 4> zzyx() const { return vec<T, 4>(z(), z(), y(), x()); }
constexpr vec<T, 4> gbgg() const { return vec<T, 4>(g(), b(), g(), g()); }
constexpr vec<T, 4> rbgg() const { return vec<T, 4>(r(), b(), g(), g()); }
constexpr vec<T, 4> yxyx() const { return vec<T, 4>(y(), x(), y(), x()); }
constexpr vec<T, 4> wzyx() const { return vec<T, 4>(w(), z(), y(), x()); }
constexpr vec<T, 3>  zyz() const { return vec<T, 3>(z(), y(), z()); }
constexpr vec<T, 4> gaab() const { return vec<T, 4>(g(), a(), a(), b()); }
constexpr vec<T, 3>  rbr() const { return vec<T, 3>(r(), b(), r()); }
constexpr vec<T, 4> braa() const { return vec<T, 4>(b(), r(), a(), a()); }
constexpr vec<T, 4> argr() const { return vec<T, 4>(a(), r(), g(), r()); }
constexpr vec<T, 2>   gb() const { return vec<T, 2>(g(), b()); }
constexpr vec<T, 4> ywzy() const { return vec<T, 4>(y(), w(), z(), y()); }
constexpr vec<T, 4> aaga() const { return vec<T, 4>(a(), a(), g(), a()); }
constexpr vec<T, 4> zywz() const { return vec<T, 4>(z(), y(), w(), z()); }
constexpr vec<T, 4> xwwy() const { return vec<T, 4>(x(), w(), w(), y()); }
constexpr vec<T, 4> rbag() const { return vec<T, 4>(r(), b(), a(), g()); }
constexpr vec<T, 4> abbg() const { return vec<T, 4>(a(), b(), b(), g()); }
constexpr vec<T, 4> xxyx() const { return vec<T, 4>(x(), x(), y(), x()); }
constexpr vec<T, 4> xywz() const { return vec<T, 4>(x(), y(), w(), z()); }
constexpr vec<T, 3>  brr() const { return vec<T, 3>(b(), r(), r()); }
constexpr vec<T, 4> wywz() const { return vec<T, 4>(w(), y(), w(), z()); }
constexpr vec<T, 2>   bb() const { return vec<T, 2>(b(), b()); }
constexpr vec<T, 4> gaaa() const { return vec<T, 4>(g(), a(), a(), a()); }
constexpr vec<T, 3>  zwy() const { return vec<T, 3>(z(), w(), y()); }
constexpr vec<T, 4> zxwz() const { return vec<T, 4>(z(), x(), w(), z()); }
constexpr vec<T, 4> arar() const { return vec<T, 4>(a(), r(), a(), r()); }
constexpr vec<T, 4> bgab() const { return vec<T, 4>(b(), g(), a(), b()); }
constexpr vec<T, 4> zyxw() const { return vec<T, 4>(z(), y(), x(), w()); }
constexpr vec<T, 2>   ga() const { return vec<T, 2>(g(), a()); }
constexpr vec<T, 3>  xwy() const { return vec<T, 3>(x(), w(), y()); }
constexpr vec<T, 3>  yxy() const { return vec<T, 3>(y(), x(), y()); }
constexpr vec<T, 4> wxwz() const { return vec<T, 4>(w(), x(), w(), z()); }
constexpr vec<T, 4> rarr() const { return vec<T, 4>(r(), a(), r(), r()); }
constexpr vec<T, 4> gggg() const { return vec<T, 4>(g(), g(), g(), g()); }
constexpr vec<T, 4> rggg() const { return vec<T, 4>(r(), g(), g(), g()); }
constexpr vec<T, 4> zyxx() const { return vec<T, 4>(z(), y(), x(), x()); }
constexpr vec<T, 4> yyzx() const { return vec<T, 4>(y(), y(), z(), x()); }
constexpr vec<T, 4> wxxx() const { return vec<T, 4>(w(), x(), x(), x()); }
constexpr vec<T, 4> bbgb() const { return vec<T, 4>(b(), b(), g(), b()); }
constexpr vec<T, 4> zxxw() const { return vec<T, 4>(z(), x(), x(), w()); }
constexpr vec<T, 3>  abb() const { return vec<T, 3>(a(), b(), b()); }
constexpr vec<T, 4> xxww() const { return vec<T, 4>(x(), x(), w(), w()); }
constexpr vec<T, 3>  gag() const { return vec<T, 3>(g(), a(), g()); }
constexpr vec<T, 4> xwyz() const { return vec<T, 4>(x(), w(), y(), z()); }
constexpr vec<T, 4> yzxw() const { return vec<T, 4>(y(), z(), x(), w()); }
constexpr vec<T, 4> xyxy() const { return vec<T, 4>(x(), y(), x(), y()); }
constexpr vec<T, 4> brar() const { return vec<T, 4>(b(), r(), a(), r()); }
constexpr vec<T, 4> bbga() const { return vec<T, 4>(b(), b(), g(), a()); }
constexpr vec<T, 4> bbab() const { return vec<T, 4>(b(), b(), a(), b()); }
constexpr vec<T, 4> aagr() const { return vec<T, 4>(a(), a(), g(), r()); }
constexpr vec<T, 3>  bab() const { return vec<T, 3>(b(), a(), b()); }
constexpr vec<T, 3>  aba() const { return vec<T, 3>(a(), b(), a()); }
constexpr vec<T, 4> zwxz() const { return vec<T, 4>(z(), w(), x(), z()); }
constexpr vec<T, 2>   wx() const { return vec<T, 2>(w(), x()); }
constexpr vec<T, 4> wwxz() const { return vec<T, 4>(w(), w(), x(), z()); }
constexpr vec<T, 4> gaar() const { return vec<T, 4>(g(), a(), a(), r()); }
constexpr vec<T, 4> agab() const { return vec<T, 4>(a(), g(), a(), b()); }
constexpr vec<T, 2>   rg() const { return vec<T, 2>(r(), g()); }
constexpr vec<T, 4> barb() const { return vec<T, 4>(b(), a(), r(), b()); }
constexpr vec<T, 4> zzww() const { return vec<T, 4>(z(), z(), w(), w()); }
constexpr vec<T, 3>  yzx() const { return vec<T, 3>(y(), z(), x()); }
constexpr vec<T, 4> raab() const { return vec<T, 4>(r(), a(), a(), b()); }
constexpr vec<T, 4> bbaa() const { return vec<T, 4>(b(), b(), a(), a()); }
constexpr vec<T, 2>   gr() const { return vec<T, 2>(g(), r()); }
constexpr vec<T, 4> zzyy() const { return vec<T, 4>(z(), z(), y(), y()); }
constexpr vec<T, 4> ywzz() const { return vec<T, 4>(y(), w(), z(), z()); }
constexpr vec<T, 4> wzww() const { return vec<T, 4>(w(), z(), w(), w()); }
constexpr vec<T, 3>  baa() const { return vec<T, 3>(b(), a(), a()); }
constexpr vec<T, 4> zzwx() const { return vec<T, 4>(z(), z(), w(), x()); }
constexpr vec<T, 4> yxyy() const { return vec<T, 4>(y(), x(), y(), y()); }
constexpr vec<T, 4> wzyy() const { return vec<T, 4>(w(), z(), y(), y()); }
constexpr vec<T, 4> xwwz() const { return vec<T, 4>(x(), w(), w(), z()); }
