commit:
	git add .
	git commit -m "Automated commit"

pull:
	git pull origin master

push:
	git push origin master

all: commit pull push
