FROM quay.io/pypa/manylinux2010_x86_64




RUN /opt/python/cp36-cp36m/bin/python -m pip install pybind11==2.7.1 importlib_metadata==4.6.4
RUN /opt/python/cp37-cp37m/bin/python -m pip install pybind11==2.7. importlib_metadata==4.6.4
RUN /opt/python/cp38-cp38/bin/python -m pip install pybind11==2.7.1 importlib_metadata==4.6.4
RUN /opt/python/cp39-cp39/bin/python -m pip install pybind11==2.7.1 importlib_metadata==4.6.4
RUN /opt/python/cp310-cp310/bin/python -m pip install pybind11==2.7.1 importlib_metadata==4.6.4
RUN /opt/python/pp37-pypy37_pp73/bin/python -m pip install pybind11==2.7.1 importlib_metadata==4.6.4

WORKDIR /app
# RUN /opt/python/cp37-cp37m/bin/python setup.py bdist_wheel

# RUN auditwheel repair -wdist dist/anltk-0.3.5-py3-none-linux_x86_64.whl