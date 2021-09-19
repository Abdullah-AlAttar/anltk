
#!/bin/bash




rm -rf ./release 

DOCKER_BUILDKIT=1 docker build --file ./docker/deploy.dockerfile --tag ab_dullah/anltk_deploy:latest -o ./release . 

# twine upload ./release/*.egg ./release/*.gz $(find ./release/ -name "*.whl")  