

import anltk


ar = "أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ"
bw = anltk.ar_to_bw(ar)


ttor = anltk.Transliterator(mapping=anltk.CM_AR2BW)

bw2 = ttor.convert(ar)


ar2 = anltk.bw_to_ar(bw2)
assert bw == bw2
assert (ar2 == ar)


print(ar)
print(bw)
print(bw2)
print(ar2)


num = 12399
ttor = anltk.Transliterator(mapping=anltk.CM_AR2BW)
bw2 = ttor.convert(ar)
print(anltk.tafqeet(num))
# اثنى عشر ألف و ثلاثمئة و تسعة و تسعون


print(anltk.is_valid_kalima('اثنى'))
print(anltk.is_valid_kalima('اّّثنى'))
print(anltk.is_valid_kalima('ىياريت'))