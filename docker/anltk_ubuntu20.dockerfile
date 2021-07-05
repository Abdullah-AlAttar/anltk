FROM ubuntu:20.04




RUN apt-get update && \
    apt-get install -y --no-install-recommends \
	git python3  python3-pip  gcc g++ pkg-config

RUN apt-get install -y --no-install-recommends 

RUN pip3 install ninja
RUN pip3 install meson


RUN git clone --recurse-submodules https://github.com/Abdullah-AlAttar/anltk.git /opt/anltk \
    && cd /opt/anltk/anltk \
    && meson build --default-library=shared --buildtype=release \
    && cd build \
    && ninja \
	&& ninja test \
	&& ninja install \
    && cd ../../python \
    && python3 setup.py install

