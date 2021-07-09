FROM ubuntu:20.04




RUN apt-get update && \
    apt-get install -y --no-install-recommends \
	git python3  python3-pip  gcc g++

RUN apt-get install -y --no-install-recommends 

RUN pip3 install ninja
RUN pip3 install meson


RUN git clone --recurse-submodules https://github.com/Abdullah-AlAttar/anltk.git \
    && cd ./anltk/anltk \
    && meson build --default-library=shared --buildtype=release --Dbuild_tests=false \
    && cd build \
    && ninja \
    && cd ../../python \
    && python3 setup.py install

