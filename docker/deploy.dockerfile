
FROM quay.io/pypa/manylinux2010_x86_64 AS build-stage


RUN /opt/python/cp36-cp36m/bin/python 		-m pip install pybind11==2.7.1 
RUN /opt/python/cp37-cp37m/bin/python 		-m pip install pybind11==2.7.1
RUN /opt/python/cp38-cp38/bin/python 		-m pip install pybind11==2.7.1 
RUN /opt/python/cp39-cp39/bin/python 		-m pip install pybind11==2.7.1 
RUN /opt/python/cp310-cp310/bin/python 		-m pip install pybind11==2.7.1 
RUN /opt/python/pp37-pypy37_pp73/bin/python -m pip install pybind11==2.7.1 


COPY . /opt

RUN cd /opt/ && bash build_linux_wheels.sh

FROM scratch AS export-stage

COPY --from=build-stage /opt/dist/* .




