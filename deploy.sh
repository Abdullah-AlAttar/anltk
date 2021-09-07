
#!/bin/bash


# docker run -ti -v $(pwd):/app \
# 		ab_dullah/anltk_manylinux1:latest \
# 		rm -rf dist && rm -rf build || exit


for value in cp310-cp310  cp36-cp36m  cp37-cp37m  cp38-cp38  cp39-cp39  pp37-pypy37_pp73
do
	for plat in 2010
	do
	    echo $value

		docker run -ti -v $(pwd):/app \
			ab_dullah/anltk_manylinux$plat:latest \
			/opt/python/$value/bin/python setup.py bdist_wheel --dist-dir ./tmp/$plat/$value --verbose || exit
		docker run -ti -v $(pwd):/app \
			ab_dullah/anltk_manylinux$plat:latest \
				auditwheel repair -wdist tmp/$plat/$value/anltk-*-py3-none-linux_x86_64.whl -w ./dist/$plat/$value || exit
	done
done
# docker run -ti -v $(pwd):/app \
# 	ab_dullah/anltk_manylinux1:latest \
# 		 rm -rf tmp && rm -rf build || exit

for wheel in $(find ./dist -name "*whl")
do
	echo $wheel
	new_name=`python3 rename_wheel.py $wheel`
	echo $new_name
	docker run -ti -v $(pwd):/app \
 		ab_dullah/anltk_manylinux1:latest \
			mv $wheel $new_name
done




twine upload $(find ./dist/ -name "*.whl")    

# docker build -t myimage \
#   --build-arg USER_ID=$(id -u) \
#   --build-arg GROUP_ID=$(id -g) .
