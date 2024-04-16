#!/bin/bash

# docker run -d -it --name devtest --mount type=bind,source="$(pwd)"/target,target=/app nginx:latest

# docker run -it --rm \
# -v $(pwd):/src/app \
# trk-gcc-image

docker run -v $(pwd)/src:/home/src/code --name krcode -it trk-second-gcc-image:latest
