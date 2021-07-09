#
from camel_tools.utils.dediac import dediac_ar
import anltk

import sys
import time
file_name = sys.argv[1]

with open(file_name) as f:
    file = f.read()
    tic = time.perf_counter()

    file = dediac_ar(file)
    toc = time.perf_counter()
    dur = (toc - tic) 
    print(f"Finished in {dur:0.4} seconds")

    with open('./out_camel.csv', 'w') as of:
        of.write(file)



with open(file_name) as f:
    file = f.read()
    tic = time.perf_counter()

    file = anltk.remove_tashkeel(file)
    toc = time.perf_counter()
    dur = (toc - tic) 
    print(f"Finished in  {dur:0.4} seconds")

    with open('./out_anltk.csv', 'w') as of:
        of.write(file)


with open(file_name) as f:
    
    tic = time.perf_counter()
    for line in f:
        a = dediac_ar(line)
    # file = f.read()

    # file = dediac_ar(file)
    toc = time.perf_counter()
    dur = (toc - tic) 
    print(f"Finished in {dur:0.4} seconds")

    # with open('./out_camel.csv', 'w') as of:
        # of.write(file)



with open(file_name) as f:
    tic = time.perf_counter()
    cnt = 0
    for line in f:
        line = anltk.remove_tashkeel(line)
        # if cnt % 1000  == 0:
            # print(f'Finished {cnt}')
    toc = time.perf_counter()
    dur = (toc - tic) 
    print(f"Finished in  {dur:0.4} seconds")

    # with open('./out_anltk.csv', 'w') as of:
    #     of.write(file)

