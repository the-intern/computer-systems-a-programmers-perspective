# Volumes

> **NOTE** : use port 80 as the apps container port only because the node app uses that port: `app.listen(80);`

```bash

# build image tagging it
docker image build --tag node-app-volumes-example:vers-1 .

# run in attached mode with naming convention
docker container run --rm --name temp-node-volume-example -p 3001:80 node-app-volumes-example:vers-1

# after creating another image, run in detached mode
docker container run --rm --detach --name feedback-node-container -p 3001:80 feedback-node

# after stopping ... to start again do simply:
docker container start feedback-node-container

# all other attributes in initial creation are retained ...

# However ... data storage???
# container restart works if no remove flag.
# but more ...

```

## How Volumes Work

- Volumes are folders on your host machine.
- Make docker aware of.
- Then mapped to docker container.
- Volumes survive the shutdown, even the removal, of a container
- A container can read and write data from and into a volume.

## Named Volumes

```bash

# first image
docker image build -t feedback-node:volumes .

# container run with named volume
docker container run -d -p 3002:80 --rm --name feedback-app-container-voluminator --volume feedback:/app/feedback feedback-node:volumes

# but more
# another image
docker image build -t test-feedback-node:test-volumes .

# and another container but with same named volume
 docker container run -d -p 3003:80 --rm --name feedback-app-container-version-test --volume feedback:/app/feedback test-feedback-node:test-volumes

#  they will share data --- in real time

```

## Removing Anonymous Volumes

We saw, that anonymous volumes are removed automatically, when a container is removed.

This happens when you start / run a container with the `--rm` option.

If you start a container without that option, the anonymous volume would NOT be removed, even if you remove the container (with `docker rm ...`).

Still, if you then re-create and re-run the container (i.e. you `run docker run ...` again), a new anonymous volume will be created. So even though the anonymous volume wasn't removed automatically, it'll also not be helpful because a different anonymous volume is attached the next time the container starts (i.e. you removed the old container and run a new one).

Now you just start piling up a bunch of unused anonymous volumes - you can clear them via

```bash

docker volume rm VOL_NAME
#  or

docker volume prune

```

## Bind mounts

Good for persistent, editable data --- e.g., source code in dev being changed all the time.

Whereas docker controls volumes, you control location and path of the bind mount.

Also, bind mount is specific to a container, not an image. Therefore, you do not enter a bind mount command in the Dockerfile.

```bash

docker container run -d -p 3000:80 --rm \
--name feedback-app --volume feedback:/app/feedback \
--volume /Users/udax/full/path/to/project:/app feedback-node:volumes

# or better -- use environmental variables
docker container run -d -p 3000:80 \
--rm --name feedback-app \
--volume feedback:/app/feedback \
--volume $(pwd):/app feedback-node:volumes

> ddbc7affad26b8069679637f0a9ce88a8fef41a02dcab60a43bd4f2501befc13
# now starts container again and entire folder will be mounted as a volume into the app folder

# you can just use -v for --volume
docker container run -d -p 3000:80 --rm \
--name feedback-app -v feedback:/app/feedback \
-v $(pwd):/app feedback-node:volumes
# or if on windows
docker container run -d -p 3000:80 --rm \
--name feedback-app --volume feedback:/app/feedback \
--volume "%cd%":/app feedback-node:volumes

#

```

> but note that app is NOT running

So run:

```bash

docker logs feedback-app
# and get

Error: Cannot find module 'express'
Require stack:
- /app/server.js
    ...
code: 'MODULE_NOT_FOUND',
requireStack: [ '/app/server.js' ]

```

Well, express.js is not installed where bind mounting would occur.

Solution?

Well, remember:

![bind mounts](/images/bindmounts.png)

Use anonymous volumes --- i.e., add yet a **third** volume to command:

```bash
docker container run -d -p 3000:80 --rm \
--name feedback-app --volume feedback:/app/feedback \
--volume $(pwd):/app \
--volume /app/node_modules \
feedback-node:volumes
```

![review](/images/review.png)

## Read-Only Volumes: Use a read-only volume as a `best practice`

For some **_development_** applications, the container needs to write into the bind mount so that changes are propagated back to the Docker host.

At other times, the container only needs read access to the data.

> Remember that multiple containers can mount the same volume, and it can be mounted read-write for some of them and read-only for others, at the same time.

```bash

docker container run --rm -dp 3000:80 \
--name feedback-app \
-v feedback:/app/feedback \
-v $(pwd):/app:ro \
-v /app/node_modules \
-v /app/temp \
feedback-node:volumes

```

The portion reading `-v $(pwd):/app:ro` adds clarity re bind mounts.
