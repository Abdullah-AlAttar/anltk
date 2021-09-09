
#!/bin/bash


for value in cp310-cp310  cp36-cp36m  cp37-cp37m  cp38-cp38  cp39-cp39  pp37-pypy37_pp73
do
	for plat in 2010
	do
		echo $value
		/opt/python/$value/bin/python setup.py bdist_wheel --dist-dir ./tmp/$plat/$value --verbose 
		auditwheel repair -wdist tmp/$plat/$value/anltk-*-py3-none-linux_x86_64.whl -w ./dist/$plat/$value 
	done
done


for wheel in $(find ./dist -name "*whl")
do
	echo $wheel
	new_name=`/opt/python/cp36-cp36m/bin/python rename_wheel.py $wheel`
	echo $new_name
	mv $wheel $new_name
done

/opt/python/cp36-cp36m/bin/python setup.py install && /opt/python/cp36-cp36m/bin/python setup.py sdist 
