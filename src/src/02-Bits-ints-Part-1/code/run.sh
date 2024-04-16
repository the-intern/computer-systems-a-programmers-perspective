#!/bin/bash

# docker run -d -it --name devtest --mount type=bind,source="$(pwd)"/target,target=/app nginx:latest

# docker run -it --rm \
# -v $(pwd):/src/app \
# trk-gcc-image

docker run -v $(pwd)/src:/home/csapp/src --rm --name bryant-ohallaron -it gcc-for-csapp
