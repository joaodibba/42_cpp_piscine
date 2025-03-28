#!/bin/bash

set -euo pipefail

IMAGE_NAME="valgrind_tmp"
CONTAINER_NAME="valgrind_tmp"
DEPENDENCIES="g++ valgrind make tree vim"
BASE_IMAGE="ubuntu:20.04"
WORK_DIR="/tmp/cpp"

if [[ "$(docker images -q $IMAGE_NAME 2> /dev/null)" == "" ]]; then
    echo "Image $IMAGE_NAME does not exist. Building it..."

    docker pull $BASE_IMAGE

    docker run --name $CONTAINER_NAME $BASE_IMAGE \
        bash -c "export DEBIAN_FRONTEND=noninteractive && \
        apt-get update && \
        apt-get install -y $DEPENDENCIES tzdata && \
        apt-get clean && \
        rm -rf /var/lib/apt/lists/*"

    docker commit $CONTAINER_NAME $IMAGE_NAME

    docker rm $CONTAINER_NAME
fi

docker run -it --rm \
    -v "$PWD:$WORK_DIR" \
    -w $WORK_DIR \
    $IMAGE_NAME \
	bash
