#
from camel_tools.utils.dediac import dediac_ar
import anltk


import time
#
#  import
#
#


with open('./test.csv') as f:
    file = f.read()
    tic = time.perf_counter()

    file = dediac_ar(file)
    toc = time.perf_counter()
    dur = (toc - tic) 
    print(f"Downloaded the tutorial in {dur:0.4} seconds")

    with open('./out_camel.csv', 'w') as of:
        of.write(file)



with open('./test.csv') as f:
    file = f.read()
    tic = time.perf_counter()

    file = anltk.remove_tashkeel(file)
    toc = time.perf_counter()
    dur = (toc - tic) 
    print(f"Downloaded the tutorial in {dur:0.4} seconds")

    with open('./out_anltk.csv', 'w') as of:
        of.write(file)

