all: token switch
token:
	@cat my_C/token_git
switch:
	@git add .
	@git commit -m "switch"
	@git push origin master
