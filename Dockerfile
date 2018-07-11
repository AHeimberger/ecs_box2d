FROM ubuntu:16.04
MAINTAINER aheimberger


# setup default build arguments
ARG GROUP_ID=1000
ARG USER_ID=1000
ARG USER_NAME=ecsbox2d


# setup environment directories
ENV DEBIAN_FRONTEND     noninteractive
ENV DIR_DEPLOY          /deploy
ENV DIR_PROJECT         /project


# general requirements
RUN apt-get -qq update && \
    apt-get -qq dist-upgrade && \
    apt-get install -qq -y --no-install-recommends \
    ca-certificates \
    g++ \
    make \
    git \
    openssl \
    cmake \
    libfreetype6-dev \
    libjpeg-dev \
    libflac++-dev \
    libflac-dev \
    libogg-dev \
    libopenal-dev \
    libvorbis-dev \
    libxrandr-dev \
    libglu1-mesa-dev \
    libudev-dev \
    wget \
    unzip \
    patch


# lets create the user
RUN groupadd -g "${GROUP_ID}" "${USER_NAME}" && \
    useradd -u ${USER_ID} -g ${GROUP_ID} -ms /bin/bash ${USER_NAME}


# setup directories
RUN mkdir -p ${DIR_DEPLOY} && \
    mkdir -p ${DIR_PROJECT}


# change permissions
RUN chown -R ${USER_NAME}:${USER_NAME} ${DIR_DEPLOY} && \
    chown -R ${USER_NAME}:${USER_NAME} ${DIR_PROJECT}


# setup the working directory
WORKDIR ${DIR_PROJECT}
USER ${USER_NAME}
