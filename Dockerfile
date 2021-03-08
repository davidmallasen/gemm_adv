FROM ubuntu:20.04

WORKDIR /
COPY gemm_adv-1.0.tar.gz .

ENV TZ=Europe/Stockholm
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

WORKDIR /
RUN apt-get update && apt-get install -y wget build-essential \
 && apt-get install -y gfortran \
 && apt-get install -y pkg-config \
 && apt-get install -y libgtest-dev libgmock-dev \
 && apt-get install -y python3 \
 && tar -xvzf gemm_adv-1.0.tar.gz

WORKDIR /
ENV OPENBLAS_NUM_THREADS=1
ENV OPENBLAS_LIB=/openblas/lib
ENV OPENBLAS_INCLUDE=/openblas/include
RUN wget https://github.com/xianyi/OpenBLAS/releases/download/v0.3.13/OpenBLAS-0.3.13.tar.gz \
 && tar -xvzf OpenBLAS-0.3.13.tar.gz \
 && cd OpenBLAS-0.3.13 \
 && make &&make && make PREFIX=/openblas install

WORKDIR /
ENV LIBXSMM_LIB=/libxsmm/lib
ENV LIBXSMM_INCLUDE=/libxsmm/include
RUN wget https://github.com/hfp/libxsmm/archive/1.16.1.tar.gz \
 && tar -xvzf 1.16.1.tar.gz \
 && cd libxsmm-1.16.1 \
 && make PREFIX=/libxsmm STATIC=0 install

WORKDIR /gemm_adv-1.0
ENV LD_LIBRARY_PATH=$OPENBLAS_LIB:$LIBXSMM_LIB:$LD_LIBRARY_PATH
RUN ./configure && make
VOLUME /data
