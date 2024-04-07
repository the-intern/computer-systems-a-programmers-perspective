#!/bin/bash

# docker run -d -it --name devtest --mount type=bind,source="$(pwd)"/target,target=/app nginx:latest

docker run -it --rm \
-v $(pwd):/src/app \
trk-gcc-image
