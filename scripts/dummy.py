
import anltk

import sys
import time
from camel_tools.utils.dediac import dediac_ar
file_name = sys.argv[1]


with open(file_name) as f:
    file = f.read()
    tic = time.perf_counter()

    file = anltk.split(file, '.')
    toc = time.perf_counter()
    dur = (toc - tic) 
    print(f"Finished in {dur:0.4} seconds")

    with open('./out_anltk.csv', 'w') as of:
        of.writelines(file)

with open(file_name) as f:
    file = f.read()
    tic = time.perf_counter()

    file = file.split('.')
    toc = time.perf_counter()
    dur = (toc - tic) 
    print(f"Finished in {dur:0.4} seconds")
    [line + '\n' for line in file]
    with open('./out_camel.csv', 'w') as of:
        of.writelines(file)