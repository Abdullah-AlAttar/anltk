FROM ubuntu:20.04




RUN apt-get update && \
    apt-get install -y --no-install-recommends \
	git python3  python3-pip python3-dev  gcc g++

RUN apt-get install -y --no-install-recommends 

RUN pip3 install ninja
RUN pip3 install meson


RUN git clone --recurse-submodules https://github.com/Abdullah-AlAttar/anltk.git \
    && cd ./anltk/anltk \
    && meson build --buildtype=release -Dbuild_tests=false --prefix=/usr/local --libdir=lib \
    && cd build \
    && ninja \
    && ninja install \
    && cd ../../ \
    && pip install -r requirements.txt  \
    && pip install .

