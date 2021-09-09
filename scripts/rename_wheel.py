


import sys
import os

wheel_name = sys.argv[1]

# fasttext_wheel-0.9.2-cp36-cp36m-manylinux1_x86_64.whl 
# anltk-0.3.7-cp37-cp37m-manylinux2010_x86_64.whl
# ./dist/cp37-cp37m/anltk-0.3.7-py3-none-manylinux_2_12_x86_64.manylinux2010_x86_64.whl 
python3_ver = os.path.split(os.path.split(wheel_name)[0])[1]

# print(python3_ver)

if '2010' in wheel_name:
	wheel_name = wheel_name.replace('py3-none-manylinux_2_12_x86_64.', f'{python3_ver}-')
elif '2014' in wheel_name:
	wheel_name = wheel_name.replace()

print(wheel_name)
